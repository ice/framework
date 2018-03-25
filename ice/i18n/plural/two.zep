
namespace Ice\I18n\Plural;

/**
 * Plural rules for the following locales and languages:
 * 
 * Locales: iu kw naq se sma smi smj smn sms
 * 
 * Rules:
 *  one → n is 1;
 *  two → n is 2;
 *  other → everything else
 * 
 * Reference CLDR Version 21 (2012-03-01 03:27:30 GMT)
 * @see  http://unicode.org/repos/cldr-tmp/trunk/diff/supplemental/language_plural_rules.html
 * @see  http://unicode.org/repos/cldr/trunk/common/supplemental/plurals.xml
 * 
 * @package     Ice/I18n
 * @category    Plural rules
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Two implements PluralInterface
{

    public function getCategory(int count) -> string
    {
        if count == 1 {
            return "one";
        } elseif count == 2 {
            return "two";
        } else {
            return "other";
        }
    }
}
