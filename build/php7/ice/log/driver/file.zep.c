
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/file.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * File driver for the Logger.
 *
 * @package     Ice/Log
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Log_Driver_File) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Log\\Driver, File, ice, log_driver_file, ice_log_driver_ce, ice_log_driver_file_method_entry, 0);

	zend_declare_property_null(ice_log_driver_file_ce, SL("file"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Logger file constructor.
 *
 * @param string file Filename to log messages to (complete path)
 * @throws Exception When logfile cannot be created or is not writeable
 */
PHP_METHOD(Ice_Log_Driver_File, __construct) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, _0$$3, _1$$4, _4, _5$$5;
	zval file, _2$$4, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(&file, file_param);


	if (!((zephir_file_exists(&file TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "touch", NULL, 147, &file);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0$$3))) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, ice_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SVS(&_2$$4, "Log file ", &file, " cannot be created");
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", &_3, 12, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "ice/log/driver/file.zep", 31 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_FUNCTION(&_4, "is_writable", NULL, 148, &file);
	zephir_check_call_status();
	if (!(zephir_is_true(&_4))) {
		ZEPHIR_INIT_VAR(&_5$$5);
		object_init_ex(&_5$$5, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZEPHIR_CONCAT_SVS(&_6$$5, "Log file ", &file, " is not writeable");
		ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", &_3, 12, &_6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$5, "ice/log/driver/file.zep", 35 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("file"), &file);
	ZEPHIR_MM_RESTORE();

}

/**
 * Logs with an arbitrary level.
 *
 * @param mixed level
 * @param string message
 * @param array context
 * @return void
 */
PHP_METHOD(Ice_Log_Driver_File, log) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval message;
	zval *level, level_sub, *message_param = NULL, *context_param = NULL, line, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 41, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_strtoupper(&_0, level);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "interpolate", NULL, 0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_GET_CONSTANT(&_3, "PHP_EOL");
	ZEPHIR_INIT_VAR(&line);
	ZEPHIR_CONCAT_SVSVSVV(&line, "[", &_1, "] ", &_0, ": ", &_2, &_3);
	zephir_read_property(&_4, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 149, &_4, &line, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Interpolates context values into the message placeholders.
 *
 * @param string message
 * @param array context
 * @return string
 */
PHP_METHOD(Ice_Log_Driver_File, interpolate) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, replace, key, value, *_0, _3$$3;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&replace);
	array_init(&replace);
	zephir_is_iterable(&context, 0, "ice/log/driver/file.zep", 77);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "{", &key, "}");
		zephir_array_update_zval(&replace, &_3$$3, &value, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 103, &message, &replace);
	zephir_check_call_status();
	RETURN_MM();

}

