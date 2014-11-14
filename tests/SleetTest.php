<?php
namespace Tests;

use PHPUnit_Framework_TestCase as PHPUnit;
use Ice\Mvc\View\Engine\Sleet\Parser;

class SleetTest extends PHPUnit
{

    /**
     * @dataProvider stringProvider
     */
    public function testParser($content, $expected)
    {
        $parser = new Parser();
        $parsed = $parser->line($content);

        $this->assertEquals($expected, $parsed, $content);
    }

    public function stringProvider()
    {
        /**
         * input, expected parser output
         */
        return [
            // ECHO
            ['hello', 'hello'],
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
            /**['{{ -10 }}', '<?php echo -10 ?>'],*/
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
            ['{{ form(["action": "save/products", "method": "post"]) }}', '<?php echo $this->tag->form(["action" => "save/products", "method" => "post"]) ?>'],
            ['{{ style([config.cdn.css.bootstrap, config.cdn.local]) }}', '<?php echo $this->tag->style([$config->cdn->css->bootstrap, $config->cdn->local]) ?>'],
            ['{{ script(["js/some.js"]) }}', '<?php echo $this->tag->script(["js/some.js"]) ?>'],
            ['{{ image(["img/logo.png", "width": 80]) }}', '<?php echo $this->tag->image(["img/logo.png", "width" => 80]) ?>'],
            ['{{ a(["/", img(["img/logo.png", "width": 80])]) }}', '<?php echo $this->tag->a(["/", $this->tag->img(["img/logo.png", "width" => 80])]) ?>'],
            // Calling services
            ['{{ url("contact") }}', '<?php echo $this->url->get("contact") ?>'],
            ['{{ this.tag.a(["user", "Account"]) }}', '<?php echo $this->tag->a(["user", "Account"]) ?>'],
            // Filters
            ['{{ user|trim }}', '<?php echo trim($user) ?>'],
            /** ['{{ user["username"]|isset }}', '<?php echo isset($user["username"]) ?>'], */
            ['{{ user|e }}', '<?php echo $this->filter->sanitize($user, \'e\') ?>'],
            ['{{ 9800.333|number_format(2, ".", ",") }}', '<?php echo number_format(9800.333, 2, ".", ",") ?>'],
            // Mixed
            ['{{ "User " ~ a([user.name, trim(user[fullname])]) }}', '<?php echo "User " . $this->tag->a([$user->name, trim($user[$fullname])]) ?>'],
            ['{{ user["username"] ? "OK" : "FAIL" }}', '<?php echo $user["username"] ? "OK" : "FAIL" ?>'],
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
            ['{% foreach users as key: user %} {{ key ~ ": " ~ user.username }} {% endforeach %}', '<?php foreach($users as $key => $user): ?> <?php echo $key . ": " . $user->username ?> <?php endforeach ?>'],
            ['{% while i<10 %} lorem {% var i++ %}{% endwhile %}', '<?php while($i < 10): ?> lorem <?php $i++; ?><?php endwhile ?>'],
            ['{% switch a %}{% case 1 %}first{% break %}{% default %}def{% break %}{% endswitch %}', '<?php switch($a): ?><?php case(1): ?>first<?php break; ?><?php default: ?>def<?php break; ?><?php endswitch ?>'],
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
            ['{% if a==b %} hello {% else %} not hello {% endif %}', '<?php if($a == $b): ?> hello <?php else: ?> not hello <?php endif ?>'],
            ['{% if a==b %} {% if c==d %} hello {% endif %} {% else %} not hello {% endif %}', '<?php if($a == $b): ?> <?php if($c == $d): ?> hello <?php endif ?> <?php else: ?> not hello <?php endif ?>'],
            ['{% if a==b %} {% if c==d %} hello {% else %} not hello {% endif %}{% endif %}', '<?php if($a == $b): ?> <?php if($c == $d): ?> hello <?php else: ?> not hello <?php endif ?><?php endif ?>'],
            ['{% if a==b %} hello {% else %} {% if c==d %} not hello {% endif %} {% endif %}', '<?php if($a == $b): ?> hello <?php else: ?> <?php if($c == $d): ?> not hello <?php endif ?> <?php endif ?>'],
            // If elseif
            ['{% if a==b %} hello {% elseif a==c %} world {% endif %}', '<?php if($a == $b): ?> hello <?php elseif($a == $c): ?> world <?php endif ?>'],
            /**
              ['{% if a is defined %} hello {% endif %}' , '<?php if($a==$b): ?> hello <?php endif ?>'],
              ['{% if a is not defined %} hello {% endif %}' , '<?php if($a==$b): ?> hello <?php endif ?>'],
              ['{% if a is 100 %} hello {% endif %}' , '<?php if($a == 100): ?> hello <?php endif ?>'],
              ['{% if a is not 100 %} hello {% endif %}' , '<?php if($a != 100): ?> hello <?php endif ?>'],
              ['{% if a["key"] is not definied %} hello {% endif %}' , '<?php if(!isset($a["key"]): ?> hello <?php endif ?>'],
              ['{% if a is odd %} hello {% endif %}', '<?php if($a) % 2) != 0)): ?> hello <?php endif ?>'],
              ['{% if a is even %} hello {% endif %}', '<?php if(((($a) % 2) == 0)): ?> hello <?php endif ?>'],
              ['{% if a is empty %} hello {% endif %}', '<?php if(empty($a)): ?> hello <?php endif ?>'],
              ['{% if a is numeric %} hello {% endif %}', '<?php if(is_numeric($a)): ?> hello <?php endif ?>'],
              ['{% if a is scalar %} hello {% endif %}', '<?php if(is_scalar($a)): ?> hello <?php endif ?>'],
              ['{% if a is iterable %} hello {% endif %}', '<?php if((is_array($a) || ($a) instanceof Traversable)): ?> hello <?php endif ?>'],
              ['{% if a is sameas(false) %} hello {% endif %}', '<?php if(($a) === (false)): ?> hello <?php endif ?>'],
              ['{% if a is sameas(b) %} hello {% endif %}', '<?php if(($a) === ($b)): ?> hello <?php endif ?>'],
              ['{% if a is divisibleby(3) %} hello {% endif %}', '<?php if(((($a) % (3)) == 0)): ?> hello <?php endif ?>'],
              ['{% if a is divisibleby(b) %} hello {% endif %}', '<?php if(((($a) % ($b)) == 0)): ?> hello <?php endif ?>'],
              ['{% if a is defined %} hello {% endif %}', '<?php if(isset($a)): ?> hello <?php endif ?>'],
              ['{% if a is not defined %} hello {% endif %}', '<?php if(!isset($a)): ?> hello <?php endif ?>'],
              ['{% if a is empty or a is defined %} hello {% else %} not hello {% endif %}', '<?php if(empty($a) || isset($a)): ?> hello <?php else: ?> not hello <?php endif ?>'],
              ['{% if a is even or b is odd %} hello {% else %} not hello {% endif %}', '<?php if (((($a) % 2) == 0) || ((($b) % 2) != 0)): ?> hello <?php else: ?> not hello <?php endif ?>'],
             */
        ];
    }
}
