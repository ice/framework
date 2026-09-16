
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
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Websocket_Server)
{
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

PHP_METHOD(Ice_Cli_Websocket_Server, setVerbose)
{
	zval *verbose, verbose_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&verbose_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("verbose", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(verbose)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &verbose);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 122, verbose);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cli_Websocket_Server, getAddress)
{

	RETURN_MEMBER(getThis(), "address");
}

PHP_METHOD(Ice_Cli_Websocket_Server, getServer)
{

	RETURN_MEMBER(getThis(), "server");
}

PHP_METHOD(Ice_Cli_Websocket_Server, getClients)
{

	RETURN_MEMBER(getThis(), "clients");
}

/**
 * Create an instance.
 *
 * @param string address Where to create the server, defaults to "ws://127.0.0.1:8080"
 * @param array options Stream context options
 */
PHP_METHOD(Ice_Cli_Websocket_Server, __construct)
{
	zend_ulong _4$$4;
	zend_bool _0, _1, _2, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _13;
	zval address_zv, *options_param = NULL, addr, context, key, value, _11, _12, _14, _15, _16, _17, _18, _19, _20, _21, *_3$$4, _8$$4, _6$$5, _10$$6;
	zend_string *address = NULL, *_5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&address_zv);
	ZVAL_UNDEF(&addr);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_13);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("address", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("server", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(address)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		options_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (!address) {
		address = zend_string_init(ZEND_STRL("ws://127.0.0.1:8080"), 0);
		zephir_memory_observe(&address_zv);
		ZVAL_STR(&address_zv, address);
	} else {
		zephir_memory_observe(&address_zv);
	ZVAL_STR_COPY(&address_zv, address);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_CALL_FUNCTION(&addr, "parse_url", NULL, 81, &address_zv);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_FALSE_IDENTICAL(&addr);
	if (!(_0)) {
		_0 = !(zephir_array_isset_value_string(&addr, SL("scheme")));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = !(zephir_array_isset_value_string(&addr, SL("host")));
	}
	_2 = _1;
	if (!(_2)) {
		_2 = !(zephir_array_isset_value_string(&addr, SL("port")));
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid address", "ice/cli/websocket/server.zep", 37);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&context, "stream_context_create", NULL, 89);
	zephir_check_call_status();
	if (zephir_fast_count_int(&options)) {
		zephir_is_iterable(&options, 0, "ice/cli/websocket/server.zep", 46);
		if (Z_TYPE_P(&options) == IS_ARRAY) {
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
				ZEPHIR_CALL_FUNCTION(NULL, "stream_context_set_option", &_7, 90, &context, &_6$$5, &key, &value);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
			zephir_check_call_status();
			_9$$4 = 1;
			while (1) {
				if (_9$$4) {
					_9$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_8$$4, &options, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_10$$6);
					ZVAL_STRING(&_10$$6, "ssl");
					ZEPHIR_CALL_FUNCTION(NULL, "stream_context_set_option", &_7, 90, &context, &_10$$6, &key, &value);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 123, &address_zv);
	ZEPHIR_INIT_VAR(&_11);
	zephir_memory_observe(&_12);
	zephir_array_fetch_string(&_12, &addr, SL("scheme"), PH_NOISY, "ice/cli/websocket/server.zep", 51);
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 2, 0);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "wss");
	zephir_array_fast_append(&_13, &_14);
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "tls");
	zephir_array_fast_append(&_13, &_14);
	if (zephir_fast_in_array(&_12, &_13)) {
		ZEPHIR_INIT_NVAR(&_11);
		ZVAL_STRING(&_11, "tls");
	} else {
		ZEPHIR_INIT_NVAR(&_11);
		ZVAL_STRING(&_11, "tcp");
	}
	zephir_memory_observe(&_15);
	zephir_array_fetch_string(&_15, &addr, SL("host"), PH_NOISY, "ice/cli/websocket/server.zep", 51);
	zephir_memory_observe(&_16);
	zephir_array_fetch_string(&_16, &addr, SL("port"), PH_NOISY, "ice/cli/websocket/server.zep", 51);
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_CONCAT_VSVSV(&_17, &_11, "://", &_15, ":", &_16);
	ZVAL_NULL(&_18);
	ZVAL_NULL(&_19);
	ZVAL_LONG(&_20, (4 | 8));
	ZEPHIR_MAKE_REF(&_18);
	ZEPHIR_MAKE_REF(&_19);
	ZEPHIR_CALL_FUNCTION(&_21, "stream_socket_server", NULL, 91, &_17, &_18, &_19, &_20, &context);
	ZEPHIR_UNREF(&_18);
	ZEPHIR_UNREF(&_19);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 124, &_21);
	zephir_read_property_cached(&_18, this_ptr, _zephir_prop_1, 124, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_18)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Could not create server", "ice/cli/websocket/server.zep", 59);
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Start processing requests. This method runs in an infinite loop.
 *
 * @return void
 */
PHP_METHOD(Ice_Cli_Websocket_Server, run)
{
	zval _26$$13, _34$$16, _48$$22, _55$$25;
	zend_bool _38$$7, _25$$13, _47$$22;
	zval changed, write, except, stream, messages, message, socket, tmp, _0, _1$$3, _2$$3, _4$$4, _8$$4, _9$$4, _66$$4, _67$$4, _68$$4, _5$$5, _6$$5, _7$$5, *_11$$7, _12$$7, *_13$$7, _37$$7, *_58$$7, _59$$7, *_60$$7, _14$$8, _15$$9, _17$$10, _19$$11, _20$$12, _21$$12, _22$$12, _23$$12, _27$$13, _28$$14, _29$$15, _30$$15, _31$$15, _32$$15, _35$$16, _36$$16, _39$$17, _40$$18, _41$$19, _42$$20, _43$$21, _44$$21, _45$$21, _46$$21, _49$$22, _50$$23, _51$$24, _52$$24, _53$$24, _54$$24, _56$$25, _57$$25, _61$$26, _62$$27, _63$$27, _64$$27, _65$$27;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_10 = NULL, *_16 = NULL, *_18 = NULL, *_24 = NULL, *_33 = NULL, *_69 = NULL, *_70 = NULL;
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
	ZVAL_UNDEF(&_66$$4);
	ZVAL_UNDEF(&_67$$4);
	ZVAL_UNDEF(&_68$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_37$$7);
	ZVAL_UNDEF(&_59$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_35$$16);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_40$$18);
	ZVAL_UNDEF(&_41$$19);
	ZVAL_UNDEF(&_42$$20);
	ZVAL_UNDEF(&_43$$21);
	ZVAL_UNDEF(&_44$$21);
	ZVAL_UNDEF(&_45$$21);
	ZVAL_UNDEF(&_46$$21);
	ZVAL_UNDEF(&_49$$22);
	ZVAL_UNDEF(&_50$$23);
	ZVAL_UNDEF(&_51$$24);
	ZVAL_UNDEF(&_52$$24);
	ZVAL_UNDEF(&_53$$24);
	ZVAL_UNDEF(&_54$$24);
	ZVAL_UNDEF(&_56$$25);
	ZVAL_UNDEF(&_57$$25);
	ZVAL_UNDEF(&_61$$26);
	ZVAL_UNDEF(&_62$$27);
	ZVAL_UNDEF(&_63$$27);
	ZVAL_UNDEF(&_64$$27);
	ZVAL_UNDEF(&_65$$27);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_48$$22);
	ZVAL_UNDEF(&_55$$25);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("server", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("callbacks", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("sockets", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("clients", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 124, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_array_append(this_ptr, SL("sockets"), &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value_string(&_0, SL("boot"))) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_2$$3);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("boot"), PH_NOISY, "ice/cli/websocket/server.zep", 75);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 87, &_2$$3, this_ptr);
		zephir_check_call_status();
	}
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_4$$4, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value_string(&_4$$4, SL("tick"))) {
			zephir_read_property_cached(&_5$$5, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&_6$$5);
			zephir_array_fetch_string(&_6$$5, &_5$$5, SL("tick"), PH_NOISY, "ice/cli/websocket/server.zep", 80);
			ZEPHIR_CALL_FUNCTION(&_7$$5, "call_user_func", &_3, 87, &_6$$5, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$5)) {
				break;
			}
		}
		ZEPHIR_OBS_NVAR(&changed);
		zephir_read_property_cached(&changed, this_ptr, _zephir_prop_2, 126, PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&write);
		array_init(&write);
		ZEPHIR_INIT_NVAR(&except);
		array_init(&except);
		ZEPHIR_INIT_NVAR(&_8$$4);
		zephir_read_property_cached(&_9$$4, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value_string(&_9$$4, SL("tick"))) {
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_LONG(&_8$$4, 0);
		} else {
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_NULL(&_8$$4);
		}
		ZEPHIR_MAKE_REF(&changed);
		ZEPHIR_MAKE_REF(&write);
		ZEPHIR_MAKE_REF(&except);
		ZEPHIR_CALL_FUNCTION(&stream, "stream_select", &_10, 88, &changed, &write, &except, &_8$$4);
		ZEPHIR_UNREF(&changed);
		ZEPHIR_UNREF(&write);
		ZEPHIR_UNREF(&except);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&stream, 0)) {
			ZEPHIR_INIT_NVAR(&messages);
			array_init(&messages);
			if (Z_TYPE_P(&changed) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_12$$7);
				zephir_string_to_char_array(&_12$$7, &changed);
				_11$$7 = &_12$$7;
			} else {
				_11$$7 = &changed;
			}
			zephir_is_iterable(_11$$7, 0, "ice/cli/websocket/server.zep", 122);
			if (Z_TYPE_P(_11$$7) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11$$7), _13$$7)
				{
					ZEPHIR_INIT_NVAR(&socket);
					ZVAL_COPY(&socket, _13$$7);
					zephir_read_property_cached(&_14$$8, this_ptr, _zephir_prop_0, 124, PH_NOISY_CC | PH_READONLY);
					if (ZEPHIR_IS_IDENTICAL(&socket, &_14$$8)) {
						zephir_read_property_cached(&_15$$9, this_ptr, _zephir_prop_0, 124, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_FUNCTION(&tmp, "stream_socket_accept", &_16, 92, &_15$$9);
						zephir_check_call_status();
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&tmp)) {
							ZEPHIR_CALL_METHOD(&_17$$10, this_ptr, "connect", &_18, 0, &tmp);
							zephir_check_call_status();
							if (zephir_is_true(&_17$$10)) {
								zephir_read_property_cached(&_19$$11, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
								if (zephir_array_isset_value_string(&_19$$11, SL("connect"))) {
									zephir_read_property_cached(&_20$$12, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_OBS_NVAR(&_21$$12);
									zephir_array_fetch_string(&_21$$12, &_20$$12, SL("connect"), PH_NOISY, "ice/cli/websocket/server.zep", 100);
									zephir_read_property_cached(&_22$$12, this_ptr, _zephir_prop_3, 127, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_OBS_NVAR(&_23$$12);
									zephir_array_fetch_long(&_23$$12, &_22$$12, zephir_get_intval(&tmp), PH_NOISY, "ice/cli/websocket/server.zep", 100);
									ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 87, &_21$$12, &_23$$12, this_ptr);
									zephir_check_call_status();
								}
							}
						}
					} else {
						ZEPHIR_CALL_METHOD(&message, this_ptr, "receive", &_24, 0, &socket);
						zephir_check_call_status();
						_25$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&message);
						if (!(_25$$13)) {
							ZEPHIR_INIT_NVAR(&_26$$13);
							zephir_create_array(&_26$$13, 3, 0);
							ZEPHIR_INIT_NVAR(&_27$$13);
							ZVAL_STRING(&_27$$13, "quit");
							zephir_array_fast_append(&_26$$13, &_27$$13);
							ZEPHIR_INIT_NVAR(&_27$$13);
							ZVAL_STRING(&_27$$13, "exit");
							zephir_array_fast_append(&_26$$13, &_27$$13);
							ZEPHIR_INIT_NVAR(&_27$$13);
							ZVAL_STRING(&_27$$13, "close");
							zephir_array_fast_append(&_26$$13, &_27$$13);
							_25$$13 = zephir_fast_in_array(&message, &_26$$13);
						}
						if (_25$$13) {
							zephir_read_property_cached(&_28$$14, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
							if (zephir_array_isset_value_string(&_28$$14, SL("disconnect"))) {
								zephir_read_property_cached(&_29$$15, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_OBS_NVAR(&_30$$15);
								zephir_array_fetch_string(&_30$$15, &_29$$15, SL("disconnect"), PH_NOISY, "ice/cli/websocket/server.zep", 109);
								zephir_read_property_cached(&_31$$15, this_ptr, _zephir_prop_3, 127, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_OBS_NVAR(&_32$$15);
								zephir_array_fetch_long(&_32$$15, &_31$$15, zephir_get_intval(&socket), PH_NOISY, "ice/cli/websocket/server.zep", 109);
								ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 87, &_30$$15, &_32$$15, this_ptr);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", &_33, 0, &socket);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&_34$$16);
							zephir_create_array(&_34$$16, 2, 0);
							zephir_read_property_cached(&_35$$16, this_ptr, _zephir_prop_3, 127, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&_36$$16);
							zephir_array_fetch_long(&_36$$16, &_35$$16, zephir_get_intval(&socket), PH_NOISY, "ice/cli/websocket/server.zep", 115);
							zephir_array_update_string(&_34$$16, SL("client"), &_36$$16, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_34$$16, SL("message"), &message, PH_COPY | PH_SEPARATE);
							zephir_array_append(&messages, &_34$$16, PH_SEPARATE, "ice/cli/websocket/server.zep", 117);
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _11$$7, "rewind", NULL, 0);
				zephir_check_call_status();
				_38$$7 = 1;
				while (1) {
					if (_38$$7) {
						_38$$7 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _11$$7, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_37$$7, _11$$7, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_37$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&socket, _11$$7, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property_cached(&_39$$17, this_ptr, _zephir_prop_0, 124, PH_NOISY_CC | PH_READONLY);
						if (ZEPHIR_IS_IDENTICAL(&socket, &_39$$17)) {
							zephir_read_property_cached(&_40$$18, this_ptr, _zephir_prop_0, 124, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_FUNCTION(&tmp, "stream_socket_accept", &_16, 92, &_40$$18);
							zephir_check_call_status();
							if (!ZEPHIR_IS_FALSE_IDENTICAL(&tmp)) {
								ZEPHIR_CALL_METHOD(&_41$$19, this_ptr, "connect", &_18, 0, &tmp);
								zephir_check_call_status();
								if (zephir_is_true(&_41$$19)) {
									zephir_read_property_cached(&_42$$20, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
									if (zephir_array_isset_value_string(&_42$$20, SL("connect"))) {
										zephir_read_property_cached(&_43$$21, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
										ZEPHIR_OBS_NVAR(&_44$$21);
										zephir_array_fetch_string(&_44$$21, &_43$$21, SL("connect"), PH_NOISY, "ice/cli/websocket/server.zep", 100);
										zephir_read_property_cached(&_45$$21, this_ptr, _zephir_prop_3, 127, PH_NOISY_CC | PH_READONLY);
										ZEPHIR_OBS_NVAR(&_46$$21);
										zephir_array_fetch_long(&_46$$21, &_45$$21, zephir_get_intval(&tmp), PH_NOISY, "ice/cli/websocket/server.zep", 100);
										ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 87, &_44$$21, &_46$$21, this_ptr);
										zephir_check_call_status();
									}
								}
							}
						} else {
							ZEPHIR_CALL_METHOD(&message, this_ptr, "receive", &_24, 37, &socket);
							zephir_check_call_status();
							_47$$22 = ZEPHIR_IS_FALSE_IDENTICAL(&message);
							if (!(_47$$22)) {
								ZEPHIR_INIT_NVAR(&_48$$22);
								zephir_create_array(&_48$$22, 3, 0);
								ZEPHIR_INIT_NVAR(&_49$$22);
								ZVAL_STRING(&_49$$22, "quit");
								zephir_array_fast_append(&_48$$22, &_49$$22);
								ZEPHIR_INIT_NVAR(&_49$$22);
								ZVAL_STRING(&_49$$22, "exit");
								zephir_array_fast_append(&_48$$22, &_49$$22);
								ZEPHIR_INIT_NVAR(&_49$$22);
								ZVAL_STRING(&_49$$22, "close");
								zephir_array_fast_append(&_48$$22, &_49$$22);
								_47$$22 = zephir_fast_in_array(&message, &_48$$22);
							}
							if (_47$$22) {
								zephir_read_property_cached(&_50$$23, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
								if (zephir_array_isset_value_string(&_50$$23, SL("disconnect"))) {
									zephir_read_property_cached(&_51$$24, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_OBS_NVAR(&_52$$24);
									zephir_array_fetch_string(&_52$$24, &_51$$24, SL("disconnect"), PH_NOISY, "ice/cli/websocket/server.zep", 109);
									zephir_read_property_cached(&_53$$24, this_ptr, _zephir_prop_3, 127, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_OBS_NVAR(&_54$$24);
									zephir_array_fetch_long(&_54$$24, &_53$$24, zephir_get_intval(&socket), PH_NOISY, "ice/cli/websocket/server.zep", 109);
									ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 87, &_52$$24, &_54$$24, this_ptr);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", &_33, 0, &socket);
								zephir_check_call_status();
							} else {
								ZEPHIR_INIT_NVAR(&_55$$25);
								zephir_create_array(&_55$$25, 2, 0);
								zephir_read_property_cached(&_56$$25, this_ptr, _zephir_prop_3, 127, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_OBS_NVAR(&_57$$25);
								zephir_array_fetch_long(&_57$$25, &_56$$25, zephir_get_intval(&socket), PH_NOISY, "ice/cli/websocket/server.zep", 115);
								zephir_array_update_string(&_55$$25, SL("client"), &_57$$25, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_55$$25, SL("message"), &message, PH_COPY | PH_SEPARATE);
								zephir_array_append(&messages, &_55$$25, PH_SEPARATE, "ice/cli/websocket/server.zep", 117);
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&socket);
			if (Z_TYPE_P(&messages) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_59$$7);
				zephir_string_to_char_array(&_59$$7, &messages);
				_58$$7 = &_59$$7;
			} else {
				_58$$7 = &messages;
			}
			zephir_is_iterable(_58$$7, 0, "ice/cli/websocket/server.zep", 127);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_58$$7), _60$$7)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _60$$7);
				zephir_read_property_cached(&_61$$26, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset_value_string(&_61$$26, SL("message"))) {
					zephir_read_property_cached(&_62$$27, this_ptr, _zephir_prop_1, 125, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_63$$27);
					zephir_array_fetch_string(&_63$$27, &_62$$27, SL("message"), PH_NOISY, "ice/cli/websocket/server.zep", 124);
					ZEPHIR_OBS_NVAR(&_64$$27);
					zephir_array_fetch_string(&_64$$27, &message, SL("client"), PH_NOISY, "ice/cli/websocket/server.zep", 124);
					ZEPHIR_OBS_NVAR(&_65$$27);
					zephir_array_fetch_string(&_65$$27, &message, SL("message"), PH_NOISY, "ice/cli/websocket/server.zep", 124);
					ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_3, 87, &_63$$27, &_64$$27, &_65$$27, this_ptr);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&message);
		}
		ZEPHIR_INIT_NVAR(&_67$$4);
		ZVAL_STRING(&_67$$4, "sleep");
		ZVAL_LONG(&_68$$4, 5000);
		ZEPHIR_CALL_METHOD(&_66$$4, this_ptr, "getparam", &_69, 0, &_67$$4, &_68$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_70, 33, &_66$$4);
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
PHP_METHOD(Ice_Cli_Websocket_Server, connect)
{
	zend_bool _17, _23, _24, _25, _28, _47, _39$$9;
	zval _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *socket, socket_sub, __$true, headers, header, request, tmp, cookies, value, client, response, _0, _2, _4, _5, _6, _7, *_9, *_10, _16, _26, _27, _29, _30, _31, _32, _45, _46, _48, _49, _51, _52, _53, _54, _55, _56, _57, _58, _61, _62, _8$$4, _11$$5, _12$$5, _13$$5, _14$$5, _15$$5, _18$$6, _19$$6, _20$$6, _21$$6, _22$$6, _33$$7, _34$$8, *_35$$8, _36$$8, *_37$$8, _38$$9, _40$$9, _41$$9, _42$$10, _43$$10, _44$$10, _50$$11, _59$$12, _60$$12;
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
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_53);
	ZVAL_UNDEF(&_54);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_56);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_61);
	ZVAL_UNDEF(&_62);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_59$$12);
	ZVAL_UNDEF(&_60$$12);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("callbacks", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("address", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_RESOURCE(socket)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_CALL_FUNCTION(&_5, "preg_replace", NULL, 53, &_2, &_4, &headers);
	zephir_check_call_status();
	zephir_fast_explode_str(&_0, SL("\r\n"), &_5, ZEND_LONG_MAX);
	ZEPHIR_CALL_FUNCTION(&headers, "array_filter", NULL, 8, &_0);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&headers);
	ZEPHIR_CALL_FUNCTION(&_6, "array_shift", NULL, 2, &headers);
	ZEPHIR_UNREF(&headers);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&request);
	zephir_fast_explode_str(&request, SL(" "), &_6, ZEND_LONG_MAX);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_memory_observe(&_7);
	zephir_array_fetch_long(&_7, &request, 0, PH_NOISY, "ice/cli/websocket/server.zep", 153);
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
	if (Z_TYPE_P(&headers) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_4);
		zephir_string_to_char_array(&_4, &headers);
		_9 = &_4;
	} else {
		_9 = &headers;
	}
	zephir_is_iterable(_9, 0, "ice/cli/websocket/server.zep", 166);
	if (Z_TYPE_P(_9) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9), _10)
		{
			ZEPHIR_INIT_NVAR(&header);
			ZVAL_COPY(&header, _10);
			ZEPHIR_INIT_NVAR(&_11$$5);
			zephir_fast_explode_str(&_11$$5, SL(":"), &header, 2 );
			ZEPHIR_CPY_WRT(&header, &_11$$5);
			ZEPHIR_INIT_NVAR(&_11$$5);
			ZEPHIR_OBS_NVAR(&_12$$5);
			zephir_array_fetch_long(&_12$$5, &header, 1, PH_NOISY, "ice/cli/websocket/server.zep", 163);
			zephir_fast_trim(&_11$$5, &_12$$5, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_NVAR(&_13$$5);
			ZEPHIR_INIT_NVAR(&_14$$5);
			ZEPHIR_OBS_NVAR(&_15$$5);
			zephir_array_fetch_long(&_15$$5, &header, 0, PH_NOISY, "ice/cli/websocket/server.zep", 163);
			zephir_fast_strtolower(&_14$$5, &_15$$5);
			zephir_fast_trim(&_13$$5, &_14$$5, NULL , ZEPHIR_TRIM_BOTH);
			zephir_array_update_zval(&tmp, &_13$$5, &_11$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _9, "rewind", NULL, 0);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _9, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, _9, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&header, _9, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$6);
				zephir_fast_explode_str(&_18$$6, SL(":"), &header, 2 );
				ZEPHIR_CPY_WRT(&header, &_18$$6);
				ZEPHIR_INIT_NVAR(&_18$$6);
				ZEPHIR_OBS_NVAR(&_19$$6);
				zephir_array_fetch_long(&_19$$6, &header, 1, PH_NOISY, "ice/cli/websocket/server.zep", 163);
				zephir_fast_trim(&_18$$6, &_19$$6, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_INIT_NVAR(&_20$$6);
				ZEPHIR_INIT_NVAR(&_21$$6);
				ZEPHIR_OBS_NVAR(&_22$$6);
				zephir_array_fetch_long(&_22$$6, &header, 0, PH_NOISY, "ice/cli/websocket/server.zep", 163);
				zephir_fast_strtolower(&_21$$6, &_22$$6);
				zephir_fast_trim(&_20$$6, &_21$$6, NULL , ZEPHIR_TRIM_BOTH);
				zephir_array_update_zval(&tmp, &_20$$6, &_18$$6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&header);
	ZEPHIR_CPY_WRT(&headers, &tmp);
	_23 = !(zephir_array_isset_value_string(&headers, SL("sec-websocket-key")));
	if (!(_23)) {
		_23 = !(zephir_array_isset_value_string(&headers, SL("upgrade")));
	}
	_24 = _23;
	if (!(_24)) {
		_24 = !(zephir_array_isset_value_string(&headers, SL("connection")));
	}
	_25 = _24;
	if (!(_25)) {
		ZEPHIR_INIT_VAR(&_26);
		zephir_memory_observe(&_27);
		zephir_array_fetch_string(&_27, &headers, SL("upgrade"), PH_NOISY, "ice/cli/websocket/server.zep", 169);
		zephir_fast_strtolower(&_26, &_27);
		_25 = !ZEPHIR_IS_STRING(&_26, "websocket");
	}
	_28 = _25;
	if (!(_28)) {
		ZEPHIR_INIT_VAR(&_29);
		zephir_memory_observe(&_30);
		zephir_array_fetch_string(&_30, &headers, SL("connection"), PH_NOISY, "ice/cli/websocket/server.zep", 169);
		zephir_fast_strtolower(&_29, &_30);
		ZEPHIR_INIT_VAR(&_31);
		ZVAL_STRING(&_31, "upgrade");
		ZEPHIR_INIT_VAR(&_32);
		zephir_fast_strpos(&_32, &_29, &_31, 0 );
		_28 = ZEPHIR_IS_FALSE_IDENTICAL(&_32);
	}
	if (_28) {
		ZEPHIR_INIT_VAR(&_33$$7);
		ZVAL_STRING(&_33$$7, "HTTP/1.1 400 Bad Request\r\n\r\n");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, socket, &_33$$7);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&cookies);
	array_init(&cookies);
	if (zephir_array_isset_value_string(&headers, SL("cookie"))) {
		zephir_memory_observe(&_34$$8);
		zephir_array_fetch_string(&_34$$8, &headers, SL("cookie"), PH_NOISY, "ice/cli/websocket/server.zep", 178);
		ZEPHIR_INIT_NVAR(&tmp);
		zephir_fast_explode_str(&tmp, SL(";"), &_34$$8, ZEND_LONG_MAX);
		if (Z_TYPE_P(&tmp) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_36$$8);
			zephir_string_to_char_array(&_36$$8, &tmp);
			_35$$8 = &_36$$8;
		} else {
			_35$$8 = &tmp;
		}
		zephir_is_iterable(_35$$8, 0, "ice/cli/websocket/server.zep", 186);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_35$$8), _37$$8)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _37$$8);
			ZEPHIR_INIT_NVAR(&_38$$9);
			zephir_fast_trim(&_38$$9, &value, NULL , ZEPHIR_TRIM_BOTH);
			_39$$9 = !ZEPHIR_IS_STRING_IDENTICAL(&_38$$9, "");
			if (_39$$9) {
				ZEPHIR_INIT_NVAR(&_40$$9);
				ZVAL_STRING(&_40$$9, "=");
				ZEPHIR_INIT_NVAR(&_41$$9);
				zephir_fast_strpos(&_41$$9, &value, &_40$$9, 0 );
				_39$$9 = !ZEPHIR_IS_FALSE_IDENTICAL(&_41$$9);
			}
			if (_39$$9) {
				ZEPHIR_INIT_NVAR(&_42$$10);
				zephir_fast_explode_str(&_42$$10, SL("="), &value, 2 );
				ZEPHIR_CPY_WRT(&value, &_42$$10);
				ZEPHIR_OBS_NVAR(&_43$$10);
				zephir_array_fetch_long(&_43$$10, &value, 1, PH_NOISY, "ice/cli/websocket/server.zep", 183);
				ZEPHIR_INIT_NVAR(&_42$$10);
				ZEPHIR_OBS_NVAR(&_44$$10);
				zephir_array_fetch_long(&_44$$10, &value, 0, PH_NOISY, "ice/cli/websocket/server.zep", 183);
				zephir_fast_trim(&_42$$10, &_44$$10, NULL , ZEPHIR_TRIM_BOTH);
				zephir_array_update_zval(&cookies, &_42$$10, &_43$$10, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
	}
	ZEPHIR_INIT_VAR(&client);
	zephir_create_array(&client, 4, 0);
	zephir_array_update_string(&client, SL("socket"), socket, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&client, SL("headers"), &headers, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_45);
	zephir_array_fetch_long(&_45, &request, 1, PH_NOISY, "ice/cli/websocket/server.zep", 191);
	zephir_array_update_string(&client, SL("resource"), &_45, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&client, SL("cookies"), &cookies, PH_COPY | PH_SEPARATE);
	zephir_read_property_cached(&_46, this_ptr, _zephir_prop_0, 125, PH_NOISY_CC | PH_READONLY);
	_47 = zephir_array_isset_value_string(&_46, SL("validate"));
	if (_47) {
		zephir_read_property_cached(&_48, this_ptr, _zephir_prop_0, 125, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_45);
		zephir_array_fetch_string(&_45, &_48, SL("validate"), PH_NOISY, "ice/cli/websocket/server.zep", 195);
		ZEPHIR_CALL_FUNCTION(&_49, "call_user_func", NULL, 87, &_45, &client, this_ptr);
		zephir_check_call_status();
		_47 = !zephir_is_true(&_49);
	}
	if (_47) {
		ZEPHIR_INIT_VAR(&_50$$11);
		ZVAL_STRING(&_50$$11, "HTTP/1.1 400 Bad Request\r\n\r\n");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendclear", NULL, 0, socket, &_50$$11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&response);
	zephir_create_array(&response, 6, 0);
	ZEPHIR_INIT_VAR(&_51);
	ZVAL_STRING(&_51, "HTTP/1.1 101 WebSocket Protocol Handshake");
	zephir_array_fast_append(&response, &_51);
	ZEPHIR_INIT_NVAR(&_51);
	ZVAL_STRING(&_51, "Upgrade: WebSocket");
	zephir_array_fast_append(&response, &_51);
	ZEPHIR_INIT_NVAR(&_51);
	ZVAL_STRING(&_51, "Connection: Upgrade");
	zephir_array_fast_append(&response, &_51);
	ZEPHIR_INIT_NVAR(&_51);
	ZVAL_STRING(&_51, "Sec-WebSocket-Version: 13");
	zephir_array_fast_append(&response, &_51);
	zephir_read_property_cached(&_52, this_ptr, _zephir_prop_1, 123, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_53);
	ZEPHIR_CONCAT_SV(&_53, "Sec-WebSocket-Location: ", &_52);
	zephir_array_fast_append(&response, &_53);
	zephir_memory_observe(&_54);
	zephir_array_fetch_string(&_54, &headers, SL("sec-websocket-key"), PH_NOISY, "ice/cli/websocket/server.zep", 207);
	zephir_memory_observe(&_55);
	zephir_read_static_property_ce(&_55, ice_cli_websocket_server_ce, SL("magic"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(&_53);
	ZEPHIR_CONCAT_VV(&_53, &_54, &_55);
	ZEPHIR_CALL_FUNCTION(&_56, "sha1", NULL, 68, &_53, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_57, "base64_encode", NULL, 15, &_56);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_58);
	ZEPHIR_CONCAT_SV(&_58, "Sec-WebSocket-Accept: ", &_57);
	zephir_array_fast_append(&response, &_58);
	if (zephir_array_isset_value_string(&headers, SL("origin"))) {
		zephir_memory_observe(&_59$$12);
		zephir_array_fetch_string(&_59$$12, &headers, SL("origin"), PH_NOISY, "ice/cli/websocket/server.zep", 211);
		ZEPHIR_INIT_VAR(&_60$$12);
		ZEPHIR_CONCAT_SV(&_60$$12, "Sec-WebSocket-Origin: ", &_59$$12);
		zephir_array_append(&response, &_60$$12, PH_SEPARATE, "ice/cli/websocket/server.zep", 211);
	}
	ZEPHIR_INIT_NVAR(&_51);
	ZVAL_LONG(&_51, zephir_get_intval(socket));
	zephir_update_property_array(this_ptr, SL("sockets"), &_51, socket);
	ZEPHIR_INIT_VAR(&_61);
	ZVAL_LONG(&_61, zephir_get_intval(socket));
	zephir_update_property_array(this_ptr, SL("clients"), &_61, &client);
	ZEPHIR_INIT_VAR(&_62);
	zephir_fast_join_str(&_62, SL("\r\n"), &response);
	ZEPHIR_INIT_NVAR(&_58);
	ZEPHIR_CONCAT_VS(&_58, &_62, "\r\n\r\n");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "sendclear", NULL, 0, socket, &_58);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Disconnect a socket from the server.
 *
 * @param resource socket The resource
 * @return void
 */
PHP_METHOD(Ice_Cli_Websocket_Server, disconnect)
{
	zval *socket, socket_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&socket_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("clients", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("sockets", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_RESOURCE(socket)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &socket);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 127, PH_NOISY_CC | PH_READONLY);
	zephir_unset_property_array(this_ptr, ZEND_STRL("clients"), &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 127, PH_NOISY_CC | PH_READONLY);
	zephir_array_unset_long(&_1, zephir_get_intval(socket), PH_SEPARATE);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 126, PH_NOISY_CC | PH_READONLY);
	zephir_unset_property_array(this_ptr, ZEND_STRL("sockets"), &_2);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 126, PH_NOISY_CC | PH_READONLY);
	zephir_array_unset_long(&_3, zephir_get_intval(socket), PH_SEPARATE);
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
PHP_METHOD(Ice_Cli_Websocket_Server, onValidate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Cli_Websocket_Server, onConnect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Cli_Websocket_Server, onDisconnect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Cli_Websocket_Server, onMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Cli_Websocket_Server, onTick)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Cli_Websocket_Server, onBoot)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Cli_Websocket_Server, callback)
{
	zval key_zv, *callback, callback_sub;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&callback_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	callback = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&key_zv, key);
	zephir_update_property_array(this_ptr, SL("callbacks"), &key_zv, callback);
	RETURN_THISW();
}

zend_object *zephir_init_properties_Ice_Cli_Websocket_Server(zend_class_entry *class_type)
{
		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("callbacks"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("callbacks"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("clients"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("clients"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("sockets"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("sockets"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

