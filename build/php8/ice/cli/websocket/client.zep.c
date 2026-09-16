
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/string.h"


/**
 * Websocket client.
 *
 * @package     Ice/Cli
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Websocket_Client)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Cli\\Websocket, Client, ice, cli_websocket_client, ice_cli_websocket_websocket_ce, ice_cli_websocket_client_method_entry, 0);

	zend_declare_property_null(ice_cli_websocket_client_ce, SL("socket"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_cli_websocket_client_ce, SL("message"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_cli_websocket_client_ce, SL("tick"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Connect to server.
 *
 * @param string address Address to bind to, defaults to `ws://127.0.0.1:8080`
 * @param array headers Optional array of headers to pass when connecting
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Client, connect)
{
	zend_ulong _21;
	zval _5, _13;
	zend_bool _0, _1, _3, _25, _27;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_17 = NULL, *_44 = NULL, *_47 = NULL, *_49 = NULL, *_60 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval address_zv, *headers = NULL, headers_sub, addr, key, name, value, res, data, matches, _2, _4, _6, _7, _8, _9, _10, _11, _12, _14, _15, _16, _18, *_19, *_20, _24, _28, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _45, _46, _48, _23$$5, _26$$6, _29$$7, _30$$7, _31$$7, _50$$10, _51$$10, _52$$10, _53$$10, _54$$10, _55$$10, _56$$10, _57$$10, _58$$10, _59$$10;
	zend_string *address = NULL, *_22;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&address_zv);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&addr);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_50$$10);
	ZVAL_UNDEF(&_51$$10);
	ZVAL_UNDEF(&_52$$10);
	ZVAL_UNDEF(&_53$$10);
	ZVAL_UNDEF(&_54$$10);
	ZVAL_UNDEF(&_55$$10);
	ZVAL_UNDEF(&_56$$10);
	ZVAL_UNDEF(&_57$$10);
	ZVAL_UNDEF(&_58$$10);
	ZVAL_UNDEF(&_59$$10);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_13);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("socket", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(address)
		Z_PARAM_ZVAL(headers)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		headers = ZEND_CALL_ARG(execute_data, 2);
	}
	if (!address) {
		address = zend_string_init(ZEND_STRL("ws://127.0.0.1:8080"), 0);
		zephir_memory_observe(&address_zv);
		ZVAL_STR(&address_zv, address);
	} else {
		zephir_memory_observe(&address_zv);
	ZVAL_STR_COPY(&address_zv, address);
	}
	if (!headers) {
		headers = &headers_sub;
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	} else {
		ZEPHIR_SEPARATE_PARAM(headers);
	}
	ZEPHIR_CALL_FUNCTION(&addr, "parse_url", NULL, 81, &address_zv);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_FALSE_IDENTICAL(&addr);
	if (!(_0)) {
		_0 = !(zephir_array_isset_value_string(&addr, SL("host")));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = !(zephir_array_isset_value_string(&addr, SL("port")));
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid address", "ice/cli/websocket/client.zep", 35);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	_3 = zephir_array_isset_value_string(&addr, SL("scheme"));
	if (_3) {
		zephir_memory_observe(&_4);
		zephir_array_fetch_string(&_4, &addr, SL("scheme"), PH_NOISY, "ice/cli/websocket/client.zep", 39);
		ZEPHIR_INIT_VAR(&_5);
		zephir_create_array(&_5, 3, 0);
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_STRING(&_6, "ssl");
		zephir_array_fast_append(&_5, &_6);
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_STRING(&_6, "tls");
		zephir_array_fast_append(&_5, &_6);
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_STRING(&_6, "wss");
		zephir_array_fast_append(&_5, &_6);
		_3 = zephir_fast_in_array(&_4, &_5);
	}
	if (_3) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "tls://");
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "");
	}
	zephir_memory_observe(&_7);
	zephir_array_fetch_string(&_7, &addr, SL("host"), PH_NOISY, "ice/cli/websocket/client.zep", 39);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_VV(&_8, &_2, &_7);
	zephir_memory_observe(&_9);
	zephir_array_fetch_string(&_9, &addr, SL("port"), PH_NOISY, "ice/cli/websocket/client.zep", 41);
	ZEPHIR_CALL_FUNCTION(&_10, "fsockopen", NULL, 82, &_8, &_9);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 119, &_10);
	zephir_read_property_cached(&_11, this_ptr, _zephir_prop_0, 119, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_11)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Could not connect", "ice/cli/websocket/client.zep", 44);
		return;
	}
	ZEPHIR_CALL_METHOD(&key, this_ptr, "generatekey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 5, 0);
	zephir_memory_observe(&_14);
	zephir_array_fetch_string(&_14, &addr, SL("host"), PH_NOISY, "ice/cli/websocket/client.zep", 50);
	zephir_memory_observe(&_15);
	zephir_array_fetch_string(&_15, &addr, SL("port"), PH_NOISY, "ice/cli/websocket/client.zep", 50);
	ZEPHIR_INIT_VAR(&_16);
	ZEPHIR_CONCAT_VSV(&_16, &_14, ":", &_15);
	zephir_array_update_string(&_13, SL("Host"), &_16, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_13, SL("Connection"), SL("Upgrade"));
	add_assoc_stringl_ex(&_13, SL("Upgrade"), SL("websocket"));
	zephir_array_update_string(&_13, SL("Sec-Websocket-Key"), &key, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_13, SL("Sec-Websocket-Version"), SL("13"));
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "normalizeheaders", &_17, 0, &_13);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_18, this_ptr, "normalizeheaders", &_17, 0, headers);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(headers);
	zephir_fast_array_merge(headers, &_12, &_18);
	ZEPHIR_OBS_NVAR(&key);
	zephir_array_fetch_string(&key, headers, SL("Sec-Websocket-Key"), PH_NOISY, "ice/cli/websocket/client.zep", 59);
	if (Z_TYPE_P(headers) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_6);
		zephir_string_to_char_array(&_6, headers);
		_19 = &_6;
	} else {
		_19 = headers;
	}
	zephir_is_iterable(_19, 0, "ice/cli/websocket/client.zep", 65);
	if (Z_TYPE_P(_19) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_19), _21, _22, _20)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_22 != NULL) { 
				ZVAL_STR_COPY(&name, _22);
			} else {
				ZVAL_LONG(&name, _21);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _20);
			ZEPHIR_INIT_NVAR(&_23$$5);
			ZEPHIR_CONCAT_VSV(&_23$$5, &name, ": ", &value);
			zephir_array_update_zval(headers, &name, &_23$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _19, "rewind", NULL, 0);
		zephir_check_call_status();
		_25 = 1;
		while (1) {
			if (_25) {
				_25 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _19, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_24, _19, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _19, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _19, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_26$$6);
				ZEPHIR_CONCAT_VSV(&_26$$6, &name, ": ", &value);
				zephir_array_update_zval(headers, &name, &_26$$6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	_27 = zephir_array_isset_value_string(&addr, SL("path"));
	if (_27) {
		zephir_memory_observe(&_28);
		zephir_array_fetch_string(&_28, &addr, SL("path"), PH_NOISY, "ice/cli/websocket/client.zep", 65);
		_27 = ((zephir_fast_strlen_ev(&_28)) ? 1 : 0);
	}
	ZEPHIR_INIT_VAR(&res);
	if (_27) {
		zephir_memory_observe(&_29$$7);
		zephir_array_fetch_string(&_29$$7, &addr, SL("path"), PH_NOISY, "ice/cli/websocket/client.zep", 66);
		ZEPHIR_INIT_VAR(&_30$$7);
		if (zephir_isempty_dim_string(&addr, SL("query"))) {
			ZEPHIR_INIT_NVAR(&_30$$7);
			ZVAL_STRING(&_30$$7, "");
		} else {
			zephir_memory_observe(&_31$$7);
			zephir_array_fetch_string(&_31$$7, &addr, SL("query"), PH_NOISY, "ice/cli/websocket/client.zep", 66);
			ZEPHIR_INIT_NVAR(&_30$$7);
			ZEPHIR_CONCAT_SV(&_30$$7, "?", &_31$$7);
		}
		ZEPHIR_CONCAT_VV(&res, &_29$$7, &_30$$7);
	} else {
		ZVAL_STRING(&res, "/");
	}
	ZEPHIR_INIT_NVAR(&_16);
	ZEPHIR_CONCAT_SVS(&_16, "GET ", &res, " HTTP/1.1");
	ZEPHIR_MAKE_REF(headers);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 83, headers, &_16);
	ZEPHIR_UNREF(headers);
	zephir_check_call_status();
	zephir_read_property_cached(&_32, this_ptr, _zephir_prop_0, 119, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_33);
	zephir_fast_join_str(&_33, SL("\r\n"), headers);
	ZEPHIR_INIT_VAR(&_34);
	ZEPHIR_CONCAT_VS(&_34, &_33, "\r\n");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, &_32, &_34);
	zephir_check_call_status();
	zephir_read_property_cached(&_35, this_ptr, _zephir_prop_0, 119, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "receiveclear", NULL, 0, &_35);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_36);
	ZVAL_STRING(&_36, "(Sec-Websocket-Accept:\\s*(.*)$)mUi");
	ZEPHIR_INIT_VAR(&_37);
	ZEPHIR_INIT_VAR(&_38);
	ZVAL_STRING(&_38, "(Sec-Websocket-Accept:\\s*(.*)$)mUi");
	zephir_preg_match(&_37, &_38, &data, &matches, 0, 0 , 0 );
	if (!(zephir_is_true(&_37))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Bad response", "ice/cli/websocket/client.zep", 77);
		return;
	}
	ZEPHIR_INIT_VAR(&_39);
	zephir_memory_observe(&_40);
	zephir_array_fetch_long(&_40, &matches, 1, PH_NOISY, "ice/cli/websocket/client.zep", 80);
	zephir_fast_trim(&_39, &_40, NULL , ZEPHIR_TRIM_BOTH);
	zephir_memory_observe(&_41);
	zephir_read_static_property_ce(&_41, ice_cli_websocket_client_ce, SL("magic"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_42);
	ZEPHIR_CONCAT_VV(&_42, &key, &_41);
	ZEPHIR_CALL_FUNCTION(&_43, "sha1", &_44, 68, &_42);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_45);
	ZVAL_STRING(&_45, "H*");
	ZEPHIR_CALL_FUNCTION(&_46, "pack", &_47, 84, &_45, &_43);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_48, "base64_encode", &_49, 15, &_46);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_39, &_48)) {
		ZEPHIR_INIT_VAR(&_50$$10);
		object_init_ex(&_50$$10, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_51$$10);
		zephir_memory_observe(&_52$$10);
		zephir_array_fetch_long(&_52$$10, &matches, 1, PH_NOISY, "ice/cli/websocket/client.zep", 81);
		zephir_fast_trim(&_51$$10, &_52$$10, NULL , ZEPHIR_TRIM_BOTH);
		zephir_memory_observe(&_53$$10);
		zephir_read_static_property_ce(&_53$$10, ice_cli_websocket_client_ce, SL("magic"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_54$$10);
		ZEPHIR_CONCAT_VV(&_54$$10, &key, &_53$$10);
		ZEPHIR_CALL_FUNCTION(&_55$$10, "sha1", &_44, 68, &_54$$10);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_56$$10);
		ZVAL_STRING(&_56$$10, "H*");
		ZEPHIR_CALL_FUNCTION(&_57$$10, "pack", &_47, 84, &_56$$10, &_55$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_58$$10, "base64_encode", &_49, 15, &_57$$10);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_56$$10);
		ZVAL_STRING(&_56$$10, "Bad key `%s` `%s`");
		ZEPHIR_CALL_FUNCTION(&_59$$10, "sprintf", NULL, 12, &_56$$10, &_51$$10, &_58$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_50$$10, "__construct", &_60, 13, &_59$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_50$$10, "ice/cli/websocket/client.zep", 81);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Generate key.
 *
 * @return string
 */
