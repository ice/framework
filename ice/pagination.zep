
namespace Ice;

/**
 * Provide the multi-page pagination component.
 *
 * @package     Ice/Pagination
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 * @uses        Ice\Tag
 */
class Pagination extends Arr
{

    protected _di { get };
    protected _tag { get };

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
            this->_di = di,
            this->_tag = di->{"getTag"}();
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
            pages = (int) ceil(total / intval(limit));

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
     * Prepare minimal pagination.
     * Previous 1 [2] 3 4 5 6 Next
     *
     * @param string url URL with pagination
     * @param string parameters UL attributes to adding
     * @return string HTML
     */
    public function minimal(string url = null, array parameters = [])
    {
        var html, query, i18n, title;
        int i;

        // Prepare list
        let html = this->_tag->tagHtml("ul", parameters, ["class": "pagination"]),
            query = this->_di->{"getRequest"}()->getQuery(),
            i18n = this->_di->get("i18n");

        // Prepare previous
        if this->get("current") > this->get("previous") {
            query->set("page", this->get("previous"));

            let title = i18n ? i18n->translate("previous") : null,
                html .= "<li>" . this->_tag->a([url, "&lsaquo;", title, "query": query->all(), "rel": "prev"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&lsaquo;</span></li>";
        }

        // Prepare pages
        for i in range(1, this->get("pages")) {
            if i !== this->get("current") {
                query->set("page", i);

                let title = i18n ? i18n->translate("page: %d", [i]) : null,
                    html .= "<li>" . this->_tag->a([url, i, title, "query": query->all()]) . "</li>";
            } else {
                let title = i18n ? i18n->translate("current") : null,
                    html .= "<li class=\"active\" title=\"" . title . "\"><span>" . i . "</span></li>";
            }
        }

        // Prepare next
        if this->get("current") < this->get("next") {
            query->set("page", this->get("next"));

            let title = i18n ? i18n->translate("next") : null,
                html .= "<li>" . this->_tag->a([url, "&rsaquo;", title, "query": query->all(), "rel": "next"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&rsaquo;</span></li>";
        }

        // Close list
        let html .= this->_tag->endTag("ul");

        return html;
    }

    /**
     * Prepare basic pagination.
     * First Previous 1 [2] 3 4 5 6 Next Last
     *
     * @param string url URL with pagination
     * @param string parameters UL attributes to adding
     * @return string HTML
     */
    public function basic(string url = null, array parameters = [])
    {
        var html, query, i18n, title;
        int i;

        // Prepare list
        let html = this->_tag->tagHtml("ul", parameters, ["class": "pagination"]),
            query = this->_di->{"getRequest"}()->getQuery(),
            i18n = this->_di->get("i18n");

        // Prepare first
        if this->get("current") != this->get("first") {
            query->remove("page");

            let title = i18n ? i18n->translate("first") : null,
                html .= "<li>" . this->_tag->a([url, "&laquo;", title, "query": query->all(), "rel": "first"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&laquo;</span></li>";
        }

        // Prepare previous
        if this->get("current") > this->get("previous") {
            query->set("page", this->get("previous"));

            let title = i18n ? i18n->translate("previous") : null,
                html .= "<li>" . this->_tag->a([url, "&lsaquo;", title, "query": query->all(), "rel": "prev"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&lsaquo;</span></li>";
        }

        // Prepare pages
        for i in range(1, this->get("pages")) {
            if i !== this->get("current") {
                query->set("page", i);

                let title = i18n ? i18n->translate("page: %d", [i]) : null,
                    html .= "<li>" . this->_tag->a([url, i, title, "query": query->all()]) . "</li>";
            } else {
                let title = i18n ? i18n->translate("current") : null,
                    html .= "<li class=\"active\" title=\"" . title . "\"><span>" . i . "</span></li>";
            }
        }

        // Prepare next
        if this->get("current") < this->get("next") {
            query->set("page", this->get("next"));

            let title = i18n ? i18n->translate("next") : null,
                html .= "<li>" . this->_tag->a([url, "&rsaquo;", title, "query": query->all(), "rel": "next"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&rsaquo;</span></li>";
        }

        // Prepare last
        if this->get("current") != this->get("last") {
            query->set("page", this->get("last"));

            let title = i18n ? i18n->translate("last") : null,
                html .= "<li>" . this->_tag->a([url, "&raquo;", title, "query": query->all(), "rel": "last"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&raquo;</span></li>";
        }

        // Close list
        let html .= this->_tag->endTag("ul");

        return html;
    }


    /**
     * Prepare floating pagination.
     * First Previous 1 2 3 ... 23 24 25 26 [27] 28 29 30 31 ... 48 49 50 Next Last
     *
     * @param string url URL with pagination
     * @param string parameters UL attributes to adding
     * @param int countOut Number of page links in the begin and end of whole range
     * @param int countIn Number of page links on each side of current page
     * @return string HTML
     */
    public function floating(string url = null, array parameters = [], int countOut = 0, int countIn = 2)
    {
        var html, query, i18n, title, links, number, content;
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
        let html = this->_tag->tagHtml("ul", parameters, ["class": "pagination"]),
            query = this->_di->{"getRequest"}()->getQuery(),
            i18n = this->_di->get("i18n");

        // Prepare first
        if this->get("current") != this->get("first") {
            query->remove("page");

            let title = i18n ? i18n->translate("first") : null,
                html .= "<li>" . this->_tag->a([url, "&laquo;", title, "query": query->all(), "rel": "first"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&laquo;</span></li>";
        }

        // Prepare previous
        if this->get("current") > this->get("previous") {
            query->set("page", this->get("previous"));

            let title = i18n ? i18n->translate("previous") : null,
                html .= "<li>" . this->_tag->a([url, "&lsaquo;", title, "query": query->all(), "rel": "prev"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&lsaquo;</span></li>";
        }

        // Prepare pages
        for number, content in links {
            if number !== this->get("current") {
                query->set("page", number);

                let title = i18n ? i18n->translate("page: %d", [number]) : null,
                    html .= "<li>" . this->_tag->a([url, content, title, "query": query->all(), "class": content == "&hellip;" ? "text-muted" : ""]) . "</li>";
            } else {
                let title = i18n ? i18n->translate("current") : null,
                    html .= "<li class=\"active\" title=\"" . title . "\"><span>" . content . "</span></li>";
            }
        }

        // Prepare next
        if this->get("current") < this->get("next") {
            query->set("page", this->get("next"));

            let title = i18n ? i18n->translate("next") : null,
                html .= "<li>" . this->_tag->a([url, "&rsaquo;", title, "query": query->all(), "rel": "next"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&rsaquo;</span></li>";
        }

        // Prepare last
        if this->get("current") != this->get("last") {
            query->set("page", this->get("last"));

            let title = i18n ? i18n->translate("last") : null,
                html .= "<li>" . this->_tag->a([url, "&raquo;", title, "query": query->all(), "rel": "last"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&raquo;</span></li>";
        }

        // Close list
        let html .= this->_tag->endTag("ul");

        return html;
    }
}
