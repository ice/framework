<?php

namespace Tests;

use PHPUnit_Framework_TestCase as PHPUnit;
use Ice\Mvc\View\Engine\Sleet\Parser;

class SleetTest extends PHPUnit
{

    private static $parser;

    public static function setUpBeforeClass()
    {
        self::$parser = $parser = new Parser();
    }

    public static function tearDownAfterClass()
    {
        self::$parser = null;
    }

    /**
     * @dataProvider stringProvider
     */
    public function testParser($content, $expected)
    {
        $parsed = self::$parser->text($content);

        $this->assertEquals($expected, $parsed, $content);
    }

    public function stringProvider()
    {
        /**
         * input, expected parser output
         */
        return [
            // Not parse
            ['hello', 'hello'],
            ['{ hello }', '{ hello }'],
            // Comments
            ['lorem {# hello #}ipsum{# other comment #} dolor', 'lorem ipsum dolor'],
            ["lorem {#\n hello \n\n other comment \n#} dolor", 'lorem  dolor'],
            // ECHO
            ['{{ "hello" }}', '<?php echo "hello" ?>'],
            ['{{ "hello" }}{{ "hello" }}', '<?php echo "hello" ?><?php echo "hello" ?>'],
            ['{{ "hello" }}-{{ "hello" }}', '<?php echo "hello" ?>-<?php echo "hello" ?>'],
            ['-{{ "hello" }}{{ "hello" }}-', '-<?php echo "hello" ?><?php echo "hello" ?>-'],
            ['-{{ "hello" }}-{{ "hello" }}-', '-<?php echo "hello" ?>-<?php echo "hello" ?>-'],
            ['Some = {{ 100+50 }}', 'Some = <?php echo 100 + 50 ?>'],
            ['Some = {{ 100-50 }}', 'Some = <?php echo 100 - 50 ?>'],
            ['Some = {{ 100*50 }}', 'Some = <?php echo 100 * 50 ?>'],
            ['Some = {{ 100/50 }}', 'Some = <?php echo 100 / 50 ?>'],
            ['Some = {{ 100%50 }}', 'Some = <?php echo 100 % 50 ?>'],
            ['Some = {{ 100~50 }}', 'Some = <?php echo 100 . 50 ?>'],
            // Unary operators
            ['{{ !10 }}', '<?php echo !10 ?>'],
            ['{{ !a }}', '<?php echo !$a ?>'],
            ['{{ not a }}', '<?php echo !$a ?>'],
            // Array acccess
            ['{{ a[0 ]}}', '<?php echo $a[0] ?>'],
            ['{{ a[0 ] [ 1]}}', '<?php echo $a[0][1] ?>'],
            ['{{ a[0]  [ "hello"] }}', '<?php echo $a[0]["hello"] ?>'],
            ['{{ a[0] [1.2] [false] [true] }}', '<?php echo $a[0][1.2][false][true] ?>'],
            // Attribute access
            ['{{ a.b }}', '<?php echo $a->b ?>'],
            ['{{ a.b.c }}', '<?php echo $a->b->c ?>'],
            // Calling functions
            ['{{ content() }}', '<?php echo $this->getContent() ?>'],
            ['{{ partial("hello/x") }}', '<?php echo $this->partial("hello/x") ?>'],
            ['{{ dump(a) }}', '<?php echo $this->dump->vars($a) ?>'],
            ['{{ date("Y-m-d", time()) }}', '<?php echo date("Y-m-d", time()) ?>'],
            ['{{ users.getPosts(a) }}', '<?php echo $users->getPosts($a) ?>'],
            // Tag helpers
            ['{{ link_to(["hello", "some-link"]) }}', '<?php echo $this->tag->linkTo(["hello", "some-link"]) ?>'],
            ['{{ form(["action": "save/products", "method": "post"]) }}',
                '<?php echo $this->tag->form(["action" => "save/products", "method" => "post"]) ?>'],
            ['{{ style([config.cdn.css.bootstrap, config.cdn.local]) }}',
                '<?php echo $this->tag->style([$config->cdn->css->bootstrap, $config->cdn->local]) ?>'],
            ['{{ script(["js/some.js"]) }}', '<?php echo $this->tag->script(["js/some.js"]) ?>'],
            ['{{ image(["img/logo.png", "width": 80]) }}',
                '<?php echo $this->tag->image(["img/logo.png", "width" => 80]) ?>'],
            ['{{ a(["/", img(["img/logo.png", "width": 80])]) }}',
                '<?php echo $this->tag->a(["/", $this->tag->img(["img/logo.png", "width" => 80])]) ?>'],
            // Calling services
            ['{{ this.url.get("contact") }}', '<?php echo $this->url->get("contact") ?>'],
            ['{{ this.tag.a(["user", "Account"]) }}', '<?php echo $this->tag->a(["user", "Account"]) ?>'],
            // Filters
            ['{{ user|trim }}', '<?php echo trim($user) ?>'],
            /** ['{{ user["username"]|isset }}', '<?php echo isset($user["username"]) ?>'], */
            ['{{ user|e }}', '<?php echo $this->filter->sanitize($user, \'e\') ?>'],
            ['{{ 9800.333|number_format(2, ".", ",") }}', '<?php echo number_format(9800.333, 2, ".", ",") ?>'],
            // Mixed
            ['{{ "User " ~ a([user.name, trim(user[fullname])]) }}',
                '<?php echo "User " . $this->tag->a([$user->name, trim($user[$fullname])]) ?>'],
            ['{{ __("Click :url", [":url": link_to([this.url.getStatic("i"), "Link" ]) ]) }}',
                '<?php echo __("Click :url", [":url" => $this->tag->linkTo([$this->url->getStatic("i"), "Link"])]) ?>'],
            // CONTROL, ASSIGNMENTS, CONDITONS
            // Set statement
            ['{% set a = 1 %}', '<?php $a = 1; ?>'],
            ['{% set a = a-1 %}', '<?php $a = $a - 1; ?>'],
            ['{% set a = 1.2 %}', '<?php $a = 1.2; ?>'],
            ['{% set a = 1.2+1*(20/b) and c %}', '<?php $a = 1.2 + 1 * (20 / $b) && $c; ?>'],
            // Use namespace
            ['{% use Ice\Filter %}', '<?php use Ice\Filter; ?>'],
            ['{% use App\Models\Users as User %}', '<?php use App\Models\Users as User; ?>'],
            // Control Structures
            ['{% for i=0; i<10; i++ %} lorem {% endfor %}', '<?php for($i = 0;$i < 10;$i++): ?> lorem <?php endfor ?>'],
            ['{% foreach users as key: user %} {{ key ~ ": " ~ user.id }} {% endforeach %}',
                '<?php foreach($users as $key => $user): ?> <?php echo $key . ": " . $user->id ?> <?php endforeach ?>'],
            ['{% while i<10 %} lorem {% var i++ %}{% endwhile %}',
                '<?php while($i < 10): ?> lorem <?php $i++; ?><?php endwhile ?>'],
            ['{% switch a %}{% case 1 %}one{% break %}{% default %}def{% break %}{% endswitch %}',
                '<?php switch($a): ?><?php case(1): ?>one<?php break; ?><?php default: ?>def<?php break; ?>' .
                '<?php endswitch ?>'],
            // If statement
            ['{% if a==b %} hello {% endif %}', '<?php if($a == $b): ?> hello <?php endif ?>'],
            ['{% if a!=b %} hello {% endif %}', '<?php if($a != $b): ?> hello <?php endif ?>'],
            ['{% if a<b %} hello {% endif %}', '<?php if($a < $b): ?> hello <?php endif ?>'],
            ['{% if a>b %} hello {% endif %}', '<?php if($a > $b): ?> hello <?php endif ?>'],
            ['{% if a>=b %} hello {% endif %}', '<?php if($a >= $b): ?> hello <?php endif ?>'],
            ['{% if a<=b %} hello {% endif %}', '<?php if($a <= $b): ?> hello <?php endif ?>'],
            ['{% if a===b %} hello {% endif %}', '<?php if($a === $b): ?> hello <?php endif ?>'],
            ['{% if a!==b %} hello {% endif %}', '<?php if($a !== $b): ?> hello <?php endif ?>'],
            ['{% if a==b and c==d %} hello {% endif %}', '<?php if($a == $b && $c == $d): ?> hello <?php endif ?>'],
            ['{% if a==b or c==d %} hello {% endif %}', '<?php if($a == $b || $c == $d): ?> hello <?php endif ?>'],
            // If else
            ['{% if a==b %} hello {% else %} not hello {% endif %}',
                '<?php if($a == $b): ?> hello <?php else: ?> not hello <?php endif ?>'],
            ['{% if a==b %} {% if c==d %}hi{% endif %} {% else %}bye{% endif %}',
                '<?php if($a == $b): ?> <?php if($c == $d): ?>hi<?php endif ?> <?php else: ?>bye<?php endif ?>'],
            ['{% if a==b %} {% if c==d %}hi{% else %}bye{% endif %}{% endif %}',
                '<?php if($a == $b): ?> <?php if($c == $d): ?>hi<?php else: ?>bye<?php endif ?><?php endif ?>'],
            ['{% if a==b %}hi{% else %} {% if c==d %}bye{% endif %} {% endif %}',
                '<?php if($a == $b): ?>hi<?php else: ?> <?php if($c == $d): ?>bye<?php endif ?> <?php endif ?>'],
            // If elseif
            ['{% if a==b %} hello {% elseif a==c %} world {% endif %}',
                '<?php if($a == $b): ?> hello <?php elseif($a == $c): ?> world <?php endif ?>'],
            // Short if
            ['{{ user["username"] ? "OK" : "FAIL" }}', '<?php echo $user["username"] ? "OK" : "FAIL" ?>'],
            ['{{ user["fullname"] ? user["fullname"] : user["username"] }}',
                '<?php echo $user["fullname"] ? $user["fullname"] : $user["username"] ?>'],
            ['{% set b = a ? ["key": "a"] : ["key": "b"] %}', '<?php $b = $a ? ["key" => "a"] : ["key" => "b"]; ?>'],
        ];
    }
}
