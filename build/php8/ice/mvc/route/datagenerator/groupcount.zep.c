
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_DataGenerator_GroupCount)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\Route\\DataGenerator, GroupCount, ice, mvc_route_datagenerator_groupcount, ice_mvc_route_datagenerator_regex_ce, ice_mvc_route_datagenerator_groupcount_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_GroupCount, getApproxChunkSize)
{

	RETURN_LONG(10);
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_GroupCount, processChunk)
{
	zval _13$$3, _23$$4;
	zend_bool _16;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, repeat = 0, i = 0;
	zval *regexToRoutesMap, regexToRoutesMap_sub, routeMap, regex, route, regexes, numGroups, numVariables, *_0, _1, *_2, _15, _25, _5$$3, _6$$3, _8$$3, _9$$3, _10$$3, _12$$3, _14$$3, _17$$4, _18$$4, _19$$4, _20$$4, _21$$4, _22$$4, _24$$4;

	ZVAL_UNDEF(&regexToRoutesMap_sub);
	ZVAL_UNDEF(&routeMap);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&regexes);
	ZVAL_UNDEF(&numGroups);
	ZVAL_UNDEF(&numVariables);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_23$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("variables", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("handler", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(regexToRoutesMap)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &regexToRoutesMap);
	ZEPHIR_INIT_VAR(&routeMap);
	array_init(&routeMap);
	ZEPHIR_INIT_VAR(&regexes);
	array_init(&regexes);
	ZEPHIR_INIT_VAR(&numGroups);
	ZVAL_LONG(&numGroups, 0);
	if (Z_TYPE_P(regexToRoutesMap) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, regexToRoutesMap);
		_0 = &_1;
	} else {
		_0 = regexToRoutesMap;
	}
	zephir_is_iterable(_0, 0, "ice/mvc/route/datagenerator/groupcount.zep", 32);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_0), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&regex);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&regex, _4);
			} else {
				ZVAL_LONG(&regex, _3);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _2);
			zephir_read_property_cached(&_5$$3, &route, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&numVariables);
			ZVAL_LONG(&numVariables, zephir_fast_count_int(&_5$$3));
			ZEPHIR_CALL_FUNCTION(&_6$$3, "max", &_7, 52, &numGroups, &numVariables);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&numGroups, &_6$$3);
			ZEPHIR_INIT_NVAR(&_8$$3);
			zephir_sub_function(&_8$$3, &numGroups, &numVariables);
			repeat = zephir_get_numberval(&_8$$3);
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "()");
			ZVAL_LONG(&_10$$3, repeat);
			ZEPHIR_CALL_FUNCTION(&_6$$3, "str_repeat", &_11, 96, &_9$$3, &_10$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$3);
			ZEPHIR_CONCAT_VV(&_12$$3, &regex, &_6$$3);
			zephir_array_append(&regexes, &_12$$3, PH_SEPARATE, "ice/mvc/route/datagenerator/groupcount.zep", 26);
			i = (zephir_get_numberval(&numGroups) + 1);
			ZEPHIR_INIT_NVAR(&_13$$3);
			zephir_create_array(&_13$$3, 2, 0);
			ZEPHIR_OBS_NVAR(&_14$$3);
			zephir_read_property_cached(&_14$$3, &route, _zephir_prop_1, 0, PH_NOISY_CC);
			zephir_array_fast_append(&_13$$3, &_14$$3);
			ZEPHIR_OBS_NVAR(&_14$$3);
			zephir_read_property_cached(&_14$$3, &route, _zephir_prop_0, 0, PH_NOISY_CC);
			zephir_array_fast_append(&_13$$3, &_14$$3);
			zephir_array_update_long(&routeMap, i, &_13$$3, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
			SEPARATE_ZVAL(&numGroups);
			zephir_increment(&numGroups);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _0, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, _0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&regex, _0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, _0, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property_cached(&_17$$4, &route, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&numVariables);
				ZVAL_LONG(&numVariables, zephir_fast_count_int(&_17$$4));
				ZEPHIR_CALL_FUNCTION(&_18$$4, "max", &_7, 52, &numGroups, &numVariables);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&numGroups, &_18$$4);
				ZEPHIR_INIT_NVAR(&_19$$4);
				zephir_sub_function(&_19$$4, &numGroups, &numVariables);
				repeat = zephir_get_numberval(&_19$$4);
				ZEPHIR_INIT_NVAR(&_20$$4);
				ZVAL_STRING(&_20$$4, "()");
				ZVAL_LONG(&_21$$4, repeat);
				ZEPHIR_CALL_FUNCTION(&_18$$4, "str_repeat", &_11, 96, &_20$$4, &_21$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$4);
				ZEPHIR_CONCAT_VV(&_22$$4, &regex, &_18$$4);
				zephir_array_append(&regexes, &_22$$4, PH_SEPARATE, "ice/mvc/route/datagenerator/groupcount.zep", 26);
				i = (zephir_get_numberval(&numGroups) + 1);
				ZEPHIR_INIT_NVAR(&_23$$4);
				zephir_create_array(&_23$$4, 2, 0);
				ZEPHIR_OBS_NVAR(&_24$$4);
				zephir_read_property_cached(&_24$$4, &route, _zephir_prop_1, 0, PH_NOISY_CC);
				zephir_array_fast_append(&_23$$4, &_24$$4);
				ZEPHIR_OBS_NVAR(&_24$$4);
				zephir_read_property_cached(&_24$$4, &route, _zephir_prop_0, 0, PH_NOISY_CC);
				zephir_array_fast_append(&_23$$4, &_24$$4);
				zephir_array_update_long(&routeMap, i, &_23$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				SEPARATE_ZVAL(&numGroups);
				zephir_increment(&numGroups);
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&regex);
	ZEPHIR_INIT_VAR(&_25);
	zephir_fast_join_str(&_25, SL("|"), &regexes);
	ZEPHIR_INIT_NVAR(&regex);
	ZEPHIR_CONCAT_SVS(&regex, "~^(?|", &_25, ")$~");
	zephir_create_array(return_value, 2, 0);
	zephir_array_update_string(return_value, SL("regex"), &regex, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("routeMap"), &routeMap, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

