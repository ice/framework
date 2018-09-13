<?php

if (!defined('__ROOT__')) {
    define('__ROOT__', dirname(__DIR__));
}

(new Ice\Loader())
    ->addNamespace('App', __ROOT__ . '/App')
    ->addNamespace('Tests', __ROOT__ . '/tests')
    ->register();

include_once __ROOT__ . '/vendor/autoload.php';
