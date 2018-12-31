
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Websocket_Client) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Cli\\Websocket, Client, ice, cli_websocket_client, ice_cli_websocket_websocket_ce, ice_cli_websocket_client_method_entry, 0);

	zend_declare_property_null(ice_cli_websocket_client_ce, SL("socket"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_websocket_client_ce, SL("message"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_websocket_client_ce, SL("tick"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	HashTable *_20;
	HashPosition _19;
	zval *_5, *_13;
	zend_bool _0, _1, _3;
	zephir_fcall_cache_entry *_17 = NULL, *_39 = NULL, *_42 = NULL, *_44 = NULL, *_55 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *address_param = NULL, *headers = NULL, *addr = NULL, *key = NULL, *name = NULL, *value = NULL, *res = NULL, *data = NULL, *matches = NULL, *_2 = NULL, *_4, *_6 = NULL, *_7, *_8, *_9, *_10 = NULL, *_11, *_12 = NULL, *_14, *_15, *_16 = NULL, *_18 = NULL, **_21, *_23, *_28, *_29, *_30, _31, *_32, _33, *_34, *_35, *_36, *_37, *_38 = NULL, _40, *_41 = NULL, *_43 = NULL, *_22$$5 = NULL, *_24$$6, *_25$$6 = NULL, *_26$$6, *_27$$6, *_45$$9, *_46$$9, *_47$$9, *_48$$9, *_49$$9, *_50$$9 = NULL, _51$$9 = zval_used_for_init, *_52$$9 = NULL, *_53$$9 = NULL, *_54$$9 = NULL;
	zval *address = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &address_param, &headers);

	if (!address_param) {
		ZEPHIR_INIT_VAR(address);
		ZVAL_STRING(address, "ws://127.0.0.1:8080", 1);
	} else {
		zephir_get_strval(address, address_param);
	}
	if (!headers) {
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	} else {
		ZEPHIR_SEPARATE_PARAM(headers);
	}


	ZEPHIR_CALL_FUNCTION(&addr, "parse_url", NULL, 80, address);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_FALSE_IDENTICAL(addr);
	if (!(_0)) {
		_0 = !(zephir_array_isset_string(addr, SS("host")));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = !(zephir_array_isset_string(addr, SS("port")));
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid address", "ice/cli/websocket/client.zep", 36);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_array_isset_string(addr, SS("scheme"));
	if (_3) {
		zephir_array_fetch_string(&_4, addr, SL("scheme"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 40 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		zephir_create_array(_5, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "ssl", 1);
		zephir_array_fast_append(_5, _6);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "tls", 1);
		zephir_array_fast_append(_5, _6);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "wss", 1);
		zephir_array_fast_append(_5, _6);
		_3 = zephir_fast_in_array(_4, _5 TSRMLS_CC);
	}
	if (_3) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "tls://", 1);
	} else {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "", 1);
	}
	zephir_array_fetch_string(&_7, addr, SL("host"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 40 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VV(_8, _2, _7);
	zephir_array_fetch_string(&_9, addr, SL("port"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 42 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_10, "fsockopen", NULL, 81, _8, _9);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("socket"), _10 TSRMLS_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_11)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Could not connect", "ice/cli/websocket/client.zep", 45);
		return;
	}
	ZEPHIR_CALL_METHOD(&key, this_ptr, "generatekey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_13);
	zephir_create_array(_13, 5, 0 TSRMLS_CC);
	zephir_array_fetch_string(&_14, addr, SL("host"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 51 TSRMLS_CC);
	zephir_array_fetch_string(&_15, addr, SL("port"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 51 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_16);
	ZEPHIR_CONCAT_VSV(_16, _14, ":", _15);
	zephir_array_update_string(&_13, SL("Host"), &_16, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_13, SS("Connection"), SL("Upgrade"), 1);
	add_assoc_stringl_ex(_13, SS("Upgrade"), SL("websocket"), 1);
	zephir_array_update_string(&_13, SL("Sec-Websocket-Key"), &key, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_13, SS("Sec-Websocket-Version"), SL("13"), 1);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "normalizeheaders", &_17, 0, _13);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_18, this_ptr, "normalizeheaders", &_17, 0, headers);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(headers);
	zephir_fast_array_merge(headers, &(_12), &(_18) TSRMLS_CC);
	ZEPHIR_OBS_NVAR(key);
	zephir_array_fetch_string(&key, headers, SL("Sec-Websocket-Key"), PH_NOISY, "ice/cli/websocket/client.zep", 60 TSRMLS_CC);
	zephir_is_iterable(headers, &_20, &_19, 1, 0, "ice/cli/websocket/client.zep", 66);
	for (
	  ; zend_hash_get_current_data_ex(_20, (void**) &_21, &_19) == SUCCESS
	  ; zend_hash_move_forward_ex(_20, &_19)
	) {
		ZEPHIR_GET_HMKEY(name, _20, _19);
		ZEPHIR_GET_HVALUE(value, _21);
		ZEPHIR_INIT_LNVAR(_22$$5);
		ZEPHIR_CONCAT_VSV(_22$$5, name, ": ", value);
		zephir_array_update_zval(&headers, name, &_22$$5, PH_COPY | PH_SEPARATE);
	}
	zend_hash_destroy(_20);
	FREE_HASHTABLE(_20);
	zephir_array_fetch_string(&_23, addr, SL("path"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 66 TSRMLS_CC);
	ZEPHIR_INIT_VAR(res);
	if (!(ZEPHIR_IS_EMPTY(_23))) {
		zephir_array_fetch_string(&_24$$6, addr, SL("path"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 67 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_25$$6);
		zephir_array_fetch_string(&_26$$6, addr, SL("query"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 67 TSRMLS_CC);
		if (ZEPHIR_IS_EMPTY(_26$$6)) {
			ZEPHIR_INIT_NVAR(_25$$6);
			ZVAL_STRING(_25$$6, "", 1);
		} else {
			zephir_array_fetch_string(&_27$$6, addr, SL("query"), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 67 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_25$$6);
			ZEPHIR_CONCAT_SV(_25$$6, "?", _27$$6);
		}
		ZEPHIR_CONCAT_VV(res, _24$$6, _25$$6);
	} else {
		ZVAL_STRING(res, "/", 1);
	}
	ZEPHIR_INIT_LNVAR(_16);
	ZEPHIR_CONCAT_SVS(_16, "GET ", res, " HTTP/1.1");
	ZEPHIR_MAKE_REF(headers);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 82, headers, _16);
	ZEPHIR_UNREF(headers);
	zephir_check_call_status();
	_28 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_6);
	zephir_fast_join_str(_6, SL("\r\n"), headers TSRMLS_CC);
	ZEPHIR_INIT_VAR(_29);
	ZEPHIR_CONCAT_VS(_29, _6, "\r\n");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, _28, _29);
	zephir_check_call_status();
	_30 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "receiveclear", NULL, 0, _30);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_31);
	ZVAL_STRING(&_31, "(Sec-Websocket-Accept:\\s*(.*)$)mUi", 0);
	ZEPHIR_INIT_VAR(_32);
	ZEPHIR_SINIT_VAR(_33);
	ZVAL_STRING(&_33, "(Sec-Websocket-Accept:\\s*(.*)$)mUi", 0);
	zephir_preg_match(_32, &_33, data, matches, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_is_true(_32))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Bad response", "ice/cli/websocket/client.zep", 78);
		return;
	}
	ZEPHIR_INIT_VAR(_34);
	zephir_array_fetch_long(&_35, matches, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 81 TSRMLS_CC);
	zephir_fast_trim(_34, _35, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_OBS_VAR(_36);
	zephir_read_static_property_ce(&_36, ice_cli_websocket_client_ce, SL("magic") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_37);
	ZEPHIR_CONCAT_VV(_37, key, _36);
	ZEPHIR_CALL_FUNCTION(&_38, "sha1", &_39, 61, _37);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_40);
	ZVAL_STRING(&_40, "H*", 0);
	ZEPHIR_CALL_FUNCTION(&_41, "pack", &_42, 83, &_40, _38);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_43, "base64_encode", &_44, 15, _41);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(_34, _43)) {
		ZEPHIR_INIT_VAR(_45$$9);
		object_init_ex(_45$$9, ice_exception_ce);
		ZEPHIR_INIT_VAR(_46$$9);
		zephir_array_fetch_long(&_47$$9, matches, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 82 TSRMLS_CC);
		zephir_fast_trim(_46$$9, _47$$9, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_OBS_VAR(_48$$9);
		zephir_read_static_property_ce(&_48$$9, ice_cli_websocket_client_ce, SL("magic") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_49$$9);
		ZEPHIR_CONCAT_VV(_49$$9, key, _48$$9);
		ZEPHIR_CALL_FUNCTION(&_50$$9, "sha1", &_39, 61, _49$$9);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_51$$9);
		ZVAL_STRING(&_51$$9, "H*", 0);
		ZEPHIR_CALL_FUNCTION(&_52$$9, "pack", &_42, 83, &_51$$9, _50$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_53$$9, "base64_encode", &_44, 15, _52$$9);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_51$$9);
		ZVAL_STRING(&_51$$9, "Bad key `%s` `%s`", 0);
		ZEPHIR_CALL_FUNCTION(&_54$$9, "sprintf", NULL, 12, &_51$$9, _46$$9, _53$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _45$$9, "__construct", &_55, 13, _54$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_45$$9, "ice/cli/websocket/client.zep", 82 TSRMLS_CC);
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

	zval *chars = NULL, *key = NULL, *length = NULL, *_0$$3, _1$$3 = zval_used_for_init;
	zend_long ZEPHIR_LAST_CALL_STATUS, i;

	ZEPHIR_MM_GROW();

	i = 0;
	ZEPHIR_INIT_VAR(chars);
	ZVAL_STRING(chars, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"$&/()=[]{}0123456789", 1);
	ZEPHIR_INIT_VAR(key);
	ZVAL_STRING(key, "", 1);
	ZEPHIR_INIT_VAR(length);
	ZVAL_LONG(length, (zephir_fast_strlen_ev(chars) - 1));
	while (1) {
		if (!(i < 16)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_LONG(&_1$$3, 0);
		zephir_array_fetch_long(&_0$$3, chars, zephir_mt_rand(zephir_get_intval(&_1$$3), zephir_get_intval(length) TSRMLS_CC), PH_NOISY | PH_READONLY, "ice/cli/websocket/client.zep", 103 TSRMLS_CC);
		zephir_concat_self(&key, _0$$3 TSRMLS_CC);
		i++;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 15, key);
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

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL, *_14 = NULL;
	zval *headers_param = NULL, *cleaned = NULL, *name = NULL, *value = NULL, **_2, _3$$3 = zval_used_for_init, _4$$3 = zval_used_for_init, *_5$$3 = NULL, _7$$4 = zval_used_for_init, *_8$$4 = NULL, *_9$$5 = NULL, *_11$$5 = NULL, _13$$5 = zval_used_for_init;
	zval *headers = NULL, *_10$$5 = NULL, *_12$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(headers, headers_param);


	ZEPHIR_INIT_VAR(cleaned);
	array_init(cleaned);
	zephir_is_iterable(headers, &_1, &_0, 0, 0, "ice/cli/websocket/client.zep", 137);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_STRING(&_3$$3, "HTTP_", 0);
		ZEPHIR_SINIT_NVAR(_4$$3);
		ZVAL_LONG(&_4$$3, 5);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "strncmp", &_6, 84, name, &_3$$3, &_4$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG_IDENTICAL(_5$$3, 0)) {
			ZEPHIR_SINIT_NVAR(_7$$4);
			ZVAL_LONG(&_7$$4, 5);
			ZEPHIR_INIT_NVAR(_8$$4);
			zephir_substr(_8$$4, name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CPY_WRT(name, _8$$4);
		}
		if (!ZEPHIR_IS_FALSE_IDENTICAL(name)) {
			ZEPHIR_INIT_NVAR(_9$$5);
			ZEPHIR_INIT_NVAR(_10$$5);
			zephir_create_array(_10$$5, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_11$$5);
			ZVAL_STRING(_11$$5, "_", 1);
			zephir_array_fast_append(_10$$5, _11$$5);
			ZEPHIR_INIT_NVAR(_11$$5);
			ZVAL_STRING(_11$$5, "-", 1);
			zephir_array_fast_append(_10$$5, _11$$5);
			ZEPHIR_INIT_NVAR(_11$$5);
			ZVAL_STRING(_11$$5, " ", 1);
			zephir_array_fast_append(_10$$5, _11$$5);
			ZEPHIR_INIT_NVAR(_12$$5);
			zephir_create_array(_12$$5, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_11$$5);
			ZVAL_STRING(_11$$5, " ", 1);
			zephir_array_fast_append(_12$$5, _11$$5);
			ZEPHIR_INIT_NVAR(_11$$5);
			ZVAL_STRING(_11$$5, " ", 1);
			zephir_array_fast_append(_12$$5, _11$$5);
			ZEPHIR_INIT_NVAR(_11$$5);
			ZVAL_STRING(_11$$5, "-", 1);
			zephir_array_fast_append(_12$$5, _11$$5);
			ZEPHIR_INIT_NVAR(_11$$5);
			zephir_fast_strtolower(_11$$5, name);
			zephir_fast_str_replace(&_9$$5, _10$$5, _12$$5, _11$$5 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_13$$5);
			ZVAL_STRING(&_13$$5, "-", 0);
			ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_14, 85, _9$$5, &_13$$5);
			zephir_check_call_status();
			zephir_array_update_zval(&cleaned, name, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(cleaned);

}

/**
 * Send a message to the server.
 *
 * @param string data The data to send
 * @param string opcode The data opcode, defaults to `text`
 * @return boolean Was the send successful
 */
PHP_METHOD(Ice_Cli_Websocket_Client, send) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL, *opcode_param = NULL, *_1, *_2;
	zval *data = NULL, *opcode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &opcode_param);

	zephir_get_strval(data, data_param);
	if (!opcode_param) {
		ZEPHIR_INIT_VAR(opcode);
		ZVAL_STRING(opcode, "text", 1);
	} else {
		zephir_get_strval(opcode, opcode_param);
	}


	_1 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_RETURN_CALL_PARENT(ice_cli_websocket_client_ce, getThis(), "senddata", &_0, 86, _1, data, opcode, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Start listening.
 *
 * @return void
 */
PHP_METHOD(Ice_Cli_Websocket_Client, run) {

	zend_bool _13$$7;
	HashTable *_10$$6;
	HashPosition _9$$6;
	zval *changed = NULL, *write = NULL, *except = NULL, *socket = NULL, *message = NULL, *_0$$4, *_1$$4 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, *_5$$3 = NULL, *_6$$3 = NULL, *_7$$3 = NULL, *_15$$3 = NULL, **_11$$6, *_14$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_8 = NULL, *_12 = NULL, *_16 = NULL, *_17 = NULL;

	ZEPHIR_MM_GROW();

	while (1) {
		if (!(1)) {
			break;
		}
		if (zephir_isset_property(this_ptr, SS("tick") TSRMLS_CC)) {
			_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("tick"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&_1$$4, "call_user_func", &_2, 87, _0$$4, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_1$$4)) {
				break;
			}
		}
		ZEPHIR_INIT_NVAR(changed);
		zephir_create_array(changed, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_3$$3);
		zephir_read_property_this(&_3$$3, this_ptr, SL("socket"), PH_NOISY_CC);
		zephir_array_fast_append(changed, _3$$3);
		ZEPHIR_INIT_NVAR(write);
		array_init(write);
		ZEPHIR_INIT_NVAR(except);
		array_init(except);
		ZEPHIR_INIT_LNVAR(_4$$3);
		if (zephir_isset_property(this_ptr, SS("tick") TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_4$$3);
			ZVAL_LONG(_4$$3, 0);
		} else {
			ZEPHIR_INIT_NVAR(_4$$3);
			ZVAL_NULL(_4$$3);
		}
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_NULL(_5$$3);
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_NULL(_6$$3);
		ZEPHIR_MAKE_REF(changed);
		ZEPHIR_MAKE_REF(_5$$3);
		ZEPHIR_MAKE_REF(_6$$3);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "stream_select", &_8, 88, changed, _5$$3, _6$$3, _4$$3);
		ZEPHIR_UNREF(changed);
		ZEPHIR_UNREF(_5$$3);
		ZEPHIR_UNREF(_6$$3);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(_7$$3, 0)) {
			zephir_is_iterable(changed, &_10$$6, &_9$$6, 0, 0, "ice/cli/websocket/client.zep", 180);
			for (
			  ; zend_hash_get_current_data_ex(_10$$6, (void**) &_11$$6, &_9$$6) == SUCCESS
			  ; zend_hash_move_forward_ex(_10$$6, &_9$$6)
			) {
				ZEPHIR_GET_HVALUE(socket, _11$$6);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "receive", &_12, 0, socket);
				zephir_check_call_status();
				_13$$7 = !ZEPHIR_IS_FALSE_IDENTICAL(message);
				if (_13$$7) {
					_13$$7 = zephir_isset_property(this_ptr, SS("message") TSRMLS_CC);
				}
				if (_13$$7) {
					_14$$8 = zephir_fetch_nproperty_this(this_ptr, SL("message"), PH_NOISY_CC);
					ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_2, 87, _14$$8, message, this_ptr);
					zephir_check_call_status();
				}
			}
		}
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_STRING(_5$$3, "sleep", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_LONG(_6$$3, 5000);
		ZEPHIR_CALL_METHOD(&_15$$3, this_ptr, "getparam", &_16, 0, _5$$3, _6$$3);
		zephir_check_temp_parameter(_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_17, 33, _15$$3);
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

	zval *callback;

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_this(getThis(), SL("message"), callback TSRMLS_CC);
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

	zval *callback;

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_this(getThis(), SL("tick"), callback TSRMLS_CC);
	RETURN_THISW();

}

