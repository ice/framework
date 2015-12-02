
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * View template engine.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\View, Engine, ice, mvc_view_engine, ice_di_access_ce, ice_mvc_view_engine_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_view_engine_ce, SL("view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_engine_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_mvc_view_engine_ce TSRMLS_CC, 1, ice_mvc_view_engine_engineinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_View_Engine, setOptions) {

	zval *options, options_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&options_sub);

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_zval(this_ptr, SL("options"), options);

}

/**
 * Engine constructor. Set the view and di object.
 */
PHP_METHOD(Ice_Mvc_View_Engine, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *view, view_sub, *di = NULL, di_sub, __$null;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&view_sub);
	ZVAL_UNDEF(&di_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &view, &di);

	if (!di) {
		di = &di_sub;
		di = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("view"), view);
	ZEPHIR_CALL_PARENT(NULL, ice_mvc_view_engine_ce, this_ptr, "__construct", &_0, 29, di);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the view content.
 *
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine, getContent) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Load some view.
 *
 * @param string path
 * @param array data
 */
PHP_METHOD(Ice_Mvc_View_Engine, load) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *path_param = NULL, *data_param = NULL, _0;
	zval path;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &data_param);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "load", NULL, 0, &path, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Load some partial view.
 *
 * @param string path
 * @param array data
 */
PHP_METHOD(Ice_Mvc_View_Engine, partial) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *path_param = NULL, *data_param = NULL, _0;
	zval path;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &data_param);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "partial", NULL, 0, &path, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Render some view.
 *
 * @param string path
 * @param array data
 */
PHP_METHOD(Ice_Mvc_View_Engine, render) {

}

