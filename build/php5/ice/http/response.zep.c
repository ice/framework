
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

	

	RETURN_MEMBER(getThis(), "protocolVersion");

}

PHP_METHOD(Ice_Http_Response, setProtocolVersion) {

	zval *protocolVersion;

	zephir_fetch_params(0, 1, 0, &protocolVersion);



	zephir_update_property_this(getThis(), SL("protocolVersion"), protocolVersion TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Http_Response, getStatus) {

	

	RETURN_MEMBER(getThis(), "status");

}

PHP_METHOD(Ice_Http_Response, setStatus) {

	zval *status;

	zephir_fetch_params(0, 1, 0, &status);



	zephir_update_property_this(getThis(), SL("status"), status TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Http_Response, getLoops) {

	

	RETURN_MEMBER(getThis(), "loops");

}

PHP_METHOD(Ice_Http_Response, setLoops) {

	zval *loops;

	zephir_fetch_params(0, 1, 0, &loops);



	zephir_update_property_this(getThis(), SL("loops"), loops TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Http_Response, getRedirects) {

	

	RETURN_MEMBER(getThis(), "redirects");

}

PHP_METHOD(Ice_Http_Response, getBody) {

	

	RETURN_MEMBER(getThis(), "body");

}

PHP_METHOD(Ice_Http_Response, setBody) {

	zval *body;

	zephir_fetch_params(0, 1, 0, &body);



	zephir_update_property_this(getThis(), SL("body"), body TSRMLS_CC);
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
	zval *body_param = NULL, *status_param = NULL, *_0, *_1, *_2, *_3;
	zval *body = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &body_param, &status_param);

	if (!body_param) {
		ZEPHIR_INIT_VAR(body);
		ZVAL_STRING(body, "", 1);
	} else {
		zephir_get_strval(body, body_param);
	}
	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, ice_http_response_headers_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 5);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("headers"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, status);
	zephir_update_property_this(getThis(), SL("status"), _1 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("body"), body TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "text/html", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _1, "set", NULL, 0, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get HTTP headers.
 *
 * @return array
 */
PHP_METHOD(Ice_Http_Response, getHeaders) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "all", NULL, 0);
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
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "has", NULL, 0, name);
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
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, name);
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
	zval *name_param = NULL, *value_param = NULL, *_0;
	zval *name = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, name, value);
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
	zval *headers_param = NULL, *_0;
	zval *headers = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(headers, headers_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "replace", NULL, 0, headers);
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
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, 0, name);
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
	zval *contet = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &contet_param);

	zephir_get_strval(contet, contet_param);


	zephir_update_property_this(getThis(), SL("body"), contet TSRMLS_CC);
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

	zval *_1;
	zend_bool sendBody = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, *_0, *_2 = NULL, *_6 = NULL, *_3$$3, *_4$$3 = NULL, *_5$$3, *_7$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	sendBody = 1;
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 204);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 304);
	zephir_array_fast_append(_1, _2);
	if (zephir_fast_in_array(_0, _1 TSRMLS_CC)) {
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "remove", NULL, 0, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Content-Length", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "remove", NULL, 0, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		sendBody = 0;
	}
	ZEPHIR_CALL_METHOD(&_6, request, "ishead", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		sendBody = 0;
	}
	if (!(sendBody)) {
		ZEPHIR_INIT_ZVAL_NREF(_7$$5);
		ZVAL_STRING(_7$$5, "", 1);
		zephir_update_property_this(getThis(), SL("body"), _7$$5 TSRMLS_CC);
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
	zval *_0 = NULL, *_1$$3, _2$$3, *_3$$3, *di$$3 = NULL, *_19$$3 = NULL, *_20$$3, *_22$$3 = NULL, *_25$$3, *_4$$4, *_5$$4 = NULL, *_6$$4, _8$$4, *_9$$4 = NULL, *_12$$5 = NULL, *_13$$5, *_14$$5 = NULL, *_15$$5, _16$$5, *_17$$5 = NULL, *_23$$6 = NULL, *_24$$6 = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL, *_11 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 106);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_GET_CONSTANT(_1$$3, "PHP_SAPI");
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "cgi", 0);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_fast_strpos(_3$$3, _1$$3, &_2$$3, 0 );
		if (ZEPHIR_IS_LONG_IDENTICAL(_3$$3, 0)) {
			_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
			_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getmessage", &_7, 0, _6$$4);
			zephir_check_call_status();
			ZEPHIR_SINIT_VAR(_8$$4);
			ZVAL_STRING(&_8$$4, "Status: %d %s", 0);
			ZEPHIR_CALL_FUNCTION(&_9$$4, "sprintf", &_10, 12, &_8$$4, _4$$4, _5$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 107, _9$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getprotocolversion", NULL, 0);
			zephir_check_call_status();
			_13$$5 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
			_15$$5 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "getmessage", &_7, 0, _15$$5);
			zephir_check_call_status();
			ZEPHIR_SINIT_VAR(_16$$5);
			ZVAL_STRING(&_16$$5, "%s %d %s", 0);
			ZEPHIR_CALL_FUNCTION(&_17$$5, "sprintf", &_10, 12, &_16$$5, _12$$5, _13$$5, _14$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 107, _17$$5);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_CE_STATIC(&di$$3, ice_di_ce, "fetch", &_18, 1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_20$$3);
		ZVAL_STRING(_20$$3, "session", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_19$$3, di$$3, "has", NULL, 0, _20$$3);
		zephir_check_temp_parameter(_20$$3);
		zephir_check_call_status();
		_21$$3 = zephir_is_true(_19$$3);
		if (_21$$3) {
			ZEPHIR_CALL_METHOD(&_22$$3, this_ptr, "isredirect", NULL, 0);
			zephir_check_call_status();
			_21$$3 = !zephir_is_true(_22$$3);
		}
		if (_21$$3) {
			ZEPHIR_INIT_VAR(_24$$6);
			ZVAL_STRING(_24$$6, "session", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_23$$6, di$$3, "get", NULL, 0, _24$$6);
			zephir_check_temp_parameter(_24$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_24$$6);
			ZVAL_STRING(_24$$6, "_redirects", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _23$$6, "remove", NULL, 0, _24$$6);
			zephir_check_temp_parameter(_24$$6);
			zephir_check_call_status();
		}
		_25$$3 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _25$$3, "send", NULL, 0);
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
	zend_bool external, _5;
	zend_long status, ZEPHIR_LAST_CALL_STATUS, redirects = 0;
	zval *location_param = NULL, *status_param = NULL, *external_param = NULL, *url = NULL, *di = NULL, *_1 = NULL, *_4 = NULL, *_6, *_12, *_2$$3, *_3$$3 = NULL, *session$$4 = NULL, *_7$$4 = NULL, *_8$$4 = NULL, *_9$$4 = NULL, *_10$$4, *_11$$4;
	zval *location = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &location_param, &status_param, &external_param);

	if (!location_param) {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	} else {
		zephir_get_strval(location, location_param);
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


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, status);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatus", NULL, 0, _1);
	zephir_check_call_status();
	if (!(external)) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&url, di, "get", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, url, "get", NULL, 0, location);
		zephir_check_call_status();
		zephir_get_strval(location, _3$$3);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, di, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_5 = zephir_is_true(_4);
	if (_5) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("loops"), PH_NOISY_CC);
		_5 = zephir_is_true(_6);
	}
	if (_5) {
		ZEPHIR_INIT_VAR(_7$$4);
		ZVAL_STRING(_7$$4, "session", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&session$$4, di, "get", NULL, 0, _7$$4);
		zephir_check_temp_parameter(_7$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7$$4);
		ZVAL_STRING(_7$$4, "_redirects", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_9$$4);
		ZVAL_LONG(_9$$4, 0);
		ZEPHIR_CALL_METHOD(&_8$$4, session$$4, "get", NULL, 0, _7$$4, _9$$4);
		zephir_check_temp_parameter(_7$$4);
		zephir_check_call_status();
		redirects = (zephir_get_intval(_8$$4) + 1);
		ZEPHIR_INIT_ZVAL_NREF(_10$$4);
		ZVAL_LONG(_10$$4, redirects);
		zephir_update_property_this(getThis(), SL("redirects"), _10$$4 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_7$$4);
		ZVAL_STRING(_7$$4, "_redirects", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_9$$4);
		ZVAL_LONG(_9$$4, redirects);
		ZEPHIR_CALL_METHOD(NULL, session$$4, "set", NULL, 0, _7$$4, _9$$4);
		zephir_check_temp_parameter(_7$$4);
		zephir_check_call_status();
		_10$$4 = zephir_fetch_nproperty_this(this_ptr, SL("redirects"), PH_NOISY_CC);
		_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("loops"), PH_NOISY_CC);
		if (ZEPHIR_GT(_10$$4, _11$$4)) {
			RETURN_THIS();
		}
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Location", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _12, "set", NULL, 0, _1, location);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Check whether status is for Empty.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isEmpty) {

	zval *_1;
	zval *_0, *_2 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 201);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 204);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 304);
	zephir_array_fast_append(_1, _2);
	RETURN_MM_BOOL(zephir_fast_in_array(_0, _1 TSRMLS_CC));

}

