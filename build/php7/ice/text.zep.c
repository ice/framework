
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

	zephir_declare_class_constant_long(ice_text_ce, SL("ALNUM"), 0);

	zephir_declare_class_constant_long(ice_text_ce, SL("ALPHA"), 1);

	zephir_declare_class_constant_long(ice_text_ce, SL("HEXDEC"), 2);

	zephir_declare_class_constant_long(ice_text_ce, SL("NUMERIC"), 3);

	zephir_declare_class_constant_long(ice_text_ce, SL("NOZERO"), 4);

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

	zephir_fcall_cache_entry *_3 = NULL, *_22 = NULL;
	long length;
	zval *type_param = NULL, *length_param = NULL, pool, str, _0$$3, _1$$3, _2$$3, _4$$3, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _11$$5, _12$$5, _13$$6, _14$$6, _15$$7, _16$$7, _17$$7, _18$$7, _19$$7, _20$$7, _21$$7, _23$$8, _24$$8, _25$$8;
	zend_long type, ZEPHIR_LAST_CALL_STATUS, end = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pool);
	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);

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


	ZEPHIR_INIT_VAR(&str);
	ZVAL_STRING(&str, "");
	do {
		if (type == 1) {
			ZEPHIR_INIT_VAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "a");
			ZEPHIR_INIT_VAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "z");
			ZEPHIR_CALL_FUNCTION(&_2$$3, "range", &_3, 189, &_0$$3, &_1$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "A");
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "Z");
			ZEPHIR_CALL_FUNCTION(&_4$$3, "range", &_3, 189, &_0$$3, &_1$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&pool);
			zephir_fast_array_merge(&pool, &_2$$3, &_4$$3 TSRMLS_CC);
			break;
		}
		if (type == 2) {
			ZVAL_LONG(&_5$$4, 0);
			ZVAL_LONG(&_6$$4, 9);
			ZEPHIR_CALL_FUNCTION(&_7$$4, "range", &_3, 189, &_5$$4, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "a");
			ZEPHIR_INIT_VAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "f");
			ZEPHIR_CALL_FUNCTION(&_10$$4, "range", &_3, 189, &_8$$4, &_9$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&pool);
			zephir_fast_array_merge(&pool, &_7$$4, &_10$$4 TSRMLS_CC);
			break;
		}
		if (type == 3) {
			ZVAL_LONG(&_11$$5, 0);
			ZVAL_LONG(&_12$$5, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", &_3, 189, &_11$$5, &_12$$5);
			zephir_check_call_status();
			break;
		}
		if (type == 4) {
			ZVAL_LONG(&_13$$6, 1);
			ZVAL_LONG(&_14$$6, 9);
			ZEPHIR_CALL_FUNCTION(&pool, "range", &_3, 189, &_13$$6, &_14$$6);
			zephir_check_call_status();
			break;
		}
		ZVAL_LONG(&_15$$7, 0);
		ZVAL_LONG(&_16$$7, 9);
		ZEPHIR_CALL_FUNCTION(&_17$$7, "range", &_3, 189, &_15$$7, &_16$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_18$$7);
		ZVAL_STRING(&_18$$7, "a");
		ZEPHIR_INIT_VAR(&_19$$7);
		ZVAL_STRING(&_19$$7, "z");
		ZEPHIR_CALL_FUNCTION(&_20$$7, "range", &_3, 189, &_18$$7, &_19$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_18$$7);
		ZVAL_STRING(&_18$$7, "A");
		ZEPHIR_INIT_NVAR(&_19$$7);
		ZVAL_STRING(&_19$$7, "Z");
		ZEPHIR_CALL_FUNCTION(&_21$$7, "range", &_3, 189, &_18$$7, &_19$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&pool, "array_merge", &_22, 190, &_17$$7, &_20$$7, &_21$$7);
		zephir_check_call_status();
		break;
	} while(0);

	end = (zephir_fast_count_int(&pool TSRMLS_CC) - 1);
	while (1) {
		if (!(zephir_fast_strlen_ev(&str) < length)) {
			break;
		}
		ZVAL_LONG(&_24$$8, 0);
		ZVAL_LONG(&_25$$8, end);
		zephir_array_fetch_long(&_23$$8, &pool, zephir_mt_rand(zephir_get_intval(&_24$$8), zephir_get_intval(&_25$$8) TSRMLS_CC), PH_NOISY | PH_READONLY, "ice/text.zep", 60 TSRMLS_CC);
		zephir_concat_self(&str, &_23$$8 TSRMLS_CC);
	}
	RETURN_CCTOR(&str);

}

