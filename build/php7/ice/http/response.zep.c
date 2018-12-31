
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/exit.h"
#include "kernel/concat.h"


/**
 * This class provides a simple interface around the HTTP response.
 *
 * @package     Ice/Http
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Ice\\Http, Response, ice, http_response, ice_http_response_method_entry, 0);

	zend_declare_property_string(ice_http_response_ce, SL("protocolVersion"), "HTTP/1.1", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_http_response_ce, SL("status"), 200, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_response_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_http_response_ce, SL("loops"), 16, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_http_response_ce, SL("redirects"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_response_ce, SL("body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_http_response_ce TSRMLS_CC, 1, ice_http_response_responseinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Http_Response, getProtocolVersion) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "protocolVersion");

}

PHP_METHOD(Ice_Http_Response, setProtocolVersion) {

	zval *protocolVersion, protocolVersion_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&protocolVersion_sub);

	zephir_fetch_params(0, 1, 0, &protocolVersion);



	zephir_update_property_zval(this_ptr, SL("protocolVersion"), protocolVersion);
	RETURN_THISW();

}

PHP_METHOD(Ice_Http_Response, getStatus) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "status");

}

PHP_METHOD(Ice_Http_Response, setStatus) {

	zval *status, status_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&status_sub);

	zephir_fetch_params(0, 1, 0, &status);



	zephir_update_property_zval(this_ptr, SL("status"), status);
	RETURN_THISW();

}

PHP_METHOD(Ice_Http_Response, getLoops) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "loops");

}

PHP_METHOD(Ice_Http_Response, setLoops) {

	zval *loops, loops_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&loops_sub);

	zephir_fetch_params(0, 1, 0, &loops);



	zephir_update_property_zval(this_ptr, SL("loops"), loops);
	RETURN_THISW();

}

PHP_METHOD(Ice_Http_Response, getRedirects) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "redirects");

}

PHP_METHOD(Ice_Http_Response, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

PHP_METHOD(Ice_Http_Response, setBody) {

	zval *body, body_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);

	zephir_fetch_params(0, 1, 0, &body);



	zephir_update_property_zval(this_ptr, SL("body"), body);
	RETURN_THISW();

}

/**
 * Response constructor. Fetch Di and set it as a property.
 *
 * @param string|null body The HTTP response body
 * @param int status The HTTP response status
 */
PHP_METHOD(Ice_Http_Response, __construct) {

	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *body = NULL, body_sub, *status_param = NULL, __$null, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &body, &status_param);

	if (!body) {
		body = &body_sub;
		body = &__$null;
	}
	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, ice_http_response_headers_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 4);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("headers"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, status);
	zephir_update_property_zval(this_ptr, SL("status"), &_1);
	zephir_update_property_zval(this_ptr, SL("body"), body);
	zephir_read_property(&_1, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Content-Type");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "text/html");
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get HTTP headers.
 *
 * @return array
 */
PHP_METHOD(Ice_Http_Response, getHeaders) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "all", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether request have a given header.
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, hasHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get header value.
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Ice_Http_Response, getHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set header value.
 *
 * @param string name
 * @param string value
 * @return object Response
 */
PHP_METHOD(Ice_Http_Response, setHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value_param = NULL, _0;
	zval name, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(&name, name_param);
	zephir_get_strval(&value, value_param);


	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &name, &value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set multiple header values.
 *
 * @param array headers
 * @return object Response
 */
PHP_METHOD(Ice_Http_Response, setHeaders) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, _0;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(&headers, headers_param);


	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "replace", NULL, 0, &headers);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Remove header by index name.
 *
 * @param string name
 * @return object Response     
 */
PHP_METHOD(Ice_Http_Response, removeHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "remove", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set body content.
 *
 * @param string content
 * @return object Response
 */
PHP_METHOD(Ice_Http_Response, setContent) {

	zval *contet_param = NULL;
	zval contet;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contet);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &contet_param);

	zephir_get_strval(&contet, contet_param);


	zephir_update_property_zval(this_ptr, SL("body"), &contet);
	RETURN_THIS();

}

/**
 * Finalize response for delivery to client.
 * Apply final preparations to the resposne object so that it is suitable for delivery to the client.
 *
 * @param RequestInterface request
 * @return object Response
 */
PHP_METHOD(Ice_Http_Response, finalize) {

	zval _1;
	zend_bool sendBody = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0, _2, _6, _3$$3, _4$$3, _5$$3, _7$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	sendBody = 1;
	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, 204);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 304);
	zephir_array_fast_append(&_1, &_2);
	if (zephir_fast_in_array(&_0, &_1 TSRMLS_CC)) {
		zephir_read_property(&_3$$3, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Content-Type");
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "remove", NULL, 0, &_4$$3);
		zephir_check_call_status();
		zephir_read_property(&_5$$3, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Content-Length");
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "remove", NULL, 0, &_4$$3);
		zephir_check_call_status();
		sendBody = 0;
	}
	ZEPHIR_CALL_METHOD(&_6, request, "ishead", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		sendBody = 0;
	}
	if (!(sendBody)) {
		ZEPHIR_INIT_VAR(&_7$$5);
		ZEPHIR_INIT_NVAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "");
		zephir_update_property_zval(this_ptr, SL("body"), &_7$$5);
	}
	RETURN_THIS();

}

/**
 * Send HTTP response headers.
 *
 * @return object Response
 */
