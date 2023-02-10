<?php

namespace Tests;

use PHPUnit\Framework\TestCase;
use Ice\Arr;
use Tests\App\Bootstrap;

class DbTest extends TestCase
{
    private static $di;

    public static function setUpBeforeClass(): void
    {
        self::$di = (new Bootstrap(['config', 'db', 'mongo']))->getDi();
    }

    public static function tearDownAfterClass(): void
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

    public function testMongoAddRoles()
    {
        $roles = $this->mongo->find('roles');

        if (!$roles->count()) {
            $insert = $this->mongo->insert('roles', [
                'id' => 1,
                'name' => 'login',
                'description' => 'Login privileges, granted after account confirmation.',
            ]);
            $this->assertTrue($insert);

            $insert = $this->mongo->insert('roles', [
                'id' => 2,
                'name' => 'admin',
                'description' => 'Administrative user, has access to everything.',
            ]);
            $this->assertTrue($insert);
        }
    }

    /**
     * Test find one
     *
     * @dataProvider roles
     */
    public function testMongoFindOne($from, $filters, $expected)
    {
        $return = $this->mongo->findOne($from, $filters);

        if ($return instanceof Arr) {
            // Remove the ObjectId
            unset($return['_id']);
        }

        if (is_array($expected)) {
            $expected = new Arr($expected);
        }

        $this->assertEquals($expected, $return);
    }

    public function testRolesCount()
    {
        $return = $this->db->count('roles');
        $this->assertEquals(2, $return);

        $return = $this->db->count('roles', ['name' => 'admin']);
        $this->assertEquals(1, $return);

        $return = $this->mongo->count('roles');
        $this->assertEquals(2, $return);

        $return = $this->mongo->count('roles', ['name' => 'admin']);
        $this->assertEquals(1, $return);
    }

    /**
     * Roles
     *
     * @return array
     */
    public static function roles()
    {
        return [
            ['roles', ['id' => 1], ['id' => 1, 'name' => 'login', 'description' => 'Login privileges, granted after account confirmation.']],
            ['roles', ['name' => 'admin'], ['id' => 2, 'name' => 'admin', 'description' => 'Administrative user, has access to everything.']],
            ['roles', ['name' => 'mod'], false],
        ];
    }
}
