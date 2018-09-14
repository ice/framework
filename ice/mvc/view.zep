
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

    protected engines { set };
    protected content { set, get };
    protected mainView = "index" { set, get };
    protected layoutsDir = "layouts/" { set, get };
    protected partialsDir = "partials/" { set, get };
    protected viewsDir { set, get };
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
        var ext, engine;

        if !this->engines {
            let this->engines[".phtml"] = new Php(this);
        } else {
            for ext, engine in this->engines {
                if typeof engine == "object" {
                    if engine instanceof \Closure {
                        let this->engines[ext] = call_user_func_array(engine, [this]);
                    }
                } else {
                    if typeof engine == "string" {
                        let this->engines[ext] = create_instance_params(engine, [this]);
                    } else {
                        throw new Exception(sprintf("Invalid template engine registration for '%s' extension", ext));
                    }
                }
            }
        }
        return this->engines;
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
        var ext, engine, engines, path, dir, dirs, exists, content;

        let exists = false,
            content = null;

        if file !== null {
            let this->file = file;
        }

        if empty this->file {
            throw new Exception("You must set the file to use within your view before rendering");
        }

        let engines = this->getEngines();

        if typeof this->viewsDir == "array" {
            let dirs = this->viewsDir;
        } else {
            let dirs = [this->viewsDir];
        }

        let ext = pathinfo(this->file, PATHINFO_EXTENSION);

        if !empty ext {
            if fetch engine, engines["." . ext] {            
                for dir in dirs {
                    let path = dir . this->file;
                    if file_exists(path) {
                        let exists = true;
                        this->replace(data);
                        let content = engine->render(path, this->all());
                        break;
                    }
                }
            }
        } else {
            for ext, engine in engines {
                for dir in dirs {
                    let path = dir . this->file . ext;
                    if file_exists(path) {
                        let exists = true;
                        this->replace(data);
                        let content = engine->render(path, this->all());
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
        return content;
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