/**
 * Check whether status is for Informational.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isInformational) {

	zend_bool _1;
	zval *_0, *_2;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
	_1 = ZEPHIR_GE_LONG(_0, 100);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
		_1 = ZEPHIR_LT_LONG(_2, 200);
	}
	RETURN_BOOL(_1);

}

/**
 * Check whether status is for OK.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isOk) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_0, 200));

}

/**
 * Check whether status is for Successful.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isSuccessful) {

	zend_bool _1;
	zval *_0, *_2;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
	_1 = ZEPHIR_GE_LONG(_0, 200);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
		_1 = ZEPHIR_LT_LONG(_2, 300);
	}
	RETURN_BOOL(_1);

}

/**
 * Check whether status is for Redirect.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isRedirect) {

	zval *_1;
	zval *_0, *_2 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 301);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 302);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 303);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 307);
	zephir_array_fast_append(_1, _2);
	RETURN_MM_BOOL(zephir_fast_in_array(_0, _1 TSRMLS_CC));

}

/**
 * Check whether status is for Redirection.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isRedirection) {

	zend_bool _1;
	zval *_0, *_2;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
	_1 = ZEPHIR_GE_LONG(_0, 300);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
		_1 = ZEPHIR_LT_LONG(_2, 400);
	}
	RETURN_BOOL(_1);

}

/**
 * Check whether status is for Forbidden.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isForbidden) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_0, 403));

}

/**
 * Check whether status is for Not Found.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isNotFound) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_0, 404));

}

/**
 * Check whether status is for Client error.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isClientError) {

	zend_bool _1;
	zval *_0, *_2;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
	_1 = ZEPHIR_GE_LONG(_0, 400);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
		_1 = ZEPHIR_LT_LONG(_2, 500);
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
	zval *_0, *_2;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
	_1 = ZEPHIR_GE_LONG(_0, 500);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
		_1 = ZEPHIR_LT_LONG(_2, 600);
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

	zval *code_param = NULL, *message = NULL, *_0 = NULL, *_1 = NULL;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &code_param);

	if (!code_param) {
		code = 200;
	} else {
		code = zephir_get_intval(code_param);
	}


	ZEPHIR_OBS_VAR(message);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessages", NULL, 0);
	zephir_check_call_status();
	zephir_array_isset_long_fetch(&message, _0, code, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	if (zephir_is_true(message)) {
		ZEPHIR_CPY_WRT(_1, message);
	} else {
		ZVAL_STRING(_1, "", 1);
	}
	RETURN_CCTOR(_1);

}

/**
 * Get all messages.
 *
 * @return array
 */