PHP_METHOD(Ice_Http_Response, send) {

	zend_bool _21$$3;
	zval _0, _1$$3, _2$$3, _3$$3, di$$3, _19$$3, _20$$3, _22$$3, _25$$3, _4$$4, _5$$4, _6$$4, _8$$4, _9$$4, _12$$5, _13$$5, _14$$5, _15$$5, _16$$5, _17$$5, _23$$6, _24$$6;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL, *_11 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&di$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 125);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_GET_CONSTANT(&_1$$3, "PHP_SAPI");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "cgi");
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_fast_strpos(&_3$$3, &_1$$3, &_2$$3, 0 );
		if (ZEPHIR_IS_LONG_IDENTICAL(&_3$$3, 0)) {
			zephir_read_property(&_4$$4, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_6$$4, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getmessage", &_7, 0, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "Status: %d %s");
			ZEPHIR_CALL_FUNCTION(&_9$$4, "sprintf", &_10, 11, &_8$$4, &_4$$4, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 126, &_9$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getprotocolversion", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_13$$5, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_15$$5, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "getmessage", &_7, 0, &_15$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_16$$5);
			ZVAL_STRING(&_16$$5, "%s %d %s");
			ZEPHIR_CALL_FUNCTION(&_17$$5, "sprintf", &_10, 11, &_16$$5, &_12$$5, &_13$$5, &_14$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 126, &_17$$5);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_CE_STATIC(&di$$3, ice_di_ce, "fetch", &_18, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_20$$3);
		ZVAL_STRING(&_20$$3, "session");
		ZEPHIR_CALL_METHOD(&_19$$3, &di$$3, "has", NULL, 0, &_20$$3);
		zephir_check_call_status();
		_21$$3 = zephir_is_true(&_19$$3);
		if (_21$$3) {
			ZEPHIR_CALL_METHOD(&_22$$3, this_ptr, "isredirect", NULL, 0);
			zephir_check_call_status();
			_21$$3 = !zephir_is_true(&_22$$3);
		}
		if (_21$$3) {
			ZEPHIR_INIT_VAR(&_24$$6);
			ZVAL_STRING(&_24$$6, "session");
			ZEPHIR_CALL_METHOD(&_23$$6, &di$$3, "get", NULL, 0, &_24$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_24$$6);
			ZVAL_STRING(&_24$$6, "_redirects");
			ZEPHIR_CALL_METHOD(NULL, &_23$$6, "remove", NULL, 0, &_24$$6);
			zephir_check_call_status();
		}
		zephir_read_property(&_25$$3, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_25$$3, "send", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Send file download as the response. All execution will be halted when
 * this method is called! The third parameter allows the following
 * options to be set:
 *
 * Type      | Option    | Description                        | Default Value
 * ----------|-----------|------------------------------------|--------------
 * string    | file      | file that already exists           | null
 * boolean   | inline    | Display inline instead of download | FALSE
 * boolean   | resumable | Allow to resumable download        | FALSE
 * boolean   | delete    | Delete the file after sending      | FALSE
 * int       | timeout   | Execute time for the script        | 0
 * int       | speed     | Download speed in millisecond      | 0
 *
 * Download a file that already exists:
 *
 *     $request->sendFile('ice.zip', 'application/zip', ['file' => '/download/latest.zip']);
 *
 * Download generated content as a file:
 *
 *     $response->setContent($content);
 *     $response->sendFile($filename, $mineType);
 *
 * Attention: No further processing can be done after this method is called!
 *
 * @param string filename The file name of the attachment
 * @param string mime Manual mime type
 * @param array options The keys can be [file|inline|resumable|delete|timeout|speed]
 * @return  void
 */
PHP_METHOD(Ice_Http_Response, sendFile) {

	zend_bool _19$$9, _45$$17;
	zephir_fcall_cache_entry *_35 = NULL, *_36 = NULL, *_39 = NULL, *_44 = NULL, *_47 = NULL, *_51 = NULL, *_52 = NULL, *_54 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, block = 0, speed = 0;
	zval options, _6$$5;
	zval *filename_param = NULL, *mime_param = NULL, *options_param = NULL, __$true, file, filepath, data, size, isDelete, disposition, pos, range, start, end, _0, _8, _9, _29, _30, _31, _32, _33, _34, _37, _42, _1$$3, _3$$4, _4$$4, _5$$5, _7$$5, _10$$8, _11$$8, _12$$9, _21$$9, _22$$9, _23$$9, _24$$9, _25$$9, _26$$9, _27$$9, _28$$9, _13$$10, _14$$10, _15$$10, _16$$10, _17$$10, _18$$10, _20$$11, _38$$13, _40$$14, _41$$14, _43$$15, _46$$17, _49$$17, _50$$17, _48$$19, _53$$20, _55$$21, _56$$21;
	zval filename, mime, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&mime);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&isDelete);
	ZVAL_UNDEF(&disposition);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&range);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_41$$14);
	ZVAL_UNDEF(&_43$$15);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_49$$17);
	ZVAL_UNDEF(&_50$$17);
	ZVAL_UNDEF(&_48$$19);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_56$$21);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &filename_param, &mime_param, &options_param);

	zephir_get_strval(&filename, filename_param);
	zephir_get_strval(&mime, mime_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_array_fetch_string(&_0, &options, SL("file"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 221 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("body"), PH_NOISY_CC);
		zephir_get_strval(&_2$$3, &_1$$3);
		ZEPHIR_CPY_WRT(&data, &_2$$3);
		ZEPHIR_INIT_VAR(&size);
		ZVAL_LONG(&size, zephir_fast_strlen_ev(&data));
		ZEPHIR_CALL_FUNCTION(&file, "tmpfile", NULL, 127);
		zephir_check_call_status();
		zephir_fwrite(NULL, &file, &data TSRMLS_CC);
		ZEPHIR_INIT_VAR(&isDelete);
		ZVAL_BOOL(&isDelete, 0);
	} else {
		zephir_array_fetch_string(&_3$$4, &options, SL("file"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 237 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&filepath, "realpath", NULL, 128, &_3$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&size, "filesize", NULL, 129, &filepath);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "rb");
		ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 112, &filepath, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&isDelete);
		zephir_array_isset_string_fetch(&isDelete, &options, SL("delete"), 0);
	}
	if (!(Z_TYPE_P(&file) == IS_RESOURCE)) {
		ZEPHIR_INIT_VAR(&_5$$5);
		object_init_ex(&_5$$5, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_create_array(&_6$$5, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "Could not read file to send: %s");
		zephir_array_fast_append(&_6$$5, &_7$$5);
		zephir_array_fast_append(&_6$$5, &filename);
		ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 12, &_6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$5, "ice/http/response.zep", 249 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_8, &options, SL("inline"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 252 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&disposition);
	if (ZEPHIR_IS_EMPTY(&_8)) {
		ZVAL_STRING(&disposition, "attachment");
	} else {
		ZVAL_STRING(&disposition, "inline");
	}
	zephir_array_fetch_string(&_9, &options, SL("resumable"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 258 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(&_9)) {
		zephir_read_property(&_10$$8, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$8);
		ZVAL_STRING(&_11$$8, "Content-Length");
		ZEPHIR_CALL_METHOD(NULL, &_10$$8, "set", NULL, 0, &_11$$8, &size);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&range, this_ptr, "getbyterange", NULL, 0, &size);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&start);
		zephir_array_fetch_long(&start, &range, 0, PH_NOISY, "ice/http/response.zep", 263 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&end);
		zephir_array_fetch_long(&end, &range, 1, PH_NOISY, "ice/http/response.zep", 264 TSRMLS_CC);
		zephir_read_property(&_12$$9, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_LONG(&_12$$9, 416)) {
			ZEPHIR_CALL_METHOD(&_13$$10, this_ptr, "getprotocolversion", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_14$$10, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_16$$10, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_15$$10, this_ptr, "getmessage", NULL, 0, &_16$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_17$$10);
			ZVAL_STRING(&_17$$10, "%s %d %s");
			ZEPHIR_CALL_FUNCTION(&_18$$10, "sprintf", NULL, 11, &_17$$10, &_13$$10, &_14$$10, &_15$$10);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 126, &_18$$10);
			zephir_check_call_status();
			ZEPHIR_MM_RESTORE();
			zephir_exit_empty();
		}
		_19$$9 = ZEPHIR_GT_LONG(&start, 0);
		if (!(_19$$9)) {
			_19$$9 = ZEPHIR_LT_LONG(&end, (zephir_get_numberval(&size) - 1));
		}
		if (_19$$9) {
			ZEPHIR_INIT_ZVAL_NREF(_20$$11);
			ZVAL_LONG(&_20$$11, 206);
			zephir_update_property_zval(this_ptr, SL("status"), &_20$$11);
		}
		zephir_read_property(&_21$$9, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_22$$9);
		ZVAL_STRING(&_22$$9, "Accept-Ranges");
		ZEPHIR_INIT_VAR(&_23$$9);
		ZVAL_STRING(&_23$$9, "bytes");
		ZEPHIR_CALL_METHOD(NULL, &_21$$9, "set", NULL, 0, &_22$$9, &_23$$9);
		zephir_check_call_status();
		zephir_read_property(&_24$$9, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_25$$9);
		ZEPHIR_CONCAT_SVSVSV(&_25$$9, "bytes ", &start, "-", &end, "/", &size);
		ZEPHIR_INIT_NVAR(&_22$$9);
		ZVAL_STRING(&_22$$9, "Content-Range");
		ZEPHIR_CALL_METHOD(NULL, &_24$$9, "set", NULL, 0, &_22$$9, &_25$$9);
		zephir_check_call_status();
		zephir_read_property(&_26$$9, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_SINIT_VAR(_27$$9);
		zephir_sub_function(&_27$$9, &end, &start);
		ZEPHIR_INIT_NVAR(&_22$$9);
		ZVAL_STRING(&_22$$9, "Content-Length");
		ZVAL_LONG(&_28$$9, (zephir_get_numberval(&_27$$9) + 1));
		ZEPHIR_CALL_METHOD(NULL, &_26$$9, "set", NULL, 0, &_22$$9, &_28$$9);
		zephir_check_call_status();
	}
	zephir_read_property(&_29, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_30);
	ZEPHIR_CONCAT_VSVS(&_30, &disposition, "; filename=\"", &filename, "\"");
	ZEPHIR_INIT_VAR(&_31);
	ZVAL_STRING(&_31, "Content-Disposition");
	ZEPHIR_CALL_METHOD(NULL, &_29, "set", NULL, 0, &_31, &_30);
	zephir_check_call_status();
	zephir_read_property(&_32, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_31);
	ZVAL_STRING(&_31, "Content-Type");
	ZEPHIR_CALL_METHOD(NULL, &_32, "set", NULL, 0, &_31, &mime);
	zephir_check_call_status();
	zephir_read_property(&_33, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_33, "send", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_FUNCTION(&_34, "ob_get_level", &_35, 119);
		zephir_check_call_status();
		if (!(zephir_is_true(&_34))) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_flush", &_36, 130);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ignore_user_abort", NULL, 131, &__$true);
	zephir_check_call_status();
	zephir_array_fetch_string(&_37, &options, SL("timeout"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 298 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(&_37)) {
		ZVAL_LONG(&_38$$13, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "set_time_limit", &_39, 132, &_38$$13);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_VAR(&_40$$14);
		zephir_array_fetch_string(&_40$$14, &options, SL("timeout"), PH_NOISY, "ice/http/response.zep", 302 TSRMLS_CC);
		ZVAL_LONG(&_41$$14, zephir_get_intval(&_40$$14));
		ZEPHIR_CALL_FUNCTION(NULL, "set_time_limit", &_39, 132, &_41$$14);
		zephir_check_call_status();
	}
	block = 16384;
	zephir_array_fetch_string(&_42, &options, SL("sleep"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 308 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(&_42))) {
		ZEPHIR_OBS_VAR(&_43$$15);
		zephir_array_fetch_string(&_43$$15, &options, SL("sleep"), PH_NOISY, "ice/http/response.zep", 309 TSRMLS_CC);
		speed = (zephir_get_intval(&_43$$15) * 1000);
	} else {
		speed = 0;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "fseek", NULL, 133, &file, &start);
	zephir_check_call_status();
	while (1) {
		if (!(!(zephir_feof(&file TSRMLS_CC)))) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&pos, "ftell", &_44, 134, &file);
		zephir_check_call_status();
		_45$$17 = ZEPHIR_GT(&pos, &end);
		if (!(_45$$17)) {
			ZEPHIR_CALL_FUNCTION(&_46$$17, "connection_aborted", &_47, 135);
			zephir_check_call_status();
			_45$$17 = zephir_is_true(&_46$$17);
		}
		if (_45$$17) {
			break;
		}
		if (ZEPHIR_LT_LONG(&end, (zephir_get_numberval(&pos) + block))) {
			ZEPHIR_SINIT_NVAR(_48$$19);
			zephir_sub_function(&_48$$19, &end, &pos);
			block = (zephir_get_numberval(&_48$$19) + 1);
		}
		ZVAL_LONG(&_49$$17, block);
		ZEPHIR_CALL_FUNCTION(&_50$$17, "fread", &_51, 30, &file, &_49$$17);
		zephir_check_call_status();
		zend_print_zval(&_50$$17, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "flush", &_52, 136);
		zephir_check_call_status();
		if (speed > 0) {
			ZVAL_LONG(&_53$$20, speed);
			ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_54, 32, &_53$$20);
			zephir_check_call_status();
		}
	}
	zephir_fclose(&file TSRMLS_CC);
	if (zephir_is_true(&isDelete)) {

		/* try_start_1: */

			ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 137, &filepath);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_55$$21);
			ZVAL_OBJ(&_55$$21, EG(exception));
			Z_ADDREF_P(&_55$$21);
			ZEPHIR_INIT_VAR(&_56$$21);
			if (zephir_instance_of_ev(&_55$$21, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&_56$$21, &_55$$21);
			}
		}
	}
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();

}

