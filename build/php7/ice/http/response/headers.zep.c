
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/iterator.h"
#include "kernel/concat.h"


/**
 * This class is a bag to manage the response headers.
 *
 * @package     Ice/Http
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Http_Response_Headers) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Http\\Response, Headers, ice, http_response_headers, ice_arr_ce, ice_http_response_headers_method_entry, 0);

	zend_class_implements(ice_http_response_headers_ce TSRMLS_CC, 1, ice_http_response_headersinterface_ce);
	return SUCCESS;

}

/**
 * Sends the headers to the client.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Response_Headers, send) {

	zend_object_iterator *_1$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	zval __$true, header, value, _0, _2$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 125);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		_1$$3 = zephir_get_iterator(this_ptr TSRMLS_CC);
		_1$$3->funcs->rewind(_1$$3 TSRMLS_CC);
		for (;_1$$3->funcs->valid(_1$$3 TSRMLS_CC) == SUCCESS && !EG(exception); _1$$3->funcs->move_forward(_1$$3 TSRMLS_CC)) {
			ZEPHIR_GET_IMKEY(header, _1$$3);
			{
				ZEPHIR_ITERATOR_COPY(&value, _1$$3);
			}
			if (!(ZEPHIR_IS_EMPTY(&value))) {
				ZEPHIR_INIT_LNVAR(_2$$5);
				ZEPHIR_CONCAT_VSV(&_2$$5, &header, ": ", &value);
				ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 126, &_2$$5, &__$true);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 126, &header, &__$true);
				zephir_check_call_status();
			}
		}
		zend_iterator_dtor(_1$$3);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

