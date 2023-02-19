
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/require.h"


/**
 * PSR-4 autoloader class.
 *
 * @package     Ice/Loader
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2023 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Loader)
{
	ZEPHIR_REGISTER_CLASS(Ice, Loader, ice, loader, ice_loader_method_entry, 0);

	zend_declare_property_null(ice_loader_ce, SL("prefixes"), ZEND_ACC_PROTECTED);
	ice_loader_ce->create_object = zephir_init_properties_Ice_Loader;

	return SUCCESS;
}

/**
 * Loader constructor.
 *
 * @param array prefixes
 */
PHP_METHOD(Ice_Loader, __construct)
{
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefixes_param = NULL, prefix$$3, dir$$3, *_0$$3, _1$$3;
	zval prefixes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefixes);
	ZVAL_UNDEF(&prefix$$3);
	ZVAL_UNDEF(&dir$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(prefixes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefixes_param);
	if (!prefixes_param) {
		ZEPHIR_INIT_VAR(&prefixes);
		array_init(&prefixes);
	} else {
		zephir_get_arrval(&prefixes, prefixes_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&prefixes))) {
		zephir_is_iterable(&prefixes, 0, "ice/loader.zep", 31);
		if (Z_TYPE_P(&prefixes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&prefixes), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&prefix$$3);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&prefix$$3, _3$$3);
				} else {
					ZVAL_LONG(&prefix$$3, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&dir$$3);
				ZVAL_COPY(&dir$$3, _0$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addnamespace", &_4, 0, &prefix$$3, &dir$$3);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &prefixes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &prefixes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&prefix$$3, &prefixes, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&dir$$3, &prefixes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addnamespace", &_4, 0, &prefix$$3, &dir$$3);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &prefixes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&dir$$3);
		ZEPHIR_INIT_NVAR(&prefix$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "register", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Register loader with SPL autoloader stack.
 *
 * @return void
 */
PHP_METHOD(Ice_Loader, register)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "loadClass");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 172, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a base directory for a namespace prefix.
 *
 * @param string prefix The namespace prefix
 * @param string baseDir A base directory for class files in the namespace
 * @param bool prepend If true, prepend the base directory to the stack instead of appending it; this causes it to
 * be searched first rather than last
 * @return Loader
 */