/**
 * Redirect to some location.
 * This method prepares the response object to return an HTTP Redirect response to the client.
 *
 * @param string location The redirect destination
 * @param int status The redirect HTTP status code
 * @return object Response
 */
PHP_METHOD(Ice_Http_Response, redirect) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_bool external, _6;
	zend_long status, ZEPHIR_LAST_CALL_STATUS, redirects = 0;
	zval *location_param = NULL, *status_param = NULL, *external_param = NULL, url, di, _1, _4, _5, _11, _2$$3, _3$$3, session$$4, _7$$4, _8$$4, _9$$4, _10$$4;
	zval location;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&session$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &location_param, &status_param, &external_param);

	if (!location_param) {
		ZEPHIR_INIT_VAR(&location);
		ZVAL_STRING(&location, "");
	} else {
		zephir_get_strval(&location, location_param);
	}
	if (!status_param) {
		status = 302;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!external_param) {
		external = 0;
	} else {
		external = zephir_get_boolval(external_param);
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, status);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatus", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(external)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "url");
		ZEPHIR_CALL_METHOD(&url, &di, "get", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, &url, "get", NULL, 0, &location);
		zephir_check_call_status();
		zephir_get_strval(&location, &_3$$3);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "session");
	ZEPHIR_CALL_METHOD(&_4, &di, "has", NULL, 0, &_5);
	zephir_check_call_status();
	_6 = zephir_is_true(&_4);
	if (_6) {
		zephir_read_property(&_1, this_ptr, SL("loops"), PH_NOISY_CC | PH_READONLY);
		_6 = zephir_is_true(&_1);
	}
	if (_6) {
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "session");
		ZEPHIR_CALL_METHOD(&session$$4, &di, "get", NULL, 0, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "_redirects");
		ZVAL_LONG(&_9$$4, 0);
		ZEPHIR_CALL_METHOD(&_8$$4, &session$$4, "get", NULL, 0, &_7$$4, &_9$$4);
		zephir_check_call_status();
		redirects = (zephir_get_intval(&_8$$4) + 1);
		ZEPHIR_INIT_ZVAL_NREF(_9$$4);
		ZVAL_LONG(&_9$$4, redirects);
		zephir_update_property_zval(this_ptr, SL("redirects"), &_9$$4);
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "_redirects");
		ZVAL_LONG(&_9$$4, redirects);
		ZEPHIR_CALL_METHOD(NULL, &session$$4, "set", NULL, 0, &_7$$4, &_9$$4);
		zephir_check_call_status();
		zephir_read_property(&_9$$4, this_ptr, SL("redirects"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_10$$4, this_ptr, SL("loops"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT(&_9$$4, &_10$$4)) {
			RETURN_THIS();
		}
	}
	zephir_read_property(&_11, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "Location");
	ZEPHIR_CALL_METHOD(NULL, &_11, "set", NULL, 0, &_5, &location);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Check whether status is for Empty.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isEmpty) {

	zval _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, 201);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 204);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 304);
	zephir_array_fast_append(&_1, &_2);
	RETURN_MM_BOOL(zephir_fast_in_array(&_0, &_1 TSRMLS_CC));

}

