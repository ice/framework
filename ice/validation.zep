
namespace Ice;

use Ice\Validation\ValidationInterface;

class Validation
{

    protected _data = [];
    protected _rules = [] { set };
    protected _validators = [];
    protected _filters = [] { set };
    protected _labels = [] { set };
    protected _messages = [];
    protected _valid = true;
    protected _aliases = [] { set };
    protected _translate = "__" { set };
    protected _defaultMessages = [
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
        "fileValid": "Field :field is not valid",
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

    public function __construct(array data = [])
    {
        let this->_data = data;
    }

    public function resolve(string alias, string field, var options = null)
    {
        var rule;

        if !fetch rule, this->_aliases[alias] {
            let rule = "Ice\\Validation\\Validator\\" . camelize(alias);

            if !class_exists(rule) {
                throw new Exception(sprintf("Validator %s not found", alias));
            }
        }

        let this->_rules[field][] = <ValidatorInterface> create_instance_params(rule, [options]);
    }

    public function rule(string field, var validators, var options = null)
    {
        var validator, rules, rule, alias, values;

        switch typeof validators {
            case "object":
                let this->_rules[field][] = <ValidatorInterface> validators;
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
    }

    public function rules(array! validators)
    {
        var field, rules;

        for field, rules in validators {
            this->rule(field, rules);
        }
    }

    public function validate(array data = [])
    {
        var field, rules, rule;

        if count(data) {
            let this->_data = data;
        }

        for field, rules in this->_rules {
            for rule in rules {
                if rule->validate(this, field)  === false {
                    let this->_valid = false;
                }
            }
        }

        // Double check
        if count(this->_messages) {
            let this->_valid = false;
        }

        return this->_valid;
    }

    public function valid()
    {
        return this->_valid;
    }

    public function hasValue(string! field)
    {
        return isset this->_data[field];
    }

    public function getValue(string! field, boolean filtered = true)
    {
        var value, filters, filter;

        fetch value, this->_data[field];

        if filtered && fetch filters, this->_filters[field] {
            let filter = Di::$fetch()->{"getFilter"}(),
                value = filter->sanitize(value, filters);
        }

        return value;
    }

    public function getLabel(string! field)
    {
        var label;

        if !fetch label, this->_labels[field] {
            return field;
        }
        return label;
    }

    public function setDefaultMessages(array messages = [])
    {
        let this->_defaultMessages = array_merge(this->_defaultMessages, messages);
    }

    public function getDefaultMessage(string! type)
    {
        var message, translate;

        if !fetch message, this->_defaultMessages[type] {
            return this->_defaultMessages["default"];
        }

        let translate = this->_translate;

        return translate && function_exists(translate) ? {translate}(message) : message;
    }

    public function addMessage(string! field, string message)
    {
        let this->_messages[field][] = message;
    }

    public function getMessages() -> <Arr>
    {
        return new Arr(this->_messages);
    }
}