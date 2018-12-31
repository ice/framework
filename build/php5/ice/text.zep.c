
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
#include "kernel/memory.h"
#include "kernel/array.h"
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
 * @copyright   (c) 2014-2018 Ice Team
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

	zephir_fcall_cache_entry *_3 = NULL, *_18 = NULL;
	long length;
	zval *type_param = NULL, *length_param = NULL, *pool = NULL, *str = NULL, _0$$3 = zval_used_for_init, _1$$3 = zval_used_for_init, *_2$$3 = NULL, *_4$$3 = NULL, _5$$4 = zval_used_for_init, _6$$4 = zval_used_for_init, *_7$$4 = NULL, *_8$$4 = NULL, _9$$5, _10$$5, _11$$6, _12$$6, _13$$7 = zval_used_for_init, _14$$7 = zval_used_for_init, *_15$$7 = NULL, *_16$$7 = NULL, *_17$$7 = NULL, *_19$$8, _20$$8 = zval_used_for_init, _21$$8 = zval_used_for_init;
	zend_long type, ZEPHIR_LAST_CALL_STATUS, end = 0;

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
			ZEPHIR_SINIT_VAR(_0$$3);
			ZVAL_STRING(&_0$$3, "a", 0);
			ZEPHIR_SINIT_VAR(_1$$3);
			ZVAL_STRING(&_1$$3, "z", 0);
			ZEPHIR_CALL_FUNCTION(&_2$$3, "range", &_3, 205, &_0$$3, &_1$$3);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0$$3);
			ZVAL_STRING(&_0$$3, "A", 0);
			ZEPHIR_SINIT_NVAR(_1$$3);
			ZVAL_STRING(&_1$$3, "Z", 0);
			ZEPHIR_CALL_FUNCTION(&_4$$3, "range", &_3, 205, &_0$$3, &_1$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(pool);
			zephir_fast_array_merge(pool, &(_2$$3), &(_4$$3) TSRMLS_CC);
			break;
		}
		if (type == 2) {
			ZEPHIR_SINIT_VAR(_5$$4);
			ZVAL_LONG(&_5$$4, 0);
			ZEPHIR_SINIT_VAR(_6$$4);
			ZVAL_LONG(&_6$$4, 9);
			ZEPHIR_CALL_FUNCTION(&_7$$4, "range", &_3, 205, &_5$$4, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_5$$4);
			ZVAL_STRING(&_5$$4, "a", 0);
			ZEPHIR_SINIT_NVAR(_6$$4);
			ZVAL_STRING(&_6$$4, "f", 0);
			ZEPHIR_CALL_FUNCTION(&_8$$4, "range", &_3, 205, &_5$$4, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(pool);
			zephir_fast_array_merge(pool, &(_7$$4), &(_8$$4) TSRMLS_CC);
			break;
		}
		if (type == 3) {
			ZEPHIR_SINIT_VAR(_9$$5);
			ZVAL_LONG(&_9$$5, 0);
			ZEPHIR_SINIT_VAR(_10$$5);
			ZVAL_LONG(&_10$$5, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", &_3, 205, &_9$$5, &_10$$5);
			zephir_check_call_status();
			break;
		}
		if (type == 4) {
			ZEPHIR_SINIT_VAR(_11$$6);
			ZVAL_LONG(&_11$$6, 1);
			ZEPHIR_SINIT_VAR(_12$$6);
			ZVAL_LONG(&_12$$6, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", &_3, 205, &_11$$6, &_12$$6);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_SINIT_VAR(_13$$7);
		ZVAL_LONG(&_13$$7, 0);
		ZEPHIR_SINIT_VAR(_14$$7);
		ZVAL_LONG(&_14$$7, 9);
		ZEPHIR_CALL_FUNCTION(&_15$$7, "range", &_3, 205, &_13$$7, &_14$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_13$$7);
		ZVAL_STRING(&_13$$7, "a", 0);
		ZEPHIR_SINIT_NVAR(_14$$7);
		ZVAL_STRING(&_14$$7, "z", 0);
		ZEPHIR_CALL_FUNCTION(&_16$$7, "range", &_3, 205, &_13$$7, &_14$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_13$$7);
		ZVAL_STRING(&_13$$7, "A", 0);
		ZEPHIR_SINIT_NVAR(_14$$7);
		ZVAL_STRING(&_14$$7, "Z", 0);
		ZEPHIR_CALL_FUNCTION(&_17$$7, "range", &_3, 205, &_13$$7, &_14$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&pool, "array_merge", &_18, 206, _15$$7, _16$$7, _17$$7);
		zephir_check_call_status();
		break;
	} while(0);

	end = (zephir_fast_count_int(pool TSRMLS_CC) - 1);
	while (1) {
		if (!(zephir_fast_strlen_ev(str) < length)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_20$$8);
		ZVAL_LONG(&_20$$8, 0);
		ZEPHIR_SINIT_NVAR(_21$$8);
		ZVAL_LONG(&_21$$8, end);
		zephir_array_fetch_long(&_19$$8, pool, zephir_mt_rand(zephir_get_intval(&_20$$8), zephir_get_intval(&_21$$8) TSRMLS_CC), PH_NOISY | PH_READONLY, "ice/text.zep", 60 TSRMLS_CC);
		zephir_concat_self(&str, _19$$8 TSRMLS_CC);
	}
	RETURN_CCTOR(str);

}