/**
 * Check whether status is for Informational.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isInformational) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 100);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 200);
	}
	RETURN_BOOL(_1);

}

/**
 * Check whether status is for OK.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isOk) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 200));

}

/**
 * Check whether status is for Successful.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isSuccessful) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 200);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 300);
	}
	RETURN_BOOL(_1);

}

/**
 * Check whether status is for Redirect.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isRedirect) {

	zval _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, 301);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 302);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 303);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 307);
	zephir_array_fast_append(&_1, &_2);
	RETURN_MM_BOOL(zephir_fast_in_array(&_0, &_1 TSRMLS_CC));

}

/**
 * Check whether status is for Redirection.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isRedirection) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 300);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 400);
	}
	RETURN_BOOL(_1);

}

/**
 * Check whether status is for Forbidden.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isForbidden) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 403));

}

/**
 * Check whether status is for Not Found.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isNotFound) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 404));

}

/**
 * Check whether status is for Client error.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isClientError) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 400);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 500);
	}
	RETURN_BOOL(_1);

}

/**
 * Check whether status is for Server Error.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isServerError) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 500);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("status"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 600);
	}
	RETURN_BOOL(_1);

}

/**
 * Get message for Response codes.
 *
 * @param int code Status code
 * @return string
 */
PHP_METHOD(Ice_Http_Response, getMessage) {

	zval *code_param = NULL, message, _0, _1;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &code_param);

	if (!code_param) {
		code = 200;
	} else {
		code = zephir_get_intval(code_param);
	}


	ZEPHIR_OBS_VAR(&message);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessages", NULL, 0);
	zephir_check_call_status();
	zephir_array_isset_long_fetch(&message, &_0, code, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_is_true(&message)) {
		ZEPHIR_CPY_WRT(&_1, &message);
	} else {
		ZVAL_STRING(&_1, "");
	}
	RETURN_CCTOR(&_1);

}

