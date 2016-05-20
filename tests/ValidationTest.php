<?php

namespace Tests;

use PHPUnit_Framework_TestCase as PHPUnit;
use Ice\Di;
use Ice\Validation;
use Ice\Validation\Validator\Email;
use Ice\Validation\Validator\Required;
use Ice\Validation\Validator\Same;

class ValidationTest extends PHPUnit
{

    private static $di;

    public static function setUpBeforeClass()
    {
        $di = new Di();
    }

    public function testRule()
    {
        $validation = new Validation([
            'emailAddress' => '',
            'repeatEmailAddress' => 'user@example.com',
        ]);

        $validation->rule('emailAddress', new Required());
        $validation->rule('emailAddress', new Email());
        $validation->rule('repeatEmailAddress', new Same(['other' => 'emailAddress']));

        $valid = $validation->validate();
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field emailAddress is required"
            ],
            "repeatEmailAddress" => [
                0 => "Field repeatEmailAddress and emailAddress must match"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());
    }

    public function testRules()
    {
        $validation = new Validation([
            'emailAddress' => '',
            'repeatEmailAddress' => 'user@example.com',
        ]);

        $validation->rules([
            'emailAddress' => [
                new Required(),
                new Email()
            ],
            'repeatEmailAddress' => new Same(['other' => 'emailAddress'])
        ]);

        $valid = $validation->validate();
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field emailAddress is required"
            ],
            "repeatEmailAddress" => [
                0 => "Field repeatEmailAddress and emailAddress must match"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());
    }

    public function testArray()
    {
        $validation = new Validation([
            'emailAddress' => '',
            'repeatEmailAddress' => 'user@example.com',
        ]);

        $validation->rules([
            'emailAddress' => [
                'required',
                'email'
            ],
            'repeatEmailAddress' => [
                'same' => [
                    'other' => 'emailAddress'
                ]
            ]
        ]);

        $valid = $validation->validate();
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field emailAddress is required"
            ],
            "repeatEmailAddress" => [
                0 => "Field repeatEmailAddress and emailAddress must match"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());
    }

    public function testShort()
    {
        $validation = new Validation([
            'emailAddress' => '',
            'repeatEmailAddress' => 'user@example.com',
        ]);

        $validation->rules([
            'emailAddress' => 'required|email',
            'repeatEmailAddress' => 'same:emailAddress'
        ]);

        $valid = $validation->validate();
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field emailAddress is required"
            ],
            "repeatEmailAddress" => [
                0 => "Field repeatEmailAddress and emailAddress must match"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());
    }

    public function testRevalidate()
    {
        $validation = new Validation([
            'emailAddress' => '',
            'repeatEmailAddress' => 'user@example.com',
        ]);

        $validation->rules([
            'emailAddress' => 'required|email',
            'repeatEmailAddress' => 'same:emailAddress'
        ]);

        $valid = $validation->validate();
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field emailAddress is required"
            ],
            "repeatEmailAddress" => [
                0 => "Field repeatEmailAddress and emailAddress must match"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());

        $validation->rules([
            'emailAddress' => 'email'
        ], true);

        $valid = $validation->revalidate(['emailAddress' => 'test']);
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field emailAddress must be an email address"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());
    }

    public function testHuman()
    {
        $validation = new Validation([
            'emailAddress' => '',
            'repeatEmailAddress' => 'user@example.com',
        ]);

        $validation->setHumanLabels(true);

        $validation->rules([
            'emailAddress' => 'required|email',
            'repeatEmailAddress' => 'same:emailAddress'
        ]);

        $valid = $validation->validate();
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field Email address is required"
            ],
            "repeatEmailAddress" => [
                0 => "Field Repeat email address and Email address must match"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());
    }

    public function testLabel()
    {
        $validation = new Validation([
            'emailAddress' => '',
            'repeatEmailAddress' => 'user@example.com',
        ]);

        $validation->setHumanLabels(true);

        $validation->rules([
            'emailAddress' => 'required|email',
            'repeatEmailAddress' => 'same:emailAddress'
        ]);

        $validation->setLabels([
            'emailAddress' => 'E-mail'
        ]);

        $valid = $validation->validate();
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field E-mail is required"
            ],
            "repeatEmailAddress" => [
                0 => "Field Repeat email address and E-mail must match"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());
    }

    public function testCustom()
    {
        $validation = new Validation([
            'emailAddress' => '',
            'repeatEmailAddress' => 'user@example.com',
        ]);

        $validation->setHumanLabels(true);

        $validation->rules([
            'emailAddress' => 'required|email',
            'repeatEmailAddress' => [
                'same' => [
                    'other' => 'emailAddress',
                    'message' => ':field must be the same as :other',
                    'label' => 'Repeat E-mail',
                    'labelOther' => 'E-mail'
                ]
            ]
        ]);

        $valid = $validation->validate();
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field Email address is required"
            ],
            "repeatEmailAddress" => [
                0 => "Repeat E-mail must be the same as E-mail"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());
    }

    public function testFilters()
    {
        $validation = new Validation();
        $validation->setFilters([
            'username' => 'alpha',
            'status' => 'int',
            'male' => 'bool'
        ]);

        $validation->validate([
            'username' => 'ice-123_framework',
            'status' => '1',
            'male' => '1'
        ]);

        // Get value without filters
        $this->assertSame('ice-123_framework', $validation->getValue('username', false));
        $this->assertSame('1', $validation->getValue('status', false));
        $this->assertSame('1', $validation->getValue('male', false));

        // Get values with filters
        $expected = [
            'username' => 'iceframework',
            'status' => 1,
            'male' => true
        ];

        $this->assertSame($expected, $validation->getValues());
    }
}
