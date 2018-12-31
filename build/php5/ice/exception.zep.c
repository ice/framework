
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/exit.h"


/**
 * Exception class.
 *
 * @package     Ice/Exception
 * @category    Error
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Exception, ice, exception, zend_exception_get_default(TSRMLS_C), ice_exception_method_entry, 0);

	return SUCCESS;

}

/**
 * Creates a new exception.
 * Translate exception's message using the [I18n] class.
 *
 * @param mixed message Error message
 * @param mixed code The exception code
 * @param Exception|Throwable previous Previous exception
 */
PHP_METHOD(Ice_Exception, __construct) {

	zval *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *message = NULL, *code = NULL, *previous = NULL, *di = NULL, *values = NULL, *str = NULL, *_2 = NULL, *_3 = NULL, _1$$3, *_4$$5 = NULL, *_5$$5, *_6$$6, _7$$6, *_8$$6 = NULL, *_9$$8, _10$$8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &message, &code, &previous);

	if (!message) {
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "", 1);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!code) {
		ZEPHIR_INIT_VAR(code);
		ZVAL_LONG(code, 0);
	}
	if (!previous) {
		previous = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 1);
	zephir_check_call_status();
	if (Z_TYPE_P(message) == IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, 1);
		ZEPHIR_CALL_FUNCTION(&values, "array_slice", NULL, 128, message, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(str);
		zephir_array_fetch_long(&str, message, 0, PH_NOISY, "ice/exception.zep", 32 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(values);
		ZVAL_NULL(values);
		ZEPHIR_CPY_WRT(str, message);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "i18n", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, di, "has", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_VAR(_5$$5);
		ZVAL_STRING(_5$$5, "i18n", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4$$5, di, "get", NULL, 0, _5$$5);
		zephir_check_temp_parameter(_5$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&message, _4$$5, "translate", NULL, 0, str, values);
		zephir_check_call_status();
	} else if (Z_TYPE_P(values) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_6$$6);
		zephir_array_keys(_6$$6, values TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_7$$6);
		ZVAL_STRING(&_7$$6, "is_string", 0);
		ZEPHIR_CALL_FUNCTION(&_8$$6, "array_filter", NULL, 8, _6$$6, &_7$$6);
		zephir_check_call_status();
		if (zephir_fast_count_int(_8$$6 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&message, "strtr", NULL, 116, str, values);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_9$$8);
			ZEPHIR_SINIT_VAR(_10$$8);
			ZVAL_STRING(&_10$$8, "sprintf", 0);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_9$$8, &_10$$8, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _9$$8);
		}
	}
	zephir_get_strval(_11, message);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, zephir_get_intval(code));
	ZEPHIR_CALL_PARENT(NULL, ice_exception_ce, getThis(), "__construct", NULL, 0, _11, _3, previous);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the full trace as string.
 *
 * @param Exception|Throwable $e
 * @return string
 */
