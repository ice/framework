
namespace Ice\Mvc;

use Ice\Arr;
use Ice\Exception;
use Ice\Mvc\View\Engine\Php;
use Ice\Mvc\View\ViewInterface;

/**
 * View is a class for working with the "view" portion of the model-view-controller pattern.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class View extends Arr implements ViewInterface
{

    protected engines;
    protected content { set, get };
    protected mainView { set, get };
    protected layoutsDir = "layouts/" { get };
    protected partialsDir = "partials/" { get };
    protected viewsDir = [];
    protected file { set, get };
    protected silent = false { set };

    /**
     * View constructor. Set the file and vars.
     *
     * @param string file
     * @param array data
     */
    public function __construct(file = null, array data = [])
    {
        if file != null {
            let this->file = file;
        }
        parent::__construct(data);
    }

    /**
     * Get registered engines.
     */
    public function getEngines()
    {
        if !this->engines {
            let this->engines[".phtml"] = new Php(this);
        }

        return this->engines;
    }

    /**
     * Registered engines.
     *
     * @param array engines
     * @return object View
     */
    public function setEngines(array engines)
    {
        var ext, engine;

        for ext, engine in engines {
            if typeof engine == "object" {
                if (engine instanceof \Closure) {
                    let this->engines[ext] = {engine}(this);
                } elseif engine instanceof EngineInterface {
                    let this->engines[ext] = engine;
                }
            } elseif is_string(engine) && class_exists(engine) {
                let this->engines[ext] = new {engine}(this);
            }
            if !isset this->engines[ext] {
                throw new Exception(sprintf("Invalid template engine registration for '%s' extension", ext));
            }
        }

        return this;
    }

    /**
     * Set the layouts dir`locate in the view dirs.
     *
     * @param string dirs
     * @return object View
     */
    public function setLayoutsDir(string dirs)
    {
        let dirs = trim(dirs, "/\\");
        if dirs {
            let dirs .= DIRECTORY_SEPARATOR;
        }

        let this->layoutsDir = dirs;

        return this;
    }

    /**
     * Set the partials dir`locate in the view dirs.
     *
     * @param string dirs
     * @return object View
     */
    public function setPartialsDir(string dirs)
    {
        let dirs = trim(dirs, "/\\");
        if dirs {
            let dirs .= DIRECTORY_SEPARATOR;
        }

        let this->partialsDir = dirs;

        return this;
    }

    /**
     * Get view directory.
     *
     * @return object View
     */
    public function getViewsDir()
    {
        return count(this->viewsDir) < 2 ? current(this->viewsDir) : this->viewsDir;
    }

    /**
     * Set view directory.
     *
     * @param array vars
     * @return object View
     */
    public function setViewsDir(dirs)
    {
        var k, dir, path;
        
        if (is_string(dirs)) {
            let dirs = [dirs];
        }

        for k, dir in dirs {
            let path = realpath(dir);
            if path {
                let dirs[k] = path . DIRECTORY_SEPARATOR;
            } else {
                throw new Exception(sprintf("The view dir '%s' could not be found", dir));
            }
        }

        let this->viewsDir = dirs;

        return this;
    }

    /**
     * Add view directory.
     *
     * @param mixed dir View directory or directories
     * @param boolean prepend Prepend to the current views dir
     * @return object View
     */
    public function addViewsDir(dirs, bool prepend = false)
    {
        var k, dir, path;
        
        if (is_string(dirs)) {
            let dirs = [dirs];
        }

        for k, dir in dirs {
            let path = realpath(dir);
            if path {
                let dirs[k] = path . DIRECTORY_SEPARATOR;
            } else {
                throw new Exception(sprintf("The view dir '%s' could not be found", dir));
            }
        }
        
        if (prepend) {
            let dirs = array_merge(dirs, this->viewsDir);
        } else {
            let dirs = array_merge(this->viewsDir, dirs);
        }
        let this->viewsDir = array_unique(dirs);
        
        return this;
    }

    /**
     * Try to render the view with vars for engines.
     *
     * @param string file
     * @param array data
     * @return string
     */
    public function render(file = null, array data = [])
    {
        var ext, engine, engines, path, dir, dirs, exists;

        if file !== null {
            let this->file = trim(file, "/\\");
        }

        if empty this->file {
            throw new Exception("You must set the file to use within your view before rendering");
        }

        let this->content = "",
            exists = false,
            dirs = this->viewsDir,
            engines = this->getEngines(),
            ext = pathinfo(file, PATHINFO_EXTENSION);

        if !empty ext && fetch engine, engines["." . ext] {
            for dir in dirs {
                let path = dir . this->file;
                if file_exists(path) {
                    let exists = true,
                        data = this->replace(data)->all(),
                        this->content = engine->render(path, data);
                    break;
                }
            }
        } else {
            for ext, engine in engines {
                for dir in dirs {
                    let path = dir . this->file . ext;
                    if file_exists(path) {
                        let exists = true,
                            data = this->replace(data)->all(),
                            this->content = engine->render(path, data);
                        break;
                    }
                }
                // no need to lookup and parse the other view
                if exists {
                    break;
                }
            }
        }

        if !this->silent && !exists {
            throw new Exception(sprintf("The requested view %s could not be found", path));
        }

        return this->content;
    }

    /**
     * Load the view.
     *
     * @param string file Name of file without extension from the views dir
     * @param array data Vars to send
     * @return string
     */
    public function load(string! file, array data = [])
    {
        return this->render(file, data);
    }

    /**
     * Load the partial view.
     *
     * @param string file Name of file without extension from the partials dir
     * @param array data Vars to send
     * @return string
     */
    public function partial(string! file, array data = [])
    {
        return this->render(this->partialsDir . file, data);
    }

    /**
     * Load the layout view.
     *
     * @param string file Name of file without extension from the layouts dir
     * @param array data Vars to send
     * @return string
     */
    public function layout(var file = null, array data = [])
    {
        if !file {
            let file = this->mainView;
        }
        return this->render(this->layoutsDir . file, data);
    }

    /**
     * Set var to the view.
     *
     * @param string name
     * @param mixed value
     * @return object View
     */
    public function setVar(string! name, value)
    {
        this->set(name, value);
        
        return this;
    }

    /**
     * Set multiple vars to the view.
     *
     * @param array vars
     * @return object View
     */
    public function setVars(array! vars)
    {
        this->replace(vars);
        
        return this;
    }

    /**
     * Alias of the `setMainView` method.
     *
     * @param array vars
     * @return object View
     */
    public function setLayout(string layout)
    {
        this->setMainView(layout);
        
        return this;
    }

    /**
     * Magic toStrint, get the rendered view.
     */
    public function __toString()
    {
        return this->render();
    }
}
