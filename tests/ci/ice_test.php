<?php return [
    'mysql' => [
        'type'     => 'mysql',
        'host'     => '127.0.0.1',
        'port'     => 3306,
        'user'     => 'root',
        'password' => '',
        'name'     => 'ice_test',
        'options'  => [
            PDO::MYSQL_ATTR_INIT_COMMAND => 'set names utf8',
        ],
    ],
    'mongodb' => [
        'type'     => 'mongodb',
        'host'     => '127.0.0.1',
        'port'     => 27017,
        'user'     => 'root',
        'password' => 'password',
        'name'     => 'ice_test',
        'options' => [
            'authMechanism' => 'SCRAM-SHA-256',
            'authSource'    => 'admin'
        ],
    ],
    'auth' => [
        'hash_method' => "sha256",
        'hash_key'    => "secret_key",
        'lifetime'    => 1209600,
        'users'       => 'Tests\\App\\Models\\Users',
    ],
];