PHP_METHOD(Ice_Exception, getFullTraceAsString) {

	HashTable *_2, *_6$$4;
	HashPosition _1, _5$$4;
	zephir_fcall_cache_entry *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, count;
	zval *e, *output = NULL, *frame = NULL, *args = NULL, *arg = NULL, *node = NULL, *_0 = NULL, **_3, *_4$$4, **_7$$4, *_8$$5 = NULL, *_9$$6 = NULL, *_10$$7 = NULL, *_11$$8 = NULL, *_12$$9 = NULL, *_13$$10 = NULL, *_14$$10 = NULL, *_15$$3 = NULL, *_16$$3, *_17$$3, *_18$$3 = NULL, *_19$$3, *_20$$3, *_21$$3, _22$$3 = zval_used_for_init, _23$$3 = zval_used_for_init, *_24$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &e);



	count = 0;
	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_CALL_METHOD(&_0, e, "gettrace", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/exception.zep", 109);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(frame, _3);
		ZEPHIR_INIT_NVAR(args);
		ZVAL_STRING(args, "", 1);
		if (zephir_array_isset_string(frame, SS("args"))) {
			ZEPHIR_INIT_NVAR(node);
			array_init(node);
			zephir_array_fetch_string(&_4$$4, frame, SL("args"), PH_NOISY | PH_READONLY, "ice/exception.zep", 72 TSRMLS_CC);
			zephir_is_iterable(_4$$4, &_6$$4, &_5$$4, 0, 0, "ice/exception.zep", 97);
			for (
			  ; zend_hash_get_current_data_ex(_6$$4, (void**) &_7$$4, &_5$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_6$$4, &_5$$4)
			) {
				ZEPHIR_GET_HVALUE(arg, _7$$4);
				ZEPHIR_INIT_NVAR(_8$$5);
				zephir_gettype(_8$$5, arg TSRMLS_CC);
				do {
					if (ZEPHIR_IS_STRING(_8$$5, "string")) {
						ZEPHIR_INIT_LNVAR(_9$$6);
						ZEPHIR_CONCAT_SVS(_9$$6, "'", arg, "'");
						zephir_array_append(&node, _9$$6, PH_SEPARATE, "ice/exception.zep", 75);
						break;
					}
					if (ZEPHIR_IS_STRING(_8$$5, "array")) {
						ZEPHIR_INIT_NVAR(_10$$7);
						ZVAL_STRING(_10$$7, "Array", 1);
						zephir_array_append(&node, _10$$7, PH_SEPARATE, "ice/exception.zep", 78);
						break;
					}
					if (ZEPHIR_IS_STRING(_8$$5, "NULL")) {
						ZEPHIR_INIT_NVAR(_11$$8);
						ZVAL_STRING(_11$$8, "NULL", 1);
						zephir_array_append(&node, _11$$8, PH_SEPARATE, "ice/exception.zep", 81);
						break;
					}
					if (ZEPHIR_IS_STRING(_8$$5, "boolean")) {
						ZEPHIR_INIT_LNVAR(_12$$9);
						if (zephir_is_true(arg)) {
							ZEPHIR_INIT_NVAR(_12$$9);
							ZVAL_STRING(_12$$9, "true", 1);
						} else {
							ZEPHIR_INIT_NVAR(_12$$9);
							ZVAL_STRING(_12$$9, "false", 1);
						}
						zephir_array_append(&node, _12$$9, PH_SEPARATE, "ice/exception.zep", 84);
						break;
					}
					if (ZEPHIR_IS_STRING(_8$$5, "object")) {
						ZEPHIR_INIT_NVAR(_13$$10);
						zephir_get_class(_13$$10, arg, 0 TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_14$$10);
						ZEPHIR_CONCAT_SVS(_14$$10, "Object(", _13$$10, ")");
						zephir_array_append(&node, _14$$10, PH_SEPARATE, "ice/exception.zep", 87);
						break;
					}
					if (ZEPHIR_IS_STRING(_8$$5, "resource")) {
						zephir_array_append(&node, arg, PH_SEPARATE, "ice/exception.zep", 90);
						break;
					}
					zephir_array_append(&node, arg, PH_SEPARATE, "ice/exception.zep", 93);
					break;
				} while(0);

			}
			ZEPHIR_INIT_NVAR(args);
			zephir_fast_join_str(args, SL(", "), node TSRMLS_CC);
		}
		ZEPHIR_INIT_LNVAR(_15$$3);
		if (zephir_array_isset_string(frame, SS("file"))) {
			zephir_array_fetch_string(&_16$$3, frame, SL("file"), PH_NOISY | PH_READONLY, "ice/exception.zep", 103 TSRMLS_CC);
			zephir_array_fetch_string(&_17$$3, frame, SL("line"), PH_NOISY | PH_READONLY, "ice/exception.zep", 103 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_15$$3);
			ZEPHIR_CONCAT_VSVS(_15$$3, _16$$3, "(", _17$$3, ")");
		} else {
			ZEPHIR_INIT_NVAR(_15$$3);
			ZVAL_STRING(_15$$3, "[internal function]", 1);
		}
		ZEPHIR_INIT_LNVAR(_18$$3);
		if (zephir_array_isset_string(frame, SS("class"))) {
			zephir_array_fetch_string(&_19$$3, frame, SL("class"), PH_NOISY | PH_READONLY, "ice/exception.zep", 104 TSRMLS_CC);
			zephir_array_fetch_string(&_20$$3, frame, SL("type"), PH_NOISY | PH_READONLY, "ice/exception.zep", 104 TSRMLS_CC);
			zephir_array_fetch_string(&_21$$3, frame, SL("function"), PH_NOISY | PH_READONLY, "ice/exception.zep", 104 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_18$$3);
			ZEPHIR_CONCAT_VVV(_18$$3, _19$$3, _20$$3, _21$$3);
		} else {
			ZEPHIR_OBS_NVAR(_18$$3);
			zephir_array_fetch_string(&_18$$3, frame, SL("function"), PH_NOISY, "ice/exception.zep", 104 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_22$$3);
		ZVAL_STRING(&_22$$3, "#%s %s: %s(%s)\n", 0);
		ZEPHIR_SINIT_NVAR(_23$$3);
		ZVAL_LONG(&_23$$3, count);
		ZEPHIR_CALL_FUNCTION(&_24$$3, "sprintf", &_25, 12, &_22$$3, &_23$$3, _15$$3, _18$$3, args);
		zephir_check_call_status();
		zephir_concat_self(&output, _24$$3 TSRMLS_CC);
		count++;
	}
	RETURN_CCTOR(output);

}

