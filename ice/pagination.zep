
namespace Ice;

use Ice\Di;
use Ice\Arr;
use Ice\Exception;
use Ice\Di\DiInterface;

/**
 * Provide the multi-page pagination component.
 *
 * @package     Ice/Pagination
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014 Ice Team
 * @license     http://iceframework.org/license
 */
class Pagination extends Arr
{

    /**
     * Returns a slice of the resultset to show in the pagination
     *
     * @return object Pagination
     */
    public function calculate() -> <Pagination>
    {
        var items, floor, data;
        int limit, page, pages, total, before, next;

        let items  = this->get("data", []);

        if typeof items != "array" && !(items instanceof \Traversable) {
            throw new Exception("Invalid data for pagination");
        }

        let limit  = (int) this->get("limit", 10),
            page = (int) this->get("page", 1),
            total = count(items),
            floor = floor(total / intval(limit)),
            pages = (int) floor;

        if floor <= 0 {
            let pages = 1;
        }

        if page <= 0 {
            let page = 1;
        }

        if items instanceof Arr {
            let data = items->all();
        } else {
            let data = items;
        }

        this->set("items", array_slice(data, limit * (page - 1), limit));

        if page < pages {
            let next = page + 1;
        } else {
            let next = pages;
        }

        this->set("next", next);

        if page > 1 {
            let before = page - 1;
        } else {
            let before = 1;
        }

        this->replace([
            "first": 1,
            "before": before,
            "current": page,
            "last": pages,
            "pages": pages,
            "total": total
        ]);

        return this;
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
        var html, di, tag, i18n, query, links, number, content;
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

        // Fetch services
        let di = Di::$fetch(),
            tag = di->getTag(),
            i18n = di->getI18n(),
            query = di->getRequest()->getGet(),
            url = url ? url : substr(query->get("_url"), 1);

        query->set("page", 1);
        query->remove("_url");

        // Prepare list
        let html = tag->tagHtml("ul", parameters, ["class": "pagination"]);

        // Prepare First button
        if this->get("current") != this->get("first") {
            query->remove("page");

            let html .= "<li>" . tag->a([url, "&laquo;", i18n->_("First"), "query": query->all(), "rel": "first"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&laquo;</span></li>";
        }
 
        // Prepare Previous button
        if this->get("current") > this->get("before") {
            query->set("page", this->get("before"));

            let html .= "<li>" . tag->a([url, "&lsaquo;", i18n->_("Previous"), "query": query->all(), "rel": "prev"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&lsaquo;</span></li>";
        }

        // Prepare Pages
        for number, content in links {
            if number !== this->get("current") {
                query->set("page", number);

                let html .= "<li>" . tag->a([url, content, "query": query->all(), "class": content == "&hellip;" ? "text-muted" : ""]) . "</li>";
            } else {
                let html .= "<li class=\"active\"><span>" . content . "</span></li>";
            }
        }

        // Prepare Next button
        if this->get("current") < this->get("next") {
            query->set("page", this->get("next"));

            let html .= "<li>" . tag->a([url, "&rsaquo;", i18n->_("Next"), "query": query->all(), "rel": "next"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&rsaquo;</span></li>";
        }

        // Prepare Last button
        if this->get("current") != this->get("last") {
            query->set("page", this->get("last"));

            let html .= "<li>" . tag->a([url, "&raquo;", i18n->_("Last"), "query": query->all(), "rel": "last"]) . "</li>";
        } else {
            let html .= "<li class=\"disabled\"><span>&raquo;</span></li>";
        }

        // Close list
        let html .= tag->endTag("ul");

        return html;
    }
}
