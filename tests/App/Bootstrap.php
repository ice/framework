<?php

namespace Tests\App;

use Ice\Di;
use Ice\Db;
use Ice\Config;
use Ice\Auth\Driver\Db as Auth;

class Bootstrap
{
    private $di;

    public function __construct(array $services)
    {
        $this->di = new Di();

        foreach ($services as $service) {
            $this->$service();
        }
    }

    public function getDi()
    {
        return $this->di;
    }

    public function config()
    {
        $this->di->set('config', function () {
            return new Config(__ROOT__ . '/tests/ci/ice_test.php');
        });
    }

    public function db()
    {
        $config = $this->di->config;

        $this->di->set('db', function () use ($config) {
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
    }

    public function mongo()
    {
        $config = $this->di->config;

        $this->di->set('mongo', function () use ($config) {
            $db = new Db(
                $config->mongodb->type,
                $config->mongodb->host,
                $config->mongodb->port,
                $config->mongodb->name,
                $config->mongodb->user,
                $config->mongodb->password,
                $config->mongodb->options->toArray()
            );

            return $db;
        });
    }

    public function auth()
    {
        $config = $this->di->config;

        $this->di->auth = new Auth($config->auth->toArray());
    }
}
