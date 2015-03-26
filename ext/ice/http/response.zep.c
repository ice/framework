
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

ZEPHIR_INIT_CLASS(Ice_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Ice\\Http, Response, ice, http_response, ice_http_response_method_entry, 0);

	zend_declare_property_null(ice_http_response_ce, SL("_di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_http_response_ce, SL("_protocolVersion"), "HTTP/1.1", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_http_response_ce, SL("_status"), 200, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_response_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_response_ce, SL("_body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_response_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_http_response_ce TSRMLS_CC, 1, ice_http_response_responseinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Http_Response, getProtocolVersion) {


	RETURN_MEMBER(this_ptr, "_protocolVersion");

}

PHP_METHOD(Ice_Http_Response, setProtocolVersion) {

	zval *protocolVersion;

	zephir_fetch_params(0, 1, 0, &protocolVersion);



	zephir_update_property_this(this_ptr, SL("_protocolVersion"), protocolVersion TSRMLS_CC);

}

PHP_METHOD(Ice_Http_Response, getStatus) {


	RETURN_MEMBER(this_ptr, "_status");

}

PHP_METHOD(Ice_Http_Response, setStatus) {

	zval *status;

	zephir_fetch_params(0, 1, 0, &status);



	zephir_update_property_this(this_ptr, SL("_status"), status TSRMLS_CC);

}

PHP_METHOD(Ice_Http_Response, getBody) {


	RETURN_MEMBER(this_ptr, "_body");

}

PHP_METHOD(Ice_Http_Response, setBody) {

	zval *body;

	zephir_fetch_params(0, 1, 0, &body);



	zephir_update_property_this(this_ptr, SL("_body"), body TSRMLS_CC);

}

PHP_METHOD(Ice_Http_Response, getMessages) {


	RETURN_MEMBER(this_ptr, "_messages");

}

/**
 * Response constructor. Fetch Di and set it as a property.
 *
 * @param string body The HTTP response body
 * @param int status The HTTP response status
 */
PHP_METHOD(Ice_Http_Response, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0;
	int status, ZEPHIR_LAST_CALL_STATUS;
	zval *body_param = NULL, *status_param = NULL, *_1 = NULL, *_3, *_4, *_5, *_6;
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
	array_init_size(_0, 76);
	add_index_stringl(_0, 100, SL("Continue"), 1);
	add_index_stringl(_0, 101, SL("Switching Protocols"), 1);
	add_index_stringl(_0, 102, SL("Processing"), 1);
	add_index_stringl(_0, 200, SL("OK"), 1);
	add_index_stringl(_0, 201, SL("Created"), 1);
	add_index_stringl(_0, 202, SL("Accepted"), 1);
	add_index_stringl(_0, 203, SL("Non-Authoritative Information"), 1);
	add_index_stringl(_0, 204, SL("No Content"), 1);
	add_index_stringl(_0, 205, SL("Reset Content"), 1);
	add_index_stringl(_0, 206, SL("Partial Content"), 1);
	add_index_stringl(_0, 207, SL("Multi-Status"), 1);
	add_index_stringl(_0, 208, SL("Already Reported"), 1);
	add_index_stringl(_0, 226, SL("IM Used"), 1);
	add_index_stringl(_0, 300, SL("Multiple Choices"), 1);
	add_index_stringl(_0, 301, SL("Moved Permanently"), 1);
	add_index_stringl(_0, 302, SL("Found"), 1);
	add_index_stringl(_0, 303, SL("See Other"), 1);
	add_index_stringl(_0, 304, SL("Not Modified"), 1);
	add_index_stringl(_0, 305, SL("Use Proxy"), 1);
	add_index_stringl(_0, 306, SL("(Unused)"), 1);
	add_index_stringl(_0, 307, SL("Temporary Redirect"), 1);
	add_index_stringl(_0, 308, SL("Permanent Redirect"), 1);
	add_index_stringl(_0, 310, SL("Too Many Redirects"), 1);
	add_index_stringl(_0, 400, SL("Bad Request"), 1);
	add_index_stringl(_0, 401, SL("Unauthorized"), 1);
	add_index_stringl(_0, 402, SL("Payment Required"), 1);
	add_index_stringl(_0, 403, SL("Forbidden"), 1);
	add_index_stringl(_0, 404, SL("Not Found"), 1);
	add_index_stringl(_0, 405, SL("Method Not Allowed"), 1);
	add_index_stringl(_0, 406, SL("Not Acceptable"), 1);
	add_index_stringl(_0, 407, SL("Proxy Authentication Required"), 1);
	add_index_stringl(_0, 408, SL("Request Timeout"), 1);
	add_index_stringl(_0, 409, SL("Conflict"), 1);
	add_index_stringl(_0, 410, SL("Gone"), 1);
	add_index_stringl(_0, 411, SL("Length Required"), 1);
	add_index_stringl(_0, 412, SL("Precondition Failed"), 1);
	add_index_stringl(_0, 413, SL("Request Entity Too Large"), 1);
	add_index_stringl(_0, 414, SL("Request-URI Too Long"), 1);
	add_index_stringl(_0, 415, SL("Unsupported Media Type"), 1);
	add_index_stringl(_0, 416, SL("Requested Range Not Satisfiable"), 1);
	add_index_stringl(_0, 417, SL("Expectation Failed"), 1);
	add_index_stringl(_0, 418, SL("I\"m a teapot"), 1);
	add_index_stringl(_0, 422, SL("Unprocessable Entity"), 1);
	add_index_stringl(_0, 423, SL("Locked"), 1);
	add_index_stringl(_0, 424, SL("Failed Dependency"), 1);
	add_index_stringl(_0, 426, SL("Upgrade Required"), 1);
	add_index_stringl(_0, 428, SL("Precondition Required"), 1);
	add_index_stringl(_0, 429, SL("Too Many Requests"), 1);
	add_index_stringl(_0, 431, SL("Request Header Fields Too Large"), 1);
	add_index_stringl(_0, 500, SL("Internal Server Error"), 1);
	add_index_stringl(_0, 501, SL("Not Implemented"), 1);
	add_index_stringl(_0, 502, SL("Bad Gateway"), 1);
	add_index_stringl(_0, 503, SL("Service Unavailable"), 1);
	add_index_stringl(_0, 504, SL("Gateway Timeout"), 1);
	add_index_stringl(_0, 505, SL("HTTP Version Not Supported"), 1);
	add_index_stringl(_0, 506, SL("Variant Also Negotiates"), 1);
	add_index_stringl(_0, 507, SL("Insufficient Storage"), 1);
	add_index_stringl(_0, 508, SL("Loop Detected"), 1);
	add_index_stringl(_0, 510, SL("Not Extended"), 1);
	add_index_stringl(_0, 511, SL("Network Authentication Required"), 1);
	zephir_update_property_this(this_ptr, SL("_messages"), _0 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_1, ice_di_ce, "fetch", &_2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_di"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, ice_http_response_headers_ce);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_headers"), _3 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, status);
	zephir_update_property_this(this_ptr, SL("_status"), _4 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_body"), body TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "text/html", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _4, "set", NULL, _5, _6);
	zephir_check_temp_parameter(_5);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get HTTP headers.
 *
 * @return array
 */
PHP_METHOD(Ice_Http_Response, getHeaders) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "all", NULL);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "has", NULL, name);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, name);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, name, value);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "replace", NULL, headers);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Finalize response for delivery to client.
 * Apply final preparations to the resposne object so that it is suitable for delivery to the client.
 *
 * @param RequestInterface request
 * @return Response
 */
