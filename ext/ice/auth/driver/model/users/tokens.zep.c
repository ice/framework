
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/iterator.h"


/**
 * Model user's Tokens.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users_Tokens) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model\\Users, Tokens, ice, auth_driver_model_users_tokens, ice_mvc_model_ce, ice_auth_driver_model_users_tokens_method_entry, 0);

	zend_declare_property_string(ice_auth_driver_model_users_tokens_ce, SL("_from"), "user_tokens", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Initialize token's relations, remove expired tokens
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, initialize) {

	zend_bool _10, _12;
	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL;
	zval *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *auth = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, _5, _6, *_7 = NULL, *_9 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&auth, _0, "getauth", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Ice\\Auth\\Driver\\Model\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, auth, "getoption", NULL, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	array_init_size(_4, 3);
	add_assoc_stringl_ex(_4, SS("alias"), SL("User"), 1);
	zephir_array_update_string(&_4, SL("foreignKey"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, _2, _1, _3, _4);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 1);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 100);
	ZEPHIR_CALL_FUNCTION(&_7, "mt_rand", &_8, &_5, &_6);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(_7, 1)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteexpired", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "expires", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "has", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_10 = zephir_is_true(_9);
	if (_10) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "expires", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		_10 = zephir_is_true(_11);
	}
	_12 = _10;
	if (_12) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "expires", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_14, "time", NULL);
		zephir_check_call_status();
		_12 = ZEPHIR_LT(_13, _14);
	}
	if (_12) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Generate a new unique token and create the token
 *
 * @param array fields Fields to save or valid fields
 * @param object extra Extra validation
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, create) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *fields = NULL, *extra = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(extra) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(extra, ice_validation_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'extra' must be an instance of 'Ice\\Validation'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_generate", NULL);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("token"), _1 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_model_users_tokens_ce, this_ptr, "create", &_2, fields);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes all expired tokens
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, deleteExpired) {

	zend_object_iterator *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;
	zval *token = NULL, *expired = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 2);
	ZEPHIR_CALL_FUNCTION(&_2, "time", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("<"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("expires"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&expired, this_ptr, "load", NULL, _0);
	zephir_check_call_status();
	_3 = zephir_get_iterator(expired TSRMLS_CC);
	_3->funcs->rewind(_3 TSRMLS_CC);
	for (;_3->funcs->valid(_3 TSRMLS_CC) == SUCCESS && !EG(exception); _3->funcs->move_forward(_3 TSRMLS_CC)) {
		{ zval **tmp; 
		_3->funcs->get_current_data(_3, &tmp TSRMLS_CC);
		token = *tmp;
		}
		ZEPHIR_CALL_METHOD(NULL, token, "remove", NULL);
		zephir_check_call_status();
	}
	_3->funcs->dtor(_3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Generate a new unique token and update the token
 *
 * @param array fields Fields to save or valid fields
 * @param object extra Extra validation
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, update) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *fields = NULL, *extra = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(extra) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(extra, ice_validation_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'extra' must be an instance of 'Ice\\Validation'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_generate", NULL);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("token"), _1 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_model_users_tokens_ce, this_ptr, "update", &_2, fields);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate a new unique token
 *
 * @return string
 * @uses Text::random()
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, _generate) {

	zval *_8 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL;
	zval *token = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	do {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 32);
		ZEPHIR_CALL_CE_STATIC(&_0, ice_text_ce, "random", &_1, _2, _3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_4, "uniqid", &_5, _0, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&token, "sha1", &_6, _4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_8);
		array_init_size(_8, 2);
		zephir_array_update_string(&_8, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_SELF(&_0, "findone", &_7, _8);
		zephir_check_call_status();
	} while (zephir_is_true(_0));
	RETURN_CCTOR(token);

}

