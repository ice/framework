
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
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/exit.h"


/**
 * Exception class.
 *
 * @package     Ice/Exception
 * @category    Error
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Exception)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice, Exception, ice, exception, zend_ce_exception, ice_exception_method_entry, 0);

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
PHP_METHOD(Ice_Exception, __construct)
{
	zval _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, message_sub, *code = NULL, code_sub, *previous = NULL, previous_sub, __$null, di, values, str, _1, _2, _11, _0$$3, _3$$5, _4$$5, _5$$6, _6$$6, _7$$6, _8$$8, _9$$8;

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&previous_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(message)
		Z_PARAM_ZVAL(code)
		Z_PARAM_ZVAL_OR_NULL(previous)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(message) == IS_ARRAY) {
		ZVAL_LONG(&_0$$3, 1);
		ZEPHIR_CALL_FUNCTION(&values, "array_slice", NULL, 127, message, &_0$$3);
		zephir_check_call_status();
		zephir_memory_observe(&str);
		zephir_array_fetch_long(&str, message, 0, PH_NOISY, "ice/exception.zep", 31);
	} else {
		ZEPHIR_INIT_NVAR(&values);
		ZVAL_NULL(&values);
		ZEPHIR_CPY_WRT(&str, message);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "i18n");
	ZEPHIR_CALL_METHOD(&_1, &di, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "i18n");
		ZEPHIR_CALL_METHOD(&_3$$5, &di, "get", NULL, 0, &_4$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(message, &_3$$5, "translate", NULL, 0, &str, &values);
		zephir_check_call_status();
	} else if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_5$$6);
		zephir_array_keys(&_5$$6, &values);
		ZEPHIR_INIT_VAR(&_6$$6);
		ZVAL_STRING(&_6$$6, "is_string");
		ZEPHIR_CALL_FUNCTION(&_7$$6, "array_filter", NULL, 8, &_5$$6, &_6$$6);
		zephir_check_call_status();
		if (zephir_fast_count_int(&_7$$6)) {
			ZEPHIR_CALL_FUNCTION(message, "strtr", NULL, 113, &str, &values);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_8$$8);
			ZEPHIR_INIT_VAR(&_9$$8);
			ZVAL_STRING(&_9$$8, "sprintf");
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_8$$8, &_9$$8, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, &_8$$8);
		}
	}
	zephir_cast_to_string(&_10, message);
	ZVAL_LONG(&_11, zephir_get_intval(code));
	ZEPHIR_CALL_PARENT(NULL, ice_exception_ce, getThis(), "__construct", NULL, 0, &_10, &_11, previous);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Get the full trace as string.
 *
 * @param Exception|Throwable $e
 * @return string
 */
