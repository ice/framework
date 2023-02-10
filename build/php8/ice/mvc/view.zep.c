
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
 * @copyright   (c) 2014-2023 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_View)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, View, ice, mvc_view, ice_arr_ce, ice_mvc_view_method_entry, 0);

	zend_declare_property_null(ice_mvc_view_ce, SL("engines"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_view_ce, SL("content"), ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_mvc_view_ce, SL("mainView"), "index", ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_mvc_view_ce, SL("layoutsDir"), "layouts/", ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_mvc_view_ce, SL("partialsDir"), "partials/", ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_view_ce, SL("viewsDir"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_view_ce, SL("file"), ZEND_ACC_PROTECTED);
	zend_declare_property_bool(ice_mvc_view_ce, SL("silent"), 0, ZEND_ACC_PROTECTED);
	zend_class_implements(ice_mvc_view_ce, 1, ice_mvc_view_viewinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Ice_Mvc_View, setEngines)
{
	zval *engines, engines_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(engines)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &engines);


	zephir_update_property_zval(this_ptr, ZEND_STRL("engines"), engines);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, setContent)
{
	zval *content, content_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(content)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &content);


	zephir_update_property_zval(this_ptr, ZEND_STRL("content"), content);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getContent)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "content");
}

PHP_METHOD(Ice_Mvc_View, setMainView)
{
	zval *mainView, mainView_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mainView_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(mainView)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &mainView);


	zephir_update_property_zval(this_ptr, ZEND_STRL("mainView"), mainView);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getMainView)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "mainView");
}

PHP_METHOD(Ice_Mvc_View, setLayoutsDir)
{
	zval *layoutsDir, layoutsDir_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&layoutsDir_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(layoutsDir)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &layoutsDir);


	zephir_update_property_zval(this_ptr, ZEND_STRL("layoutsDir"), layoutsDir);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getLayoutsDir)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "layoutsDir");
}

PHP_METHOD(Ice_Mvc_View, setPartialsDir)
{
	zval *partialsDir, partialsDir_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialsDir_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(partialsDir)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &partialsDir);


	zephir_update_property_zval(this_ptr, ZEND_STRL("partialsDir"), partialsDir);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getPartialsDir)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "partialsDir");
}

PHP_METHOD(Ice_Mvc_View, setViewsDir)
{
	zval *viewsDir, viewsDir_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewsDir_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(viewsDir)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &viewsDir);


	zephir_update_property_zval(this_ptr, ZEND_STRL("viewsDir"), viewsDir);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getViewsDir)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "viewsDir");
}

PHP_METHOD(Ice_Mvc_View, setFile)
{
	zval *file, file_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(file)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &file);


	zephir_update_property_zval(this_ptr, ZEND_STRL("file"), file);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getFile)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "file");
}

PHP_METHOD(Ice_Mvc_View, setSilent)
{
	zval *silent, silent_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&silent_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(silent)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &silent);


	zephir_update_property_zval(this_ptr, ZEND_STRL("silent"), silent);
	RETURN_THISW();
}

/**
 * View constructor. Set the file and vars.
 *
 * @param string file
 * @param array data
 */
