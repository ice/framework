<?php

namespace Tests;

use PHPUnit_Framework_TestCase as PHPUnit;
use Ice\Di;
use Ice\Mvc\FastRouter;

class FastRouteTest extends PHPUnit
{

    private static $di;

    public static function setUpBeforeClass()
    {
        $di = new Di();
        $di->router = new FastRouter();
        $di->router->setRoutes(self::routes());
        $di->router->setDefaultModule('frontend');

        self::$di = $di;
    }

    public static function tearDownAfterClass()
    {
        self::$di = null;
    }

    public function __get($service)
    {
        return self::$di->{$service};
    }

    /**
     * Test route matching for universal routes and GET method
     *
     * @dataProvider GETrouteProvider
     */
    public function testUniversalGET($pattern, $expected)
    {
        $return = $this->router->handle('GET', $pattern);

        $this->assertEquals('GET', $this->router->getMethod());

        if (is_array($return)) {
            $this->assertEquals(
                $expected,
                [
                    $this->router->getModule(),
                    $this->router->getHandler(),
                    $this->router->getAction(),
                    $this->router->getParams()
                ],
                $pattern
            );
        } else {
            $this->assertEquals($expected, null, "The route wasn't matched by any route");
        }
    }

    /**
     * Test route matching for universal routes and POST method
     *
     * @dataProvider POSTrouteProvider
     */
    public function testUniversalPOST($pattern, $expected)
    {
        $return = $this->router->handle('POST', $pattern);

        $this->assertEquals('POST', $this->router->getMethod());

        if (is_array($return)) {
            $this->assertEquals(
                $expected,
                [
                    $this->router->getModule(),
                    $this->router->getHandler(),
                    $this->router->getAction(),
                    $this->router->getParams()
                ],
                $pattern
            );
        } else {
            $this->assertEquals($expected, null, "The route wasn't matched by any route");
        }
    }

    public static function routes()
    {
        return [
            ['GET', '/license', ['controller' => 'info', 'action' => 'license']],
            ['POST', '/{controller:info}/{action:contact}'],
            // Routes for doc module
            ['GET', '/{module:doc}/{controller:[a-z]+}/{action:[a-z]+}/{param}'],
            ['GET', '/{module:doc}/{controller:[a-z]+}/{action:[a-z]+[/]?}'],
            ['GET', '/{module:doc}/{controller:[a-z]+[/]?}'],
            ['GET', '/{module:doc+[/]?}'],
            // Routes for default module
            ['GET', '/{controller:[a-z]+}/{action:[a-z]+}/{param}'],
            ['GET', '/{controller:[a-z]+}/{action:[a-z]+[/]?}'],
            ['GET', '/{controller:[a-z]+[/]?}'],
            ['GET', ''],
        ];
    }

    /**
     * Routes provider for GET method
     * [pattern, expected route: [module, handler, action, [params]]]
     *
     * @return array
     */
    public function GETrouteProvider()
    {
        return [
            ['', ['frontend', 'index', 'index', []]],
            ['/index', ['frontend', 'index', 'index', []]],
            ['/index/index', ['frontend', 'index', 'index', []]],
            ['/index/test', ['frontend', 'index', 'test', []]],
            ['/info', ['frontend', 'info', 'index', []]],
            ['/info/', ['frontend', 'info', 'index', []]],
            ['/info/download', ['frontend', 'info', 'download', []]],
            ['/info/contact', ['frontend', 'info', 'contact', []]],

            ['/lang/set/en-gb', ['frontend', 'lang', 'set', ['param' => 'en-gb']]],

            ['/doc', ['doc', 'index', 'index', []]],
            ['/doc/index', ['doc', 'index', 'index', []]],
            ['/doc/index/index', ['doc', 'index', 'index', []]],
            ['/doc/index/test', ['doc', 'index', 'test', []]],
            
            ['/doc/install', ['doc', 'install', 'index', []]],
            ['/doc/install/requirements', ['doc', 'install', 'requirements', []]],
            ['/doc/install/requirements/php', ['doc', 'install', 'requirements', ['param' => 'php']]],
        ];
    }

    /**
     * Routes provider for POST method
     * [pattern, expected route: [module, handler, action, [params]]]
     *
     * @return array
     */
    public function POSTrouteProvider()
    {
        return [
            ['/info/contact', ['frontend', 'info', 'contact', []]],
        ];
    }
}
