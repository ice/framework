
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
 * @param string|null body The HTTP response body
 * @param int status The HTTP response status
 */
PHP_METHOD(Ice_Http_Response, __construct) {

	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *body = NULL, *status_param = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &body, &status_param);

	if (!body) {
		body = ZEPHIR_GLOBAL(global_null);
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
 * @return object Response
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
	zval *headers_param = NULL, *_0;
	zval *headers = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(headers, headers_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "replace", NULL, 0, headers);
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
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, 0, name);
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
 * @return object Response
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
 * @return object Response
 */
PHP_METHOD(Ice_Http_Response, send) {

	zend_bool _21$$3;
	zval *_0 = NULL, *_1$$3, _2$$3, *_3$$3, *di$$3 = NULL, *_19$$3 = NULL, *_20$$3, *_22$$3 = NULL, *_25$$3, *_4$$4, *_5$$4 = NULL, *_6$$4, _8$$4, *_9$$4 = NULL, *_12$$5 = NULL, *_13$$5, *_14$$5 = NULL, *_15$$5, _16$$5, *_17$$5 = NULL, *_23$$6 = NULL, *_24$$6 = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL, *_11 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 138);
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
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 139, _9$$4);
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
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 139, _17$$5);
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

	zend_bool _19$$9, _44$$17;
	zephir_fcall_cache_entry *_34 = NULL, *_35 = NULL, *_38 = NULL, *_43 = NULL, *_46 = NULL, *_50 = NULL, *_51 = NULL, *_53 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, block = 0, speed = 0;
	zval *options = NULL, *_6$$5;
	zval *filename_param = NULL, *mime_param = NULL, *options_param = NULL, *file = NULL, *filepath = NULL, *data = NULL, *size = NULL, *isDelete = NULL, *disposition = NULL, *pos = NULL, *range = NULL, *start = NULL, *end = NULL, *_0, *_8, *_9, *_28, *_29, *_30 = NULL, *_31, *_32, *_33 = NULL, *_36, *_41, *_1$$3, *_3$$4, _4$$4, *_5$$5, *_7$$5, *_10$$8, *_11$$8, *_12$$9, *_21$$9, *_22$$9 = NULL, *_23$$9 = NULL, *_24$$9, *_25$$9, *_26$$9, _27$$9, *_13$$10 = NULL, *_14$$10, *_15$$10 = NULL, *_16$$10, _17$$10, *_18$$10 = NULL, *_20$$11, _37$$13, *_39$$14, _40$$14, *_42$$15, *_45$$17 = NULL, _48$$17 = zval_used_for_init, *_49$$17 = NULL, _47$$19 = zval_used_for_init, _52$$20 = zval_used_for_init, *_54$$21, *_55$$21 = NULL;
	zval *filename = NULL, *mime = NULL, *_2$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &filename_param, &mime_param, &options_param);

	zephir_get_strval(filename, filename_param);
	zephir_get_strval(mime, mime_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	zephir_array_fetch_string(&_0, options, SL("file"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 221 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_OBS_VAR(_1$$3);
		zephir_read_property_this(&_1$$3, this_ptr, SL("body"), PH_NOISY_CC);
		zephir_get_strval(_2$$3, _1$$3);
		ZEPHIR_CPY_WRT(data, _2$$3);
		ZEPHIR_INIT_VAR(size);
		ZVAL_LONG(size, zephir_fast_strlen_ev(data));
		ZEPHIR_CALL_FUNCTION(&file, "tmpfile", NULL, 140);
		zephir_check_call_status();
		zephir_fwrite(NULL, file, data TSRMLS_CC);
		ZEPHIR_INIT_VAR(isDelete);
		ZVAL_BOOL(isDelete, 0);
	} else {
		zephir_array_fetch_string(&_3$$4, options, SL("file"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 237 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&filepath, "realpath", NULL, 141, _3$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&size, "filesize", NULL, 142, filepath);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_4$$4);
		ZVAL_STRING(&_4$$4, "rb", 0);
		ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 125, filepath, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(isDelete);
		zephir_array_isset_string_fetch(&isDelete, options, SS("delete"), 0 TSRMLS_CC);
	}
	if (!(Z_TYPE_P(file) == IS_RESOURCE)) {
		ZEPHIR_INIT_VAR(_5$$5);
		object_init_ex(_5$$5, ice_exception_ce);
		ZEPHIR_INIT_VAR(_6$$5);
		zephir_create_array(_6$$5, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$5);
		ZVAL_STRING(_7$$5, "Could not read file to send: %s", 1);
		zephir_array_fast_append(_6$$5, _7$$5);
		zephir_array_fast_append(_6$$5, filename);
		ZEPHIR_CALL_METHOD(NULL, _5$$5, "__construct", NULL, 13, _6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$5, "ice/http/response.zep", 249 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_8, options, SL("inline"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 252 TSRMLS_CC);
	ZEPHIR_INIT_VAR(disposition);
	if (ZEPHIR_IS_EMPTY(_8)) {
		ZVAL_STRING(disposition, "attachment", 1);
	} else {
		ZVAL_STRING(disposition, "inline", 1);
	}
	zephir_array_fetch_string(&_9, options, SL("resumable"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 258 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_9)) {
		_10$$8 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_11$$8);
		ZVAL_STRING(_11$$8, "Content-Length", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _10$$8, "set", NULL, 0, _11$$8, size);
		zephir_check_temp_parameter(_11$$8);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&range, this_ptr, "getbyterange", NULL, 0, size);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(start);
		zephir_array_fetch_long(&start, range, 0, PH_NOISY, "ice/http/response.zep", 263 TSRMLS_CC);
		ZEPHIR_OBS_VAR(end);
		zephir_array_fetch_long(&end, range, 1, PH_NOISY, "ice/http/response.zep", 264 TSRMLS_CC);
		_12$$9 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
		if (ZEPHIR_IS_LONG(_12$$9, 416)) {
			ZEPHIR_CALL_METHOD(&_13$$10, this_ptr, "getprotocolversion", NULL, 0);
			zephir_check_call_status();
			_14$$10 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
			_16$$10 = zephir_fetch_nproperty_this(this_ptr, SL("status"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_15$$10, this_ptr, "getmessage", NULL, 0, _16$$10);
			zephir_check_call_status();
			ZEPHIR_SINIT_VAR(_17$$10);
			ZVAL_STRING(&_17$$10, "%s %d %s", 0);
			ZEPHIR_CALL_FUNCTION(&_18$$10, "sprintf", NULL, 12, &_17$$10, _13$$10, _14$$10, _15$$10);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 139, _18$$10);
			zephir_check_call_status();
			ZEPHIR_MM_RESTORE();
			zephir_exit_empty();
		}
		_19$$9 = ZEPHIR_GT_LONG(start, 0);
		if (!(_19$$9)) {
			_19$$9 = ZEPHIR_LT_LONG(end, (zephir_get_numberval(size) - 1));
		}
		if (_19$$9) {
			ZEPHIR_INIT_ZVAL_NREF(_20$$11);
			ZVAL_LONG(_20$$11, 206);
			zephir_update_property_this(getThis(), SL("status"), _20$$11 TSRMLS_CC);
		}
		_21$$9 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_22$$9);
		ZVAL_STRING(_22$$9, "Accept-Ranges", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_23$$9);
		ZVAL_STRING(_23$$9, "bytes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _21$$9, "set", NULL, 0, _22$$9, _23$$9);
		zephir_check_temp_parameter(_22$$9);
		zephir_check_temp_parameter(_23$$9);
		zephir_check_call_status();
		_24$$9 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_25$$9);
		ZEPHIR_CONCAT_SVSVSV(_25$$9, "bytes ", start, "-", end, "/", size);
		ZEPHIR_INIT_NVAR(_22$$9);
		ZVAL_STRING(_22$$9, "Content-Range", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _24$$9, "set", NULL, 0, _22$$9, _25$$9);
		zephir_check_temp_parameter(_22$$9);
		zephir_check_call_status();
		_26$$9 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_27$$9);
		zephir_sub_function(&_27$$9, end, start);
		ZEPHIR_INIT_NVAR(_22$$9);
		ZVAL_STRING(_22$$9, "Content-Length", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_23$$9);
		ZVAL_LONG(_23$$9, (zephir_get_numberval(&_27$$9) + 1));
		ZEPHIR_CALL_METHOD(NULL, _26$$9, "set", NULL, 0, _22$$9, _23$$9);
		zephir_check_temp_parameter(_22$$9);
		zephir_check_call_status();
	}
	_28 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_29);
	ZEPHIR_CONCAT_VSVS(_29, disposition, "; filename=\"", filename, "\"");
	ZEPHIR_INIT_VAR(_30);
	ZVAL_STRING(_30, "Content-Disposition", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _28, "set", NULL, 0, _30, _29);
	zephir_check_temp_parameter(_30);
	zephir_check_call_status();
	_31 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_30);
	ZVAL_STRING(_30, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _31, "set", NULL, 0, _30, mime);
	zephir_check_temp_parameter(_30);
	zephir_check_call_status();
	_32 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _32, "send", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_FUNCTION(&_33, "ob_get_level", &_34, 132);
		zephir_check_call_status();
		if (!(zephir_is_true(_33))) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_flush", &_35, 143);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ignore_user_abort", NULL, 144, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zephir_array_fetch_string(&_36, options, SL("timeout"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 298 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_36)) {
		ZEPHIR_SINIT_VAR(_37$$13);
		ZVAL_LONG(&_37$$13, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "set_time_limit", &_38, 145, &_37$$13);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_VAR(_39$$14);
		zephir_array_fetch_string(&_39$$14, options, SL("timeout"), PH_NOISY, "ice/http/response.zep", 302 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_40$$14);
		ZVAL_LONG(&_40$$14, zephir_get_intval(_39$$14));
		ZEPHIR_CALL_FUNCTION(NULL, "set_time_limit", &_38, 145, &_40$$14);
		zephir_check_call_status();
	}
	block = 16384;
	zephir_array_fetch_string(&_41, options, SL("sleep"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 308 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(_41))) {
		ZEPHIR_OBS_VAR(_42$$15);
		zephir_array_fetch_string(&_42$$15, options, SL("sleep"), PH_NOISY, "ice/http/response.zep", 309 TSRMLS_CC);
		speed = (zephir_get_intval(_42$$15) * 1000);
	} else {
		speed = 0;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "fseek", NULL, 146, file, start);
	zephir_check_call_status();
	while (1) {
		if (!(!(zephir_feof(file TSRMLS_CC)))) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&pos, "ftell", &_43, 147, file);
		zephir_check_call_status();
		_44$$17 = ZEPHIR_GT(pos, end);
		if (!(_44$$17)) {
			ZEPHIR_CALL_FUNCTION(&_45$$17, "connection_aborted", &_46, 148);
			zephir_check_call_status();
			_44$$17 = zephir_is_true(_45$$17);
		}
		if (_44$$17) {
			break;
		}
		if (ZEPHIR_LT_LONG(end, (zephir_get_numberval(pos) + block))) {
			ZEPHIR_SINIT_NVAR(_47$$19);
			zephir_sub_function(&_47$$19, end, pos);
			block = (zephir_get_numberval(&_47$$19) + 1);
		}
		ZEPHIR_SINIT_NVAR(_48$$17);
		ZVAL_LONG(&_48$$17, block);
		ZEPHIR_CALL_FUNCTION(&_49$$17, "fread", &_50, 31, file, &_48$$17);
		zephir_check_call_status();
		zend_print_zval(_49$$17, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "flush", &_51, 149);
		zephir_check_call_status();
		if (speed > 0) {
			ZEPHIR_SINIT_NVAR(_52$$20);
			ZVAL_LONG(&_52$$20, speed);
			ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_53, 33, &_52$$20);
			zephir_check_call_status();
		}
	}
	zephir_fclose(file TSRMLS_CC);
	if (zephir_is_true(isDelete)) {

		/* try_start_1: */

			ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 150, filepath);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(_54$$21);
			ZEPHIR_CPY_WRT(_54$$21, EG(exception));
			ZEPHIR_INIT_VAR(_55$$21);
			if (zephir_instance_of_ev(_54$$21, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(_55$$21, _54$$21);
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
 * Response data to JSON string.
 *
 * @param mixed data Can be any type excepta resource
 * @param int option The options for json_encode
 * @return object Response
 */
PHP_METHOD(Ice_Http_Response, toJson) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, *option = NULL, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &option);

	if (!option) {
		option = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "application/json;charset=utf-8", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	zephir_json_encode(_1, &(_1), data, zephir_get_intval(option)  TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("body"), _1 TSRMLS_CC);
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
	zval *data, *options = NULL, *doc = NULL, *ns = NULL, *rootName = NULL, *charset = NULL, *_1, *_2, *_3, *_4 = NULL, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_array_isset_string(options, SS("root"))) {
		ZEPHIR_OBS_VAR(rootName);
		zephir_array_fetch_string(&rootName, options, SL("root"), PH_NOISY, "ice/http/response.zep", 623 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(rootName);
		ZVAL_STRING(rootName, "result", 1);
	}
	if (zephir_array_isset_string(options, SS("charset"))) {
		ZEPHIR_OBS_VAR(charset);
		zephir_array_fetch_string(&charset, options, SL("charset"), PH_NOISY, "ice/http/response.zep", 624 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(charset);
		ZVAL_STRING(charset, "utf-8", 1);
	}
	ZEPHIR_CALL_METHOD(&doc, this_ptr, "xmlencode", NULL, 0, data, rootName);
	zephir_check_call_status();
	if (0) {
		zephir_update_property_zval(doc, SL("preserveWhiteSpace"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_zval(doc, SL("preserveWhiteSpace"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (1) {
		zephir_update_property_zval(doc, SL("formatOutput"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_zval(doc, SL("formatOutput"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_zval(doc, SL("encoding"), charset TSRMLS_CC);
	ZEPHIR_OBS_VAR(ns);
	if (zephir_array_isset_string_fetch(&ns, options, SS("namespace"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "xmlns", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, doc, "createattributens", NULL, 0, ns, _0$$3);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "application/xml;charset=", charset);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _1, "set", NULL, 0, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, doc, "savexml", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("body"), _4 TSRMLS_CC);
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
	HashTable *_4$$4, *_16$$8;
	HashPosition _3$$4, _15$$8;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *root = NULL;
	zval *data = NULL, *root_param = NULL, *domNode = NULL, *domDoc = NULL, *type = NULL, *key = NULL, *val = NULL, *node = NULL, *_2, *_0$$3, **_5$$4, *_6$$6 = NULL, *_7$$6 = NULL, _8$$6 = zval_used_for_init, *_9$$6 = NULL, *_11$$5 = NULL, *_12$$8, *_13$$8, *_14$$8 = NULL, **_17$$8, *_19$$10 = NULL, *_20$$13 = NULL, *_21$$12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &data, &root_param, &domNode);

	ZEPHIR_SEPARATE_PARAM(data);
	if (!root_param) {
		ZEPHIR_INIT_VAR(root);
		ZVAL_STRING(root, "root", 1);
	} else {
		zephir_get_strval(root, root_param);
	}
	if (!domNode) {
		ZEPHIR_CPY_WRT(domNode, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(domNode);
	}


	if (Z_TYPE_P(domNode) == IS_NULL) {
		ZEPHIR_INIT_VAR(domDoc);
		object_init_ex(domDoc, zephir_get_internal_ce(SS("domdocument") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, domDoc, "__construct", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&domNode, domDoc, "createelement", NULL, 0, root);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, domDoc, "appendchild", NULL, 0, domNode);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_NULL(_0$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "xmlencode", &_1, 151, data, _0$$3, domNode);
		zephir_check_call_status();
		RETURN_CCTOR(domDoc);
	}
	ZEPHIR_OBS_NVAR(domDoc);
	zephir_read_property(&domDoc, domNode, SL("ownerDocument"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_gettype(_2, data TSRMLS_CC);
	ZEPHIR_CPY_WRT(type, _2);
	if (ZEPHIR_IS_STRING(type, "array")) {
		zephir_is_iterable(data, &_4$$4, &_3$$4, 0, 0, "ice/http/response.zep", 678);
		for (
		  ; zend_hash_get_current_data_ex(_4$$4, (void**) &_5$$4, &_3$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_4$$4, &_3$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _4$$4, _3$$4);
			ZEPHIR_GET_HVALUE(val, _5$$4);
			if (Z_TYPE_P(key) == IS_LONG) {
				ZEPHIR_INIT_NVAR(_6$$6);
				ZEPHIR_OBS_NVAR(_7$$6);
				zephir_read_property(&_7$$6, domNode, SL("tagName"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_8$$6);
				ZVAL_STRING(&_8$$6, "s", 0);
				zephir_fast_trim(_6$$6, _7$$6, &_8$$6, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&node, domDoc, "createelement", NULL, 0, _6$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_9$$6);
				ZVAL_STRING(_9$$6, "i", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, node, "setattribute", NULL, 0, _9$$6, key);
				zephir_check_temp_parameter(_9$$6);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&node, domDoc, "createelement", NULL, 0, key);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(NULL, domNode, "appendchild", &_10, 0, node);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_11$$5);
			ZVAL_NULL(_11$$5);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "xmlencode", &_1, 151, val, _11$$5, node);
			zephir_check_call_status();
		}
	} else if (ZEPHIR_IS_STRING(type, "object")) {
		ZEPHIR_INIT_VAR(_12$$8);
		ZVAL_STRING(_12$$8, "__is__", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_13$$8);
		ZVAL_STRING(_13$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, domNode, "setattribute", NULL, 0, _12$$8, _13$$8);
		zephir_check_temp_parameter(_12$$8);
		zephir_check_temp_parameter(_13$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_14$$8, "get_object_vars", NULL, 119, data);
		zephir_check_call_status();
		zephir_is_iterable(_14$$8, &_16$$8, &_15$$8, 0, 0, "ice/http/response.zep", 691);
		for (
		  ; zend_hash_get_current_data_ex(_16$$8, (void**) &_17$$8, &_15$$8) == SUCCESS
		  ; zend_hash_move_forward_ex(_16$$8, &_15$$8)
		) {
			ZEPHIR_GET_HMKEY(key, _16$$8, _15$$8);
			ZEPHIR_GET_HVALUE(val, _17$$8);
			_18$$9 = Z_TYPE_P(val) == IS_ARRAY;
			if (!(_18$$9)) {
				_18$$9 = Z_TYPE_P(val) == IS_OBJECT;
			}
			if (_18$$9) {
				ZEPHIR_CALL_METHOD(&node, domDoc, "createelement", NULL, 0, key);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, domNode, "appendchild", &_10, 0, node);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_19$$10);
				ZVAL_NULL(_19$$10);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "xmlencode", &_1, 151, val, _19$$10, node);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, domNode, "setattribute", NULL, 0, key, val);
				zephir_check_call_status();
			}
		}
	} else {
		if (ZEPHIR_IS_STRING(type, "boolean")) {
			ZEPHIR_INIT_VAR(_20$$13);
			if (zephir_is_true(data)) {
				ZEPHIR_INIT_NVAR(_20$$13);
				ZVAL_STRING(_20$$13, "true", 1);
			} else {
				ZEPHIR_INIT_NVAR(_20$$13);
				ZVAL_STRING(_20$$13, "false", 1);
			}
			ZEPHIR_CPY_WRT(data, _20$$13);
		}
		ZEPHIR_CALL_METHOD(&_21$$12, domDoc, "createtextnode", NULL, 0, data);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, domNode, "appendchild", &_10, 0, _21$$12);
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

	zval *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("body"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	RETURN_CTOR(_1);

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
	zval *size_param = NULL, *_SERVER, *start = NULL, *end = NULL, *range = NULL, *_0$$3, *_1$$3, *_2$$4, *_3$$5, *_4$$5, _5$$6 = zval_used_for_init, *_6$$6 = NULL, *_8$$7, *_9$$7, _10$$7, *_11$$7, *_13$$7, *_14$$8, *_17$$10;
	zend_long size, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &size_param);

	size = zephir_get_intval(size_param);


	ZEPHIR_INIT_VAR(start);
	ZVAL_LONG(start, 0);
	ZEPHIR_INIT_VAR(end);
	ZVAL_LONG(end, (size - 1));
	if (zephir_array_isset_string(_SERVER, SS("HTTP_RANGE"))) {
		zephir_array_fetch_string(&_0$$3, _SERVER, SL("HTTP_RANGE"), PH_NOISY | PH_READONLY, "ice/http/response.zep", 733 TSRMLS_CC);
		ZEPHIR_INIT_VAR(range);
		zephir_fast_explode_str(range, SL("="), _0$$3, 2  TSRMLS_CC);
		zephir_array_fetch_long(&_1$$3, range, 0, PH_NOISY | PH_READONLY, "ice/http/response.zep", 735 TSRMLS_CC);
		if (!ZEPHIR_IS_STRING(_1$$3, "bytes")) {
			ZEPHIR_INIT_ZVAL_NREF(_2$$4);
			ZVAL_LONG(_2$$4, 416);
			zephir_update_property_this(getThis(), SL("status"), _2$$4 TSRMLS_CC);
		} else {
			zephir_array_fetch_long(&_3$$5, range, 1, PH_NOISY | PH_READONLY, "ice/http/response.zep", 740 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(range);
			zephir_fast_explode_str(range, SL(","), _3$$5, 2  TSRMLS_CC);
			zephir_array_fetch_long(&_4$$5, range, 0, PH_NOISY | PH_READONLY, "ice/http/response.zep", 740 TSRMLS_CC);
			ZEPHIR_CPY_WRT(range, _4$$5);
			zephir_array_fetch_long(&_4$$5, range, 0, PH_NOISY | PH_READONLY, "ice/http/response.zep", 743 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(_4$$5, "-")) {
				ZEPHIR_SINIT_VAR(_5$$6);
				ZVAL_LONG(&_5$$6, zephir_get_intval(range));
				ZEPHIR_CALL_FUNCTION(&_6$$6, "abs", &_7, 152, &_5$$6);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_5$$6);
				ZVAL_LONG(&_5$$6, (size - zephir_get_numberval(_6$$6)));
				ZEPHIR_CALL_FUNCTION(&start, "abs", &_7, 152, &_5$$6);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(_8$$7);
				zephir_fast_explode_str(_8$$7, SL("-"), range, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(range, _8$$7);
				ZEPHIR_OBS_VAR(_9$$7);
				zephir_array_fetch_long(&_9$$7, range, 0, PH_NOISY, "ice/http/response.zep", 746 TSRMLS_CC);
				ZEPHIR_SINIT_VAR(_10$$7);
				ZVAL_LONG(&_10$$7, zephir_get_intval(_9$$7));
				ZEPHIR_CALL_FUNCTION(&start, "abs", &_7, 152, &_10$$7);
				zephir_check_call_status();
				zephir_array_fetch_long(&_11$$7, range, 1, PH_NOISY | PH_READONLY, "ice/http/response.zep", 748 TSRMLS_CC);
				_12$$7 = zephir_is_true(_11$$7);
				if (_12$$7) {
					zephir_array_fetch_long(&_13$$7, range, 1, PH_NOISY | PH_READONLY, "ice/http/response.zep", 748 TSRMLS_CC);
					_12$$7 = zephir_is_numeric(_13$$7);
				}
				if (_12$$7) {
					ZEPHIR_OBS_VAR(_14$$8);
					zephir_array_fetch_long(&_14$$8, range, 1, PH_NOISY, "ice/http/response.zep", 749 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(end);
					ZVAL_LONG(end, zephir_get_intval(_14$$8));
				}
			}
			if (ZEPHIR_GT_LONG(end, size)) {
				ZEPHIR_INIT_NVAR(end);
				ZVAL_LONG(end, (size - 1));
			}
			_15$$5 = ZEPHIR_GT(start, end);
			if (!(_15$$5)) {
				_15$$5 = ZEPHIR_GT_LONG(start, (size - 1));
			}
			_16$$5 = _15$$5;
			if (!(_16$$5)) {
				_16$$5 = ZEPHIR_GE_LONG(end, size);
			}
			if (_16$$5) {
				ZEPHIR_INIT_ZVAL_NREF(_17$$10);
				ZVAL_LONG(_17$$10, 416);
				zephir_update_property_this(getThis(), SL("status"), _17$$10 TSRMLS_CC);
			}
		}
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, start);
	zephir_array_fast_append(return_value, end);
	RETURN_MM();

}

