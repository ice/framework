<?php

namespace Tests;

use PHPUnit_Framework_TestCase as PHPUnit;
use Ice\Di;
use Ice\Tag;
use Ice\Mvc\Url;

class TagTest extends PHPUnit
{

    private static $di;

    public static function setUpBeforeClass()
    {
        $di = new Di();
        $di->url = new Url();
        $di->tag = new Tag();


        $_POST = [
            'somePOST' => 'some_post',
            'SETPOST' => 'some_post',
            'checkPOST' => 'on_post',
            'contentPOST' => 'text_post',
        ];

        $di->tag->setValues([
            'someSET' => 'some_default',
            'SETPOST' => 'some_default',
            'checkSET' => 'on_default',
            'contentSET' => 'text_default',
        ]);

        self::$di = $di;
    }

    public static function tearDownAfterClass()
    {
        self::$di = null;
    }

    public function __get($key)
    {
        return self::$di->{$key};
    }

    public function testTitle()
    {
        $this->tag->setTitle('Home');
        $expected = 'Home';
        $this->assertEquals($expected, $this->tag->getTitle());

        $this->tag->appendTitle('example.com', ' | ');
        $expected = 'Home | example.com';
        $this->assertEquals($expected, $this->tag->getTitle());

        $this->tag->prependTitle('Hello');
        $expected = 'Hello - Home | example.com';
        $this->assertEquals($expected, $this->tag->getTitle());

        $this->tag->setTitleSeparator(' / ');
        $this->tag->prependTitle('Hi');
        $this->tag->prependTitle('Hey');
        $expected = 'Hey / Hi / Hello - Home | example.com';
        $this->assertEquals($expected, $this->tag->getTitle());
    }

    /**
     * @dataProvider tagProvider
     */
    public function testTag($method, $parameters, $expected)
    {
        $output = $this->tag->{$method}($parameters);
        $this->assertEquals($expected, $output, json_encode($parameters));
    }

