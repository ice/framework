<?php

namespace Tests;

use PHPUnit_Framework_TestCase as PHPUnit;
use Ice\Exception;
use Ice\Arr;
use Tests\App\Bootstrap;
use Tests\App\Models\Roles;
use Tests\App\Models\MongoRoles;

class ModelTest extends PHPUnit
{
    private static $di;

    public static function setUpBeforeClass()
    {
        self::$di = (new Bootstrap(['config', 'db', 'mongo']))->getDi();
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
    public function testFindOne($filters, $expected)
    {
        $return = Roles::findOne($filters);

        if ($return instanceof Roles) {
            $return = $return->getData();
        }

        $this->assertEquals($expected, $return);
    }

    /**
     * Test construct
     *
     * @dataProvider roles
     */
    public function testConstruct($filters, $expected)
    {
        $role = new Roles($filters);

        if ($expected) {
            $data = $role->getData();
            $this->assertEquals($expected, $data);
        } else {
            $this->assertFalse($role->exists());
        }
    }

    /**
     * Test find one
     *
     * @dataProvider roles
     */
    public function testMongoFindOne($filters, $expected)
    {
        $return = MongoRoles::findOne($filters);

        if ($return instanceof MongoRoles) {
            // Remove the ObjectId
            unset($return['_id']);

            $return = $return->getData();
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
            [['id' => 1], ['id' => '1', 'name' => 'login', 'description' => 'Login privileges, granted after account confirmation.']],
            [['name' => 'admin'], ['id' => '2', 'name' => 'admin', 'description' => 'Administrative user, has access to everything.']],
            [['name' => 'mod'], false],
        ];
    }
}
