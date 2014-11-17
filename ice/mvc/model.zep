
namespace Ice\Mvc;

use Ice\Di;
use Ice\Arr;
use Ice\Exception;
use Ice\Validation;
use Ice\Di\DiInterface;

abstract class Model extends Arr
{

    protected _di { get };
    protected _db { get };
    protected _from { set };
    protected _fields = [] { set, get };
    protected _relations = [] { get };
    protected _labels = [] { set };
    protected _rules = [];
    protected _messages = [] { get };

    const BELONGS_TO = 1;
    const HAS_ONE = 2;
    const HAS_MANY = 3;

    public function __construct(var filters = null, array data = [])
    {
        var di;

        let di = <DiInterface> Di::$fetch(),
            this->_di = di,
            this->_db = di->getDb();

        let data = array_merge(array_fill_keys(this->_fields, null), data);

        parent::__construct(data);

        if !this->_from {
            let this->_from = uncamelize(get_class_ns(this));
        }

        if method_exists(this, "onConstruct") {
            this->{"onConstruct"}();
        }

        if filters {
            this->loadOne(filters);
        }

        if method_exists(this, "initialize") {
            this->{"initialize"}();
        }
    }

    public function loadOne(var filters)
    {
        var result;

        let result = this->_db->findOne(this->_from, filters);

        if !result->count() {
            return false;
        } else {
            this->replace(result->all());
            return this;
        }
    }

    public function load(var filters, array options = [])
    {
        var result, instances, data;

        let result = this->_db->find(this->_from, filters, options),
            instances = [];

        if result->count() {
            for data in iterator(result) {
                let instances[] = create_instance_params(get_called_class(), [null, data]);
            }
        }
        return new Arr(instances);
    }

    public static function findOne(var filters = null)
    {
        var result, model;

        let model = get_called_class(),
            result = create_instance_params(model, [filters]);

        if !result->count() {
            return false;
        } else {
            return result;
        }
    }

    public static function find(var filters = null, array options = [])
    {
        var result, model, instance;

        let model = get_called_class(),
            instance = create_instance(model),
            result = instance->load(filters, options);

        return result;
    }

    public function fields(var fields = [])
    {
        // Check if model has defined valid fields
        if !count(this->_fields) {
            // No defined model's fields
            // Check if fields param has any elements
            if !count(fields) {
                // Get all model's data as fields
                let fields = this->all();
            } else {
                // Get only fields from method parameter
                // Check if fields param is associative or sequential
                if count(array_filter(array_keys(fields), "is_string")) {
                    // Merge model data with fields values
                    let fields = array_merge(this->all(), fields);
                } else {
                    // Use fields as only valid keys
                    let fields = array_intersect_key(this->all(), array_flip(fields));
                }
            }
        } else {
            // Only valid model's fields
            // Check if fields param has any elements
            if !count(fields) {
                // Get all valid model's data as fields
                let fields = array_intersect_key(this->all(), array_flip(this->_fields));
            } else {
                // Get only fields from method parameter
                // Check if fields param is associative or sequential
                if count(array_filter(array_keys(fields), "is_string")) {
                    // Merge model data with fields values, get only valid model's fields
                    let fields = array_intersect_key(array_merge(this->all(), fields), array_flip(this->_fields));
                } else {
                    // Use fields as only valid keys, get only valid model's fields
                    let fields = array_intersect_key(this->all(), array_flip(fields), array_flip(this->_fields));
                }
            }
        }

        unset(fields[this->_db->getId()]);
        return fields;
    }

    /**
     * Insert a new object to the database
     *
     * @param array fields Fields to save or valid fields
     * @param object extra Validation for fields such as a CSRF token, password verification, or a CAPTCHA
     */
    public function create(var fields = [], <Validation> extra = null)
    {
        var status, validation, valid, extraValid, messages, extraMessages;

        let fields = this->fields(fields),
            extraValid = false,
            extraMessages = [],
            valid = false,
            messages = [];

        this->setData(fields);

        if extra {
            let extraValid = extra->validate(),
                extraMessages = extra->getMessages();
        }

        this->_di->applyHook("model.before.validate", [this]);

        if count(this->_rules) {
            let validation = new Validation();

            validation->rules(this->_rules);
            validation->setLabels(this->_labels);

            let valid = validation->validate(this->getData()),
                messages = validation->getMessages();
        }

        if count(this->_rules) && !valid || extra && !extraValid {
            let this->_messages = array_merge(extraMessages, messages);

            return false;
        }

        this->_di->applyHook("model.after.validate", [this]);

        let status = this->_db->insert(this->_from, this->getData());

        if status {
            this->set(this->_db->getId(), this->_db->lastInsertId());
        }

        return status;
    }

