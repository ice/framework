
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/file.h"
#include "kernel/require.h"

ZEPHIR_INIT_CLASS(Ice_Loader) {

	ZEPHIR_REGISTER_CLASS(Ice, Loader, ice, loader, ice_loader_method_entry, 0);

	zend_declare_property_null(ice_loader_ce, SL("_prefixes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Register loader with SPL autoloader stack.
 * 
 * @return void
 */
PHP_METHOD(Ice_Loader, register) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "loadClass", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 96, _0);
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
PHP_METHOD(Ice_Loader, addNamespace) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_bool prepend;
	zval *prefix_param = NULL, *baseDir_param = NULL, *prepend_param = NULL, *_0, _1, *_2, *_3, _4, *_5, *_6, _7, *_8, *_9, *_10, *_11, *_12, *_13 = NULL;
	zval *prefix = NULL, *baseDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &prefix_param, &baseDir_param, &prepend_param);

	zephir_get_strval(prefix, prefix_param);
	zephir_get_strval(baseDir, baseDir_param);
	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	zephir_fast_trim(_0, prefix, &_1, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, "\\");
	zephir_get_strval(prefix, _2);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "/", 0);
	zephir_fast_trim(_3, baseDir, &_4, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, _3, "/");
	zephir_get_strval(baseDir, _5);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "/", 0);
	zephir_fast_trim(_6, baseDir, &_7, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VS(_8, _6, "/");
	zephir_get_strval(baseDir, _8);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_prefixes"), PH_NOISY_CC);
	if (!(zephir_array_isset(_9, prefix))) {
		ZEPHIR_INIT_VAR(_10);
		array_init(_10);
		zephir_update_property_array(this_ptr, SL("_prefixes"), prefix, _10 TSRMLS_CC);
	}
	if (prepend) {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_prefixes"), PH_NOISY_CC);
		zephir_array_fetch(&_12, _11, prefix, PH_NOISY | PH_READONLY, "ice/loader.zep", 53 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_13, "utf8_encode", &_14, 97, baseDir);
		zephir_check_call_status();
		Z_SET_ISREF_P(_12);
		ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 98, _12, _13);
		Z_UNSET_ISREF_P(_12);
		zephir_check_call_status();
	} else {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_prefixes"), PH_NOISY_CC);
		zephir_array_fetch(&_12, _11, prefix, PH_NOISY | PH_READONLY, "ice/loader.zep", 55 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_13, "utf8_encode", &_14, 97, baseDir);
		zephir_check_call_status();
		Z_SET_ISREF_P(_12);
		ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 99, _12, _13);
		Z_UNSET_ISREF_P(_12);
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
PHP_METHOD(Ice_Loader, loadClass) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval *className_param = NULL, *prefix = NULL, *pos = NULL, *relativeClass = NULL, *mappedFile = NULL, _0 = zval_used_for_init, _2 = zval_used_for_init, _3 = zval_used_for_init, *_5 = NULL, _6 = zval_used_for_init, _7 = zval_used_for_init;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	ZEPHIR_CPY_WRT(prefix, className);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "\\", 0);
	ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_1, 100, prefix, &_0);
	zephir_check_call_status();
	while (1) {
		if (!(!ZEPHIR_IS_FALSE_IDENTICAL(pos))) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, (zephir_get_numberval(pos) + 1));
		ZEPHIR_INIT_NVAR(prefix);
		zephir_substr(prefix, className, 0 , zephir_get_intval(&_2), 0);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, (zephir_get_numberval(pos) + 1));
		ZEPHIR_INIT_NVAR(relativeClass);
		zephir_substr(relativeClass, className, zephir_get_intval(&_3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&mappedFile, this_ptr, "loadmappedfile", &_4, 0, prefix, relativeClass);
		zephir_check_call_status();
		if (zephir_is_true(mappedFile)) {
			RETURN_CCTOR(mappedFile);
		}
		ZEPHIR_INIT_NVAR(_5);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_STRING(&_6, "\\", 0);
		zephir_fast_trim(_5, prefix, &_6, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_CPY_WRT(prefix, _5);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_STRING(&_7, "\\", 0);
		ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_1, 100, prefix, &_7);
		zephir_check_call_status();
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
PHP_METHOD(Ice_Loader, loadMappedFile) {

	zephir_fcall_cache_entry *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_4;
	HashPosition _3;
	zval *prefix_param = NULL, *relativeClass_param = NULL, *baseDir = NULL, *file = NULL, *_0, *_1, *_2, **_5, *_6 = NULL, _7 = zval_used_for_init, _8 = zval_used_for_init, *_9 = NULL, _10 = zval_used_for_init, _11 = zval_used_for_init, *_12 = NULL;
	zval *prefix = NULL, *relativeClass = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &prefix_param, &relativeClass_param);

	zephir_get_strval(prefix, prefix_param);
	zephir_get_strval(relativeClass, relativeClass_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefixes"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, prefix))) {
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_prefixes"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, prefix, PH_NOISY | PH_READONLY, "ice/loader.zep", 116 TSRMLS_CC);
	zephir_is_iterable(_2, &_4, &_3, 0, 0, "ice/loader.zep", 131);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(baseDir, _5);
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_STRING(&_7, "\\", 0);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "/", 0);
		zephir_fast_str_replace(&_6, &_7, &_8, relativeClass TSRMLS_CC);
		ZEPHIR_INIT_NVAR(file);
		ZEPHIR_CONCAT_VVS(file, baseDir, _6, ".php");
		ZEPHIR_INIT_NVAR(_9);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_STRING(&_10, "\\", 0);
		ZEPHIR_SINIT_NVAR(_11);
		ZVAL_STRING(&_11, "/", 0);
		zephir_fast_str_replace(&_9, &_10, &_11, relativeClass TSRMLS_CC);
		ZEPHIR_INIT_NVAR(file);
		ZEPHIR_CONCAT_VVS(file, baseDir, _9, ".php");
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "requirefile", &_13, 0, file);
		zephir_check_call_status();
		if (zephir_is_true(_12)) {
			RETURN_CCTOR(file);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * If a file exists, require it from the file system.
 * 
 * @param string $file The file to require
 * @return bool True if the file exists, false if not
 */
PHP_METHOD(Ice_Loader, requireFile) {

	zval *file_param = NULL;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(file, file_param);


	if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
		if (zephir_require_zval(file TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Ice_Loader, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_prefixes"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

