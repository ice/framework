
namespace Ice\I18n\Plural;

/**
 * Plural rules for the following locales and languages:
 * 
 * Locales: be bs hr ru sh sr uk
 *
 * Rules:
 *  one → n mod 10 is 1 and n mod 100 is not 11;
 *  few → n mod 10 in 2..4 and n mod 100 not in 12..14;
 *  many → n mod 10 is 0 or n mod 10 in 5..9 or n mod 100 in 11..14;
 *  other → everything else (fractions)
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
class Balkan implements PluralInterface
{

    public function getCategory(int count) -> string
    {
        var isInt;
        int i10, i100;

        let isInt = this->isInt(count),
            i10 = count % 10,
            i100 = count % 100;

        if isInt && count % 10 == 1 && count % 100 != 11 {
            return "one";
        } elseif isInt && i10 >= 2 && i10 <= 4 && !(i100 >= 12 && i100 <= 14)  {
            return "few";
        } elseif isInt && (i10 == 0 || (i10 >= 5 && i10 <= 9) || (i100 >= 11 && i100 <= 14)) {
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
