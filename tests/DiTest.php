<?php

namespace Tests;

use PHPUnit\Framework\TestCase;
use Ice\Arr;
use Ice\Config;
use Ice\Config\Json;
use Ice\Di;
use Ice\Cli\Dispatcher;
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
    public static function services()
    {
        return [
            ['getConfig', Config::class],
        ];
    }

    /**
     * Test set service
     */
    public function testCliDefaultService()
    {
        $di = new Di();

        $this->assertInstanceOf(Dispatcher::class, $di->dispatcher);
    }

    /**
     * Test set service
     *
     * @dataProvider configs
     * @param mixed $service
     */
    public function testSetDefaultService($service)
    {
        $di = new Di();

        $di->config = $service;
        $this->assertInstanceOf(Config::class, $di->config);
    }

    /**
     * Configs
     *
     * @return array
     */
    public static function configs()
    {
        yield 'Set object' => [
            new Config(['key' => 'value'])
        ];

        yield 'Set by class name' => [
            Config::class
        ];

        yield 'Set anonymous function' => [
            function () {
                return new Config(['key' => 'value']);
            }
        ];

        yield 'Set arrow function' => [
            fn() => new Config(['key' => 'value'])
        ];

        yield 'Set array to default' => [
            [['key' => 'value']]
        ];

        yield 'Set class in the key' => [
            [Json::class => '{"key":"value"}']
        ];
    }
}
