
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
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_Sleet) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\View\\Engine, Sleet, ice, mvc_view_engine_sleet, ice_mvc_view_engine_ce, ice_mvc_view_engine_sleet_method_entry, 0);

	zend_declare_property_null(ice_mvc_view_engine_sleet_ce, SL("_compiler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_View_Engine_Sleet, getCompiler) {


	RETURN_MEMBER(this_ptr, "_compiler");

}

/**
 * Compile the .sleet file.
 *
 * @param string path Path to the file
 * @return string Path to the compiled file
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet, compile) {

	zephir_fcall_cache_entry *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *compileDir, *compile = NULL, *trim, *dir, *file = NULL, *compiledPath, *old = NULL, *compiled = NULL, *_0, *_1, *_2, *_3, _4, *_5, *_6 = NULL, *_7 = NULL, _8, _9 = zval_used_for_init, *_10, *_11, *_12 = NULL, *_13 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	ZEPHIR_OBS_VAR(trim);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_array_isset_string_fetch(&trim, _0, SS("trimPath"), 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(compileDir);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_array_isset_string_fetch(&compileDir, _1, SS("compileDir"), 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(compile);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_array_isset_string_fetch(&compile, _2, SS("compile"), 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "/", 0);
	zephir_fast_trim(_3, compileDir, &_4, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CALL_FUNCTION(&_6, "dirname", NULL, 119, path);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "realpath", NULL, 60, _6);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "", 0);
	zephir_fast_str_replace(&_5, trim, &_8, _7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(dir);
	ZEPHIR_CONCAT_VV(dir, _3, _5);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, ".sleet", 0);
	ZEPHIR_CALL_FUNCTION(&file, "basename", NULL, 120, path, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(compiledPath);
	ZEPHIR_CONCAT_VSVS(compiledPath, dir, "/", file, ".phtml");
	do {
		if (ZEPHIR_IS_LONG(compile, 0)) {
			ZEPHIR_INIT_NVAR(compile);
			ZVAL_BOOL(compile, 0);
			break;
		}
		if (ZEPHIR_IS_LONG(compile, 1)) {
			ZEPHIR_INIT_NVAR(compile);
			ZVAL_BOOL(compile, !((zephir_file_exists(compiledPath TSRMLS_CC) == SUCCESS)));
			break;
		}
		if (ZEPHIR_IS_LONG(compile, 2)) {
			if (!((zephir_file_exists(compiledPath TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_NVAR(compile);
				ZVAL_BOOL(compile, 1);
			} else {
				ZEPHIR_CALL_FUNCTION(&compile, "md5_file", NULL, 121, compiledPath);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_INIT_NVAR(compile);
		ZVAL_BOOL(compile, 1);
		break;
	} while(0);

	if (zephir_is_true(compile)) {
		ZEPHIR_INIT_VAR(_10);
		object_init_ex(_10, ice_mvc_view_engine_sleet_compiler_ce);
		ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, 122, this_ptr);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_compiler"), _10 TSRMLS_CC);
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_compiler"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&compiled, _11, "compile", NULL, 0, path);
		zephir_check_call_status();
		if (Z_TYPE_P(compile) == IS_STRING) {
			ZEPHIR_INIT_VAR(_12);
			zephir_md5(_12, compiled);
			if (!ZEPHIR_IS_EQUAL(compile, _12)) {
				ZEPHIR_INIT_NVAR(compile);
				ZVAL_BOOL(compile, 1);
			}
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(compile)) {
			ZEPHIR_CALL_FUNCTION(&_13, "is_dir", NULL, 123, dir);
			zephir_check_call_status();
			if (!(zephir_is_true(_13))) {
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 0);
				ZEPHIR_CALL_FUNCTION(&old, "umask", &_14, 124, &_9);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 0777);
				ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 125, dir, &_9, ZEPHIR_GLOBAL(global_true));
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "umask", &_14, 124, old);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_12);
			zephir_file_put_contents(_12, compiledPath, compiled TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_12)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Directory can't be written", "ice/mvc/view/engine/sleet.zep", 80);
				return;
			}
		}
	}
	RETURN_CCTOR(compiledPath);

}

/**
 * Render the Slet file. Compile first.
 *
 * @param string path
 * @param array data
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet, render) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *path_param = NULL, *data_param = NULL, *_0 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &data_param);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "compile", NULL, 0, path);
	zephir_check_call_status();
	zephir_get_strval(path, _0);
	Z_SET_ISREF_P(data);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 116, data);
	Z_UNSET_ISREF_P(data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 117);
	zephir_check_call_status();
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 118);
	zephir_check_call_status();
	RETURN_MM();

}

