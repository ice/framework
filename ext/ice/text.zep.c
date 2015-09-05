
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/math.h"


/**
 * Text helper.
 *
 * @package     Ice/Text
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Text) {

	ZEPHIR_REGISTER_CLASS(Ice, Text, ice, text, ice_text_method_entry, 0);

	zend_declare_class_constant_long(ice_text_ce, SL("ALNUM"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_text_ce, SL("ALPHA"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_text_ce, SL("HEXDEC"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_text_ce, SL("NUMERIC"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(ice_text_ce, SL("NOZERO"), 4 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Generates a random string based on the given type. Type is one of the constants.
 *
 * @param int type
 * @param int length
 * @return string
 */
PHP_METHOD(Ice_Text, random) {

	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	long length;
	zval *type_param = NULL, *length_param = NULL, *pool = NULL, *str, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_7;
	int type, end, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &type_param, &length_param);

	if (!type_param) {
		type = 0;
	} else {
		type = zephir_get_intval(type_param);
	}
	if (!length_param) {
		length = 8;
	} else {
		length = zephir_get_intval(length_param);
	}
	ZEPHIR_INIT_VAR(str);
	ZVAL_STRING(str, "", 1);


	do {
		if (type == 1) {
			ZEPHIR_SINIT_VAR(_0);
			ZVAL_STRING(&_0, "a", 0);
			ZEPHIR_SINIT_VAR(_1);
			ZVAL_STRING(&_1, "z", 0);
			ZEPHIR_CALL_FUNCTION(&_2, "range", &_3, 160, &_0, &_1);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "A", 0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "Z", 0);
			ZEPHIR_CALL_FUNCTION(&_4, "range", &_3, 160, &_0, &_1);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(pool);
			zephir_fast_array_merge(pool, &(_2), &(_4) TSRMLS_CC);
			break;
		}
		if (type == 2) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 9);
			ZEPHIR_CALL_FUNCTION(&_2, "range", &_3, 160, &_0, &_1);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "a", 0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "f", 0);
			ZEPHIR_CALL_FUNCTION(&_4, "range", &_3, 160, &_0, &_1);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(pool);
			zephir_fast_array_merge(pool, &(_2), &(_4) TSRMLS_CC);
			break;
		}
		if (type == 3) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", &_3, 160, &_0, &_1);
			zephir_check_call_status();
			break;
		}
		if (type == 4) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 1);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", &_3, 160, &_0, &_1);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 9);
		ZEPHIR_CALL_FUNCTION(&_2, "range", &_3, 160, &_0, &_1);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "a", 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "z", 0);
		ZEPHIR_CALL_FUNCTION(&_4, "range", &_3, 160, &_0, &_1);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "A", 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "Z", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "range", &_3, 160, &_0, &_1);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&pool, "array_merge", &_6, 161, _2, _4, _5);
		zephir_check_call_status();
		break;
	} while(0);

	end = (zephir_fast_count_int(pool TSRMLS_CC) - 1);
	while (1) {
		if (!(zephir_fast_strlen_ev(str) < length)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, end);
		zephir_array_fetch_long(&_7, pool, zephir_mt_rand(zephir_get_intval(&_0), zephir_get_intval(&_1) TSRMLS_CC), PH_NOISY | PH_READONLY, "ice/text.zep", 61 TSRMLS_CC);
		zephir_concat_self(&str, _7 TSRMLS_CC);
	}
	RETURN_CCTOR(str);

}

