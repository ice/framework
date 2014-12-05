
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * Exception class. Translates exceptions using the [I18n] class.
 */
ZEPHIR_INIT_CLASS(Ice_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Exception, ice, exception, zend_exception_get_default(TSRMLS_C), ice_exception_method_entry, 0);

	return SUCCESS;

}

/**
 * Creates a new exception.
 *
 * @param mixed message Error message
 * @param mixed code The exception code
 * @param Exception previous Previous exception
 * @return void
 */
PHP_METHOD(Ice_Exception, __construct) {

	zval *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_7 = NULL, *_8 = NULL;
	zend_bool _0;
	zval *message = NULL, *code = NULL, *previous = NULL, *di = NULL, *values = NULL, *str = NULL, _2 = zval_used_for_init, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_9 = NULL;

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


	_0 = Z_TYPE_P(previous) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(previous, zend_exception_get_default(TSRMLS_C) TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'previous' must be an instance of 'Exception'", "", 0);
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(message) == IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_CALL_FUNCTION(&values, "array_slice", &_3, message, &_2);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(str);
		zephir_array_fetch_long(&str, message, 0, PH_NOISY, "ice/exception.zep", 26 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(values);
		ZVAL_NULL(values);
		ZEPHIR_CPY_WRT(str, message);
	}
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "i18n", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, di, "has", NULL, _5);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "i18n", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_6, di, "get", NULL, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&message, _6, "translate", NULL, str, values);
		zephir_check_call_status();
	} else if (Z_TYPE_P(values) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(_5);
		zephir_array_keys(_5, values TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "is_string", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "array_filter", &_7, _5, &_2);
		zephir_check_call_status();
		if (zephir_fast_count_int(_6 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&message, "strtr", &_8, str, values);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_9);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_STRING(&_2, "sprintf", 0);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_9, &_2, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _9);
		}
	}
	zephir_get_strval(_10, message);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_LONG(_9, zephir_get_intval(code));
	ZEPHIR_CALL_PARENT(NULL, ice_exception_ce, this_ptr, "__construct", NULL, _10, _9, previous);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

