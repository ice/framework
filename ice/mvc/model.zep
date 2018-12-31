
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Model extends Arr implements \Serializable
{

    protected di { get };
    protected db { get };
    protected service = "db";
    protected from { set };
    protected primary { set, get };
    protected autoincrement = true { set };
    protected filters = [] { set, get };
    protected fields = [] { set, get };
    protected validation { set, get };
    protected relations = [] { get };
    protected labels = [] { set };
    protected rules = [];
    protected messages = [] { get, set };

    // this model has been loaded from service
    protected isLoaded = null;

    const BELONGS_TO = 1;
    const HAS_ONE = 2;
    const HAS_MANY = 3;

    /**
     * Model constructor. Fetch Di and set it as a property.
     *
     * @param mixed filters
     * @param array data
     * @param array options Options to limit/group/orderby results when filters is not null
     */
    public function __construct(var filters = null, array data = [], array options = [])
    {
        var di;

        let di = Di::$fetch(),
            this->di = di,
            this->db = di->get(this->service);

        let data = array_merge(array_fill_keys(this->fields, null), data);

        parent::__construct(data);

        if !this->from {
            let this->from = uncamelize(get_class_ns(this));
        }

        if !this->primary {
            let this->primary = this->db->getId();
        }

        if method_exists(this, "onConstruct") {
            this->{"onConstruct"}();
        }

        if filters {
            this->loadOne(filters, options);
        }

        if method_exists(this, "initialize") {
            this->{"initialize"}();
        }
    }

    /**
     * Get the id.
     *
     * @return mixed
     */
    public function getId()
    {
        return this->get(this->getIdKey());
    }

    /**
     * Get the id key depending on db driver.
     *
     * @return string
     */
    public function getIdKey() -> string
    {
        return this->db->getId();
    }

    /**
     * Get the date time object.
     *
     * @param mixed key
     * @param boolean model
     * @return object
     */
    public function getDateTime(key, model = false)
    {
        var value;
        if this->has(key) {
            let value = this->get(key);
        } else {
            let value = key;
        }

        return this->db->getDateTime(value, model);
    }

    /**
     * Load one result to the current object.
     *
     * @param mixed filters
     * @param array options Options to limit/group/orderby results
     * @return this|false
     */
    public function loadOne(var filters, array options = [])
    {
        var result;

        if empty filters {
            return false;
        }

        let result = this->db->findOne(this->from, filters, options);

        if result {
            this->replace(result->all());
            let this->isLoaded = true;
            return this;
        } else {
            let this->isLoaded = false;
            return false;
        }
    }

    /**
     * Load results to the current object.
     *
     * @param mixed filters
     * @param array options
     * @return object Arr
     */
    public function load(var filters, array options = [])
    {
        var result, instances, data, model;

        let result = this->db->find(this->from, filters, options),
            instances = [];

        if result->count() {
            for data in iterator(result) {
                let model = create_instance_params(get_called_class(), [null, data]),
                    model->isLoaded = true,
                    instances[] = model;
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
     * @param array options
     * @return this|false
     */
    public static function findOne(var filters = null, array options = [])
    {
        var model;

        let model = create_instance_params(get_called_class(), [filters, null, options]);

        return model->isLoaded ? model : false;
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
     * @param array options
     * @return object Arr
     */
    public static function find(var filters = null, array options = [])
    {
        var model;

        let model = create_instance(get_called_class());

        return model->load(filters, options);
    }

    /**
     * Prepare fields for validation on create/update.
     *
     * @param mixed fields Fields to save or valid fields
     * @param boolean primary Keep primary key
     * @return array
     */
    protected function fields(var fields = [], boolean primary = true)
    {
        // Check if model has defined valid fields
        if empty this->fields {
            // No defined model's fields
            // Check if fields param has any elements
            if empty fields {
                // Get all model's data as fields
                let fields = this->all();
            } else {
                // Get only fields from method parameter
                // Check if fields param is associative or sequential
                if array_filter(array_keys(fields), "is_string") {
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
            if empty fields {
                // Get all valid model's data as fields
                let fields = array_intersect_key(this->all(), array_flip(this->fields));
            } else {
                // Get only fields from method parameter
                // Check if fields param is associative or sequential
                if array_filter(array_keys(fields), "is_string") {
                    // Merge model data with fields values, get only valid model's fields
                    let fields = array_intersect_key(array_merge(this->all(), fields), array_flip(this->fields));
                } else {
                    // Use fields as only valid keys, get only valid model's fields
                    let fields = array_intersect_key(this->all(), array_flip(fields), array_flip(this->fields));
                }
            }
        }

        // Remove primary key
        if !primary {
            var key, keys = [];

            if typeof this->primary == "array" {
                for key in this->primary {
                    let keys[] = key;
                }
            } else {
                let keys[] = this->primary;
            }

            for key in keys {
                unset fields[key];
            }
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
     * @return null|boolean If validate fail return null, else return insert status
     */
    public function create(var fields = [], <Validation> extra = null)
    {
        var status;

        this->setData(this->fields(fields, !this->autoincrement));

        if extra {
            extra->validate();

            let this->messages = extra->getMessages()->all();
        } else {
            let this->messages = [];
        }

        this->di->applyHook("model.before.validate", [this], this);

        // Run validation if rules or validation is specified
        if !empty this->rules || typeof this->validation == "object" && (this->validation instanceof Validation) {
            if !(typeof this->validation == "object" && (this->validation instanceof Validation)) {
                let this->validation = new Validation();
            }

            if !this->validation->getRules() {
                // Resolve the rules
                this->validation->rules(this->rules);
            }

            this->validation->setFilters(this->filters);
            this->validation->setLabels(this->labels);
            this->validation->validate(this->getData());

            // Replace values by validation values (with applied filters)
            this->replace(this->validation->getValues());

            if !this->validation->valid() {
                let this->messages = array_merge(this->messages, this->validation->getMessages()->all());
            }
        }

        this->di->applyHook("model.after.validate", [this], this);

        if !empty this->messages {
            return null;
        }

        this->di->applyHook("model.before.create", [this], this);

        let status = this->db->insert(this->from, this->getData());

        if status {
            let this->isLoaded = true;
            if this->autoincrement {
                this->set(this->db->getId(), this->db->getLastInsertId());
            }
        }

        this->di->applyHook("model.after.create", [this], this);

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
     * @return null|boolean If validate fail return null, else return update status
     */
    public function update(var fields = [], <Validation> extra = null)
    {
        var data, status, primary, key;

        let data = this->getData(),
            primary = [];

        if typeof this->primary == "array" {
            for key in this->primary {
                let primary[key] = this->get(key);
            }
        } else {
            let primary = [this->primary: this->get(this->primary)];
        }

        this->setData(this->fields(fields));

        if extra {
            extra->validate();

            let this->messages = extra->getMessages()->all();
        } else {
            let this->messages = [];
        }

        this->di->applyHook("model.before.validate", [this], this);

        if typeof this->validation == "object" && (this->validation instanceof Validation) {
            this->validation->validate(this->getData());

            // Replace values by validation values (with applied filters)
            this->replace(this->validation->getValues());

            if !this->validation->valid() {
                let this->messages = array_merge(this->messages, this->validation->getMessages()->all());
            }
        }

        this->di->applyHook("model.after.validate", [this], this);

        if !empty this->messages {
            // Rollback changes and restore old data
            this->setData(data);
            return null;
        }

        this->di->applyHook("model.before.update", [this], this);

        let status = this->db->update(this->from, primary, this->fields(this->getData(), !this->autoincrement));

        if !status {
            // Rollback changes and restore old data
            this->setData(data);
        } else {
            let this->isLoaded = true;
            // changes and update old data
            this->setData(array_merge(data, fields));
        }

        this->di->applyHook("model.after.update", [this], this);

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
     * @return null|boolean If validate fail return null, else return save status
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
     *  $status = (new Users())->delete(["status" => 0]);
     * </code></pre>
     *
     * @param filters
     * @return boolean
     */
    public function delete(var filters = [])
    {
        var key, status;

        if !filters {
            let filters = [];

            if typeof this->primary == "array" {
                for key in this->primary {
                    let filters[key] = this->get(key);
                }
            } else {
                let filters = [this->primary: this->get(this->primary)];
            }
        }

        let status = this->db->delete(this->from, filters);

        if status {
            // this model doesn't exist in db
            let this->isLoaded = false;
        }

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

        if this->isLoaded !== null {
            return this->isLoaded ? this : false;
        }

        if !filters {
            let filters = [];

            if typeof this->primary == "array" {
                for key in this->primary {
                    if this->has(key) && this->get(key) {
                        let filters[key] = this->get(key);
                    } else {
                        return false;
                    }
                }
            } else {
                if this->has(this->primary) && this->get(this->primary) {
                    let filters = [this->primary: this->get(this->primary)];
                } else {
                    return false;
                }
            }
        }

        return this->loadOne(filters);
    }

    /**
     * Get the last Db error.
     *
     * @return mixed
     */
    public function getError()
    {
        return this->db->getError();
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
     * @return object Model
     */
    public function belongsTo(string field, string referenceModel, string referencedField, array options = [])
    {
        var alias;

        if !fetch alias, options["alias"] {
            let alias = referenceModel;
        }

        let this->relations[alias] = [
            "type": self::BELONGS_TO,
            "field": field,
            "referenceModel": referenceModel,
            "referencedField": referencedField,
            "options": options
        ];

        return this;
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
     * @return object Model
     */
    public function hasOne(string field, string referenceModel, string referencedField, array options = [])
    {
        var alias;

        if !fetch alias, options["alias"] {
            let alias = referenceModel;
        }

        let this->relations[alias] = [
            "type": self::HAS_ONE,
            "field": field,
            "referenceModel": referenceModel,
            "referencedField": referencedField,
            "options": options
        ];

        return this;
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
     * @return object Model
     */
    public function hasMany(string field, string referenceModel, string referencedField, array options = [])
    {
        var alias;

        if !fetch alias, options["alias"] {
            let alias = referenceModel;
        }

        let this->relations[alias] = [
            "type": self::HAS_MANY,
            "field": field,
            "referenceModel": referenceModel,
            "referencedField": referencedField,
            "options": options
        ];

        return this;
    }

    /**
     * Get related models.
     *
     * @param string alias
     * @param array filters
     * @param array options
     */
    public function getRelated(string alias, array filters = [], array options = [])
    {
        var relation, field, referenceModel, referencedField, result;

        if !fetch relation, this->relations[alias] {
            throw new Exception(sprintf("Alias '%s' not found", alias));
        }

        fetch field, relation["field"];
        fetch referenceModel, relation["referenceModel"];
        fetch referencedField, relation["referencedField"];

        switch relation["type"] {
            case self::BELONGS_TO:
            case self::HAS_ONE:
                let filters[referencedField] = this->{field},
                    result = create_instance_params(referenceModel, [filters, null, options]);

                if !result->count() {
                    return false;
                }

                return result;

            case self::HAS_MANY:
                let filters[referencedField] = this->{field},
                    result = {referenceModel}::find(filters, options);

                return result;
        }
    }

    /**
     * Get rules for validation.
     *
     * <pre><code>
     *  // Get rules for one field
     *  $this->getRules('password');
     *
     *  // Get rules for multiple fields
     *  $this->getRules(['fullName', 'about']);
     *
     *  // Get all rules
     *  $this->getRules();
     * </code></pre>
     *
     * @param mixed fields
     * @return mixed
     */
    public function getRules(fields = null)
    {
        var rules, field;

        if fields {
            if typeof fields == "array" {
                let rules = [];

                for field in fields {
                    if isset this->rules[field] {
                        let rules[field] = this->rules[field];
                    }
                }

                return rules;
            } elseif typeof fields == "string" && isset this->rules[fields] {
                return this->rules[fields];
            }
            return null;
        }

        return this->rules;
    }

    /**
     * Set rules for validation.
     *
     * @param array rules
     * @param boolean merge
     * @return object Model
     */
    public function setRules(array! rules = [], boolean merge = true)
    {
        if merge {
            let this->rules = array_merge(this->rules, rules);
        } else {
            let this->rules = rules;
        }
        return this;
    }

    /**
     * Serialize the model's data.
     *
     * @return string
     */
    public function serialize() -> string
    {
        return base64_encode(serialize(this->data));
    }

    /**
     * Unserialize and set the data.
     * @return object Model
     */
    public function unserialize(serialized)
    {
        this->__construct();
        let this->data = unserialize(base64_decode(serialized));

        return this;
    }

    /**
     * Magic call to get related models.
     */
    public function __call(string method, arguments = null)
    {
        var filters, options;

        if starts_with(method, "get") {
            fetch filters, arguments[0];
            fetch options, arguments[1];
            return this->getRelated(ucfirst(substr(method, 3)), filters, options);
        }

        // The method doesn't exist throw an exception
        throw new Exception(sprintf("The method '%s' doesn't exist", method));
    }
}
