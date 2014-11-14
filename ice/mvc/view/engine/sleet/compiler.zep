
namespace Ice\Mvc\View\Engine\Sleet;

class Compiler
{

    protected _view;
    protected _content;
    protected _parsed;
    protected _parser { get };

    const NEVER = 0;
    const NOT_EXIST = 1;
    const IF_CHANGE = 2;
    const ALWAYS = 3;

    public function __construct(view = null)
    {
        let this->_view = view,
            this->_parser = new Parser();
    }

    public function compile(string path)
    {
        var content;

        let content = file_get_contents(path),
            this->_content = content,
            this->_parsed = this->_parser->text(content);

        return this->_parsed;
    }

    public function __toString()
    {
        return this->_parsed;
    }
}