    public function update(var fields = [], <Validation> extra = null)
    {
        var id, status;

        let fields = this->fields(fields),
            id = this->_db->getId(),
            status = this->_db->update(this->_from, [id: this->get(id)], fields);

        if status {
            this->replace(fields);
        }

        return status;
    }

    public function save(var fields = [], <Validation> extra = null)
    {
        var id;

        let id = this->_db->getId();

        if this->has(id) && this->get(id) {
            return this->update(fields, extra);
        } else {
            return this->create(fields, extra);
        }
    }

    public function remove(var filters = [])
    {
        var id, status;

        if !filters {
            let id = this->_db->getId(),
                filters = [id: this->get(id)];
        }

        let status = this->_db->remove(this->_from, filters);

        return status;
    }

    public function getError()
    {
        return this->_db->getError();
    }

    public function belongsTo(string field, string referenceModel, string referencedField, array options = [])
    {
        var alias;

        if !fetch alias, options["alias"] {
            let alias = referenceModel;
        }

        let this->_relations[alias] = [
            "type": self::BELONGS_TO,
            "field": field,
            "referenceModel": referenceModel,
            "referencedField": referencedField,
            "options": options
        ];
    }

    public function hasOne(string field, string referenceModel, string referencedField, array options = [])
    {
        var alias;

        if !fetch alias, options["alias"] {
            let alias = referenceModel;
        }

        let this->_relations[alias] = [
            "type": self::HAS_ONE,
            "field": field,
            "referenceModel": referenceModel,
            "referencedField": referencedField,
            "options": options
        ];
    }

    public function hasMany(string field, string referenceModel, string referencedField, array options = [])
    {
        var alias;

        if !fetch alias, options["alias"] {
            let alias = referenceModel;
        }

        let this->_relations[alias] = [
            "type": self::HAS_MANY,
            "field": field,
            "referenceModel": referenceModel,
            "referencedField": referencedField,
            "options": options
        ];
    }

    public function getRelated(string alias, array filters = [])
    {
        var relation, field, referenceModel, referencedField, from, result;

        if !fetch relation, this->_relations[alias] {
            throw new Exception(sprintf("Alias '%s' not found", alias));
        }

        fetch field, relation["field"];
        fetch referenceModel, relation["referenceModel"];
        fetch referencedField, relation["referencedField"];

        let from = uncamelize(get_class_ns(referenceModel));

        switch relation["type"] {
            case self::BELONGS_TO:
            case self::HAS_ONE:
                let filters = array_merge(filters, [referencedField: this->{field}]),
                    result = create_instance_params(referenceModel, [filters]);

                if !result->count() {
                    return false;
                }

                return result;

            case self::HAS_MANY:
                let filters = array_merge(filters, [referencedField: this->{field}]);
                    let result = {referenceModel}::find(filters);

                return result;
        }
    }

    public function setRules(array! rules = [], boolean merge = true)
    {
        if merge {
            let this->_rules = array_merge(this->_rules, rules);
        } else {
            let this->_rules = rules;
        }
    }

    public function serialize() -> string
    {
        return serialize(this->all());
    }

    public function unserialize(var data)
    {
        if typeof data == "string" {
            let data = unserialize(data);

            if typeof data == "array" {
                this->setData(data);
                return true;
            }
        }
        throw new Exception("Invalid serialization data");
    }

    public function __call(string method, arguments = null)
    {
        var filters;

        if starts_with(method, "get") {
            fetch filters, arguments[0];
            return this->getRelated(ucfirst(substr(method, 3)), filters);
        }

        // The method doesn't exist throw an exception
        throw new Exception(sprintf("The method '%s' doesn't exist", method));
    }
}