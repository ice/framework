
namespace Ice;

/**
 * Provide the multi-page pagination component.
 *
 * @package     Ice/Pagination
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        Ice\Tag
 */
class Pagination extends Arr
{

    protected di { get };
    protected tag { get };

    /**
     * Pagination constructor. Fetch di and tag.
     *
     * @param array options
     */
    public function __construct(array options = [])
    {
        var di;

        parent::__construct(options);

        let di = Di::$fetch(),
            this->di = di,
            this->tag = di->get("tag");
    }

    /**
     * Returns a slice of the resultset to show in the pagination.
     *
     * @return object Pagination
     */
    public function calculate() -> <Pagination>
    {
        var items, data;
        int limit, page, pages, total, previous, next;

        let items  = this->get("data", []);

        if typeof items != "array" && !(items instanceof Arr) {
            throw new Exception("Invalid data for pagination");
        }

        if items instanceof Arr {
            let data = items->all();
        } else {
            let data = items;
        }

        let limit  = (int) this->get("limit", 10),
            page = (int) this->get("page", 1),
            total = count(items),
            pages = (int) ceil(total / intval(limit ? limit : 1));

        // Make sure page is >= 1
        if page <= 0 {
            let page = 1;
        }

        this->set("items", array_slice(data, limit * (page - 1), limit));

        if page < pages {
            let next = page + 1;
        } else {
            let next = pages;
        }

        this->set("next", next);

        if page > 1 {
            let previous = page - 1;
        } else {
            let previous = 1;
        }

        this->replace([
            "first": 1,
            "previous": previous,
            "current": page,
            "last": pages,
            "pages": pages,
            "total": total
        ]);

        return this;
    }

    /**
     * Prepare list button.
     *
     * @param mixed page Name or page number
     * @param mixed url URL with pagination
     * @param boolean active If active create link else span
     * @param string symbol HTML symbol to add
     * @return string HTML
     */
    protected function prepareButton(var page, var url = null, boolean active = false, var symbol = null)
    {
        var query, i18n, title, liClass, spanClass, aClass;
        boolean pages = false;

        switch page {
            case "first":
                let symbol = "&laquo;";
                break;
            case "previous":
                let symbol = "&lsaquo;";
                break;
            case "next":
                let symbol = "&rsaquo;";
                break;
            case "last":
                let symbol = "&raquo;";
                break;
            default:
                let symbol = !symbol ? page : symbol,
                    pages = true;
                break;
        }

        let liClass = this->get("liClass"),
            spanClass = this->get("spanClass"),
            aClass = this->get("aClass");

        if !active {
            return "<li class=\"" . (pages ? "active" : "disabled") . (liClass ? " " . liClass : "") . "\"><span" . (spanClass ? " class=\"" . spanClass . "\"" : "") . ">" . symbol . "</span></li>";
        }

        let query = this->di->get("request")->getQuery(),
            i18n = this->di->get("i18n");

        if pages {
            let title = i18n ? i18n->translate("page: %d", [page]) : null;
        } else {
            let title = i18n ? i18n->translate(page) : null,
                page = this->get(page);
        }

        if this->has("query") && !this->get("query") {
            // Get current URL if uri is false
            if url === false {
                let url = this->di->get("url")->get(false);
            }

            // Add /1 to the url
            let url .= (url ? "/" : "") . page . this->get("hash");
        } else {
            // Don't add ?page=1 for first page
            if page > 1 {
                query->set("page", page);
            } else {
                query->remove("page");
            }
        }

        return "<li" . (liClass ? " class=\"" . liClass . "\"" : "") . ">" . this->tag->a([url, symbol, title, "query": query->all(), "class": aClass]) . "</li>";
    }

    /**
     * Prepare minimal pagination.
     * Previous 1 [2] 3 4 5 6 Next
     *
     * @param mixed url URL with pagination
     * @param array parameters UL attributes to adding
     * @return string HTML
     */
    public function minimal(var url = null, array parameters = [])
    {
        var html;
        int i;

        // Prepare list
        let html = this->tag->tagHtml("ul", parameters, ["class": "pagination"]);

        // Prepare previous
        let html .= this->prepareButton("previous", url, this->get("current") > this->get("previous"));

        // Prepare pages
        for i in range(1, this->get("pages")) {
            let html .= this->prepareButton(i, url, i !== this->get("current"));
        }

        // Prepare next
        let html .= this->prepareButton("next", url, this->get("current") < this->get("next"));

        // Close list
        let html .= this->tag->endTag("ul");

        return html;
    }

