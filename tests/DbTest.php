<?php

namespace Tests;

use PHPUnit_Framework_TestCase as PHPUnit;
use Ice\Arr;
use Ice\Di;
use Ice\Db;
use Ice\Config;

class DbTest extends PHPUnit
{

    private static $di;

    public static function setUpBeforeClass()
    {
        $di = new Di();
        $config = new Config(__ROOT__ . '/tests/ci/ice_test.php');

        $di->set('db', function () use ($config) {
            $db = new Db(
                $config->mysql->type,
                $config->mysql->host,
                $config->mysql->port,
                $config->mysql->name,
                $config->mysql->user,
                $config->mysql->password,
                $config->mysql->options
            );

            return $db;
        });

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
     * Test find one
     *
     * @dataProvider roles
     */
    public function testFindOne($from, $filters, $expected)
    {
        $return = $this->db->findOne($from, $filters);

        if (is_array($expected)) {
            $expected = new Arr($expected);
        }

        $this->assertEquals($expected, $return);
    }

    /**
     * Roles
     *
     * @return array
     */
    public function roles()
    {
        return [
            ['roles', 1, ['id' => 1, 'name' => 'login', 'description' => 'Login privileges, granted after account confirmation']],
            ['roles', ['name' => 'admin'], ['id' => 2, 'name' => 'admin', 'description' => 'Administrative user, has access to everything.']],
            ['roles', ['name' => 'mod'], false],
        ];
    }
}