    public function tagProvider()
    {
        /**
         * input, parameters, expected output
         */
        return [
            // Text field
            ['textField', ['some'], '<input type="text" id="some" name="some">'],
            ['textField', ['some', 'some_value'], '<input type="text" id="some" name="some" value="some_value">'],
            ['textField', ['somePOST'], '<input type="text" id="somePOST" name="somePOST" value="some_post">'],
            ['textField', ['someSET'], '<input type="text" id="someSET" name="someSET" value="some_default">'],
            ['textField', ['SETPOST'], '<input type="text" id="SETPOST" name="SETPOST" value="some_post">'],
            ['textField', ['some', 'id' => 'some1'], '<input type="text" id="some1" name="some">'],
            ['textField', ['name' => 'some', 'id' => 'some1'], '<input type="text" id="some1" name="some">'],
            ['textField', ['some', 'some_value', 'id' => 'some1', 'class' => 'field', 'style' => 'width: 100%'],
                '<input type="text" id="some1" name="some" value="some_value" class="field" style="width: 100%">'],
            // Mixed fields
            ['passwordField', ['pass'], '<input type="password" id="pass" name="pass">'],
            ['fileField', ['picture'], '<input type="file" id="picture" name="picture">'],
            ['hiddenField', ['secret'], '<input type="hidden" id="secret" name="secret">'],
            ['submitButton', ['some', 'Submit'], '<input type="submit" id="some" name="some" value="Submit">'],
            ['submitButton', ['some', 'value' => 'Submit', 'id' => 'some1', 'class' => 'btn'],
                '<input type="submit" id="some1" name="some" value="Submit" class="btn">'],
            // Button tag
            ['button', ['some', 'Submit'], '<button type="submit" id="some" name="some">Submit</button>'],
            ['button', ['some', 'Submit', 'value' => 'some_value'],
                '<button type="submit" id="some" name="some" value="some_value">Submit</button>'],
            ['button', ['someSET', 'Submit'],
                '<button type="submit" id="someSET" name="someSET" value="some_default">Submit</button>'],
            ['button', ['somePOST', 'Submit'],
                '<button type="submit" id="somePOST" name="somePOST" value="some_post">Submit</button>'],
            ['button', ['some', '<i class="icon">+</i> ' . 'Submit', 'type' => 'button', 'id' => 'some1'],
                '<button type="button" id="some1" name="some"><i class="icon">+</i> Submit</button>'],
            // Checkbox
            ['checkField', ['terms', 'on'], '<input type="checkbox" id="terms" name="terms" value="on">'],
            ['checkField', ['terms', 'on', 'checked' => 'checked'],
                '<input type="checkbox" id="terms" name="terms" value="on" checked="checked">'],
            ['checkField', ['checkPOST', 'on_post'],
                '<input type="checkbox" id="checkPOST" name="checkPOST" value="on_post" checked="checked">'],
            ['checkField', ['checkSET', 'on_default'],
                '<input type="checkbox" id="checkSET" name="checkSET" value="on_default" checked="checked">'],
            // Radio
            ['radioField', ['sex', 'male'], '<input type="radio" id="sex" name="sex" value="male">'],
            ['radioField', ['sex', 'male', 'checked' => 'checked'],
                '<input type="radio" id="sex" name="sex" value="male" checked="checked">'],
            ['radioField', ['checkPOST', 'on_post'],
                '<input type="radio" id="checkPOST" name="checkPOST" value="on_post" checked="checked">'],
            ['radioField', ['checkSET', 'on_default'],
                '<input type="radio" id="checkSET" name="checkSET" value="on_default" checked="checked">'],
            // Form tag
            ['form', [false], '<form method="post">'],
            ['form', [null, 'method' => 'get'], '<form action="/" method="get">'],
            ['form', ['http://example.com', 'local' => false], '<form action="http://example.com" method="post">'],
            ['form', ['post/add', 'enctype' => 'multipart/form-data', 'class' => 'form-horizontal'],
                '<form action="/post/add" class="form-horizontal" method="post" enctype="multipart/form-data">'],
            // Text area
            ['textArea', ['content'], '<textarea id="content" name="content"></textarea>'],
            ['textArea', ['content', 'Text'], '<textarea id="content" name="content">Text</textarea>'],
            ['textArea', ['contentSET', 'Text'],
                '<textarea id="contentSET" name="contentSET">text_default</textarea>'],
            ['textArea', ['contentPOST', 'Text'], '<textarea id="contentPOST" name="contentPOST">text_post</textarea>'],
            // Image tag
            ['image', ['img/logo.png'], '<img src="/img/logo.png">'],
            ['image', ['img/logo.png', 'Logo'], '<img src="/img/logo.png" alt="Logo">'],
            ['img', ['img/logo.png', 'class' => 'img-rounded'], '<img src="/img/logo.png" class="img-rounded">'],
            ['image', ['http://example.com/img/logo.png', 'Logo', 'local' => false],
                '<img src="http://example.com/img/logo.png" alt="Logo">'],
            // Hyperlinks
            ['linkTo', [null, 'Home'], '<a href="/">Home</a>'],
            ['linkTo', ['post/add', 'Add', 'Add a post'], '<a href="/post/add" title="Add a post">Add</a>'],
            ['linkTo', ['//google.com', 'Google', 'local' => false], '<a href="//google.com">Google</a>'],
            ['linkTo', ['mailto:noreply@iceframework.org', 'Mail', 'local' => false],
                '<a href="mailto:noreply@iceframework.org">Mail</a>'],
            ['a', ['http://google.com', 'Google', 'local' => false], '<a href="http://google.com">Google</a>'],
            // Meta link
            ['link', ['css/app.css'], '<link rel="stylesheet" type="text/css" href="/css/app.css">' . PHP_EOL],
            ['link', ['favicon.ico', "type" => "image/x-icon", "rel" => "icon"],
                '<link rel="icon" type="image/x-icon" href="/favicon.ico">' . PHP_EOL],
            // Script tag
            ['script', ['js/plugins.js'], '<script type="text/javascript" src="/js/plugins.js"></script>' . PHP_EOL],
            ['script', ['content' => 'alert("OK");'], '<script type="text/javascript">alert("OK");</script>' . PHP_EOL],
            // Style tag
            ['style', ['body { color: #444 }'], "<style type=\"text/css\">\nbody { color: #444 }\n</style>\n"],
            // End tag
            ['endTag', 'form', "</form>\n"],
        ];
    }

