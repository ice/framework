
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
#include "kernel/string.h"
#include "kernel/object.h"
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Websocket_Websocket) {

	ZEPHIR_REGISTER_CLASS(Ice\\Cli\\Websocket, Websocket, ice, cli_websocket_websocket, ice_cli_websocket_websocket_method_entry, 0);

	zend_declare_property_null(ice_cli_websocket_websocket_ce, SL("opcodes"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_long(ice_cli_websocket_websocket_ce, SL("fragmentSize"), 4096, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(ice_cli_websocket_websocket_ce, SL("magic"), "258EAFA5-E914-47DA-95CA-C5AB0DC85B11", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(ice_cli_websocket_websocket_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Send data to a socket in clear form (basically fwrite).
 *
 * @param resource socket The socket to write to
 * @param string data The data to send
 * @return boolean Was the send successful
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, sendClear) {

	zval data;
	zval *socket, socket_sub, *data_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&socket_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &socket, &data_param);

	zephir_get_strval(&data, data_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fwrite(&_0, socket, &data TSRMLS_CC);
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
PHP_METHOD(Ice_Cli_Websocket_Websocket, sendData) {

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
		ZEPHIR_INIT_LNVAR(_2$$3);
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
			_11$$3 = !(zephir_feof(socket TSRMLS_CC));
		}
		if (_11$$3) {
			ZEPHIR_INIT_NVAR(&_12$$4);
			zephir_fwrite(&_12$$4, socket, &tmp TSRMLS_CC);
			_13$$4 = ZEPHIR_IS_FALSE_IDENTICAL(&_12$$4);
			if (!(_13$$4)) {
				ZEPHIR_CALL_FUNCTION(&_14$$4, "stream_get_meta_data", &_15, 29, socket);
				zephir_check_call_status();
				zephir_array_fetch_string(&_16$$4, &_14$$4, SL("timed_out"), PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 63 TSRMLS_CC);
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
PHP_METHOD(Ice_Cli_Websocket_Websocket, receiveClear) {

	zend_bool _7;
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
		zephir_concat_self(&data, &buff TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&meta, "stream_get_meta_data", &_1, 29, socket);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&_2$$3);
		zephir_array_fetch_string(&_2$$3, &meta, SL("unread_bytes"), PH_NOISY, "ice/cli/websocket/websocket.zep", 98 TSRMLS_CC);
		zephir_read_static_property_ce(&_3$$3, ice_cli_websocket_websocket_ce, SL("fragmentSize"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, zephir_get_intval(&_2$$3));
		ZEPHIR_CALL_FUNCTION(&read, "min", &_5, 31, &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 1000);
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_6, 32, &_4$$3);
		zephir_check_call_status();
		_7 = !(zephir_feof(socket TSRMLS_CC));
		if (_7) {
			ZEPHIR_OBS_NVAR(&_8);
			zephir_array_fetch_string(&_8, &meta, SL("unread_bytes"), PH_NOISY, "ice/cli/websocket/websocket.zep", 101 TSRMLS_CC);
			_7 = zephir_get_intval(&_8) > 0;
		}
	} while (_7);
	if (zephir_fast_strlen_ev(&data) == 1) {
		ZEPHIR_CALL_METHOD(&_9$$5, this_ptr, "receiveclear", NULL, 33, socket);
		zephir_check_call_status();
		zephir_concat_self(&data, &_9$$5 TSRMLS_CC);
	}
	RETURN_CCTOR(&data);

}

/**
 * Read data from a socket (in websocket format).
 *
 * @param resource socket The socket to read from
 * @return string The read data (decoded)
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, receive) {

	zend_bool fin = 0, masked = 0, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_19 = NULL, *_24 = NULL;
	zval *socket, socket_sub, data, opcode, payload, length, tmp, mask, buff, _0, _5, _6, _8, _9, _10, _11, _12, _13, _28, _29, _30, _2$$3, _3$$3, _14$$5, _20$$5, _15$$7, _16$$7, _17$$7, _18$$7, _21$$8, _22$$11, _23$$11, _25$$14, _26$$14, _27$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&socket_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&opcode);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&mask);
	ZVAL_UNDEF(&buff);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$14);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &socket);



	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&data, "fread", &_1, 30, socket, &_0);
	zephir_check_call_status();
	if (zephir_fast_strlen_ev(&data) == 1) {
		ZVAL_LONG(&_2$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "fread", &_1, 30, socket, &_2$$3);
		zephir_check_call_status();
		zephir_concat_self(&data, &_3$$3 TSRMLS_CC);
	}
	_4 = ZEPHIR_IS_FALSE_IDENTICAL(&data);
	if (!(_4)) {
		_4 = zephir_fast_strlen_ev(&data) < 2;
	}
	if (_4) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_5, &data, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 131 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_6, "ord", &_7, 34, &_5);
	zephir_check_call_status();
	fin = (zend_bool) (((int) (zephir_get_numberval(&_6)) & 1) << 7);
	zephir_array_fetch_long(&_8, &data, 0, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 135 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_9, "ord", &_7, 34, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&opcode);
	ZVAL_LONG(&opcode, ((int) (zephir_get_numberval(&_9)) & 31));
	zephir_array_fetch_long(&_10, &data, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 136 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_11, "ord", &_7, 34, &_10);
	zephir_check_call_status();
	masked = (zend_bool) ((int) (zephir_get_numberval(&_11)) >> 7);
	ZEPHIR_INIT_VAR(&payload);
	ZVAL_STRING(&payload, "");
	zephir_array_fetch_long(&_12, &data, 1, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 138 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_13, "ord", &_7, 34, &_12);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, ((int) (zephir_get_numberval(&_13)) & 127));
	if (ZEPHIR_GT_LONG(&length, 125)) {
		if (ZEPHIR_IS_LONG_IDENTICAL(&length, 126)) {
			ZVAL_LONG(&_14$$5, 2);
			ZEPHIR_CALL_FUNCTION(&tmp, "fread", &_1, 30, socket, &_14$$5);
			zephir_check_call_status();
		} else {
			ZVAL_LONG(&_14$$5, 8);
			ZEPHIR_CALL_FUNCTION(&tmp, "fread", &_1, 30, socket, &_14$$5);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(&tmp)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&length);
		ZVAL_STRING(&length, "");
		i = 0;
		while (1) {
			if (!(i < zephir_fast_strlen_ev(&tmp))) {
				break;
			}
			zephir_array_fetch_long(&_15$$7, &tmp, i, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 151 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_16$$7, "ord", &_7, 34, &_15$$7);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_17$$7);
			ZVAL_STRING(&_17$$7, "%08b");
			ZEPHIR_CALL_FUNCTION(&_18$$7, "sprintf", &_19, 11, &_17$$7, &_16$$7);
			zephir_check_call_status();
			zephir_concat_self(&length, &_18$$7 TSRMLS_CC);
			i++;
		}
		ZEPHIR_CALL_FUNCTION(&_20$$5, "bindec", NULL, 35, &length);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&length, &_20$$5);
	}
	ZEPHIR_INIT_VAR(&mask);
	ZVAL_STRING(&mask, "");
	if (masked) {
		ZVAL_LONG(&_21$$8, 4);
		ZEPHIR_CALL_FUNCTION(&mask, "fread", &_1, 30, socket, &_21$$8);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&mask)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GT_LONG(&length, 0)) {
		ZEPHIR_INIT_NVAR(&tmp);
		ZVAL_STRING(&tmp, "");
		do {
			zephir_read_static_property_ce(&_22$$11, ice_cli_websocket_websocket_ce, SL("fragmentSize"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_23$$11, "min", &_24, 31, &length, &_22$$11);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&buff, "fread", &_1, 30, socket, &_23$$11);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&buff)) {
				RETURN_MM_BOOL(0);
			}
			zephir_concat_self(&tmp, &buff TSRMLS_CC);
		} while (ZEPHIR_GT_LONG(&length, zephir_fast_strlen_ev(&tmp)));
		if (masked) {
			i = 0;
			while (1) {
				if (!(ZEPHIR_GT_LONG(&length, i))) {
					break;
				}
				zephir_array_fetch_long(&_25$$14, &tmp, i, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 185 TSRMLS_CC);
				zephir_array_fetch_long(&_26$$14, &mask, (int) (zephir_safe_mod_long_long(i, 4 TSRMLS_CC)), PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 185 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_27$$14);
				zephir_bitwise_xor_function(&_27$$14, &_25$$14, &_26$$14 TSRMLS_CC);
				zephir_concat_self(&payload, &_27$$14 TSRMLS_CC);
				i++;
			}
		} else {
			ZEPHIR_CPY_WRT(&payload, &tmp);
		}
	}
	zephir_read_static_property_ce(&_0, ice_cli_websocket_websocket_ce, SL("opcodes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_28, &_0, SL("close"), PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 193 TSRMLS_CC);
	if (ZEPHIR_IS_IDENTICAL(&opcode, &_28)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_29);
	if (fin) {
		ZEPHIR_CPY_WRT(&_29, &payload);
	} else {
		ZEPHIR_CALL_METHOD(&_30, this_ptr, "receive", NULL, 36, socket);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(&_29, &payload, &_30);
	}
	RETURN_CCTOR(&_29);

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
PHP_METHOD(Ice_Cli_Websocket_Websocket, encode) {

	unsigned char _32$$9, _34$$9;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zephir_fcall_cache_entry *_6 = NULL, *_22 = NULL, *_25 = NULL, *_29 = NULL;
	zend_bool masked, fin;
	zval *data_param = NULL, *opcode_param = NULL, *masked_param = NULL, *fin_param = NULL, length, head, frame, binstr, mask, _0, _2, _3, _4, _5, _7, _18, _19, *_20, _8$$3, _9$$3, _10$$3, _11$$3, _12$$4, _13$$4, _14$$4, _15$$4, _16$$5, _17$$5, _21$$6, _23$$6, _24$$6, _26$$8, _27$$8, _28$$8, _30$$8, _31$$9, _33$$9;
	zval data, opcode, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&opcode);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&head);
	ZVAL_UNDEF(&frame);
	ZVAL_UNDEF(&binstr);
	ZVAL_UNDEF(&mask);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_33$$9);

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
	ZVAL_STRING(&head, "");
	ZEPHIR_INIT_VAR(&_0);
	if (fin) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "1");
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "0");
	}
	zephir_concat_self(&head, &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SSS(&_1, "0", "0", "0");
	zephir_concat_self(&head, &_1 TSRMLS_CC);
	zephir_read_static_property_ce(&_2, ice_cli_websocket_websocket_ce, SL("opcodes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &opcode, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 218 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "%04b");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", &_6, 11, &_4, &_3);
	zephir_check_call_status();
	zephir_concat_self(&head, &_5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_7);
	if (masked) {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "1");
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "0");
	}
	zephir_concat_self(&head, &_7 TSRMLS_CC);
	if (ZEPHIR_GT_LONG(&length, 65535)) {
		ZVAL_LONG(&_8$$3, 127);
		ZEPHIR_CALL_FUNCTION(&_9$$3, "decbin", NULL, 37, &_8$$3);
		zephir_check_call_status();
		zephir_concat_self(&head, &_9$$3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "%064b");
		ZEPHIR_CALL_FUNCTION(&_11$$3, "sprintf", &_6, 11, &_10$$3, &length);
		zephir_check_call_status();
		zephir_concat_self(&head, &_11$$3 TSRMLS_CC);
	} else if (ZEPHIR_GT_LONG(&length, 125)) {
		ZVAL_LONG(&_12$$4, 126);
		ZEPHIR_CALL_FUNCTION(&_13$$4, "decbin", NULL, 37, &_12$$4);
		zephir_check_call_status();
		zephir_concat_self(&head, &_13$$4 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_14$$4);
		ZVAL_STRING(&_14$$4, "%016b");
		ZEPHIR_CALL_FUNCTION(&_15$$4, "sprintf", &_6, 11, &_14$$4, &length);
		zephir_check_call_status();
		zephir_concat_self(&head, &_15$$4 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&_16$$5);
		ZVAL_STRING(&_16$$5, "%07b");
		ZEPHIR_CALL_FUNCTION(&_17$$5, "sprintf", &_6, 11, &_16$$5, &length);
		zephir_check_call_status();
		zephir_concat_self(&head, &_17$$5 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&frame);
	ZVAL_STRING(&frame, "");
	ZVAL_LONG(&_18, 8);
	ZEPHIR_CALL_FUNCTION(&_19, "str_split", NULL, 38, &head, &_18);
	zephir_check_call_status();
	zephir_is_iterable(&_19, 0, "ice/cli/websocket/websocket.zep", 237);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_19), _20)
	{
		ZEPHIR_INIT_NVAR(&binstr);
		ZVAL_COPY(&binstr, _20);
		ZEPHIR_CALL_FUNCTION(&_21$$6, "bindec", &_22, 35, &binstr);
		zephir_check_call_status();
		ZVAL_LONG(&_23$$6, zephir_get_intval(&_21$$6));
		ZEPHIR_CALL_FUNCTION(&_24$$6, "chr", &_25, 39, &_23$$6);
		zephir_check_call_status();
		zephir_concat_self(&frame, &_24$$6 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&binstr);
	ZEPHIR_INIT_VAR(&mask);
	ZVAL_STRING(&mask, "");
	if (masked) {
		i = 0;
		while (1) {
			if (!(i < 4)) {
				break;
			}
			ZVAL_LONG(&_26$$8, 0);
			ZVAL_LONG(&_27$$8, 255);
			ZEPHIR_CALL_FUNCTION(&_28$$8, "rand", &_29, 40, &_26$$8, &_27$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_30$$8, "chr", &_25, 39, &_28$$8);
			zephir_check_call_status();
			zephir_concat_self(&mask, &_30$$8 TSRMLS_CC);
			i++;
		}
		zephir_concat_self(&frame, &mask TSRMLS_CC);
	}
	i = 0;
	while (1) {
		if (!(ZEPHIR_GT_LONG(&length, i))) {
			break;
		}
		ZEPHIR_INIT_LNVAR(_31$$9);
		if (masked == 1) {
			_32$$9 = ZEPHIR_STRING_OFFSET(&data, i);
			zephir_array_fetch_long(&_33$$9, &mask, (int) (zephir_safe_mod_long_long(i, 4 TSRMLS_CC)), PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 253 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_31$$9);
			ZVAL_LONG(&_31$$9, (_32$$9 ^ (int) (zephir_get_numberval(&_33$$9))));
		} else {
			_34$$9 = ZEPHIR_STRING_OFFSET(&data, i);
			ZEPHIR_INIT_NVAR(&_31$$9);
			ZVAL_LONG(&_31$$9, _34$$9);
		}
		zephir_concat_self(&frame, &_31$$9 TSRMLS_CC);
		i++;
	}
	RETURN_CCTOR(&frame);

}

/**
 * Set server params.
 *
 * @param array params
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, setParams) {

	zval *params_param = NULL;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(&params, params_param);


	zephir_update_property_zval(this_ptr, SL("params"), &params);
	RETURN_THIS();

}

/**
 * Get server params.
 *
 * @return array
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, getParams) {

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
PHP_METHOD(Ice_Cli_Websocket_Websocket, getParam) {

	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1$$3, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	zephir_get_strval(&key, key_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &key)) {
		zephir_read_property(&_1$$3, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 293 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Display text on the console.
 *
 * @param string text Text to display
 * @param string color The foreground color
 * @param int decoration Formatting type
 * @param string bgColor The background color
 * @param boolean exit Die if true
 * @return self
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, console) {

	zephir_fcall_cache_entry *_3 = NULL, *_9 = NULL;
	zend_bool exit;
	zend_long decoration, ZEPHIR_LAST_CALL_STATUS;
	zval color, bgColor;
	zval text, *text_param = NULL, *color_param = NULL, *decoration_param = NULL, *bgColor_param = NULL, *exit_param = NULL, _0, _1, _2, _4, _5, _6, _7, _8$$4, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&bgColor);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &text_param, &color_param, &decoration_param, &bgColor_param, &exit_param);

	zephir_get_strval(&text, text_param);
	if (!color_param) {
		ZEPHIR_INIT_VAR(&color);
		ZVAL_STRING(&color, "");
	} else {
		zephir_get_strval(&color, color_param);
	}
	if (!decoration_param) {
		decoration = 0;
	} else {
		decoration = zephir_get_intval(decoration_param);
	}
	if (!bgColor_param) {
		ZEPHIR_INIT_VAR(&bgColor);
		ZVAL_STRING(&bgColor, "");
	} else {
		zephir_get_strval(&bgColor, bgColor_param);
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
		ZVAL_LONG(&_10$$4, decoration);
		ZEPHIR_CALL_CE_STATIC(&_8$$4, ice_cli_console_ce, "color", &_9, 0, &text, &color, &_10$$4, &bgColor);
		zephir_check_call_status();
		zend_print_zval(&_8$$4, 0);
	}
	RETURN_THIS();

}

/**
 * Get script uptime.
 *
 * @param boolean human In seconds if false
 * @return float|string
 */
PHP_METHOD(Ice_Cli_Websocket_Websocket, getUptime) {

	zval _14;
	zend_long s = 0;
	zval *human_param = NULL, __$true, *_SERVER, uptime, y, m, d, h, i, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13;
	zend_bool human;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
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

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 1, &human_param);

	if (!human_param) {
		human = 1;
	} else {
		human = zephir_get_boolval(human_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_microtime(&_0, &__$true TSRMLS_CC);
	zephir_array_fetch_string(&_1, _SERVER, SL("REQUEST_TIME_FLOAT"), PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 336 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&uptime);
	zephir_sub_function(&uptime, &_0, &_1);
	if (!(human)) {
		RETURN_CCTOR(&uptime);
	}
	s = (long) (zephir_safe_mod_zval_long(&uptime, 60 TSRMLS_CC));
	ZVAL_DOUBLE(&_2, zephir_safe_div_double_long((zephir_safe_mod_zval_long(&uptime, 3600 TSRMLS_CC)), (double) (60) TSRMLS_CC));
	ZEPHIR_INIT_VAR(&i);
	ZVAL_DOUBLE(&i, zephir_floor(&_2 TSRMLS_CC));
	ZVAL_DOUBLE(&_3, zephir_safe_div_double_long((zephir_safe_mod_zval_long(&uptime, 86400 TSRMLS_CC)), (double) (3600) TSRMLS_CC));
	ZEPHIR_INIT_VAR(&h);
	ZVAL_DOUBLE(&h, zephir_floor(&_3 TSRMLS_CC));
	ZVAL_DOUBLE(&_4, zephir_safe_div_double_long((zephir_safe_mod_zval_long(&uptime, 2592000 TSRMLS_CC)), (double) (86400) TSRMLS_CC));
	ZEPHIR_INIT_VAR(&d);
	ZVAL_DOUBLE(&d, zephir_floor(&_4 TSRMLS_CC));
	ZVAL_DOUBLE(&_5, zephir_safe_div_zval_long(&uptime, 2592000 TSRMLS_CC));
	ZEPHIR_INIT_VAR(&m);
	ZVAL_DOUBLE(&m, zephir_floor(&_5 TSRMLS_CC));
	ZVAL_DOUBLE(&_6, (zephir_safe_div_zval_long(&uptime, 2592000 TSRMLS_CC) * (double) (12)));
	ZEPHIR_INIT_VAR(&y);
	ZVAL_DOUBLE(&y, zephir_floor(&_6 TSRMLS_CC));
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
		ZEPHIR_SINIT_VAR(_13);
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
PHP_METHOD(Ice_Cli_Websocket_Websocket, getMemoryUsage) {

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
	zephir_create_array(&unit, 6, 0 TSRMLS_CC);
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
	ZVAL_DOUBLE(&i, zephir_floor(&_2 TSRMLS_CC));
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_1, 1024);
	zephir_pow_function(&_3, &_1, &i);
	ZEPHIR_SINIT_VAR(_4);
	div_function(&_4, &size, &_3 TSRMLS_CC);
	ZVAL_LONG(&_5, 2);
	zephir_round(&_0, &_4, &_5, NULL TSRMLS_CC);
	zephir_array_fetch(&_6, &unit, &i, PH_NOISY | PH_READONLY, "ice/cli/websocket/websocket.zep", 376 TSRMLS_CC);
	ZEPHIR_CONCAT_VV(return_value, &_0, &_6);
	RETURN_MM();

}

void zephir_init_static_properties_Ice_Cli_Websocket_Websocket(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 6, 0 TSRMLS_CC);
	add_assoc_long_ex(&_0, SL("continuation"), 0);
	add_assoc_long_ex(&_0, SL("text"), 1);
	add_assoc_long_ex(&_0, SL("binary"), 2);
	add_assoc_long_ex(&_0, SL("close"), 8);
	add_assoc_long_ex(&_0, SL("ping"), 9);
	add_assoc_long_ex(&_0, SL("pong"), 10);
	zend_update_static_property(ice_cli_websocket_websocket_ce, ZEND_STRL("opcodes"), &_0);
	ZEPHIR_MM_RESTORE();

}

