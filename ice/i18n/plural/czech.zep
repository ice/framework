
namespace Ice\I18n\Plural;

/**
 * Plural rules for the following locales and languages:
 * 
 * Locales: cs sk
 * 
 * Rules:
 *  one → n is 1;
 *  few → n in 2..4;
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
class Czech implements PluralInterface
{

    public function getCategory(int count) -> string
    {
        if count == 1 {
            return "one";
        } elseif this->isInt(count) && count >= 2 && count <= 4 {
            return "few";
        } else {
            return "other";
        }
    }

    protected function isInt(value)
    {
        return is_numeric(value) && value - intval(value) == 0;
    }
}