    /**
     * @dataProvider tagXHTMLProvider
     */
    public function testTagXHTML($input, $parameters, $expected)
    {
        $this->tag->setDocType(Tag::XHTML5);
        $output = $this->tag->{$input}($parameters);
        $this->assertEquals($expected, $output, json_encode($parameters));
    }

    public function tagXHTMLProvider()
    {
        /**
         * input, parameters, expected output
         */
        return [
            ['textField', ['some'], '<input type="text" id="some" name="some" />'],
            ['passwordField', ['pass'], '<input type="password" id="pass" name="pass" />'],
            ['fileField', ['picture'], '<input type="file" id="picture" name="picture" />'],
            ['hiddenField', ['secret'], '<input type="hidden" id="secret" name="secret" />'],
            ['submitButton', ['some', 'Submit'], '<input type="submit" id="some" name="some" value="Submit" />'],
            ['form', [false], '<form method="post">'],
            ['image', ['img/logo.png'], '<img src="/img/logo.png" />'],
            ['textArea', ['content'], '<textarea id="content" name="content"></textarea>'],
            ['button', ['some', 'Submit'], '<button type="submit" id="some" name="some">Submit</button>'],
            ['linkTo', [null, 'Home'], '<a href="/">Home</a>'],
            ['link', ['css/app.css'], '<link rel="stylesheet" type="text/css" href="/css/app.css" />' . PHP_EOL],
            ['script', ['js/plugins.js'], '<script type="text/javascript" src="/js/plugins.js"></script>' . PHP_EOL],
            ['endTag', 'form', "</form>\n"],
        ];
    }

    public function testFriendlyTitle()
    {
        $title = "Mess'd up --text-- just (to) stress /test/ ?our! `little` \\clean\\ url fun.ction!?-->";
        $friendly = $this->tag->friendlyTitle($title);
        $expected = 'messd-up-text-just-to-stress-test-our-little-clean-url-function';
        $this->assertEquals($expected, $friendly);

        $title = "Perché l'erba è verde?";
        $friendly = $this->tag->friendlyTitle($title, "-", true, "'");
        $expected = 'perche-l-erba-e-verde';
        $this->assertEquals($expected, $friendly);

        $title = "Perché l'erba è verde?";
        $friendly = $this->tag->friendlyTitle($title, "_", false);
        $expected = 'Perche_lerba_e_verde';
        $this->assertEquals($expected, $friendly);

        $title = "Perché l'erba è verde?";
        $friendly = $this->tag->friendlyTitle($title, "_", false, ['e', 'a']);
        $expected = 'P_rch_l_rb_v_rd';
        $this->assertEquals($expected, $friendly);
    }

    public function testSelect()
    {
        $options = [0 => 'Unactive', 1 => 'Active'];
        $output = $this->tag->select(['status', $options]);
        $expected = '<select id="status" name="status">' . PHP_EOL .
            '<option value="0">Unactive</option>' . PHP_EOL .
            '<option value="1">Active</option>' . PHP_EOL .
            '</select>' . PHP_EOL;
        $this->assertEquals($expected, $output);

        $this->tag->setValue('timeZone', 'Europe/Warsaw');

        $options = ['Europe' => ['Europe/London' => 'London', 'Europe/Warsaw' => 'Warsaw']];
        $output = $this->tag->select(['timeZone', $options]);
        $expected = '<select id="timeZone" name="timeZone">' . PHP_EOL .
            '<optgroup label="Europe">' . PHP_EOL .
            '<option value="Europe/London">London</option>' . PHP_EOL .
            '<option value="Europe/Warsaw" selected="selected">Warsaw</option>' . PHP_EOL .
            '</optgroup>' . PHP_EOL .
            '</select>' . PHP_EOL;
        $this->assertEquals($expected, $output);
    }
}
