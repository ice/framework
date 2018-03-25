
namespace Ice\Mvc\View\Engine;

use Ice\Exception;
use Ice\Mvc\View\Engine;
use Ice\Mvc\View\ViewInterface;
use Ice\Mvc\View\Engine\Sleet\Compiler;

/**
 * Sleet template engine. Syntax is similar to Twig, Volt or Django.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Sleet extends Engine
{
    protected compiler { get };

    /**
     * Compile the .sleet file.
     *
     * @param string path Path to the file
     * @return string Path to the compiled file
     */
    public function compile(string! path)
    {
        var compileDir, compile, trim, dir, file, compiledPath, old, compiled;

        fetch trim, this->options["trimPath"];
        fetch compileDir, this->options["compileDir"];
        fetch compile, this->options["compile"];

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
            let this->compiler = new Compiler(this),
                compiled = this->compiler->compile(path);

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

    /**
     * Render the Slet file. Compile first.
     *
     * @param string path
     * @param array data
     * @return string
     */
    public function render(string! path, array data = [])
    {
        var key, value;

        let path = this->compile(path);

        for key, value in data {
            let {key} = value;
        }

        ob_start();

        require path;
        return ob_get_clean();
    }
}
