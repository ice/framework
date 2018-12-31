
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

	zval *valid = NULL, *_0 = NULL, *_1$$3 = NULL, *_3$$3, *_4$$4 = NULL, *_6$$5, *_7$$5 = NULL, *_8$$5, *_9$$6 = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 138);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "session_start", &_2, 196);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("started"), _1$$3 TSRMLS_CC);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("started"), PH_NOISY_CC);
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_INIT_VAR(valid);
			ZVAL_STRING(valid, "__valid__", 1);
			ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "has", &_5, 0, valid);
			zephir_check_call_status();
			if (!(zephir_is_true(_4$$4))) {
				ZEPHIR_INIT_VAR(_6$$5);
				ZVAL_BOOL(_6$$5, 1);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, valid, _6$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "session_write_close", NULL, 197);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_7$$5, "session_start", &_2, 196);
				zephir_check_call_status();
				zephir_update_property_this(getThis(), SL("started"), _7$$5 TSRMLS_CC);
				_8$$5 = zephir_fetch_nproperty_this(this_ptr, SL("started"), PH_NOISY_CC);
				if (zephir_is_true(_8$$5)) {
					ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "has", &_5, 0, valid);
					zephir_check_call_status();
					if (!(zephir_is_true(_9$$6))) {
						if (0) {
							zephir_update_property_this(getThis(), SL("started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
						} else {
							zephir_update_property_this(getThis(), SL("started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
						}
					} else {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, valid);
						zephir_check_call_status();
					}
				}
			}
		}
	}
	RETURN_MM_MEMBER(getThis(), "started");

}

/**
 * Check whether the session was started.
 *
 * @param boolean autoStart If session is not started, try to start it
 * @return boolean
 */
PHP_METHOD(Ice_Session, isStarted) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *autoStart_param = NULL, *_0, *_3 = NULL, *_1$$3 = NULL;
	zend_bool autoStart;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &autoStart_param);

	if (!autoStart_param) {
		autoStart = 1;
	} else {
		autoStart = zephir_get_boolval(autoStart_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("started"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "session_status", NULL, 198);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(_1$$3, 1)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "start", &_2, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_3);
	if (autoStart) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "start", &_2, 0);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(_3, 0);
	}
	RETURN_CCTOR(_3);

}

/**
 * Get session id.
 *
 * @return string
 */
PHP_METHOD(Ice_Session, getId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_id", NULL, 199);
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

	ZEPHIR_RETURN_CALL_FUNCTION("session_regenerate_id", NULL, 200);
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
	ZEPHIR_RETURN_CALL_FUNCTION("session_destroy", NULL, 201);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether session has the key.
 * No support for passing variables by reference yet zephir/issues/203
 *
 * @return boolean
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
 *
 * @return mixed
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
 *
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
 *
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

/**
 * Fetch all data.
 *
 * @return array
 */
PHP_METHOD(Ice_Session, getData) {

	zval *_SESSION;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);

	RETVAL_ZVAL(_SESSION, 1, 0);
	RETURN_MM();

}

