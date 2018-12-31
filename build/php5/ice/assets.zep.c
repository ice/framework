
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Assets) {

	ZEPHIR_REGISTER_CLASS(Ice, Assets, ice, assets, ice_assets_method_entry, 0);

	zend_declare_property_null(ice_assets_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_assets_ce, SL("collections"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_assets_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_assets_ce->create_object = zephir_init_properties_Ice_Assets;
	zend_declare_class_constant_long(ice_assets_ce, SL("NEVER"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_assets_ce, SL("NOT_EXIST"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_assets_ce, SL("IF_CHANGE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_assets_ce, SL("ALWAYS"), 3 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Assets, setCollections) {

	zval *collections;

	zephir_fetch_params(0, 1, 0, &collections);



	zephir_update_property_this(getThis(), SL("collections"), collections TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Assets, getCollections) {

	

	RETURN_MEMBER(getThis(), "collections");

}

PHP_METHOD(Ice_Assets, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(getThis(), SL("options"), options TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Assets constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Assets, __construct) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 1);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("di"), _0 TSRMLS_CC);
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

	zval *key, *defaultValue = NULL, *value = NULL, *_0;

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
 * @param string Collection Collection name
 * @param mixed minify Local minify option
 * @return object this
 */
PHP_METHOD(Ice_Assets, add) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *version = NULL, *collection = NULL;
	zval *parameters = NULL, *version_param = NULL, *collection_param = NULL, *minify = NULL, *content = NULL, *type = NULL, *link = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &parameters, &version_param, &collection_param, &minify);

	ZEPHIR_SEPARATE_PARAM(parameters);
	if (!version_param) {
		ZEPHIR_INIT_VAR(version);
		ZVAL_EMPTY_STRING(version);
	} else {
		zephir_get_strval(version, version_param);
	}
	if (!collection_param) {
		ZEPHIR_INIT_VAR(collection);
		ZVAL_EMPTY_STRING(collection);
	} else {
		zephir_get_strval(collection, collection_param);
	}
	if (!minify) {
		minify = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(parameters) == IS_STRING) {
		ZEPHIR_CPY_WRT(link, parameters);
		ZEPHIR_INIT_NVAR(parameters);
		array_init(parameters);
		zephir_array_append(&parameters, link, PH_SEPARATE, "ice/assets.zep", 67);
	}
	ZEPHIR_OBS_VAR(content);
	if (!(zephir_array_isset_string_fetch(&content, parameters, SS("content"), 0 TSRMLS_CC))) {
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
		if (!(!(!collection) && Z_STRLEN_P(collection))) {
			ZEPHIR_INIT_NVAR(collection);
			ZVAL_STRING(collection, "css", 1);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcss", NULL, 0, parameters, version, collection, minify);
		zephir_check_call_status();
	} else if (_1) {
		if (!(!(!collection) && Z_STRLEN_P(collection))) {
			ZEPHIR_INIT_NVAR(collection);
			ZVAL_STRING(collection, "js", 1);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addjs", NULL, 0, parameters, version, collection, minify);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Add CSS resource to assets.
 *
 * @param array parameters Parameters of link/style
 * @param string version Version appending to the uri
 * @param string Collection Collection name
 * @param mixed minify Local minify option
 * @return object this
 */
PHP_METHOD(Ice_Assets, addCss) {

	zend_bool _4;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *version = NULL, *collection = NULL, *_13$$8;
	zval *parameters_param = NULL, *version_param = NULL, *collection_param = NULL, *minify = NULL, *content = NULL, *local = NULL, *tag = NULL, *_0, *_1, *_2$$5, *_3$$5, *_5$$7 = NULL, *_7$$7 = NULL, *_8$$7, *_10$$8 = NULL, *_11$$8, *_12$$8 = NULL, *_14$$8, *_15$$8 = NULL;
	zval *parameters = NULL, *_6$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &parameters_param, &version_param, &collection_param, &minify);

	parameters = parameters_param;
	if (!version_param) {
		ZEPHIR_INIT_VAR(version);
		ZVAL_EMPTY_STRING(version);
	} else {
		zephir_get_strval(version, version_param);
	}
	if (!collection_param) {
		ZEPHIR_INIT_VAR(collection);
		ZVAL_STRING(collection, "css", 1);
	} else {
		zephir_get_strval(collection, collection_param);
	}
	if (!minify) {
		ZEPHIR_CPY_WRT(minify, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(minify);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&tag, _0, "get", NULL, 0, _1);
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
		ZEPHIR_INIT_VAR(_2$$5);
		ZVAL_STRING(_2$$5, "minify", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3$$5);
		ZVAL_LONG(_3$$5, 0);
		ZEPHIR_CALL_METHOD(&minify, this_ptr, "getoption", NULL, 0, _2$$5, _3$$5);
		zephir_check_temp_parameter(_2$$5);
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
		ZEPHIR_INIT_VAR(_6$$7);
		zephir_create_array(_6$$7, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$7);
		if (zephir_is_true(minify)) {
			ZEPHIR_INIT_VAR(_8$$7);
			ZVAL_STRING(_8$$7, "css", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "minify", NULL, 0, content, _8$$7);
			zephir_check_temp_parameter(_8$$7);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_7$$7, content);
		}
		zephir_array_update_string(&_6$$7, SL("content"), &_7$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_5$$7, tag, "style", NULL, 0, _6$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtocollection", &_9, 0, collection, _5$$7);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_11$$8);
		ZVAL_STRING(_11$$8, "css", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10$$8, this_ptr, "prepare", NULL, 0, content, _11$$8, minify);
		zephir_check_temp_parameter(_11$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_12$$8);
		if (!(!version) && Z_STRLEN_P(version)) {
			ZEPHIR_INIT_VAR(_13$$8);
			ZEPHIR_CONCAT_SV(_13$$8, "?v=", version);
			ZEPHIR_CPY_WRT(_12$$8, _13$$8);
		} else {
			ZEPHIR_INIT_NVAR(_12$$8);
			ZVAL_STRING(_12$$8, "", 1);
		}
		ZEPHIR_INIT_VAR(_14$$8);
		ZEPHIR_CONCAT_VV(_14$$8, _10$$8, _12$$8);
		zephir_array_update_string(&parameters, SL("href"), &_14$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_15$$8, tag, "link", NULL, 0, parameters);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtocollection", &_9, 0, collection, _15$$8);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Add JS resource to assets.
 *
 * @param array parameters Parameters of script
 * @param string version Version appending to the uri
 * @param string Collection Collection name
 * @param mixed minify Local minify option
 * @return object this
 */
PHP_METHOD(Ice_Assets, addJs) {

	zend_bool _4;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *version = NULL, *collection = NULL, *_13$$8;
	zval *parameters_param = NULL, *version_param = NULL, *collection_param = NULL, *minify = NULL, *content = NULL, *local = NULL, *tag = NULL, *_0, *_1, *_2$$5, *_3$$5, *_5$$7 = NULL, *_7$$7 = NULL, *_8$$7, *_10$$8 = NULL, *_11$$8, *_12$$8 = NULL, *_14$$8, *_15$$8 = NULL;
	zval *parameters = NULL, *_6$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &parameters_param, &version_param, &collection_param, &minify);

	parameters = parameters_param;
	if (!version_param) {
		ZEPHIR_INIT_VAR(version);
		ZVAL_EMPTY_STRING(version);
	} else {
		zephir_get_strval(version, version_param);
	}
	if (!collection_param) {
		ZEPHIR_INIT_VAR(collection);
		ZVAL_STRING(collection, "js", 1);
	} else {
		zephir_get_strval(collection, collection_param);
	}
	if (!minify) {
		ZEPHIR_CPY_WRT(minify, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(minify);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&tag, _0, "get", NULL, 0, _1);
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
		ZEPHIR_INIT_VAR(_2$$5);
		ZVAL_STRING(_2$$5, "minify", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3$$5);
		ZVAL_LONG(_3$$5, 0);
		ZEPHIR_CALL_METHOD(&minify, this_ptr, "getoption", NULL, 0, _2$$5, _3$$5);
		zephir_check_temp_parameter(_2$$5);
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
		ZEPHIR_INIT_VAR(_6$$7);
		zephir_create_array(_6$$7, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$7);
		if (zephir_is_true(minify)) {
			ZEPHIR_INIT_VAR(_8$$7);
			ZVAL_STRING(_8$$7, "js", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "minify", NULL, 0, content, _8$$7);
			zephir_check_temp_parameter(_8$$7);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_7$$7, content);
		}
		zephir_array_update_string(&_6$$7, SL("content"), &_7$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_5$$7, tag, "script", NULL, 0, _6$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtocollection", &_9, 0, collection, _5$$7);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_11$$8);
		ZVAL_STRING(_11$$8, "js", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10$$8, this_ptr, "prepare", NULL, 0, content, _11$$8, minify);
		zephir_check_temp_parameter(_11$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_12$$8);
		if (!(!version) && Z_STRLEN_P(version)) {
			ZEPHIR_INIT_VAR(_13$$8);
			ZEPHIR_CONCAT_SV(_13$$8, "?v=", version);
			ZEPHIR_CPY_WRT(_12$$8, _13$$8);
		} else {
			ZEPHIR_INIT_NVAR(_12$$8);
			ZVAL_STRING(_12$$8, "", 1);
		}
		ZEPHIR_INIT_VAR(_14$$8);
		ZEPHIR_CONCAT_VV(_14$$8, _10$$8, _12$$8);
		zephir_array_update_string(&parameters, SL("src"), &_14$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_15$$8, tag, "script", NULL, 0, parameters);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtocollection", &_9, 0, collection, _15$$8);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Add an asset to the collection.
 *
 * @param string key Collection name
 * @param string value Asset HTML code
 */
PHP_METHOD(Ice_Assets, addToCollection) {

	zval *key, *value, *_0, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("collections"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, key))) {
		ZEPHIR_INIT_VAR(_1$$3);
		array_init(_1$$3);
		zephir_update_property_array(this_ptr, SL("collections"), key, _1$$3 TSRMLS_CC);
	}
	zephir_update_property_array_multi(this_ptr, SL("collections"), &value TSRMLS_CC, SL("za"), 2, key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the CSS default collection.
 *
 * @return array
 */
PHP_METHOD(Ice_Assets, getCss) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "css", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the JS default collection.
 *
 * @return array
 */
PHP_METHOD(Ice_Assets, getJs) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "js", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get some collection.
 *
 * @param string key Collection name
 * @return array
 */
PHP_METHOD(Ice_Assets, get) {

	zval *key_param = NULL, *collection = NULL, *_0, *_1 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("collections"), PH_NOISY_CC);
	zephir_array_isset_fetch(&collection, _0, key, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	if (zephir_is_true(collection)) {
		ZEPHIR_CPY_WRT(_1, collection);
	} else {
		array_init(_1);
	}
	RETURN_CCTOR(_1);

}

/**
 * Minify content.
 *
 * @param string content Input text to minify
 * @param string type Type of content
 * @return string
 */
PHP_METHOD(Ice_Assets, minify) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, *type, *_0, *_1 = NULL, *_2, *_3;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &content_param, &type);

	if (UNEXPECTED(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(content, content_param);
	} else {
		ZEPHIR_INIT_VAR(content);
		ZVAL_EMPTY_STRING(content);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "filter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, type, "min");
	ZEPHIR_RETURN_CALL_METHOD(_1, "sanitize", NULL, 0, content, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepare resource.
 *
 * @param string uri The uri/url source path
 * @param string type Type of content
 * @param int minify Option of minify
 * @return string New path to the source
 */
PHP_METHOD(Ice_Assets, prepare) {

	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *type_param = NULL, *minify = NULL, *source = NULL, *target = NULL, *dir = NULL, *file = NULL, *uriMin = NULL, *destination = NULL, *exist = NULL, *old = NULL, *minified = NULL, *_0 = NULL, *_2 = NULL, *_5$$8 = NULL, *_6$$8, *_7$$10 = NULL, *_8$$11, *_9$$11, *_10$$12, *_11$$14 = NULL, *_12$$14 = NULL, *_16$$14, _13$$15 = zval_used_for_init, *_15$$15 = NULL;
	zval *uri = NULL, *type = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &uri_param, &type_param, &minify);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	}
	zephir_get_strval(type, type_param);
	ZEPHIR_SEPARATE_PARAM(minify);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "source", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getoption", &_1, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "target", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&target, this_ptr, "getoption", &_1, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "dirname", &_3, 54, uri);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(dir);
	ZEPHIR_CONCAT_VS(dir, _2, "/");
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, ".", type);
	ZEPHIR_CALL_FUNCTION(&file, "basename", NULL, 55, uri, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(uriMin);
	ZEPHIR_CONCAT_VVVSV(uriMin, target, dir, file, ".min.", type);
	ZEPHIR_INIT_VAR(destination);
	ZEPHIR_CONCAT_VV(destination, source, uriMin);
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
				ZEPHIR_CALL_FUNCTION(&minify, "md5_file", NULL, 56, destination);
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
		ZEPHIR_INIT_VAR(_6$$8);
		ZVAL_STRING(_6$$8, "forceMinified", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "getoption", &_1, 0, _6$$8);
		zephir_check_temp_parameter(_6$$8);
		zephir_check_call_status();
		if (zephir_is_true(_5$$8)) {
			ZEPHIR_INIT_NVAR(exist);
			ZVAL_BOOL(exist, (zephir_file_exists(destination TSRMLS_CC) == SUCCESS));
		}
		break;
	} while(0);

	if (!(zephir_is_true(minify))) {
		ZEPHIR_INIT_VAR(_7$$10);
		if (zephir_is_true(exist)) {
			ZEPHIR_CPY_WRT(_7$$10, uriMin);
		} else {
			ZEPHIR_CPY_WRT(_7$$10, uri);
		}
		RETURN_CCTOR(_7$$10);
	} else {
		ZEPHIR_INIT_VAR(_8$$11);
		ZEPHIR_INIT_VAR(_9$$11);
		ZEPHIR_CONCAT_VV(_9$$11, source, uri);
		zephir_file_get_contents(_8$$11, _9$$11 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&minified, this_ptr, "minify", NULL, 0, _8$$11, type);
		zephir_check_call_status();
		if (Z_TYPE_P(minify) == IS_STRING) {
			ZEPHIR_INIT_VAR(_10$$12);
			zephir_md5(_10$$12, minified);
			if (!ZEPHIR_IS_EQUAL(minify, _10$$12)) {
				ZEPHIR_INIT_NVAR(minify);
				ZVAL_BOOL(minify, 1);
			}
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(minify)) {
			ZEPHIR_CALL_FUNCTION(&_11$$14, "dirname", &_3, 54, destination);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_12$$14, "is_dir", NULL, 57, _11$$14);
			zephir_check_call_status();
			if (!(zephir_is_true(_12$$14))) {
				ZEPHIR_SINIT_VAR(_13$$15);
				ZVAL_LONG(&_13$$15, 0);
				ZEPHIR_CALL_FUNCTION(&old, "umask", &_14, 58, &_13$$15);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_15$$15, "dirname", &_3, 54, destination);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_13$$15);
				ZVAL_LONG(&_13$$15, 0777);
				ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 59, _15$$15, &_13$$15, ZEPHIR_GLOBAL(global_true));
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "umask", &_14, 58, old);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_VAR(_16$$14);
			zephir_file_put_contents(_16$$14, destination, minified TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_16$$14)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Directory can't be written", "ice/assets.zep", 309);
				return;
			}
		}
		RETURN_CCTOR(uriMin);
	}
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Ice_Assets(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("options"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("collections"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("collections"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

