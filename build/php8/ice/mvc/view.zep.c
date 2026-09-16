
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
#include "kernel/string.h"
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
 * @copyright   (c) Ice Team
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("engines", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(engines)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &engines);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 243, engines);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, setContent)
{
	zval *content, content_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("content", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(content)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &content);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 244, content);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getContent)
{

	RETURN_MEMBER(getThis(), "content");
}

PHP_METHOD(Ice_Mvc_View, setMainView)
{
	zval *mainView, mainView_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mainView_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("mainView", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(mainView)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &mainView);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 245, mainView);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getMainView)
{

	RETURN_MEMBER(getThis(), "mainView");
}

PHP_METHOD(Ice_Mvc_View, setLayoutsDir)
{
	zval *layoutsDir, layoutsDir_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&layoutsDir_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("layoutsDir", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(layoutsDir)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &layoutsDir);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 246, layoutsDir);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getLayoutsDir)
{

	RETURN_MEMBER(getThis(), "layoutsDir");
}

PHP_METHOD(Ice_Mvc_View, setPartialsDir)
{
	zval *partialsDir, partialsDir_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialsDir_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("partialsDir", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(partialsDir)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &partialsDir);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 247, partialsDir);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getPartialsDir)
{

	RETURN_MEMBER(getThis(), "partialsDir");
}

PHP_METHOD(Ice_Mvc_View, setViewsDir)
{
	zval *viewsDir, viewsDir_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewsDir_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewsDir", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(viewsDir)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &viewsDir);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 248, viewsDir);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getViewsDir)
{

	RETURN_MEMBER(getThis(), "viewsDir");
}

PHP_METHOD(Ice_Mvc_View, setFile)
{
	zval *file, file_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("file", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(file)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &file);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 249, file);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_View, getFile)
{

	RETURN_MEMBER(getThis(), "file");
}

