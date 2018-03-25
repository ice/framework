/**
 * Global alias of translate method.
 */
function _t(string! str, array values = null, var context = null, string lang = null)
{
    var i18n;

    let i18n = I18n::$fetch();

    if i18n {
        return i18n->translate(str, values, context, lang);
    }
}

namespace Ice;

use Ice\I18n\Plural;

/**
 * Internationalization (i18n) class.
 *
 * @package     Ice/I18n
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class I18n
{
    
    protected static i18n;
    protected cache = [];
    protected rules = [];
    protected options = [
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
        let this->options = array_merge(this->options, options),
            self::i18n = this;
    }

    /**
     * Return the last I18n created.
     *
     * @return I18n
     */
    public static function $fetch()
    {
        return self::i18n;
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
            let this->options["lang"] = strtolower(str_replace("_", "-", lang));
        }

        return this->options["lang"];
    }

    /**
     * Get ISO language code.
     *
     * @param string lang Language
     * @param boolean country Get country code, by default gets language code
     * @return string
     */
    public function iso(var lang = null, boolean country = false) -> string
    {
        var parts;

        if !lang {
            let lang = this->options["lang"];
        }

        let parts = explode("-", strtolower(str_replace("_", "-", lang)));

        return country && isset parts[1] ? parts[1] : parts[0];
    }



    /**
     * Returns specified form of a string translation. No parameters are replaced.
     * If no translation exists, the original string will be returned. 
     *
     * @param string str Text to translate
     * @param mixed form If NULL, looking for `other` form, else the very first form
     * @param string lang Target language
     * @return string
     */
    public function get(string str, var form = null, string lang = null) -> string
    {
        var messages, translation;

        let messages = [];

        if !lang {
            // Use the global target language
            let lang = (string) this->options["lang"];
        }

        // Load the translation messages for this language
        let messages = this->load(lang);

        if isset messages[str] {
            let translation = messages[str];

            // If translation is array, return right context
            if typeof translation == "array" {
                // Get a value for the form key
                if array_key_exists(form, translation) {
                    return translation[form];
                } elseif array_key_exists("other", translation) {
                    return translation["other"];
                }

                // Return the very first form
                return reset(translation);
            }

            return translation;
        }

        // If no translation exists, return the original string
        return str;
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
        if fetch cache, this->cache[lang] {
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
                let path = (string) this->options["dir"] . found . ".php";

                if file_exists(path) {
                    let messages = require path;
                    // Stop searching
                    break;
                }
            }
        }

        let this->cache[lang] = messages;

        return this->cache[lang];
    }

    /**
     * Returns translation of a string with right plural form.
     * If no translation exists, the original string will be returned.
     * 
     * @param string string
     * @param int count
     * @param string lang
     * @return string
     */
    public function plural(string! str, int count = 0, string lang = null)
    {
        var rules, form, code;

        let code = this->iso(lang);

        if !fetch rules, this->rules[code] {
            // Get language code prefix
            let this->rules[code] = this->pluralRules(code),
                rules = this->rules[code];
        }


        let form = rules->getCategory(count);

        // Return the translation for that form
        return this->get(str, form, lang);
    }

    /**
     * Plural rules lazy initialization.
     * 
     * @param string code Language code
     * @return object
     */
    protected function pluralRules(string code)
    {
        if code === "pl" {
            return new Plural\Polish;
        } elseif code === "ar" {
            return new Plural\Arabic;
        } elseif in_array(code, ["cs", "sk"], true) {
            return new Plural\Czech;
        } elseif in_array(code, ["ru", "sr", "uk", "sh", "be", "hr", "bs"], true) {
            return new Plural\Balkan;
        } elseif in_array(code, ["fr", "ff", "kab"], true) {
            return new Plural\French;
        } elseif in_array(code, ["mo", "ro"], true) {
            return new Plural\Romanian;
        } elseif in_array(code, ["hi", "ln", "mg", "ak", "tl", "am", "bh", "wa", "ti", "guw", "fil", "nso"], true) {
            return new Plural\Zero;
        } elseif in_array(code, [
            "en", "ny", "nr", "no", "om", "os", "ps", "pa", "nn", "or", "nl", "lg", "lb", "ky", "ml", "mr",
            "ne", "nd", "nb", "pt", "rm", "ts", "tn", "tk", "ur", "vo", "zu", "xh", "ve", "te", "ta", "sq",
            "so", "sn", "ss", "st", "sw", "sv", "ku", "mn", "et", "eo", "el", "eu", "fi", "fy", "fo", "ee",
            "dv", "bg", "af", "bn", "ca", "de", "da", "gl", "es", "it", "is", "ks", "ha", "kk", "kl", "gu",
            "brx", "mas", "teo", "chr", "cgg", "tig", "wae", "xog", "ast", "vun", "bem", "syr", "bez", "asa",
            "rof", "ksb", "rwk", "haw", "pap", "gsw", "fur", "saq", "seh", "nyn", "kcg", "ssy", "kaj", "jmc",
            "nah", "ckb"], true) {
            return new Plural\One;
        } elseif in_array(code, ["se", "kw", "iu", "smn", "sms", "smj", "sma", "naq", "smi"], true) {
            return new Plural\Two;
        } elseif in_array(code, [
            "my", "sg", "ms", "lo", "kn", "ko", "th", "to", "yo", "zh", "wo", "vi", "tr", "az", "km", "id",
            "ig", "fa", "dz", "bm", "bo", "ii", "hu", "ka", "jv", "ja", "kde", "ses", "sah", "kea"], true) {
            return new Plural\None;
        } else {
            throw new Exception("Unknown language code: " . code);
        }
    }

    /**
     * Alias of translate.
     */
    public function _(string! str, array values = null, var context = null, string lang = null) -> string
    {
        return this->translate(str, values, lang);
    }

    /**
     * Translation/internationalization function. strtr() or sprintf is used for replacing parameters.
     *
     * @param string string Text to translate
     * @param array values Values to replace in the translated text
     * @param mixed context String form or numeric count
     * @param string lang Source language
     * @return string
     */
    public function translate(string! str, array values = null, var context = null, string lang = null) -> string
    {
        if !lang {
            let lang = (string) this->options["lang"];
        }

        if is_numeric(context) {
            // Get plural form
            let str = this->plural(str, context, lang);
        } else {
            // Get custom form
            let str = this->get(str, context, lang);
        }

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
