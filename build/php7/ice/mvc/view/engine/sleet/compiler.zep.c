
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/operators.h"


/**
 * Sleet file compiler.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_Sleet_Compiler) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\View\\Engine\\Sleet, Compiler, ice, mvc_view_engine_sleet_compiler, ice_mvc_view_engine_sleet_compiler_method_entry, 0);

	zend_declare_property_null(ice_mvc_view_engine_sleet_compiler_ce, SL("view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_engine_sleet_compiler_ce, SL("content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_engine_sleet_compiler_ce, SL("parsed"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_engine_sleet_compiler_ce, SL("parser"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_long(ice_mvc_view_engine_sleet_compiler_ce, SL("NEVER"), 0);

	zephir_declare_class_constant_long(ice_mvc_view_engine_sleet_compiler_ce, SL("NOT_EXIST"), 1);

	zephir_declare_class_constant_long(ice_mvc_view_engine_sleet_compiler_ce, SL("IF_CHANGE"), 2);

	zephir_declare_class_constant_long(ice_mvc_view_engine_sleet_compiler_ce, SL("ALWAYS"), 3);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Compiler, getParser) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "parser");

}

/**
 * Sleet compiler constructor. Set the view and parser.
 *
 * @param mixed view
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Compiler, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *view = NULL, view_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &view);

	if (!view) {
		view = &view_sub;
		view = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("view"), view);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, ice_mvc_view_engine_sleet_parser_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 160);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("parser"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Compile the file.
 *
 * @param string path
 * @return string Parsed content
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Compiler, compile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, content, _0, _1;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZEPHIR_INIT_VAR(&content);
	zephir_file_get_contents(&content, &path TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("content"), &content);
	zephir_read_property(&_0, this_ptr, SL("parser"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "text", NULL, 0, &content);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("parsed"), &_1);
	RETURN_MM_MEMBER(getThis(), "parsed");

}

/**
 * Magic toString to get parsed content.
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Compiler, __toString) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "parsed");

}

