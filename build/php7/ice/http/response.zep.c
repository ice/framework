
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
 * @param string body The HTTP response body
 * @param int status The HTTP response status
 */
PHP_METHOD(Ice_Http_Response, __construct) {

	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *body_param = NULL, *status_param = NULL, _0, _1, _2, _3;
	zval body;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &body_param, &status_param);

	if (!body_param) {
		ZEPHIR_INIT_VAR(&body);
		ZVAL_STRING(&body, "");
	} else {
		zephir_get_strval(&body, body_param);
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
	zephir_update_property_zval(this_ptr, SL("body"), &body);
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
	ZEPHIR_MM_RESTORE();

}

/**
 * Set multiple header values.
 *
 * @param array headers
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
	ZEPHIR_MM_RESTORE();

}

/**
 * Remove header by index name.
 *
 * @param string name
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
	ZEPHIR_MM_RESTORE();

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
 * @return Response
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
 * @return Response
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

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 98);
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
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 99, &_9$$4);
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
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 99, &_17$$5);
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
 * Redirect to some location.
 * This method prepares the response object to return an HTTP Redirect response to the client.
 *
 * @param string location The redirect destination
 * @param int status The redirect HTTP status code
 * @return object this
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
	RETURN_CCTOR(_1);

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
 * Magic toString, convert response to string.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Response, __toString) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

