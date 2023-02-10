
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_DataGenerator_GroupCount)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\Route\\DataGenerator, GroupCount, ice, mvc_route_datagenerator_groupcount, ice_mvc_route_datagenerator_regex_ce, ice_mvc_route_datagenerator_groupcount_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_GroupCount, getApproxChunkSize)
{
	zval *this_ptr = getThis();



	RETURN_LONG(10);
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_GroupCount, processChunk)
{
	zval _12$$3, _20$$4;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, repeat = 0, i = 0;
	zval *regexToRoutesMap, regexToRoutesMap_sub, routeMap, regex, route, regexes, numGroups, numVariables, *_0, _1, _22, _23, _4$$3, _5$$3, _7$$3, _8$$3, _9$$3, _11$$3, _13$$3, _14$$4, _15$$4, _16$$4, _17$$4, _18$$4, _19$$4, _21$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&regexToRoutesMap_sub);
	ZVAL_UNDEF(&routeMap);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&regexes);
	ZVAL_UNDEF(&numGroups);
	ZVAL_UNDEF(&numVariables);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_20$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(regexToRoutesMap)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &regexToRoutesMap);


	ZEPHIR_INIT_VAR(&routeMap);
	array_init(&routeMap);
	ZEPHIR_INIT_VAR(&regexes);
	array_init(&regexes);
	ZEPHIR_INIT_VAR(&numGroups);
	ZVAL_LONG(&numGroups, 0);
	zephir_is_iterable(regexToRoutesMap, 0, "ice/mvc/route/datagenerator/groupcount.zep", 32);
	if (Z_TYPE_P(regexToRoutesMap) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(regexToRoutesMap), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&regex);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&regex, _3);
			} else {
				ZVAL_LONG(&regex, _2);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _0);
			zephir_read_property(&_4$$3, &route, ZEND_STRL("variables"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&numVariables);
			ZVAL_LONG(&numVariables, zephir_fast_count_int(&_4$$3));
			ZEPHIR_CALL_FUNCTION(&_5$$3, "max", &_6, 50, &numGroups, &numVariables);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&numGroups, &_5$$3);
			ZEPHIR_INIT_NVAR(&_7$$3);
			zephir_sub_function(&_7$$3, &numGroups, &numVariables);
			repeat = zephir_get_numberval(&_7$$3);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "()");
			ZVAL_LONG(&_9$$3, repeat);
			ZEPHIR_CALL_FUNCTION(&_5$$3, "str_repeat", &_10, 94, &_8$$3, &_9$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_11$$3);
			ZEPHIR_CONCAT_VV(&_11$$3, &regex, &_5$$3);
			zephir_array_append(&regexes, &_11$$3, PH_SEPARATE, "ice/mvc/route/datagenerator/groupcount.zep", 26);
			i = (zephir_get_numberval(&numGroups) + 1);
			ZEPHIR_INIT_NVAR(&_12$$3);
			zephir_create_array(&_12$$3, 2, 0);
			ZEPHIR_OBS_NVAR(&_13$$3);
			zephir_read_property(&_13$$3, &route, ZEND_STRL("handler"), PH_NOISY_CC);
			zephir_array_fast_append(&_12$$3, &_13$$3);
			ZEPHIR_OBS_NVAR(&_13$$3);
			zephir_read_property(&_13$$3, &route, ZEND_STRL("variables"), PH_NOISY_CC);
			zephir_array_fast_append(&_12$$3, &_13$$3);
			zephir_array_update_long(&routeMap, i, &_12$$3, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
			ZEPHIR_SEPARATE(&numGroups);
			zephir_increment(&numGroups);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, regexToRoutesMap, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, regexToRoutesMap, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&regex, regexToRoutesMap, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, regexToRoutesMap, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_14$$4, &route, ZEND_STRL("variables"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&numVariables);
				ZVAL_LONG(&numVariables, zephir_fast_count_int(&_14$$4));
				ZEPHIR_CALL_FUNCTION(&_15$$4, "max", &_6, 50, &numGroups, &numVariables);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&numGroups, &_15$$4);
				ZEPHIR_INIT_NVAR(&_16$$4);
				zephir_sub_function(&_16$$4, &numGroups, &numVariables);
				repeat = zephir_get_numberval(&_16$$4);
				ZEPHIR_INIT_NVAR(&_17$$4);
				ZVAL_STRING(&_17$$4, "()");
				ZVAL_LONG(&_18$$4, repeat);
				ZEPHIR_CALL_FUNCTION(&_15$$4, "str_repeat", &_10, 94, &_17$$4, &_18$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$4);
				ZEPHIR_CONCAT_VV(&_19$$4, &regex, &_15$$4);
				zephir_array_append(&regexes, &_19$$4, PH_SEPARATE, "ice/mvc/route/datagenerator/groupcount.zep", 26);
				i = (zephir_get_numberval(&numGroups) + 1);
				ZEPHIR_INIT_NVAR(&_20$$4);
				zephir_create_array(&_20$$4, 2, 0);
				ZEPHIR_OBS_NVAR(&_21$$4);
				zephir_read_property(&_21$$4, &route, ZEND_STRL("handler"), PH_NOISY_CC);
				zephir_array_fast_append(&_20$$4, &_21$$4);
				ZEPHIR_OBS_NVAR(&_21$$4);
				zephir_read_property(&_21$$4, &route, ZEND_STRL("variables"), PH_NOISY_CC);
				zephir_array_fast_append(&_20$$4, &_21$$4);
				zephir_array_update_long(&routeMap, i, &_20$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				ZEPHIR_SEPARATE(&numGroups);
				zephir_increment(&numGroups);
			ZEPHIR_CALL_METHOD(NULL, regexToRoutesMap, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&regex);
	ZEPHIR_INIT_VAR(&_22);
	zephir_fast_join_str(&_22, SL("|"), &regexes);
	ZEPHIR_INIT_NVAR(&regex);
	ZEPHIR_CONCAT_SVS(&regex, "~^(?|", &_22, ")$~");
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_CALL_FUNCTION(&_23, "utf8_encode", NULL, 173, &regex);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("regex"), &_23, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("routeMap"), &routeMap, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