/**
 * Get all messages.
 *
 * @return array
 */
PHP_METHOD(Ice_Http_Response, getMessages) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 61, 0 TSRMLS_CC);
	add_index_stringl(return_value, 100, SL("Continue"));
	add_index_stringl(return_value, 101, SL("Switching Protocols"));
	add_index_stringl(return_value, 102, SL("Processing"));
	add_index_stringl(return_value, 200, SL("OK"));
	add_index_stringl(return_value, 201, SL("Created"));
	add_index_stringl(return_value, 202, SL("Accepted"));
	add_index_stringl(return_value, 203, SL("Non-Authoritative Information"));
	add_index_stringl(return_value, 204, SL("No Content"));
	add_index_stringl(return_value, 205, SL("Reset Content"));
	add_index_stringl(return_value, 206, SL("Partial Content"));
	add_index_stringl(return_value, 207, SL("Multi-Status"));
	add_index_stringl(return_value, 208, SL("Already Reported"));
	add_index_stringl(return_value, 226, SL("IM Used"));
	add_index_stringl(return_value, 300, SL("Multiple Choices"));
	add_index_stringl(return_value, 301, SL("Moved Permanently"));
	add_index_stringl(return_value, 302, SL("Found"));
	add_index_stringl(return_value, 303, SL("See Other"));
	add_index_stringl(return_value, 304, SL("Not Modified"));
	add_index_stringl(return_value, 305, SL("Use Proxy"));
	add_index_stringl(return_value, 306, SL("(Unused)"));
	add_index_stringl(return_value, 307, SL("Temporary Redirect"));
	add_index_stringl(return_value, 308, SL("Permanent Redirect"));
	add_index_stringl(return_value, 310, SL("Too Many Redirects"));
	add_index_stringl(return_value, 400, SL("Bad Request"));
	add_index_stringl(return_value, 401, SL("Unauthorized"));
	add_index_stringl(return_value, 402, SL("Payment Required"));
	add_index_stringl(return_value, 403, SL("Forbidden"));
	add_index_stringl(return_value, 404, SL("Not Found"));
	add_index_stringl(return_value, 405, SL("Method Not Allowed"));
	add_index_stringl(return_value, 406, SL("Not Acceptable"));
	add_index_stringl(return_value, 407, SL("Proxy Authentication Required"));
	add_index_stringl(return_value, 408, SL("Request Timeout"));
	add_index_stringl(return_value, 409, SL("Conflict"));
	add_index_stringl(return_value, 410, SL("Gone"));
	add_index_stringl(return_value, 411, SL("Length Required"));
	add_index_stringl(return_value, 412, SL("Precondition Failed"));
	add_index_stringl(return_value, 413, SL("Request Entity Too Large"));
	add_index_stringl(return_value, 414, SL("Request-URI Too Long"));
	add_index_stringl(return_value, 415, SL("Unsupported Media Type"));
	add_index_stringl(return_value, 416, SL("Requested Range Not Satisfiable"));
	add_index_stringl(return_value, 417, SL("Expectation Failed"));
	add_index_stringl(return_value, 418, SL("I'm a teapot"));
	add_index_stringl(return_value, 422, SL("Unprocessable Entity"));
	add_index_stringl(return_value, 423, SL("Locked"));
	add_index_stringl(return_value, 424, SL("Failed Dependency"));
	add_index_stringl(return_value, 426, SL("Upgrade Required"));
	add_index_stringl(return_value, 428, SL("Precondition Required"));
	add_index_stringl(return_value, 429, SL("Too Many Requests"));
	add_index_stringl(return_value, 431, SL("Request Header Fields Too Large"));
	add_index_stringl(return_value, 500, SL("Internal Server Error"));
	add_index_stringl(return_value, 501, SL("Not Implemented"));
	add_index_stringl(return_value, 502, SL("Bad Gateway"));
	add_index_stringl(return_value, 503, SL("Service Unavailable"));
	add_index_stringl(return_value, 504, SL("Gateway Timeout"));
	add_index_stringl(return_value, 505, SL("HTTP Version Not Supported"));
	add_index_stringl(return_value, 506, SL("Variant Also Negotiates"));
	add_index_stringl(return_value, 507, SL("Insufficient Storage"));
	add_index_stringl(return_value, 508, SL("Loop Detected"));
	add_index_stringl(return_value, 510, SL("Not Extended"));
	add_index_stringl(return_value, 511, SL("Network Authentication Required"));
	return;

}

