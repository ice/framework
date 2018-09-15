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
     * Users
     *
     * @return array
     */
    public function users()
    {
        return [
            [['email' => 'user@example.com', 'username' => 'user', 'password' => 'password']],
            [['email' => 'user2@example.com', 'username' => 'user2', 'password' => 'password2']],
            [['email' => 'user3@example.com', 'username' => 'user3', 'password' => 'password3']],
            [['email' => 'admin@example.com', 'username' => 'admin', 'password' => 'password']],
            [['email' => 'admin2@example.com', 'username' => 'admin2', 'password' => 'password2']],
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
            [['user_id' => 1, 'title' => 'Post 1', 'content' => 'Post 1 content', 'status' => 1]],
            [['user_id' => 2, 'title' => 'Post 2', 'content' => 'Post 2 content', 'status' => 1]],
            [['user_id' => 3, 'title' => 'Post 3', 'content' => 'Post 3 content', 'status' => 1]],
            [['user_id' => 1, 'title' => 'Post 4', 'content' => 'Post 4 content', 'status' => 0]],
            [['user_id' => 1, 'title' => 'Post 5', 'content' => 'Post 5 content', 'status' => 1]],
            [['user_id' => 2, 'title' => 'Post 6', 'content' => 'Post 6 content', 'status' => 1]],
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
            [['user_id' => 1, 'post_id' => 1, 'content' => 'Post 1 comment 1', 'status' => 1]],
            [['user_id' => 2, 'post_id' => 1, 'content' => 'Post 1 comment 2', 'status' => 1]],
            [['user_id' => 3, 'post_id' => 1, 'content' => 'Post 1 comment 3', 'status' => 1]],
            [['user_id' => 1, 'post_id' => 1, 'content' => 'Post 1 comment 4', 'status' => 0]],
            [['user_id' => 1, 'post_id' => 1, 'content' => 'Post 1 comment 5', 'status' => 1]],
            [['user_id' => 2, 'post_id' => 1, 'content' => 'Post 1 comment 6', 'status' => 1]],

            [['user_id' => 1, 'post_id' => 2, 'content' => 'Post 2 comment 1', 'status' => 1]],
            [['user_id' => 2, 'post_id' => 2, 'content' => 'Post 2 comment 2', 'status' => 1]],
            [['user_id' => 3, 'post_id' => 2, 'content' => 'Post 2 comment 3', 'status' => 1]],

            [['user_id' => 1, 'post_id' => 3, 'content' => 'Post 3 comment 1', 'status' => 0]],
            [['user_id' => 2, 'post_id' => 3, 'content' => 'Post 3 comment 2', 'status' => 0]],

            [['user_id' => 2, 'post_id' => 4, 'content' => 'Post 4 comment 1', 'status' => 1]],

            [['user_id' => 3, 'post_id' => 5, 'content' => 'Post 5 comment 1', 'status' => 1]],
            [['user_id' => 4, 'post_id' => 5, 'content' => 'Post 5 comment 2', 'status' => 1]],
        ];
    }
}