PHP_METHOD(Ice_Mvc_View, setSilent)
{
	zval *silent, silent_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&silent_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("silent", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(silent)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &silent);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 250, silent);
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
	zval data;
	zval *file = NULL, file_sub, *data_param = NULL, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("file", 4, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(file)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 249, file);
	}
	ZEPHIR_CALL_PARENT(NULL, ice_mvc_view_ce, getThis(), "__construct", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Get registered engines.
 */
PHP_METHOD(Ice_Mvc_View, getEngines)
{
	zval _10$$7, _12$$9, _21$$13, _23$$15;
	zend_bool _19$$4;
	zend_string *_8$$4;
	zend_ulong _7$$4;
	zval ext, engine, _0, _1$$3, _2$$3, _3$$4, *_4$$4, _5$$4, *_6$$4, _18$$4, _9$$7, _11$$9, _13$$10, _14$$10, _15$$10, _20$$13, _22$$15, _24$$16, _25$$16, _26$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_23$$15);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("engines", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 243, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, ice_mvc_view_engine_php_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 184, this_ptr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, ".phtml");
		zephir_update_property_array(this_ptr, SL("engines"), &_2$$3, &_1$$3);
	} else {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 243, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_3$$4) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$4);
			zephir_string_to_char_array(&_5$$4, &_3$$4);
			_4$$4 = &_5$$4;
		} else {
			_4$$4 = &_3$$4;
		}
		zephir_is_iterable(_4$$4, 0, "ice/mvc/view.zep", 66);
		if (Z_TYPE_P(_4$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4$$4), _7$$4, _8$$4, _6$$4)
			{
				ZEPHIR_INIT_NVAR(&ext);
				if (_8$$4 != NULL) { 
					ZVAL_STR_COPY(&ext, _8$$4);
				} else {
					ZVAL_LONG(&ext, _7$$4);
				}
				ZEPHIR_INIT_NVAR(&engine);
				ZVAL_COPY(&engine, _6$$4);
				if (Z_TYPE_P(&engine) == IS_OBJECT) {
					if (zephir_is_instance_of(&engine, SL("Closure"))) {
						ZEPHIR_INIT_NVAR(&_9$$7);
						ZEPHIR_INIT_NVAR(&_10$$7);
						zephir_create_array(&_10$$7, 1, 0);
						zephir_array_fast_append(&_10$$7, this_ptr);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_9$$7, &engine, &_10$$7);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("engines"), &ext, &_9$$7);
					}
				} else {
					if (Z_TYPE_P(&engine) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_11$$9);
						ZEPHIR_INIT_NVAR(&_12$$9);
						zephir_create_array(&_12$$9, 1, 0);
						zephir_array_fast_append(&_12$$9, this_ptr);
						ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_11$$9, &engine, &_12$$9);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("engines"), &ext, &_11$$9);
					} else {
						ZEPHIR_INIT_NVAR(&_13$$10);
						object_init_ex(&_13$$10, ice_exception_ce);
						ZEPHIR_INIT_NVAR(&_14$$10);
						ZVAL_STRING(&_14$$10, "Invalid template engine registration for '%s' extension");
						ZEPHIR_CALL_FUNCTION(&_15$$10, "sprintf", &_16, 12, &_14$$10, &ext);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &_13$$10, "__construct", &_17, 13, &_15$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_13$$10, "ice/mvc/view.zep", 62);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_19$$4 = 1;
			while (1) {
				if (_19$$4) {
					_19$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _4$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_18$$4, _4$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_18$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&ext, _4$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&engine, _4$$4, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&engine) == IS_OBJECT) {
						if (zephir_is_instance_of(&engine, SL("Closure"))) {
							ZEPHIR_INIT_NVAR(&_20$$13);
							ZEPHIR_INIT_NVAR(&_21$$13);
							zephir_create_array(&_21$$13, 1, 0);
							zephir_array_fast_append(&_21$$13, this_ptr);
							ZEPHIR_CALL_USER_FUNC_ARRAY(&_20$$13, &engine, &_21$$13);
							zephir_check_call_status();
							zephir_update_property_array(this_ptr, SL("engines"), &ext, &_20$$13);
						}
					} else {
						if (Z_TYPE_P(&engine) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_22$$15);
							ZEPHIR_INIT_NVAR(&_23$$15);
							zephir_create_array(&_23$$15, 1, 0);
							zephir_array_fast_append(&_23$$15, this_ptr);
							ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_22$$15, &engine, &_23$$15);
							zephir_check_call_status();
							zephir_update_property_array(this_ptr, SL("engines"), &ext, &_22$$15);
						} else {
							ZEPHIR_INIT_NVAR(&_24$$16);
							object_init_ex(&_24$$16, ice_exception_ce);
							ZEPHIR_INIT_NVAR(&_25$$16);
							ZVAL_STRING(&_25$$16, "Invalid template engine registration for '%s' extension");
							ZEPHIR_CALL_FUNCTION(&_26$$16, "sprintf", &_16, 12, &_25$$16, &ext);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &_24$$16, "__construct", &_17, 13, &_26$$16);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_24$$16, "ice/mvc/view.zep", 62);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
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
	zend_string *_24$$13;
	zend_ulong _23$$13;
	zend_bool exists = 0, _49, _16$$8, _37$$13, _32$$14, _45$$20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_13 = NULL, *_14 = NULL, *_19 = NULL, *_30 = NULL, *_35 = NULL, *_43 = NULL, *_48 = NULL, *_53 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file = NULL, file_sub, *data_param = NULL, __$null, ext, engine, engines, path, dir, dirs, content, _0, _1, _4, _5, _2$$6, _3$$6, _6$$7, *_7$$8, _8$$8, *_9$$8, _15$$8, _10$$9, _12$$10, _17$$11, _18$$12, *_20$$13, _21$$13, *_22$$13, _36$$13, *_25$$14, _26$$14, *_27$$14, _31$$14, _28$$15, _29$$16, _33$$17, _34$$18, *_38$$20, _39$$20, *_40$$20, _44$$20, _41$$21, _42$$22, _46$$23, _47$$24, _50$$26, _51$$26, _52$$26;
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
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_33$$17);
	ZVAL_UNDEF(&_34$$18);
	ZVAL_UNDEF(&_39$$20);
	ZVAL_UNDEF(&_44$$20);
	ZVAL_UNDEF(&_41$$21);
	ZVAL_UNDEF(&_42$$22);
	ZVAL_UNDEF(&_46$$23);
	ZVAL_UNDEF(&_47$$24);
	ZVAL_UNDEF(&_50$$26);
	ZVAL_UNDEF(&_51$$26);
	ZVAL_UNDEF(&_52$$26);
	ZVAL_UNDEF(&data);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("file", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("viewsDir", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("silent", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(file)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_INIT_VAR(&path);
	ZVAL_NULL(&path);
	exists = 0;
	ZEPHIR_INIT_VAR(&content);
	ZVAL_NULL(&content);
	if (Z_TYPE_P(file) != IS_NULL) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 249, file);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 249, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "You must set the file to use within your view before rendering", "ice/mvc/view.zep", 89);
		return;
	}
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "getengines", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 248, PH_NOISY_CC);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		zephir_memory_observe(&dirs);
		zephir_read_property_cached(&dirs, this_ptr, _zephir_prop_1, 248, PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_VAR(&_2$$6);
		zephir_create_array(&_2$$6, 1, 0);
		zephir_memory_observe(&_3$$6);
		zephir_read_property_cached(&_3$$6, this_ptr, _zephir_prop_1, 248, PH_NOISY_CC);
		zephir_array_fast_append(&_2$$6, &_3$$6);
		ZEPHIR_CPY_WRT(&dirs, &_2$$6);
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 249, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", NULL, 57, &_4, &_5);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&ext))) {
		zephir_memory_observe(&engine);
		ZEPHIR_INIT_VAR(&_6$$7);
		ZEPHIR_CONCAT_SV(&_6$$7, ".", &ext);
		if (zephir_array_isset_fetch(&engine, &engines, &_6$$7, 0)) {
			if (Z_TYPE_P(&dirs) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_8$$8);
				zephir_string_to_char_array(&_8$$8, &dirs);
				_7$$8 = &_8$$8;
			} else {
				_7$$8 = &dirs;
			}
			zephir_is_iterable(_7$$8, 0, "ice/mvc/view.zep", 113);
			if (Z_TYPE_P(_7$$8) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_7$$8), _9$$8)
				{
					ZEPHIR_INIT_NVAR(&dir);
					ZVAL_COPY(&dir, _9$$8);
					zephir_read_property_cached(&_10$$9, this_ptr, _zephir_prop_0, 249, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&path);
					ZEPHIR_CONCAT_VV(&path, &dir, &_10$$9);
					if ((zephir_file_exists(&path) == SUCCESS)) {
						exists = 1;
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_11, 0, &data);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_12$$10, this_ptr, "all", &_13, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&content, &engine, "render", &_14, 0, &path, &_12$$10);
						zephir_check_call_status();
						break;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _7$$8, "rewind", NULL, 0);
				zephir_check_call_status();
				_16$$8 = 1;
				while (1) {
					if (_16$$8) {
						_16$$8 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _7$$8, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_15$$8, _7$$8, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_15$$8)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&dir, _7$$8, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property_cached(&_17$$11, this_ptr, _zephir_prop_0, 249, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&path);
						ZEPHIR_CONCAT_VV(&path, &dir, &_17$$11);
						if ((zephir_file_exists(&path) == SUCCESS)) {
							exists = 1;
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_11, 0, &data);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_18$$12, this_ptr, "all", &_13, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&content, &engine, "render", &_19, 0, &path, &_18$$12);
							zephir_check_call_status();
							break;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&dir);
		}
	} else {
		if (Z_TYPE_P(&engines) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_21$$13);
			zephir_string_to_char_array(&_21$$13, &engines);
			_20$$13 = &_21$$13;
		} else {
			_20$$13 = &engines;
		}
		zephir_is_iterable(_20$$13, 0, "ice/mvc/view.zep", 130);
		if (Z_TYPE_P(_20$$13) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_20$$13), _23$$13, _24$$13, _22$$13)
			{
				ZEPHIR_INIT_NVAR(&ext);
				if (_24$$13 != NULL) { 
					ZVAL_STR_COPY(&ext, _24$$13);
				} else {
					ZVAL_LONG(&ext, _23$$13);
				}
				ZEPHIR_INIT_NVAR(&engine);
				ZVAL_COPY(&engine, _22$$13);
				if (Z_TYPE_P(&dirs) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_26$$14);
					zephir_string_to_char_array(&_26$$14, &dirs);
					_25$$14 = &_26$$14;
				} else {
					_25$$14 = &dirs;
				}
				zephir_is_iterable(_25$$14, 0, "ice/mvc/view.zep", 126);
				if (Z_TYPE_P(_25$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_25$$14), _27$$14)
					{
						ZEPHIR_INIT_NVAR(&dir);
						ZVAL_COPY(&dir, _27$$14);
						zephir_read_property_cached(&_28$$15, this_ptr, _zephir_prop_0, 249, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&path);
						ZEPHIR_CONCAT_VVV(&path, &dir, &_28$$15, &ext);
						if ((zephir_file_exists(&path) == SUCCESS)) {
							exists = 1;
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_11, 0, &data);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_29$$16, this_ptr, "all", &_13, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&content, &engine, "render", &_30, 0, &path, &_29$$16);
							zephir_check_call_status();
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _25$$14, "rewind", NULL, 0);
					zephir_check_call_status();
					_32$$14 = 1;
					while (1) {
						if (_32$$14) {
							_32$$14 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _25$$14, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_31$$14, _25$$14, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_31$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&dir, _25$$14, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property_cached(&_33$$17, this_ptr, _zephir_prop_0, 249, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_NVAR(&path);
							ZEPHIR_CONCAT_VVV(&path, &dir, &_33$$17, &ext);
							if ((zephir_file_exists(&path) == SUCCESS)) {
								exists = 1;
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_11, 0, &data);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_34$$18, this_ptr, "all", &_13, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&content, &engine, "render", &_35, 0, &path, &_34$$18);
								zephir_check_call_status();
								break;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&dir);
				if (exists) {
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _20$$13, "rewind", NULL, 0);
			zephir_check_call_status();
			_37$$13 = 1;
			while (1) {
				if (_37$$13) {
					_37$$13 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _20$$13, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_36$$13, _20$$13, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_36$$13)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&ext, _20$$13, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&engine, _20$$13, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&dirs) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_39$$20);
						zephir_string_to_char_array(&_39$$20, &dirs);
						_38$$20 = &_39$$20;
					} else {
						_38$$20 = &dirs;
					}
					zephir_is_iterable(_38$$20, 0, "ice/mvc/view.zep", 126);
					if (Z_TYPE_P(_38$$20) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_38$$20), _40$$20)
						{
							ZEPHIR_INIT_NVAR(&dir);
							ZVAL_COPY(&dir, _40$$20);
							zephir_read_property_cached(&_41$$21, this_ptr, _zephir_prop_0, 249, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_NVAR(&path);
							ZEPHIR_CONCAT_VVV(&path, &dir, &_41$$21, &ext);
							if ((zephir_file_exists(&path) == SUCCESS)) {
								exists = 1;
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_11, 0, &data);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_42$$22, this_ptr, "all", &_13, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&content, &engine, "render", &_43, 0, &path, &_42$$22);
								zephir_check_call_status();
								break;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _38$$20, "rewind", NULL, 0);
						zephir_check_call_status();
						_45$$20 = 1;
						while (1) {
							if (_45$$20) {
								_45$$20 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _38$$20, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_44$$20, _38$$20, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_44$$20)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&dir, _38$$20, "current", NULL, 0);
							zephir_check_call_status();
								zephir_read_property_cached(&_46$$23, this_ptr, _zephir_prop_0, 249, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_INIT_NVAR(&path);
								ZEPHIR_CONCAT_VVV(&path, &dir, &_46$$23, &ext);
								if ((zephir_file_exists(&path) == SUCCESS)) {
									exists = 1;
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_11, 0, &data);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_47$$24, this_ptr, "all", &_13, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&content, &engine, "render", &_48, 0, &path, &_47$$24);
									zephir_check_call_status();
									break;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&dir);
					if (exists) {
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&engine);
		ZEPHIR_INIT_NVAR(&ext);
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_2, 250, PH_NOISY_CC | PH_READONLY);
	_49 = !zephir_is_true(&_5);
	if (_49) {
		_49 = !exists;
	}
	if (_49) {
		ZEPHIR_INIT_VAR(&_50$$26);
		object_init_ex(&_50$$26, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_51$$26);
		ZVAL_STRING(&_51$$26, "The requested view %s could not be found");
		ZEPHIR_CALL_FUNCTION(&_52$$26, "sprintf", NULL, 12, &_51$$26, &path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_50$$26, "__construct", &_53, 13, &_52$$26);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_50$$26, "ice/mvc/view.zep", 133);
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
	zval file_zv, *data_param = NULL;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&data);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		data_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, &file_zv, &data);
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
	zval file_zv, *data_param = NULL, _0, _1;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("partialsDir", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		data_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 247, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, &file_zv);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("mainView", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("layoutsDir", 10, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(file)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		zephir_read_property_cached(file, this_ptr, _zephir_prop_0, 245, PH_NOISY_CC);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 246, PH_NOISY_CC | PH_READONLY);
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
	zval name_zv, *value, value_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &name_zv, value);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(vars, vars_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zval layout_zv;
	zend_string *layout = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&layout_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(layout)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&layout_zv);
	ZVAL_STR_COPY(&layout_zv, layout);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmainview", NULL, 0, &layout_zv);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

