
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/require.h"


/**
 * Sleet template engine. Syntax is similar to Twig, Volt or Django.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_Sleet) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\View\\Engine, Sleet, ice, mvc_view_engine_sleet, ice_mvc_view_engine_ce, ice_mvc_view_engine_sleet_method_entry, 0);

	zend_declare_property_null(ice_mvc_view_engine_sleet_ce, SL("compiler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_View_Engine_Sleet, getCompiler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "compiler");

}

/**
 * Compile the .sleet file.
 *
 * @param string path Path to the file
 * @return string Path to the compiled file
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet, compile) {

	zephir_fcall_cache_entry *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, __$true, compileDir, compile, trim, dir, file, compiledPath, old, compiled, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10$$9, _11$$9, _12$$10, _13$$12, _16$$12, _14$$13;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&compileDir);
	ZVAL_UNDEF(&compile);
	ZVAL_UNDEF(&trim);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&compiledPath);
	ZVAL_UNDEF(&old);
	ZVAL_UNDEF(&compiled);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_14$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	ZEPHIR_OBS_VAR(&trim);
	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_string_fetch(&trim, &_0, SL("trimPath"), 0);
	ZEPHIR_OBS_VAR(&compileDir);
	zephir_read_property(&_1, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_string_fetch(&compileDir, &_1, SL("compileDir"), 0);
	ZEPHIR_OBS_VAR(&compile);
	zephir_read_property(&_2, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_string_fetch(&compile, &_2, SL("compile"), 0);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/");
	zephir_fast_trim(&_3, &compileDir, &_4, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CALL_FUNCTION(&_6, "dirname", NULL, 52, &path);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "realpath", NULL, 128, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "");
	zephir_fast_str_replace(&_5, &trim, &_8, &_7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&dir);
	ZEPHIR_CONCAT_VV(&dir, &_3, &_5);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, ".sleet");
	ZEPHIR_CALL_FUNCTION(&file, "basename", NULL, 53, &path, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&compiledPath);
	ZEPHIR_CONCAT_VSVS(&compiledPath, &dir, "/", &file, ".phtml");
	do {
		if (ZEPHIR_IS_LONG(&compile, 0)) {
			ZEPHIR_INIT_NVAR(&compile);
			ZVAL_BOOL(&compile, 0);
			break;
		}
		if (ZEPHIR_IS_LONG(&compile, 1)) {
			ZEPHIR_INIT_NVAR(&compile);
			ZVAL_BOOL(&compile, !((zephir_file_exists(&compiledPath TSRMLS_CC) == SUCCESS)));
			break;
		}
		if (ZEPHIR_IS_LONG(&compile, 2)) {
			if (!((zephir_file_exists(&compiledPath TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_NVAR(&compile);
				ZVAL_BOOL(&compile, 1);
			} else {
				ZEPHIR_CALL_FUNCTION(&compile, "md5_file", NULL, 54, &compiledPath);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_INIT_NVAR(&compile);
		ZVAL_BOOL(&compile, 1);
		break;
	} while(0);

	if (zephir_is_true(&compile)) {
		ZEPHIR_INIT_VAR(&_10$$9);
		object_init_ex(&_10$$9, ice_mvc_view_engine_sleet_compiler_ce);
		ZEPHIR_CALL_METHOD(NULL, &_10$$9, "__construct", NULL, 159, this_ptr);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("compiler"), &_10$$9);
		zephir_read_property(&_11$$9, this_ptr, SL("compiler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&compiled, &_11$$9, "compile", NULL, 0, &path);
		zephir_check_call_status();
		if (Z_TYPE_P(&compile) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_12$$10);
			zephir_md5(&_12$$10, &compiled);
			if (!ZEPHIR_IS_EQUAL(&compile, &_12$$10)) {
				ZEPHIR_INIT_NVAR(&compile);
				ZVAL_BOOL(&compile, 1);
			}
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(&compile)) {
			ZEPHIR_CALL_FUNCTION(&_13$$12, "is_dir", NULL, 55, &dir);
			zephir_check_call_status();
			if (!(zephir_is_true(&_13$$12))) {
				ZVAL_LONG(&_14$$13, 0);
				ZEPHIR_CALL_FUNCTION(&old, "umask", &_15, 56, &_14$$13);
				zephir_check_call_status();
				ZVAL_LONG(&_14$$13, 0777);
				ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 57, &dir, &_14$$13, &__$true);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "umask", &_15, 56, &old);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_VAR(&_16$$12);
			zephir_file_put_contents(&_16$$12, &compiledPath, &compiled TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_16$$12)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Directory can't be written", "ice/mvc/view/engine/sleet.zep", 80);
				return;
			}
		}
	}
	RETURN_CCTOR(&compiledPath);

}

/**
 * Render the Slet file. Compile first.
 *
 * @param string path
 * @param array data
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet, render) {

	zend_string *_3;
	zend_ulong _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *path_param = NULL, *data_param = NULL, key, value, _0, *_1, _4$$3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "compile", NULL, 0, &path);
	zephir_check_call_status();
	zephir_get_strval(&path, &_0);
	zephir_is_iterable(&data, 0, "ice/mvc/view/engine/sleet.zep", 105);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_CPY_WRT(&_4$$3, &value);
		if (zephir_set_symbol(&key, &_4$$3 TSRMLS_CC) == FAILURE) {
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 157);
	zephir_check_call_status();
	if (zephir_require_zval(&path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 158);
	zephir_check_call_status();
	RETURN_MM();

}