    /**
     * Prepare basic pagination.
     * First Previous 1 [2] 3 4 5 6 Next Last
     *
     * @param mixed url URL with pagination
     * @param array parameters UL attributes to adding
     * @return string HTML
     */
    public function basic(var url = null, array parameters = [])
    {
        var html;
        int i;

        // Prepare list
        let html = this->tag->tagHtml("ul", parameters, ["class": "pagination"]);

        // Prepare first
        let html .= this->prepareButton("first", url, this->get("current") != this->get("first"));

        // Prepare previous
        let html .= this->prepareButton("previous", url, this->get("current") > this->get("previous"));

        // Prepare pages
        for i in range(1, this->get("pages")) {
            let html .= this->prepareButton(i, url, i !== this->get("current"));
        }

        // Prepare next
        let html .= this->prepareButton("next", url, this->get("current") < this->get("next"));

        // Prepare last
        let html .= this->prepareButton("last", url, this->get("current") != this->get("last"));

        // Close list
        let html .= this->tag->endTag("ul");

        return html;
    }


    /**
     * Prepare floating pagination.
     * First Previous 1 2 3 ... 23 24 25 26 [27] 28 29 30 31 ... 48 49 50 Next Last
     *
     * @param mixed url URL with pagination
     * @param array parameters UL attributes to adding
     * @param int countOut Number of page links in the begin and end of whole range
     * @param int countIn Number of page links on each side of current page
     * @return string HTML
     */
    public function floating(var url = null, array parameters = [], int countOut = 0, int countIn = 2)
    {
        var html, links, page, content;
        boolean useMiddle, useN3, useN6;
        var n2, n4, n5, n7, n8;
        int n1, n3, n6, i;

        if this->get("pages") < 2 {
            return;
        }

        // Beginning group of pages: n1...n2
        let n1 = 1,
            n2 = min(countOut, this->get("pages"));

        // Ending group of pages: n7...n8
        let n7 = max(1, this->get("pages") - countOut + 1),
            n8 = this->get("pages");

        // Middle group of pages: n4...n5
        let n4 = max(n2 + 1, this->get("current") - countIn),
            n5 = min(n7 - 1, this->get("current") + countIn),
            useMiddle = (n5 >= n4);

        // Point n3 between n2 and n4
        let n3 = (int) ((n2 + n4) / 2),
            useN3 = (useMiddle && ((n4 - n2) > 1));

        // Point n6 between n5 and n7
        let n6 = (int) ((n5 + n7) / 2),
            useN6 = (useMiddle && ((n7 - n5) > 1));

        // Links to display as array(page: content)
        let links = [];

        // Generate links data in accordance with calculated numbers
        for i in range(n1, n2) {
            let links[i] = i;
        }

        if useN3 {
            let links[n3] = "&hellip;";
        }

        for i in range(n4, n5) {
            let links[i] = i;
        }

        if useN6 {
            let links[n6] = "&hellip;";
        }

        for i in range(n7, n8) {
            let links[i] = i;
        }

        // Prepare list
        let html = this->tag->tagHtml("ul", parameters, ["class": "pagination"]);

        // Prepare first
        let html .= this->prepareButton("first", url, this->get("current") != this->get("first"));

        // Prepare previous
        let html .= this->prepareButton("previous", url, this->get("current") > this->get("previous"));

        // Prepare pages
        for page, content in links {
            let html .= this->prepareButton(page, url, page !== this->get("current"), content);
        }

        // Prepare next
        let html .= this->prepareButton("next", url, this->get("current") < this->get("next"));

        // Prepare last
        let html .= this->prepareButton("last", url, this->get("current") != this->get("last"));

        // Close list
        let html .= this->tag->endTag("ul");

        return html;
    }
}
