
namespace Ice;

/**
 * PSR-4 autoloader class.
 *
 * @package     Ice/Loader
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Loader
{

    protected prefixes = [];

    /**
     * Register loader with SPL autoloader stack.
     * 
     * @return void
     */
    public function register()
    {
        spl_autoload_register([this, "loadClass"]);
    }

    /**
     * Adds a base directory for a namespace prefix.
     *
     * @param string prefix The namespace prefix
     * @param string baseDir A base directory for class files in the namespace
     * @param bool prepend If true, prepend the base directory to the stack instead of appending it; this causes it to
     * be searched first rather than last
     * @return Loader
     */
    public function addNamespace(string prefix, string baseDir, boolean prepend = false)
    {
        // normalize namespace prefix
        let prefix = trim(prefix, "\\") . "\\";

        // normalize the base directory with a trailing separator
        let baseDir = rtrim(baseDir, "/") . DIRECTORY_SEPARATOR,
            baseDir = rtrim(baseDir, DIRECTORY_SEPARATOR) . "/";

        // initialize the namespace prefix array
        if !isset this->prefixes[prefix] {
            // Refcount of the new array zephir/issues/1140
            let this->prefixes[prefix] = [utf8_encode(baseDir)];
            return this;
        }

        // retain the base directory for the namespace prefix
        if prepend {
            array_unshift(this->prefixes[prefix], utf8_encode(baseDir));
        } else {
            array_push(this->prefixes[prefix], utf8_encode(baseDir));
        }
        return this;
    }

    /**
     * Loads the class file for a given class name.
     *
     * @param string className The fully-qualified class name
     * @return mixed The mapped file name on success, or boolean false on failure
     */
    public function loadClass(string className)
    {
        var prefix, pos, relativeClass, mappedFile;

        // the current namespace prefix
        let prefix = className;

        // work backwards through the namespace names of the fully-qualified
        // class name to find a mapped file name
        let pos = strrpos(prefix, "\\");

        if pos === false {        
            // try to load a mapped file for the prefix and relative class
            let mappedFile = this->loadMappedFile("\\", className);
            if mappedFile {
                return mappedFile;
            }
        } else {        
            do {
                // retain the trailing namespace separator in the prefix
                let prefix = substr(className, 0, pos + 1);

                // the rest is the relative class name
                let relativeClass = substr(className, pos + 1);

                // try to load a mapped file for the prefix and relative class
                let mappedFile = this->loadMappedFile(prefix, relativeClass);
                if mappedFile {
                    return mappedFile;
                }

                // remove the trailing namespace separator for the next iteration
                // of strrpos()
                let prefix = rtrim(prefix, "\\");
                let pos = strrpos(prefix, "\\");
            } 
            while pos !== false;
        }

        // never found a mapped file
        return false;
    }

    /**
     * Load the mapped file for a namespace prefix and relative class.
     * 
     * @param string $prefix The namespace prefix
     * @param string $relative_class The relative class name
     * @return mixed Boolean false if no mapped file can be loaded, or the name of the mapped file that was loaded
     */
    protected function loadMappedFile(string prefix, string relativeClass)
    {
        var baseDir, file;

        // are there any base directories for this namespace prefix?
        if !isset this->prefixes[prefix] {
            return false;
        }

        let relativeClass = str_replace("\\", DIRECTORY_SEPARATOR, relativeClass) . ".php";

        // look through base directories for this namespace prefix
        for baseDir in this->prefixes[prefix] {
            // replace the namespace prefix with the base directory,
            // replace namespace separators with directory separators
            // in the relative class name, append with .php
            let file = baseDir . relativeClass;

            // if the mapped file exists, require it
            if this->requireFile(file) {
                // yes, we"re done
                return file;
            }
        }

        // never found it
        return false;
    }

    /**
     * If a file exists, require it from the file system.
     * 
     * @param string $file The file to require
     * @return bool True if the file exists, false if not
     */
    protected function requireFile(string file)
    {
        if file_exists(file) {
            require file;
            return true;
        }
        return false;
    }
}
