
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * Session helper.
 *
 * @package     Ice/Session
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Session) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Session, ice, session, ice_arr_ce, ice_session_method_entry, 0);

	zend_declare_property_bool(ice_session_ce, SL("started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Session constructor. Start the session.
 */
PHP_METHOD(Ice_Session, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "start", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Start the session.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Session, start) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 136);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_start", NULL, 195);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_this(getThis(), SL("started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Check whether the session was started.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Session, isStarted) {

	

	RETURN_MEMBER(getThis(), "started");

}

/**
 * Get session id.
 *
 * @return string
 */
PHP_METHOD(Ice_Session, getId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_id", NULL, 196);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Regenerate session id.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Session, regenerate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_regenerate_id", NULL, 197);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Destroy the session.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Session, destroy) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	if (0) {
		zephir_update_property_this(getThis(), SL("started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("session_destroy", NULL, 198);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether session has the key.
 * No support for passing variables by reference yet zephir/issues/203
 */
PHP_METHOD(Ice_Session, has) {

	zval *key_param = NULL, *_SESSION;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	RETURN_MM_BOOL(zephir_array_isset(_SESSION, key));

}

/**
 * Retrieve a single key from the session.
 * @return mix
 */
PHP_METHOD(Ice_Session, get) {

	zend_bool required;
	zval *key_param = NULL, *defaultValue = NULL, *required_param = NULL, *_SESSION, *value = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 1, 2, &key_param, &defaultValue, &required_param);

	zephir_get_strval(key, key_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!required_param) {
		required = 0;
	} else {
		required = zephir_get_boolval(required_param);
	}


	if (zephir_array_isset_fetch(&value, _SESSION, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Assigns a value to the specified session key.
 * @return object Session
 */
PHP_METHOD(Ice_Session, set) {

	zval *key_param = NULL, *value, *_SESSION;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_array_update_zval(&_SESSION, key, &value, PH_COPY | PH_SEPARATE);
	RETURN_THIS();

}

/**
 * Remove session key.
 * @return object Session
 */
PHP_METHOD(Ice_Session, remove) {

	zval *key_param = NULL, *_SESSION;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	zephir_array_unset(&_SESSION, key, PH_SEPARATE);
	RETURN_THIS();

}

