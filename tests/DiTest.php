<?php

namespace Tests;

use PHPUnit\Framework\TestCase;
use Ice\Arr;
use Ice\Config;
use Tests\App\Bootstrap;

class DiTest extends TestCase
{
    private static $di;

    public static function setUpBeforeClass(): void
    {
        self::$di = (new Bootstrap(['config']))->getDi();
    }

    public static function tearDownAfterClass(): void
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
