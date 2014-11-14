
namespace Ice\Di;

interface DiInterface extends \ArrayAccess
{

    /**
     * Return the last DI created
     *
     * @return DiInterface
     */
    public static function $fetch() -> <DiInterface>;
}