PHP_METHOD(Ice_Exception, getFullTraceAsString)
{
	zend_bool _36, _16$$4, _49$$22;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_34 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, count;
	zval *e, e_sub, output, frame, args, arg, node, _0, *_1, _2, *_3, _35, _4$$4, *_5$$4, _6$$4, *_7$$4, _15$$4, _8$$5, _9$$6, _10$$7, _11$$8, _12$$9, _13$$10, _14$$10, _17$$13, _18$$14, _19$$15, _20$$16, _21$$17, _22$$18, _23$$18, _24$$3, _25$$3, _26$$3, _27$$3, _28$$3, _29$$3, _30$$3, _31$$3, _32$$3, _33$$3, _37$$22, *_38$$22, _39$$22, *_40$$22, _48$$22, _41$$23, _42$$24, _43$$25, _44$$26, _45$$27, _46$$28, _47$$28, _50$$31, _51$$32, _52$$33, _53$$34, _54$$35, _55$$36, _56$$36, _57$$21, _58$$21, _59$$21, _60$$21, _61$$21, _62$$21, _63$$21, _64$$21, _65$$21, _66$$21;

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&frame);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&arg);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_27$$3);
	ZVAL_UNDEF(&_28$$3);
	ZVAL_UNDEF(&_29$$3);
	ZVAL_UNDEF(&_30$$3);
	ZVAL_UNDEF(&_31$$3);
	ZVAL_UNDEF(&_32$$3);
	ZVAL_UNDEF(&_33$$3);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_48$$22);
	ZVAL_UNDEF(&_41$$23);
	ZVAL_UNDEF(&_42$$24);
	ZVAL_UNDEF(&_43$$25);
	ZVAL_UNDEF(&_44$$26);
	ZVAL_UNDEF(&_45$$27);
	ZVAL_UNDEF(&_46$$28);
	ZVAL_UNDEF(&_47$$28);
	ZVAL_UNDEF(&_50$$31);
	ZVAL_UNDEF(&_51$$32);
	ZVAL_UNDEF(&_52$$33);
	ZVAL_UNDEF(&_53$$34);
	ZVAL_UNDEF(&_54$$35);
	ZVAL_UNDEF(&_55$$36);
	ZVAL_UNDEF(&_56$$36);
	ZVAL_UNDEF(&_57$$21);
	ZVAL_UNDEF(&_58$$21);
	ZVAL_UNDEF(&_59$$21);
	ZVAL_UNDEF(&_60$$21);
	ZVAL_UNDEF(&_61$$21);
	ZVAL_UNDEF(&_62$$21);
	ZVAL_UNDEF(&_63$$21);
	ZVAL_UNDEF(&_64$$21);
	ZVAL_UNDEF(&_65$$21);
	ZVAL_UNDEF(&_66$$21);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(e)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &e);
	count = 0;
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_CALL_METHOD(&_0, e, "gettrace", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "ice/exception.zep", 108);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&frame);
			ZVAL_COPY(&frame, _3);
			ZEPHIR_INIT_NVAR(&args);
			ZVAL_STRING(&args, "");
			if (zephir_array_isset_value_string(&frame, SL("args"))) {
				ZEPHIR_INIT_NVAR(&node);
				array_init(&node);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch_string(&_4$$4, &frame, SL("args"), PH_NOISY, "ice/exception.zep", 71);
				if (Z_TYPE_P(&_4$$4) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_6$$4);
					zephir_string_to_char_array(&_6$$4, &_4$$4);
					_5$$4 = &_6$$4;
				} else {
					_5$$4 = &_4$$4;
				}
				zephir_is_iterable(_5$$4, 0, "ice/exception.zep", 96);
				if (Z_TYPE_P(_5$$4) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_5$$4), _7$$4)
					{
						ZEPHIR_INIT_NVAR(&arg);
						ZVAL_COPY(&arg, _7$$4);
						ZEPHIR_INIT_NVAR(&_8$$5);
						zephir_gettype(&_8$$5, &arg);
						if (ZEPHIR_IS_STRING(&_8$$5, "string")) { goto zephir_switch_0_clause_0; }
						if (ZEPHIR_IS_STRING(&_8$$5, "array")) { goto zephir_switch_0_clause_1; }
						if (ZEPHIR_IS_STRING(&_8$$5, "NULL")) { goto zephir_switch_0_clause_2; }
						if (ZEPHIR_IS_STRING(&_8$$5, "boolean")) { goto zephir_switch_0_clause_3; }
						if (ZEPHIR_IS_STRING(&_8$$5, "object")) { goto zephir_switch_0_clause_4; }
						if (ZEPHIR_IS_STRING(&_8$$5, "resource")) { goto zephir_switch_0_clause_5; }
						goto zephir_switch_0_clause_6;
						zephir_switch_0_clause_0: ;
							ZEPHIR_INIT_NVAR(&_9$$6);
							ZEPHIR_CONCAT_SVS(&_9$$6, "'", &arg, "'");
							zephir_array_append(&node, &_9$$6, PH_SEPARATE, "ice/exception.zep", 74);
							goto zephir_switch_0_end;
						zephir_switch_0_clause_1: ;
							ZEPHIR_INIT_NVAR(&_10$$7);
							ZVAL_STRING(&_10$$7, "Array");
							zephir_array_append(&node, &_10$$7, PH_SEPARATE, "ice/exception.zep", 77);
							goto zephir_switch_0_end;
						zephir_switch_0_clause_2: ;
							ZEPHIR_INIT_NVAR(&_11$$8);
							ZVAL_STRING(&_11$$8, "NULL");
							zephir_array_append(&node, &_11$$8, PH_SEPARATE, "ice/exception.zep", 80);
							goto zephir_switch_0_end;
						zephir_switch_0_clause_3: ;
							ZEPHIR_INIT_NVAR(&_12$$9);
							if (zephir_is_true(&arg)) {
								ZEPHIR_INIT_NVAR(&_12$$9);
								ZVAL_STRING(&_12$$9, "true");
							} else {
								ZEPHIR_INIT_NVAR(&_12$$9);
								ZVAL_STRING(&_12$$9, "false");
							}
							zephir_array_append(&node, &_12$$9, PH_SEPARATE, "ice/exception.zep", 83);
							goto zephir_switch_0_end;
						zephir_switch_0_clause_4: ;
							ZEPHIR_INIT_NVAR(&_13$$10);
							zephir_get_class(&_13$$10, &arg, 0);
							ZEPHIR_INIT_NVAR(&_14$$10);
							ZEPHIR_CONCAT_SVS(&_14$$10, "Object(", &_13$$10, ")");
							zephir_array_append(&node, &_14$$10, PH_SEPARATE, "ice/exception.zep", 86);
							goto zephir_switch_0_end;
						zephir_switch_0_clause_5: ;
							zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 89);
							goto zephir_switch_0_end;
						zephir_switch_0_clause_6: ;
							zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 92);
							goto zephir_switch_0_end;
						zephir_switch_0_end: ;

					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _5$$4, "rewind", NULL, 0);
					zephir_check_call_status();
					_16$$4 = 1;
					while (1) {
						if (_16$$4) {
							_16$$4 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _5$$4, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_15$$4, _5$$4, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_15$$4)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&arg, _5$$4, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_17$$13);
							zephir_gettype(&_17$$13, &arg);
							if (ZEPHIR_IS_STRING(&_17$$13, "string")) { goto zephir_switch_1_clause_0; }
							if (ZEPHIR_IS_STRING(&_17$$13, "array")) { goto zephir_switch_1_clause_1; }
							if (ZEPHIR_IS_STRING(&_17$$13, "NULL")) { goto zephir_switch_1_clause_2; }
							if (ZEPHIR_IS_STRING(&_17$$13, "boolean")) { goto zephir_switch_1_clause_3; }
							if (ZEPHIR_IS_STRING(&_17$$13, "object")) { goto zephir_switch_1_clause_4; }
							if (ZEPHIR_IS_STRING(&_17$$13, "resource")) { goto zephir_switch_1_clause_5; }
							goto zephir_switch_1_clause_6;
							zephir_switch_1_clause_0: ;
								ZEPHIR_INIT_NVAR(&_18$$14);
								ZEPHIR_CONCAT_SVS(&_18$$14, "'", &arg, "'");
								zephir_array_append(&node, &_18$$14, PH_SEPARATE, "ice/exception.zep", 74);
								goto zephir_switch_1_end;
							zephir_switch_1_clause_1: ;
								ZEPHIR_INIT_NVAR(&_19$$15);
								ZVAL_STRING(&_19$$15, "Array");
								zephir_array_append(&node, &_19$$15, PH_SEPARATE, "ice/exception.zep", 77);
								goto zephir_switch_1_end;
							zephir_switch_1_clause_2: ;
								ZEPHIR_INIT_NVAR(&_20$$16);
								ZVAL_STRING(&_20$$16, "NULL");
								zephir_array_append(&node, &_20$$16, PH_SEPARATE, "ice/exception.zep", 80);
								goto zephir_switch_1_end;
							zephir_switch_1_clause_3: ;
								ZEPHIR_INIT_NVAR(&_21$$17);
								if (zephir_is_true(&arg)) {
									ZEPHIR_INIT_NVAR(&_21$$17);
									ZVAL_STRING(&_21$$17, "true");
								} else {
									ZEPHIR_INIT_NVAR(&_21$$17);
									ZVAL_STRING(&_21$$17, "false");
								}
								zephir_array_append(&node, &_21$$17, PH_SEPARATE, "ice/exception.zep", 83);
								goto zephir_switch_1_end;
							zephir_switch_1_clause_4: ;
								ZEPHIR_INIT_NVAR(&_22$$18);
								zephir_get_class(&_22$$18, &arg, 0);
								ZEPHIR_INIT_NVAR(&_23$$18);
								ZEPHIR_CONCAT_SVS(&_23$$18, "Object(", &_22$$18, ")");
								zephir_array_append(&node, &_23$$18, PH_SEPARATE, "ice/exception.zep", 86);
								goto zephir_switch_1_end;
							zephir_switch_1_clause_5: ;
								zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 89);
								goto zephir_switch_1_end;
							zephir_switch_1_clause_6: ;
								zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 92);
								goto zephir_switch_1_end;
							zephir_switch_1_end: ;

					}
				}
				ZEPHIR_INIT_NVAR(&arg);
				ZEPHIR_INIT_NVAR(&args);
				zephir_fast_join_str(&args, SL(", "), &node);
			}
			ZEPHIR_INIT_NVAR(&_24$$3);
			if (zephir_array_isset_value_string(&frame, SL("file"))) {
				ZEPHIR_OBS_NVAR(&_25$$3);
				zephir_array_fetch_string(&_25$$3, &frame, SL("file"), PH_NOISY, "ice/exception.zep", 102);
				ZEPHIR_OBS_NVAR(&_26$$3);
				zephir_array_fetch_string(&_26$$3, &frame, SL("line"), PH_NOISY, "ice/exception.zep", 102);
				ZEPHIR_INIT_NVAR(&_24$$3);
				ZEPHIR_CONCAT_VSVS(&_24$$3, &_25$$3, "(", &_26$$3, ")");
			} else {
				ZEPHIR_INIT_NVAR(&_24$$3);
				ZVAL_STRING(&_24$$3, "[internal function]");
			}
			ZEPHIR_INIT_NVAR(&_27$$3);
			if (zephir_array_isset_value_string(&frame, SL("class"))) {
				ZEPHIR_OBS_NVAR(&_28$$3);
				zephir_array_fetch_string(&_28$$3, &frame, SL("class"), PH_NOISY, "ice/exception.zep", 103);
				ZEPHIR_OBS_NVAR(&_29$$3);
				zephir_array_fetch_string(&_29$$3, &frame, SL("type"), PH_NOISY, "ice/exception.zep", 103);
				ZEPHIR_OBS_NVAR(&_30$$3);
				zephir_array_fetch_string(&_30$$3, &frame, SL("function"), PH_NOISY, "ice/exception.zep", 103);
				ZEPHIR_INIT_NVAR(&_27$$3);
				ZEPHIR_CONCAT_VVV(&_27$$3, &_28$$3, &_29$$3, &_30$$3);
			} else {
				ZEPHIR_OBS_NVAR(&_27$$3);
				zephir_array_fetch_string(&_27$$3, &frame, SL("function"), PH_NOISY, "ice/exception.zep", 103);
			}
			ZEPHIR_INIT_NVAR(&_31$$3);
			ZVAL_STRING(&_31$$3, "#%s %s: %s(%s)\n");
			ZVAL_LONG(&_32$$3, count);
			ZEPHIR_CALL_FUNCTION(&_33$$3, "sprintf", &_34, 12, &_31$$3, &_32$$3, &_24$$3, &_27$$3, &args);
			zephir_check_call_status();
			zephir_concat_self(&output, &_33$$3);
			count++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_36 = 1;
		while (1) {
			if (_36) {
				_36 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_35, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_35)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&frame, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&args);
				ZVAL_STRING(&args, "");
				if (zephir_array_isset_value_string(&frame, SL("args"))) {
					ZEPHIR_INIT_NVAR(&node);
					array_init(&node);
					ZEPHIR_OBS_NVAR(&_37$$22);
					zephir_array_fetch_string(&_37$$22, &frame, SL("args"), PH_NOISY, "ice/exception.zep", 71);
					if (Z_TYPE_P(&_37$$22) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_39$$22);
						zephir_string_to_char_array(&_39$$22, &_37$$22);
						_38$$22 = &_39$$22;
					} else {
						_38$$22 = &_37$$22;
					}
					zephir_is_iterable(_38$$22, 0, "ice/exception.zep", 96);
					if (Z_TYPE_P(_38$$22) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_38$$22), _40$$22)
						{
							ZEPHIR_INIT_NVAR(&arg);
							ZVAL_COPY(&arg, _40$$22);
							ZEPHIR_INIT_NVAR(&_41$$23);
							zephir_gettype(&_41$$23, &arg);
							if (ZEPHIR_IS_STRING(&_41$$23, "string")) { goto zephir_switch_2_clause_0; }
							if (ZEPHIR_IS_STRING(&_41$$23, "array")) { goto zephir_switch_2_clause_1; }
							if (ZEPHIR_IS_STRING(&_41$$23, "NULL")) { goto zephir_switch_2_clause_2; }
							if (ZEPHIR_IS_STRING(&_41$$23, "boolean")) { goto zephir_switch_2_clause_3; }
							if (ZEPHIR_IS_STRING(&_41$$23, "object")) { goto zephir_switch_2_clause_4; }
							if (ZEPHIR_IS_STRING(&_41$$23, "resource")) { goto zephir_switch_2_clause_5; }
							goto zephir_switch_2_clause_6;
							zephir_switch_2_clause_0: ;
								ZEPHIR_INIT_NVAR(&_42$$24);
								ZEPHIR_CONCAT_SVS(&_42$$24, "'", &arg, "'");
								zephir_array_append(&node, &_42$$24, PH_SEPARATE, "ice/exception.zep", 74);
								goto zephir_switch_2_end;
							zephir_switch_2_clause_1: ;
								ZEPHIR_INIT_NVAR(&_43$$25);
								ZVAL_STRING(&_43$$25, "Array");
								zephir_array_append(&node, &_43$$25, PH_SEPARATE, "ice/exception.zep", 77);
								goto zephir_switch_2_end;
							zephir_switch_2_clause_2: ;
								ZEPHIR_INIT_NVAR(&_44$$26);
								ZVAL_STRING(&_44$$26, "NULL");
								zephir_array_append(&node, &_44$$26, PH_SEPARATE, "ice/exception.zep", 80);
								goto zephir_switch_2_end;
							zephir_switch_2_clause_3: ;
								ZEPHIR_INIT_NVAR(&_45$$27);
								if (zephir_is_true(&arg)) {
									ZEPHIR_INIT_NVAR(&_45$$27);
									ZVAL_STRING(&_45$$27, "true");
								} else {
									ZEPHIR_INIT_NVAR(&_45$$27);
									ZVAL_STRING(&_45$$27, "false");
								}
								zephir_array_append(&node, &_45$$27, PH_SEPARATE, "ice/exception.zep", 83);
								goto zephir_switch_2_end;
							zephir_switch_2_clause_4: ;
								ZEPHIR_INIT_NVAR(&_46$$28);
								zephir_get_class(&_46$$28, &arg, 0);
								ZEPHIR_INIT_NVAR(&_47$$28);
								ZEPHIR_CONCAT_SVS(&_47$$28, "Object(", &_46$$28, ")");
								zephir_array_append(&node, &_47$$28, PH_SEPARATE, "ice/exception.zep", 86);
								goto zephir_switch_2_end;
							zephir_switch_2_clause_5: ;
								zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 89);
								goto zephir_switch_2_end;
							zephir_switch_2_clause_6: ;
								zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 92);
								goto zephir_switch_2_end;
							zephir_switch_2_end: ;

						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _38$$22, "rewind", NULL, 0);
						zephir_check_call_status();
						_49$$22 = 1;
						while (1) {
							if (_49$$22) {
								_49$$22 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _38$$22, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_48$$22, _38$$22, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_48$$22)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&arg, _38$$22, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_50$$31);
								zephir_gettype(&_50$$31, &arg);
								if (ZEPHIR_IS_STRING(&_50$$31, "string")) { goto zephir_switch_3_clause_0; }
								if (ZEPHIR_IS_STRING(&_50$$31, "array")) { goto zephir_switch_3_clause_1; }
								if (ZEPHIR_IS_STRING(&_50$$31, "NULL")) { goto zephir_switch_3_clause_2; }
								if (ZEPHIR_IS_STRING(&_50$$31, "boolean")) { goto zephir_switch_3_clause_3; }
								if (ZEPHIR_IS_STRING(&_50$$31, "object")) { goto zephir_switch_3_clause_4; }
								if (ZEPHIR_IS_STRING(&_50$$31, "resource")) { goto zephir_switch_3_clause_5; }
								goto zephir_switch_3_clause_6;
								zephir_switch_3_clause_0: ;
									ZEPHIR_INIT_NVAR(&_51$$32);
									ZEPHIR_CONCAT_SVS(&_51$$32, "'", &arg, "'");
									zephir_array_append(&node, &_51$$32, PH_SEPARATE, "ice/exception.zep", 74);
									goto zephir_switch_3_end;
								zephir_switch_3_clause_1: ;
									ZEPHIR_INIT_NVAR(&_52$$33);
									ZVAL_STRING(&_52$$33, "Array");
									zephir_array_append(&node, &_52$$33, PH_SEPARATE, "ice/exception.zep", 77);
									goto zephir_switch_3_end;
								zephir_switch_3_clause_2: ;
									ZEPHIR_INIT_NVAR(&_53$$34);
									ZVAL_STRING(&_53$$34, "NULL");
									zephir_array_append(&node, &_53$$34, PH_SEPARATE, "ice/exception.zep", 80);
									goto zephir_switch_3_end;
								zephir_switch_3_clause_3: ;
									ZEPHIR_INIT_NVAR(&_54$$35);
									if (zephir_is_true(&arg)) {
										ZEPHIR_INIT_NVAR(&_54$$35);
										ZVAL_STRING(&_54$$35, "true");
									} else {
										ZEPHIR_INIT_NVAR(&_54$$35);
										ZVAL_STRING(&_54$$35, "false");
									}
									zephir_array_append(&node, &_54$$35, PH_SEPARATE, "ice/exception.zep", 83);
									goto zephir_switch_3_end;
								zephir_switch_3_clause_4: ;
									ZEPHIR_INIT_NVAR(&_55$$36);
									zephir_get_class(&_55$$36, &arg, 0);
									ZEPHIR_INIT_NVAR(&_56$$36);
									ZEPHIR_CONCAT_SVS(&_56$$36, "Object(", &_55$$36, ")");
									zephir_array_append(&node, &_56$$36, PH_SEPARATE, "ice/exception.zep", 86);
									goto zephir_switch_3_end;
								zephir_switch_3_clause_5: ;
									zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 89);
									goto zephir_switch_3_end;
								zephir_switch_3_clause_6: ;
									zephir_array_append(&node, &arg, PH_SEPARATE, "ice/exception.zep", 92);
									goto zephir_switch_3_end;
								zephir_switch_3_end: ;

						}
					}
					ZEPHIR_INIT_NVAR(&arg);
					ZEPHIR_INIT_NVAR(&args);
					zephir_fast_join_str(&args, SL(", "), &node);
				}
				ZEPHIR_INIT_NVAR(&_57$$21);
				if (zephir_array_isset_value_string(&frame, SL("file"))) {
					ZEPHIR_OBS_NVAR(&_58$$21);
					zephir_array_fetch_string(&_58$$21, &frame, SL("file"), PH_NOISY, "ice/exception.zep", 102);
					ZEPHIR_OBS_NVAR(&_59$$21);
					zephir_array_fetch_string(&_59$$21, &frame, SL("line"), PH_NOISY, "ice/exception.zep", 102);
					ZEPHIR_INIT_NVAR(&_57$$21);
					ZEPHIR_CONCAT_VSVS(&_57$$21, &_58$$21, "(", &_59$$21, ")");
				} else {
					ZEPHIR_INIT_NVAR(&_57$$21);
					ZVAL_STRING(&_57$$21, "[internal function]");
				}
				ZEPHIR_INIT_NVAR(&_60$$21);
				if (zephir_array_isset_value_string(&frame, SL("class"))) {
					ZEPHIR_OBS_NVAR(&_61$$21);
					zephir_array_fetch_string(&_61$$21, &frame, SL("class"), PH_NOISY, "ice/exception.zep", 103);
					ZEPHIR_OBS_NVAR(&_62$$21);
					zephir_array_fetch_string(&_62$$21, &frame, SL("type"), PH_NOISY, "ice/exception.zep", 103);
					ZEPHIR_OBS_NVAR(&_63$$21);
					zephir_array_fetch_string(&_63$$21, &frame, SL("function"), PH_NOISY, "ice/exception.zep", 103);
					ZEPHIR_INIT_NVAR(&_60$$21);
					ZEPHIR_CONCAT_VVV(&_60$$21, &_61$$21, &_62$$21, &_63$$21);
				} else {
					ZEPHIR_OBS_NVAR(&_60$$21);
					zephir_array_fetch_string(&_60$$21, &frame, SL("function"), PH_NOISY, "ice/exception.zep", 103);
				}
				ZEPHIR_INIT_NVAR(&_64$$21);
				ZVAL_STRING(&_64$$21, "#%s %s: %s(%s)\n");
				ZVAL_LONG(&_65$$21, count);
				ZEPHIR_CALL_FUNCTION(&_66$$21, "sprintf", &_34, 12, &_64$$21, &_65$$21, &_57$$21, &_60$$21, &args);
				zephir_check_call_status();
				zephir_concat_self(&output, &_66$$21);
				count++;
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
PHP_METHOD(Ice_Exception, errorHandler)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zend_string *message = NULL, *file = NULL;
	zval *code_param = NULL, message_zv, file_zv, *line_param = NULL, *context_param = NULL, _0, _1$$3, _2$$3, _3$$3, _4$$3;
	zend_long code, line, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&context);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 5)
		Z_PARAM_LONG(code)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(file)
		Z_PARAM_LONG(line)
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	code_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 3) {
		line_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		context_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	if (!file) {
		ZEPHIR_INIT_VAR(&file_zv);
	} else {
		zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	}
	if (!line_param) {
		line = 0;
	} else {
		}
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "error_reporting", NULL, 128);
	zephir_check_call_status();
	if (((int) (zephir_get_numberval(&_0)) & code)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zend_ce_error_exception);
		ZVAL_LONG(&_2$$3, code);
		ZVAL_LONG(&_3$$3, 0);
		ZVAL_LONG(&_4$$3, line);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 129, &message_zv, &_2$$3, &_3$$3, &file_zv, &_4$$3);
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
PHP_METHOD(Ice_Exception, handler)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *e, e_sub, di, response, _0, _2, _4, _3$$3;

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(e)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &e);
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "response");
	ZEPHIR_CALL_METHOD(&response, &di, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	ZEPHIR_CALL_METHOD(NULL, &response, "setbody", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	zephir_array_fast_append(&_1, e);
	zephir_array_fast_append(&_1, &di);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "exception.after.uncaught");
	ZEPHIR_CALL_METHOD(NULL, &di, "applyhook", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &response, "getbody", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&_3$$3, &response, "send", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(&_3$$3, 0);
	} else {
		zephir_throw_exception_debug(e, "ice/exception.zep", 149);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_4, 1);
	zephir_exit(&_4);
	ZEPHIR_MM_RESTORE();
}

