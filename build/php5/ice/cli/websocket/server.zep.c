
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Websocket server.
 *
 * @package     Ice/Cli
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Websocket_Server) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Cli\\Websocket, Server, ice, cli_websocket_server, ice_cli_websocket_websocket_ce, ice_cli_websocket_server_method_entry, 0);

	zend_declare_property_bool(ice_cli_websocket_server_ce, SL("verbose"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_websocket_server_ce, SL("address"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_websocket_server_ce, SL("server"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_websocket_server_ce, SL("sockets"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_websocket_server_ce, SL("clients"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_websocket_server_ce, SL("callbacks"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_cli_websocket_server_ce->create_object = zephir_init_properties_Ice_Cli_Websocket_Server;
	return SUCCESS;

}

PHP_METHOD(Ice_Cli_Websocket_Server, setVerbose) {

	zval *verbose;

	zephir_fetch_params(0, 1, 0, &verbose);



	zephir_update_property_this(getThis(), SL("verbose"), verbose TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cli_Websocket_Server, getServer) {

	

	RETURN_MEMBER(getThis(), "server");

}

PHP_METHOD(Ice_Cli_Websocket_Server, getClients) {

	

	RETURN_MEMBER(getThis(), "clients");

}

/**
 * Create an instance.
 *
 * @param string address Where to create the server, defaults to "ws://127.0.0.1:8080"
 * @param array options Stream context options
 */
PHP_METHOD(Ice_Cli_Websocket_Server, __construct) {

	HashTable *_4$$4;
	HashPosition _3$$4;
	zend_bool _0, _1, _2;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *_10;
	zval *address_param = NULL, *options_param = NULL, *addr = NULL, *context = NULL, *key = NULL, *value = NULL, *_8 = NULL, *_9, *_11 = NULL, *_12, *_13, *_14, *_15, *_16, *_17 = NULL, *_18, **_5$$4, _6$$5 = zval_used_for_init;
	zval *address = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &address_param, &options_param);

	if (!address_param) {
		ZEPHIR_INIT_VAR(address);
		ZVAL_STRING(address, "ws://127.0.0.1:8080", 1);
	} else {
		zephir_get_strval(address, address_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_FUNCTION(&addr, "parse_url", NULL, 80, address);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_FALSE_IDENTICAL(addr);
	if (!(_0)) {
		_0 = !(zephir_array_isset_string(addr, SS("scheme")));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = !(zephir_array_isset_string(addr, SS("host")));
	}
	_2 = _1;
	if (!(_2)) {
		_2 = !(zephir_array_isset_string(addr, SS("port")));
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid address", "ice/cli/websocket/server.zep", 38);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&context, "stream_context_create", NULL, 89);
	zephir_check_call_status();
	if (zephir_fast_count_int(options TSRMLS_CC)) {
		zephir_is_iterable(options, &_4$$4, &_3$$4, 0, 0, "ice/cli/websocket/server.zep", 47);
		for (
		  ; zend_hash_get_current_data_ex(_4$$4, (void**) &_5$$4, &_3$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_4$$4, &_3$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _4$$4, _3$$4);
			ZEPHIR_GET_HVALUE(value, _5$$4);
			ZEPHIR_SINIT_NVAR(_6$$5);
			ZVAL_STRING(&_6$$5, "ssl", 0);
			ZEPHIR_CALL_FUNCTION(NULL, "stream_context_set_option", &_7, 90, context, &_6$$5, key, value);
			zephir_check_call_status();
		}
	}
	zephir_update_property_this(getThis(), SL("address"), address TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	zephir_array_fetch_string(&_9, addr, SL("scheme"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 52 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	zephir_create_array(_10, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_STRING(_11, "wss", 1);
	zephir_array_fast_append(_10, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "tls", 1);
	zephir_array_fast_append(_10, _11);
	if (zephir_fast_in_array(_9, _10 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_STRING(_8, "tls", 1);
	} else {
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_STRING(_8, "tcp", 1);
	}
	zephir_array_fetch_string(&_12, addr, SL("host"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 52 TSRMLS_CC);
	zephir_array_fetch_string(&_13, addr, SL("port"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 52 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_VSVSV(_14, _8, "://", _12, ":", _13);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_NULL(_11);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_NULL(_15);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_LONG(_16, (4 | 8));
	ZEPHIR_MAKE_REF(_11);
	ZEPHIR_MAKE_REF(_15);
	ZEPHIR_CALL_FUNCTION(&_17, "stream_socket_server", NULL, 91, _14, _11, _15, _16, context);
	ZEPHIR_UNREF(_11);
	ZEPHIR_UNREF(_15);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("server"), _17 TSRMLS_CC);
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_18)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Could not create server", "ice/cli/websocket/server.zep", 60);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Start processing requests. This method runs in an infinite loop.
 *
 * @return void
 */
PHP_METHOD(Ice_Cli_Websocket_Server, run) {

	zval *_26$$13 = NULL, *_34$$16 = NULL;
	zend_bool _25$$13;
	HashTable *_12$$7, *_38$$7;
	HashPosition _11$$7, _37$$7;
	zval *changed = NULL, *write = NULL, *except = NULL, *stream = NULL, *messages = NULL, *message = NULL, *socket = NULL, *tmp = NULL, *_0, *_1$$3, *_2$$3, *_4$$4, *_8$$4 = NULL, *_9$$4, *_45$$4 = NULL, *_46$$4 = NULL, *_47$$4 = NULL, *_5$$5, *_6$$5, *_7$$5 = NULL, **_13$$7, **_39$$7, *_14$$8, *_15$$9, *_17$$10 = NULL, *_19$$11, *_20$$12, *_21$$12, *_22$$12, *_23$$12, *_27$$13 = NULL, *_28$$14, *_29$$15, *_30$$15, *_31$$15, *_32$$15, *_35$$16, *_36$$16 = NULL, *_40$$17, *_41$$18, *_42$$18, *_43$$18, *_44$$18;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_10 = NULL, *_16 = NULL, *_18 = NULL, *_24 = NULL, *_33 = NULL, *_48 = NULL, *_49 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	zephir_update_property_array_append(this_ptr, SL("sockets"), _0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
	if (zephir_array_isset_string(_0, SS("boot"))) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
		zephir_array_fetch_string(&_2$$3, _1$$3, SL("boot"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 76 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 87, _2$$3, this_ptr);
		zephir_check_call_status();
	}
	while (1) {
		if (!(1)) {
			break;
		}
		_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
		if (zephir_array_isset_string(_4$$4, SS("tick"))) {
			_5$$5 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
			zephir_array_fetch_string(&_6$$5, _5$$5, SL("tick"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 81 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_7$$5, "call_user_func", &_3, 87, _6$$5, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_7$$5)) {
				break;
			}
		}
		ZEPHIR_OBS_NVAR(changed);
		zephir_read_property_this(&changed, this_ptr, SL("sockets"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(write);
		array_init(write);
		ZEPHIR_INIT_NVAR(except);
		array_init(except);
		ZEPHIR_INIT_LNVAR(_8$$4);
		_9$$4 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
		if (zephir_array_isset_string(_9$$4, SS("tick"))) {
			ZEPHIR_INIT_NVAR(_8$$4);
			ZVAL_LONG(_8$$4, 0);
		} else {
			ZEPHIR_INIT_NVAR(_8$$4);
			ZVAL_NULL(_8$$4);
		}
		ZEPHIR_MAKE_REF(changed);
		ZEPHIR_MAKE_REF(write);
		ZEPHIR_MAKE_REF(except);
		ZEPHIR_CALL_FUNCTION(&stream, "stream_select", &_10, 88, changed, write, except, _8$$4);
		ZEPHIR_UNREF(changed);
		ZEPHIR_UNREF(write);
		ZEPHIR_UNREF(except);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(stream, 0)) {
			ZEPHIR_INIT_NVAR(messages);
			array_init(messages);
			zephir_is_iterable(changed, &_12$$7, &_11$$7, 0, 0, "ice/cli/websocket/server.zep", 123);
			for (
			  ; zend_hash_get_current_data_ex(_12$$7, (void**) &_13$$7, &_11$$7) == SUCCESS
			  ; zend_hash_move_forward_ex(_12$$7, &_11$$7)
			) {
				ZEPHIR_GET_HVALUE(socket, _13$$7);
				_14$$8 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
				if (ZEPHIR_IS_IDENTICAL(socket, _14$$8)) {
					_15$$9 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
					ZEPHIR_CALL_FUNCTION(&tmp, "stream_socket_accept", &_16, 92, _15$$9);
					zephir_check_call_status();
					if (!ZEPHIR_IS_FALSE_IDENTICAL(tmp)) {
						ZEPHIR_CALL_METHOD(&_17$$10, this_ptr, "connect", &_18, 0, tmp);
						zephir_check_call_status();
						if (zephir_is_true(_17$$10)) {
							_19$$11 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
							if (zephir_array_isset_string(_19$$11, SS("connect"))) {
								_20$$12 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
								zephir_array_fetch_string(&_21$$12, _20$$12, SL("connect"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 101 TSRMLS_CC);
								_22$$12 = zephir_fetch_nproperty_this(this_ptr, SL("clients"), PH_NOISY_CC);
								zephir_array_fetch_long(&_23$$12, _22$$12, zephir_get_intval(tmp), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 101 TSRMLS_CC);
								ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 87, _21$$12, _23$$12, this_ptr);
								zephir_check_call_status();
							}
						}
					}
				} else {
					ZEPHIR_CALL_METHOD(&message, this_ptr, "receive", &_24, 0, socket);
					zephir_check_call_status();
					_25$$13 = ZEPHIR_IS_FALSE_IDENTICAL(message);
					if (!(_25$$13)) {
						ZEPHIR_INIT_NVAR(_26$$13);
						zephir_create_array(_26$$13, 3, 0 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(_27$$13);
						ZVAL_STRING(_27$$13, "quit", 1);
						zephir_array_fast_append(_26$$13, _27$$13);
						ZEPHIR_INIT_NVAR(_27$$13);
						ZVAL_STRING(_27$$13, "exit", 1);
						zephir_array_fast_append(_26$$13, _27$$13);
						ZEPHIR_INIT_NVAR(_27$$13);
						ZVAL_STRING(_27$$13, "close", 1);
						zephir_array_fast_append(_26$$13, _27$$13);
						_25$$13 = zephir_fast_in_array(message, _26$$13 TSRMLS_CC);
					}
					if (_25$$13) {
						_28$$14 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
						if (zephir_array_isset_string(_28$$14, SS("disconnect"))) {
							_29$$15 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
							zephir_array_fetch_string(&_30$$15, _29$$15, SL("disconnect"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 110 TSRMLS_CC);
							_31$$15 = zephir_fetch_nproperty_this(this_ptr, SL("clients"), PH_NOISY_CC);
							zephir_array_fetch_long(&_32$$15, _31$$15, zephir_get_intval(socket), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 110 TSRMLS_CC);
							ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 87, _30$$15, _32$$15, this_ptr);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", &_33, 0, socket);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(_34$$16);
						zephir_create_array(_34$$16, 2, 0 TSRMLS_CC);
						_35$$16 = zephir_fetch_nproperty_this(this_ptr, SL("clients"), PH_NOISY_CC);
						ZEPHIR_OBS_NVAR(_36$$16);
						zephir_array_fetch_long(&_36$$16, _35$$16, zephir_get_intval(socket), PH_NOISY, "ice/cli/websocket/server.zep", 116 TSRMLS_CC);
						zephir_array_update_string(&_34$$16, SL("client"), &_36$$16, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_34$$16, SL("message"), &message, PH_COPY | PH_SEPARATE);
						zephir_array_append(&messages, _34$$16, PH_SEPARATE, "ice/cli/websocket/server.zep", 118);
					}
				}
			}
			zephir_is_iterable(messages, &_38$$7, &_37$$7, 0, 0, "ice/cli/websocket/server.zep", 128);
			for (
			  ; zend_hash_get_current_data_ex(_38$$7, (void**) &_39$$7, &_37$$7) == SUCCESS
			  ; zend_hash_move_forward_ex(_38$$7, &_37$$7)
			) {
				ZEPHIR_GET_HVALUE(message, _39$$7);
				_40$$17 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
				if (zephir_array_isset_string(_40$$17, SS("message"))) {
					_41$$18 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
					zephir_array_fetch_string(&_42$$18, _41$$18, SL("message"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125 TSRMLS_CC);
					zephir_array_fetch_string(&_43$$18, message, SL("client"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125 TSRMLS_CC);
					zephir_array_fetch_string(&_44$$18, message, SL("message"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125 TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 87, _42$$18, _43$$18, _44$$18, this_ptr);
					zephir_check_call_status();
				}
			}
		}
		ZEPHIR_INIT_NVAR(_46$$4);
		ZVAL_STRING(_46$$4, "sleep", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_47$$4);
		ZVAL_LONG(_47$$4, 5000);
		ZEPHIR_CALL_METHOD(&_45$$4, this_ptr, "getparam", &_48, 0, _46$$4, _47$$4);
		zephir_check_temp_parameter(_46$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_49, 33, _45$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Connect a socket to the server.
 *
 * @param resource socket The resource
 * @return boolean
 */
PHP_METHOD(Ice_Cli_Websocket_Server, connect) {

	zend_bool _17, _18, _19, _21, _40, _32$$8;
	HashTable *_10, *_29$$7;
	HashPosition _9, _28$$7;
	zval *_1, *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *socket, *headers = NULL, *header = NULL, *request = NULL, *tmp = NULL, *cookies = NULL, *value = NULL, *client = NULL, *response = NULL, *_0 = NULL, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7, **_11, *_20, *_22, *_23, _24, *_25, *_38, *_39, *_41, *_42, *_43 = NULL, *_45 = NULL, *_46, *_47 = NULL, *_48, *_49, *_50 = NULL, *_51 = NULL, *_52 = NULL, *_55, *_56, *_8$$4, *_12$$5 = NULL, *_13$$5, *_14$$5 = NULL, *_15$$5 = NULL, *_16$$5, *_26$$6, *_27$$7, **_30$$7, *_31$$8 = NULL, _33$$8 = zval_used_for_init, *_34$$8 = NULL, *_35$$9 = NULL, *_36$$9, *_37$$9, *_44$$10, *_53$$11, *_54$$11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &socket);



	ZEPHIR_CALL_METHOD(&headers, this_ptr, "receiveclear", NULL, 0, socket);
	zephir_check_call_status();
	if (!(zephir_is_true(headers))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "\r\n", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "\n", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "\n", 1);
	zephir_array_fast_append(_3, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "\r\n", 1);
	zephir_array_fast_append(_3, _2);
	zephir_fast_str_replace(&_0, _1, _3, headers TSRMLS_CC);
	ZEPHIR_CPY_WRT(headers, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "(\r\n\\s+)", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, " ", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_5, "preg_replace", NULL, 93, _2, _4, headers);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_fast_explode_str(_0, SL("\r\n"), _5, LONG_MAX TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&headers, "array_filter", NULL, 8, _0);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(headers);
	ZEPHIR_CALL_FUNCTION(&_6, "array_shift", NULL, 3, headers);
	ZEPHIR_UNREF(headers);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(request);
	zephir_fast_explode_str(request, SL(" "), _6, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	zephir_array_fetch_long(&_7, request, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 154 TSRMLS_CC);
	zephir_fast_strtoupper(_2, _7);
	if (!ZEPHIR_IS_STRING_IDENTICAL(_2, "GET")) {
		ZEPHIR_INIT_VAR(_8$$4);
		ZVAL_STRING(_8$$4, "HTTP/1.1 405 Method Not Allowed\r\n\r\n", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, socket, _8$$4);
		zephir_check_temp_parameter(_8$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(tmp);
	array_init(tmp);
	zephir_is_iterable(headers, &_10, &_9, 0, 0, "ice/cli/websocket/server.zep", 167);
	for (
	  ; zend_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zend_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HVALUE(header, _11);
		ZEPHIR_INIT_NVAR(_12$$5);
		zephir_fast_explode_str(_12$$5, SL(":"), header, 2  TSRMLS_CC);
		ZEPHIR_CPY_WRT(header, _12$$5);
		ZEPHIR_INIT_NVAR(_12$$5);
		zephir_array_fetch_long(&_13$$5, header, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 164 TSRMLS_CC);
		zephir_fast_trim(_12$$5, _13$$5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_14$$5);
		ZEPHIR_INIT_NVAR(_15$$5);
		zephir_array_fetch_long(&_16$$5, header, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 164 TSRMLS_CC);
		zephir_fast_strtolower(_15$$5, _16$$5);
		zephir_fast_trim(_14$$5, _15$$5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		zephir_array_update_zval(&tmp, _14$$5, &_12$$5, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CPY_WRT(headers, tmp);
	_17 = !(zephir_array_isset_string(headers, SS("sec-websocket-key")));
	if (!(_17)) {
		_17 = !(zephir_array_isset_string(headers, SS("upgrade")));
	}
	_18 = _17;
	if (!(_18)) {
		_18 = !(zephir_array_isset_string(headers, SS("connection")));
	}
	_19 = _18;
	if (!(_19)) {
		ZEPHIR_INIT_NVAR(_4);
		zephir_array_fetch_string(&_20, headers, SL("upgrade"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 170 TSRMLS_CC);
		zephir_fast_strtolower(_4, _20);
		_19 = !ZEPHIR_IS_STRING(_4, "websocket");
	}
	_21 = _19;
	if (!(_21)) {
		ZEPHIR_INIT_VAR(_22);
		zephir_array_fetch_string(&_23, headers, SL("connection"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 170 TSRMLS_CC);
		zephir_fast_strtolower(_22, _23);
		ZEPHIR_SINIT_VAR(_24);
		ZVAL_STRING(&_24, "upgrade", 0);
		ZEPHIR_INIT_VAR(_25);
		zephir_fast_strpos(_25, _22, &_24, 0 );
		_21 = ZEPHIR_IS_FALSE_IDENTICAL(_25);
	}
	if (_21) {
		ZEPHIR_INIT_VAR(_26$$6);
		ZVAL_STRING(_26$$6, "HTTP/1.1 400 Bad Request\r\n\r\n", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, socket, _26$$6);
		zephir_check_temp_parameter(_26$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(cookies);
	array_init(cookies);
	if (zephir_array_isset_string(headers, SS("cookie"))) {
		zephir_array_fetch_string(&_27$$7, headers, SL("cookie"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 179 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(tmp);
		zephir_fast_explode_str(tmp, SL(";"), _27$$7, LONG_MAX TSRMLS_CC);
		zephir_is_iterable(tmp, &_29$$7, &_28$$7, 0, 0, "ice/cli/websocket/server.zep", 187);
		for (
		  ; zend_hash_get_current_data_ex(_29$$7, (void**) &_30$$7, &_28$$7) == SUCCESS
		  ; zend_hash_move_forward_ex(_29$$7, &_28$$7)
		) {
			ZEPHIR_GET_HVALUE(value, _30$$7);
			ZEPHIR_INIT_NVAR(_31$$8);
			zephir_fast_trim(_31$$8, value, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			_32$$8 = !ZEPHIR_IS_STRING_IDENTICAL(_31$$8, "");
			if (_32$$8) {
				ZEPHIR_SINIT_NVAR(_33$$8);
				ZVAL_STRING(&_33$$8, "=", 0);
				ZEPHIR_INIT_NVAR(_34$$8);
				zephir_fast_strpos(_34$$8, value, &_33$$8, 0 );
				_32$$8 = !ZEPHIR_IS_FALSE_IDENTICAL(_34$$8);
			}
			if (_32$$8) {
				ZEPHIR_INIT_NVAR(_35$$9);
				zephir_fast_explode_str(_35$$9, SL("="), value, 2  TSRMLS_CC);
				ZEPHIR_CPY_WRT(value, _35$$9);
				zephir_array_fetch_long(&_36$$9, value, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 184 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_35$$9);
				zephir_array_fetch_long(&_37$$9, value, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 184 TSRMLS_CC);
				zephir_fast_trim(_35$$9, _37$$9, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
				zephir_array_update_zval(&cookies, _35$$9, &_36$$9, PH_COPY | PH_SEPARATE);
			}
		}
	}
	ZEPHIR_INIT_VAR(client);
	zephir_create_array(client, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&client, SL("socket"), &socket, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&client, SL("headers"), &headers, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_38);
	zephir_array_fetch_long(&_38, request, 1, PH_NOISY, "ice/cli/websocket/server.zep", 192 TSRMLS_CC);
	zephir_array_update_string(&client, SL("resource"), &_38, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&client, SL("cookies"), &cookies, PH_COPY | PH_SEPARATE);
	_39 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
	_40 = zephir_array_isset_string(_39, SS("validate"));
	if (_40) {
		_41 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
		zephir_array_fetch_string(&_42, _41, SL("validate"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 196 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_43, "call_user_func", NULL, 87, _42, client, this_ptr);
		zephir_check_call_status();
		_40 = !zephir_is_true(_43);
	}
	if (_40) {
		ZEPHIR_INIT_VAR(_44$$10);
		ZVAL_STRING(_44$$10, "HTTP/1.1 400 Bad Request\r\n\r\n", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, socket, _44$$10);
		zephir_check_temp_parameter(_44$$10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(response);
	zephir_create_array(response, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_45);
	ZVAL_STRING(_45, "HTTP/1.1 101 WebSocket Protocol Handshake", 1);
	zephir_array_fast_append(response, _45);
	ZEPHIR_INIT_NVAR(_45);
	ZVAL_STRING(_45, "Upgrade: WebSocket", 1);
	zephir_array_fast_append(response, _45);
	ZEPHIR_INIT_NVAR(_45);
	ZVAL_STRING(_45, "Connection: Upgrade", 1);
	zephir_array_fast_append(response, _45);
	ZEPHIR_INIT_NVAR(_45);
	ZVAL_STRING(_45, "Sec-WebSocket-Version: 13", 1);
	zephir_array_fast_append(response, _45);
	_46 = zephir_fetch_nproperty_this(this_ptr, SL("address"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_47);
	ZEPHIR_CONCAT_SV(_47, "Sec-WebSocket-Location: ", _46);
	zephir_array_fast_append(response, _47);
	zephir_array_fetch_string(&_48, headers, SL("sec-websocket-key"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 208 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_49);
	zephir_read_static_property_ce(&_49, ice_cli_websocket_server_ce, SL("magic") TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_47);
	ZEPHIR_CONCAT_VV(_47, _48, _49);
	ZEPHIR_CALL_FUNCTION(&_50, "sha1", NULL, 61, _47, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_51, "base64_encode", NULL, 15, _50);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_52);
	ZEPHIR_CONCAT_SV(_52, "Sec-WebSocket-Accept: ", _51);
	zephir_array_fast_append(response, _52);
	if (zephir_array_isset_string(headers, SS("origin"))) {
		zephir_array_fetch_string(&_53$$11, headers, SL("origin"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 212 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_54$$11);
		ZEPHIR_CONCAT_SV(_54$$11, "Sec-WebSocket-Origin: ", _53$$11);
		zephir_array_append(&response, _54$$11, PH_SEPARATE, "ice/cli/websocket/server.zep", 212);
	}
	ZEPHIR_INIT_NVAR(_45);
	ZVAL_LONG(_45, zephir_get_intval(socket));
	zephir_update_property_array(this_ptr, SL("sockets"), _45, socket TSRMLS_CC);
	ZEPHIR_INIT_VAR(_55);
	ZVAL_LONG(_55, zephir_get_intval(socket));
	zephir_update_property_array(this_ptr, SL("clients"), _55, client TSRMLS_CC);
	ZEPHIR_INIT_VAR(_56);
	zephir_fast_join_str(_56, SL("\r\n"), response TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_52);
	ZEPHIR_CONCAT_VS(_52, _56, "\r\n\r\n");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "sendclear", NULL, 0, socket, _52);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Disconnect a socket from the server.
 *
 * @param resource socket The resource
 * @return void
 */
PHP_METHOD(Ice_Cli_Websocket_Server, disconnect) {

	zval *socket, *_0, *_1;

	zephir_fetch_params(0, 1, 0, &socket);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("clients"), PH_NOISY_CC);
	zephir_array_unset_long(&_0, zephir_get_intval(socket), PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("sockets"), PH_NOISY_CC);
	zephir_array_unset_long(&_1, zephir_get_intval(socket), PH_SEPARATE);

}

/**
 * Set a callback to be executed when a client connects, returning `false` will prevent the client from connecting.
 * The callable will receive:
 *  - an associative array with client data
 *  - the current server instance
 * The callable should return `true` if the client should be allowed to connect or `false` otherwise.
 *
 * @param callable callback The callback
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Server, onValidate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, _0, callback);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set a callback to be executed when a client is connected.
 * The callable will receive:
 *  - an associative array with client data
 *  - the current server instance
 *
 * @param callable callback The callback
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Server, onConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "connect", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, _0, callback);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set a callback to execute when a client disconnects.
 * The callable will receive:
 *  - an associative array with client data
 *  - the current server instance
 *
 * @param callable callback The callback
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Server, onDisconnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "disconnect", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, _0, callback);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set a callback to execute when a client sends a message.
 * The callable will receive:
 *  - an associative array with client data
 *  - the message string
 *  - the current server instance
 *
 * @param callable callback The callback
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Server, onMessage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "message", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, _0, callback);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set a callback to execute every few milliseconds.
 * The callable will receive the server instance. If it returns boolean `false` the server will stop listening.
 *
 * @param callable callback The callback
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Server, onTick) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "tick", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, _0, callback);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set a callback to execute on boot the server.
 * The callable will receive the server instance.
 *
 * @param callable callback The callback
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Server, onBoot) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "boot", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, _0, callback);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Register a callback to execute.
 *
 * @param string key A callback key
 * @param callable callback The callback
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Server, callback) {

	zval *key_param = NULL, *callback;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &callback);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("callbacks"), key, callback TSRMLS_CC);
	RETURN_THIS();

}

zend_object_value zephir_init_properties_Ice_Cli_Websocket_Server(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_1$$3, *_3$$4, *_5$$5;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("callbacks"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("callbacks"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("clients"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("clients"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("sockets"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(getThis(), SL("sockets"), _5$$5 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

