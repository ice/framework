
namespace Ice\Mvc;

use Ice\Arr;
use Ice\Exception;
use Ice\Mvc\View\Engine\Php;
use Ice\Mvc\View\ViewInterface;

class View extends Arr implements ViewInterface
{

    protected _engines { set };
    protected _content { set, get };
    protected _mainView = "index" { set, get };
    protected _layoutsDir = "layouts/" { set, get };
    protected _partialsDir = "partials/" { set, get };
    protected _viewsDir { set, get };
    protected _file { set, get };
    protected _silent = false { set };

    public function __construct(file = null, array data = [])
    {
        if file != null {
            let this->_file = file;
        }
        parent::__construct(data);
    }

    public function getEngines()
    {
        var ext, engine;

        if !this->_engines {
            let this->_engines[".phtml"] = new Php(this);
        }
        for ext, engine in this->_engines {
            if typeof engine == "object" {
                if engine instanceof \Closure {
                    let this->_engines[ext] = call_user_func_array(engine, [this]);
                }
            } else {
                if typeof engine == "string" {
                    let this->_engines[ext] = create_instance_params(engine, [this]);
                } else {
                    throw new Exception(sprintf("Invalid template engine registration for '%s' extension", ext));
                }
            }
        }
        return this->_engines;
    }

    public function render(file = null, array data = [])
    {
        var ext, engine, engines, path, exists, content;

        let exists = false,
            content = null;

        if file !== null {
            let this->_file = file;
        }

        if empty this->_file {
            throw new Exception("You must set the file to use within your view before rendering");
        }

        let engines = this->getEngines();

        for ext, engine in engines {
            let path = this->_viewsDir . this->_file . ext;
            if file_exists(path) {
                let exists = true;
                this->replace(data);
                let content = engine->render(path, this->all());
                break;
            }
        }

        if !this->_silent && !exists {
            throw new Exception(sprintf("The requested view %s could not be found", path));
        }
        return content;
    }

    public function load(string! file, array data = [])
    {
        return this->render(file, data);
    }

    public function partial(string! file, array data = [])
    {
        return this->render(this->_partialsDir . file, data);
    }

    public function layout(var file = null, array data = [])
    {
        if !file {
            let file = this->_mainView;
        }
        return this->render(this->_layoutsDir . file, data);
    }

    public function setVar(string! key, value)
    {
        this->set(key, value);
    }

    public function setVars(array! vars)
    {
        this->replace(vars);
    }

    public function __toString()
    {
        return this->render();
    }
}