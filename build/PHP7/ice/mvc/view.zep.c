
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


/**
 * View is a class for working with the "view" portion of the model-view-controller pattern.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_View) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, View, ice, mvc_view, ice_arr_ce, ice_mvc_view_method_entry, 0);

	zend_declare_property_null(ice_mvc_view_ce, SL("engines"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_ce, SL("content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_view_ce, SL("mainView"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_view_ce, SL("layoutsDir"), "layouts/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_view_ce, SL("partialsDir"), "partials/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_ce, SL("viewsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_ce, SL("file"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_mvc_view_ce, SL("silent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_mvc_view_ce TSRMLS_CC, 1, ice_mvc_view_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_View, setEngines) {

	zval *engines, engines_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&engines_sub);

	zephir_fetch_params(0, 1, 0, &engines);



	zephir_update_property_zval(this_ptr, SL("engines"), engines);

}

PHP_METHOD(Ice_Mvc_View, setContent) {

	zval *content, content_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&content_sub);

	zephir_fetch_params(0, 1, 0, &content);



	zephir_update_property_zval(this_ptr, SL("content"), content);

}

PHP_METHOD(Ice_Mvc_View, getContent) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "content");

}

PHP_METHOD(Ice_Mvc_View, setMainView) {

	zval *mainView, mainView_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&mainView_sub);

	zephir_fetch_params(0, 1, 0, &mainView);



	zephir_update_property_zval(this_ptr, SL("mainView"), mainView);

}

PHP_METHOD(Ice_Mvc_View, getMainView) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "mainView");

}

PHP_METHOD(Ice_Mvc_View, setLayoutsDir) {

	zval *layoutsDir, layoutsDir_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&layoutsDir_sub);

	zephir_fetch_params(0, 1, 0, &layoutsDir);



	zephir_update_property_zval(this_ptr, SL("layoutsDir"), layoutsDir);

}

PHP_METHOD(Ice_Mvc_View, getLayoutsDir) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "layoutsDir");

}

PHP_METHOD(Ice_Mvc_View, setPartialsDir) {

	zval *partialsDir, partialsDir_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&partialsDir_sub);

	zephir_fetch_params(0, 1, 0, &partialsDir);



	zephir_update_property_zval(this_ptr, SL("partialsDir"), partialsDir);

}

PHP_METHOD(Ice_Mvc_View, getPartialsDir) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "partialsDir");

}

PHP_METHOD(Ice_Mvc_View, setViewsDir) {

	zval *viewsDir, viewsDir_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&viewsDir_sub);

	zephir_fetch_params(0, 1, 0, &viewsDir);



	zephir_update_property_zval(this_ptr, SL("viewsDir"), viewsDir);

}

PHP_METHOD(Ice_Mvc_View, getViewsDir) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "viewsDir");

}

PHP_METHOD(Ice_Mvc_View, setFile) {

	zval *file, file_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&file_sub);

	zephir_fetch_params(0, 1, 0, &file);



	zephir_update_property_zval(this_ptr, SL("file"), file);

}

PHP_METHOD(Ice_Mvc_View, getFile) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "file");

}

PHP_METHOD(Ice_Mvc_View, setSilent) {

	zval *silent, silent_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&silent_sub);

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_zval(this_ptr, SL("silent"), silent);

}

/**
 * View constructor. Set the file and vars.
 *
 * @param string file
 * @param array data
 */
PHP_METHOD(Ice_Mvc_View, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval data;
	zval *file = NULL, file_sub, *data_param = NULL, __$null;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&file_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file, &data_param);

	if (!file) {
		file = &file_sub;
		file = &__$null;
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	if (Z_TYPE_P(file) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("file"), file);
	}
	ZEPHIR_CALL_PARENT(NULL, ice_mvc_view_ce, this_ptr, "__construct", &_0, 6, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get registered engines.
 */
PHP_METHOD(Ice_Mvc_View, getEngines) {

	zval _8$$6, _10$$8;
	zend_string *_6;
	zend_ulong _5;
	zval ext, engine, _0, _3, *_4, _1$$3, _2$$3, _7$$6, _9$$8, _11$$9, _12$$9, _13$$9;
	zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$8);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("engines"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, ice_mvc_view_engine_php_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 124, this_ptr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, ".phtml");
		zephir_update_property_array(this_ptr, SL("engines"), &_2$$3, &_1$$3 TSRMLS_CC);
	}
	zephir_read_property(&_3, this_ptr, SL("engines"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "ice/mvc/view.zep", 67);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&ext);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&ext, _6);
		} else {
			ZVAL_LONG(&ext, _5);
		}
		ZEPHIR_INIT_NVAR(&engine);
		ZVAL_COPY(&engine, _4);
		if (Z_TYPE_P(&engine) == IS_OBJECT) {
			if (zephir_instance_of_ev(&engine, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZEPHIR_INIT_NVAR(&_8$$6);
				zephir_create_array(&_8$$6, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&_8$$6, this_ptr);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_7$$6, &engine, &_8$$6);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("engines"), &ext, &_7$$6 TSRMLS_CC);
			}
		} else {
			if (Z_TYPE_P(&engine) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_9$$8);
				ZEPHIR_INIT_NVAR(&_10$$8);
				zephir_create_array(&_10$$8, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&_10$$8, this_ptr);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_9$$8, &engine, &_10$$8 TSRMLS_CC);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("engines"), &ext, &_9$$8 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(&_11$$9);
				object_init_ex(&_11$$9, ice_exception_ce);
				ZEPHIR_INIT_NVAR(&_12$$9);
				ZVAL_STRING(&_12$$9, "Invalid template engine registration for '%s' extension");
				ZEPHIR_CALL_FUNCTION(&_13$$9, "sprintf", &_14, 1, &_12$$9, &ext);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_11$$9, "__construct", &_15, 2, &_13$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$9, "ice/mvc/view.zep", 63 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&engine);
	ZEPHIR_INIT_NVAR(&ext);
	RETURN_MM_MEMBER(this_ptr, "engines");

}

