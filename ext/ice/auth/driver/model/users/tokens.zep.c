
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
#include "kernel/math.h"
#include "kernel/operators.h"
#include "kernel/time.h"
#include "kernel/object.h"
#include "kernel/iterator.h"


/**
 * Model user's Tokens.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users_Tokens) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model\\Users, Tokens, ice, auth_driver_model_users_tokens, ice_mvc_model_ce, ice_auth_driver_model_users_tokens_method_entry, 0);

	zend_declare_property_string(ice_auth_driver_model_users_tokens_ce, SL("from"), "user_tokens", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Initialize token's relations, remove expired tokens.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, initialize) {

	zend_bool _10, _12;
	zval *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *auth = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_5 = NULL, _7, _8, *_9 = NULL, *_11 = NULL, *_13 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "auth", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(&auth, _0, "get", NULL, 0, _1, _2, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, auth, "getoption", NULL, 0, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_6, SS("alias"), SL("User"), 1);
	zephir_array_update_string(&_6, SL("foreignKey"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, 0, _1, _4, _5, _6);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 1);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 100);
	if (zephir_mt_rand(zephir_get_intval(&_7), zephir_get_intval(&_8) TSRMLS_CC) == 1) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteexpired", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "expires", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_10 = zephir_is_true(_9);
	if (_10) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "expires", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_10 = zephir_is_true(_11);
	}
	_12 = _10;
	if (_12) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "expires", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1);
		zephir_time(_1);
		_12 = ZEPHIR_LT(_13, _1);
	}
	if (_12) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Generate a new unique token and create the token.
 *
 * @param array fields Fields to save or valid fields
 * @param object extra Extra validation
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, create) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, *extra = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generate", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("token"), _0 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_model_users_tokens_ce, this_ptr, "create", &_1, 42, fields);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes all expired tokens.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, deleteExpired) {

	zend_object_iterator *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;
	zval *token = NULL, *expired = NULL, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_time(_2);
	zephir_array_update_string(&_1, SL("<"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("expires"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&expired, this_ptr, "load", NULL, 0, _0);
	zephir_check_call_status();
	_3 = zephir_get_iterator(expired TSRMLS_CC);
	_3->funcs->rewind(_3 TSRMLS_CC);
	for (;_3->funcs->valid(_3 TSRMLS_CC) == SUCCESS && !EG(exception); _3->funcs->move_forward(_3 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_3->funcs->get_current_data(_3, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(token, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_CALL_METHOD(NULL, token, "remove", NULL, 0);
		zephir_check_call_status();
	}
	_3->funcs->dtor(_3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Generate a new unique token and update the token.
 *
 * @param array fields Fields to save or valid fields
 * @param object extra Extra validation
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, update) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, *extra = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generate", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("token"), _0 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_model_users_tokens_ce, this_ptr, "update", &_1, 43, fields);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate a new unique token.
 *
 * @return string
 * @uses Text::random()
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, generate) {

	zval *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL;
	zval *token = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	do {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 32);
		ZEPHIR_CALL_CE_STATIC(&_0, ice_text_ce, "random", &_1, 0, _2, _3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_4, "uniqid", &_5, 44, _0, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&token, "sha1", &_6, 36, _4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_8);
		zephir_create_array(_8, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_8, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_SELF(&_0, "findone", &_7, 0, _8);
		zephir_check_call_status();
	} while (zephir_is_true(_0));
	RETURN_CCTOR(token);

}