/**
 * Response data to JSON string.
 *
 * @param mixed data Can be any type excepta resource
 * @param int option The options for json_encode
 * @return object Response
 */
PHP_METHOD(Ice_Http_Response, toJson) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, *option = NULL, option_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&option_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &option);

	if (!option) {
		option = &option_sub;
		option = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Content-Type");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "application/json;charset=utf-8");
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	zephir_json_encode(&_1, data, zephir_get_intval(option) );
	zephir_update_property_zval(this_ptr, SL("body"), &_1);
	RETURN_THIS();

}

/**
 * Response data to XML string.
 *
 * <pre><code>
 *     $response->toXml(
 *         [['title' => 'hello world', 'desc' => 'dont panic']],
 *         ['root' => 'blogs', 'namespace' => 'http://example.com/xml/blog']
 *     );
 *
 *     // This will output the xml
 *     <?xml version="1.0"?><blogs xmlns="http://example.com/xml/blog">
 *     <blog><title>hello world</title><desc>dont panic</desc></blog></blogs>
 * </code></pre>
 *
 * @param mixed data Can be any type excepta resource
 * @param array options The options can be [root|charset|namespace]
 * @return object Response
 */
PHP_METHOD(Ice_Http_Response, toXml) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, *options = NULL, options_sub, __$true, __$false, __$null, doc, ns, rootName, charset, _1, _2, _3, _4, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&doc);
	ZVAL_UNDEF(&ns);
	ZVAL_UNDEF(&rootName);
	ZVAL_UNDEF(&charset);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &options);

	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	if (zephir_array_isset_string(options, SL("root"))) {
		ZEPHIR_OBS_VAR(&rootName);
		zephir_array_fetch_string(&rootName, options, SL("root"), PH_NOISY, "ice/http/response.zep", 623 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&rootName);
		ZVAL_STRING(&rootName, "result");
	}
	if (zephir_array_isset_string(options, SL("charset"))) {
		ZEPHIR_OBS_VAR(&charset);
		zephir_array_fetch_string(&charset, options, SL("charset"), PH_NOISY, "ice/http/response.zep", 624 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&charset);
		ZVAL_STRING(&charset, "utf-8");
	}
	ZEPHIR_CALL_METHOD(&doc, this_ptr, "xmlencode", NULL, 0, data, &rootName);
	zephir_check_call_status();
	if (0) {
		zephir_update_property_zval(&doc, SL("preserveWhiteSpace"), &__$true);
	} else {
		zephir_update_property_zval(&doc, SL("preserveWhiteSpace"), &__$false);
	}
	if (1) {
		zephir_update_property_zval(&doc, SL("formatOutput"), &__$true);
	} else {
		zephir_update_property_zval(&doc, SL("formatOutput"), &__$false);
	}
	zephir_update_property_zval(&doc, SL("encoding"), &charset);
	ZEPHIR_OBS_VAR(&ns);
	if (zephir_array_isset_string_fetch(&ns, options, SL("namespace"), 0)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "xmlns");
		ZEPHIR_CALL_METHOD(NULL, &doc, "createattributens", NULL, 0, &ns, &_0$$3);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "application/xml;charset=", &charset);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Content-Type");
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &doc, "savexml", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("body"), &_4);
	RETURN_THIS();

}

/**
 * Convert data to XML string.
 *
 * @param mixed data Can be any type excepta resource
 * @param string root The root tag name
 * @param DOMElement domNode null, ONLY FOR INTERNAL USE
 * @return DOMDocument domDoc object
 */
