
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

	zval *verbose, verbose_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&verbose_sub);

	zephir_fetch_params(0, 1, 0, &verbose);



	zephir_update_property_zval(this_ptr, SL("verbose"), verbose);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cli_Websocket_Server, getServer) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "server");

}

PHP_METHOD(Ice_Cli_Websocket_Server, getClients) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "clients");

}

/**
 * Create an instance.
 *
 * @param string address Where to create the server, defaults to "ws://127.0.0.1:8080"
 * @param array options Stream context options
 */
PHP_METHOD(Ice_Cli_Websocket_Server, __construct) {

	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_bool _0, _1, _2;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _10;
	zval *address_param = NULL, *options_param = NULL, addr, context, key, value, _8, _9, _11, _12, _13, _14, _15, _16, _17, _18, *_3$$4, _6$$5;
	zval address;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&addr);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &address_param, &options_param);

	if (!address_param) {
		ZEPHIR_INIT_VAR(&address);
		ZVAL_STRING(&address, "ws://127.0.0.1:8080");
	} else {
		zephir_get_strval(&address, address_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_FUNCTION(&addr, "parse_url", NULL, 70, &address);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_FALSE_IDENTICAL(&addr);
	if (!(_0)) {
		_0 = !(zephir_array_isset_string(&addr, SL("scheme")));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = !(zephir_array_isset_string(&addr, SL("host")));
	}
	_2 = _1;
	if (!(_2)) {
		_2 = !(zephir_array_isset_string(&addr, SL("port")));
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid address", "ice/cli/websocket/server.zep", 38);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&context, "stream_context_create", NULL, 78);
	zephir_check_call_status();
	if (zephir_fast_count_int(&options TSRMLS_CC)) {
		zephir_is_iterable(&options, 0, "ice/cli/websocket/server.zep", 47);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _5$$4);
			} else {
				ZVAL_LONG(&key, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3$$4);
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "ssl");
			ZEPHIR_CALL_FUNCTION(NULL, "stream_context_set_option", &_7, 79, &context, &_6$$5, &key, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	zephir_update_property_zval(this_ptr, SL("address"), &address);
	ZEPHIR_INIT_VAR(&_8);
	zephir_array_fetch_string(&_9, &addr, SL("scheme"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 52 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "wss");
	zephir_array_fast_append(&_10, &_11);
	ZEPHIR_INIT_NVAR(&_11);
	ZVAL_STRING(&_11, "tls");
	zephir_array_fast_append(&_10, &_11);
	if (zephir_fast_in_array(&_9, &_10 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_STRING(&_8, "tls");
	} else {
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_STRING(&_8, "tcp");
	}
	zephir_array_fetch_string(&_12, &addr, SL("host"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 52 TSRMLS_CC);
	zephir_array_fetch_string(&_13, &addr, SL("port"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 52 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_14);
	ZEPHIR_CONCAT_VSVSV(&_14, &_8, "://", &_12, ":", &_13);
	ZVAL_NULL(&_15);
	ZVAL_NULL(&_16);
	ZVAL_LONG(&_17, (4 | 8));
	ZEPHIR_MAKE_REF(&_15);
	ZEPHIR_MAKE_REF(&_16);
	ZEPHIR_CALL_FUNCTION(&_18, "stream_socket_server", NULL, 80, &_14, &_15, &_16, &_17, &context);
	ZEPHIR_UNREF(&_15);
	ZEPHIR_UNREF(&_16);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("server"), &_18);
	zephir_read_property(&_15, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_15)) {
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

	zval _24$$13, _32$$16;
	zend_bool _23$$13;
	zval changed, write, except, stream, messages, message, socket, tmp, _0, _1$$3, _2$$3, _4$$4, _8$$4, _9$$4, _41$$4, _42$$4, _43$$4, _5$$5, _6$$5, _7$$5, *_11$$7, *_35$$7, _12$$8, _13$$9, _15$$10, _17$$11, _18$$12, _19$$12, _20$$12, _21$$12, _25$$13, _26$$14, _27$$15, _28$$15, _29$$15, _30$$15, _33$$16, _34$$16, _36$$17, _37$$18, _38$$18, _39$$18, _40$$18;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_10 = NULL, *_14 = NULL, *_16 = NULL, *_22 = NULL, *_31 = NULL, *_44 = NULL, *_45 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&changed);
	ZVAL_UNDEF(&write);
	ZVAL_UNDEF(&except);
	ZVAL_UNDEF(&stream);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&socket);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_41$$4);
	ZVAL_UNDEF(&_42$$4);
	ZVAL_UNDEF(&_43$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$18);
	ZVAL_UNDEF(&_38$$18);
	ZVAL_UNDEF(&_39$$18);
	ZVAL_UNDEF(&_40$$18);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_32$$16);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_array_append(this_ptr, SL("sockets"), &_0 TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("boot"))) {
		zephir_read_property(&_1$$3, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("boot"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 76 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 76, &_2$$3, this_ptr);
		zephir_check_call_status();
	}
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_4$$4, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string(&_4$$4, SL("tick"))) {
			zephir_read_property(&_5$$5, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_6$$5, &_5$$5, SL("tick"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 81 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_7$$5, "call_user_func", &_3, 76, &_6$$5, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$5)) {
				break;
			}
		}
		ZEPHIR_OBS_NVAR(&changed);
		zephir_read_property(&changed, this_ptr, SL("sockets"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&write);
		array_init(&write);
		ZEPHIR_INIT_NVAR(&except);
		array_init(&except);
		ZEPHIR_INIT_LNVAR(_8$$4);
		zephir_read_property(&_9$$4, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string(&_9$$4, SL("tick"))) {
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_LONG(&_8$$4, 0);
		} else {
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_NULL(&_8$$4);
		}
		ZEPHIR_MAKE_REF(&changed);
		ZEPHIR_MAKE_REF(&write);
		ZEPHIR_MAKE_REF(&except);
		ZEPHIR_CALL_FUNCTION(&stream, "stream_select", &_10, 77, &changed, &write, &except, &_8$$4);
		ZEPHIR_UNREF(&changed);
		ZEPHIR_UNREF(&write);
		ZEPHIR_UNREF(&except);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&stream, 0)) {
			ZEPHIR_INIT_NVAR(&messages);
			array_init(&messages);
			zephir_is_iterable(&changed, 0, "ice/cli/websocket/server.zep", 123);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&changed), _11$$7)
			{
				ZEPHIR_INIT_NVAR(&socket);
				ZVAL_COPY(&socket, _11$$7);
				zephir_read_property(&_12$$8, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_IDENTICAL(&socket, &_12$$8)) {
					zephir_read_property(&_13$$9, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_FUNCTION(&tmp, "stream_socket_accept", &_14, 81, &_13$$9);
					zephir_check_call_status();
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&tmp)) {
						ZEPHIR_CALL_METHOD(&_15$$10, this_ptr, "connect", &_16, 0, &tmp);
						zephir_check_call_status();
						if (zephir_is_true(&_15$$10)) {
							zephir_read_property(&_17$$11, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
							if (zephir_array_isset_string(&_17$$11, SL("connect"))) {
								zephir_read_property(&_18$$12, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch_string(&_19$$12, &_18$$12, SL("connect"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 101 TSRMLS_CC);
								zephir_read_property(&_20$$12, this_ptr, SL("clients"), PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch_long(&_21$$12, &_20$$12, zephir_get_intval(&tmp), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 101 TSRMLS_CC);
								ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 76, &_19$$12, &_21$$12, this_ptr);
								zephir_check_call_status();
							}
						}
					}
				} else {
					ZEPHIR_CALL_METHOD(&message, this_ptr, "receive", &_22, 0, &socket);
					zephir_check_call_status();
					_23$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&message);
					if (!(_23$$13)) {
						ZEPHIR_INIT_NVAR(&_24$$13);
						zephir_create_array(&_24$$13, 3, 0 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(&_25$$13);
						ZVAL_STRING(&_25$$13, "quit");
						zephir_array_fast_append(&_24$$13, &_25$$13);
						ZEPHIR_INIT_NVAR(&_25$$13);
						ZVAL_STRING(&_25$$13, "exit");
						zephir_array_fast_append(&_24$$13, &_25$$13);
						ZEPHIR_INIT_NVAR(&_25$$13);
						ZVAL_STRING(&_25$$13, "close");
						zephir_array_fast_append(&_24$$13, &_25$$13);
						_23$$13 = zephir_fast_in_array(&message, &_24$$13 TSRMLS_CC);
					}
					if (_23$$13) {
						zephir_read_property(&_26$$14, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset_string(&_26$$14, SL("disconnect"))) {
							zephir_read_property(&_27$$15, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch_string(&_28$$15, &_27$$15, SL("disconnect"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 110 TSRMLS_CC);
							zephir_read_property(&_29$$15, this_ptr, SL("clients"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch_long(&_30$$15, &_29$$15, zephir_get_intval(&socket), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 110 TSRMLS_CC);
							ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 76, &_28$$15, &_30$$15, this_ptr);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", &_31, 0, &socket);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_32$$16);
						zephir_create_array(&_32$$16, 2, 0 TSRMLS_CC);
						zephir_read_property(&_33$$16, this_ptr, SL("clients"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_34$$16);
						zephir_array_fetch_long(&_34$$16, &_33$$16, zephir_get_intval(&socket), PH_NOISY, "ice/cli/websocket/server.zep", 116 TSRMLS_CC);
						zephir_array_update_string(&_32$$16, SL("client"), &_34$$16, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_32$$16, SL("message"), &message, PH_COPY | PH_SEPARATE);
						zephir_array_append(&messages, &_32$$16, PH_SEPARATE, "ice/cli/websocket/server.zep", 118);
					}
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&socket);
			zephir_is_iterable(&messages, 0, "ice/cli/websocket/server.zep", 128);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&messages), _35$$7)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _35$$7);
				zephir_read_property(&_36$$17, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset_string(&_36$$17, SL("message"))) {
					zephir_read_property(&_37$$18, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch_string(&_38$$18, &_37$$18, SL("message"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125 TSRMLS_CC);
					zephir_array_fetch_string(&_39$$18, &message, SL("client"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125 TSRMLS_CC);
					zephir_array_fetch_string(&_40$$18, &message, SL("message"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125 TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 76, &_38$$18, &_39$$18, &_40$$18, this_ptr);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&message);
		}
		ZEPHIR_INIT_NVAR(&_42$$4);
		ZVAL_STRING(&_42$$4, "sleep");
		ZVAL_LONG(&_43$$4, 5000);
		ZEPHIR_CALL_METHOD(&_41$$4, this_ptr, "getparam", &_44, 0, &_42$$4, &_43$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_45, 32, &_41$$4);
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

	zend_bool _15, _16, _17, _19, _36, _28$$8;
	zval _1, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *socket, socket_sub, __$true, headers, header, request, tmp, cookies, value, client, response, _0, _2, _4, _5, _6, _7, *_9, _18, _20, _21, _22, _23, _34, _35, _37, _38, _39, _41, _42, _43, _44, _45, _46, _47, _48, _51, _52, _8$$4, _10$$5, _11$$5, _12$$5, _13$$5, _14$$5, _24$$6, _25$$7, *_26$$7, _27$$8, _29$$8, _30$$8, _31$$9, _32$$9, _33$$9, _40$$10, _49$$11, _50$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&socket_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&client);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &socket);



	ZEPHIR_CALL_METHOD(&headers, this_ptr, "receiveclear", NULL, 0, socket);
	zephir_check_call_status();
	if (!(zephir_is_true(&headers))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\r\n");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "\n");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "\n");
	zephir_array_fast_append(&_3, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "\r\n");
	zephir_array_fast_append(&_3, &_2);
	zephir_fast_str_replace(&_0, &_1, &_3, &headers TSRMLS_CC);
	ZEPHIR_CPY_WRT(&headers, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "(\r\n\\s+)");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, " ");
	ZEPHIR_CALL_FUNCTION(&_5, "preg_replace", NULL, 82, &_2, &_4, &headers);
	zephir_check_call_status();
	zephir_fast_explode_str(&_0, SL("\r\n"), &_5, LONG_MAX TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&headers, "array_filter", NULL, 7, &_0);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&headers);
	ZEPHIR_CALL_FUNCTION(&_6, "array_shift", NULL, 2, &headers);
	ZEPHIR_UNREF(&headers);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&request);
	zephir_fast_explode_str(&request, SL(" "), &_6, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_array_fetch_long(&_7, &request, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 154 TSRMLS_CC);
	zephir_fast_strtoupper(&_2, &_7);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_2, "GET")) {
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "HTTP/1.1 405 Method Not Allowed\r\n\r\n");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, socket, &_8$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&tmp);
	array_init(&tmp);
	zephir_is_iterable(&headers, 0, "ice/cli/websocket/server.zep", 167);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&headers), _9)
	{
		ZEPHIR_INIT_NVAR(&header);
		ZVAL_COPY(&header, _9);
		ZEPHIR_INIT_NVAR(&_10$$5);
		zephir_fast_explode_str(&_10$$5, SL(":"), &header, 2  TSRMLS_CC);
		ZEPHIR_CPY_WRT(&header, &_10$$5);
		ZEPHIR_INIT_NVAR(&_10$$5);
		zephir_array_fetch_long(&_11$$5, &header, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 164 TSRMLS_CC);
		zephir_fast_trim(&_10$$5, &_11$$5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_12$$5);
		ZEPHIR_INIT_NVAR(&_13$$5);
		zephir_array_fetch_long(&_14$$5, &header, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 164 TSRMLS_CC);
		zephir_fast_strtolower(&_13$$5, &_14$$5);
		zephir_fast_trim(&_12$$5, &_13$$5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		zephir_array_update_zval(&tmp, &_12$$5, &_10$$5, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&header);
	ZEPHIR_CPY_WRT(&headers, &tmp);
	_15 = !(zephir_array_isset_string(&headers, SL("sec-websocket-key")));
	if (!(_15)) {
		_15 = !(zephir_array_isset_string(&headers, SL("upgrade")));
	}
	_16 = _15;
	if (!(_16)) {
		_16 = !(zephir_array_isset_string(&headers, SL("connection")));
	}
	_17 = _16;
	if (!(_17)) {
		ZEPHIR_INIT_NVAR(&_4);
		zephir_array_fetch_string(&_18, &headers, SL("upgrade"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 170 TSRMLS_CC);
		zephir_fast_strtolower(&_4, &_18);
		_17 = !ZEPHIR_IS_STRING(&_4, "websocket");
	}
	_19 = _17;
	if (!(_19)) {
		ZEPHIR_INIT_VAR(&_20);
		zephir_array_fetch_string(&_21, &headers, SL("connection"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 170 TSRMLS_CC);
		zephir_fast_strtolower(&_20, &_21);
		ZEPHIR_INIT_VAR(&_22);
		ZVAL_STRING(&_22, "upgrade");
		ZEPHIR_INIT_VAR(&_23);
		zephir_fast_strpos(&_23, &_20, &_22, 0 );
		_19 = ZEPHIR_IS_FALSE_IDENTICAL(&_23);
	}
	if (_19) {
		ZEPHIR_INIT_VAR(&_24$$6);
		ZVAL_STRING(&_24$$6, "HTTP/1.1 400 Bad Request\r\n\r\n");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, socket, &_24$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&cookies);
	array_init(&cookies);
	if (zephir_array_isset_string(&headers, SL("cookie"))) {
		zephir_array_fetch_string(&_25$$7, &headers, SL("cookie"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 179 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&tmp);
		zephir_fast_explode_str(&tmp, SL(";"), &_25$$7, LONG_MAX TSRMLS_CC);
		zephir_is_iterable(&tmp, 0, "ice/cli/websocket/server.zep", 187);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmp), _26$$7)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _26$$7);
			ZEPHIR_INIT_NVAR(&_27$$8);
			zephir_fast_trim(&_27$$8, &value, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			_28$$8 = !ZEPHIR_IS_STRING_IDENTICAL(&_27$$8, "");
			if (_28$$8) {
				ZEPHIR_INIT_NVAR(&_29$$8);
				ZVAL_STRING(&_29$$8, "=");
				ZEPHIR_INIT_NVAR(&_30$$8);
				zephir_fast_strpos(&_30$$8, &value, &_29$$8, 0 );
				_28$$8 = !ZEPHIR_IS_FALSE_IDENTICAL(&_30$$8);
			}
			if (_28$$8) {
				ZEPHIR_INIT_NVAR(&_31$$9);
				zephir_fast_explode_str(&_31$$9, SL("="), &value, 2  TSRMLS_CC);
				ZEPHIR_CPY_WRT(&value, &_31$$9);
				zephir_array_fetch_long(&_32$$9, &value, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 184 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_31$$9);
				zephir_array_fetch_long(&_33$$9, &value, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 184 TSRMLS_CC);
				zephir_fast_trim(&_31$$9, &_33$$9, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
				zephir_array_update_zval(&cookies, &_31$$9, &_32$$9, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
	}
	ZEPHIR_INIT_VAR(&client);
	zephir_create_array(&client, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&client, SL("socket"), socket, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&client, SL("headers"), &headers, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_34);
	zephir_array_fetch_long(&_34, &request, 1, PH_NOISY, "ice/cli/websocket/server.zep", 192 TSRMLS_CC);
	zephir_array_update_string(&client, SL("resource"), &_34, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&client, SL("cookies"), &cookies, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_35, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
	_36 = zephir_array_isset_string(&_35, SL("validate"));
	if (_36) {
		zephir_read_property(&_37, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_38, &_37, SL("validate"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 196 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_39, "call_user_func", NULL, 76, &_38, &client, this_ptr);
		zephir_check_call_status();
		_36 = !zephir_is_true(&_39);
	}
	if (_36) {
		ZEPHIR_INIT_VAR(&_40$$10);
		ZVAL_STRING(&_40$$10, "HTTP/1.1 400 Bad Request\r\n\r\n");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, socket, &_40$$10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&response);
	zephir_create_array(&response, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_41);
	ZVAL_STRING(&_41, "HTTP/1.1 101 WebSocket Protocol Handshake");
	zephir_array_fast_append(&response, &_41);
	ZEPHIR_INIT_NVAR(&_41);
	ZVAL_STRING(&_41, "Upgrade: WebSocket");
	zephir_array_fast_append(&response, &_41);
	ZEPHIR_INIT_NVAR(&_41);
	ZVAL_STRING(&_41, "Connection: Upgrade");
	zephir_array_fast_append(&response, &_41);
	ZEPHIR_INIT_NVAR(&_41);
	ZVAL_STRING(&_41, "Sec-WebSocket-Version: 13");
	zephir_array_fast_append(&response, &_41);
	zephir_read_property(&_42, this_ptr, SL("address"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_43);
	ZEPHIR_CONCAT_SV(&_43, "Sec-WebSocket-Location: ", &_42);
	zephir_array_fast_append(&response, &_43);
	zephir_array_fetch_string(&_44, &headers, SL("sec-websocket-key"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 208 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_45);
	zephir_read_static_property_ce(&_45, ice_cli_websocket_server_ce, SL("magic"), PH_NOISY_CC);
	ZEPHIR_INIT_LNVAR(_43);
	ZEPHIR_CONCAT_VV(&_43, &_44, &_45);
	ZEPHIR_CALL_FUNCTION(&_46, "sha1", NULL, 58, &_43, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_47, "base64_encode", NULL, 14, &_46);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_48);
	ZEPHIR_CONCAT_SV(&_48, "Sec-WebSocket-Accept: ", &_47);
	zephir_array_fast_append(&response, &_48);
	if (zephir_array_isset_string(&headers, SL("origin"))) {
		zephir_array_fetch_string(&_49$$11, &headers, SL("origin"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 212 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_50$$11);
		ZEPHIR_CONCAT_SV(&_50$$11, "Sec-WebSocket-Origin: ", &_49$$11);
		zephir_array_append(&response, &_50$$11, PH_SEPARATE, "ice/cli/websocket/server.zep", 212);
	}
	ZEPHIR_INIT_NVAR(&_41);
	ZVAL_LONG(&_41, zephir_get_intval(socket));
	zephir_update_property_array(this_ptr, SL("sockets"), &_41, socket TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_51);
	ZVAL_LONG(&_51, zephir_get_intval(socket));
	zephir_update_property_array(this_ptr, SL("clients"), &_51, &client TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_52);
	zephir_fast_join_str(&_52, SL("\r\n"), &response TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_48);
	ZEPHIR_CONCAT_VS(&_48, &_52, "\r\n\r\n");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "sendclear", NULL, 0, socket, &_48);
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

	zval *socket, socket_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&socket_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params(0, 1, 0, &socket);



	zephir_read_property(&_0, this_ptr, SL("clients"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset_long(&_0, zephir_get_intval(socket), PH_SEPARATE);
	zephir_read_property(&_1, this_ptr, SL("sockets"), PH_NOISY_CC | PH_READONLY);
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
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "validate");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, &_0, callback);
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
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "connect");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, &_0, callback);
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
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "disconnect");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, &_0, callback);
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
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "message");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, &_0, callback);
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
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "tick");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, &_0, callback);
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
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "boot");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callback", NULL, 0, &_0, callback);
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

	zval *key_param = NULL, *callback, callback_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&callback_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &callback);

	zephir_get_strval(&key, key_param);


	zephir_update_property_array(this_ptr, SL("callbacks"), &key, callback TSRMLS_CC);
	RETURN_THIS();

}

zend_object *zephir_init_properties_Ice_Cli_Websocket_Server(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("callbacks"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("clients"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("clients"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("sockets"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("sockets"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

