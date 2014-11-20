
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
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_DataGenerator_GroupCount) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\Route\\DataGenerator, GroupCount, ice, mvc_route_datagenerator_groupcount, ice_mvc_route_datagenerator_regex_ce, ice_mvc_route_datagenerator_groupcount_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_GroupCount, getApproxChunkSize) {


	RETURN_LONG(10);

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_GroupCount, processChunk) {

	zval *_16 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_11 = NULL;
	HashTable *_1, *_14;
	HashPosition _0, _13;
	int repeat, i, ZEPHIR_LAST_CALL_STATUS;
	zval *regexToRoutesMap, *routeMap, *regex = NULL, *regexes, *route = NULL, *routes = NULL, *numGroups = NULL, *numVariables = NULL, **_2, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_8 = NULL, _9 = zval_used_for_init, _10 = zval_used_for_init, *_12 = NULL, **_15, *_17 = NULL, *_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &regexToRoutesMap);



	ZEPHIR_INIT_VAR(routeMap);
	array_init(routeMap);
	ZEPHIR_INIT_VAR(regexes);
	array_init(regexes);
	ZEPHIR_INIT_VAR(numGroups);
	ZVAL_LONG(numGroups, 0);
	zephir_is_iterable(regexToRoutesMap, &_1, &_0, 0, 0, "ice/mvc/route/datagenerator/groupcount.zep", 39);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HKEY(regex, _1, _0);
		ZEPHIR_GET_HVALUE(routes, _2);
		Z_SET_ISREF_P(routes);
		ZEPHIR_CALL_FUNCTION(&_3, "reset", &_4, routes);
		Z_UNSET_ISREF_P(routes);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(_5);
		zephir_read_property(&_5, _3, SL("variables"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(numVariables);
		ZVAL_LONG(numVariables, zephir_fast_count_int(_5 TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_6, "max", &_7, numGroups, numVariables);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(numGroups, _6);
		ZEPHIR_INIT_LNVAR(_8);
		sub_function(_8, numGroups, numVariables TSRMLS_CC);
		repeat = zephir_get_numberval(_8);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "()", 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, repeat);
		ZEPHIR_CALL_FUNCTION(&_6, "str_repeat", &_11, &_9, &_10);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_12);
		ZEPHIR_CONCAT_VV(_12, regex, _6);
		zephir_array_append(&regexes, _12, PH_SEPARATE, "ice/mvc/route/datagenerator/groupcount.zep", 29);
		zephir_is_iterable(routes, &_14, &_13, 0, 0, "ice/mvc/route/datagenerator/groupcount.zep", 36);
		for (
		  ; zephir_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
		  ; zephir_hash_move_forward_ex(_14, &_13)
		) {
			ZEPHIR_GET_HVALUE(route, _15);
			i = (zephir_get_numberval(numGroups) + 1);
			ZEPHIR_INIT_NVAR(_16);
			array_init_size(_16, 3);
			ZEPHIR_OBS_NVAR(_17);
			zephir_read_property(&_17, route, SL("handler"), PH_NOISY_CC);
			zephir_array_fast_append(_16, _17);
			ZEPHIR_OBS_NVAR(_17);
			zephir_read_property(&_17, route, SL("variables"), PH_NOISY_CC);
			zephir_array_fast_append(_16, _17);
			ZEPHIR_OBS_NVAR(_17);
			zephir_read_property(&_17, route, SL("httpMethod"), PH_NOISY_CC);
			zephir_array_update_multi(&routeMap, &_16 TSRMLS_CC, SL("lz"), 2, i, _17);
		}
		ZEPHIR_SEPARATE(numGroups);
		zephir_increment(numGroups);
	}
	ZEPHIR_INIT_VAR(_18);
	zephir_fast_join_str(_18, SL("|"), regexes TSRMLS_CC);
	ZEPHIR_INIT_VAR(regex);
	ZEPHIR_CONCAT_SVS(regex, "~^(?|", _18, ")$~");
	array_init_size(return_value, 3);
	ZEPHIR_CALL_FUNCTION(&_3, "utf8_encode", NULL, regex);
	zephir_check_call_status();
	zephir_array_update_string(&return_value, SL("regex"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("routeMap"), &routeMap, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