/**
 * Catches errors that are not caught by the error handler.
 * E_PARSE, E_ERROR, E_CORE_ERROR, E_USER_ERROR
 *
 * @return  void
 */
PHP_METHOD(Ice_Exception, shutdownHandler)
{
	zval _2;
	zend_bool _0;
	zval e, _1, _3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_FUNCTION(&e, "error_get_last", NULL, 130);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&e) == IS_ARRAY;
	if (_0) {
		zephir_memory_observe(&_1);
		zephir_array_fetch_string(&_1, &e, SL("type"), PH_NOISY, "ice/exception.zep", 166);
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
		ZEPHIR_CALL_FUNCTION(NULL, "ob_get_level", NULL, 131);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "ob_clean", NULL, 132);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, zend_ce_error_exception);
		zephir_memory_observe(&_5$$3);
		zephir_array_fetch_string(&_5$$3, &e, SL("message"), PH_NOISY, "ice/exception.zep", 171);
		zephir_memory_observe(&_6$$3);
		zephir_array_fetch_string(&_6$$3, &e, SL("type"), PH_NOISY, "ice/exception.zep", 171);
		zephir_memory_observe(&_7$$3);
		zephir_array_fetch_string(&_7$$3, &e, SL("file"), PH_NOISY, "ice/exception.zep", 171);
		zephir_memory_observe(&_8$$3);
		zephir_array_fetch_string(&_8$$3, &e, SL("line"), PH_NOISY, "ice/exception.zep", 171);
		ZVAL_LONG(&_9$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 129, &_5$$3, &_6$$3, &_9$$3, &_7$$3, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(NULL, "handler", NULL, 0, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_9$$3, 1);
		zephir_exit(&_9$$3);
	}
	ZEPHIR_MM_RESTORE();
}

