
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/math.h"


/**
 * Websocket client.
 *
 * @package     Ice/Cli
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Websocket_Client) {

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
PHP_METHOD(Ice_Cli_Websocket_Client, connect) {

	zend_string *_22;
	zend_ulong _21;
	zval _5, _13;
	zend_bool _0, _1, _3, _25;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_17 = NULL, *_42 = NULL, *_45 = NULL, *_47 = NULL, *_58 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *address_param = NULL, *headers = NULL, headers_sub, addr, key, name, value, res, data, matches, _2, _4, _6, _7, _8, _9, _10, _11, _12, _14, _15, _16, _18, *_19, _20, _26, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _43, _44, _46, _23$$5, _24$$6, _27$$7, _28$$7, _29$$7, _30$$7, _48$$10, _49$$10, _50$$10, _51$$10, _52$$10, _53$$10, _54$$10, _55$$10, _56$$10, _57$$10;
	zval address;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&address);
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
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_31);
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
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_48$$10);
	ZVAL_UNDEF(&_49$$10);
	ZVAL_UNDEF(&_50$$10);
	ZVAL_UNDEF(&_51$$10);
	ZVAL_UNDEF(&_52$$10);
	ZVAL_UNDEF(&_53$$10);
	ZVAL_UNDEF(&_54$$10);
	ZVAL_UNDEF(&_55$$10);
	ZVAL_UNDEF(&_56$$10);
	ZVAL_UNDEF(&_57$$10);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_13);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(address)
		Z_PARAM_ZVAL(headers)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &address_param, &headers);

	if (!address_param) {
		ZEPHIR_INIT_VAR(&address);
		ZVAL_STRING(&address, "ws://127.0.0.1:8080");
	} else {
		zephir_get_strval(&address, address_param);
	}
	if (!headers) {
		headers = &headers_sub;
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	} else {
		ZEPHIR_SEPARATE_PARAM(headers);
	}


	ZEPHIR_CALL_FUNCTION(&addr, "parse_url", NULL, 78, &address);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_FALSE_IDENTICAL(&addr);
	if (!(_0)) {
		_0 = !(zephir_array_isset_string(&addr, SL("host")));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = !(zephir_array_isset_string(&addr, SL("port")));
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid address", "ice/cli/websocket/client.zep", 35);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	_3 = zephir_array_isset_string(&addr, SL("scheme"));
	if (_3) {
		zephir_array_fetch_string(&_4, &addr, SL("scheme"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 39);
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
	zephir_array_fetch_string(&_7, &addr, SL("host"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 39);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_VV(&_8, &_2, &_7);
	zephir_array_fetch_string(&_9, &addr, SL("port"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 41);
	ZEPHIR_CALL_FUNCTION(&_10, "fsockopen", NULL, 79, &_8, &_9);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("socket"), &_10);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("socket"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_11)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Could not connect", "ice/cli/websocket/client.zep", 44);
		return;
	}
	ZEPHIR_CALL_METHOD(&key, this_ptr, "generatekey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 5, 0);
	zephir_array_fetch_string(&_14, &addr, SL("host"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 50);
	zephir_array_fetch_string(&_15, &addr, SL("port"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 50);
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
	zephir_is_iterable(headers, 1, "ice/cli/websocket/client.zep", 65);
	if (Z_TYPE_P(headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(headers), _21, _22, _19)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_22 != NULL) { 
				ZVAL_STR_COPY(&name, _22);
			} else {
				ZVAL_LONG(&name, _21);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _19);
			ZEPHIR_INIT_NVAR(&_23$$5);
			ZEPHIR_CONCAT_VSV(&_23$$5, &name, ": ", &value);
			zephir_array_update_zval(headers, &name, &_23$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_20, headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_20)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_24$$6);
				ZEPHIR_CONCAT_VSV(&_24$$6, &name, ": ", &value);
				zephir_array_update_zval(headers, &name, &_24$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	_25 = zephir_array_isset_string(&addr, SL("path"));
	if (_25) {
		zephir_array_fetch_string(&_26, &addr, SL("path"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 65);
		_25 = ((zephir_fast_strlen_ev(&_26)) ? 1 : 0);
	}
	ZEPHIR_INIT_VAR(&res);
	if (_25) {
		zephir_array_fetch_string(&_27$$7, &addr, SL("path"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 66);
		ZEPHIR_INIT_VAR(&_28$$7);
		zephir_array_fetch_string(&_29$$7, &addr, SL("query"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 66);
		if (ZEPHIR_IS_EMPTY(&_29$$7)) {
			ZEPHIR_INIT_NVAR(&_28$$7);
			ZVAL_STRING(&_28$$7, "");
		} else {
			zephir_array_fetch_string(&_30$$7, &addr, SL("query"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 66);
			ZEPHIR_INIT_NVAR(&_28$$7);
			ZEPHIR_CONCAT_SV(&_28$$7, "?", &_30$$7);
		}
		ZEPHIR_CONCAT_VV(&res, &_27$$7, &_28$$7);
	} else {
		ZVAL_STRING(&res, "/");
	}
	ZEPHIR_INIT_NVAR(&_16);
	ZEPHIR_CONCAT_SVS(&_16, "GET ", &res, " HTTP/1.1");
	ZEPHIR_MAKE_REF(headers);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 80, headers, &_16);
	ZEPHIR_UNREF(headers);
	zephir_check_call_status();
	zephir_read_property(&_31, this_ptr, ZEND_STRL("socket"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_6);
	zephir_fast_join_str(&_6, SL("\r\n"), headers);
	ZEPHIR_INIT_VAR(&_32);
	ZEPHIR_CONCAT_VS(&_32, &_6, "\r\n");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, &_31, &_32);
	zephir_check_call_status();
	zephir_read_property(&_33, this_ptr, ZEND_STRL("socket"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "receiveclear", NULL, 0, &_33);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_34);
	ZVAL_STRING(&_34, "(Sec-Websocket-Accept:\\s*(.*)$)mUi");
	ZEPHIR_INIT_VAR(&_35);
	ZEPHIR_INIT_VAR(&_36);
	ZVAL_STRING(&_36, "(Sec-Websocket-Accept:\\s*(.*)$)mUi");
	zephir_preg_match(&_35, &_36, &data, &matches, 0, 0 , 0 );
	if (!(zephir_is_true(&_35))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Bad response", "ice/cli/websocket/client.zep", 77);
		return;
	}
	ZEPHIR_INIT_VAR(&_37);
	zephir_array_fetch_long(&_38, &matches, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 80);
	zephir_fast_trim(&_37, &_38, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_OBS_VAR(&_39);
	zephir_read_static_property_ce(&_39, ice_cli_websocket_client_ce, SL("magic"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_40);
	ZEPHIR_CONCAT_VV(&_40, &key, &_39);
	ZEPHIR_CALL_FUNCTION(&_41, "sha1", &_42, 66, &_40);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_43);
	ZVAL_STRING(&_43, "H*");
	ZEPHIR_CALL_FUNCTION(&_44, "pack", &_45, 81, &_43, &_41);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_46, "base64_encode", &_47, 14, &_44);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_37, &_46)) {
		ZEPHIR_INIT_VAR(&_48$$10);
		object_init_ex(&_48$$10, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_49$$10);
		zephir_array_fetch_long(&_50$$10, &matches, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 81);
		zephir_fast_trim(&_49$$10, &_50$$10, NULL , ZEPHIR_TRIM_BOTH);
		ZEPHIR_OBS_VAR(&_51$$10);
		zephir_read_static_property_ce(&_51$$10, ice_cli_websocket_client_ce, SL("magic"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_52$$10);
		ZEPHIR_CONCAT_VV(&_52$$10, &key, &_51$$10);
		ZEPHIR_CALL_FUNCTION(&_53$$10, "sha1", &_42, 66, &_52$$10);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_54$$10);
		ZVAL_STRING(&_54$$10, "H*");
		ZEPHIR_CALL_FUNCTION(&_55$$10, "pack", &_45, 81, &_54$$10, &_53$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_56$$10, "base64_encode", &_47, 14, &_55$$10);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_54$$10);
		ZVAL_STRING(&_54$$10, "Bad key `%s` `%s`");
		ZEPHIR_CALL_FUNCTION(&_57$$10, "sprintf", NULL, 11, &_54$$10, &_49$$10, &_56$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_48$$10, "__construct", &_58, 12, &_57$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_48$$10, "ice/cli/websocket/client.zep", 81);
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
PHP_METHOD(Ice_Cli_Websocket_Client, generateKey) {

	unsigned char _0$$3;
	zval length, _1$$3;
	zval chars, key;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&chars);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

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
		ZVAL_LONG(&_1$$3, 0);
		_0$$3 = ZEPHIR_STRING_OFFSET(&chars, zephir_mt_rand(zephir_get_intval(&_1$$3), zephir_get_intval(&length)));
		zephir_concat_self_char(&key, _0$$3);
		i++;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 14, &key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Normalize header.
 *
 * @param array headers headers to normalize
 * @return array
 */
