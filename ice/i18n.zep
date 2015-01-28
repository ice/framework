
namespace Ice;

/**
 * Internationalization (i18n) class.
 *
 * @package     Ice/I18n
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class I18n
{
    
    protected static _i18n;
    protected _cache = [];
    protected _options = [
        "source": "en-gb",
        "lang": "en-gb",
        "dir": ""
    ];

    /**
     * I18n constructor.
     *
     * @param array options
     */
    public function __construct(array options = [])
    {
        let this->_options = array_merge(this->_options, options),
            self::_i18n = this;
    }

    /**
     * Return the last I18n created.
     *
     * @return I18n
     */
    public static function $fetch()
    {
        return self::_i18n;
    }

    /**
     * Get and set the target language.
     *
     * @param string lang New language setting
     * @return string
     */
    public function lang(string lang = null) -> string
    {
        // Normalize the language
        if lang {
            let this->_options["lang"] = strtolower(str_replace("_", "-", lang));
        }

        return this->_options["lang"];
    }

    /**
     * Get ISO language code.
     *
     * @return string
     */
    public function iso() -> string
    {
        return substr(this->_options["lang"], 0, 2);
    }



    /**
     * Returns translation of a string. No parameters are replaced.
     * If no translation exists, the original string will be returned. 
     *
     * @param string str Text to translate
     * @param string lang Target language
     * @return string
     */
    public function get(string str, string lang = null) -> string
    {
        var messages;

        let messages = [];

        if !lang {
            // Use the global target language
            let lang = (string) this->_options["lang"];
        }

        // Load the translation messages for this language
        let messages = this->load(lang);

        // Return the translated string if it exists
        return isset messages[str] ? messages[str] : str;
    }

    /**
     * Load language from the file.
     *
     * @param string lang Language code
     * @return array
     */
    private function load(string lang) -> array
    {
        var cache, parts, subdir, tail, tmp, found, path, messages;

        // Load from the cache
        if fetch cache, this->_cache[lang] {
            return cache;
        }

        let parts = explode("-", lang),
            subdir = implode(DIRECTORY_SEPARATOR, parts),
            messages = [];

        // Search for /en/gb.php, /en-gb.php, /en.php or gb.php
        for tail in  [subdir, lang, parts] {
            if typeof tail != "array" {
                let tmp = tail,
                    tail = [tmp];
            }

            for found in tail {
                let path = (string) this->_options["dir"] . found . ".php";

                if file_exists(path) {
                    let messages = require path;
                    // Stop searching
                    break;
                }
            }
        }

        let this->_cache[lang] = messages;

        return this->_cache[lang];
    }

    /**
     * Alias of translate.
     */
    public function _(string! str, array values = null, string lang = null) -> string
    {
        return this->translate(str, values, lang);
    }

    /**
     * Translation/internationalization function. strtr() or sprintf is used for replacing parameters.
     *
     * @param string string Text to translate
     * @param array values Values to replace in the translated text
     * @param string lang Source language
     * @return string
     */
    public function translate(string! str, array values = null, string lang = null) -> string
    {
        if !lang {
            let lang = (string) this->_options["lang"];
        }

        // Get the translation for this message
        let str = this->get(str, lang);

        if !count(values) {
            return str;
        } else {
            // Check if values is associative or sequential
            if count(array_filter(array_keys(values), "is_string")) {
                return strtr(str, values);
            } else {
                return call_user_func_array("sprintf", array_merge([str], values));
            }
        }
    }
}
