<?php

namespace Tests;

use PHPUnit_Framework_TestCase as PHPUnit;
use Ice\Exception;
use Ice\Arr;
use Ice\Auth\Driver\Model\Roles;
use Ice\Auth\Driver\Model\Roles\Users as AuthRolesUsers;
use Tests\App\Bootstrap;
use Tests\App\Models\Users;
use Tests\App\Models\Posts;
use Tests\App\Models\Comments;
use Tests\App\Services\UserService;

class ModelsTest extends PHPUnit
{
    private static $di;

    public static function setUpBeforeClass()
    {
        self::$di = (new Bootstrap(['config', 'db', 'auth']))->getDi();
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
     * Test create
     *
     * @dataProvider users
     */
    public function test1CreateUsers($data)
    {
        $user = new Users(null, $data);
        $this->assertTrue($user->create());

        $login = new AuthRolesUsers();
        $login->user_id = $user->getId();
        $login->role_id = Roles::findOne(['name' => 'login'])->getId();

        $this->assertTrue($login->create());

        if (strpos($user->username, 'admin') === 0) {
            $admin = new AuthRolesUsers();
            $admin->user_id = $user->getId();
            $admin->role_id = Roles::findOne(['name' => 'admin'])->getId();

            $this->assertTrue($admin->create());
        }
    }

    /**
     * Test create
     *
     * @dataProvider posts
     */
    public function test2CreatePosts($data)
    {
        $post = new Posts;
        $this->assertTrue($post->create($data));
    }

    /**
     * Test create
     *
     * @dataProvider comments
     */
    public function test3CreateComments($data)
    {
        $comment = new Comments;
        $comment->replace($data);
        $this->assertTrue($comment->save());
    }

    /**
     * Find related model
     */
    public function test4GetRelated()
    {
        $post = Posts::findOne(1);

        $this->assertEquals(6, count($post->getComments()));
        $this->assertEquals(5, count($post->getComments(['status' => 1])));

        foreach ($post->getComments(null, ['order' => ['id' => 'DESC']]) as $key => $comment) {
            if (!$key) {
                $this->assertEquals(6, $comment->getId());
                $this->assertEquals(2, $comment->getUser()->getId());
                $this->assertEquals(2, $comment->getUser()->getPosts());
                $this->assertEquals(4, $comment->getUser()->getComments(['status', 1]));
            }

            $this->assertInstanceOf(Comments::class, $comment);
            $this->assertInstanceOf(Users::class, $comment->getUser());
        }

        $user = $post->getUser();
        $this->assertEquals(1, $user->getId());
        $userComments = $user->getComments();
        $this->assertEquals(5, count($userComments));

        $this->assertEquals(3, count(Comments::find(['status' => 0])));

        $post = Posts::findOne(2);
        $this->assertEquals(2, count($post->getComments(null, ['limit' => 2])));
        $this->assertEquals(new Arr, $post->getComments(['status' => 0]));

        $post = Posts::findOne(6);
        $this->assertEquals(new Arr, $post->getComments());
    }

    /**
     * Service access test
     */
    public function testService()
    {
        $service = new UserService(new Users());

        $this->assertInstanceOf(\Ice\Di::class, $service->di);
        $this->assertInstanceOf(\Ice\Config::class, $service->config);
        $this->assertInstanceOf(\Ice\Db::class, $service->db);

        $service->loadOne(1);
        $this->assertEquals(1, $service->getId());
        $this->assertEquals('user@example.com', $service->get('email'));
    }

    /**
     * Update test
     */
    public function testUpdate()
    {
        $user = Users::findOne(1);
        $this->assertEquals(1, $user->id);
        $this->assertEquals(0, $user->logins);
        $user->update(['logins' => 1]);
        $this->assertEquals(1, $user->id);
        $this->assertEquals(1, $user->logins);
        $user->logins++;
        $user->update(['logins']);
        $this->assertEquals(1, $user->id);
        $this->assertEquals(2, $user->logins);
    }

    /**
     * Users
     *
     * @return array
     */
    public function users()
    {
        return [
            [['id'=>1, 'email' => 'user@example.com', 'username' => 'user', 'password' => 'password']],
            [['id'=>2, 'email' => 'user2@example.com', 'username' => 'user2', 'password' => 'password2']],
            [['id'=>3, 'email' => 'user3@example.com', 'username' => 'user3', 'password' => 'password3']],
            [['id'=>4, 'email' => 'admin@example.com', 'username' => 'admin', 'password' => 'password']],
            [['id'=>5, 'email' => 'admin2@example.com', 'username' => 'admin2', 'password' => 'password2']],
        ];
    }

    /**
     * Posts
     *
     * @return array
     */
    public function posts()
    {
        return [
            [['id'=>1, 'user_id' => 1, 'title' => 'Post 1', 'content' => 'Post 1 content', 'status' => 1]],
            [['id'=>2, 'user_id' => 2, 'title' => 'Post 2', 'content' => 'Post 2 content', 'status' => 1]],
            [['id'=>3, 'user_id' => 3, 'title' => 'Post 3', 'content' => 'Post 3 content', 'status' => 1]],
            [['id'=>4, 'user_id' => 1, 'title' => 'Post 4', 'content' => 'Post 4 content', 'status' => 0]],
            [['id'=>5, 'user_id' => 1, 'title' => 'Post 5', 'content' => 'Post 5 content', 'status' => 1]],
            [['id'=>6, 'user_id' => 2, 'title' => 'Post 6', 'content' => 'Post 6 content', 'status' => 1]],
        ];
    }

    /**
     * Comments
     *
     * @return array
     */
    public function comments()
    {
        return [
            [['id'=>1, 'user_id' => 1, 'post_id' => 1, 'content' => 'Post 1 comment 1', 'status' => 1]],
            [['id'=>2, 'user_id' => 2, 'post_id' => 1, 'content' => 'Post 1 comment 2', 'status' => 1]],
            [['id'=>3, 'user_id' => 3, 'post_id' => 1, 'content' => 'Post 1 comment 3', 'status' => 1]],
            [['id'=>4, 'user_id' => 1, 'post_id' => 1, 'content' => 'Post 1 comment 4', 'status' => 0]],
            [['id'=>5, 'user_id' => 1, 'post_id' => 1, 'content' => 'Post 1 comment 5', 'status' => 1]],
            [['id'=>6, 'user_id' => 2, 'post_id' => 1, 'content' => 'Post 1 comment 6', 'status' => 1]],

            [['id'=>7, 'user_id' => 1, 'post_id' => 2, 'content' => 'Post 2 comment 1', 'status' => 1]],
            [['id'=>8, 'user_id' => 2, 'post_id' => 2, 'content' => 'Post 2 comment 2', 'status' => 1]],
            [['id'=>9, 'user_id' => 3, 'post_id' => 2, 'content' => 'Post 2 comment 3', 'status' => 1]],

            [['id'=>10, 'user_id' => 1, 'post_id' => 3, 'content' => 'Post 3 comment 1', 'status' => 0]],
            [['id'=>11, 'user_id' => 2, 'post_id' => 3, 'content' => 'Post 3 comment 2', 'status' => 0]],

            [['id'=>12, 'user_id' => 2, 'post_id' => 4, 'content' => 'Post 4 comment 1', 'status' => 1]],

            [['id'=>13, 'user_id' => 3, 'post_id' => 5, 'content' => 'Post 5 comment 1', 'status' => 1]],
            [['id'=>14, 'user_id' => 4, 'post_id' => 5, 'content' => 'Post 5 comment 2', 'status' => 1]],
        ];
    }
}
