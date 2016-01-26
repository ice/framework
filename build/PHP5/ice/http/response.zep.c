
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
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Ice\\Http, Response, ice, http_response, ice_http_response_method_entry, 0);

	zend_declare_property_null(ice_http_response_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_http_response_ce, SL("protocolVersion"), "HTTP/1.1", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_http_response_ce, SL("status"), 200, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_response_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_response_ce, SL("body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_response_ce, SL("messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_http_response_ce->create_object = zephir_init_properties_Ice_Http_Response;

	zend_class_implements(ice_http_response_ce TSRMLS_CC, 1, ice_http_response_responseinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Http_Response, getProtocolVersion) {

	

	RETURN_MEMBER(this_ptr, "protocolVersion");

}

PHP_METHOD(Ice_Http_Response, setProtocolVersion) {

	zval *protocolVersion;

	zephir_fetch_params(0, 1, 0, &protocolVersion);



	zephir_update_property_this(this_ptr, SL("protocolVersion"), protocolVersion TSRMLS_CC);

}

PHP_METHOD(Ice_Http_Response, getStatus) {

	

	RETURN_MEMBER(this_ptr, "status");

}

PHP_METHOD(Ice_Http_Response, setStatus) {

	zval *status;

	zephir_fetch_params(0, 1, 0, &status);



	zephir_update_property_this(this_ptr, SL("status"), status TSRMLS_CC);

}

PHP_METHOD(Ice_Http_Response, getBody) {

	

	RETURN_MEMBER(this_ptr, "body");

}

PHP_METHOD(Ice_Http_Response, setBody) {

	zval *body;

	zephir_fetch_params(0, 1, 0, &body);



	zephir_update_property_this(this_ptr, SL("body"), body TSRMLS_CC);

}

PHP_METHOD(Ice_Http_Response, getMessages) {

	

	RETURN_MEMBER(this_ptr, "messages");

}

/**
 * Response constructor. Fetch Di and set it as a property.
 *
 * @param string body The HTTP response body
 * @param int status The HTTP response status
 */
PHP_METHOD(Ice_Http_Response, __construct) {

	zephir_fcall_cache_entry *_1 = NULL;
	int status, ZEPHIR_LAST_CALL_STATUS;
	zval *body_param = NULL, *status_param = NULL, *_0 = NULL, *_2, *_3, *_4, *_5;
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


	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 6);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, ice_http_response_headers_ce);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 4);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("headers"), _2 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(_3, status);
	zephir_update_property_this(this_ptr, SL("status"), _3 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("body"), body TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "text/html", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _3, "set", NULL, 0, _4, _5);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_5);
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
	int ZEPHIR_LAST_CALL_STATUS;

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

	int ZEPHIR_LAST_CALL_STATUS;
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

	int ZEPHIR_LAST_CALL_STATUS;
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

	int ZEPHIR_LAST_CALL_STATUS;
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

	int ZEPHIR_LAST_CALL_STATUS;
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

	int ZEPHIR_LAST_CALL_STATUS;
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


	zephir_update_property_this(this_ptr, SL("body"), contet TSRMLS_CC);
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
	int ZEPHIR_LAST_CALL_STATUS;
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
		zephir_update_property_this(this_ptr, SL("body"), _7$$5 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Send HTTP response headers.
 *
 * @return Response
 */
PHP_METHOD(Ice_Http_Response, send) {

	zval *_0 = NULL, *_1$$3, _2$$3, *_3$$3, *_19$$3, *_4$$4, *_5$$4, *_6$$4, *_7$$4, _8$$4, *_9$$4 = NULL, *_12$$5 = NULL, *_13$$5, *_14$$5, *_15$$5, *_16$$5, _17$$5, *_18$$5 = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 108);
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
			_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(_7$$4);
			zephir_read_property_this(&_7$$4, this_ptr, SL("status"), PH_NOISY_CC);
			zephir_array_fetch(&_6$$4, _5$$4, _7$$4, PH_NOISY | PH_READONLY, "ice/http/response.zep", 229 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_8$$4);
			ZVAL_STRING(&_8$$4, "Status: %d %s", 0);
			ZEPHIR_CALL_FUNCTION(&_9$$4, "sprintf", &_10, 12, &_8$$4, _4$$4, _6$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 109, _9$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getprotocolversion", NULL, 0);
			zephir_check_call_status();
			_13$$5 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
			_14$$5 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(_16$$5);
			zephir_read_property_this(&_16$$5, this_ptr, SL("status"), PH_NOISY_CC);
			zephir_array_fetch(&_15$$5, _14$$5, _16$$5, PH_NOISY | PH_READONLY, "ice/http/response.zep", 231 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_17$$5);
			ZVAL_STRING(&_17$$5, "%s %d %s", 0);
			ZEPHIR_CALL_FUNCTION(&_18$$5, "sprintf", &_10, 12, &_17$$5, _12$$5, _13$$5, _15$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 109, _18$$5);
			zephir_check_call_status();
		}
		_19$$3 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _19$$3, "send", NULL, 0);
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

	zend_bool external;
	int status, ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *status_param = NULL, *external_param = NULL, *url = NULL, *_0 = NULL, *_4, *_1$$3, *_2$$3, *_3$$3 = NULL;
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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, status);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatus", NULL, 0, _0);
	zephir_check_call_status();
	if (!(external)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&url, _1$$3, "get", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, url, "get", NULL, 0, location);
		zephir_check_call_status();
		zephir_get_strval(location, _3$$3);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Location", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _4, "set", NULL, 0, _0, location);
	zephir_check_temp_parameter(_0);
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

	zval *code_param = NULL, *message = NULL, *_0, *_1 = NULL;
	int code;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &code_param);

	if (!code_param) {
		code = 200;
	} else {
		code = zephir_get_intval(code_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
	zephir_array_isset_long_fetch(&message, _0, code, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	if (zephir_is_true(message)) {
		ZEPHIR_CPY_WRT(_1, message);
	} else {
		ZVAL_STRING(_1, "", 1);
	}
	RETURN_CCTOR(_1);

}

/**
 * Magic toString, convert response to string.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Response, __toString) {

	

	RETURN_MEMBER(this_ptr, "body");

}

static zend_object_value zephir_init_properties_Ice_Http_Response(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 61, 0 TSRMLS_CC);
			add_index_stringl(_1$$3, 100, SL("Continue"), 1);
			add_index_stringl(_1$$3, 101, SL("Switching Protocols"), 1);
			add_index_stringl(_1$$3, 102, SL("Processing"), 1);
			add_index_stringl(_1$$3, 200, SL("OK"), 1);
			add_index_stringl(_1$$3, 201, SL("Created"), 1);
			add_index_stringl(_1$$3, 202, SL("Accepted"), 1);
			add_index_stringl(_1$$3, 203, SL("Non-Authoritative Information"), 1);
			add_index_stringl(_1$$3, 204, SL("No Content"), 1);
			add_index_stringl(_1$$3, 205, SL("Reset Content"), 1);
			add_index_stringl(_1$$3, 206, SL("Partial Content"), 1);
			add_index_stringl(_1$$3, 207, SL("Multi-Status"), 1);
			add_index_stringl(_1$$3, 208, SL("Already Reported"), 1);
			add_index_stringl(_1$$3, 226, SL("IM Used"), 1);
			add_index_stringl(_1$$3, 300, SL("Multiple Choices"), 1);
			add_index_stringl(_1$$3, 301, SL("Moved Permanently"), 1);
			add_index_stringl(_1$$3, 302, SL("Found"), 1);
			add_index_stringl(_1$$3, 303, SL("See Other"), 1);
			add_index_stringl(_1$$3, 304, SL("Not Modified"), 1);
			add_index_stringl(_1$$3, 305, SL("Use Proxy"), 1);
			add_index_stringl(_1$$3, 306, SL("(Unused)"), 1);
			add_index_stringl(_1$$3, 307, SL("Temporary Redirect"), 1);
			add_index_stringl(_1$$3, 308, SL("Permanent Redirect"), 1);
			add_index_stringl(_1$$3, 310, SL("Too Many Redirects"), 1);
			add_index_stringl(_1$$3, 400, SL("Bad Request"), 1);
			add_index_stringl(_1$$3, 401, SL("Unauthorized"), 1);
			add_index_stringl(_1$$3, 402, SL("Payment Required"), 1);
			add_index_stringl(_1$$3, 403, SL("Forbidden"), 1);
			add_index_stringl(_1$$3, 404, SL("Not Found"), 1);
			add_index_stringl(_1$$3, 405, SL("Method Not Allowed"), 1);
			add_index_stringl(_1$$3, 406, SL("Not Acceptable"), 1);
			add_index_stringl(_1$$3, 407, SL("Proxy Authentication Required"), 1);
			add_index_stringl(_1$$3, 408, SL("Request Timeout"), 1);
			add_index_stringl(_1$$3, 409, SL("Conflict"), 1);
			add_index_stringl(_1$$3, 410, SL("Gone"), 1);
			add_index_stringl(_1$$3, 411, SL("Length Required"), 1);
			add_index_stringl(_1$$3, 412, SL("Precondition Failed"), 1);
			add_index_stringl(_1$$3, 413, SL("Request Entity Too Large"), 1);
			add_index_stringl(_1$$3, 414, SL("Request-URI Too Long"), 1);
			add_index_stringl(_1$$3, 415, SL("Unsupported Media Type"), 1);
			add_index_stringl(_1$$3, 416, SL("Requested Range Not Satisfiable"), 1);
			add_index_stringl(_1$$3, 417, SL("Expectation Failed"), 1);
			add_index_stringl(_1$$3, 418, SL("I\"m a teapot"), 1);
			add_index_stringl(_1$$3, 422, SL("Unprocessable Entity"), 1);
			add_index_stringl(_1$$3, 423, SL("Locked"), 1);
			add_index_stringl(_1$$3, 424, SL("Failed Dependency"), 1);
			add_index_stringl(_1$$3, 426, SL("Upgrade Required"), 1);
			add_index_stringl(_1$$3, 428, SL("Precondition Required"), 1);
			add_index_stringl(_1$$3, 429, SL("Too Many Requests"), 1);
			add_index_stringl(_1$$3, 431, SL("Request Header Fields Too Large"), 1);
			add_index_stringl(_1$$3, 500, SL("Internal Server Error"), 1);
			add_index_stringl(_1$$3, 501, SL("Not Implemented"), 1);
			add_index_stringl(_1$$3, 502, SL("Bad Gateway"), 1);
			add_index_stringl(_1$$3, 503, SL("Service Unavailable"), 1);
			add_index_stringl(_1$$3, 504, SL("Gateway Timeout"), 1);
			add_index_stringl(_1$$3, 505, SL("HTTP Version Not Supported"), 1);
			add_index_stringl(_1$$3, 506, SL("Variant Also Negotiates"), 1);
			add_index_stringl(_1$$3, 507, SL("Insufficient Storage"), 1);
			add_index_stringl(_1$$3, 508, SL("Loop Detected"), 1);
			add_index_stringl(_1$$3, 510, SL("Not Extended"), 1);
			add_index_stringl(_1$$3, 511, SL("Network Authentication Required"), 1);
			zephir_update_property_this(this_ptr, SL("messages"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

