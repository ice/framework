<?php

if (!defined('__ROOT__')) {
    define('__ROOT__', dirname(__DIR__));
}

(new Ice\Loader())
    ->addNamespace('App', __ROOT__ . '/app')
    ->addNamespace('Tests', __ROOT__ . '/tests')
    ->register();