PHP_METHOD(Ice_Http_Response, finalize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zend_bool sendBody;
	zval *request, *_0, *_2 = NULL, *_3, *_4, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	sendBody = 1;
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 204);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 304);
	zephir_array_fast_append(_1, _2);
	if (zephir_fast_in_array(_0, _1 TSRMLS_CC)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3, "remove", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "Content-Length", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _4, "remove", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		sendBody = 0;
	}
	ZEPHIR_CALL_METHOD(&_5, request, "ishead", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		sendBody = 0;
	}
	if (!(sendBody)) {
		ZEPHIR_INIT_ZVAL_NREF(_3);
		ZVAL_STRING(_3, "", 1);
		zephir_update_property_this(this_ptr, SL("_body"), _3 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Send HTTP response headers.
 *
 * @return Response
 */
PHP_METHOD(Ice_Http_Response, send) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_11 = NULL, *_12 = NULL;
	zval *_0 = NULL, *_2, _3, *_4, *_5, *_6, *_7, *_8 = NULL, _9 = zval_used_for_init, *_10 = NULL, *_13 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_GET_CONSTANT(_2, "PHP_SAPI");
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "cgi", 0);
		ZEPHIR_INIT_VAR(_4);
		zephir_fast_strpos(_4, _2, &_3, 0 );
		if (ZEPHIR_IS_LONG_IDENTICAL(_4, 0)) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(_8);
			zephir_read_property_this(&_8, this_ptr, SL("_status"), PH_NOISY_CC);
			zephir_array_fetch(&_7, _6, _8, PH_NOISY | PH_READONLY, "ice/http/response.zep", 216 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_9);
			ZVAL_STRING(&_9, "Status: %d %s", 0);
			ZEPHIR_CALL_FUNCTION(&_10, "sprintf", &_11, &_9, _5, _7);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_12, _10);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "getprotocolversion", NULL);
			zephir_check_call_status();
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(_8);
			zephir_read_property_this(&_8, this_ptr, SL("_status"), PH_NOISY_CC);
			zephir_array_fetch(&_7, _6, _8, PH_NOISY | PH_READONLY, "ice/http/response.zep", 218 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_STRING(&_9, "%s %d %s", 0);
			ZEPHIR_CALL_FUNCTION(&_13, "sprintf", &_11, &_9, _10, _5, _7);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_12, _13);
			zephir_check_call_status();
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _5, "send", NULL);
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
 */
PHP_METHOD(Ice_Http_Response, redirect) {

	zend_bool external;
	int status, ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *status_param = NULL, *external_param = NULL, *url = NULL, *_0 = NULL, *_1, *_2 = NULL;
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatus", NULL, _0);
	zephir_check_call_status();
	if (!(external)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&url, _1, "geturl", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2, url, "get", NULL, location);
		zephir_check_call_status();
		zephir_get_strval(location, _2);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Location", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _1, "set", NULL, _0, location);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

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

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 4);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
	_1 = ZEPHIR_GE_LONG(_0, 100);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
	_1 = ZEPHIR_GE_LONG(_0, 200);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
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

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 6);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
	_1 = ZEPHIR_GE_LONG(_0, 300);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_0, 403));

}

/**
 * Check whether status is for Not Found.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response, isNotFound) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
	_1 = ZEPHIR_GE_LONG(_0, 400);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
	_1 = ZEPHIR_GE_LONG(_0, 500);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
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

	zval *code_param = NULL, *message, *_0, *_1 = NULL;
	int code;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &code_param);

	if (!code_param) {
		code = 200;
	} else {
		code = zephir_get_intval(code_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
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


	RETURN_MEMBER(this_ptr, "_body");

}