/**
 * PHP error handler, converts all errors into ErrorExceptions. This handler respects error_reporting settings.
 *
 * @throws ErrorException
 * @return true
 */
PHP_METHOD(Ice_Exception, errorHandler) {

	zval *context = NULL;
	zval *message = NULL, *file = NULL;
	zval *code_param = NULL, *message_param = NULL, *file_param = NULL, *line_param = NULL, *context_param = NULL, *_0 = NULL, *_1$$3, *_2$$3, *_3$$3, *_4$$3;
	zend_long code, line, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &code_param, &message_param, &file_param, &line_param, &context_param);

	code = zephir_get_intval(code_param);
	zephir_get_strval(message, message_param);
	if (!file_param) {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	} else {
		zephir_get_strval(file, file_param);
	}
	if (!line_param) {
		line = 0;
	} else {
		line = zephir_get_intval(line_param);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "error_reporting", NULL, 129);
	zephir_check_call_status();
	if (((int) (zephir_get_numberval(_0)) & code)) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, zephir_get_internal_ce(SS("errorexception") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, code);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_LONG(_3$$3, 0);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, line);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 130, message, _2$$3, _3$$3, file, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "ice/exception.zep", 123 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

/**
 * Inline exception handler, displays the error message, source of the exception, and the stack trace of the error.
 *
 * @param Exception|Throwable $e
 * @return void
 */
PHP_METHOD(Ice_Exception, handler) {

	zval *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *e, *di = NULL, *response = NULL, *_1 = NULL, *_3 = NULL, _5, *_4$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &e);



	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "response", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&response, di, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, e);
	zephir_array_fast_append(_2, di);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "exception.after.uncaught", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, di, "applyhook", NULL, 0, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, response, "getbody", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_CALL_METHOD(&_4$$3, response, "send", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(_4$$3, 0);
	} else {
		zephir_throw_exception_debug(e, "ice/exception.zep", 150 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 1);
	ZEPHIR_MM_RESTORE();
	zephir_exit(&_5);
	ZEPHIR_MM_RESTORE();

}

/**
 * Catches errors that are not caught by the error handler.
 * E_PARSE, E_ERROR, E_CORE_ERROR, E_USER_ERROR
 *
 * @return  void
 */
PHP_METHOD(Ice_Exception, shutdownHandler) {

	zval *_2;
	zend_bool _0;
	zval *e = NULL, *_1, *_3 = NULL, *_4$$3, *_5$$3, *_6$$3, *_7$$3, *_8$$3, *_9$$3, _10$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&e, "error_get_last", NULL, 131);
	zephir_check_call_status();
	_0 = Z_TYPE_P(e) == IS_ARRAY;
	if (_0) {
		zephir_array_fetch_string(&_1, e, SL("type"), PH_NOISY | PH_READONLY, "ice/exception.zep", 167 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		zephir_create_array(_2, 4, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, 4);
		zephir_array_fast_append(_2, _3);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 1);
		zephir_array_fast_append(_2, _3);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 16);
		zephir_array_fast_append(_2, _3);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 256);
		zephir_array_fast_append(_2, _3);
		_0 = zephir_fast_in_array(_1, _2 TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_get_level", NULL, 132);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "ob_clean", NULL, 133);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$3);
		object_init_ex(_4$$3, zephir_get_internal_ce(SS("errorexception") TSRMLS_CC));
		zephir_array_fetch_string(&_5$$3, e, SL("message"), PH_NOISY | PH_READONLY, "ice/exception.zep", 172 TSRMLS_CC);
		zephir_array_fetch_string(&_6$$3, e, SL("type"), PH_NOISY | PH_READONLY, "ice/exception.zep", 172 TSRMLS_CC);
		zephir_array_fetch_string(&_7$$3, e, SL("file"), PH_NOISY | PH_READONLY, "ice/exception.zep", 172 TSRMLS_CC);
		zephir_array_fetch_string(&_8$$3, e, SL("line"), PH_NOISY | PH_READONLY, "ice/exception.zep", 172 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_LONG(_9$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "__construct", NULL, 130, _5$$3, _6$$3, _9$$3, _7$$3, _8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(NULL, "handler", NULL, 0, _4$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_10$$3);
		ZVAL_LONG(&_10$$3, 1);
		ZEPHIR_MM_RESTORE();
		zephir_exit(&_10$$3);
	}
	ZEPHIR_MM_RESTORE();

}

