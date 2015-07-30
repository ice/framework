
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/file.h"


/**
 * Assets helper is designed to management css/js resources.
 *
 * @package     Ice/Assets
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Assets) {

	ZEPHIR_REGISTER_CLASS(Ice, Assets, ice, assets, ice_assets_method_entry, 0);

	zend_declare_property_null(ice_assets_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_assets_ce, SL("css"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_assets_ce, SL("js"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_assets_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_assets_ce->create_object = zephir_init_properties_Ice_Assets;
	zend_declare_class_constant_long(ice_assets_ce, SL("NEVER"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_assets_ce, SL("NOT_EXIST"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_assets_ce, SL("IF_CHANGE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_assets_ce, SL("ALWAYS"), 3 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Assets, getCss) {


	RETURN_MEMBER(this_ptr, "css");

}

PHP_METHOD(Ice_Assets, getJs) {


	RETURN_MEMBER(this_ptr, "js");

}

PHP_METHOD(Ice_Assets, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);

}

/**
 * Assets constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Assets, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 8);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Retrieve a single option.
 *
 * @param string key The data key
 * @param mixed defaultValue The value to return if data key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Assets, getOption) {

	zval *key, *defaultValue = NULL, *value, *_0;

	zephir_fetch_params(0, 1, 1, &key, &defaultValue);

	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTORW(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;

}

/**
 * Add resource to assets, autodetect type.
 *
 * @param mixed parameters Parameters of link/script/style
 * @param string version Version appending to the uri
 * @param mixed minify Local minify option
 * @return object this
 */