PHP_METHOD(Ice_Http_Response, xmlEncode) {

	zend_bool _18$$9;
	zend_string *_5$$4, *_17$$8;
	zend_ulong _4$$4, _16$$8;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval root;
	zval *data = NULL, data_sub, *root_param = NULL, *domNode = NULL, domNode_sub, __$null, domDoc, type, key, val, node, _2, _0$$3, *_3$$4, _6$$6, _7$$6, _8$$6, _9$$6, _11$$5, _12$$8, _13$$8, _14$$8, *_15$$8, _19$$10, _20$$13, _21$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&domNode_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&domDoc);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&root);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &data, &root_param, &domNode);

	ZEPHIR_SEPARATE_PARAM(data);
	if (!root_param) {
		ZEPHIR_INIT_VAR(&root);
		ZVAL_STRING(&root, "root");
	} else {
		zephir_get_strval(&root, root_param);
	}
	if (!domNode) {
		domNode = &domNode_sub;
		ZEPHIR_CPY_WRT(domNode, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(domNode);
	}


	if (Z_TYPE_P(domNode) == IS_NULL) {
		ZEPHIR_INIT_VAR(&domDoc);
		object_init_ex(&domDoc, zephir_get_internal_ce(SL("domdocument")));
		ZEPHIR_CALL_METHOD(NULL, &domDoc, "__construct", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(domNode, &domDoc, "createelement", NULL, 0, &root);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &domDoc, "appendchild", NULL, 0, domNode);
		zephir_check_call_status();
		ZVAL_NULL(&_0$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "xmlencode", &_1, 138, data, &_0$$3, domNode);
		zephir_check_call_status();
		RETURN_CCTOR(&domDoc);
	}
	ZEPHIR_OBS_NVAR(&domDoc);
	zephir_read_property(&domDoc, domNode, SL("ownerDocument"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_2);
	zephir_gettype(&_2, data TSRMLS_CC);
	ZEPHIR_CPY_WRT(&type, &_2);
	if (ZEPHIR_IS_STRING(&type, "array")) {
		zephir_is_iterable(data, 0, "ice/http/response.zep", 678);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _5$$4);
			} else {
				ZVAL_LONG(&key, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _3$$4);
			if (Z_TYPE_P(&key) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&_6$$6);
				zephir_read_property(&_7$$6, domNode, SL("tagName"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_8$$6);
				ZVAL_STRING(&_8$$6, "s");
				zephir_fast_trim(&_6$$6, &_7$$6, &_8$$6, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&node, &domDoc, "createelement", NULL, 0, &_6$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$6);
				ZVAL_STRING(&_9$$6, "i");
				ZEPHIR_CALL_METHOD(NULL, &node, "setattribute", NULL, 0, &_9$$6, &key);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&node, &domDoc, "createelement", NULL, 0, &key);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(NULL, domNode, "appendchild", &_10, 0, &node);
			zephir_check_call_status();
			ZVAL_NULL(&_11$$5);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "xmlencode", &_1, 138, &val, &_11$$5, &node);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val);
		ZEPHIR_INIT_NVAR(&key);
	} else if (ZEPHIR_IS_STRING(&type, "object")) {
		ZEPHIR_INIT_VAR(&_12$$8);
		ZVAL_STRING(&_12$$8, "__is__");
		ZEPHIR_INIT_VAR(&_13$$8);
		ZVAL_STRING(&_13$$8, "obj");
		ZEPHIR_CALL_METHOD(NULL, domNode, "setattribute", NULL, 0, &_12$$8, &_13$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_14$$8, "get_object_vars", NULL, 106, data);
		zephir_check_call_status();
		zephir_is_iterable(&_14$$8, 0, "ice/http/response.zep", 691);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_14$$8), _16$$8, _17$$8, _15$$8)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_17$$8 != NULL) { 
				ZVAL_STR_COPY(&key, _17$$8);
			} else {
				ZVAL_LONG(&key, _16$$8);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _15$$8);
			_18$$9 = Z_TYPE_P(&val) == IS_ARRAY;
			if (!(_18$$9)) {
				_18$$9 = Z_TYPE_P(&val) == IS_OBJECT;
			}
			if (_18$$9) {
				ZEPHIR_CALL_METHOD(&node, &domDoc, "createelement", NULL, 0, &key);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, domNode, "appendchild", &_10, 0, &node);
				zephir_check_call_status();
				ZVAL_NULL(&_19$$10);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "xmlencode", &_1, 138, &val, &_19$$10, &node);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, domNode, "setattribute", NULL, 0, &key, &val);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		if (ZEPHIR_IS_STRING(&type, "boolean")) {
			ZEPHIR_INIT_VAR(&_20$$13);
			if (zephir_is_true(data)) {
				ZEPHIR_INIT_NVAR(&_20$$13);
				ZVAL_STRING(&_20$$13, "true");
			} else {
				ZEPHIR_INIT_NVAR(&_20$$13);
				ZVAL_STRING(&_20$$13, "false");
			}
			ZEPHIR_CPY_WRT(data, &_20$$13);
		}
		ZEPHIR_CALL_METHOD(&_21$$12, &domDoc, "createtextnode", NULL, 0, data);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, domNode, "appendchild", &_10, 0, &_21$$12);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic toString, convert response to string.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Response, __toString) {

	zval _1;
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("body"), PH_NOISY_CC);
	zephir_get_strval(&_1, &_0);
	RETURN_CTOR(&_1);

}

