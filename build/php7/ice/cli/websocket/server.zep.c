
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

	zend_declare_property_bool(ice_cli_websocket_server_ce, SL("verbose"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_cli_websocket_server_ce, SL("address"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_cli_websocket_server_ce, SL("server"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_cli_websocket_server_ce, SL("sockets"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_cli_websocket_server_ce, SL("clients"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_cli_websocket_server_ce, SL("callbacks"), ZEND_ACC_PROTECTED);

	ice_cli_websocket_server_ce->create_object = zephir_init_properties_Ice_Cli_Websocket_Server;
	return SUCCESS;

}

PHP_METHOD(Ice_Cli_Websocket_Server, setVerbose) {

	zval *verbose, verbose_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&verbose_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &verbose);



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

	zend_string *_6$$4;
	zend_ulong _5$$4;
	zend_bool _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _12;
	zval *address_param = NULL, *options_param = NULL, addr, context, key, value, _10, _11, _13, _14, _15, _16, _17, _18, _19, _20, *_3$$4, _4$$4, _7$$5, _9$$6;
	zval address;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&addr);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_12);

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
	if (zephir_fast_count_int(&options)) {
		zephir_is_iterable(&options, 0, "ice/cli/websocket/server.zep", 47);
		if (Z_TYPE_P(&options) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _5$$4, _6$$4, _3$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_6$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _6$$4);
				} else {
					ZVAL_LONG(&key, _5$$4);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _3$$4);
				ZEPHIR_INIT_NVAR(&_7$$5);
				ZVAL_STRING(&_7$$5, "ssl");
				ZEPHIR_CALL_FUNCTION(NULL, "stream_context_set_option", &_8, 79, &context, &_7$$5, &key, &value);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$4, &options, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_9$$6);
					ZVAL_STRING(&_9$$6, "ssl");
					ZEPHIR_CALL_FUNCTION(NULL, "stream_context_set_option", &_8, 79, &context, &_9$$6, &key, &value);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	zephir_update_property_zval(this_ptr, SL("address"), &address);
	ZEPHIR_INIT_VAR(&_10);
	zephir_array_fetch_string(&_11, &addr, SL("scheme"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 52);
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 2, 0);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "wss");
	zephir_array_fast_append(&_12, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "tls");
	zephir_array_fast_append(&_12, &_13);
	if (zephir_fast_in_array(&_11, &_12)) {
		ZEPHIR_INIT_NVAR(&_10);
		ZVAL_STRING(&_10, "tls");
	} else {
		ZEPHIR_INIT_NVAR(&_10);
		ZVAL_STRING(&_10, "tcp");
	}
	zephir_array_fetch_string(&_14, &addr, SL("host"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 52);
	zephir_array_fetch_string(&_15, &addr, SL("port"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 52);
	ZEPHIR_INIT_VAR(&_16);
	ZEPHIR_CONCAT_VSVSV(&_16, &_10, "://", &_14, ":", &_15);
	ZVAL_NULL(&_17);
	ZVAL_NULL(&_18);
	ZVAL_LONG(&_19, (4 | 8));
	ZEPHIR_MAKE_REF(&_17);
	ZEPHIR_MAKE_REF(&_18);
	ZEPHIR_CALL_FUNCTION(&_20, "stream_socket_server", NULL, 80, &_16, &_17, &_18, &_19, &context);
	ZEPHIR_UNREF(&_17);
	ZEPHIR_UNREF(&_18);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("server"), &_20);
	zephir_read_property(&_17, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_17)) {
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

	zval _25$$13, _33$$16, _45$$22, _52$$25;
	zend_bool _24$$13, _44$$22;
	zval changed, write, except, stream, messages, message, socket, tmp, _0, _1$$3, _2$$3, _4$$4, _8$$4, _9$$4, _67$$4, _68$$4, _69$$4, _5$$5, _6$$5, _7$$5, *_11$$7, _12$$7, *_55$$7, _56$$7, _13$$8, _14$$9, _16$$10, _18$$11, _19$$12, _20$$12, _21$$12, _22$$12, _26$$13, _27$$14, _28$$15, _29$$15, _30$$15, _31$$15, _34$$16, _35$$16, _36$$17, _37$$18, _38$$19, _39$$20, _40$$21, _41$$21, _42$$21, _43$$21, _46$$22, _47$$23, _48$$24, _49$$24, _50$$24, _51$$24, _53$$25, _54$$25, _57$$26, _58$$27, _59$$27, _60$$27, _61$$27, _62$$28, _63$$29, _64$$29, _65$$29, _66$$29;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_10 = NULL, *_15 = NULL, *_17 = NULL, *_23 = NULL, *_32 = NULL, *_70 = NULL, *_71 = NULL;
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
	ZVAL_UNDEF(&_67$$4);
	ZVAL_UNDEF(&_68$$4);
	ZVAL_UNDEF(&_69$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_56$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_35$$16);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$18);
	ZVAL_UNDEF(&_38$$19);
	ZVAL_UNDEF(&_39$$20);
	ZVAL_UNDEF(&_40$$21);
	ZVAL_UNDEF(&_41$$21);
	ZVAL_UNDEF(&_42$$21);
	ZVAL_UNDEF(&_43$$21);
	ZVAL_UNDEF(&_46$$22);
	ZVAL_UNDEF(&_47$$23);
	ZVAL_UNDEF(&_48$$24);
	ZVAL_UNDEF(&_49$$24);
	ZVAL_UNDEF(&_50$$24);
	ZVAL_UNDEF(&_51$$24);
	ZVAL_UNDEF(&_53$$25);
	ZVAL_UNDEF(&_54$$25);
	ZVAL_UNDEF(&_57$$26);
	ZVAL_UNDEF(&_58$$27);
	ZVAL_UNDEF(&_59$$27);
	ZVAL_UNDEF(&_60$$27);
	ZVAL_UNDEF(&_61$$27);
	ZVAL_UNDEF(&_62$$28);
	ZVAL_UNDEF(&_63$$29);
	ZVAL_UNDEF(&_64$$29);
	ZVAL_UNDEF(&_65$$29);
	ZVAL_UNDEF(&_66$$29);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_45$$22);
	ZVAL_UNDEF(&_52$$25);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_array_append(this_ptr, SL("sockets"), &_0);
	zephir_read_property(&_0, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("boot"))) {
		zephir_read_property(&_1$$3, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("boot"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 76);
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
			zephir_array_fetch_string(&_6$$5, &_5$$5, SL("tick"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 81);
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
		ZEPHIR_INIT_NVAR(&_8$$4);
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
			if (Z_TYPE_P(&changed) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&changed), _11$$7)
				{
					ZEPHIR_INIT_NVAR(&socket);
					ZVAL_COPY(&socket, _11$$7);
					zephir_read_property(&_13$$8, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
					if (ZEPHIR_IS_IDENTICAL(&socket, &_13$$8)) {
						zephir_read_property(&_14$$9, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_FUNCTION(&tmp, "stream_socket_accept", &_15, 81, &_14$$9);
						zephir_check_call_status();
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&tmp)) {
							ZEPHIR_CALL_METHOD(&_16$$10, this_ptr, "connect", &_17, 0, &tmp);
							zephir_check_call_status();
							if (zephir_is_true(&_16$$10)) {
								zephir_read_property(&_18$$11, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
								if (zephir_array_isset_string(&_18$$11, SL("connect"))) {
									zephir_read_property(&_19$$12, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch_string(&_20$$12, &_19$$12, SL("connect"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 101);
									zephir_read_property(&_21$$12, this_ptr, SL("clients"), PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch_long(&_22$$12, &_21$$12, zephir_get_intval(&tmp), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 101);
									ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 76, &_20$$12, &_22$$12, this_ptr);
									zephir_check_call_status();
								}
							}
						}
					} else {
						ZEPHIR_CALL_METHOD(&message, this_ptr, "receive", &_23, 0, &socket);
						zephir_check_call_status();
						_24$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&message);
						if (!(_24$$13)) {
							ZEPHIR_INIT_NVAR(&_25$$13);
							zephir_create_array(&_25$$13, 3, 0);
							ZEPHIR_INIT_NVAR(&_26$$13);
							ZVAL_STRING(&_26$$13, "quit");
							zephir_array_fast_append(&_25$$13, &_26$$13);
							ZEPHIR_INIT_NVAR(&_26$$13);
							ZVAL_STRING(&_26$$13, "exit");
							zephir_array_fast_append(&_25$$13, &_26$$13);
							ZEPHIR_INIT_NVAR(&_26$$13);
							ZVAL_STRING(&_26$$13, "close");
							zephir_array_fast_append(&_25$$13, &_26$$13);
							_24$$13 = zephir_fast_in_array(&message, &_25$$13);
						}
						if (_24$$13) {
							zephir_read_property(&_27$$14, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
							if (zephir_array_isset_string(&_27$$14, SL("disconnect"))) {
								zephir_read_property(&_28$$15, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch_string(&_29$$15, &_28$$15, SL("disconnect"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 110);
								zephir_read_property(&_30$$15, this_ptr, SL("clients"), PH_NOISY_CC | PH_READONLY);
								zephir_array_fetch_long(&_31$$15, &_30$$15, zephir_get_intval(&socket), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 110);
								ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 76, &_29$$15, &_31$$15, this_ptr);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", &_32, 0, &socket);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&_33$$16);
							zephir_create_array(&_33$$16, 2, 0);
							zephir_read_property(&_34$$16, this_ptr, SL("clients"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&_35$$16);
							zephir_array_fetch_long(&_35$$16, &_34$$16, zephir_get_intval(&socket), PH_NOISY, "ice/cli/websocket/server.zep", 116);
							zephir_array_update_string(&_33$$16, SL("client"), &_35$$16, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_33$$16, SL("message"), &message, PH_COPY | PH_SEPARATE);
							zephir_array_append(&messages, &_33$$16, PH_SEPARATE, "ice/cli/websocket/server.zep", 118);
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &changed, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_12$$7, &changed, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_12$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&socket, &changed, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property(&_36$$17, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
						if (ZEPHIR_IS_IDENTICAL(&socket, &_36$$17)) {
							zephir_read_property(&_37$$18, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_FUNCTION(&tmp, "stream_socket_accept", &_15, 81, &_37$$18);
							zephir_check_call_status();
							if (!ZEPHIR_IS_FALSE_IDENTICAL(&tmp)) {
								ZEPHIR_CALL_METHOD(&_38$$19, this_ptr, "connect", &_17, 0, &tmp);
								zephir_check_call_status();
								if (zephir_is_true(&_38$$19)) {
									zephir_read_property(&_39$$20, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
									if (zephir_array_isset_string(&_39$$20, SL("connect"))) {
										zephir_read_property(&_40$$21, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
										zephir_array_fetch_string(&_41$$21, &_40$$21, SL("connect"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 101);
										zephir_read_property(&_42$$21, this_ptr, SL("clients"), PH_NOISY_CC | PH_READONLY);
										zephir_array_fetch_long(&_43$$21, &_42$$21, zephir_get_intval(&tmp), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 101);
										ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 76, &_41$$21, &_43$$21, this_ptr);
										zephir_check_call_status();
									}
								}
							}
						} else {
							ZEPHIR_CALL_METHOD(&message, this_ptr, "receive", &_23, 36, &socket);
							zephir_check_call_status();
							_44$$22 = ZEPHIR_IS_FALSE_IDENTICAL(&message);
							if (!(_44$$22)) {
								ZEPHIR_INIT_NVAR(&_45$$22);
								zephir_create_array(&_45$$22, 3, 0);
								ZEPHIR_INIT_NVAR(&_46$$22);
								ZVAL_STRING(&_46$$22, "quit");
								zephir_array_fast_append(&_45$$22, &_46$$22);
								ZEPHIR_INIT_NVAR(&_46$$22);
								ZVAL_STRING(&_46$$22, "exit");
								zephir_array_fast_append(&_45$$22, &_46$$22);
								ZEPHIR_INIT_NVAR(&_46$$22);
								ZVAL_STRING(&_46$$22, "close");
								zephir_array_fast_append(&_45$$22, &_46$$22);
								_44$$22 = zephir_fast_in_array(&message, &_45$$22);
							}
							if (_44$$22) {
								zephir_read_property(&_47$$23, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
								if (zephir_array_isset_string(&_47$$23, SL("disconnect"))) {
									zephir_read_property(&_48$$24, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch_string(&_49$$24, &_48$$24, SL("disconnect"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 110);
									zephir_read_property(&_50$$24, this_ptr, SL("clients"), PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch_long(&_51$$24, &_50$$24, zephir_get_intval(&socket), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 110);
									ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 76, &_49$$24, &_51$$24, this_ptr);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", &_32, 0, &socket);
								zephir_check_call_status();
							} else {
								ZEPHIR_INIT_NVAR(&_52$$25);
								zephir_create_array(&_52$$25, 2, 0);
								zephir_read_property(&_53$$25, this_ptr, SL("clients"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_OBS_NVAR(&_54$$25);
								zephir_array_fetch_long(&_54$$25, &_53$$25, zephir_get_intval(&socket), PH_NOISY, "ice/cli/websocket/server.zep", 116);
								zephir_array_update_string(&_52$$25, SL("client"), &_54$$25, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_52$$25, SL("message"), &message, PH_COPY | PH_SEPARATE);
								zephir_array_append(&messages, &_52$$25, PH_SEPARATE, "ice/cli/websocket/server.zep", 118);
							}
						}
					ZEPHIR_CALL_METHOD(NULL, &changed, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&socket);
			zephir_is_iterable(&messages, 0, "ice/cli/websocket/server.zep", 128);
			if (Z_TYPE_P(&messages) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&messages), _55$$7)
				{
					ZEPHIR_INIT_NVAR(&message);
					ZVAL_COPY(&message, _55$$7);
					zephir_read_property(&_57$$26, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset_string(&_57$$26, SL("message"))) {
						zephir_read_property(&_58$$27, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch_string(&_59$$27, &_58$$27, SL("message"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125);
						zephir_array_fetch_string(&_60$$27, &message, SL("client"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125);
						zephir_array_fetch_string(&_61$$27, &message, SL("message"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125);
						ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 76, &_59$$27, &_60$$27, &_61$$27, this_ptr);
						zephir_check_call_status();
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_56$$7, &messages, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_56$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&message, &messages, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property(&_62$$28, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset_string(&_62$$28, SL("message"))) {
							zephir_read_property(&_63$$29, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch_string(&_64$$29, &_63$$29, SL("message"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125);
							zephir_array_fetch_string(&_65$$29, &message, SL("client"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125);
							zephir_array_fetch_string(&_66$$29, &message, SL("message"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 125);
							ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 76, &_64$$29, &_65$$29, &_66$$29, this_ptr);
							zephir_check_call_status();
						}
					ZEPHIR_CALL_METHOD(NULL, &messages, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&message);
		}
		ZEPHIR_INIT_NVAR(&_68$$4);
		ZVAL_STRING(&_68$$4, "sleep");
		ZVAL_LONG(&_69$$4, 5000);
		ZEPHIR_CALL_METHOD(&_67$$4, this_ptr, "getparam", &_70, 0, &_68$$4, &_69$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_71, 32, &_67$$4);
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

	zend_bool _21, _22, _23, _25, _50, _35$$9, _42$$11;
	zval _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *socket, socket_sub, __$true, headers, header, request, tmp, cookies, value, client, response, _0, _2, _4, _5, _6, _7, *_9, _10, _24, _26, _27, _28, _29, _48, _49, _51, _52, _53, _55, _56, _57, _58, _59, _60, _61, _62, _65, _66, _8$$4, _11$$5, _12$$5, _13$$5, _14$$5, _15$$5, _16$$6, _17$$6, _18$$6, _19$$6, _20$$6, _30$$7, _31$$8, *_32$$8, _33$$8, _34$$9, _36$$9, _37$$9, _38$$10, _39$$10, _40$$10, _41$$11, _43$$11, _44$$11, _45$$12, _46$$12, _47$$12, _54$$13, _63$$14, _64$$14;
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
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_53);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_56);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_59);
	ZVAL_UNDEF(&_60);
	ZVAL_UNDEF(&_61);
	ZVAL_UNDEF(&_62);
	ZVAL_UNDEF(&_65);
	ZVAL_UNDEF(&_66);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_41$$11);
	ZVAL_UNDEF(&_43$$11);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&_45$$12);
	ZVAL_UNDEF(&_46$$12);
	ZVAL_UNDEF(&_47$$12);
	ZVAL_UNDEF(&_54$$13);
	ZVAL_UNDEF(&_63$$14);
	ZVAL_UNDEF(&_64$$14);
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
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\r\n");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "\n");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "\n");
	zephir_array_fast_append(&_3, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "\r\n");
	zephir_array_fast_append(&_3, &_2);
	zephir_fast_str_replace(&_0, &_1, &_3, &headers);
	ZEPHIR_CPY_WRT(&headers, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "(\r\n\\s+)");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, " ");
	ZEPHIR_CALL_FUNCTION(&_5, "preg_replace", NULL, 82, &_2, &_4, &headers);
	zephir_check_call_status();
	zephir_fast_explode_str(&_0, SL("\r\n"), &_5, LONG_MAX);
	ZEPHIR_CALL_FUNCTION(&headers, "array_filter", NULL, 7, &_0);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&headers);
	ZEPHIR_CALL_FUNCTION(&_6, "array_shift", NULL, 2, &headers);
	ZEPHIR_UNREF(&headers);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&request);
	zephir_fast_explode_str(&request, SL(" "), &_6, LONG_MAX);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_array_fetch_long(&_7, &request, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 154);
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
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&headers), _9)
		{
			ZEPHIR_INIT_NVAR(&header);
			ZVAL_COPY(&header, _9);
			ZEPHIR_INIT_NVAR(&_11$$5);
			zephir_fast_explode_str(&_11$$5, SL(":"), &header, 2 );
			ZEPHIR_CPY_WRT(&header, &_11$$5);
			ZEPHIR_INIT_NVAR(&_11$$5);
			zephir_array_fetch_long(&_12$$5, &header, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 164);
			zephir_fast_trim(&_11$$5, &_12$$5, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_NVAR(&_13$$5);
			ZEPHIR_INIT_NVAR(&_14$$5);
			zephir_array_fetch_long(&_15$$5, &header, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 164);
			zephir_fast_strtolower(&_14$$5, &_15$$5);
			zephir_fast_trim(&_13$$5, &_14$$5, NULL , ZEPHIR_TRIM_BOTH);
			zephir_array_update_zval(&tmp, &_13$$5, &_11$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_10, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&header, &headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$6);
				zephir_fast_explode_str(&_16$$6, SL(":"), &header, 2 );
				ZEPHIR_CPY_WRT(&header, &_16$$6);
				ZEPHIR_INIT_NVAR(&_16$$6);
				zephir_array_fetch_long(&_17$$6, &header, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 164);
				zephir_fast_trim(&_16$$6, &_17$$6, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_INIT_NVAR(&_18$$6);
				ZEPHIR_INIT_NVAR(&_19$$6);
				zephir_array_fetch_long(&_20$$6, &header, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 164);
				zephir_fast_strtolower(&_19$$6, &_20$$6);
				zephir_fast_trim(&_18$$6, &_19$$6, NULL , ZEPHIR_TRIM_BOTH);
				zephir_array_update_zval(&tmp, &_18$$6, &_16$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&header);
	ZEPHIR_CPY_WRT(&headers, &tmp);
	_21 = !(zephir_array_isset_string(&headers, SL("sec-websocket-key")));
	if (!(_21)) {
		_21 = !(zephir_array_isset_string(&headers, SL("upgrade")));
	}
	_22 = _21;
	if (!(_22)) {
		_22 = !(zephir_array_isset_string(&headers, SL("connection")));
	}
	_23 = _22;
	if (!(_23)) {
		ZEPHIR_INIT_NVAR(&_4);
		zephir_array_fetch_string(&_24, &headers, SL("upgrade"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 170);
		zephir_fast_strtolower(&_4, &_24);
		_23 = !ZEPHIR_IS_STRING(&_4, "websocket");
	}
	_25 = _23;
	if (!(_25)) {
		ZEPHIR_INIT_VAR(&_26);
		zephir_array_fetch_string(&_27, &headers, SL("connection"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 170);
		zephir_fast_strtolower(&_26, &_27);
		ZEPHIR_INIT_VAR(&_28);
		ZVAL_STRING(&_28, "upgrade");
		ZEPHIR_INIT_VAR(&_29);
		zephir_fast_strpos(&_29, &_26, &_28, 0 );
		_25 = ZEPHIR_IS_FALSE_IDENTICAL(&_29);
	}
	if (_25) {
		ZEPHIR_INIT_VAR(&_30$$7);
		ZVAL_STRING(&_30$$7, "HTTP/1.1 400 Bad Request\r\n\r\n");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, socket, &_30$$7);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&cookies);
	array_init(&cookies);
	if (zephir_array_isset_string(&headers, SL("cookie"))) {
		zephir_array_fetch_string(&_31$$8, &headers, SL("cookie"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 179);
		ZEPHIR_INIT_NVAR(&tmp);
		zephir_fast_explode_str(&tmp, SL(";"), &_31$$8, LONG_MAX);
		zephir_is_iterable(&tmp, 0, "ice/cli/websocket/server.zep", 187);
		if (Z_TYPE_P(&tmp) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmp), _32$$8)
			{
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _32$$8);
				ZEPHIR_INIT_NVAR(&_34$$9);
				zephir_fast_trim(&_34$$9, &value, NULL , ZEPHIR_TRIM_BOTH);
				_35$$9 = !ZEPHIR_IS_STRING_IDENTICAL(&_34$$9, "");
				if (_35$$9) {
					ZEPHIR_INIT_NVAR(&_36$$9);
					ZVAL_STRING(&_36$$9, "=");
					ZEPHIR_INIT_NVAR(&_37$$9);
					zephir_fast_strpos(&_37$$9, &value, &_36$$9, 0 );
					_35$$9 = !ZEPHIR_IS_FALSE_IDENTICAL(&_37$$9);
				}
				if (_35$$9) {
					ZEPHIR_INIT_NVAR(&_38$$10);
					zephir_fast_explode_str(&_38$$10, SL("="), &value, 2 );
					ZEPHIR_CPY_WRT(&value, &_38$$10);
					zephir_array_fetch_long(&_39$$10, &value, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 184);
					ZEPHIR_INIT_NVAR(&_38$$10);
					zephir_array_fetch_long(&_40$$10, &value, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 184);
					zephir_fast_trim(&_38$$10, &_40$$10, NULL , ZEPHIR_TRIM_BOTH);
					zephir_array_update_zval(&cookies, &_38$$10, &_39$$10, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &tmp, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_33$$8, &tmp, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_33$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&value, &tmp, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_41$$11);
					zephir_fast_trim(&_41$$11, &value, NULL , ZEPHIR_TRIM_BOTH);
					_42$$11 = !ZEPHIR_IS_STRING_IDENTICAL(&_41$$11, "");
					if (_42$$11) {
						ZEPHIR_INIT_NVAR(&_43$$11);
						ZVAL_STRING(&_43$$11, "=");
						ZEPHIR_INIT_NVAR(&_44$$11);
						zephir_fast_strpos(&_44$$11, &value, &_43$$11, 0 );
						_42$$11 = !ZEPHIR_IS_FALSE_IDENTICAL(&_44$$11);
					}
					if (_42$$11) {
						ZEPHIR_INIT_NVAR(&_45$$12);
						zephir_fast_explode_str(&_45$$12, SL("="), &value, 2 );
						ZEPHIR_CPY_WRT(&value, &_45$$12);
						zephir_array_fetch_long(&_46$$12, &value, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 184);
						ZEPHIR_INIT_NVAR(&_45$$12);
						zephir_array_fetch_long(&_47$$12, &value, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 184);
						zephir_fast_trim(&_45$$12, &_47$$12, NULL , ZEPHIR_TRIM_BOTH);
						zephir_array_update_zval(&cookies, &_45$$12, &_46$$12, PH_COPY | PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, &tmp, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
	}
	ZEPHIR_INIT_VAR(&client);
	zephir_create_array(&client, 4, 0);
	zephir_array_update_string(&client, SL("socket"), socket, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&client, SL("headers"), &headers, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_48);
	zephir_array_fetch_long(&_48, &request, 1, PH_NOISY, "ice/cli/websocket/server.zep", 192);
	zephir_array_update_string(&client, SL("resource"), &_48, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&client, SL("cookies"), &cookies, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_49, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
	_50 = zephir_array_isset_string(&_49, SL("validate"));
	if (_50) {
		zephir_read_property(&_51, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_52, &_51, SL("validate"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 196);
		ZEPHIR_CALL_FUNCTION(&_53, "call_user_func", NULL, 76, &_52, &client, this_ptr);
		zephir_check_call_status();
		_50 = !zephir_is_true(&_53);
	}
	if (_50) {
		ZEPHIR_INIT_VAR(&_54$$13);
		ZVAL_STRING(&_54$$13, "HTTP/1.1 400 Bad Request\r\n\r\n");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, socket, &_54$$13);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&response);
	zephir_create_array(&response, 6, 0);
	ZEPHIR_INIT_VAR(&_55);
	ZVAL_STRING(&_55, "HTTP/1.1 101 WebSocket Protocol Handshake");
	zephir_array_fast_append(&response, &_55);
	ZEPHIR_INIT_NVAR(&_55);
	ZVAL_STRING(&_55, "Upgrade: WebSocket");
	zephir_array_fast_append(&response, &_55);
	ZEPHIR_INIT_NVAR(&_55);
	ZVAL_STRING(&_55, "Connection: Upgrade");
	zephir_array_fast_append(&response, &_55);
	ZEPHIR_INIT_NVAR(&_55);
	ZVAL_STRING(&_55, "Sec-WebSocket-Version: 13");
	zephir_array_fast_append(&response, &_55);
	zephir_read_property(&_56, this_ptr, SL("address"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_57);
	ZEPHIR_CONCAT_SV(&_57, "Sec-WebSocket-Location: ", &_56);
	zephir_array_fast_append(&response, &_57);
	zephir_array_fetch_string(&_58, &headers, SL("sec-websocket-key"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 208);
	ZEPHIR_OBS_VAR(&_59);
	zephir_read_static_property_ce(&_59, ice_cli_websocket_server_ce, SL("magic"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(&_57);
	ZEPHIR_CONCAT_VV(&_57, &_58, &_59);
	ZEPHIR_CALL_FUNCTION(&_60, "sha1", NULL, 58, &_57, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_61, "base64_encode", NULL, 14, &_60);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_62);
	ZEPHIR_CONCAT_SV(&_62, "Sec-WebSocket-Accept: ", &_61);
	zephir_array_fast_append(&response, &_62);
	if (zephir_array_isset_string(&headers, SL("origin"))) {
		zephir_array_fetch_string(&_63$$14, &headers, SL("origin"), PH_NOISY | PH_READONLY, "ice/cli/websocket/server.zep", 212);
		ZEPHIR_INIT_VAR(&_64$$14);
		ZEPHIR_CONCAT_SV(&_64$$14, "Sec-WebSocket-Origin: ", &_63$$14);
		zephir_array_append(&response, &_64$$14, PH_SEPARATE, "ice/cli/websocket/server.zep", 212);
	}
	ZEPHIR_INIT_NVAR(&_55);
	ZVAL_LONG(&_55, zephir_get_intval(socket));
	zephir_update_property_array(this_ptr, SL("sockets"), &_55, socket);
	ZEPHIR_INIT_VAR(&_65);
	ZVAL_LONG(&_65, zephir_get_intval(socket));
	zephir_update_property_array(this_ptr, SL("clients"), &_65, &client);
	ZEPHIR_INIT_VAR(&_66);
	zephir_fast_join_str(&_66, SL("\r\n"), &response);
	ZEPHIR_INIT_NVAR(&_62);
	ZEPHIR_CONCAT_VS(&_62, &_66, "\r\n\r\n");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "sendclear", NULL, 0, socket, &_62);
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

	zephir_fetch_params_without_memory_grow(1, 0, &socket);



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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *callback, callback_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&callback_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &callback);

	zephir_get_strval(&key, key_param);


	zephir_update_property_array(this_ptr, SL("callbacks"), &key, callback);
	RETURN_THIS();

}

zend_object *zephir_init_properties_Ice_Cli_Websocket_Server(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

