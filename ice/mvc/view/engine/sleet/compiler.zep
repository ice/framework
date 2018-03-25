
namespace Ice\Mvc\View\Engine\Sleet;

/**
 * Sleet file compiler.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Compiler
{

    protected view;
    protected content;
    protected parsed;
    protected parser { get };

    const NEVER = 0;
    const NOT_EXIST = 1;
    const IF_CHANGE = 2;
    const ALWAYS = 3;

    /**
     * Sleet compiler constructor. Set the view and parser.
     *
     * @param mixed view
     */
    public function __construct(view = null)
    {
        let this->view = view,
            this->parser = new Parser();
    }

    /**
     * Compile the file.
     *
     * @param string path
     * @return string Parsed content
     */
    public function compile(string path)
    {
        var content;

        let content = file_get_contents(path),
            this->content = content,
            this->parsed = this->parser->text(content);

        return this->parsed;
    }

    /**
     * Magic toString to get parsed content.
     */
    public function __toString()
    {
        return this->parsed;
    }
}
