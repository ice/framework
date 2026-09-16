
namespace Ice\I18n\Plural;

/**
 * Interface for Plural rules
 *
 * @package     Ice/I18n
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
interface PluralInterface
{
    public function getCategory(int count) -> string;
}
