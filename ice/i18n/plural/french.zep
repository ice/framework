
namespace Ice\I18n\Plural;

/**
 * Plural rules for the following locales and languages:
 * 
 * Locales: ff fr kab
 * 
 * Rules:
 *  one → n within 0..2 and n is not 2;
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
class French implements PluralInterface
{

    public function getCategory(int count) -> string
    {
        if count >= 0 && count < 2 {
            return "one";
        } else {
            return "other";
        }
    }
}
