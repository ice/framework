
namespace Ice\I18n\Plural;

/**
 * Plural rules for Arabic language
 * 
 * Locales: ar
 * 
 * Rules:
 *  zero → n is 0;
 *  one → n is 1;
 *  two → n is 2;
 *  few → n mod 100 in 3..10;
 *  many → n mod 100 in 11..99;
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
class Arabic implements PluralInterface
{

    public function getCategory(int count) -> string
    {
        var isInt;
        int i100;

        let isInt = this->isInt(count),
            i100 = count % 100;

        if count == 0 {
            return "zero";
        } elseif count == 1 {
            return "one";
        } elseif count == 2 {
            return "two";
        } elseif isInt && i100 >= 3 && i100 <= 10 {
            return "few";
        } elseif isInt && i100 >= 11 && i100 <= 99 {
            return "many";
        } else {
            return "other";
        }
    }

    protected function isInt(value)
    {
        return is_numeric(value) && value - intval(value) == 0;
    }
}
