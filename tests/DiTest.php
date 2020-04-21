<?php

namespace Tests;

use PHPUnit_Framework_TestCase as PHPUnit;
use Ice\Arr;
use Ice\Config;
use Tests\App\Bootstrap;

class DbTest extends PHPUnit
{
    private static $di;

    public static function setUpBeforeClass()
    {
        self::$di = (new Bootstrap(['config']))->getDi();
    }

    public static function tearDownAfterClass()
    {
        self::$di = null;
    }

    /**
     * Test magic call
     *
     * @dataProvider services
     */
    public function testGetMagicService($method, $expected)
    {
        $di = self::$di;

        $this->assertInstanceOf($expected, $di->{$method}());
        $this->assertInstanceOf($expected, $di->{$method}());
    }

    /**
     * Services
     *
     * @return array
     */
    public function services()
    {
        return [
            ['getConfig', Config::class],
        ];
    }
}
