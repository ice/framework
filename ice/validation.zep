
namespace Ice;

use Ice\Validation\Validator;

/**
 * Allows to validate array data.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        Ice\Filter (if service is available)
 * @uses        Ice\I18n (if service is available)
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *  
 *  $validation->rules([
 *      'fullName' => 'required',
 *      'email' => 'required|email',
 *      'repeatEmail' => 'same:email',
 *      'about' => 'required|length:10,5000',
 *  ]);
 *  
 *  $valid = $validation->validate($_POST);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
class Validation
{

    protected di { get };
    protected data { get };
    protected rules = [] { set, get };
    protected validators = [];
    protected filters = [] { set };
    protected labels = [] { set };
    protected messages = [];
    protected valid = true;
    protected aliases = [] { set };
    protected translate = true { set, get };
    protected humanLabels = false { set };
    protected defaultMessages = [
        "alnum": "Field :field must contain only letters and numbers",
        "alpha": "Field :field must contain only letters",
        "between": "Field :field must be within the range of :min to :max",
        "digit": "Field :field must be numeric",
        "default": "Field :field is not valid",
        "email": "Field :field must be an email address",
        "fileEmpty": "Field :field must not be empty",
        "fileIniSize": "File :field exceeds the maximum file size",
        "fileMaxResolution": "File :field must not exceed :max resolution",
        "fileMinResolution": "File :field must be at least :min resolution",
        "fileSize": "File :field exceeds the size of :max",
        "fileType": "File :field must be of type: :types",
        "in": "Field :field must be a part of list: :values",
        "lengthMax": "Field :field must not exceed :max characters long",
        "lengthMin": "Field :field must be at least :min characters long",
        "notIn": "Field :field must not be a part of list: :values",
        "regex": "Field :field does not match the required format",
        "required": "Field :field is required",
        "same": "Field :field and :other must match",
        "unique": "Field :field must be unique",
        "url": "Field :field must be a url",
        "with": "Field :field must occur together with :fields",
        "without": "Field :field must not occur together with :fields"
    ];

    /**
     * Validation constructor. Fetch Di and set the data if given.
     *
     * @param array data Data to validate
     */
    public function __construct(array data = [])
    {
        let this->di = Di::$fetch(),
            this->data = new Arr(data);
    }

    /**
     * Resolve one rule.
     *
     * @param string alias
     * @param string field
     * @param mixed options
     * @return object Validation
     */
    public function resolve(string alias, string field, var options = null)
    {
        var rule;

        if !fetch rule, this->aliases[alias] {
            let rule = "Ice\\Validation\\Validator\\" . camelize(alias);

            if !class_exists(rule) {
                throw new Exception(sprintf("Validator %s not found", alias));
            }
        }

        let this->rules[field][] = <Validator> create_instance_params(rule, [options]);
        
        return this;
    }

    /**
     * Add one rule.
     *
     * <pre><code>
     *  $validation = new Ice\Validation();
     *  
     *  $validation->rule('email', 'required|email');
     *  $validation->rule('content', [
     *      'length' => [
     *          'max' => 1000,
     *          'messageMin' => 'Too long!',
     *          'label' => 'Desctiption'
     *      ]
     *  ]);
     * </code></pre>
     *
     * @param string field
     * @param mixed validators
     * @param mixed options
     * @return object Validation
     */
    public function rule(string field, var validators, var options = null)
    {
        var validator, rules, rule, alias, values;

        switch typeof validators {
            case "object":
                let this->rules[field][] = <Validator> validators;
            break;
            case "array":
                for validator, options in validators {
                    if typeof validator == "integer" {
                        let validator = options;
                    }
                    this->rule(field, validator, options);
                }
            break;
            case "string":
                if strpos(validators, "|") === false && strpos(validators, ":") === false {
                    this->resolve(validators, field, options);
                } else {
                    let rules = explode("|", validators);

                    for rule in rules {
                        let options = explode(":", rule),
                            alias = array_shift(options);

                        if alias != "regex" {
                            if fetch values, options[0] {
                                let options = explode(",", values);
                            }
                        }

                        this->resolve(alias, field, options);
                    }
                }
            break;
        }
        return this;
    }

    /**
     * Add multiple rules at once.
     *
     * <pre><code>
     *  $validation = new Ice\Validation();
     *  
     *  $validation->rules([
     *      'username' => 'required|length:4,24|notIn:admin,user,root|unique:users',
     *      'password'  => 'required|length:5,32',
     *      'repeatPassword'  => 'same:password',
     *      'email'  => 'email',
     *      'status'  => 'required|digit|in:0,1,2',
     *      'website'  => 'url',
     *      'title'  => 'length:,100',
     *      'age'  => 'required|between:18,21',
     *  ]);
     * </code></pre>
     *
     * @param array validators
     * @param boolean merge
     * @return object Validation
     */
    public function rules(array! validators, boolean merge = true)
    {
        var field, rules;

        if !merge {
            let this->rules = [];
        }

        for field, rules in validators {
            this->rule(field, rules);
        }
        
        return this;
    }

    /**
     * Validate the data.
     *
     * @param array data Data to validate
     * @param boolean clear Clear messages before
     * @return boolean
     */
    public function validate(array data = [], boolean clear = true) -> boolean
    {
        var tmp, field, rules, rule;

        if count(data) {
            let tmp = this->data;

            tmp->setData(data);

            let this->data = tmp;
        }

        if clear {
            let this->valid = true,
                this->messages = [];
        }

        // Validate the rules
        for field, rules in this->rules {
            for rule in rules {
                if rule->validate(this, field)  === false {
                    let this->valid = false;
                }
            }
        }

        // Double check
        if count(this->messages) {
            let this->valid = false;
        }

        return this->valid;
    }

    /**
     * Check if validation passed.
     *
     * @return boolean
     */
    public function valid() -> boolean
    {
        return this->valid;
    }

    /**
     * Whether or not a value exists by field.
     *
     * @param string field The data key
     * @return boolean
     */
    public function hasValue(string! field) -> boolean
    {
        return this->data->has(field);
    }

    /**
     * Get a value by field.
     *
     * @param string field The data key
     * @param boolean filtered Get the filtered value or original
     * @return mixed
     */
    public function getValue(string! field, boolean filtered = true)
    {
        var filters = null;

        if filtered {
            fetch filters, this->filters[field];
        }

        return this->data->getValue(field, filters);
    }

    /**
     * Get the values by fields.
     * Values are automatically filtered out if filters have been setted.
     * 
     * <pre><code>
     *  // Get value for one field
     *  $validation->getValues('password');
     *  
     *  // Get values for multiple fields
     *  $validation->getValues(['fullName', 'about']);
     *  
     *  // Get all values
     *  $validation->getValues();
     * </code></pre>
     *
     * @param mixed fields The data keys
     * @param boolean filtered Get the filtered value or original
     * @return mixed
     */
    public function getValues(var fields = null, boolean filtered = true)
    {
        var data, field;

        let data = [];

        if fields === null {
            for field, _ in iterator(this->data) {
                let data[field] = this->getValue(field, filtered);
            }
        } else {
            switch typeof fields {
                case "array":
                    for field in fields {
                        if isset this->data[field] {
                            let data[field] = this->getValue(field, filtered);
                        }
                    }
                break;
                case "string":
                    let data = this->getValue(fields, filtered);
                break;
            }
        }
            
        return data;
    }

    /**
     * Get the label of a field.
     * Humanize a label if humanLabels attribute and filter service is available
     *
     * @param string field The data key
     * @return string
     */
    public function getLabel(string! field) -> string
    {
        var label;

        if !fetch label, this->labels[field] {
            // Humanize the field
            if this->humanLabels {
                let label = this->di->get("filter")->sanitize(field, "human");
            } else {
                let label = field;
            }
        }

        return label;
    }

    /**
     * Set the default messages.
     *
     * @param array messages
     * @return object Validation
     */
    public function setDefaultMessages(array messages = [])
    {
        let this->defaultMessages = array_merge(this->defaultMessages, messages);
        
        return this;
    }

    /**
     * Get a default message for the type.
     *
     * @param string type Type of message
     * @return string
     */
    public function getDefaultMessage(string! type) -> string
    {
        var message;

        if !fetch message, this->defaultMessages[type] {
            let message = this->defaultMessages["default"];
        }

        return message;
    }

    /**
     * Add a message to the field.
     *
     * @param string field
     * @param string message
     * @return object Validation
     */
    public function addMessage(string! field, string message)
    {
        let this->messages[field][] = message;
        
        return this;
    }

    /**
     * Get the validation's messages.
     *
     * @return object Arr
     */
    public function getMessages() -> <Arr>
    {
        return new Arr(this->messages);
    }
}
