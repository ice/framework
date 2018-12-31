
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
 * @copyright   (c) 2014-2018 Ice Team
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

	zval *engines;

	zephir_fetch_params(0, 1, 0, &engines);



	zephir_update_property_this(getThis(), SL("engines"), engines TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_View, setContent) {

	zval *content;

	zephir_fetch_params(0, 1, 0, &content);



	zephir_update_property_this(getThis(), SL("content"), content TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_View, getContent) {

	

	RETURN_MEMBER(getThis(), "content");

}

PHP_METHOD(Ice_Mvc_View, setMainView) {

	zval *mainView;

	zephir_fetch_params(0, 1, 0, &mainView);



	zephir_update_property_this(getThis(), SL("mainView"), mainView TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_View, getMainView) {

	

	RETURN_MEMBER(getThis(), "mainView");

}

PHP_METHOD(Ice_Mvc_View, setLayoutsDir) {

	zval *layoutsDir;

	zephir_fetch_params(0, 1, 0, &layoutsDir);



	zephir_update_property_this(getThis(), SL("layoutsDir"), layoutsDir TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_View, getLayoutsDir) {

	

	RETURN_MEMBER(getThis(), "layoutsDir");

}

PHP_METHOD(Ice_Mvc_View, setPartialsDir) {

	zval *partialsDir;

	zephir_fetch_params(0, 1, 0, &partialsDir);



	zephir_update_property_this(getThis(), SL("partialsDir"), partialsDir TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_View, getPartialsDir) {

	

	RETURN_MEMBER(getThis(), "partialsDir");

}

PHP_METHOD(Ice_Mvc_View, setViewsDir) {

	zval *viewsDir;

	zephir_fetch_params(0, 1, 0, &viewsDir);



	zephir_update_property_this(getThis(), SL("viewsDir"), viewsDir TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_View, getViewsDir) {

	

	RETURN_MEMBER(getThis(), "viewsDir");

}

PHP_METHOD(Ice_Mvc_View, setFile) {

	zval *file;

	zephir_fetch_params(0, 1, 0, &file);



	zephir_update_property_this(getThis(), SL("file"), file TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_View, getFile) {

	

	RETURN_MEMBER(getThis(), "file");

}

PHP_METHOD(Ice_Mvc_View, setSilent) {

	zval *silent;

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_this(getThis(), SL("silent"), silent TSRMLS_CC);
	RETURN_THISW();

}

/**
 * View constructor. Set the file and vars.
 *
 * @param string file
 * @param array data
 */
PHP_METHOD(Ice_Mvc_View, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
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
		zephir_update_property_this(getThis(), SL("file"), file TSRMLS_CC);
	}
	ZEPHIR_CALL_PARENT(NULL, ice_mvc_view_ce, getThis(), "__construct", &_0, 5, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get registered engines.
 */
PHP_METHOD(Ice_Mvc_View, getEngines) {

	zval *_8$$7 = NULL, *_10$$9 = NULL;
	HashTable *_5$$4;
	HashPosition _4$$4;
	zval *ext = NULL, *engine = NULL, *_0, *_1$$3, *_2$$3, *_3$$4, **_6$$4, *_7$$7 = NULL, *_9$$9 = NULL, *_11$$10 = NULL, _12$$10 = zval_used_for_init, *_13$$10 = NULL;
	zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("engines"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, ice_mvc_view_engine_php_ce);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 171, this_ptr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, ".phtml", 1);
		zephir_update_property_array(this_ptr, SL("engines"), _2$$3, _1$$3 TSRMLS_CC);
	} else {
		_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("engines"), PH_NOISY_CC);
		zephir_is_iterable(_3$$4, &_5$$4, &_4$$4, 0, 0, "ice/mvc/view.zep", 67);
		for (
		  ; zend_hash_get_current_data_ex(_5$$4, (void**) &_6$$4, &_4$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_5$$4, &_4$$4)
		) {
			ZEPHIR_GET_HMKEY(ext, _5$$4, _4$$4);
			ZEPHIR_GET_HVALUE(engine, _6$$4);
			if (Z_TYPE_P(engine) == IS_OBJECT) {
				if (zephir_instance_of_ev(engine, zend_ce_closure TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_7$$7);
					ZEPHIR_INIT_NVAR(_8$$7);
					zephir_create_array(_8$$7, 1, 0 TSRMLS_CC);
					zephir_array_fast_append(_8$$7, this_ptr);
					ZEPHIR_CALL_USER_FUNC_ARRAY(_7$$7, engine, _8$$7);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("engines"), ext, _7$$7 TSRMLS_CC);
				}
			} else {
				if (Z_TYPE_P(engine) == IS_STRING) {
					ZEPHIR_INIT_NVAR(_9$$9);
					ZEPHIR_INIT_NVAR(_10$$9);
					zephir_create_array(_10$$9, 1, 0 TSRMLS_CC);
					zephir_array_fast_append(_10$$9, this_ptr);
					ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_9$$9, engine, _10$$9 TSRMLS_CC);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("engines"), ext, _9$$9 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(_11$$10);
					object_init_ex(_11$$10, ice_exception_ce);
					ZEPHIR_SINIT_NVAR(_12$$10);
					ZVAL_STRING(&_12$$10, "Invalid template engine registration for '%s' extension", 0);
					ZEPHIR_CALL_FUNCTION(&_13$$10, "sprintf", &_14, 12, &_12$$10, ext);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, _11$$10, "__construct", &_15, 13, _13$$10);
					zephir_check_call_status();
					zephir_throw_exception_debug(_11$$10, "ice/mvc/view.zep", 63 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	RETURN_MM_MEMBER(getThis(), "engines");

}

/**
 * Try to render the view with vars for engines.
 *
 * @param string file
 * @param array data
 * @return string
 */
PHP_METHOD(Ice_Mvc_View, render) {

	HashTable *_7$$8, *_15$$11, *_18$$12;
	HashPosition _6$$8, _14$$11, _17$$12;
	zend_bool exists = 0, _24;
	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL, *_13 = NULL, *_22 = NULL, *_28 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *file = NULL, *data_param = NULL, *ext = NULL, *engine = NULL, *engines = NULL, *path = NULL, *dir = NULL, *dirs = NULL, *content = NULL, *_0, *_1, *_3, _4, *_23, *_2$$6, *_5$$7, **_8$$8, *_9$$9, *_11$$10 = NULL, **_16$$11, **_19$$12, *_20$$13, *_21$$14 = NULL, *_25$$16, _26$$16, *_27$$16 = NULL;

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
		zephir_update_property_this(getThis(), SL("file"), file TSRMLS_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("file"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "You must set the file to use within your view before rendering", "ice/mvc/view.zep", 90);
		return;
	}
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "getengines", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("viewsDir"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(dirs);
		zephir_read_property_this(&dirs, this_ptr, SL("viewsDir"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_NVAR(dirs);
		zephir_create_array(dirs, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_2$$6);
		zephir_read_property_this(&_2$$6, this_ptr, SL("viewsDir"), PH_NOISY_CC);
		zephir_array_fast_append(dirs, _2$$6);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("file"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", NULL, 172, _3, &_4);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(ext))) {
		ZEPHIR_OBS_VAR(engine);
		ZEPHIR_INIT_VAR(_5$$7);
		ZEPHIR_CONCAT_SV(_5$$7, ".", ext);
		if (zephir_array_isset_fetch(&engine, engines, _5$$7, 0 TSRMLS_CC)) {
			zephir_is_iterable(dirs, &_7$$8, &_6$$8, 0, 0, "ice/mvc/view.zep", 114);
			for (
			  ; zend_hash_get_current_data_ex(_7$$8, (void**) &_8$$8, &_6$$8) == SUCCESS
			  ; zend_hash_move_forward_ex(_7$$8, &_6$$8)
			) {
				ZEPHIR_GET_HVALUE(dir, _8$$8);
				_9$$9 = zephir_fetch_nproperty_this(this_ptr, SL("file"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(path);
				ZEPHIR_CONCAT_VV(path, dir, _9$$9);
				if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
					exists = 1;
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", &_10, 0, data);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_11$$10, this_ptr, "all", &_12, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&content, engine, "render", &_13, 0, path, _11$$10);
					zephir_check_call_status();
					break;
				}
			}
		}
	} else {
		zephir_is_iterable(engines, &_15$$11, &_14$$11, 0, 0, "ice/mvc/view.zep", 131);
		for (
		  ; zend_hash_get_current_data_ex(_15$$11, (void**) &_16$$11, &_14$$11) == SUCCESS
		  ; zend_hash_move_forward_ex(_15$$11, &_14$$11)
		) {
			ZEPHIR_GET_HMKEY(ext, _15$$11, _14$$11);
			ZEPHIR_GET_HVALUE(engine, _16$$11);
			zephir_is_iterable(dirs, &_18$$12, &_17$$12, 0, 0, "ice/mvc/view.zep", 127);
			for (
			  ; zend_hash_get_current_data_ex(_18$$12, (void**) &_19$$12, &_17$$12) == SUCCESS
			  ; zend_hash_move_forward_ex(_18$$12, &_17$$12)
			) {
				ZEPHIR_GET_HVALUE(dir, _19$$12);
				_20$$13 = zephir_fetch_nproperty_this(this_ptr, SL("file"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(path);
				ZEPHIR_CONCAT_VVV(path, dir, _20$$13, ext);
				if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
					exists = 1;
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", &_10, 0, data);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_21$$14, this_ptr, "all", &_12, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&content, engine, "render", &_22, 0, path, _21$$14);
					zephir_check_call_status();
					break;
				}
			}
			if (exists) {
				break;
			}
		}
	}
	_23 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
	_24 = !zephir_is_true(_23);
	if (_24) {
		_24 = !exists;
	}
	if (_24) {
		ZEPHIR_INIT_VAR(_25$$16);
		object_init_ex(_25$$16, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_26$$16);
		ZVAL_STRING(&_26$$16, "The requested view %s could not be found", 0);
		ZEPHIR_CALL_FUNCTION(&_27$$16, "sprintf", NULL, 12, &_26$$16, path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _25$$16, "__construct", &_28, 13, _27$$16);
		zephir_check_call_status();
		zephir_throw_exception_debug(_25$$16, "ice/mvc/view.zep", 134 TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *file_param = NULL, *data_param = NULL;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, file, data);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *file_param = NULL, *data_param = NULL, *_0, *_1;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("partialsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, _1, data);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
		zephir_read_property_this(&file, this_ptr, SL("mainView"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("layoutsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, _1, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set var to the view.
 *
 * @param string name
 * @param mixed value
 * @return object View
 */
PHP_METHOD(Ice_Mvc_View, setVar) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set multiple vars to the view.
 *
 * @param array vars
 * @return object View
 */
PHP_METHOD(Ice_Mvc_View, setVars) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *vars_param = NULL;
	zval *vars = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vars_param);

	vars = vars_param;


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, vars);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Alias of the `setMainView` method.
 *
 * @param array vars
 * @return object View
 */
PHP_METHOD(Ice_Mvc_View, setLayout) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *layout_param = NULL;
	zval *layout = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layout_param);

	zephir_get_strval(layout, layout_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmainview", NULL, 0, layout);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Magic toStrint, get the rendered view.
 */
PHP_METHOD(Ice_Mvc_View, __toString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

