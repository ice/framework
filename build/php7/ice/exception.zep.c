
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
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/exit.h"


/**
 * Exception class.
 *
 * @package     Ice/Exception
 * @category    Error
 * @author      Ice Team
 * @copyright   (c) 2014-2020 Ice Team
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

	zval _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *message = NULL, message_sub, *code = NULL, code_sub, *previous = NULL, previous_sub, __$null, di, values, str, _2, _3, _12, _1$$3, _4$$5, _5$$5, _6$$6, _7$$6, _8$$6, _9$$8, _10$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&previous_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &message, &code, &previous);

	if (!message) {
		message = &message_sub;
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "");
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!code) {
		code = &code_sub;
		ZEPHIR_INIT_VAR(code);
		ZVAL_LONG(code, 0);
	}
	if (!previous) {
		previous = &previous_sub;
		previous = &__$null;
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(message) == IS_ARRAY) {
		ZVAL_LONG(&_1$$3, 1);
		ZEPHIR_CALL_FUNCTION(&values, "array_slice", NULL, 124, message, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&str);
		zephir_array_fetch_long(&str, message, 0, PH_NOISY, "ice/exception.zep", 31);
	} else {
		ZEPHIR_INIT_NVAR(&values);
		ZVAL_NULL(&values);
		ZEPHIR_CPY_WRT(&str, message);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "i18n");
	ZEPHIR_CALL_METHOD(&_2, &di, "has", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "i18n");
		ZEPHIR_CALL_METHOD(&_4$$5, &di, "get", NULL, 0, &_5$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(message, &_4$$5, "translate", NULL, 0, &str, &values);
		zephir_check_call_status();
	} else if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_6$$6);
		zephir_array_keys(&_6$$6, &values);
		ZEPHIR_INIT_VAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "is_string");
		ZEPHIR_CALL_FUNCTION(&_8$$6, "array_filter", NULL, 7, &_6$$6, &_7$$6);
		zephir_check_call_status();
		if (zephir_fast_count_int(&_8$$6)) {
			ZEPHIR_CALL_FUNCTION(message, "strtr", NULL, 110, &str, &values);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_9$$8);
			ZEPHIR_INIT_VAR(&_10$$8);
			ZVAL_STRING(&_10$$8, "sprintf");
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_9$$8, &_10$$8, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, &_9$$8);
		}
	}
	zephir_get_strval(&_11, message);
	ZVAL_LONG(&_12, zephir_get_intval(code));
	ZEPHIR_CALL_PARENT(NULL, ice_exception_ce, getThis(), "__construct", NULL, 0, &_11, &_12, previous);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_30 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, count;
	zval *e, e_sub, output, frame, args, arg, node, _0, *_1, _2, _3$$4, *_4$$4, _5$$4, _6$$5, _7$$6, _8$$7, _9$$8, _10$$9, _11$$10, _12$$10, _13$$13, _14$$14, _15$$15, _16$$16, _17$$17, _18$$18, _19$$18, _20$$3, _21$$3, _22$$3, _23$$3, _24$$3, _25$$3, _26$$3, _27$$3, _28$$3, _29$$3, _31$$22, *_32$$22, _33$$22, _34$$23, _35$$24, _36$$25, _37$$26, _38$$27, _39$$28, _40$$28, _41$$31, _42$$32, _43$$33, _44$$34, _45$$35, _46$$36, _47$$36, _48$$21, _49$$21, _50$$21, _51$$21, _52$$21, _53$$21, _54$$21, _55$$21, _56$$21, _57$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&frame);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&arg);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_27$$3);
	ZVAL_UNDEF(&_28$$3);
	ZVAL_UNDEF(&_29$$3);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_36$$25);
	ZVAL_UNDEF(&_37$$26);
	ZVAL_UNDEF(&_38$$27);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&_40$$28);
	ZVAL_UNDEF(&_41$$31);
	ZVAL_UNDEF(&_42$$32);
	ZVAL_UNDEF(&_43$$33);
	ZVAL_UNDEF(&_44$$34);
	ZVAL_UNDEF(&_45$$35);
	ZVAL_UNDEF(&_46$$36);
	ZVAL_UNDEF(&_47$$36);
	ZVAL_UNDEF(&_48$$21);
	ZVAL_UNDEF(&_49$$21);
	ZVAL_UNDEF(&_50$$21);
	ZVAL_UNDEF(&_51$$21);
	ZVAL_UNDEF(&_52$$21);
	ZVAL_UNDEF(&_53$$21);
	ZVAL_UNDEF(&_54$$21);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_56$$21);
	ZVAL_UNDEF(&_57$$21);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &e);



	count = 0;
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_CALL_METHOD(&_0, e, "gettrace", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "ice/exception.zep", 108);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&frame);
			ZVAL_COPY(&frame, _1);
			ZEPHIR_INIT_NVAR(&args);
			ZVAL_STRING(&args, "");
			if (zephir_array_isset_string(&frame, SL("args"))) {
				ZEPHIR_INIT_NVAR(&node);
				array_init(&node);
				zephir_array_fetch_string(&_3$$4, &frame, SL("args"), PH_NOISY | PH_READONLY, "ice/exception.zep", 71);
				zephir_is_iterable(&_3$$4, 0, "ice/exception.zep", 96);
				if (Z_TYPE_P(&_3$$4) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3$$4), _4$$4)
					{
						ZEPHIR_INIT_NVAR(&arg);
						ZVAL_COPY(&arg, _4$$4);
						ZEPHIR_INIT_NVAR(&_6$$5);
						zephir_gettype(&_6$$5, &arg);
						do {
							if (ZEPHIR_IS_STRING(&_6$$5, "string")) {
								ZEPHIR_INIT_NVAR(&_7$$6);
								ZEPHIR_CONCAT_SVS(&_7$$6, "'", &arg, "'");
								zephir_array_append(&node, &_7$$6, PH_SEPARATE, "ice/exception.zep", 74);
								break;
							}
							if (ZEPHIR_IS_STRING(&_6$$5, "array")) {
								ZEPHIR_INIT_NVAR(&_8$$7);
								ZVAL_STRING(&_8$$7, "Array");
								zephir_array_append(&node, &_8$$7, PH_SEPARATE, "ice/exception.zep", 77);
								break;
							}
							if (ZEPHIR_IS_STRING(&_6$$5, "NULL")) {
								ZEPHIR_INIT_NVAR(&_9$$8);
								ZVAL_STRING(&_9$$8, "NULL");
								zephir_array_append(&node, &_9$$8, PH_SEPARATE, "ice/exception.zep", 80);
								break;
							}
							if (ZEPHIR_IS_STRING(&_6$$5, "boolean")) {
								ZEPHIR_INIT_NVAR(&_10$$9);
								if (zephir_is_true(&arg)) {
									ZEPHIR_INIT_NVAR(&_10$$9);
									ZVAL_STRING(&_10$$9, "true");
								} else {
									ZEPHIR_INIT_NVAR(&_10$$9);
									ZVAL_STRING(&_10$$9, "false");
								}
								zephir_array_append(&node, &_10$$9, PH_SEPARATE, "ice/exception.zep", 83);
								break;
							}
							if (ZEPHIR_IS_STRING(&_6$$5, "object")) {
								ZEPHIR_INIT_NVAR(&_11$$10);
								zephir_get_class(&_11$$10, &arg, 0);
								ZEPHIR_INIT_NVAR(&_12$$10);
								ZEPHIR_CONCAT_SVS(&_12$$10, "Object(", &_11$$10, ")");
								zephir_array_append(&node, &_12$$10, PH_SEPARATE, "ice/exception.zep", 86);
								break;
							}
							if (ZEPHIR_IS_STRING(&_6$$5, "resource")) {
								zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 89);
								break;
							}
							zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 92);
							break;
						} while(0);

					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_3$$4, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_5$$4, &_3$$4, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_5$$4)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&arg, &_3$$4, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_13$$13);
							zephir_gettype(&_13$$13, &arg);
							do {
								if (ZEPHIR_IS_STRING(&_13$$13, "string")) {
									ZEPHIR_INIT_NVAR(&_14$$14);
									ZEPHIR_CONCAT_SVS(&_14$$14, "'", &arg, "'");
									zephir_array_append(&node, &_14$$14, PH_SEPARATE, "ice/exception.zep", 74);
									break;
								}
								if (ZEPHIR_IS_STRING(&_13$$13, "array")) {
									ZEPHIR_INIT_NVAR(&_15$$15);
									ZVAL_STRING(&_15$$15, "Array");
									zephir_array_append(&node, &_15$$15, PH_SEPARATE, "ice/exception.zep", 77);
									break;
								}
								if (ZEPHIR_IS_STRING(&_13$$13, "NULL")) {
									ZEPHIR_INIT_NVAR(&_16$$16);
									ZVAL_STRING(&_16$$16, "NULL");
									zephir_array_append(&node, &_16$$16, PH_SEPARATE, "ice/exception.zep", 80);
									break;
								}
								if (ZEPHIR_IS_STRING(&_13$$13, "boolean")) {
									ZEPHIR_INIT_NVAR(&_17$$17);
									if (zephir_is_true(&arg)) {
										ZEPHIR_INIT_NVAR(&_17$$17);
										ZVAL_STRING(&_17$$17, "true");
									} else {
										ZEPHIR_INIT_NVAR(&_17$$17);
										ZVAL_STRING(&_17$$17, "false");
									}
									zephir_array_append(&node, &_17$$17, PH_SEPARATE, "ice/exception.zep", 83);
									break;
								}
								if (ZEPHIR_IS_STRING(&_13$$13, "object")) {
									ZEPHIR_INIT_NVAR(&_18$$18);
									zephir_get_class(&_18$$18, &arg, 0);
									ZEPHIR_INIT_NVAR(&_19$$18);
									ZEPHIR_CONCAT_SVS(&_19$$18, "Object(", &_18$$18, ")");
									zephir_array_append(&node, &_19$$18, PH_SEPARATE, "ice/exception.zep", 86);
									break;
								}
								if (ZEPHIR_IS_STRING(&_13$$13, "resource")) {
									zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 89);
									break;
								}
								zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 92);
								break;
							} while(0);

						ZEPHIR_CALL_METHOD(NULL, &_3$$4, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&arg);
				ZEPHIR_INIT_NVAR(&args);
				zephir_fast_join_str(&args, SL(", "), &node);
			}
			ZEPHIR_INIT_NVAR(&_20$$3);
			if (zephir_array_isset_string(&frame, SL("file"))) {
				zephir_array_fetch_string(&_21$$3, &frame, SL("file"), PH_NOISY | PH_READONLY, "ice/exception.zep", 102);
				zephir_array_fetch_string(&_22$$3, &frame, SL("line"), PH_NOISY | PH_READONLY, "ice/exception.zep", 102);
				ZEPHIR_INIT_NVAR(&_20$$3);
				ZEPHIR_CONCAT_VSVS(&_20$$3, &_21$$3, "(", &_22$$3, ")");
			} else {
				ZEPHIR_INIT_NVAR(&_20$$3);
				ZVAL_STRING(&_20$$3, "[internal function]");
			}
			ZEPHIR_INIT_NVAR(&_23$$3);
			if (zephir_array_isset_string(&frame, SL("class"))) {
				zephir_array_fetch_string(&_24$$3, &frame, SL("class"), PH_NOISY | PH_READONLY, "ice/exception.zep", 103);
				zephir_array_fetch_string(&_25$$3, &frame, SL("type"), PH_NOISY | PH_READONLY, "ice/exception.zep", 103);
				zephir_array_fetch_string(&_26$$3, &frame, SL("function"), PH_NOISY | PH_READONLY, "ice/exception.zep", 103);
				ZEPHIR_INIT_NVAR(&_23$$3);
				ZEPHIR_CONCAT_VVV(&_23$$3, &_24$$3, &_25$$3, &_26$$3);
			} else {
				ZEPHIR_OBS_NVAR(&_23$$3);
				zephir_array_fetch_string(&_23$$3, &frame, SL("function"), PH_NOISY, "ice/exception.zep", 103);
			}
			ZEPHIR_INIT_NVAR(&_27$$3);
			ZVAL_STRING(&_27$$3, "#%s %s: %s(%s)\n");
			ZVAL_LONG(&_28$$3, count);
			ZEPHIR_CALL_FUNCTION(&_29$$3, "sprintf", &_30, 11, &_27$$3, &_28$$3, &_20$$3, &_23$$3, &args);
			zephir_check_call_status();
			zephir_concat_self(&output, &_29$$3);
			count++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&frame, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&args);
				ZVAL_STRING(&args, "");
				if (zephir_array_isset_string(&frame, SL("args"))) {
					ZEPHIR_INIT_NVAR(&node);
					array_init(&node);
					zephir_array_fetch_string(&_31$$22, &frame, SL("args"), PH_NOISY | PH_READONLY, "ice/exception.zep", 71);
					zephir_is_iterable(&_31$$22, 0, "ice/exception.zep", 96);
					if (Z_TYPE_P(&_31$$22) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_31$$22), _32$$22)
						{
							ZEPHIR_INIT_NVAR(&arg);
							ZVAL_COPY(&arg, _32$$22);
							ZEPHIR_INIT_NVAR(&_34$$23);
							zephir_gettype(&_34$$23, &arg);
							do {
								if (ZEPHIR_IS_STRING(&_34$$23, "string")) {
									ZEPHIR_INIT_NVAR(&_35$$24);
									ZEPHIR_CONCAT_SVS(&_35$$24, "'", &arg, "'");
									zephir_array_append(&node, &_35$$24, PH_SEPARATE, "ice/exception.zep", 74);
									break;
								}
								if (ZEPHIR_IS_STRING(&_34$$23, "array")) {
									ZEPHIR_INIT_NVAR(&_36$$25);
									ZVAL_STRING(&_36$$25, "Array");
									zephir_array_append(&node, &_36$$25, PH_SEPARATE, "ice/exception.zep", 77);
									break;
								}
								if (ZEPHIR_IS_STRING(&_34$$23, "NULL")) {
									ZEPHIR_INIT_NVAR(&_37$$26);
									ZVAL_STRING(&_37$$26, "NULL");
									zephir_array_append(&node, &_37$$26, PH_SEPARATE, "ice/exception.zep", 80);
									break;
								}
								if (ZEPHIR_IS_STRING(&_34$$23, "boolean")) {
									ZEPHIR_INIT_NVAR(&_38$$27);
									if (zephir_is_true(&arg)) {
										ZEPHIR_INIT_NVAR(&_38$$27);
										ZVAL_STRING(&_38$$27, "true");
									} else {
										ZEPHIR_INIT_NVAR(&_38$$27);
										ZVAL_STRING(&_38$$27, "false");
									}
									zephir_array_append(&node, &_38$$27, PH_SEPARATE, "ice/exception.zep", 83);
									break;
								}
								if (ZEPHIR_IS_STRING(&_34$$23, "object")) {
									ZEPHIR_INIT_NVAR(&_39$$28);
									zephir_get_class(&_39$$28, &arg, 0);
									ZEPHIR_INIT_NVAR(&_40$$28);
									ZEPHIR_CONCAT_SVS(&_40$$28, "Object(", &_39$$28, ")");
									zephir_array_append(&node, &_40$$28, PH_SEPARATE, "ice/exception.zep", 86);
									break;
								}
								if (ZEPHIR_IS_STRING(&_34$$23, "resource")) {
									zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 89);
									break;
								}
								zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 92);
								break;
							} while(0);

						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_31$$22, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_33$$22, &_31$$22, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_33$$22)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&arg, &_31$$22, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_41$$31);
								zephir_gettype(&_41$$31, &arg);
								do {
									if (ZEPHIR_IS_STRING(&_41$$31, "string")) {
										ZEPHIR_INIT_NVAR(&_42$$32);
										ZEPHIR_CONCAT_SVS(&_42$$32, "'", &arg, "'");
										zephir_array_append(&node, &_42$$32, PH_SEPARATE, "ice/exception.zep", 74);
										break;
									}
									if (ZEPHIR_IS_STRING(&_41$$31, "array")) {
										ZEPHIR_INIT_NVAR(&_43$$33);
										ZVAL_STRING(&_43$$33, "Array");
										zephir_array_append(&node, &_43$$33, PH_SEPARATE, "ice/exception.zep", 77);
										break;
									}
									if (ZEPHIR_IS_STRING(&_41$$31, "NULL")) {
										ZEPHIR_INIT_NVAR(&_44$$34);
										ZVAL_STRING(&_44$$34, "NULL");
										zephir_array_append(&node, &_44$$34, PH_SEPARATE, "ice/exception.zep", 80);
										break;
									}
									if (ZEPHIR_IS_STRING(&_41$$31, "boolean")) {
										ZEPHIR_INIT_NVAR(&_45$$35);
										if (zephir_is_true(&arg)) {
											ZEPHIR_INIT_NVAR(&_45$$35);
											ZVAL_STRING(&_45$$35, "true");
										} else {
											ZEPHIR_INIT_NVAR(&_45$$35);
											ZVAL_STRING(&_45$$35, "false");
										}
										zephir_array_append(&node, &_45$$35, PH_SEPARATE, "ice/exception.zep", 83);
										break;
									}
									if (ZEPHIR_IS_STRING(&_41$$31, "object")) {
										ZEPHIR_INIT_NVAR(&_46$$36);
										zephir_get_class(&_46$$36, &arg, 0);
										ZEPHIR_INIT_NVAR(&_47$$36);
										ZEPHIR_CONCAT_SVS(&_47$$36, "Object(", &_46$$36, ")");
										zephir_array_append(&node, &_47$$36, PH_SEPARATE, "ice/exception.zep", 86);
										break;
									}
									if (ZEPHIR_IS_STRING(&_41$$31, "resource")) {
										zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 89);
										break;
									}
									zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 92);
									break;
								} while(0);

							ZEPHIR_CALL_METHOD(NULL, &_31$$22, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&arg);
					ZEPHIR_INIT_NVAR(&args);
					zephir_fast_join_str(&args, SL(", "), &node);
				}
				ZEPHIR_INIT_NVAR(&_48$$21);
				if (zephir_array_isset_string(&frame, SL("file"))) {
					zephir_array_fetch_string(&_49$$21, &frame, SL("file"), PH_NOISY | PH_READONLY, "ice/exception.zep", 102);
					zephir_array_fetch_string(&_50$$21, &frame, SL("line"), PH_NOISY | PH_READONLY, "ice/exception.zep", 102);
					ZEPHIR_INIT_NVAR(&_48$$21);
					ZEPHIR_CONCAT_VSVS(&_48$$21, &_49$$21, "(", &_50$$21, ")");
				} else {
					ZEPHIR_INIT_NVAR(&_48$$21);
					ZVAL_STRING(&_48$$21, "[internal function]");
				}
				ZEPHIR_INIT_NVAR(&_51$$21);
				if (zephir_array_isset_string(&frame, SL("class"))) {
					zephir_array_fetch_string(&_52$$21, &frame, SL("class"), PH_NOISY | PH_READONLY, "ice/exception.zep", 103);
					zephir_array_fetch_string(&_53$$21, &frame, SL("type"), PH_NOISY | PH_READONLY, "ice/exception.zep", 103);
					zephir_array_fetch_string(&_54$$21, &frame, SL("function"), PH_NOISY | PH_READONLY, "ice/exception.zep", 103);
					ZEPHIR_INIT_NVAR(&_51$$21);
					ZEPHIR_CONCAT_VVV(&_51$$21, &_52$$21, &_53$$21, &_54$$21);
				} else {
					ZEPHIR_OBS_NVAR(&_51$$21);
					zephir_array_fetch_string(&_51$$21, &frame, SL("function"), PH_NOISY, "ice/exception.zep", 103);
				}
				ZEPHIR_INIT_NVAR(&_55$$21);
				ZVAL_STRING(&_55$$21, "#%s %s: %s(%s)\n");
				ZVAL_LONG(&_56$$21, count);
				ZEPHIR_CALL_FUNCTION(&_57$$21, "sprintf", &_30, 11, &_55$$21, &_56$$21, &_48$$21, &_51$$21, &args);
				zephir_check_call_status();
				zephir_concat_self(&output, &_57$$21);
				count++;
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&frame);
	RETURN_CCTOR(&output);

}

/**
 * PHP error handler, converts all errors into ErrorExceptions. This handler respects error_reporting settings.
 *
 * @throws ErrorException
 * @return true
 */
