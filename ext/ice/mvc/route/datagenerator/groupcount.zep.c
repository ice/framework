
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
#include "kernel/object.h"
#include "kernel/fcall.h"
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

	zval *_11 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	HashTable *_1;
	HashPosition _0;
	int repeat, i, ZEPHIR_LAST_CALL_STATUS;
	zval *regexToRoutesMap, *routeMap, *regex = NULL, *route = NULL, *regexes, *numGroups = NULL, *numVariables = NULL, **_2, *_3 = NULL, *_4 = NULL, *_6 = NULL, _7 = zval_used_for_init, _8 = zval_used_for_init, *_10 = NULL, *_12 = NULL, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &regexToRoutesMap);



	ZEPHIR_INIT_VAR(routeMap);
	array_init(routeMap);
	ZEPHIR_INIT_VAR(regexes);
	array_init(regexes);
	ZEPHIR_INIT_VAR(numGroups);
	ZVAL_LONG(numGroups, 0);
	zephir_is_iterable(regexToRoutesMap, &_1, &_0, 0, 0, "ice/mvc/route/datagenerator/groupcount.zep", 33);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(regex, _1, _0);
		ZEPHIR_GET_HVALUE(route, _2);
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_property(&_3, route, SL("variables"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(numVariables);
		ZVAL_LONG(numVariables, zephir_fast_count_int(_3 TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_4, "max", &_5, 32, numGroups, numVariables);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(numGroups, _4);
		ZEPHIR_INIT_LNVAR(_6);
		sub_function(_6, numGroups, numVariables TSRMLS_CC);
		repeat = zephir_get_numberval(_6);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_STRING(&_7, "()", 0);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_LONG(&_8, repeat);
		ZEPHIR_CALL_FUNCTION(&_4, "str_repeat", &_9, 68, &_7, &_8);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_10);
		ZEPHIR_CONCAT_VV(_10, regex, _4);
		zephir_array_append(&regexes, _10, PH_SEPARATE, "ice/mvc/route/datagenerator/groupcount.zep", 27);
		i = (zephir_get_numberval(numGroups) + 1);
		ZEPHIR_INIT_NVAR(_11);
		zephir_create_array(_11, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_12);
		zephir_read_property(&_12, route, SL("handler"), PH_NOISY_CC);
		zephir_array_fast_append(_11, _12);
		ZEPHIR_OBS_NVAR(_12);
		zephir_read_property(&_12, route, SL("variables"), PH_NOISY_CC);
		zephir_array_fast_append(_11, _12);
		zephir_array_update_long(&routeMap, i, &_11, PH_COPY | PH_SEPARATE, "ice/mvc/route/datagenerator/groupcount.zep", 29);
		ZEPHIR_SEPARATE(numGroups);
		zephir_increment(numGroups);
	}
	ZEPHIR_INIT_VAR(_13);
	zephir_fast_join_str(_13, SL("|"), regexes TSRMLS_CC);
	ZEPHIR_INIT_VAR(regex);
	ZEPHIR_CONCAT_SVS(regex, "~^(?|", _13, ")$~");
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "utf8_encode", NULL, 115, regex);
	zephir_check_call_status();
	zephir_array_update_string(&return_value, SL("regex"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("routeMap"), &routeMap, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

