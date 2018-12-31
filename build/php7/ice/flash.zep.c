
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

	zval *options, options_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_zval(this_ptr, SL("options"), options);
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
	zval *options_param = NULL, di, _1, _2, _3;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "session");
	ZEPHIR_CALL_METHOD(&_1, &di, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("session"), &_1);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "tag");
	ZEPHIR_CALL_METHOD(&_3, &di, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("tag"), &_3);
	if (zephir_fast_count_int(&options TSRMLS_CC)) {
		zephir_update_property_zval(this_ptr, SL("options"), &options);
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

	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &key, 1 TSRMLS_CC)) {
		RETURN_CTOR(&value);
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

	zend_string *_4$$3;
	zend_ulong _3$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, key, type, message, messages, body, _0, _1, *_2$$3, _5$$4, _7$$5;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &remove_param);

	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session_key");
	ZEPHIR_CALL_METHOD(&key, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&messages, &_1, "get", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&body);
	ZVAL_STRING(&body, "");
	if (Z_TYPE_P(&messages) == IS_ARRAY) {
		zephir_is_iterable(&messages, 0, "ice/flash.zep", 80);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&messages), _3$$3, _4$$3, _2$$3)
		{
			ZEPHIR_INIT_NVAR(&type);
			if (_4$$3 != NULL) { 
				ZVAL_STR_COPY(&type, _4$$3);
			} else {
				ZVAL_LONG(&type, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_COPY(&message, _2$$3);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getmessage", &_6, 0, &type, &message);
			zephir_check_call_status();
			zephir_concat_self(&body, &_5$$4 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_INIT_NVAR(&type);
	}
	if (remove) {
		zephir_read_property(&_7$$5, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_7$$5, "remove", NULL, 0, &key);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&body);

}

/**
 * Get a message formatting it with HTML.
 *
 * @param string type
 * @param mixed message
 * @return string
 */
PHP_METHOD(Ice_Flash, getMessage) {

	zval _3, _10$$5, _12$$5;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *messages = NULL, messages_sub, params, body, close, message, _0, _2, _4, *_5, _6$$4, _7$$4, _8$$5, _9$$5, _11$$5, _13$$5, _14$$5, _15$$5, _16$$5, _17$$6, _18$$6;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&messages_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&close);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &messages);

	zephir_get_strval(&type, type_param);
	ZEPHIR_SEPARATE_PARAM(messages);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&params, this_ptr, "getoption", &_1, 0, &type, &_0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "#");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "×");
	zephir_array_fast_append(&_3, &_4);
	add_assoc_stringl_ex(&_3, SL("class"), SL("close"));
	ZEPHIR_CALL_METHOD(&close, &_2, "a", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&body);
	ZVAL_STRING(&body, "");
	if (Z_TYPE_P(messages) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(messages);
		zephir_create_array(messages, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(messages, messages);
	}
	zephir_is_iterable(messages, 0, "ice/flash.zep", 116);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(messages), _5)
	{
		ZEPHIR_INIT_NVAR(&message);
		ZVAL_COPY(&message, _5);
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "html");
		ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "getoption", &_1, 0, &_7$$4);
		zephir_check_call_status();
		if (zephir_is_true(&_6$$4)) {
			zephir_read_property(&_8$$5, this_ptr, SL("tag"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_10$$5);
			zephir_create_array(&_10$$5, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_11$$5);
			ZEPHIR_CONCAT_VV(&_11$$5, &close, &message);
			zephir_array_update_string(&_10$$5, SL("content"), &_11$$5, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_12$$5);
			zephir_create_array(&_12$$5, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_13$$5);
			ZVAL_STRING(&_13$$5, "content");
			zephir_array_fast_append(&_12$$5, &_13$$5);
			ZEPHIR_INIT_NVAR(&_13$$5);
			ZVAL_STRING(&_13$$5, "div");
			ZEPHIR_INIT_NVAR(&_14$$5);
			ZVAL_STRING(&_14$$5, "content");
			ZVAL_BOOL(&_15$$5, 1);
			ZVAL_BOOL(&_16$$5, 1);
			ZEPHIR_CALL_METHOD(&_9$$5, &_8$$5, "taghtml", NULL, 0, &_13$$5, &params, &_10$$5, &_12$$5, &_14$$5, &_15$$5, &_16$$5);
			zephir_check_call_status();
			zephir_concat_self(&body, &_9$$5 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_17$$6);
			ZEPHIR_GET_CONSTANT(&_17$$6, "PHP_EOL");
			ZEPHIR_INIT_LNVAR(_18$$6);
			ZEPHIR_CONCAT_VV(&_18$$6, &message, &_17$$6);
			zephir_concat_self(&body, &_18$$6 TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&message);
	RETURN_CCTOR(&body);

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
	zval *type_param = NULL, *message_param = NULL, key, messages, _0, _1, _3, _2$$3;
	zval type, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message_param);

	zephir_get_strval(&type, type_param);
	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session_key");
	ZEPHIR_CALL_METHOD(&key, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&messages, &_1, "get", NULL, 0, &key, &_0);
	zephir_check_call_status();
	if (!(zephir_array_isset(&messages, &type))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		array_init(&_2$$3);
		zephir_array_update_zval(&messages, &type, &_2$$3, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_multi(&messages, &message TSRMLS_CC, SL("za"), 2, &type);
	zephir_read_property(&_3, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "set", NULL, 0, &key, &messages);
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
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "success");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Alias of success message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, ok) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "success");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
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
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "info");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of info message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, notice) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "info");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
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
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of warning message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, alert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
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
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "danger");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of danger message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, error) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "danger");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Ice_Flash(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3, _2$$3;
	zval __$true, _0;
		ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 6, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("session_key"), SL("_flash"));
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-success"));
			zephir_array_update_string(&_1$$3, SL("success"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-info"));
			zephir_array_update_string(&_1$$3, SL("info"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-warning"));
			zephir_array_update_string(&_1$$3, SL("warning"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-danger"));
			zephir_array_update_string(&_1$$3, SL("danger"), &_2$$3, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("html"), &__$true, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

