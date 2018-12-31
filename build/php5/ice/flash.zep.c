
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * Shows HTML notifications related to different circumstances.
 *
 * @package     Ice/Flash
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Flash) {

	ZEPHIR_REGISTER_CLASS(Ice, Flash, ice, flash, ice_flash_method_entry, 0);

	zend_declare_property_null(ice_flash_ce, SL("session"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_flash_ce, SL("tag"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_flash_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_flash_ce->create_object = zephir_init_properties_Ice_Flash;
	return SUCCESS;

}

PHP_METHOD(Ice_Flash, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(getThis(), SL("options"), options TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Flash constructor. Fetch session and tag service from the di.
 *
 * @param array options
 */
PHP_METHOD(Ice_Flash, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL, *di = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, di, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("session"), _1 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, di, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("tag"), _3 TSRMLS_CC);
	if (zephir_fast_count_int(options TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("options"), options TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get option value with key.
 *
 * @param string key The option key
 * @param mixed defaultValue The value to return if option key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Flash, getOption) {

	zval *key_param = NULL, *defaultValue = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Display the messages.
 *
 * @param boolean remove
 * @return string
 */
PHP_METHOD(Ice_Flash, getMessages) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, *key = NULL, *type = NULL, *message = NULL, *messages = NULL, *body = NULL, *_0, *_1, **_4$$3, *_5$$4 = NULL, *_7$$5;
	zend_bool remove;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &remove_param);

	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "session_key", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&key, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&messages, _1, "get", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(body);
	ZVAL_STRING(body, "", 1);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		zephir_is_iterable(messages, &_3$$3, &_2$$3, 0, 0, "ice/flash.zep", 80);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(type, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(message, _4$$3);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getmessage", &_6, 0, type, message);
			zephir_check_call_status();
			zephir_concat_self(&body, _5$$4 TSRMLS_CC);
		}
	}
	if (remove) {
		_7$$5 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _7$$5, "remove", NULL, 0, key);
		zephir_check_call_status();
	}
	RETURN_CCTOR(body);

}

/**
 * Get a message formatting it with HTML.
 *
 * @param string type
 * @param mixed message
 * @return string
 */
PHP_METHOD(Ice_Flash, getMessage) {

	HashTable *_6;
	HashPosition _5;
	zval *_3, *_12$$5 = NULL, *_14$$5 = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *messages = NULL, *params = NULL, *body = NULL, *close = NULL, *message = NULL, *_0, *_2, *_4 = NULL, **_7, *_8$$4 = NULL, *_9$$4 = NULL, *_10$$5, *_11$$5 = NULL, *_13$$5 = NULL, *_15$$5 = NULL, *_16$$5 = NULL, *_17$$5 = NULL, *_18$$5 = NULL, *_19$$6 = NULL, *_20$$6 = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &messages);

	zephir_get_strval(type, type_param);
	ZEPHIR_SEPARATE_PARAM(messages);


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_CALL_METHOD(&params, this_ptr, "getoption", &_1, 0, type, _0);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "#", 1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "×", 1);
	zephir_array_fast_append(_3, _4);
	add_assoc_stringl_ex(_3, SS("class"), SL("close"), 1);
	ZEPHIR_CALL_METHOD(&close, _2, "a", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(body);
	ZVAL_STRING(body, "", 1);
	if (Z_TYPE_P(messages) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(messages);
		zephir_create_array(messages, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(messages, messages);
	}
	zephir_is_iterable(messages, &_6, &_5, 0, 0, "ice/flash.zep", 116);
	for (
	  ; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zend_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(message, _7);
		ZEPHIR_INIT_NVAR(_9$$4);
		ZVAL_STRING(_9$$4, "html", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "getoption", &_1, 0, _9$$4);
		zephir_check_temp_parameter(_9$$4);
		zephir_check_call_status();
		if (zephir_is_true(_8$$4)) {
			_10$$5 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_12$$5);
			zephir_create_array(_12$$5, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_13$$5);
			ZEPHIR_CONCAT_VV(_13$$5, close, message);
			zephir_array_update_string(&_12$$5, SL("content"), &_13$$5, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_14$$5);
			zephir_create_array(_14$$5, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_15$$5);
			ZVAL_STRING(_15$$5, "content", 1);
			zephir_array_fast_append(_14$$5, _15$$5);
			ZEPHIR_INIT_NVAR(_15$$5);
			ZVAL_STRING(_15$$5, "div", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_16$$5);
			ZVAL_STRING(_16$$5, "content", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_17$$5);
			ZVAL_BOOL(_17$$5, 1);
			ZEPHIR_INIT_NVAR(_18$$5);
			ZVAL_BOOL(_18$$5, 1);
			ZEPHIR_CALL_METHOD(&_11$$5, _10$$5, "taghtml", NULL, 0, _15$$5, params, _12$$5, _14$$5, _16$$5, _17$$5, _18$$5);
			zephir_check_temp_parameter(_15$$5);
			zephir_check_temp_parameter(_16$$5);
			zephir_check_call_status();
			zephir_concat_self(&body, _11$$5 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_19$$6);
			ZEPHIR_GET_CONSTANT(_19$$6, "PHP_EOL");
			ZEPHIR_INIT_LNVAR(_20$$6);
			ZEPHIR_CONCAT_VV(_20$$6, message, _19$$6);
			zephir_concat_self(&body, _20$$6 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(body);

}

/**
 * Adds a message to the flash.
 *
 * @param string type
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, message) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message_param = NULL, *key = NULL, *messages = NULL, *_0 = NULL, *_1, *_3, *_2$$3;
	zval *type = NULL, *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message_param);

	zephir_get_strval(type, type_param);
	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "session_key", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&key, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_0);
	array_init(_0);
	ZEPHIR_CALL_METHOD(&messages, _1, "get", NULL, 0, key, _0);
	zephir_check_call_status();
	if (!(zephir_array_isset(messages, type))) {
		ZEPHIR_INIT_VAR(_2$$3);
		array_init(_2$$3);
		zephir_array_update_zval(&messages, type, &_2$$3, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_multi(&messages, &message TSRMLS_CC, SL("za"), 2, type);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "set", NULL, 0, key, messages);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Add success message.
 *
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, success) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "success", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Alias of success message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, ok) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "success", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add info message.
 *
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, info) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "info", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of info message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, notice) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "info", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add warning message.
 *
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, warning) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "warning", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of warning message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, alert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "warning", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add danger message.
 *
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, danger) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "danger", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of danger message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, error) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "danger", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object_value zephir_init_properties_Ice_Flash(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3, *_2$$3 = NULL;
	zval *_0;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 6, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1$$3, SS("session_key"), SL("_flash"), 1);
			ZEPHIR_INIT_VAR(_2$$3);
			zephir_create_array(_2$$3, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_2$$3, SS("class"), SL("alert alert-success"), 1);
			zephir_array_update_string(&_1$$3, SL("success"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_2$$3);
			zephir_create_array(_2$$3, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_2$$3, SS("class"), SL("alert alert-info"), 1);
			zephir_array_update_string(&_1$$3, SL("info"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_2$$3);
			zephir_create_array(_2$$3, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_2$$3, SS("class"), SL("alert alert-warning"), 1);
			zephir_array_update_string(&_1$$3, SL("warning"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_2$$3);
			zephir_create_array(_2$$3, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_2$$3, SS("class"), SL("alert alert-danger"), 1);
			zephir_array_update_string(&_1$$3, SL("danger"), &_2$$3, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("html"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			zephir_update_property_this(getThis(), SL("options"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