PHP_METHOD(Ice_Http_Response, getMessages) {

	

	zephir_create_array(return_value, 61, 0 TSRMLS_CC);
	add_index_stringl(return_value, 100, SL("Continue"), 1);
	add_index_stringl(return_value, 101, SL("Switching Protocols"), 1);
	add_index_stringl(return_value, 102, SL("Processing"), 1);
	add_index_stringl(return_value, 200, SL("OK"), 1);
	add_index_stringl(return_value, 201, SL("Created"), 1);
	add_index_stringl(return_value, 202, SL("Accepted"), 1);
	add_index_stringl(return_value, 203, SL("Non-Authoritative Information"), 1);
	add_index_stringl(return_value, 204, SL("No Content"), 1);
	add_index_stringl(return_value, 205, SL("Reset Content"), 1);
	add_index_stringl(return_value, 206, SL("Partial Content"), 1);
	add_index_stringl(return_value, 207, SL("Multi-Status"), 1);
	add_index_stringl(return_value, 208, SL("Already Reported"), 1);
	add_index_stringl(return_value, 226, SL("IM Used"), 1);
	add_index_stringl(return_value, 300, SL("Multiple Choices"), 1);
	add_index_stringl(return_value, 301, SL("Moved Permanently"), 1);
	add_index_stringl(return_value, 302, SL("Found"), 1);
	add_index_stringl(return_value, 303, SL("See Other"), 1);
	add_index_stringl(return_value, 304, SL("Not Modified"), 1);
	add_index_stringl(return_value, 305, SL("Use Proxy"), 1);
	add_index_stringl(return_value, 306, SL("(Unused)"), 1);
	add_index_stringl(return_value, 307, SL("Temporary Redirect"), 1);
	add_index_stringl(return_value, 308, SL("Permanent Redirect"), 1);
	add_index_stringl(return_value, 310, SL("Too Many Redirects"), 1);
	add_index_stringl(return_value, 400, SL("Bad Request"), 1);
	add_index_stringl(return_value, 401, SL("Unauthorized"), 1);
	add_index_stringl(return_value, 402, SL("Payment Required"), 1);
	add_index_stringl(return_value, 403, SL("Forbidden"), 1);
	add_index_stringl(return_value, 404, SL("Not Found"), 1);
	add_index_stringl(return_value, 405, SL("Method Not Allowed"), 1);
	add_index_stringl(return_value, 406, SL("Not Acceptable"), 1);
	add_index_stringl(return_value, 407, SL("Proxy Authentication Required"), 1);
	add_index_stringl(return_value, 408, SL("Request Timeout"), 1);
	add_index_stringl(return_value, 409, SL("Conflict"), 1);
	add_index_stringl(return_value, 410, SL("Gone"), 1);
	add_index_stringl(return_value, 411, SL("Length Required"), 1);
	add_index_stringl(return_value, 412, SL("Precondition Failed"), 1);
	add_index_stringl(return_value, 413, SL("Request Entity Too Large"), 1);
	add_index_stringl(return_value, 414, SL("Request-URI Too Long"), 1);
	add_index_stringl(return_value, 415, SL("Unsupported Media Type"), 1);
	add_index_stringl(return_value, 416, SL("Requested Range Not Satisfiable"), 1);
	add_index_stringl(return_value, 417, SL("Expectation Failed"), 1);
	add_index_stringl(return_value, 418, SL("I'm a teapot"), 1);
	add_index_stringl(return_value, 422, SL("Unprocessable Entity"), 1);
	add_index_stringl(return_value, 423, SL("Locked"), 1);
	add_index_stringl(return_value, 424, SL("Failed Dependency"), 1);
	add_index_stringl(return_value, 426, SL("Upgrade Required"), 1);
	add_index_stringl(return_value, 428, SL("Precondition Required"), 1);
	add_index_stringl(return_value, 429, SL("Too Many Requests"), 1);
	add_index_stringl(return_value, 431, SL("Request Header Fields Too Large"), 1);
	add_index_stringl(return_value, 500, SL("Internal Server Error"), 1);
	add_index_stringl(return_value, 501, SL("Not Implemented"), 1);
	add_index_stringl(return_value, 502, SL("Bad Gateway"), 1);
	add_index_stringl(return_value, 503, SL("Service Unavailable"), 1);
	add_index_stringl(return_value, 504, SL("Gateway Timeout"), 1);
	add_index_stringl(return_value, 505, SL("HTTP Version Not Supported"), 1);
	add_index_stringl(return_value, 506, SL("Variant Also Negotiates"), 1);
	add_index_stringl(return_value, 507, SL("Insufficient Storage"), 1);
	add_index_stringl(return_value, 508, SL("Loop Detected"), 1);
	add_index_stringl(return_value, 510, SL("Not Extended"), 1);
	add_index_stringl(return_value, 511, SL("Network Authentication Required"), 1);
	return;

}

/**
 * Magic toString, convert response to string.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Response, __toString) {

	zval *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("body"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	RETURN_CTOR(_1);

}

