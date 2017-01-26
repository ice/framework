<?php

namespace Tests;

use PHPUnit_Framework_TestCase as PHPUnit;
use Ice\Di;
use Ice\I18n;
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
        $data = [
            'emailAddress' => '',
            'repeatEmailAddress' => 'user@example.com',
        ];

        $validation = new Validation();

        $validation->rules([
            'emailAddress' => 'required|email',
        ]);

        $valid = $validation->validate($data);
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field emailAddress is required"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());

        // Add extra rules
        $validation->rules([
            'repeatEmailAddress' => 'same:emailAddress'
        ]);

        $valid = $validation->validate($data);
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

        // Add wrong value and revalidate
        $data['emailAddress'] = 'test';

        $valid = $validation->validate($data);
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field emailAddress must be an email address"
            ],
            "repeatEmailAddress" => [
                0 => "Field repeatEmailAddress and emailAddress must match"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());

        // Overwrite the rules
        $validation->rules([
            'emailAddress' => 'required|email'
        ], false);

        $valid = $validation->validate($data);
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field emailAddress must be an email address"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());

        // Pass right data, but do not clear the old messages
        $data['emailAddress'] = 'user@example.com';

        $valid = $validation->validate($data, false);
        $this->assertFalse($valid);

        $expected = [
            "emailAddress" => [
                0 => "Field emailAddress must be an email address"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());

        // Pass the rules
        $valid = $validation->validate($data);
        $this->assertTrue($valid);
        $this->assertSame([], $validation->getMessages()->all());
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

    public function testTranslate()
    {
        $di = Di::fetch();
        $di->i18n = new I18n([
            'lang' => 'pl-pl',
            'dir' => __DIR__ . '/i18n/'
        ]);

        $validation = new Validation([
            'firstName' => '',
            'lastName' => 'Framework',
        ]);

        $validation->rules([
            'firstName' => 'required|email',
            'lastName' => 'with:firstName'
        ]);


        $valid = $validation->validate();
        $this->assertFalse($valid);

        $expected = [
            "firstName" => [
                0 => "Pole Imię jest wymagane"
            ],
            "lastName" => [
                0 => "Pole Nazwisko musi wystąpić, wraz z Imię"
            ]
        ];

        $this->assertSame($expected, $validation->getMessages()->all());
    }
}
