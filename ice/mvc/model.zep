
namespace Ice\Mvc;

use Ice\Di;
use Ice\Arr;
use Ice\Exception;
use Ice\Validation;

/**
 * Model connects business objects and database tables to create a persistable domain model where logic and data are
 * presented in one wrapping (ORM & ODM).
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Model extends Arr implements \Serializable
{

    protected _di { get };
    protected _db { get };
    protected _from { set };
    protected _primary { set, get };
    protected _filters = [] { set, get };
    protected _fields = [] { set, get };
    protected _validation { set, get };
    protected _relations = [] { get };
    protected _labels = [] { set };
    protected _rules = [];
    protected _messages = [] { get };

    const BELONGS_TO = 1;
    const HAS_ONE = 2;
    const HAS_MANY = 3;

    /**
     * Model constructor. Fetch Di and set it as a property.
     *
     * @param mixed filters
     * @param array data
     */
    public function __construct(var filters = null, array data = [])
    {
        var di;

        let di = Di::$fetch(),
            this->_di = di,
            this->_db = di->{"getDb"}();

        let data = array_merge(array_fill_keys(this->_fields, null), data);

        parent::__construct(data);

        if !this->_from {
            let this->_from = uncamelize(get_class_ns(this));
        }

        if !this->_primary {
            let this->_primary = this->_db->getId();
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

    /**
     * Load one result to the current object.
     *
     * @param mixed filters
     */
    public function loadOne(var filters)
    {
        var result;

        let result = this->_db->findOne(this->_from, filters);

        if result {
            this->replace(result->all());
            return this;
        } else {
            return false;
        }
    }

    /**
     * Load results to the current object.
     *
     * @param mixed filters
     * @return Arr
     */
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

    /**
     * Allows to query one record that match the specified conditions.
     *
     * <pre><code>
     *  //Get the user from users by id 2
     *  $user = Users::findOne(2);
     *  echo "The user name is ", $user->username;
     *
     *  //Get one active user with age > 18
     *  $user = Users::findOne(array("status" => 1, "age" => array(">" => 18)));
     * </code></pre>
     *
     * @param array filters
     * @return Model|false
     */
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

    /**
     * Allows to query all records that match the specified conditions.
     *
     * <pre><code>
     *  //Get all active users with age > 18
     *  $user = Users::find(array("status" => 1, "age" => array(">" => 18)));
     * </code></pre>
     *
     * @param array filters
     * @return Arr
     */
    public static function find(var filters = null, array options = [])
    {
        var result, model, instance;

        let model = get_called_class(),
            instance = create_instance(model),
            result = instance->load(filters, options);

        return result;
    }

    /**
     * Prepare fields for validation on create/update.
     *
     * @param mixed fields
     * @return array
     */
    protected function fields(var fields = [])
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

        if typeof this->_primary == "string" {
            unset fields[this->_primary];
        }

        return fields;
    }

    /**
     * Insert a new object to the database.
     *
     * <pre><code>
     *  //Creating a new user
     *  $user = new Users();
     *  $user->lastname = "Kowalski";
     *  $user->status = 1;
     *  $user->create();
     * </code></pre>
     *
     * @param array fields Fields to save or valid fields
     * @param object extra Validation for fields such as a CSRF token, password verification, or a CAPTCHA
     */
    public function create(var fields = [], <Validation> extra = null)
    {
        var status, valid, extraValid, messages, extraMessages;

        let fields = this->fields(fields),
            extraValid = false,
            extraMessages = [],
            valid = false,
            messages = [];

        this->setData(fields);

        if extra {
            let extraValid = extra->validate(),
                extraMessages = extra->getMessages()->all();
        }

        this->_di->applyHook("model.before.validate", [this]);

        if count(this->_rules) {
            if !(typeof this->_validation == "object" && (this->_validation instanceof Validation)) {
                let this->_validation = new Validation();
            }

            this->_validation->rules(this->_rules);
            this->_validation->setFilters(this->_filters);
            this->_validation->setLabels(this->_labels);

            let valid = this->_validation->validate(this->getData()),
                messages = this->_validation->getMessages()->all();
        }

        if count(this->_rules) && !valid || extra && !extraValid {
            let this->_messages = array_merge(extraMessages, messages);

            return false;
        }

        this->_di->applyHook("model.after.validate", [this]);

        let status = this->_db->insert(this->_from, this->getData());

        if status {
            this->set(this->_db->getId(), this->_db->getLastInsertId());
        }

        return status;
    }

    /**
     * Update an existing object in the database.
     *
     * <pre><code>
     *  //Updating a user last name
     *  $user = Users::findOne(100);
     *  $user->lastname = "Nowak";
     *  $user->update();
     * </code></pre>
     *
     * @param array fields Fields to save or valid fields
     * @param object extra Validation for fields such as a CSRF token, password verification, or a CAPTCHA
     */
    public function update(var fields = [], <Validation> extra = null)
    {
        var status, primary, key, extraValid, extraMessages;

        let fields = this->fields(fields),
            extraValid = false,
            extraMessages = [],
            primary = [];

        if extra {
            let extraValid = extra->validate(),
                extraMessages = extra->getMessages()->all();
        }

        this->_di->applyHook("model.before.validate", [this]);

        if extra && !extraValid {
            let this->_messages = extraMessages;

            return false;
        }

        this->_di->applyHook("model.after.validate", [this]);

        if typeof this->_primary == "array" {
            for key in this->_primary {
                let primary[key] = this->get(key);
            }
        } else {
            let primary = [this->_primary: this->get(this->_primary)];
        }

        let status = this->_db->update(this->_from, primary, fields);

        if status {
            this->replace(fields);
        }

        return status;
    }

    /**
     * Inserts or updates a model instance. Returning true on success or false otherwise.
     *
     * <pre><code>
     *  //Creating a new user
     *  $user = new Users();
     *  $user->lastname = "Kowalski";
     *  $user->status = 1;
     *  $user->save();
     *
     *  //Updating a user last name
     *  $user = Users::findOne(100);
     *  $user->lastname = "Nowak";
     *  $user->save();
     * </code></pre>
     *
     * @param array fields
     * @param Validation extra
     * @return boolean
     */
    public function save(var fields = [], <Validation> extra = null)
    {
        if this->exists() {
            return this->update(fields, extra);
        } else {
            return this->create(fields, extra);
        }
    }

    /**
     * Removes a model instance(s). Returning true on success or false otherwise.
     *
     * <pre><code>
     *  //Remove current user
     *  $user = Users::findOne(100);
     *  $user->delete();
     *  
     *  //Remove all unactive users
     *  $status = (new Users())->remove(["status" => 0]);
     * </code></pre>
     *
     * @param filters
     * @return boolean
     */
    public function remove(var filters = [])
    {
        var key, status;

        if !filters {
            let filters = [];

            if typeof this->_primary == "array" {
                for key in this->_primary {
                    let filters[key] = this->get(key);
                }
            } else {
                let filters = [this->_primary: this->get(this->_primary)];
            }
        }

        let status = this->_db->remove(this->_from, filters);

        return status;
    }

    /**
     * Get the record if exist.
     *
     * @param mixed filters
     * @return Model|false
     */
    public function exists(var filters = [])
    {
        var key;

        if !filters {
            let filters = [];

            if typeof this->_primary == "array" {
                for key in this->_primary {
                    if this->has(key) && this->get(key) {
                        let filters[key] = this->get(key);
                    } else {
                        return false;
                    }
                }
            } else {
                if this->has(this->_primary) && this->get(this->_primary) {
                    let filters = [this->_primary: this->get(this->_primary)];
                } else {
                    return false;
                }
            }
        }

        return self::findOne(filters);
    }

    /**
     * Get the last Db error.
     *
     * @return mixed
     */
    public function getError()
    {
        return this->_db->getError();
    }

    /**
     * Setup a relation reverse 1-1 between two models.
     *
     * <pre><code>
     *  class Posts extends Model
     *  {
     *      public function initialize()
     *      {
     *          //Relation with user, be able to get post's author
     *          $this->belongsTo('user_id', __NAMESPACE__ . '\Users', 'id', ['alias' => 'User']);
     *      }
     *  }
     *
     *  //Get post's author
     *  $post = Posts::findOne(100);
     *  echo $post->getUser()->username;
     * </code></pre>
     *
     * @param string field
     * @param string referenceModel
     * @param string referencedField
     * @param array options
     */
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

    /**
     * Setup a 1-1 relation between two models
     *
     * <pre><code>
     *  class Users extends Model
     *  {
     *      public function initialize()
     *      {
     *          $this->hasOne('id', __NAMESPACE__ . '\UsersDescriptions', 'user_id', ['alias' => 'Description']);
     *      }
     *  }
     * </code></pre>
     *
     * @param string field
     * @param string referenceModel
     * @param string referencedField
     * @param array options
     */
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

    /**
     * Setup a relation 1-n between two models.
     *
     * <pre><code>
     *  class Users extends Model
     *  {
     *      public function initialize()
     *      {
     *          //Relation with posts, be able to get user's posts
     *          $this->hasMany('id', __NAMESPACE__ . '\Posts', 'user_id', ['alias' => 'Posts']);
     *      }
     *  }
     *
     *  //Get user's posts
     *  $user = Users::findOne(2);
     *  foreach ($user->getPosts() as $post) {
     *      echo $post->title;
     *  }
     * </code></pre>
     *
     * @param string field
     * @param string referenceModel
     * @param string referencedField
     * @param array options
     */
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

    /**
     * Get related models.
     *
     * @param string alias
     * @param array filters
     */
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

    /**
     * Set rules for validation.
     *
     * @param array rules
     * @param boolean merge
     */
    public function setRules(array! rules = [], boolean merge = true)
    {
        if merge {
            let this->_rules = array_merge(this->_rules, rules);
        } else {
            let this->_rules = rules;
        }
    }

    /**
     * Serialize the model's data.
     *
     * @return string
     */
    public function serialize() -> string
    {
        return json_encode(this->_data);
    }

    /**
     * Unserialize and set the data.
     */
    public function unserialize(string! data)
    {
        this->__construct();
        let this->_data = json_decode(data, true);
    }

    /**
     * Magic call to get related models.
     */
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
