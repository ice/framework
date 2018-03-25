
namespace Ice\I18n\Plural;

/**
 * Plural rules for Polish language:
 * 
 * Locales: pl
 *
 * Rules:
 *  one → n is 1;
 *  few → n mod 10 in 2..4 and n mod 100 not in 12..14 and n mod 100 not in 22..24;
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
class Polish implements PluralInterface
{

    public function getCategory(int count) -> string
    {
        var isInt;
        int i10, i100;

        let isInt = this->isInt(count),
            i10 = count % 10,
            i100 = count % 100;

        if count == 1 {
            return "one";
        } elseif isInt && i10 >= 2 && i10 <= 4 && !(i100 >= 12 && i100 <= 14) && !(i100 >= 22 && i100 <= 24) {
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
