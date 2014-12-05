
namespace Ice\Mvc\View\Engine;

use Ice\Exception;
use Ice\Mvc\View\Engine;
use Ice\Mvc\View\ViewInterface;
use Ice\Mvc\View\Engine\Sleet\Compiler;

class Sleet extends Engine
{
    protected _compiler { get };

    public function compile(string! path)
    {
        var compileDir, compile, trim, dir, file, compiledPath, old, compiled;

        fetch trim, this->_options["trimPath"];
        fetch compileDir, this->_options["compileDir"];
        fetch compile, this->_options["compile"];

        let dir = rtrim(compileDir, DIRECTORY_SEPARATOR) . str_replace(trim, "", realpath(dirname(path))),
            file = basename(path, ".sleet"),
            compiledPath = dir . DIRECTORY_SEPARATOR . file . ".phtml";
        

        switch compile {
            case Compiler::NEVER:
                let compile = false;
            break;
            case Compiler::NOT_EXIST:
                let compile = !file_exists(compiledPath);
            break;
            case Compiler::IF_CHANGE:
                if !file_exists(compiledPath) {
                    let compile = true;
                } else {
                    let compile = md5_file(compiledPath);
                }
            break;
            default: // Compiler::ALWAYS:
                let compile = true;
            break;
        }

        if compile {
            let this->_compiler = new Compiler(this),
                compiled = this->_compiler->compile(path);

            // Check if file was changed
            if typeof compile == "string" {
                if compile != md5(compiled) {
                    let compile = true;
                }
            }

            if compile === true {
                if !is_dir(dir) {
                    let old = umask(0);

                    mkdir(dir, 0777, true);
                    umask(old);
                }

                if file_put_contents(compiledPath, compiled) === false {
                    throw new Exception("Directory can't be written");
                }
            }
        }

        return compiledPath;
    }

    public function render(string! path, array data = [])
    {
        let path = this->compile(path);

        extract(data);
        ob_start();

        require path;
        return ob_get_clean();
    }

}