PHP_METHOD(Ice_Loader, addNamespace)
{
	zval _10$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool prepend;
	zval *prefix_param = NULL, *baseDir_param = NULL, *prepend_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _11$$4, _12$$4, _13$$5, _14$$5;
	zval prefix, baseDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&baseDir);
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
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_10$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(prefix)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(baseDir)
		Z_PARAM_BOOL(prepend)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &prefix_param, &baseDir_param, &prepend_param);
	zephir_get_strval(&prefix, prefix_param);
	if (!baseDir_param) {
		ZEPHIR_INIT_VAR(&baseDir);
	} else {
		zephir_get_strval(&baseDir, baseDir_param);
	}
	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\");
	zephir_fast_trim(&_0, &prefix, &_1, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_0, "\\");
	zephir_get_strval(&prefix, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/");
	zephir_fast_trim(&_3, &baseDir, &_4, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VS(&_5, &_3, "/");
	zephir_get_strval(&baseDir, &_5);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "/");
	zephir_fast_trim(&_6, &baseDir, &_7, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_VS(&_8, &_6, "/");
	zephir_get_strval(&baseDir, &_8);
	zephir_read_property(&_9, this_ptr, ZEND_STRL("prefixes"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_9, &prefix))) {
		ZEPHIR_INIT_VAR(&_10$$3);
		zephir_create_array(&_10$$3, 1, 0);
		zephir_array_fast_append(&_10$$3, &baseDir);
		zephir_update_property_array(this_ptr, SL("prefixes"), &prefix, &_10$$3);
		RETURN_THIS();
	}
	if (prepend) {
		zephir_read_property(&_11$$4, this_ptr, ZEND_STRL("prefixes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_12$$4, &_11$$4, &prefix, PH_NOISY | PH_READONLY, "ice/loader.zep", 72);
		ZEPHIR_MAKE_REF(&_12$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 81, &_12$$4, &baseDir);
		ZEPHIR_UNREF(&_12$$4);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_13$$5, this_ptr, ZEND_STRL("prefixes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_14$$5, &_13$$5, &prefix, PH_NOISY | PH_READONLY, "ice/loader.zep", 74);
		ZEPHIR_MAKE_REF(&_14$$5);
		ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 173, &_14$$5, &baseDir);
		ZEPHIR_UNREF(&_14$$5);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

/**
 * Loads the class file for a given class name.
 *
 * @param string className The fully-qualified class name
 * @return mixed The mapped file name on success, or boolean false on failure
 */
PHP_METHOD(Ice_Loader, loadClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	zval *className_param = NULL, prefix, pos, relativeClass, mappedFile, _0, _2$$3, _4$$6, _5$$6, _6$$6, _7$$6, _8$$6;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&relativeClass);
	ZVAL_UNDEF(&mappedFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);
	zephir_get_strval(&className, className_param);


	ZEPHIR_CPY_WRT(&prefix, &className);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_1, 174, &prefix, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\\");
		ZEPHIR_CALL_METHOD(&mappedFile, this_ptr, "loadmappedfile", &_3, 0, &_2$$3, &className);
		zephir_check_call_status();
		if (zephir_is_true(&mappedFile)) {
			RETURN_CCTOR(&mappedFile);
		}
	} else {
		do {
			ZVAL_LONG(&_4$$6, 0);
			ZVAL_LONG(&_5$$6, (zephir_get_numberval(&pos) + 1));
			ZEPHIR_INIT_NVAR(&prefix);
			zephir_substr(&prefix, &className, 0 , zephir_get_intval(&_5$$6), 0);
			ZVAL_LONG(&_6$$6, (zephir_get_numberval(&pos) + 1));
			ZEPHIR_INIT_NVAR(&relativeClass);
			zephir_substr(&relativeClass, &className, zephir_get_intval(&_6$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_METHOD(&mappedFile, this_ptr, "loadmappedfile", &_3, 0, &prefix, &relativeClass);
			zephir_check_call_status();
			if (zephir_is_true(&mappedFile)) {
				RETURN_CCTOR(&mappedFile);
			}
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "\\");
			zephir_fast_trim(&_7$$6, &prefix, &_8$$6, ZEPHIR_TRIM_RIGHT);
			ZEPHIR_CPY_WRT(&prefix, &_7$$6);
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZVAL_STRING(&_7$$6, "\\");
			ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_1, 174, &prefix, &_7$$6);
			zephir_check_call_status();
		} while (!ZEPHIR_IS_FALSE_IDENTICAL(&pos));
	}
	RETURN_MM_BOOL(0);
}

/**
 * Load the mapped file for a namespace prefix and relative class.
 *
 * @param string $prefix The namespace prefix
 * @param string $relative_class The relative class name
 * @return mixed Boolean false if no mapped file can be loaded, or the name of the mapped file that was loaded
 */
PHP_METHOD(Ice_Loader, loadMappedFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, *relativeClass_param = NULL, baseDir, file, _0, _1, _2, _3, _4, _5, _6, *_7, _8, _9$$4, _11$$6;
	zval prefix, relativeClass;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&relativeClass);
	ZVAL_UNDEF(&baseDir);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(prefix)
		Z_PARAM_STR(relativeClass)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &prefix_param, &relativeClass_param);
	zephir_get_strval(&prefix, prefix_param);
	zephir_get_strval(&relativeClass, relativeClass_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("prefixes"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &prefix))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/");
	zephir_fast_str_replace(&_1, &_2, &_3, &relativeClass);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &_1, ".php");
	zephir_get_strval(&relativeClass, &_4);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("prefixes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &prefix, PH_NOISY | PH_READONLY, "ice/loader.zep", 147);
	zephir_is_iterable(&_6, 0, "ice/loader.zep", 161);
	if (Z_TYPE_P(&_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_6), _7)
		{
			ZEPHIR_INIT_NVAR(&baseDir);
			ZVAL_COPY(&baseDir, _7);
			ZEPHIR_INIT_NVAR(&file);
			ZEPHIR_CONCAT_VV(&file, &baseDir, &relativeClass);
			ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "requirefile", &_10, 0, &file);
			zephir_check_call_status();
			if (zephir_is_true(&_9$$4)) {
				RETURN_CCTOR(&file);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_6, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &_6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&baseDir, &_6, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&file);
				ZEPHIR_CONCAT_VV(&file, &baseDir, &relativeClass);
				ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "requirefile", &_10, 0, &file);
				zephir_check_call_status();
				if (zephir_is_true(&_11$$6)) {
					RETURN_CCTOR(&file);
				}
			ZEPHIR_CALL_METHOD(NULL, &_6, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&baseDir);
	RETURN_MM_BOOL(0);
}

/**
 * If a file exists, require it from the file system.
 *
 * @param string $file The file to require
 * @return bool True if the file exists, false if not
 */
PHP_METHOD(Ice_Loader, requireFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *file_param = NULL;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);
	zephir_get_strval(&file, file_param);


	if ((zephir_file_exists(&file) == SUCCESS)) {
		if (zephir_require_zval(&file) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

zend_object *zephir_init_properties_Ice_Loader(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("prefixes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("prefixes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