PHP_METHOD(Ice_Cli_Websocket_Client, generateKey)
{
	unsigned char _2$$3;
	zval length, index, _0$$3, _3$$3;
	zval chars, key;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i;
	zephir_fcall_cache_entry *_1 = NULL;

	ZVAL_UNDEF(&chars);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	i = 0;
	ZEPHIR_INIT_VAR(&chars);
	ZVAL_STRING(&chars, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"$&/()=[]{}0123456789");
	ZEPHIR_INIT_VAR(&key);
	ZVAL_STRING(&key, "");
	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, (zephir_fast_strlen_ev(&chars) - 1));
	while (1) {
		if (!(i < 16)) {
			break;
		}
		ZVAL_LONG(&_0$$3, 0);
		ZEPHIR_CALL_FUNCTION(&index, "mt_rand", &_1, 72, &_0$$3, &length);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_string_offset_read(&_3$$3, &chars, zephir_get_intval(&index), PH_NOISY);
		zephir_concat_self(&key, &_3$$3);
		i++;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 15, &key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Normalize header.
 *
 * @param array headers headers to normalize
 * @return array
 */
PHP_METHOD(Ice_Cli_Websocket_Client, normalizeHeaders)
{
	zend_bool _16;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, cleaned, name, value, *_0, _15, _3$$3, _4$$3, _5$$3, _7$$4, _8$$4, _9$$5, _11$$5, _13$$5, _17$$6, _18$$6, _19$$6, _20$$7, _21$$7, _22$$8, _24$$8, _26$$8;
	zval headers, _10$$5, _12$$5, _23$$8, _25$$8;

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&cleaned);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_26$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(headers, headers_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &headers_param);
	zephir_get_arrval(&headers, headers_param);
	ZEPHIR_INIT_VAR(&cleaned);
	array_init(&cleaned);
	zephir_is_iterable(&headers, 0, "ice/cli/websocket/client.zep", 138);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&name, _2);
			} else {
				ZVAL_LONG(&name, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "HTTP_");
			ZVAL_LONG(&_4$$3, 5);
			ZEPHIR_CALL_FUNCTION(&_5$$3, "strncmp", &_6, 85, &name, &_3$$3, &_4$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_5$$3, 0)) {
				ZVAL_LONG(&_7$$4, 5);
				ZEPHIR_INIT_NVAR(&_8$$4);
				zephir_substr(&_8$$4, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CPY_WRT(&name, &_8$$4);
			}
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&name)) {
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZEPHIR_INIT_NVAR(&_10$$5);
				zephir_create_array(&_10$$5, 3, 0);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "_");
				zephir_array_fast_append(&_10$$5, &_11$$5);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "-");
				zephir_array_fast_append(&_10$$5, &_11$$5);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, " ");
				zephir_array_fast_append(&_10$$5, &_11$$5);
				ZEPHIR_INIT_NVAR(&_12$$5);
				zephir_create_array(&_12$$5, 3, 0);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, " ");
				zephir_array_fast_append(&_12$$5, &_11$$5);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, " ");
				zephir_array_fast_append(&_12$$5, &_11$$5);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "-");
				zephir_array_fast_append(&_12$$5, &_11$$5);
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_fast_strtolower(&_11$$5, &name);
				zephir_fast_str_replace(&_9$$5, &_10$$5, &_12$$5, &_11$$5);
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "-");
				ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_14, 86, &_9$$5, &_13$$5);
				zephir_check_call_status();
				zephir_array_update_zval(&cleaned, &name, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$6);
				ZVAL_STRING(&_17$$6, "HTTP_");
				ZVAL_LONG(&_18$$6, 5);
				ZEPHIR_CALL_FUNCTION(&_19$$6, "strncmp", &_6, 85, &name, &_17$$6, &_18$$6);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_19$$6, 0)) {
					ZVAL_LONG(&_20$$7, 5);
					ZEPHIR_INIT_NVAR(&_21$$7);
					zephir_substr(&_21$$7, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					ZEPHIR_CPY_WRT(&name, &_21$$7);
				}
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&name)) {
					ZEPHIR_INIT_NVAR(&_22$$8);
					ZEPHIR_INIT_NVAR(&_23$$8);
					zephir_create_array(&_23$$8, 3, 0);
					ZEPHIR_INIT_NVAR(&_24$$8);
					ZVAL_STRING(&_24$$8, "_");
					zephir_array_fast_append(&_23$$8, &_24$$8);
					ZEPHIR_INIT_NVAR(&_24$$8);
					ZVAL_STRING(&_24$$8, "-");
					zephir_array_fast_append(&_23$$8, &_24$$8);
					ZEPHIR_INIT_NVAR(&_24$$8);
					ZVAL_STRING(&_24$$8, " ");
					zephir_array_fast_append(&_23$$8, &_24$$8);
					ZEPHIR_INIT_NVAR(&_25$$8);
					zephir_create_array(&_25$$8, 3, 0);
					ZEPHIR_INIT_NVAR(&_24$$8);
					ZVAL_STRING(&_24$$8, " ");
					zephir_array_fast_append(&_25$$8, &_24$$8);
					ZEPHIR_INIT_NVAR(&_24$$8);
					ZVAL_STRING(&_24$$8, " ");
					zephir_array_fast_append(&_25$$8, &_24$$8);
					ZEPHIR_INIT_NVAR(&_24$$8);
					ZVAL_STRING(&_24$$8, "-");
					zephir_array_fast_append(&_25$$8, &_24$$8);
					ZEPHIR_INIT_NVAR(&_24$$8);
					zephir_fast_strtolower(&_24$$8, &name);
					zephir_fast_str_replace(&_22$$8, &_23$$8, &_25$$8, &_24$$8);
					ZEPHIR_INIT_NVAR(&_26$$8);
					ZVAL_STRING(&_26$$8, "-");
					ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_14, 86, &_22$$8, &_26$$8);
					zephir_check_call_status();
					zephir_array_update_zval(&cleaned, &name, &value, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&cleaned);
}

