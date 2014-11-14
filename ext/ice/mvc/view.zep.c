
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "Zend/zend_closures.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_View) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, View, ice, mvc_view, ice_arr_ce, ice_mvc_view_method_entry, 0);

	zend_declare_property_null(ice_mvc_view_ce, SL("_engines"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_ce, SL("_content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_view_ce, SL("_mainView"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_view_ce, SL("_layoutsDir"), "layouts/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_view_ce, SL("_partialsDir"), "partials/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_ce, SL("_viewsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_ce, SL("_file"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_mvc_view_ce, SL("_silent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_mvc_view_ce TSRMLS_CC, 1, ice_mvc_view_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_View, setEngines) {

	zval *engines;

	zephir_fetch_params(0, 1, 0, &engines);



	zephir_update_property_this(this_ptr, SL("_engines"), engines TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, setContent) {

	zval *content;

	zephir_fetch_params(0, 1, 0, &content);



	zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getContent) {


	RETURN_MEMBER(this_ptr, "_content");

}

PHP_METHOD(Ice_Mvc_View, setMainView) {

	zval *mainView;

	zephir_fetch_params(0, 1, 0, &mainView);



	zephir_update_property_this(this_ptr, SL("_mainView"), mainView TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getMainView) {


	RETURN_MEMBER(this_ptr, "_mainView");

}

PHP_METHOD(Ice_Mvc_View, setLayoutsDir) {

	zval *layoutsDir;

	zephir_fetch_params(0, 1, 0, &layoutsDir);



	zephir_update_property_this(this_ptr, SL("_layoutsDir"), layoutsDir TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getLayoutsDir) {


	RETURN_MEMBER(this_ptr, "_layoutsDir");

}

PHP_METHOD(Ice_Mvc_View, setPartialsDir) {

	zval *partialsDir;

	zephir_fetch_params(0, 1, 0, &partialsDir);



	zephir_update_property_this(this_ptr, SL("_partialsDir"), partialsDir TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getPartialsDir) {


	RETURN_MEMBER(this_ptr, "_partialsDir");

}

PHP_METHOD(Ice_Mvc_View, setViewsDir) {

	zval *viewsDir;

	zephir_fetch_params(0, 1, 0, &viewsDir);



	zephir_update_property_this(this_ptr, SL("_viewsDir"), viewsDir TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getViewsDir) {


	RETURN_MEMBER(this_ptr, "_viewsDir");

}

PHP_METHOD(Ice_Mvc_View, setFile) {

	zval *file;

	zephir_fetch_params(0, 1, 0, &file);



	zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getFile) {


	RETURN_MEMBER(this_ptr, "_file");

}

PHP_METHOD(Ice_Mvc_View, setSilent) {

	zval *silent;

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_this(this_ptr, SL("_silent"), silent TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *data = NULL;
	zval *file = NULL, *data_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file, &data_param);

	if (!file) {
		file = ZEPHIR_GLOBAL(global_null);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	if (Z_TYPE_P(file) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	}
	ZEPHIR_CALL_PARENT(NULL, ice_mvc_view_ce, this_ptr, "__construct", &_0, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_View, getEngines) {

	zephir_fcall_cache_entry *_11 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL;
	zval *_7 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *ext = NULL, *engine = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, **_6, _8 = zval_used_for_init, *_9 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_engines"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, ice_mvc_view_engine_php_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, this_ptr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, ".phtml", 1);
		zephir_update_property_array(this_ptr, SL("_engines"), _2, _1 TSRMLS_CC);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_engines"), PH_NOISY_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "ice/mvc/view.zep", 49);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(ext, _5, _4);
		ZEPHIR_GET_HVALUE(engine, _6);
		if (Z_TYPE_P(engine) == IS_OBJECT) {
			if (zephir_instance_of_ev(engine, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(_2);
				ZEPHIR_INIT_NVAR(_7);
				array_init_size(_7, 2);
				zephir_array_fast_append(_7, this_ptr);
				ZEPHIR_CALL_USER_FUNC_ARRAY(_2, engine, _7);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("_engines"), ext, _2 TSRMLS_CC);
			}
		} else {
			if (Z_TYPE_P(engine) == IS_STRING) {
				ZEPHIR_INIT_NVAR(_2);
				ZEPHIR_INIT_NVAR(_7);
				array_init_size(_7, 2);
				zephir_array_fast_append(_7, this_ptr);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_2, engine, _7 TSRMLS_CC);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("_engines"), ext, _2 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_1);
				object_init_ex(_1, ice_exception_ce);
				ZEPHIR_SINIT_NVAR(_8);
				ZVAL_STRING(&_8, "Invalid template engine registration for '%s' extension", 0);
				ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_10, &_8, ext);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_11, _9);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "ice/mvc/view.zep", 45 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_MM_MEMBER(this_ptr, "_engines");

}

PHP_METHOD(Ice_Mvc_View, render) {

	zephir_nts_static zephir_fcall_cache_entry *_12 = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_13 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, _9;
	zval *data = NULL;
	zval *file = NULL, *data_param = NULL, *ext = NULL, *engine = NULL, *engines = NULL, *path = NULL, *content = NULL, *_0, **_3, *_4, *_5, *_7 = NULL, *_10, _11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file, &data_param);

	if (!file) {
		file = ZEPHIR_GLOBAL(global_null);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	exists = 0;
	ZEPHIR_INIT_VAR(content);
	ZVAL_NULL(content);
	if (Z_TYPE_P(file) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "You must set the file to use within your view before rendering", "ice/mvc/view.zep", 64);
		return;
	}
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "getengines",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(engines, &_2, &_1, 0, 0, "ice/mvc/view.zep", 79);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(ext, _2, _1);
		ZEPHIR_GET_HVALUE(engine, _3);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_viewsDir"), PH_NOISY_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(path);
		ZEPHIR_CONCAT_VVV(path, _4, _5, ext);
		if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
			exists = 1;
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", &_6, data);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7, this_ptr, "all",  &_8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&content, engine, "render", NULL, path, _7);
			zephir_check_call_status();
			break;
		}
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_silent"), PH_NOISY_CC);
	_9 = !zephir_is_true(_4);
	if (_9) {
		_9 = !exists;
	}
	if (_9) {
		ZEPHIR_INIT_VAR(_10);
		object_init_ex(_10, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_11);
		ZVAL_STRING(&_11, "The requested view %s could not be found", 0);
		ZEPHIR_CALL_FUNCTION(&_7, "sprintf", &_12, &_11, path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _10, "__construct", &_13, _7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_10, "ice/mvc/view.zep", 80 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(content);

}

PHP_METHOD(Ice_Mvc_View, partial) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *file_param = NULL, *data_param = NULL, *_0, *_1;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &data_param);

	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(file, file_param);
	} else {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_partialsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, _1, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Mvc_View, layout) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *file = NULL, *data_param = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file, &data_param);

	if (!file) {
		ZEPHIR_CPY_WRT(file, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	if (!(zephir_is_true(file))) {
		ZEPHIR_OBS_NVAR(file);
		zephir_read_property_this(&file, this_ptr, SL("_mainView"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_layoutsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, _1, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Mvc_View, setVar) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_View, setVars) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *vars_param = NULL;
	zval *vars = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vars_param);

	if (unlikely(Z_TYPE_P(vars_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'vars' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		vars = vars_param;



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, vars);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_View, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