PHP_METHOD(Ice_Assets, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _1;
	zval *version = NULL;
	zval *parameters = NULL, *version_param = NULL, *minify = NULL, *content = NULL, *type;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &parameters, &version_param, &minify);

	ZEPHIR_SEPARATE_PARAM(parameters);
	if (!version_param) {
		ZEPHIR_INIT_VAR(version);
		ZVAL_EMPTY_STRING(version);
	} else {
		zephir_get_strval(version, version_param);
	}
	if (!minify) {
		minify = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(content);
	if (Z_TYPE_P(parameters) == IS_STRING) {
		ZEPHIR_CPY_WRT(content, parameters);
		ZEPHIR_INIT_NVAR(parameters);
		array_init(parameters);
		zephir_array_append(&parameters, content, PH_SEPARATE, "ice/assets.zep", 67);
	} else if (!(zephir_array_isset_string_fetch(&content, parameters, SS("content"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(content);
		zephir_array_isset_long_fetch(&content, parameters, 0, 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(type);
	zephir_array_isset_string_fetch(&type, parameters, SS("type"), 0 TSRMLS_CC);
	_0 = zephir_end_with_str(content, SL(".css"));
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(type, "text/css");
	}
	_1 = zephir_end_with_str(content, SL(".js"));
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING(type, "text/javascript");
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcss", NULL, 0, parameters, version, minify);
		zephir_check_call_status();
	} else if (_1) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addjs", NULL, 0, parameters, version, minify);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Add CSS resource to assets.
 *
 * @param array parameters Parameters of link/style
 * @param string version Version appending to the uri
 * @param mixed minify Local minify option
 * @return object this
 */
PHP_METHOD(Ice_Assets, addCss) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *version = NULL, *_8;
	zval *parameters_param = NULL, *version_param = NULL, *minify = NULL, *content = NULL, *local = NULL, *tag = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_5 = NULL, *_7 = NULL, *_9, *_10 = NULL;
	zval *parameters = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &parameters_param, &version_param, &minify);

	parameters = parameters_param;

	if (!version_param) {
		ZEPHIR_INIT_VAR(version);
		ZVAL_EMPTY_STRING(version);
	} else {
		zephir_get_strval(version, version_param);
	}
	if (!minify) {
		ZEPHIR_CPY_WRT(minify, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(minify);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(&tag, _0, "get", NULL, 0, _1, _2, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(content);
	if (!(zephir_array_isset_string_fetch(&content, parameters, SS("content"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(content);
		zephir_array_isset_long_fetch(&content, parameters, 0, 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(local);
	if (!(zephir_array_isset_string_fetch(&local, parameters, SS("local"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(local);
		ZVAL_BOOL(local, 1);
	}
	if (Z_TYPE_P(minify) == IS_NULL) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "minify", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_CALL_METHOD(&minify, this_ptr, "getoption", NULL, 0, _1, _2);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	_4 = !zephir_is_true(local);
	if (!(_4)) {
		_4 = zephir_end_with_str(content, SL(".min.css"));
	}
	if (_4) {
		ZEPHIR_INIT_NVAR(minify);
		ZVAL_LONG(minify, 0);
	}
	if (zephir_array_isset_string(parameters, SS("content"))) {
		ZEPHIR_INIT_VAR(_6);
		zephir_create_array(_6, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		if (zephir_is_true(minify)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "css", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7, this_ptr, "minify", NULL, 0, content, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_7, content);
		}
		zephir_array_update_string(&_6, SL("content"), &_7, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_5, tag, "style", NULL, 0, _6);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("css"), _5 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "css", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "prepare", NULL, 0, content, _1, minify);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_7);
		if (version && Z_STRLEN_P(version)) {
			ZEPHIR_INIT_VAR(_8);
			ZEPHIR_CONCAT_SV(_8, "?v=", version);
			ZEPHIR_CPY_WRT(_7, _8);
		} else {
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "", 1);
		}
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_VV(_9, _5, _7);
		zephir_array_update_string(&parameters, SL("href"), &_9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_10, tag, "link", NULL, 0, parameters);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("css"), _10 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Add JS resource to assets.
 *
 * @param array parameters Parameters of script
 * @param string version Version appending to the uri
 * @param mixed minify Local minify option
 * @return object this
 */
PHP_METHOD(Ice_Assets, addJs) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *version = NULL, *_8;
	zval *parameters_param = NULL, *version_param = NULL, *minify = NULL, *content = NULL, *local = NULL, *tag = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_5 = NULL, *_7 = NULL, *_9, *_10 = NULL;
	zval *parameters = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &parameters_param, &version_param, &minify);

	parameters = parameters_param;

	if (!version_param) {
		ZEPHIR_INIT_VAR(version);
		ZVAL_EMPTY_STRING(version);
	} else {
		zephir_get_strval(version, version_param);
	}
	if (!minify) {
		ZEPHIR_CPY_WRT(minify, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(minify);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(&tag, _0, "get", NULL, 0, _1, _2, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(content);
	if (!(zephir_array_isset_string_fetch(&content, parameters, SS("content"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(content);
		zephir_array_isset_long_fetch(&content, parameters, 0, 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(local);
	if (!(zephir_array_isset_string_fetch(&local, parameters, SS("local"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(local);
		ZVAL_BOOL(local, 1);
	}
	if (Z_TYPE_P(minify) == IS_NULL) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "minify", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_CALL_METHOD(&minify, this_ptr, "getoption", NULL, 0, _1, _2);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	_4 = !zephir_is_true(local);
	if (!(_4)) {
		_4 = zephir_end_with_str(content, SL(".min.js"));
	}
	if (_4) {
		ZEPHIR_INIT_NVAR(minify);
		ZVAL_LONG(minify, 0);
	}
	if (zephir_array_isset_string(parameters, SS("content"))) {
		ZEPHIR_INIT_VAR(_6);
		zephir_create_array(_6, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		if (zephir_is_true(minify)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "js", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7, this_ptr, "minify", NULL, 0, content, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_7, content);
		}
		zephir_array_update_string(&_6, SL("content"), &_7, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_5, tag, "script", NULL, 0, _6);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("js"), _5 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "js", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "prepare", NULL, 0, content, _1, minify);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_7);
		if (version && Z_STRLEN_P(version)) {
			ZEPHIR_INIT_VAR(_8);
			ZEPHIR_CONCAT_SV(_8, "?v=", version);
			ZEPHIR_CPY_WRT(_7, _8);
		} else {
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "", 1);
		}
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_VV(_9, _5, _7);
		zephir_array_update_string(&parameters, SL("src"), &_9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_10, tag, "script", NULL, 0, parameters);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("js"), _10 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Minify content
 *
 * @param string content Input text to minify
 * @param string type Type of content
 * @return string
 */
PHP_METHOD(Ice_Assets, minify) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, *type, *_0, *_1 = NULL, *_2, *_3, *_4, *_5;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &content_param, &type);

	if (unlikely(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(content, content_param);
	} else {
		ZEPHIR_INIT_VAR(content);
		ZVAL_EMPTY_STRING(content);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "filter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_NULL(_3);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, 1);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, 0, _2, _3, _4);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, type, "min");
	ZEPHIR_RETURN_CALL_METHOD(_1, "sanitize", NULL, 0, content, _5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepare resource
 *
 * @param string source The uri/url source path
 * @param string type Type of content
 * @param int minify Option of minify
 * @return string New path to the source
 */
PHP_METHOD(Ice_Assets, prepare) {

	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *type_param = NULL, *minify = NULL, *path = NULL, *target = NULL, *dir, *file = NULL, *sourceMin, *destination, *exist = NULL, *old = NULL, *minified = NULL, *_0 = NULL, *_2 = NULL, *_5 = NULL, *_6, *_7 = NULL, *_8 = NULL, _9 = zval_used_for_init, *_11 = NULL;
	zval *source = NULL, *type = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &source_param, &type_param, &minify);

	if (unlikely(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(source, source_param);
	} else {
		ZEPHIR_INIT_VAR(source);
		ZVAL_EMPTY_STRING(source);
	}
	zephir_get_strval(type, type_param);
	ZEPHIR_SEPARATE_PARAM(minify);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "path", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&path, this_ptr, "getoption", &_1, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "target", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&target, this_ptr, "getoption", &_1, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "dirname", &_3, 34, source);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(dir);
	ZEPHIR_CONCAT_VS(dir, _2, "/");
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, ".", type);
	ZEPHIR_CALL_FUNCTION(&file, "basename", NULL, 35, source, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sourceMin);
	ZEPHIR_CONCAT_VVVSV(sourceMin, target, dir, file, ".min.", type);
	ZEPHIR_INIT_VAR(destination);
	ZEPHIR_CONCAT_VV(destination, path, sourceMin);
	ZEPHIR_INIT_VAR(exist);
	ZVAL_BOOL(exist, 0);
	do {
		if (ZEPHIR_IS_LONG(minify, 1)) {
			ZEPHIR_INIT_NVAR(minify);
			ZVAL_BOOL(minify, !((zephir_file_exists(destination TSRMLS_CC) == SUCCESS)));
			break;
		}
		if (ZEPHIR_IS_LONG(minify, 2)) {
			if (!((zephir_file_exists(destination TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_NVAR(minify);
				ZVAL_BOOL(minify, 1);
			} else {
				ZEPHIR_CALL_FUNCTION(&minify, "md5_file", NULL, 36, destination);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(minify, 3)) {
			ZEPHIR_INIT_NVAR(minify);
			ZVAL_BOOL(minify, 1);
			break;
		}
		ZEPHIR_INIT_NVAR(minify);
		ZVAL_BOOL(minify, 0);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "forceMinified", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "getoption", &_1, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			ZEPHIR_INIT_NVAR(exist);
			ZVAL_BOOL(exist, (zephir_file_exists(destination TSRMLS_CC) == SUCCESS));
		}
		break;
	} while(0);

	if (!(zephir_is_true(minify))) {
		ZEPHIR_INIT_NVAR(_0);
		if (zephir_is_true(exist)) {
			ZEPHIR_CPY_WRT(_0, sourceMin);
		} else {
			ZEPHIR_CPY_WRT(_0, source);
		}
		RETURN_CCTOR(_0);
	} else {
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_VV(_6, path, source);
		zephir_file_get_contents(_0, _6 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&minified, this_ptr, "minify", NULL, 0, _0, type);
		zephir_check_call_status();
		if (Z_TYPE_P(minify) == IS_STRING) {
			ZEPHIR_INIT_VAR(_7);
			zephir_md5(_7, minified);
			if (!ZEPHIR_IS_EQUAL(minify, _7)) {
				ZEPHIR_INIT_NVAR(minify);
				ZVAL_BOOL(minify, 1);
			}
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(minify)) {
			ZEPHIR_CALL_FUNCTION(&_5, "dirname", &_3, 34, destination);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_8, "is_dir", NULL, 37, _5);
			zephir_check_call_status();
			if (!(zephir_is_true(_8))) {
				ZEPHIR_SINIT_VAR(_9);
				ZVAL_LONG(&_9, 0);
				ZEPHIR_CALL_FUNCTION(&old, "umask", &_10, 38, &_9);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_11, "dirname", &_3, 34, destination);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 0777);
				ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 39, _11, &_9, ZEPHIR_GLOBAL(global_true));
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "umask", &_10, 38, old);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_7);
			zephir_file_put_contents(_7, destination, minified TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_7)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Directory can't be written", "ice/assets.zep", 249);
				return;
			}
		}
		RETURN_CCTOR(sourceMin);
	}
	ZEPHIR_MM_RESTORE();

}

static zend_object_value zephir_init_properties_Ice_Assets(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2, *_3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("options"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("js"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("js"), _1 TSRMLS_CC);
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("css"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("css"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