/**
 * Send a message to the server.
 *
 * @param string data The data to send
 * @param string opcode The data opcode, defaults to `text`
 * @return boolean Was the send successful
 */
PHP_METHOD(Ice_Cli_Websocket_Client, send)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data_zv, opcode_zv, _0, _1;
	zend_string *data = NULL, *opcode = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&opcode_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("socket", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(opcode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!opcode) {
		opcode = zend_string_init(ZEND_STRL("text"), 0);
		zephir_memory_observe(&opcode_zv);
		ZVAL_STR(&opcode_zv, opcode);
	} else {
		zephir_memory_observe(&opcode_zv);
	ZVAL_STR_COPY(&opcode_zv, opcode);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 119, PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_RETURN_CALL_PARENT(ice_cli_websocket_client_ce, getThis(), "senddata", NULL, 0, &_0, &data_zv, &opcode_zv, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Start listening.
 *
 * @return void
 */
PHP_METHOD(Ice_Cli_Websocket_Client, run)
{
	zend_bool _14$$6, _12$$7, _15$$9;
	zval changed, write, except, socket, message, tick, onMessage, _0$$3, _3$$3, _4$$3, _5$$3, _6$$3, _16$$3, _17$$3, _1$$4, *_8$$6, _9$$6, *_10$$6, _13$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL, *_11 = NULL, *_18 = NULL, *_19 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&changed);
	ZVAL_UNDEF(&write);
	ZVAL_UNDEF(&except);
	ZVAL_UNDEF(&socket);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&tick);
	ZVAL_UNDEF(&onMessage);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_13$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("tick", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("socket", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("message", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_0$$3);
		static zend_string *_zephir_isset_0 = NULL;
		if (UNEXPECTED(!_zephir_isset_0)) {
			_zephir_isset_0 = zend_string_init("tick", 4, 1);
		}
		if (zephir_isset_property_value_fast(this_ptr, _zephir_isset_0)) {
			ZEPHIR_OBS_NVAR(&_0$$3);
			zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 120, PH_NOISY_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_NULL(&_0$$3);
		}
		ZEPHIR_CPY_WRT(&tick, &_0$$3);
		if (zephir_is_true(&tick)) {
			ZEPHIR_CALL_FUNCTION(&_1$$4, "call_user_func", &_2, 87, &tick, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$4)) {
				break;
			}
		}
		ZEPHIR_INIT_NVAR(&changed);
		zephir_create_array(&changed, 1, 0);
		ZEPHIR_OBS_NVAR(&_3$$3);
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_1, 119, PH_NOISY_CC);
		zephir_array_fast_append(&changed, &_3$$3);
		ZEPHIR_INIT_NVAR(&write);
		array_init(&write);
		ZEPHIR_INIT_NVAR(&except);
		array_init(&except);
		ZEPHIR_INIT_NVAR(&_0$$3);
		if (zephir_is_true(&tick)) {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_LONG(&_0$$3, 0);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_NULL(&_0$$3);
		}
		ZVAL_NULL(&_4$$3);
		ZVAL_NULL(&_5$$3);
		ZEPHIR_MAKE_REF(&changed);
		ZEPHIR_MAKE_REF(&_4$$3);
		ZEPHIR_MAKE_REF(&_5$$3);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "stream_select", &_7, 88, &changed, &_4$$3, &_5$$3, &_0$$3);
		ZEPHIR_UNREF(&changed);
		ZEPHIR_UNREF(&_4$$3);
		ZEPHIR_UNREF(&_5$$3);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&_6$$3, 0)) {
			static zend_string *_zephir_isset_1 = NULL;
			if (UNEXPECTED(!_zephir_isset_1)) {
				_zephir_isset_1 = zend_string_init("message", 7, 1);
			}
			if (zephir_isset_property_value_fast(this_ptr, _zephir_isset_1)) {
				ZEPHIR_OBS_NVAR(&onMessage);
				zephir_read_property_cached(&onMessage, this_ptr, _zephir_prop_2, 121, PH_NOISY_CC);
			} else {
				ZEPHIR_INIT_NVAR(&onMessage);
				ZVAL_NULL(&onMessage);
			}
			if (Z_TYPE_P(&changed) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_9$$6);
				zephir_string_to_char_array(&_9$$6, &changed);
				_8$$6 = &_9$$6;
			} else {
				_8$$6 = &changed;
			}
			zephir_is_iterable(_8$$6, 0, "ice/cli/websocket/client.zep", 185);
			if (Z_TYPE_P(_8$$6) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8$$6), _10$$6)
				{
					ZEPHIR_INIT_NVAR(&socket);
					ZVAL_COPY(&socket, _10$$6);
					ZEPHIR_CALL_METHOD(&message, this_ptr, "receive", &_11, 0, &socket);
					zephir_check_call_status();
					_12$$7 = !ZEPHIR_IS_FALSE_IDENTICAL(&message);
					if (_12$$7) {
						_12$$7 = zephir_is_true(&onMessage);
					}
					if (_12$$7) {
						ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_2, 87, &onMessage, &message, this_ptr);
						zephir_check_call_status();
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _8$$6, "rewind", NULL, 0);
				zephir_check_call_status();
				_14$$6 = 1;
				while (1) {
					if (_14$$6) {
						_14$$6 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _8$$6, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_13$$6, _8$$6, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&socket, _8$$6, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&message, this_ptr, "receive", &_11, 37, &socket);
						zephir_check_call_status();
						_15$$9 = !ZEPHIR_IS_FALSE_IDENTICAL(&message);
						if (_15$$9) {
							_15$$9 = zephir_is_true(&onMessage);
						}
						if (_15$$9) {
							ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_2, 87, &onMessage, &message, this_ptr);
							zephir_check_call_status();
						}
				}
			}
			ZEPHIR_INIT_NVAR(&socket);
		}
		ZEPHIR_INIT_NVAR(&_17$$3);
		ZVAL_STRING(&_17$$3, "sleep");
		ZVAL_LONG(&_4$$3, 5000);
		ZEPHIR_CALL_METHOD(&_16$$3, this_ptr, "getparam", &_18, 0, &_17$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_19, 33, &_16$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Set a callback to execute when a message arrives.
 * The callable will receive the message string and the server instance.
 *
 * @param callable callback The callback
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Client, onMessage)
{
	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("message", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &callback);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 121, callback);
	RETURN_THISW();
}

/**
 * Set a callback to execute every few milliseconds.
 * The callable will receive the server instance. If it returns boolean `false` the client will stop listening.
 *
 * @param callable callback The callback
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Client, onTick)
{
	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("tick", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &callback);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 120, callback);
	RETURN_THISW();
}

