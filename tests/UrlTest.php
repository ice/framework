<?php

namespace Tests;

use PHPUnit\Framework\TestCase;
use Ice\Mvc\Url;

class UrlTest extends TestCase
{
    private static $url;

    public static function setUpBeforeClass(): void
    {
        self::$url = new Url();
    }

    public static function tearDownAfterClass(): void
    {
        self::$url = null;
    }

    /**
    * @dataProvider staticUrls
    */
    public function testGetStatic($uri, $expected, $static = '/')
    {
        self::$url->setStaticUri($static);
        $this->assertEquals(self::$url->getStatic($uri), $expected);
    }


    public static function staticUrls()
    {
        yield ['style.css', '/style.css'];
        yield ['/style.css', '/style.css'];
        yield ['style.css', 'https://www.iceframework.org/style.css', 'https://www.iceframework.org/'];
        yield ['/style.css', 'https://www.iceframework.org/style.css', 'https://www.iceframework.org/'];
    }

    /**
     * @dataProvider urls
     */
    public function testGet($args, $expected, $base = '/')
    {
        self::$url->setBaseUri($base);
        $this->assertEquals(self::$url->get(...$args), $expected);
    }

    public static function urls()
    {
        yield [[null, [], true], '/'];
        yield [[null, [], true], '/blog/', '/blog/'];

        yield [['about-us', [], true], '/about-us',];
        yield [['about-us', [], true], '/blog/about-us',  '/blog/'];

        yield [['search', ['k' => 'v'], true], '/search?k=v'];
        yield [['search?v=1.0', ['k' => 'v'], true], '/search?v=1.0&k=v'];

        yield [['https://example.com/about-us', [], false], 'https://example.com/about-us'];
        yield [['https://example.com/about-us', ['k' => 'v'], false], 'https://example.com/about-us?k=v'];

        yield [['//google.com', [], false], '//google.com'];
        yield [['#javascript', [], false], '#javascript'];
        yield [['?query-string', [], false], '?query-string'];

        yield [['mailto:noreply@iceframework.org', [], false], 'mailto:noreply@iceframework.org'];
        yield [['skype:iceframework', [], false], 'skype:iceframework'];
    }
}
