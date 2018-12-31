
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
	zval *file_param = NULL, *_0$$3 = NULL, *_1$$4, *_4 = NULL, *_5$$5;
	zval *file = NULL, *_2$$4, *_6$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(file, file_param);


	if (!((zephir_file_exists(file TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "touch", NULL, 161, file);
		zephir_check_call_status();
		if (!(zephir_is_true(_0$$3))) {
			ZEPHIR_INIT_VAR(_1$$4);
			object_init_ex(_1$$4, ice_exception_ce);
			ZEPHIR_INIT_VAR(_2$$4);
			ZEPHIR_CONCAT_SVS(_2$$4, "Log file ", file, " cannot be created");
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", &_3, 13, _2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1$$4, "ice/log/driver/file.zep", 31 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_FUNCTION(&_4, "is_writable", NULL, 162, file);
	zephir_check_call_status();
	if (!(zephir_is_true(_4))) {
		ZEPHIR_INIT_VAR(_5$$5);
		object_init_ex(_5$$5, ice_exception_ce);
		ZEPHIR_INIT_VAR(_6$$5);
		ZEPHIR_CONCAT_SVS(_6$$5, "Log file ", file, " is not writeable");
		ZEPHIR_CALL_METHOD(NULL, _5$$5, "__construct", &_3, 13, _6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$5, "ice/log/driver/file.zep", 35 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(getThis(), SL("file"), file TSRMLS_CC);
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
	zval *context = NULL;
	zval *message = NULL;
	zval *level, *message_param = NULL, *context_param = NULL, *line = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2, *_3 = NULL, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 42, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_strtoupper(_2, level);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "interpolate", NULL, 0, message, context);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_GET_CONSTANT(_4, "PHP_EOL");
	ZEPHIR_INIT_VAR(line);
	ZEPHIR_CONCAT_SVSVSVV(line, "[", _1, "] ", _2, ": ", _3, _4);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("file"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 163, _5, line, &_0);
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

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *replace = NULL, *key = NULL, *value = NULL, **_2, *_3$$3 = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(replace);
	array_init(replace);
	zephir_is_iterable(context, &_1, &_0, 0, 0, "ice/log/driver/file.zep", 77);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SVS(_3$$3, "{", key, "}");
		zephir_array_update_zval(&replace, _3$$3, &value, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 116, message, replace);
	zephir_check_call_status();
	RETURN_MM();

}