/**
 * Try to render the view with vars for engines.
 *
 * @param string file
 * @param array data
 * @return string
 */
PHP_METHOD(Ice_Mvc_View, render) {

	zend_string *_3;
	zend_ulong _2;
	zend_bool exists = 0, _10;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file = NULL, file_sub, *data_param = NULL, __$null, ext, engine, engines, path, content, _0, *_1, _9, _4$$5, _5$$5, _7$$6, _11$$7, _12$$7, _13$$7;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&file_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file, &data_param);

	if (!file) {
		file = &file_sub;
		file = &__$null;
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	exists = 0;
	ZEPHIR_INIT_VAR(&content);
	ZVAL_NULL(&content);
	if (Z_TYPE_P(file) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("file"), file);
	}
	zephir_read_property(&_0, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "You must set the file to use within your view before rendering", "ice/mvc/view.zep", 89);
		return;
	}
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "getengines", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&engines, 0, "ice/mvc/view.zep", 104);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&ext);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&ext, _3);
		} else {
			ZVAL_LONG(&ext, _2);
		}
		ZEPHIR_INIT_NVAR(&engine);
		ZVAL_COPY(&engine, _1);
		zephir_read_property(&_4$$5, this_ptr, SL("viewsDir"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_5$$5, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&path);
		ZEPHIR_CONCAT_VVV(&path, &_4$$5, &_5$$5, &ext);
		if ((zephir_file_exists(&path TSRMLS_CC) == SUCCESS)) {
			exists = 1;
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", &_6, 0, &data);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "all", &_8, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&content, &engine, "render", NULL, 0, &path, &_7$$6);
			zephir_check_call_status();
			break;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&engine);
	ZEPHIR_INIT_NVAR(&ext);
	zephir_read_property(&_9, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
	_10 = !zephir_is_true(&_9);
	if (_10) {
		_10 = !exists;
	}
	if (_10) {
		ZEPHIR_INIT_VAR(&_11$$7);
		object_init_ex(&_11$$7, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_12$$7);
		ZVAL_STRING(&_12$$7, "The requested view %s could not be found");
		ZEPHIR_CALL_FUNCTION(&_13$$7, "sprintf", NULL, 1, &_12$$7, &path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_11$$7, "__construct", &_14, 2, &_13$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$7, "ice/mvc/view.zep", 105 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(content);

}

/**
 * Load the view.
 *
 * @param string file Name of file without extension from the views dir
 * @param array data Vars to send
 * @return string
 */
PHP_METHOD(Ice_Mvc_View, load) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file_param = NULL, *data_param = NULL;
	zval file;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &data_param);

	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_EMPTY_STRING(&file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, &file, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Load the partial view.
 *
 * @param string file Name of file without extension from the partials dir
 * @param array data Vars to send
 * @return string
 */
PHP_METHOD(Ice_Mvc_View, partial) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file_param = NULL, *data_param = NULL, _0, _1;
	zval file;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &data_param);

	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_EMPTY_STRING(&file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	zephir_read_property(&_0, this_ptr, SL("partialsDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, &file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, &_1, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Load the layout view.
 *
 * @param string file Name of file without extension from the layouts dir
 * @param array data Vars to send
 * @return string
 */
PHP_METHOD(Ice_Mvc_View, layout) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file = NULL, file_sub, *data_param = NULL, __$null, _0, _1;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&file_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file, &data_param);

	if (!file) {
		file = &file_sub;
		ZEPHIR_CPY_WRT(file, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	if (!(zephir_is_true(file))) {
		ZEPHIR_OBS_NVAR(file);
		zephir_read_property(file, this_ptr, SL("mainView"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, SL("layoutsDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, &_1, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set var to the view.
 *
 * @param string name
 * @param mixed value
 */
PHP_METHOD(Ice_Mvc_View, setVar) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub;
	zval name;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &name, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set multiple vars to the view.
 *
 * @param array vars
 */
PHP_METHOD(Ice_Mvc_View, setVars) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *vars_param = NULL;
	zval vars;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&vars);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vars_param);

	ZVAL_COPY_VALUE(&vars, vars_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, &vars);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic toStrint, get the rendered view.
 */
PHP_METHOD(Ice_Mvc_View, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

