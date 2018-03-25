
namespace Ice\I18n\Plural;

/**
 * Plural rules for the following locales and languages:
 * 
 * Locales: asa ast af bem bez bg bn brx ca cgg chr ckb da de dv ee el en eo es et eu fi fo fur fy gl gsw gu
 *          ha haw is it jmc kaj kcg kk kl ks ksb ku ky lb lg mas ml mn mr nah nb nd ne nl nn no nr ny nyn om
 *          or os pa pap ps pt rof rm rwk saq seh sn so sq ss ssy st sv sw syr ta te teo tig tk tn ts ur vo
 *          wae ve vun xh xog zu
 * 
 * Rules:
 *  one → n is 1;
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
class One implements PluralInterface
{

    public function getCategory(int count) -> string
    {
        return count == 1 ? "one" : "other";
    }
}
