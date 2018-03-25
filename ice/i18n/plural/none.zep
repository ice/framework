
namespace Ice\I18n\Plural;

/**
 * Plural rules for the following locales and languages:
 * 
 * Locales: az bm bo dz fa id ig ii hu ja jv ka kde kea km kn ko lo ms my sah ses sg th to tr vi wo yo zh
 * 
 * These are known to have no plurals, there are no rules:
 *  other → everything
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
class None implements PluralInterface
{

    public function getCategory(int count) -> string
    {
        return "other";
    }
}