PHP_METHOD(Ice_Exception, errorHandler) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zval message, file;
	zval *code_param = NULL, *message_param = NULL, *file_param = NULL, *line_param = NULL, *context_param = NULL, _0, _1$$3, _2$$3, _3$$3, _4$$3;
	zend_long code, line, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &code_param, &message_param, &file_param, &line_param, &context_param);

	code = zephir_get_intval(code_param);
	zephir_get_strval(&message, message_param);
	if (!file_param) {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_STRING(&file, "");
	} else {
		zephir_get_strval(&file, file_param);
	}
	if (!line_param) {
		line = 0;
	} else {
		line = zephir_get_intval(line_param);
	}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "error_reporting", NULL, 125);
	zephir_check_call_status();
	if (((int) (zephir_get_numberval(&_0)) & code)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zephir_get_internal_ce(SL("errorexception")));
		ZVAL_LONG(&_2$$3, code);
		ZVAL_LONG(&_3$$3, 0);
		ZVAL_LONG(&_4$$3, line);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 126, &message, &_2$$3, &_3$$3, &file, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "ice/exception.zep", 122);
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

	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *e, e_sub, di, response, _1, _3, _5, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &e);



	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "response");
	ZEPHIR_CALL_METHOD(&response, &di, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(NULL, &response, "setbody", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, e);
	zephir_array_fast_append(&_2, &di);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "exception.after.uncaught");
	ZEPHIR_CALL_METHOD(NULL, &di, "applyhook", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &response, "getbody", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(&_4$$3, &response, "send", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(&_4$$3, 0);
	} else {
		zephir_throw_exception_debug(e, "ice/exception.zep", 149);
		ZEPHIR_MM_RESTORE();
		return;
	}
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

	zval _2;
	zend_bool _0;
	zval e, _1, _3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&e, "error_get_last", NULL, 127);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&e) == IS_ARRAY;
	if (_0) {
		zephir_array_fetch_string(&_1, &e, SL("type"), PH_NOISY | PH_READONLY, "ice/exception.zep", 166);
		ZEPHIR_INIT_VAR(&_2);
		zephir_create_array(&_2, 4, 0);
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_LONG(&_3, 4);
		zephir_array_fast_append(&_2, &_3);
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_LONG(&_3, 1);
		zephir_array_fast_append(&_2, &_3);
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_LONG(&_3, 16);
		zephir_array_fast_append(&_2, &_3);
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_LONG(&_3, 256);
		zephir_array_fast_append(&_2, &_3);
		_0 = zephir_fast_in_array(&_1, &_2);
	}
	if (_0) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_get_level", NULL, 128);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "ob_clean", NULL, 129);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, zephir_get_internal_ce(SL("errorexception")));
		zephir_array_fetch_string(&_5$$3, &e, SL("message"), PH_NOISY | PH_READONLY, "ice/exception.zep", 171);
		zephir_array_fetch_string(&_6$$3, &e, SL("type"), PH_NOISY | PH_READONLY, "ice/exception.zep", 171);
		zephir_array_fetch_string(&_7$$3, &e, SL("file"), PH_NOISY | PH_READONLY, "ice/exception.zep", 171);
		zephir_array_fetch_string(&_8$$3, &e, SL("line"), PH_NOISY | PH_READONLY, "ice/exception.zep", 171);
		ZVAL_LONG(&_9$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 126, &_5$$3, &_6$$3, &_9$$3, &_7$$3, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(NULL, "handler", NULL, 0, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_9$$3, 1);
		ZEPHIR_MM_RESTORE();
		zephir_exit(&_9$$3);
	}
	ZEPHIR_MM_RESTORE();

}

