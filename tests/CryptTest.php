<?php

namespace Tests;

use PHPUnit_Framework_TestCase as PHPUnit;
use Ice\Crypt;

class CryptTest extends PHPUnit
{

    private static $crypt;

    public static function setUpBeforeClass()
    {
        self::$crypt = new Crypt('0123456789ABCDEF');
    }

    /**
     * @dataProvider stringProvider
     */
    public function testEncrypt($content)
    {
        $encrypted = self::$crypt->encrypt($content);
        $decrypted = self::$crypt->decrypt($encrypted);

        $this->assertEquals($content, $decrypted);
    }

    public function stringProvider()
    {
        /**
         * input
         */
        return [
            ['hello'],
            ['12e54511931f2c3ab37b8ba92bc1b643d261c045'],
            ['Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/40.0.2214.93 Safari/537.36'],
            ['1\x00\x00\x00\x00\x00\x00\x001\x00\x00\x00\x00\x00\x00'],
        ];
    }
}
