<?php return [
    'mysql' => [
        'type'     => 'mysql',
        'host'     => 'localhost',
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
        'host'     => 'localhost',
        'port'     => 27017,
        'user'     => 'root',
        'password' => 'password',
        'name'     => 'ice_test',
        'options' => [
            'authMechanism' => 'MONGODB-CR',
        ],
    ],
];
