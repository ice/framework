
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
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Shows HTML notifications related to different circumstances.
 *
 * @package     Ice/Flash
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Flash)
{
	ZEPHIR_REGISTER_CLASS(Ice, Flash, ice, flash, ice_flash_method_entry, 0);

	zend_declare_property_null(ice_flash_ce, SL("session"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_flash_ce, SL("tag"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_flash_ce, SL("options"), ZEND_ACC_PROTECTED);
	ice_flash_ce->create_object = zephir_init_properties_Ice_Flash;

	return SUCCESS;
}

PHP_METHOD(Ice_Flash, setOptions)
{
	zval *options, options_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(options)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &options);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 167, options);
	RETURN_THISW();
}

/**
 * Flash constructor. Fetch session and tag service from the di.
 *
 * @param array options
 */
PHP_METHOD(Ice_Flash, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, di, _0, _1, _2;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("session", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("tag", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "session");
	ZEPHIR_CALL_METHOD(&_0, &di, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 168, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tag");
	ZEPHIR_CALL_METHOD(&_2, &di, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 169, &_2);
	if (zephir_fast_count_int(&options)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 167, &options);
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
PHP_METHOD(Ice_Flash, getOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval key_zv, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_memory_observe(&value);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 167, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &key_zv, 0)) {
		RETURN_CCTOR(&value);
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
PHP_METHOD(Ice_Flash, getMessages)
{
	zend_string *_6$$3;
	zend_ulong _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, key, type, message, messages, body, _0, _1, *_2$$3, _3$$3, *_4$$3, _9$$3, _7$$4, _11$$5, _12$$6;
	zend_bool remove, _10$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("session", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(remove)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &remove_param);
	if (!remove_param) {
		remove = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session_key");
	ZEPHIR_CALL_METHOD(&key, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 168, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&messages, &_1, "get", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&body);
	ZVAL_STRING(&body, "");
	if (Z_TYPE_P(&messages) == IS_ARRAY) {
		if (Z_TYPE_P(&messages) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_3$$3);
			zephir_string_to_char_array(&_3$$3, &messages);
			_2$$3 = &_3$$3;
		} else {
			_2$$3 = &messages;
		}
		zephir_is_iterable(_2$$3, 0, "ice/flash.zep", 80);
		if (Z_TYPE_P(_2$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_2$$3), _5$$3, _6$$3, _4$$3)
			{
				ZEPHIR_INIT_NVAR(&type);
				if (_6$$3 != NULL) { 
					ZVAL_STR_COPY(&type, _6$$3);
				} else {
					ZVAL_LONG(&type, _5$$3);
				}
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _4$$3);
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "getmessage", &_8, 0, &type, &message);
				zephir_check_call_status();
				zephir_concat_self(&body, &_7$$4);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _2$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_10$$3 = 1;
			while (1) {
				if (_10$$3) {
					_10$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _2$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_9$$3, _2$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&type, _2$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&message, _2$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "getmessage", &_8, 0, &type, &message);
					zephir_check_call_status();
					zephir_concat_self(&body, &_11$$5);
			}
		}
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_INIT_NVAR(&type);
	}
	if (remove) {
		zephir_read_property_cached(&_12$$6, this_ptr, _zephir_prop_0, 168, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_12$$6, "remove", NULL, 0, &key);
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
PHP_METHOD(Ice_Flash, getMessage)
{
	zval _13$$5, _15$$5, _28$$8, _30$$8;
	zend_bool _23;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, *messages = NULL, messages_sub, params, body, close, message, _0, _2, _3, _4, _5, *_7, *_8, _22, _6$$3, _9$$4, _10$$4, _11$$5, _12$$5, _14$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$6, _21$$6, _24$$7, _25$$7, _26$$8, _27$$8, _29$$8, _31$$8, _32$$8, _33$$8, _34$$8, _35$$9, _36$$9;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&messages_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&close);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_30$$8);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("tag", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_ZVAL(messages)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	messages = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	ZEPHIR_SEPARATE_PARAM(messages);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&params, this_ptr, "getoption", &_1, 0, &type_zv, &_0);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 169, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "close");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoption", &_1, 0, &_5, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&close, &_2, "button", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&body);
	ZVAL_STRING(&body, "");
	if (Z_TYPE_P(messages) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_create_array(&_6$$3, 1, 0);
		zephir_array_fast_append(&_6$$3, messages);
		ZEPHIR_CPY_WRT(messages, &_6$$3);
	}
	if (Z_TYPE_P(messages) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_5);
		zephir_string_to_char_array(&_5, messages);
		_7 = &_5;
	} else {
		_7 = messages;
	}
	zephir_is_iterable(_7, 0, "ice/flash.zep", 116);
	if (Z_TYPE_P(_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_7), _8)
		{
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_COPY(&message, _8);
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "html");
			ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "getoption", &_1, 0, &_10$$4);
			zephir_check_call_status();
			if (zephir_is_true(&_9$$4)) {
				zephir_read_property_cached(&_11$$5, this_ptr, _zephir_prop_0, 169, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_create_array(&_13$$5, 1, 0);
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZEPHIR_CONCAT_VV(&_14$$5, &close, &message);
				zephir_array_update_string(&_13$$5, SL("content"), &_14$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_15$$5);
				zephir_create_array(&_15$$5, 1, 0);
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZVAL_STRING(&_16$$5, "content");
				zephir_array_fast_append(&_15$$5, &_16$$5);
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZVAL_STRING(&_16$$5, "div");
				ZEPHIR_INIT_NVAR(&_17$$5);
				ZVAL_STRING(&_17$$5, "content");
				ZVAL_BOOL(&_18$$5, 1);
				ZVAL_BOOL(&_19$$5, 1);
				ZEPHIR_CALL_METHOD(&_12$$5, &_11$$5, "taghtml", NULL, 0, &_16$$5, &params, &_13$$5, &_15$$5, &_17$$5, &_18$$5, &_19$$5);
				zephir_check_call_status();
				zephir_concat_self(&body, &_12$$5);
			} else {
				ZEPHIR_INIT_NVAR(&_20$$6);
				ZEPHIR_GET_CONSTANT(&_20$$6, "PHP_EOL");
				ZEPHIR_INIT_NVAR(&_21$$6);
				ZEPHIR_CONCAT_VV(&_21$$6, &message, &_20$$6);
				zephir_concat_self(&body, &_21$$6);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _7, "rewind", NULL, 0);
		zephir_check_call_status();
		_23 = 1;
		while (1) {
			if (_23) {
				_23 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _7, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_22, _7, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_22)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&message, _7, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_25$$7);
				ZVAL_STRING(&_25$$7, "html");
				ZEPHIR_CALL_METHOD(&_24$$7, this_ptr, "getoption", &_1, 0, &_25$$7);
				zephir_check_call_status();
				if (zephir_is_true(&_24$$7)) {
					zephir_read_property_cached(&_26$$8, this_ptr, _zephir_prop_0, 169, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_28$$8);
					zephir_create_array(&_28$$8, 1, 0);
					ZEPHIR_INIT_NVAR(&_29$$8);
					ZEPHIR_CONCAT_VV(&_29$$8, &close, &message);
					zephir_array_update_string(&_28$$8, SL("content"), &_29$$8, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_30$$8);
					zephir_create_array(&_30$$8, 1, 0);
					ZEPHIR_INIT_NVAR(&_31$$8);
					ZVAL_STRING(&_31$$8, "content");
					zephir_array_fast_append(&_30$$8, &_31$$8);
					ZEPHIR_INIT_NVAR(&_31$$8);
					ZVAL_STRING(&_31$$8, "div");
					ZEPHIR_INIT_NVAR(&_32$$8);
					ZVAL_STRING(&_32$$8, "content");
					ZVAL_BOOL(&_33$$8, 1);
					ZVAL_BOOL(&_34$$8, 1);
					ZEPHIR_CALL_METHOD(&_27$$8, &_26$$8, "taghtml", NULL, 0, &_31$$8, &params, &_28$$8, &_30$$8, &_32$$8, &_33$$8, &_34$$8);
					zephir_check_call_status();
					zephir_concat_self(&body, &_27$$8);
				} else {
					ZEPHIR_INIT_NVAR(&_35$$9);
					ZEPHIR_GET_CONSTANT(&_35$$9, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_36$$9);
					ZEPHIR_CONCAT_VV(&_36$$9, &message, &_35$$9);
					zephir_concat_self(&body, &_36$$9);
				}
		}
	}
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
PHP_METHOD(Ice_Flash, message)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, message_zv, key, messages, _0, _1, _3, _2$$3;
	zend_string *type = NULL, *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("session", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session_key");
	ZEPHIR_CALL_METHOD(&key, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 168, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&messages, &_1, "get", NULL, 0, &key, &_0);
	zephir_check_call_status();
	if (!(zephir_array_isset_value(&messages, &type_zv))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		array_init(&_2$$3);
		zephir_array_update_zval(&messages, &type_zv, &_2$$3, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_multi(&messages, &message_zv, SL("za"), 2, &type_zv);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 168, PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Ice_Flash, success)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "success");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, 0, &_0, &message_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Alias of success message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, ok)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "success");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Add info message.
 *
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, info)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "info");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Alias of info message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, notice)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "info");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Add warning message.
 *
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, warning)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Alias of warning message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, alert)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Add danger message.
 *
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, danger)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "danger");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Alias of danger message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, error)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "danger");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message_zv);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Ice_Flash(zend_class_entry *class_type)
{
		zval _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, _0, _3$$3;
		ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 7, 0);
			add_assoc_stringl_ex(&_1$$3, SL("session_key"), SL("_flash"));
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-success alert-dismissible fade show"));
			zephir_array_update_string(&_1$$3, SL("success"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-info alert-dismissible fade show"));
			zephir_array_update_string(&_1$$3, SL("info"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-warning alert-dismissible fade show"));
			zephir_array_update_string(&_1$$3, SL("warning"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-danger alert-dismissible fade show"));
			zephir_array_update_string(&_1$$3, SL("danger"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 5, 0);
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "close");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "×");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			add_assoc_stringl_ex(&_2$$3, SL("type"), SL("button"));
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("close"));
			add_assoc_stringl_ex(&_2$$3, SL("data-dismiss"), SL("alert"));
			zephir_array_update_string(&_1$$3, SL("close"), &_2$$3, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("html"), &__$true, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

