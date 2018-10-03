
namespace Ice\Mvc;

use Ice\Di;
use Ice\Exception;

/**
 * Routes are used to determine the controller and action for a requested URI.
 * Every route generates a regular expression which is used to match a URI
 * and a route. Routes may also contain keys which can be used to set the
 * controller, action, and parameters.
 *
 * Each {key} will be translated to a regular expression using a default
 * regular expression pattern. You can override the default pattern by providing
 * a pattern for the key:
 *
 * <pre><code>
 *     // This route will only match when {id} is a digit
 *     Route::set("blog", "blog/{action}/{id}", ["id" => "\d+"], ['GET', 'POST']);
 *
 *     // This route will match when {path} is anything
 *     Route::set("file", "{path}", ["path" => ".*"]);
 * </code></pre>
 *
 * It is also possible to create optional segments by using parentheses in
 * the URI definition:
 *
 * <pre><code>
 *     // This is the standard default route, and no keys are required
 *     Route::set('default', '[{controller}[/{action}[/{id}]][.json]]');
 *
 *     // This route only requires the {file} key
 *     Route::set('file', '[{path}/]{file}[.{ext}]', ['path' => '.*', 'ext' => '\w+']);
 * </code></pre>
 *
 * Routes also provide a way to generate URIs (called "reverse routing"), which
 * makes them an extremely powerful and flexible way to generate internal links.
 *
 * <pre><code>
 *     // route: blog/post/10
 *     $uri = $route->uri(["handle" => "blog", "action" => "post", "id" => 10]);
 * </code></pre
 */
class Route
{
    // Route URI string
    protected routeUri = "";

    // Regular expressions for route keys
    protected routeKeys = [];

    // Compiled regex cache
    protected routeRegex;

    // default module
    protected defaultModule = "default" { get, set };

    // default handler
    protected defaultHandler = "index" { get, set };

    // default action
    protected defaultAction = "index" { get, set };

    protected method { get };
    protected module { get };
    protected handler { get };
    protected action { get };
    protected params = [] { get };
    protected silent = false { get, set };
    protected error { get };

    // Defines the pattern of a <placeholder>
    const REGEX_KEYWORD = "\{([a-zA-Z0-9_]++)\}";

    // What can be part of a <placeholder> value
    const REGEX_PLACEHOLDER = "[^/.,;?\n]++";

    // What must be escaped in the route regex
    const REGEX_ESCAPE = "[.\\+*?^$=!|]";

}