PHP_METHOD(Ice_Mvc_View, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval data;
	zval *file = NULL, file_sub, *data_param = NULL, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(file)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		zephir_update_property_zval(this_ptr, ZEND_STRL("file"), file);
	}
	ZEPHIR_CALL_PARENT(NULL, ice_mvc_view_ce, getThis(), "__construct", &_0, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Get registered engines.
 */
PHP_METHOD(Ice_Mvc_View, getEngines)
{
	zval _9$$7, _11$$9, _18$$13, _20$$15;
	zend_string *_7$$4;
	zend_ulong _6$$4;
	zval ext, engine, _0, _1$$3, _2$$3, _3$$4, *_4$$4, _5$$4, _8$$7, _10$$9, _12$$10, _13$$10, _14$$10, _17$$13, _19$$15, _21$$16, _22$$16, _23$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_20$$15);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("engines"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, ice_mvc_view_engine_php_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 183, this_ptr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, ".phtml");
		zephir_update_property_array(this_ptr, SL("engines"), &_2$$3, &_1$$3);
	} else {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("engines"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_3$$4, 0, "ice/mvc/view.zep", 66);
		if (Z_TYPE_P(&_3$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3$$4), _6$$4, _7$$4, _4$$4)
			{
				ZEPHIR_INIT_NVAR(&ext);
				if (_7$$4 != NULL) { 
					ZVAL_STR_COPY(&ext, _7$$4);
				} else {
					ZVAL_LONG(&ext, _6$$4);
				}
				ZEPHIR_INIT_NVAR(&engine);
				ZVAL_COPY(&engine, _4$$4);
				if (Z_TYPE_P(&engine) == IS_OBJECT) {
					if (zephir_is_instance_of(&engine, SL("Closure"))) {
						ZEPHIR_INIT_NVAR(&_8$$7);
						ZEPHIR_INIT_NVAR(&_9$$7);
						zephir_create_array(&_9$$7, 1, 0);
						zephir_array_fast_append(&_9$$7, this_ptr);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_8$$7, &engine, &_9$$7);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("engines"), &ext, &_8$$7);
					}
				} else {
					if (Z_TYPE_P(&engine) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_10$$9);
						ZEPHIR_INIT_NVAR(&_11$$9);
						zephir_create_array(&_11$$9, 1, 0);
						zephir_array_fast_append(&_11$$9, this_ptr);
						ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_10$$9, &engine, &_11$$9);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("engines"), &ext, &_10$$9);
					} else {
						ZEPHIR_INIT_NVAR(&_12$$10);
						object_init_ex(&_12$$10, ice_exception_ce);
						ZEPHIR_INIT_NVAR(&_13$$10);
						ZVAL_STRING(&_13$$10, "Invalid template engine registration for '%s' extension");
						ZEPHIR_CALL_FUNCTION(&_14$$10, "sprintf", &_15, 11, &_13$$10, &ext);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &_12$$10, "__construct", &_16, 12, &_14$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$10, "ice/mvc/view.zep", 62);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$4, &_3$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&ext, &_3$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&engine, &_3$$4, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&engine) == IS_OBJECT) {
						if (zephir_is_instance_of(&engine, SL("Closure"))) {
							ZEPHIR_INIT_NVAR(&_17$$13);
							ZEPHIR_INIT_NVAR(&_18$$13);
							zephir_create_array(&_18$$13, 1, 0);
							zephir_array_fast_append(&_18$$13, this_ptr);
							ZEPHIR_CALL_USER_FUNC_ARRAY(&_17$$13, &engine, &_18$$13);
							zephir_check_call_status();
							zephir_update_property_array(this_ptr, SL("engines"), &ext, &_17$$13);
						}
					} else {
						if (Z_TYPE_P(&engine) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_19$$15);
							ZEPHIR_INIT_NVAR(&_20$$15);
							zephir_create_array(&_20$$15, 1, 0);
							zephir_array_fast_append(&_20$$15, this_ptr);
							ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_19$$15, &engine, &_20$$15);
							zephir_check_call_status();
							zephir_update_property_array(this_ptr, SL("engines"), &ext, &_19$$15);
						} else {
							ZEPHIR_INIT_NVAR(&_21$$16);
							object_init_ex(&_21$$16, ice_exception_ce);
							ZEPHIR_INIT_NVAR(&_22$$16);
							ZVAL_STRING(&_22$$16, "Invalid template engine registration for '%s' extension");
							ZEPHIR_CALL_FUNCTION(&_23$$16, "sprintf", &_15, 11, &_22$$16, &ext);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &_21$$16, "__construct", &_16, 12, &_23$$16);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_21$$16, "ice/mvc/view.zep", 62);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &_3$$4, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&engine);
		ZEPHIR_INIT_NVAR(&ext);
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
PHP_METHOD(Ice_Mvc_View, render)
{
	zend_string *_20$$13;
	zend_ulong _19$$13;
	zend_bool exists = 0, _37;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL, *_13 = NULL, *_16 = NULL, *_25 = NULL, *_28 = NULL, *_33 = NULL, *_36 = NULL, *_41 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file = NULL, file_sub, *data_param = NULL, __$null, ext, engine, engines, path, dir, dirs, content, _0, _1, _4, _5, _2$$6, _3$$6, _6$$7, *_7$$8, _8$$8, _9$$9, _11$$10, _14$$11, _15$$12, *_17$$13, _18$$13, *_21$$14, _22$$14, _23$$15, _24$$16, _26$$17, _27$$18, *_29$$20, _30$$20, _31$$21, _32$$22, _34$$23, _35$$24, _38$$26, _39$$26, _40$$26;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&dirs);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$21);
	ZVAL_UNDEF(&_32$$22);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_39$$26);
	ZVAL_UNDEF(&_40$$26);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(file)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		zephir_update_property_zval(this_ptr, ZEND_STRL("file"), file);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "You must set the file to use within your view before rendering", "ice/mvc/view.zep", 89);
		return;
	}
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "getengines", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("viewsDir"), PH_NOISY_CC);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&dirs);
		zephir_read_property(&dirs, this_ptr, ZEND_STRL("viewsDir"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_VAR(&_2$$6);
		zephir_create_array(&_2$$6, 1, 0);
		ZEPHIR_OBS_VAR(&_3$$6);
		zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("viewsDir"), PH_NOISY_CC);
		zephir_array_fast_append(&_2$$6, &_3$$6);
		ZEPHIR_CPY_WRT(&dirs, &_2$$6);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", NULL, 55, &_4, &_5);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&ext))) {
		ZEPHIR_OBS_VAR(&engine);
		ZEPHIR_INIT_VAR(&_6$$7);
		ZEPHIR_CONCAT_SV(&_6$$7, ".", &ext);
		if (zephir_array_isset_fetch(&engine, &engines, &_6$$7, 0)) {
			zephir_is_iterable(&dirs, 0, "ice/mvc/view.zep", 113);
			if (Z_TYPE_P(&dirs) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&dirs), _7$$8)
				{
					ZEPHIR_INIT_NVAR(&dir);
					ZVAL_COPY(&dir, _7$$8);
					zephir_read_property(&_9$$9, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&path);
					ZEPHIR_CONCAT_VV(&path, &dir, &_9$$9);
					if ((zephir_file_exists(&path) == SUCCESS)) {
						exists = 1;
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_10, 0, &data);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_11$$10, this_ptr, "all", &_12, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&content, &engine, "render", &_13, 0, &path, &_11$$10);
						zephir_check_call_status();
						break;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &dirs, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_8$$8, &dirs, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_8$$8)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&dir, &dirs, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property(&_14$$11, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&path);
						ZEPHIR_CONCAT_VV(&path, &dir, &_14$$11);
						if ((zephir_file_exists(&path) == SUCCESS)) {
							exists = 1;
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_10, 0, &data);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_15$$12, this_ptr, "all", &_12, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&content, &engine, "render", &_16, 0, &path, &_15$$12);
							zephir_check_call_status();
							break;
						}
					ZEPHIR_CALL_METHOD(NULL, &dirs, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&dir);
		}
	} else {
		zephir_is_iterable(&engines, 0, "ice/mvc/view.zep", 130);
		if (Z_TYPE_P(&engines) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _19$$13, _20$$13, _17$$13)
			{
				ZEPHIR_INIT_NVAR(&ext);
				if (_20$$13 != NULL) { 
					ZVAL_STR_COPY(&ext, _20$$13);
				} else {
					ZVAL_LONG(&ext, _19$$13);
				}
				ZEPHIR_INIT_NVAR(&engine);
				ZVAL_COPY(&engine, _17$$13);
				zephir_is_iterable(&dirs, 0, "ice/mvc/view.zep", 126);
				if (Z_TYPE_P(&dirs) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&dirs), _21$$14)
					{
						ZEPHIR_INIT_NVAR(&dir);
						ZVAL_COPY(&dir, _21$$14);
						zephir_read_property(&_23$$15, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&path);
						ZEPHIR_CONCAT_VVV(&path, &dir, &_23$$15, &ext);
						if ((zephir_file_exists(&path) == SUCCESS)) {
							exists = 1;
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_10, 0, &data);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_24$$16, this_ptr, "all", &_12, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&content, &engine, "render", &_25, 0, &path, &_24$$16);
							zephir_check_call_status();
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &dirs, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_22$$14, &dirs, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_22$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&dir, &dirs, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property(&_26$$17, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_NVAR(&path);
							ZEPHIR_CONCAT_VVV(&path, &dir, &_26$$17, &ext);
							if ((zephir_file_exists(&path) == SUCCESS)) {
								exists = 1;
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_10, 0, &data);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_27$$18, this_ptr, "all", &_12, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&content, &engine, "render", &_28, 0, &path, &_27$$18);
								zephir_check_call_status();
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &dirs, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&dir);
				if (exists) {
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &engines, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_18$$13, &engines, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_18$$13)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&ext, &engines, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&engine, &engines, "current", NULL, 0);
				zephir_check_call_status();
					zephir_is_iterable(&dirs, 0, "ice/mvc/view.zep", 126);
					if (Z_TYPE_P(&dirs) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&dirs), _29$$20)
						{
							ZEPHIR_INIT_NVAR(&dir);
							ZVAL_COPY(&dir, _29$$20);
							zephir_read_property(&_31$$21, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_NVAR(&path);
							ZEPHIR_CONCAT_VVV(&path, &dir, &_31$$21, &ext);
							if ((zephir_file_exists(&path) == SUCCESS)) {
								exists = 1;
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_10, 0, &data);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_32$$22, this_ptr, "all", &_12, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&content, &engine, "render", &_33, 0, &path, &_32$$22);
								zephir_check_call_status();
								break;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &dirs, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_30$$20, &dirs, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_30$$20)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&dir, &dirs, "current", NULL, 0);
							zephir_check_call_status();
								zephir_read_property(&_34$$23, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_INIT_NVAR(&path);
								ZEPHIR_CONCAT_VVV(&path, &dir, &_34$$23, &ext);
								if ((zephir_file_exists(&path) == SUCCESS)) {
									exists = 1;
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_10, 0, &data);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_35$$24, this_ptr, "all", &_12, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&content, &engine, "render", &_36, 0, &path, &_35$$24);
									zephir_check_call_status();
									break;
								}
							ZEPHIR_CALL_METHOD(NULL, &dirs, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&dir);
					if (exists) {
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, &engines, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&engine);
		ZEPHIR_INIT_NVAR(&ext);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("silent"), PH_NOISY_CC | PH_READONLY);
	_37 = !zephir_is_true(&_5);
	if (_37) {
		_37 = !exists;
	}
	if (_37) {
		ZEPHIR_INIT_VAR(&_38$$26);
		object_init_ex(&_38$$26, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_39$$26);
		ZVAL_STRING(&_39$$26, "The requested view %s could not be found");
		ZEPHIR_CALL_FUNCTION(&_40$$26, "sprintf", NULL, 11, &_39$$26, &path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_38$$26, "__construct", &_41, 12, &_40$$26);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_38$$26, "ice/mvc/view.zep", 133);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&content);
}

