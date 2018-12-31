
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
	zephir_declare_class_constant_long(ice_assets_ce, SL("NEVER"), 0);

	zephir_declare_class_constant_long(ice_assets_ce, SL("NOT_EXIST"), 1);

	zephir_declare_class_constant_long(ice_assets_ce, SL("IF_CHANGE"), 2);

	zephir_declare_class_constant_long(ice_assets_ce, SL("ALWAYS"), 3);

	return SUCCESS;

}

PHP_METHOD(Ice_Assets, setCollections) {

	zval *collections, collections_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collections_sub);

	zephir_fetch_params(0, 1, 0, &collections);



	zephir_update_property_zval(this_ptr, SL("collections"), collections);
	RETURN_THISW();

}

PHP_METHOD(Ice_Assets, getCollections) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "collections");

}

PHP_METHOD(Ice_Assets, setOptions) {

	zval *options, options_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_zval(this_ptr, SL("options"), options);
	RETURN_THISW();

}

/**
 * Assets constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Assets, __construct) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("di"), &_0);
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

	zval *key, key_sub, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 1, &key, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, key, 1 TSRMLS_CC)) {
		RETURN_CTORW(&value);
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
	zval version, collection;
	zval *parameters = NULL, parameters_sub, *version_param = NULL, *collection_param = NULL, *minify = NULL, minify_sub, __$null, content, type, link;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&minify_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&collection);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &parameters, &version_param, &collection_param, &minify);

	ZEPHIR_SEPARATE_PARAM(parameters);
	if (!version_param) {
		ZEPHIR_INIT_VAR(&version);
		ZVAL_STRING(&version, "");
	} else {
		zephir_get_strval(&version, version_param);
	}
	if (!collection_param) {
		ZEPHIR_INIT_VAR(&collection);
		ZVAL_STRING(&collection, "");
	} else {
		zephir_get_strval(&collection, collection_param);
	}
	if (!minify) {
		minify = &minify_sub;
		minify = &__$null;
	}


	if (Z_TYPE_P(parameters) == IS_STRING) {
		ZEPHIR_CPY_WRT(&link, parameters);
		ZEPHIR_INIT_NVAR(parameters);
		array_init(parameters);
		zephir_array_append(parameters, &link, PH_SEPARATE, "ice/assets.zep", 67);
	}
	ZEPHIR_OBS_VAR(&content);
	if (!(zephir_array_isset_string_fetch(&content, parameters, SL("content"), 0))) {
		ZEPHIR_OBS_NVAR(&content);
		zephir_array_isset_long_fetch(&content, parameters, 0, 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&type);
	zephir_array_isset_string_fetch(&type, parameters, SL("type"), 0);
	_0 = zephir_end_with_str(&content, SL(".css"));
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(&type, "text/css");
	}
	_1 = zephir_end_with_str(&content, SL(".js"));
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING(&type, "text/javascript");
	}
	if (_0) {
		if (!(!(Z_TYPE_P(&collection) == IS_UNDEF) && Z_STRLEN_P(&collection))) {
			ZEPHIR_INIT_NVAR(&collection);
			ZVAL_STRING(&collection, "css");
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcss", NULL, 0, parameters, &version, &collection, minify);
		zephir_check_call_status();
	} else if (_1) {
		if (!(!(Z_TYPE_P(&collection) == IS_UNDEF) && Z_STRLEN_P(&collection))) {
			ZEPHIR_INIT_NVAR(&collection);
			ZVAL_STRING(&collection, "js");
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addjs", NULL, 0, parameters, &version, &collection, minify);
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
	zval version, collection, _13$$8;
	zval *parameters_param = NULL, *version_param = NULL, *collection_param = NULL, *minify = NULL, minify_sub, __$null, content, local, tag, _0, _1, _2$$5, _3$$5, _5$$7, _7$$7, _8$$7, _10$$8, _11$$8, _12$$8, _14$$8, _15$$8;
	zval parameters, _6$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&minify_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_13$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &parameters_param, &version_param, &collection_param, &minify);

	ZEPHIR_OBS_COPY_OR_DUP(&parameters, parameters_param);
	if (!version_param) {
		ZEPHIR_INIT_VAR(&version);
		ZVAL_STRING(&version, "");
	} else {
		zephir_get_strval(&version, version_param);
	}
	if (!collection_param) {
		ZEPHIR_INIT_VAR(&collection);
		ZVAL_STRING(&collection, "css");
	} else {
		zephir_get_strval(&collection, collection_param);
	}
	if (!minify) {
		minify = &minify_sub;
		ZEPHIR_CPY_WRT(minify, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(minify);
	}


	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "tag");
	ZEPHIR_CALL_METHOD(&tag, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&content);
	if (!(zephir_array_isset_string_fetch(&content, &parameters, SL("content"), 0))) {
		ZEPHIR_OBS_NVAR(&content);
		zephir_array_isset_long_fetch(&content, &parameters, 0, 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	if (Z_TYPE_P(minify) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "minify");
		ZVAL_LONG(&_3$$5, 0);
		ZEPHIR_CALL_METHOD(minify, this_ptr, "getoption", NULL, 0, &_2$$5, &_3$$5);
		zephir_check_call_status();
	}
	_4 = !zephir_is_true(&local);
	if (!(_4)) {
		_4 = zephir_end_with_str(&content, SL(".min.css"));
	}
	if (_4) {
		ZEPHIR_INIT_NVAR(minify);
		ZVAL_LONG(minify, 0);
	}
	if (zephir_array_isset_string(&parameters, SL("content"))) {
		ZEPHIR_INIT_VAR(&_6$$7);
		zephir_create_array(&_6$$7, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$7);
		if (zephir_is_true(minify)) {
			ZEPHIR_INIT_VAR(&_8$$7);
			ZVAL_STRING(&_8$$7, "css");
			ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "minify", NULL, 0, &content, &_8$$7);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&_7$$7, &content);
		}
		zephir_array_update_string(&_6$$7, SL("content"), &_7$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_5$$7, &tag, "style", NULL, 0, &_6$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtocollection", &_9, 0, &collection, &_5$$7);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_11$$8);
		ZVAL_STRING(&_11$$8, "css");
		ZEPHIR_CALL_METHOD(&_10$$8, this_ptr, "prepare", NULL, 0, &content, &_11$$8, minify);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_12$$8);
		if (!(Z_TYPE_P(&version) == IS_UNDEF) && Z_STRLEN_P(&version)) {
			ZEPHIR_INIT_VAR(&_13$$8);
			ZEPHIR_CONCAT_SV(&_13$$8, "?v=", &version);
			ZEPHIR_CPY_WRT(&_12$$8, &_13$$8);
		} else {
			ZEPHIR_INIT_NVAR(&_12$$8);
			ZVAL_STRING(&_12$$8, "");
		}
		ZEPHIR_INIT_VAR(&_14$$8);
		ZEPHIR_CONCAT_VV(&_14$$8, &_10$$8, &_12$$8);
		zephir_array_update_string(&parameters, SL("href"), &_14$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_15$$8, &tag, "link", NULL, 0, &parameters);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtocollection", &_9, 0, &collection, &_15$$8);
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
	zval version, collection, _13$$8;
	zval *parameters_param = NULL, *version_param = NULL, *collection_param = NULL, *minify = NULL, minify_sub, __$null, content, local, tag, _0, _1, _2$$5, _3$$5, _5$$7, _7$$7, _8$$7, _10$$8, _11$$8, _12$$8, _14$$8, _15$$8;
	zval parameters, _6$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&minify_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_13$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &parameters_param, &version_param, &collection_param, &minify);

	ZEPHIR_OBS_COPY_OR_DUP(&parameters, parameters_param);
	if (!version_param) {
		ZEPHIR_INIT_VAR(&version);
		ZVAL_STRING(&version, "");
	} else {
		zephir_get_strval(&version, version_param);
	}
	if (!collection_param) {
		ZEPHIR_INIT_VAR(&collection);
		ZVAL_STRING(&collection, "js");
	} else {
		zephir_get_strval(&collection, collection_param);
	}
	if (!minify) {
		minify = &minify_sub;
		ZEPHIR_CPY_WRT(minify, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(minify);
	}


	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "tag");
	ZEPHIR_CALL_METHOD(&tag, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&content);
	if (!(zephir_array_isset_string_fetch(&content, &parameters, SL("content"), 0))) {
		ZEPHIR_OBS_NVAR(&content);
		zephir_array_isset_long_fetch(&content, &parameters, 0, 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	if (Z_TYPE_P(minify) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "minify");
		ZVAL_LONG(&_3$$5, 0);
		ZEPHIR_CALL_METHOD(minify, this_ptr, "getoption", NULL, 0, &_2$$5, &_3$$5);
		zephir_check_call_status();
	}
	_4 = !zephir_is_true(&local);
	if (!(_4)) {
		_4 = zephir_end_with_str(&content, SL(".min.js"));
	}
	if (_4) {
		ZEPHIR_INIT_NVAR(minify);
		ZVAL_LONG(minify, 0);
	}
	if (zephir_array_isset_string(&parameters, SL("content"))) {
		ZEPHIR_INIT_VAR(&_6$$7);
		zephir_create_array(&_6$$7, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$7);
		if (zephir_is_true(minify)) {
			ZEPHIR_INIT_VAR(&_8$$7);
			ZVAL_STRING(&_8$$7, "js");
			ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "minify", NULL, 0, &content, &_8$$7);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&_7$$7, &content);
		}
		zephir_array_update_string(&_6$$7, SL("content"), &_7$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_5$$7, &tag, "script", NULL, 0, &_6$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtocollection", &_9, 0, &collection, &_5$$7);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_11$$8);
		ZVAL_STRING(&_11$$8, "js");
		ZEPHIR_CALL_METHOD(&_10$$8, this_ptr, "prepare", NULL, 0, &content, &_11$$8, minify);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_12$$8);
		if (!(Z_TYPE_P(&version) == IS_UNDEF) && Z_STRLEN_P(&version)) {
			ZEPHIR_INIT_VAR(&_13$$8);
			ZEPHIR_CONCAT_SV(&_13$$8, "?v=", &version);
			ZEPHIR_CPY_WRT(&_12$$8, &_13$$8);
		} else {
			ZEPHIR_INIT_NVAR(&_12$$8);
			ZVAL_STRING(&_12$$8, "");
		}
		ZEPHIR_INIT_VAR(&_14$$8);
		ZEPHIR_CONCAT_VV(&_14$$8, &_10$$8, &_12$$8);
		zephir_array_update_string(&parameters, SL("src"), &_14$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_15$$8, &tag, "script", NULL, 0, &parameters);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtocollection", &_9, 0, &collection, &_15$$8);
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

	zval *key, key_sub, *value, value_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	zephir_read_property(&_0, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, key))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_array(this_ptr, SL("collections"), key, &_1$$3 TSRMLS_CC);
	}
	zephir_update_property_array_multi(this_ptr, SL("collections"), value TSRMLS_CC, SL("za"), 2, key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the CSS default collection.
 *
 * @return array
 */
