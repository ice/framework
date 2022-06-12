
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
#include "kernel/file.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exit.h"
#include "kernel/time.h"
#include "kernel/math.h"


/**
 * A base class used in the server class.
 * It handles all encoding / decoding / masking / socket operations.
 *
 * @package     Ice/Cli
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Websocket_Websocket)
{
	ZEPHIR_REGISTER_CLASS(Ice\\Cli\\Websocket, Websocket, ice, cli_websocket_websocket, ice_cli_websocket_websocket_method_entry, 0);

	zend_declare_property_null(ice_cli_websocket_websocket_ce, SL("opcodes"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	zend_declare_property_long(ice_cli_websocket_websocket_ce, SL("fragmentSize"), 4096, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	zend_declare_property_string(ice_cli_websocket_websocket_ce, SL("magic"), "258EAFA5-E914-47DA-95CA-C5AB0DC85B11", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	zend_declare_property_null(ice_cli_websocket_websocket_ce, SL("params"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Send data to a socket in clear form (basically fwrite).
 *
 * @param resource socket The socket to write to
 * @param string data The data to send
 * @return boolean Was the send successful
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, sendClear)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval data;
	zval *socket, socket_sub, *data_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&socket_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_RESOURCE(socket)
		Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &socket, &data_param);
	zephir_get_strval(&data, data_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fwrite(&_0, socket, &data);
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_0, 0));
}

/**
 * Send data to a socket.
 *
 * @param resource socket The socket to send to
 * @param string data The data to send
 * @param string opcode One of the opcodes (defaults to "text")
 * @param boolean masked Should the data be masked (per specs the server should not mask, defaults to false)
 * @return boolean Was the send successful
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, sendData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool masked, _9$$3, _11$$3, _13$$4;
	zval data, opcode;
	zval *socket, socket_sub, *data_param = NULL, *opcode_param = NULL, *masked_param = NULL, tmp, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _12$$4, _14$$4, _16$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&socket_sub);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&opcode);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_RESOURCE(socket)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(opcode)
		Z_PARAM_BOOL(masked)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &socket, &data_param, &opcode_param, &masked_param);
	zephir_get_strval(&data, data_param);
	if (!opcode_param) {
		ZEPHIR_INIT_VAR(&opcode);
		ZVAL_STRING(&opcode, "text");
	} else {
		zephir_get_strval(&opcode, opcode_param);
	}
	if (!masked_param) {
		masked = 0;
	} else {
		masked = zephir_get_boolval(masked_param);
	}


	while (1) {
		if (!(zephir_fast_strlen_ev(&data))) {
			break;
		}
		zephir_read_static_property_ce(&_0$$3, ice_cli_websocket_websocket_ce, SL("fragmentSize"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_1$$3, 0);
		ZEPHIR_INIT_NVAR(&tmp);
		zephir_substr(&tmp, &data, 0 , zephir_get_intval(&_0$$3), 0);
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_read_static_property_ce(&_3$$3, ice_cli_websocket_websocket_ce, SL("fragmentSize"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT_LONG(&_3$$3, zephir_fast_strlen_ev(&data))) {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "");
		} else {
			zephir_read_static_property_ce(&_4$$3, ice_cli_websocket_websocket_ce, SL("fragmentSize"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_substr(&_2$$3, &data, zephir_get_intval(&_4$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		}
		zephir_get_strval(&data, &_2$$3);
		if (masked) {
			ZVAL_BOOL(&_6$$3, 1);
		} else {
			ZVAL_BOOL(&_6$$3, 0);
		}
		ZVAL_BOOL(&_7$$3, zephir_fast_strlen_ev(&data) == 0);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "encode", &_8, 0, &tmp, &opcode, &_6$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&tmp, &_5$$3);
		_9$$3 = Z_TYPE_P(socket) == IS_RESOURCE;
		if (_9$$3) {
			ZEPHIR_CALL_FUNCTION(&_5$$3, "get_resource_type", &_10, 28, socket);
			zephir_check_call_status();
			_9$$3 = ZEPHIR_IS_STRING(&_5$$3, "stream");
		}
		_11$$3 = _9$$3;
		if (_11$$3) {
			_11$$3 = !(zephir_feof(socket));
		}
		if (_11$$3) {
			ZEPHIR_INIT_NVAR(&_12$$4);
			zephir_fwrite(&_12$$4, socket, &tmp);
			_13$$4 = ZEPHIR_IS_FALSE_IDENTICAL(&_12$$4);
			if (!(_13$$4)) {
				ZEPHIR_CALL_FUNCTION(&_14$$4, "stream_get_meta_data", &_15, 29, socket);
				zephir_check_call_status();
				zephir_array_fetch_string(&_16$$4, &_14$$4, SL("timed_out"), PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 63);
				_13$$4 = zephir_is_true(&_16$$4);
			}
			if (_13$$4) {
				RETURN_MM_BOOL(0);
			}
		} else {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&opcode);
		ZVAL_STRING(&opcode, "continuation");
	}
	RETURN_MM_BOOL(1);
}

/**
 * Read clear data from a socket (basically a fread).
 *
 * @param resource socket The socket to read from
 * @return string The data that was read
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, receiveClear)
{
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL, *_5 = NULL, *_6 = NULL;
	zval *socket, socket_sub, data, read, buff, meta, _8, _2$$3, _3$$3, _4$$3, _9$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&socket_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&read);
	ZVAL_UNDEF(&buff);
	ZVAL_UNDEF(&meta);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_RESOURCE(socket)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &socket);


	ZEPHIR_INIT_VAR(&data);
	ZVAL_STRING(&data, "");
	ZEPHIR_OBS_VAR(&read);
	zephir_read_static_property_ce(&read, ice_cli_websocket_websocket_ce, SL("fragmentSize"), PH_NOISY_CC);
	do {
		ZEPHIR_CALL_FUNCTION(&buff, "fread", &_0, 30, socket, &read);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&buff)) {
			RETURN_MM_STRING("");
		}
		zephir_concat_self(&data, &buff);
		ZEPHIR_CALL_FUNCTION(&meta, "stream_get_meta_data", &_1, 29, socket);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&_2$$3);
		zephir_array_fetch_string(&_2$$3, &meta, SL("unread_bytes"), PH_NOISY, "ice/cli/websocket/websocket.zep", 98);
		zephir_read_static_property_ce(&_3$$3, ice_cli_websocket_websocket_ce, SL("fragmentSize"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, zephir_get_intval(&_2$$3));
		ZEPHIR_CALL_FUNCTION(&read, "min", &_5, 31, &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 1000);
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_6, 32, &_4$$3);
		zephir_check_call_status();
		_7 = !(zephir_feof(socket));
		if (_7) {
			ZEPHIR_OBS_NVAR(&_8);
			zephir_array_fetch_string(&_8, &meta, SL("unread_bytes"), PH_NOISY, "ice/cli/websocket/websocket.zep", 101);
			_7 = zephir_get_intval(&_8) > 0;
		}
	} while (_7);
	if (zephir_fast_strlen_ev(&data) == 1) {
		ZEPHIR_CALL_METHOD(&_9$$5, this_ptr, "receiveclear", NULL, 33, socket);
		zephir_check_call_status();
		zephir_concat_self(&data, &_9$$5);
	}
	RETURN_CCTOR(&data);
}

/**
 * Read data from a socket (in websocket format).
 *
 * @param resource socket The socket to read from
 * @return string The read data (decoded)
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, receive)
{
	long _24$$14;
	unsigned char _12$$8;
	char d = 0, f = 0, c$$14 = 0, d$$14 = 0;
	zval data, payload, mask, _11$$6, _19$$9, _23$$11, _25$$15;
	zend_bool fin = 0, masked = 0, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, j$$14 = 0;
	zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL, *_16 = NULL, *_22 = NULL;
	zval *socket, socket_sub, opcode, length, tmp, buff, _0, e, _5, _7, _8, _9, _27, _28, _2$$4, _3$$4, _10$$6, _17$$6, _13$$8, _14$$8, _15$$8, _18$$9, _20$$12, _21$$12, s$$14, t$$14, _26$$15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&socket_sub);
	ZVAL_UNDEF(&opcode);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&buff);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&s$$14);
	ZVAL_UNDEF(&t$$14);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&mask);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_25$$15);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_RESOURCE(socket)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &socket);


	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&tmp, "fread", &_1, 30, socket, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&tmp)) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_fast_strlen_ev(&tmp) == 1) {
		ZVAL_LONG(&_2$$4, 1);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "fread", &_1, 30, socket, &_2$$4);
		zephir_check_call_status();
		zephir_concat_self(&tmp, &_3$$4);
	}
	_4 = ZEPHIR_IS_FALSE_IDENTICAL(&tmp);
	if (!(_4)) {
		_4 = zephir_fast_strlen_ev(&tmp) < 2;
	}
	if (_4) {
		RETURN_MM_BOOL(0);
	}
	zephir_get_strval(&data, &tmp);
	f = ZEPHIR_STRING_OFFSET(&data, 0);
	f = f;
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRINGL(&_5, &f, 1);
	ZEPHIR_CALL_FUNCTION(&e, "ord", &_6, 34, &_5);
	zephir_check_call_status();
	fin = (zend_bool) (((int) (zephir_get_numberval(&e)) & 128));
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRINGL(&_5, &f, 1);
	ZEPHIR_CALL_FUNCTION(&_7, "ord", &_6, 34, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&opcode);
	ZVAL_LONG(&opcode, ((int) (zephir_get_numberval(&_7)) & 31));
	d = ZEPHIR_STRING_OFFSET(&data, 1);
	d = d;
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRINGL(&_5, &d, 1);
	ZEPHIR_CALL_FUNCTION(&_8, "ord", &_6, 34, &_5);
	zephir_check_call_status();
	masked = (zend_bool) ((int) (zephir_get_numberval(&_8)) >> 7);
	ZEPHIR_INIT_VAR(&payload);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRINGL(&_5, &d, 1);
	ZEPHIR_CALL_FUNCTION(&_9, "ord", &_6, 34, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, ((int) (zephir_get_numberval(&_9)) & 127));
	if (ZEPHIR_GT_LONG(&length, 125)) {
		if (ZEPHIR_IS_LONG_IDENTICAL(&length, 126)) {
			ZVAL_LONG(&_10$$6, 2);
			ZEPHIR_CALL_FUNCTION(&tmp, "fread", &_1, 30, socket, &_10$$6);
			zephir_check_call_status();
		} else {
			ZVAL_LONG(&_10$$6, 8);
			ZEPHIR_CALL_FUNCTION(&tmp, "fread", &_1, 30, socket, &_10$$6);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(&tmp)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&length);
		ZVAL_STRING(&length, "");
		i = 0;
		zephir_cast_to_string(&_11$$6, &tmp);
		ZEPHIR_CPY_WRT(&data, &_11$$6);
		while (1) {
			if (!(i < zephir_fast_strlen_ev(&tmp))) {
				break;
			}
			_12$$8 = ZEPHIR_STRING_OFFSET(&data, i);
			ZEPHIR_INIT_NVAR(&_13$$8);
			ZVAL_STRINGL(&_13$$8, &_12$$8, 1);
			ZEPHIR_CALL_FUNCTION(&_14$$8, "ord", &_6, 34, &_13$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_13$$8);
			ZVAL_STRING(&_13$$8, "%08b");
			ZEPHIR_CALL_FUNCTION(&_15$$8, "sprintf", &_16, 11, &_13$$8, &_14$$8);
			zephir_check_call_status();
			zephir_concat_self(&length, &_15$$8);
			i++;
		}
		ZEPHIR_CALL_FUNCTION(&_17$$6, "bindec", NULL, 35, &length);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&length, &_17$$6);
	}
	ZEPHIR_INIT_VAR(&mask);
	if (masked) {
		ZVAL_LONG(&_18$$9, 4);
		ZEPHIR_CALL_FUNCTION(&tmp, "fread", &_1, 30, socket, &_18$$9);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&tmp)) {
			RETURN_MM_BOOL(0);
		}
		zephir_cast_to_string(&_19$$9, &tmp);
		ZEPHIR_CPY_WRT(&mask, &_19$$9);
	}
	if (ZEPHIR_GT_LONG(&length, 0)) {
		ZEPHIR_INIT_NVAR(&tmp);
		ZVAL_STRING(&tmp, "");
		do {
			zephir_read_static_property_ce(&_20$$12, ice_cli_websocket_websocket_ce, SL("fragmentSize"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_21$$12, "min", &_22, 31, &length, &_20$$12);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&buff, "fread", &_1, 30, socket, &_21$$12);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&buff)) {
				RETURN_MM_BOOL(0);
			}
			zephir_concat_self(&tmp, &buff);
		} while (ZEPHIR_GT_LONG(&length, zephir_fast_strlen_ev(&tmp)));
		zephir_cast_to_string(&_23$$11, &tmp);
		ZEPHIR_CPY_WRT(&data, &_23$$11);
		if (masked) {
			for (_24$$14 = 0; _24$$14 < Z_STRLEN_P(&data); _24$$14++) {
				i = _24$$14; 
				c$$14 = ZEPHIR_STRING_OFFSET(&data, _24$$14);
				j$$14 = (int) (zephir_safe_mod_long_long(i, 4));
				d$$14 = ZEPHIR_STRING_OFFSET(&mask, j$$14);
				d$$14 = d$$14;
				ZEPHIR_INIT_NVAR(&_25$$15);
				ZVAL_STRINGL(&_25$$15, &c$$14, 1);
				ZEPHIR_CPY_WRT(&s$$14, &_25$$15);
				ZEPHIR_INIT_NVAR(&_25$$15);
				ZVAL_STRINGL(&_25$$15, &d$$14, 1);
				ZEPHIR_CPY_WRT(&t$$14, &_25$$15);
				ZEPHIR_INIT_NVAR(&_26$$15);
				zephir_bitwise_xor_function(&_26$$15, &s$$14, &t$$14);
				zephir_concat_self(&payload, &_26$$15);
			}
		} else {
			ZEPHIR_CPY_WRT(&payload, &data);
		}
	}
	zephir_read_static_property_ce(&_0, ice_cli_websocket_websocket_ce, SL("opcodes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_27, &_0, SL("close"), PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 213);
	if (ZEPHIR_IS_IDENTICAL(&opcode, &_27)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(&_5);
	if (fin) {
		ZEPHIR_CPY_WRT(&_5, &payload);
	} else {
		ZEPHIR_CALL_METHOD(&_28, this_ptr, "receive", NULL, 36, socket);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(&_5, &payload, &_28);
	}
	RETURN_CCTOR(&_5);
}

/**
 * Encode the data.
 *
 * @param string data The data to send
 * @param string opcode One of the opcodes (defaults to "text")
 * @param boolean masked Should the data be masked
 * @param boolean fin Add 1 to the head
 * @return string
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, encode)
{
	long _34$$10;
	char c$$10 = 0, d$$10 = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, j$$10 = 0;
	zephir_fcall_cache_entry *_5 = NULL, *_22 = NULL, *_25 = NULL, *_32 = NULL;
	zend_bool masked, fin;
	zval *data_param = NULL, *opcode_param = NULL, *masked_param = NULL, *fin_param = NULL, length, binstr, _0, _1, _2, _3, _4, _6, _17, _18, *_19, _20, _7$$3, _8$$3, _9$$3, _10$$3, _11$$4, _12$$4, _13$$4, _14$$4, _15$$5, _16$$5, _21$$6, _23$$6, _24$$6, _26$$7, _27$$7, _28$$7, _29$$9, _30$$9, _31$$9, _33$$9, s$$10, t$$10, _36$$11;
	zval data, opcode, head, frame, mask, _35$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&opcode);
	ZVAL_UNDEF(&head);
	ZVAL_UNDEF(&frame);
	ZVAL_UNDEF(&mask);
	ZVAL_UNDEF(&_35$$11);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&binstr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&s$$10);
	ZVAL_UNDEF(&t$$10);
	ZVAL_UNDEF(&_36$$11);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(opcode)
		Z_PARAM_BOOL(masked)
		Z_PARAM_BOOL(fin)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &data_param, &opcode_param, &masked_param, &fin_param);
	zephir_get_strval(&data, data_param);
	if (!opcode_param) {
		ZEPHIR_INIT_VAR(&opcode);
		ZVAL_STRING(&opcode, "text");
	} else {
		zephir_get_strval(&opcode, opcode_param);
	}
	if (!masked_param) {
		masked = 1;
	} else {
		masked = zephir_get_boolval(masked_param);
	}
	if (!fin_param) {
		fin = 1;
	} else {
		fin = zephir_get_boolval(fin_param);
	}


	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, zephir_fast_strlen_ev(&data));
	ZEPHIR_INIT_VAR(&head);
	ZEPHIR_INIT_VAR(&_0);
	if (fin) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "1");
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "0");
	}
	zephir_concat_self(&head, &_0);
	zephir_concat_self_str(&head, "000", sizeof("000") - 1);
	zephir_read_static_property_ce(&_1, ice_cli_websocket_websocket_ce, SL("opcodes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_2, &_1, &opcode, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 239);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "%04b");
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", &_5, 11, &_3, &_2);
	zephir_check_call_status();
	zephir_concat_self(&head, &_4);
	ZEPHIR_INIT_VAR(&_6);
	if (masked) {
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_STRING(&_6, "1");
	} else {
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_STRING(&_6, "0");
	}
	zephir_concat_self(&head, &_6);
	if (ZEPHIR_GT_LONG(&length, 65535)) {
		ZVAL_LONG(&_7$$3, 127);
		ZEPHIR_CALL_FUNCTION(&_8$$3, "decbin", NULL, 37, &_7$$3);
		zephir_check_call_status();
		zephir_concat_self(&head, &_8$$3);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "%064b");
		ZEPHIR_CALL_FUNCTION(&_10$$3, "sprintf", &_5, 11, &_9$$3, &length);
		zephir_check_call_status();
		zephir_concat_self(&head, &_10$$3);
	} else if (ZEPHIR_GT_LONG(&length, 125)) {
		ZVAL_LONG(&_11$$4, 126);
		ZEPHIR_CALL_FUNCTION(&_12$$4, "decbin", NULL, 37, &_11$$4);
		zephir_check_call_status();
		zephir_concat_self(&head, &_12$$4);
		ZEPHIR_INIT_VAR(&_13$$4);
		ZVAL_STRING(&_13$$4, "%016b");
		ZEPHIR_CALL_FUNCTION(&_14$$4, "sprintf", &_5, 11, &_13$$4, &length);
		zephir_check_call_status();
		zephir_concat_self(&head, &_14$$4);
	} else {
		ZEPHIR_INIT_VAR(&_15$$5);
		ZVAL_STRING(&_15$$5, "%07b");
		ZEPHIR_CALL_FUNCTION(&_16$$5, "sprintf", &_5, 11, &_15$$5, &length);
		zephir_check_call_status();
		zephir_concat_self(&head, &_16$$5);
	}
	ZEPHIR_INIT_VAR(&frame);
	ZVAL_LONG(&_17, 8);
	ZEPHIR_CALL_FUNCTION(&_18, "str_split", NULL, 38, &head, &_17);
	zephir_check_call_status();
	zephir_is_iterable(&_18, 0, "ice/cli/websocket/websocket.zep", 258);
	if (Z_TYPE_P(&_18) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_18), _19)
		{
			ZEPHIR_INIT_NVAR(&binstr);
			ZVAL_COPY(&binstr, _19);
			ZEPHIR_CALL_FUNCTION(&_21$$6, "bindec", &_22, 35, &binstr);
			zephir_check_call_status();
			ZVAL_LONG(&_23$$6, zephir_get_intval(&_21$$6));
			ZEPHIR_CALL_FUNCTION(&_24$$6, "chr", &_25, 39, &_23$$6);
			zephir_check_call_status();
			zephir_concat_self(&frame, &_24$$6);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_18, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_20, &_18, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_20)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&binstr, &_18, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_26$$7, "bindec", &_22, 35, &binstr);
				zephir_check_call_status();
				ZVAL_LONG(&_27$$7, zephir_get_intval(&_26$$7));
				ZEPHIR_CALL_FUNCTION(&_28$$7, "chr", &_25, 39, &_27$$7);
				zephir_check_call_status();
				zephir_concat_self(&frame, &_28$$7);
			ZEPHIR_CALL_METHOD(NULL, &_18, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&binstr);
	ZEPHIR_INIT_VAR(&mask);
	if (masked) {
		i = 0;
		while (1) {
			if (!(i < 4)) {
				break;
			}
			ZVAL_LONG(&_29$$9, 0);
			ZVAL_LONG(&_30$$9, 255);
			ZEPHIR_CALL_FUNCTION(&_31$$9, "rand", &_32, 40, &_29$$9, &_30$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_33$$9, "chr", &_25, 39, &_31$$9);
			zephir_check_call_status();
			zephir_concat_self(&mask, &_33$$9);
			i++;
		}
		zephir_concat_self(&frame, &mask);
	}
	if (masked) {
		for (_34$$10 = 0; _34$$10 < Z_STRLEN_P(&data); _34$$10++) {
			i = _34$$10; 
			c$$10 = ZEPHIR_STRING_OFFSET(&data, _34$$10);
			j$$10 = (int) (zephir_safe_mod_long_long(i, 4));
			d$$10 = ZEPHIR_STRING_OFFSET(&mask, j$$10);
			d$$10 = d$$10;
			ZEPHIR_INIT_NVAR(&_35$$11);
			ZVAL_STRINGL(&_35$$11, &c$$10, 1);
			ZEPHIR_CPY_WRT(&s$$10, &_35$$11);
			ZEPHIR_INIT_NVAR(&_35$$11);
			ZVAL_STRINGL(&_35$$11, &d$$10, 1);
			ZEPHIR_CPY_WRT(&t$$10, &_35$$11);
			ZEPHIR_INIT_NVAR(&_36$$11);
			zephir_bitwise_xor_function(&_36$$11, &s$$10, &t$$10);
			zephir_concat_self(&frame, &_36$$11);
		}
	} else {
		zephir_concat_self(&frame, &data);
	}
	RETURN_CTOR(&frame);
}

/**
 * Set server params.
 *
 * @param array params
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, setParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *params_param = NULL;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);
	zephir_get_arrval(&params, params_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &params);
	RETURN_THIS();
}

/**
 * Get server params.
 *
 * @return array
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, getParams)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "params");
}

/**
 * Retrieve a single param.
 *
 * @param string key The data key
 * @param mixed defaultValue The value to return if data key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, getParam)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1$$3, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);
	zephir_get_strval(&key, key_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &key)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 324);
		RETURN_CTOR(&_2$$3);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();
}

/**
 * Display text on the console.
 *
 * @param string text Text to display
 * @param int color The foreground color
 * @param int decoration Formatting type
 * @param int bgColor The background color
 * @param boolean exit Die if true
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, console)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL;
	zend_bool exit;
	zend_long color, decoration, bgColor, ZEPHIR_LAST_CALL_STATUS;
	zval text, *text_param = NULL, *color_param = NULL, *decoration_param = NULL, *bgColor_param = NULL, *exit_param = NULL, di, _0, _1, _2, _4, _5, _6, _7, _9$$4, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(color, is_null_true)
		Z_PARAM_LONG(decoration)
		Z_PARAM_LONG_OR_NULL(bgColor, is_null_true)
		Z_PARAM_BOOL(exit)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &text_param, &color_param, &decoration_param, &bgColor_param, &exit_param);
	zephir_get_strval(&text, text_param);
	if (!color_param) {
		color = 0;
	} else {
		color = zephir_get_intval(color_param);
	}
	if (!decoration_param) {
		decoration = 0;
	} else {
		decoration = zephir_get_intval(decoration_param);
	}
	if (!bgColor_param) {
		bgColor = 0;
	} else {
		bgColor = zephir_get_intval(bgColor_param);
	}
	if (!exit_param) {
		exit = 0;
	} else {
		exit = zephir_get_boolval(exit_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "date_format");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "[Y-m-d H:i:s]");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparam", &_3, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "date", NULL, 41, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VSVS(&_5, &_4, " ", &text, "\r\n");
	ZEPHIR_CPY_WRT(&text, &_5);
	if (exit) {
		ZEPHIR_MM_RESTORE();
		zephir_exit(&text);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "verbose");
	ZVAL_BOOL(&_7, 0);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getparam", &_3, 0, &_1, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_8, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "console");
		ZEPHIR_CALL_METHOD(&_9$$4, &di, "get", NULL, 0, &_10$$4);
		zephir_check_call_status();
		ZVAL_LONG(&_12$$4, color);
		ZVAL_LONG(&_13$$4, decoration);
		ZVAL_LONG(&_14$$4, bgColor);
		ZEPHIR_CALL_METHOD(&_11$$4, &_9$$4, "color", NULL, 0, &text, &_12$$4, &_13$$4, &_14$$4);
		zephir_check_call_status();
		zend_print_zval(&_11$$4, 0);
	}
	RETURN_THIS();
}

/**
 * Returns info text.
 *
 * @param string text
 * @return string
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, info)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, _0;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);
	zephir_get_strval(&text, text_param);


	ZVAL_LONG(&_0, 36);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "console", NULL, 0, &text, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns success text.
 *
 * @param string text
 * @return string
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, success)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, _0;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);
	zephir_get_strval(&text, text_param);


	ZVAL_LONG(&_0, 32);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "console", NULL, 0, &text, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns warning text.
 *
 * @param string text
 * @return string
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, warning)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, _0;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);
	zephir_get_strval(&text, text_param);


	ZVAL_LONG(&_0, 33);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "console", NULL, 0, &text, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns error text.
 *
 * @param string text
 * @return string
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, error)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, _0;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);
	zephir_get_strval(&text, text_param);


	ZVAL_LONG(&_0, 31);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "console", NULL, 0, &text, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get script uptime.
 *
 * @param boolean human In seconds if false
 * @return float|string
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, getUptime)
{
	zval _14;
	zend_long s = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *human_param = NULL, __$true, _SERVER, uptime, y, m, d, h, i, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13;
	zend_bool human;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&uptime);
	ZVAL_UNDEF(&y);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&d);
	ZVAL_UNDEF(&h);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(human)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 1, &human_param);
	if (!human_param) {
		human = 1;
	} else {
		human = zephir_get_boolval(human_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_microtime(&_0, &__$true);
	zephir_array_fetch_string(&_1, &_SERVER, SL("REQUEST_TIME_FLOAT"), PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 413);
	ZEPHIR_INIT_VAR(&uptime);
	zephir_sub_function(&uptime, &_0, &_1);
	if (!(human)) {
		RETURN_CCTOR(&uptime);
	}
	s = (long) (zephir_safe_mod_zval_long(&uptime, 60));
	ZVAL_DOUBLE(&_2, zephir_safe_div_double_long((zephir_safe_mod_zval_long(&uptime, 3600)), (double) (60)));
	ZEPHIR_INIT_VAR(&i);
	ZVAL_DOUBLE(&i, zephir_floor(&_2));
	ZVAL_DOUBLE(&_3, zephir_safe_div_double_long((zephir_safe_mod_zval_long(&uptime, 86400)), (double) (3600)));
	ZEPHIR_INIT_VAR(&h);
	ZVAL_DOUBLE(&h, zephir_floor(&_3));
	ZVAL_DOUBLE(&_4, zephir_safe_div_double_long((zephir_safe_mod_zval_long(&uptime, 2592000)), (double) (86400)));
	ZEPHIR_INIT_VAR(&d);
	ZVAL_DOUBLE(&d, zephir_floor(&_4));
	ZVAL_DOUBLE(&_5, zephir_safe_div_zval_long(&uptime, 2592000));
	ZEPHIR_INIT_VAR(&m);
	ZVAL_DOUBLE(&m, zephir_floor(&_5));
	ZVAL_DOUBLE(&_6, (zephir_safe_div_zval_long(&uptime, 2592000) * (double) (12)));
	ZEPHIR_INIT_VAR(&y);
	ZVAL_DOUBLE(&y, zephir_floor(&_6));
	ZEPHIR_INIT_VAR(&_7);
	if (zephir_is_true(&y)) {
		ZEPHIR_INIT_NVAR(&_7);
		ZEPHIR_CONCAT_VS(&_7, &y, "Y ");
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "");
	}
	ZEPHIR_INIT_VAR(&_8);
	if (zephir_is_true(&m)) {
		ZEPHIR_INIT_NVAR(&_8);
		ZEPHIR_CONCAT_VS(&_8, &m, "M ");
	} else {
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_STRING(&_8, "");
	}
	ZEPHIR_INIT_VAR(&_9);
	if (zephir_is_true(&d)) {
		ZEPHIR_INIT_NVAR(&_9);
		ZEPHIR_CONCAT_VS(&_9, &d, "d ");
	} else {
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_STRING(&_9, "");
	}
	ZEPHIR_INIT_VAR(&_10);
	if (zephir_is_true(&h)) {
		ZEPHIR_INIT_NVAR(&_10);
		ZEPHIR_CONCAT_VS(&_10, &h, "h ");
	} else {
		ZEPHIR_INIT_NVAR(&_10);
		ZVAL_STRING(&_10, "");
	}
	ZEPHIR_INIT_VAR(&_11);
	if (zephir_is_true(&i)) {
		ZEPHIR_INIT_NVAR(&_11);
		ZEPHIR_CONCAT_VS(&_11, &i, "m ");
	} else {
		ZEPHIR_INIT_NVAR(&_11);
		ZVAL_STRING(&_11, "");
	}
	ZEPHIR_INIT_VAR(&_12);
	if (s) {
		ZEPHIR_INIT_VAR(&_13);
		ZVAL_LONG(&_13, s);
		ZEPHIR_INIT_VAR(&_14);
		ZEPHIR_CONCAT_VS(&_14, &_13, "s");
		ZEPHIR_CPY_WRT(&_12, &_14);
	} else {
		ZEPHIR_INIT_NVAR(&_12);
		ZVAL_STRING(&_12, "");
	}
	ZEPHIR_CONCAT_VVVVVV(return_value, &_7, &_8, &_9, &_10, &_11, &_12);
	RETURN_MM();
}

/**
 * Get memory usage.
 *
 * @param boolean human In byetes if false
 * @return int|string
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, getMemoryUsage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *human_param = NULL, size, unit, i, _0, _1, _2, _3, _4, _5, _6;
	zend_bool human;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&unit);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(human)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &human_param);
	if (!human_param) {
		human = 1;
	} else {
		human = zephir_get_boolval(human_param);
	}


	ZEPHIR_CALL_FUNCTION(&size, "memory_get_usage", NULL, 42);
	zephir_check_call_status();
	if (!(human)) {
		RETURN_CCTOR(&size);
	}
	ZEPHIR_INIT_VAR(&unit);
	zephir_create_array(&unit, 6, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "B");
	zephir_array_fast_append(&unit, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "KB");
	zephir_array_fast_append(&unit, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "MB");
	zephir_array_fast_append(&unit, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "GB");
	zephir_array_fast_append(&unit, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "TB");
	zephir_array_fast_append(&unit, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "PB");
	zephir_array_fast_append(&unit, &_0);
	ZVAL_LONG(&_1, 1024);
	ZEPHIR_CALL_FUNCTION(&_2, "log", NULL, 43, &size, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&i);
	ZVAL_DOUBLE(&i, zephir_floor(&_2));
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_1, 1024);
	zephir_pow_function(&_3, &_1, &i);
	ZEPHIR_INIT_VAR(&_4);
	div_function(&_4, &size, &_3);
	ZVAL_LONG(&_5, 2);
	zephir_round(&_0, &_4, &_5, NULL);
	zephir_array_fetch(&_6, &unit, &i, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 453);
	ZEPHIR_CONCAT_VV(return_value, &_0, &_6);
	RETURN_MM();
}

void zephir_init_static_properties_Ice_Cli_Websocket_Websocket()
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 6, 0);
	add_assoc_long_ex(&_0, SL("continuation"), 0);
	add_assoc_long_ex(&_0, SL("text"), 1);
	add_assoc_long_ex(&_0, SL("binary"), 2);
	add_assoc_long_ex(&_0, SL("close"), 8);
	add_assoc_long_ex(&_0, SL("ping"), 9);
	add_assoc_long_ex(&_0, SL("pong"), 10);
	zephir_update_static_property_ce(ice_cli_websocket_websocket_ce, ZEND_STRL("opcodes"), &_0);
	ZEPHIR_MM_RESTORE();
}