PHP_METHOD(Ice_Cli_Websocket_Client, normalizeHeaders) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, cleaned, name, value, *_0, _1, _4$$3, _5$$3, _6$$3, _8$$4, _9$$4, _10$$5, _12$$5, _14$$5, _16$$6, _17$$6, _18$$6, _19$$7, _20$$7, _21$$8, _23$$8, _25$$8;
	zval headers, _11$$5, _13$$5, _22$$8, _24$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&cleaned);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_25$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(headers)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(&headers, headers_param);


	ZEPHIR_INIT_VAR(&cleaned);
	array_init(&cleaned);
	zephir_is_iterable(&headers, 0, "ice/cli/websocket/client.zep", 137);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "HTTP_");
			ZVAL_LONG(&_5$$3, 5);
			ZEPHIR_CALL_FUNCTION(&_6$$3, "strncmp", &_7, 82, &name, &_4$$3, &_5$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_6$$3, 0)) {
				ZVAL_LONG(&_8$$4, 5);
				ZEPHIR_INIT_NVAR(&_9$$4);
				zephir_substr(&_9$$4, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CPY_WRT(&name, &_9$$4);
			}
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&name)) {
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_create_array(&_11$$5, 3, 0);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "_");
				zephir_array_fast_append(&_11$$5, &_12$$5);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "-");
				zephir_array_fast_append(&_11$$5, &_12$$5);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, " ");
				zephir_array_fast_append(&_11$$5, &_12$$5);
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_create_array(&_13$$5, 3, 0);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, " ");
				zephir_array_fast_append(&_13$$5, &_12$$5);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, " ");
				zephir_array_fast_append(&_13$$5, &_12$$5);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "-");
				zephir_array_fast_append(&_13$$5, &_12$$5);
				ZEPHIR_INIT_NVAR(&_12$$5);
				zephir_fast_strtolower(&_12$$5, &name);
				zephir_fast_str_replace(&_10$$5, &_11$$5, &_13$$5, &_12$$5);
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZVAL_STRING(&_14$$5, "-");
				ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_15, 83, &_10$$5, &_14$$5);
				zephir_check_call_status();
				zephir_array_update_zval(&cleaned, &name, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZVAL_STRING(&_16$$6, "HTTP_");
				ZVAL_LONG(&_17$$6, 5);
				ZEPHIR_CALL_FUNCTION(&_18$$6, "strncmp", &_7, 82, &name, &_16$$6, &_17$$6);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_18$$6, 0)) {
					ZVAL_LONG(&_19$$7, 5);
					ZEPHIR_INIT_NVAR(&_20$$7);
					zephir_substr(&_20$$7, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					ZEPHIR_CPY_WRT(&name, &_20$$7);
				}
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&name)) {
					ZEPHIR_INIT_NVAR(&_21$$8);
					ZEPHIR_INIT_NVAR(&_22$$8);
					zephir_create_array(&_22$$8, 3, 0);
					ZEPHIR_INIT_NVAR(&_23$$8);
					ZVAL_STRING(&_23$$8, "_");
					zephir_array_fast_append(&_22$$8, &_23$$8);
					ZEPHIR_INIT_NVAR(&_23$$8);
					ZVAL_STRING(&_23$$8, "-");
					zephir_array_fast_append(&_22$$8, &_23$$8);
					ZEPHIR_INIT_NVAR(&_23$$8);
					ZVAL_STRING(&_23$$8, " ");
					zephir_array_fast_append(&_22$$8, &_23$$8);
					ZEPHIR_INIT_NVAR(&_24$$8);
					zephir_create_array(&_24$$8, 3, 0);
					ZEPHIR_INIT_NVAR(&_23$$8);
					ZVAL_STRING(&_23$$8, " ");
					zephir_array_fast_append(&_24$$8, &_23$$8);
					ZEPHIR_INIT_NVAR(&_23$$8);
					ZVAL_STRING(&_23$$8, " ");
					zephir_array_fast_append(&_24$$8, &_23$$8);
					ZEPHIR_INIT_NVAR(&_23$$8);
					ZVAL_STRING(&_23$$8, "-");
					zephir_array_fast_append(&_24$$8, &_23$$8);
					ZEPHIR_INIT_NVAR(&_23$$8);
					zephir_fast_strtolower(&_23$$8, &name);
					zephir_fast_str_replace(&_21$$8, &_22$$8, &_24$$8, &_23$$8);
					ZEPHIR_INIT_NVAR(&_25$$8);
					ZVAL_STRING(&_25$$8, "-");
					ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_15, 83, &_21$$8, &_25$$8);
					zephir_check_call_status();
					zephir_array_update_zval(&cleaned, &name, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
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
PHP_METHOD(Ice_Cli_Websocket_Client, send) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL, *opcode_param = NULL, _1, _2;
	zval data, opcode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&opcode);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(opcode)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &opcode_param);

	zephir_get_strval(&data, data_param);
	if (!opcode_param) {
		ZEPHIR_INIT_VAR(&opcode);
		ZVAL_STRING(&opcode, "text");
	} else {
		zephir_get_strval(&opcode, opcode_param);
	}


	zephir_read_property(&_1, this_ptr, ZEND_STRL("socket"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_RETURN_CALL_PARENT(ice_cli_websocket_client_ce, getThis(), "senddata", &_0, 0, &_1, &data, &opcode, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Start listening.
 *
 * @return void
 */
PHP_METHOD(Ice_Cli_Websocket_Client, run) {

	zend_bool _12$$7, _14$$9;
	zval changed, write, except, socket, message, _0$$4, _1$$4, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _16$$3, _17$$3, *_9$$6, _10$$6, _13$$8, _15$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_8 = NULL, *_11 = NULL, *_18 = NULL, *_19 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&changed);
	ZVAL_UNDEF(&write);
	ZVAL_UNDEF(&except);
	ZVAL_UNDEF(&socket);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_15$$10);


	ZEPHIR_MM_GROW();

	while (1) {
		if (!(1)) {
			break;
		}
		if (zephir_isset_property(this_ptr, SL("tick"))) {
			zephir_read_property(&_0$$4, this_ptr, ZEND_STRL("tick"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_1$$4, "call_user_func", &_2, 84, &_0$$4, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$4)) {
				break;
			}
		}
		ZEPHIR_INIT_NVAR(&changed);
		zephir_create_array(&changed, 1, 0);
		ZEPHIR_OBS_NVAR(&_3$$3);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("socket"), PH_NOISY_CC);
		zephir_array_fast_append(&changed, &_3$$3);
		ZEPHIR_INIT_NVAR(&write);
		array_init(&write);
		ZEPHIR_INIT_NVAR(&except);
		array_init(&except);
		ZEPHIR_INIT_NVAR(&_4$$3);
		if (zephir_isset_property(this_ptr, SL("tick"))) {
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_LONG(&_4$$3, 0);
		} else {
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_NULL(&_4$$3);
		}
		ZVAL_NULL(&_5$$3);
		ZVAL_NULL(&_6$$3);
		ZEPHIR_MAKE_REF(&changed);
		ZEPHIR_MAKE_REF(&_5$$3);
		ZEPHIR_MAKE_REF(&_6$$3);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "stream_select", &_8, 85, &changed, &_5$$3, &_6$$3, &_4$$3);
		ZEPHIR_UNREF(&changed);
		ZEPHIR_UNREF(&_5$$3);
		ZEPHIR_UNREF(&_6$$3);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&_7$$3, 0)) {
			zephir_is_iterable(&changed, 0, "ice/cli/websocket/client.zep", 180);
			if (Z_TYPE_P(&changed) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&changed), _9$$6)
				{
					ZEPHIR_INIT_NVAR(&socket);
					ZVAL_COPY(&socket, _9$$6);
					ZEPHIR_CALL_METHOD(&message, this_ptr, "receive", &_11, 0, &socket);
					zephir_check_call_status();
					_12$$7 = !ZEPHIR_IS_FALSE_IDENTICAL(&message);
					if (_12$$7) {
						_12$$7 = zephir_isset_property(this_ptr, SL("message"));
					}
					if (_12$$7) {
						zephir_read_property(&_13$$8, this_ptr, ZEND_STRL("message"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_2, 84, &_13$$8, &message, this_ptr);
						zephir_check_call_status();
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &changed, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_10$$6, &changed, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_10$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&socket, &changed, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&message, this_ptr, "receive", &_11, 36, &socket);
						zephir_check_call_status();
						_14$$9 = !ZEPHIR_IS_FALSE_IDENTICAL(&message);
						if (_14$$9) {
							_14$$9 = zephir_isset_property(this_ptr, SL("message"));
						}
						if (_14$$9) {
							zephir_read_property(&_15$$10, this_ptr, ZEND_STRL("message"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_2, 84, &_15$$10, &message, this_ptr);
							zephir_check_call_status();
						}
					ZEPHIR_CALL_METHOD(NULL, &changed, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&socket);
		}
		ZEPHIR_INIT_NVAR(&_17$$3);
		ZVAL_STRING(&_17$$3, "sleep");
		ZVAL_LONG(&_5$$3, 5000);
		ZEPHIR_CALL_METHOD(&_16$$3, this_ptr, "getparam", &_18, 0, &_17$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_19, 32, &_16$$3);
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
PHP_METHOD(Ice_Cli_Websocket_Client, onMessage) {

	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &callback);



	zephir_update_property_zval(this_ptr, ZEND_STRL("message"), callback);
	RETURN_THISW();

}

/**
 * Set a callback to execute every few milliseconds.
 * The callable will receive the server instance. If it returns boolean `false` the client will stop listening.
 *
 * @param callable callback The callback
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Client, onTick) {

	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &callback);



	zephir_update_property_zval(this_ptr, ZEND_STRL("tick"), callback);
	RETURN_THISW();

}