PHP_METHOD(Ice_Assets, getCss) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "css");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the JS default collection.
 *
 * @return array
 */
PHP_METHOD(Ice_Assets, getJs) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "js");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_0);
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

	zval *key_param = NULL, collection, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_fetch(&collection, &_0, &key, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_is_true(&collection)) {
		ZEPHIR_CPY_WRT(&_1, &collection);
	} else {
		array_init(&_1);
	}
	RETURN_CCTOR(&_1);

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
	zval *content_param = NULL, *type, type_sub, _0, _1, _2, _3;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &content_param, &type);

	if (UNEXPECTED(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(&content, content_param);
	} else {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_EMPTY_STRING(&content);
	}


	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "filter");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VS(&_3, type, "min");
	ZEPHIR_RETURN_CALL_METHOD(&_1, "sanitize", NULL, 0, &content, &_3);
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
	zval *uri_param = NULL, *type_param = NULL, *minify = NULL, minify_sub, __$true, source, target, dir, file, uriMin, destination, exist, old, minified, _0, _2, _5$$8, _6$$8, _7$$10, _8$$11, _9$$11, _10$$12, _11$$14, _12$$14, _16$$14, _13$$15, _15$$15;
	zval uri, type, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&minify_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&uriMin);
	ZVAL_UNDEF(&destination);
	ZVAL_UNDEF(&exist);
	ZVAL_UNDEF(&old);
	ZVAL_UNDEF(&minified);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_15$$15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &uri_param, &type_param, &minify);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}
	zephir_get_strval(&type, type_param);
	ZEPHIR_SEPARATE_PARAM(minify);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "source");
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getoption", &_1, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "target");
	ZEPHIR_CALL_METHOD(&target, this_ptr, "getoption", &_1, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "dirname", &_3, 52, &uri);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&dir);
	ZEPHIR_CONCAT_VS(&dir, &_2, "/");
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, ".", &type);
	ZEPHIR_CALL_FUNCTION(&file, "basename", NULL, 53, &uri, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&uriMin);
	ZEPHIR_CONCAT_VVVSV(&uriMin, &target, &dir, &file, ".min.", &type);
	ZEPHIR_INIT_VAR(&destination);
	ZEPHIR_CONCAT_VV(&destination, &source, &uriMin);
	ZEPHIR_INIT_VAR(&exist);
	ZVAL_BOOL(&exist, 0);
	do {
		if (ZEPHIR_IS_LONG(minify, 1)) {
			ZEPHIR_INIT_NVAR(minify);
			ZVAL_BOOL(minify, !((zephir_file_exists(&destination TSRMLS_CC) == SUCCESS)));
			break;
		}
		if (ZEPHIR_IS_LONG(minify, 2)) {
			if (!((zephir_file_exists(&destination TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_NVAR(minify);
				ZVAL_BOOL(minify, 1);
			} else {
				ZEPHIR_CALL_FUNCTION(minify, "md5_file", NULL, 54, &destination);
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
		ZEPHIR_INIT_VAR(&_6$$8);
		ZVAL_STRING(&_6$$8, "forceMinified");
		ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "getoption", &_1, 0, &_6$$8);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$8)) {
			ZEPHIR_INIT_NVAR(&exist);
			ZVAL_BOOL(&exist, (zephir_file_exists(&destination TSRMLS_CC) == SUCCESS));
		}
		break;
	} while(0);

	if (!(zephir_is_true(minify))) {
		ZEPHIR_INIT_VAR(&_7$$10);
		if (zephir_is_true(&exist)) {
			ZEPHIR_CPY_WRT(&_7$$10, &uriMin);
		} else {
			ZEPHIR_CPY_WRT(&_7$$10, &uri);
		}
		RETURN_CCTOR(&_7$$10);
	} else {
		ZEPHIR_INIT_VAR(&_8$$11);
		ZEPHIR_INIT_VAR(&_9$$11);
		ZEPHIR_CONCAT_VV(&_9$$11, &source, &uri);
		zephir_file_get_contents(&_8$$11, &_9$$11 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&minified, this_ptr, "minify", NULL, 0, &_8$$11, &type);
		zephir_check_call_status();
		if (Z_TYPE_P(minify) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_10$$12);
			zephir_md5(&_10$$12, &minified);
			if (!ZEPHIR_IS_EQUAL(minify, &_10$$12)) {
				ZEPHIR_INIT_NVAR(minify);
				ZVAL_BOOL(minify, 1);
			}
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(minify)) {
			ZEPHIR_CALL_FUNCTION(&_11$$14, "dirname", &_3, 52, &destination);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_12$$14, "is_dir", NULL, 55, &_11$$14);
			zephir_check_call_status();
			if (!(zephir_is_true(&_12$$14))) {
				ZVAL_LONG(&_13$$15, 0);
				ZEPHIR_CALL_FUNCTION(&old, "umask", &_14, 56, &_13$$15);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_15$$15, "dirname", &_3, 52, &destination);
				zephir_check_call_status();
				ZVAL_LONG(&_13$$15, 0777);
				ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 57, &_15$$15, &_13$$15, &__$true);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "umask", &_14, 56, &old);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_VAR(&_16$$14);
			zephir_file_put_contents(&_16$$14, &destination, &minified TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_16$$14)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Directory can't be written", "ice/assets.zep", 309);
				return;
			}
		}
		RETURN_CCTOR(&uriMin);
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Ice_Assets(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("collections"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