/**
 * Load the view.
 *
 * @param string file Name of file without extension from the views dir
 * @param array data Vars to send
 * @return string
 */
PHP_METHOD(Ice_Mvc_View, load)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file_param = NULL, *data_param = NULL;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &data_param);
	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
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
PHP_METHOD(Ice_Mvc_View, partial)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file_param = NULL, *data_param = NULL, _0, _1;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &data_param);
	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("partialsDir"), PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Ice_Mvc_View, layout)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file = NULL, file_sub, *data_param = NULL, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(file)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		zephir_read_property(file, this_ptr, ZEND_STRL("mainView"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("layoutsDir"), PH_NOISY_CC | PH_READONLY);
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
 * @return object View
 */
PHP_METHOD(Ice_Mvc_View, setVar)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &name, value);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Set multiple vars to the view.
 *
 * @param array vars
 * @return object View
 */
PHP_METHOD(Ice_Mvc_View, setVars)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *vars_param = NULL;
	zval vars;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&vars);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(vars)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vars_param);
	ZEPHIR_OBS_COPY_OR_DUP(&vars, vars_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", NULL, 0, &vars);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Alias of the `setMainView` method.
 *
 * @param array vars
 * @return object View
 */
PHP_METHOD(Ice_Mvc_View, setLayout)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *layout_param = NULL;
	zval layout;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&layout);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(layout)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layout_param);
	zephir_get_strval(&layout, layout_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmainview", NULL, 0, &layout);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Magic toStrint, get the rendered view.
 */
PHP_METHOD(Ice_Mvc_View, __toString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