/**
 *
 * At the moment we only support single ranges.
 * Multiple ranges requires some more work to ensure it works correctly
 * and comply with the spesifications:
 *    http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.2
 *
 * Multirange support annouces itself with:
 * header('Accept-Ranges: bytes');
 *
 * Multirange content must be sent with multipart/byteranges mediatype,
 * as well as a boundry header to indicate the various chunks of data.
 *
 * @return array The bytes range start and end, error message if there is
 */
PHP_METHOD(Ice_Http_Response, getByteRange) {

	zend_bool _15$$5, _16$$5, _12$$7;
	zephir_fcall_cache_entry *_7 = NULL;
	zval *size_param = NULL, *_SERVER, start, end, range, _0$$3, _1$$3, _2$$4, _3$$5, _4$$5, _5$$6, _6$$6, _8$$7, _9$$7, _10$$7, _11$$7, _13$$7, _14$$8, _17$$10;
	zend_long size, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&range);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_17$$10);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &size_param);

	size = zephir_get_intval(size_param);


	ZEPHIR_INIT_VAR(&start);
	ZVAL_LONG(&start, 0);
	ZEPHIR_INIT_VAR(&end);
	ZVAL_LONG(&end, (size - 1));
	if (zephir_array_isset_string(_SERVER, SL("HTTP_RANGE"))) {
		zephir_array_fetch_string(&_0$$3, _SERVER, SL("HTTP_RANGE"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 733 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&range);
		zephir_fast_explode_str(&range, SL("="), &_0$$3, 2  TSRMLS_CC);
		zephir_array_fetch_long(&_1$$3, &range, 0, PH_NOISY | PH_READONLY, "ice/http/response.zep", 735 TSRMLS_CC);
		if (!ZEPHIR_IS_STRING(&_1$$3, "bytes")) {
			ZEPHIR_INIT_ZVAL_NREF(_2$$4);
			ZVAL_LONG(&_2$$4, 416);
			zephir_update_property_zval(this_ptr, SL("status"), &_2$$4);
		} else {
			zephir_array_fetch_long(&_3$$5, &range, 1, PH_NOISY | PH_READONLY, "ice/http/response.zep", 740 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&range);
			zephir_fast_explode_str(&range, SL(","), &_3$$5, 2  TSRMLS_CC);
			zephir_array_fetch_long(&_4$$5, &range, 0, PH_NOISY | PH_READONLY, "ice/http/response.zep", 740 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&range, &_4$$5);
			zephir_array_fetch_long(&_4$$5, &range, 0, PH_NOISY | PH_READONLY, "ice/http/response.zep", 743 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_4$$5, "-")) {
				ZVAL_LONG(&_5$$6, zephir_get_intval(&range));
				ZEPHIR_CALL_FUNCTION(&_6$$6, "abs", &_7, 139, &_5$$6);
				zephir_check_call_status();
				ZVAL_LONG(&_5$$6, (size - zephir_get_numberval(&_6$$6)));
				ZEPHIR_CALL_FUNCTION(&start, "abs", &_7, 139, &_5$$6);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_8$$7);
				zephir_fast_explode_str(&_8$$7, SL("-"), &range, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(&range, &_8$$7);
				ZEPHIR_OBS_VAR(&_9$$7);
				zephir_array_fetch_long(&_9$$7, &range, 0, PH_NOISY, "ice/http/response.zep", 746 TSRMLS_CC);
				ZVAL_LONG(&_10$$7, zephir_get_intval(&_9$$7));
				ZEPHIR_CALL_FUNCTION(&start, "abs", &_7, 139, &_10$$7);
				zephir_check_call_status();
				zephir_array_fetch_long(&_11$$7, &range, 1, PH_NOISY | PH_READONLY, "ice/http/response.zep", 748 TSRMLS_CC);
				_12$$7 = zephir_is_true(&_11$$7);
				if (_12$$7) {
					zephir_array_fetch_long(&_13$$7, &range, 1, PH_NOISY | PH_READONLY, "ice/http/response.zep", 748 TSRMLS_CC);
					_12$$7 = zephir_is_numeric(&_13$$7);
				}
				if (_12$$7) {
					ZEPHIR_OBS_VAR(&_14$$8);
					zephir_array_fetch_long(&_14$$8, &range, 1, PH_NOISY, "ice/http/response.zep", 749 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&end);
					ZVAL_LONG(&end, zephir_get_intval(&_14$$8));
				}
			}
			if (ZEPHIR_GT_LONG(&end, size)) {
				ZEPHIR_INIT_NVAR(&end);
				ZVAL_LONG(&end, (size - 1));
			}
			_15$$5 = ZEPHIR_GT(&start, &end);
			if (!(_15$$5)) {
				_15$$5 = ZEPHIR_GT_LONG(&start, (size - 1));
			}
			_16$$5 = _15$$5;
			if (!(_16$$5)) {
				_16$$5 = ZEPHIR_GE_LONG(&end, size);
			}
			if (_16$$5) {
				ZEPHIR_INIT_ZVAL_NREF(_17$$10);
				ZVAL_LONG(&_17$$10, 416);
				zephir_update_property_zval(this_ptr, SL("status"), &_17$$10);
			}
		}
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &start);
	zephir_array_fast_append(return_value, &end);
	RETURN_MM();

}

