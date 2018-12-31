
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/time.h"


/**
 * Twitter Auth social adapter.
 *
 * @package     Ice/Auth
 * @category    Adapter
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Social_Twitter) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Social, Twitter, ice, auth_social_twitter, ice_auth_social_adapter_ce, ice_auth_social_twitter_method_entry, 0);

	return SUCCESS;

}

/**
 * Twitter adapter constructor.
 *
 * @param array config
 */
PHP_METHOD(Ice_Auth_Social_Twitter, __construct) {

	zval _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *config = NULL, config_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		config = &config_sub;
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "twitter");
	zephir_update_property_zval(this_ptr, SL("provider"), &_0);
	ZEPHIR_CALL_PARENT(NULL, ice_auth_social_twitter_ce, getThis(), "__construct", &_1, 0, config);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 5, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_2, SL("socialId"), SL("id"));
	add_assoc_stringl_ex(&_2, SL("email"), SL("email"));
	add_assoc_stringl_ex(&_2, SL("name"), SL("name"));
	add_assoc_stringl_ex(&_2, SL("sex"), SL("sex"));
	add_assoc_stringl_ex(&_2, SL("birthday"), SL("bdate"));
	zephir_update_property_zval(this_ptr, SL("socialFieldsMap"), &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "oauth_token");
	zephir_update_property_zval(this_ptr, SL("responseType"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get user social id or null if it is not set.
 *
 * @return string|null
 */
PHP_METHOD(Ice_Auth_Social_Twitter, getSocialPage) {

	zval _0, _1, _2$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "screen_name");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "screen_name");
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "get", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SV(return_value, "http://twitter.com/", &_2$$3);
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Get url of user"s avatar or null if it is not set.
 *
 * @return string|null
 */
PHP_METHOD(Ice_Auth_Social_Twitter, getImage) {

	zval _0, _1, _2$$3, _3$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "profile_image_url");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "profile_image_url");
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "get", NULL, 0, &_4$$3);
		zephir_check_call_status();
		zephir_fast_explode_str(&_2$$3, SL("_normal"), &_3$$3, LONG_MAX TSRMLS_CC);
		zephir_fast_join_str(return_value, SL(""), &_2$$3 TSRMLS_CC);
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Authenticate and return bool result of authentication.
 *
 * @return bool
 */
PHP_METHOD(Ice_Auth_Social_Twitter, authenticate) {

	zval _10$$5;
	zend_bool result = 0, _0, _7$$4, _8$$4, _9$$4;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_GET, params, tokenInfo, userInfo, accessTokenUrl, getDataUrl, _1$$3, _2$$3, _12$$3, _3$$4, _5$$4, _6$$4, _11$$5, _13$$6, _14$$6, _15$$6, _16$$6, _17$$6, _18$$6, _19$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&tokenInfo);
	ZVAL_UNDEF(&userInfo);
	ZVAL_UNDEF(&accessTokenUrl);
	ZVAL_UNDEF(&getDataUrl);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_10$$5);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));

	result = 0;
	ZEPHIR_INIT_VAR(&tokenInfo);
	ZVAL_NULL(&tokenInfo);
	_0 = zephir_array_isset_string(_GET, SL("oauth_token"));
	if (_0) {
		_0 = zephir_array_isset_string(_GET, SL("oauth_verifier"));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_array_fetch_string(&_1$$3, _GET, SL("oauth_token"), PH_NOISY, "ice/auth/social/twitter.zep", 80 TSRMLS_CC);
		zephir_array_update_string(&params, SL("oauth_token"), &_1$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_1$$3);
		zephir_array_fetch_string(&_1$$3, _GET, SL("oauth_verifier"), PH_NOISY, "ice/auth/social/twitter.zep", 82 TSRMLS_CC);
		zephir_array_update_string(&params, SL("oauth_verifier"), &_1$$3, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_2$$3, this_ptr, SL("accessToken"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_2$$3))) {
			ZEPHIR_INIT_VAR(&accessTokenUrl);
			ZVAL_STRING(&accessTokenUrl, "https://api.twitter.com/oauth/access_token");
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "prepareurlparams", &_4, 65, &accessTokenUrl, &params);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&params, &_3$$4);
			ZVAL_LONG(&_5$$4, 0);
			ZVAL_BOOL(&_6$$4, 0);
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "call", NULL, 0, &_5$$4, &accessTokenUrl, &params, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_MAKE_REF(&tokenInfo);
			ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 66, &_3$$4, &tokenInfo);
			ZEPHIR_UNREF(&tokenInfo);
			zephir_check_call_status();
			_7$$4 = zephir_fast_count_int(&tokenInfo TSRMLS_CC) > 0;
			if (_7$$4) {
				_7$$4 = zephir_array_isset_string(&tokenInfo, SL("oauth_token"));
			}
			_8$$4 = _7$$4;
			if (_8$$4) {
				_8$$4 = zephir_array_isset_string(&tokenInfo, SL("oauth_token_secret"));
			}
			_9$$4 = _8$$4;
			if (_9$$4) {
				_9$$4 = zephir_array_isset_string(&tokenInfo, SL("screen_name"));
			}
			if (_9$$4) {
				ZEPHIR_INIT_VAR(&_10$$5);
				zephir_create_array(&_10$$5, 3, 0 TSRMLS_CC);
				ZEPHIR_OBS_VAR(&_11$$5);
				zephir_array_fetch_string(&_11$$5, &tokenInfo, SL("oauth_token"), PH_NOISY, "ice/auth/social/twitter.zep", 93 TSRMLS_CC);
				zephir_array_update_string(&_10$$5, SL("oauth_token"), &_11$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_11$$5);
				zephir_array_fetch_string(&_11$$5, &tokenInfo, SL("oauth_token_secret"), PH_NOISY, "ice/auth/social/twitter.zep", 94 TSRMLS_CC);
				zephir_array_update_string(&_10$$5, SL("oauth_token_secret"), &_11$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_11$$5);
				zephir_array_fetch_string(&_11$$5, &tokenInfo, SL("screen_name"), PH_NOISY, "ice/auth/social/twitter.zep", 96 TSRMLS_CC);
				zephir_array_update_string(&_10$$5, SL("screen_name"), &_11$$5, PH_COPY | PH_SEPARATE);
				zephir_update_property_zval(this_ptr, SL("accessToken"), &_10$$5);
			}
		}
		zephir_read_property(&_12$$3, this_ptr, SL("accessToken"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_12$$3)) {
			ZEPHIR_INIT_VAR(&getDataUrl);
			ZVAL_STRING(&getDataUrl, "https://api.twitter.com/1.1/users/show.json");
			ZEPHIR_INIT_NVAR(&params);
			zephir_create_array(&params, 3, 0 TSRMLS_CC);
			zephir_read_property(&_13$$6, this_ptr, SL("accessToken"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_VAR(&_14$$6);
			zephir_array_fetch_string(&_14$$6, &_13$$6, SL("oauth_token"), PH_NOISY, "ice/auth/social/twitter.zep", 103 TSRMLS_CC);
			zephir_array_update_string(&params, SL("oauth_token"), &_14$$6, PH_COPY | PH_SEPARATE);
			zephir_read_property(&_15$$6, this_ptr, SL("accessToken"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&_14$$6);
			zephir_array_fetch_string(&_14$$6, &_15$$6, SL("screen_name"), PH_NOISY, "ice/auth/social/twitter.zep", 104 TSRMLS_CC);
			zephir_array_update_string(&params, SL("screen_name"), &_14$$6, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&params, SL("include_entities"), SL("false"));
			zephir_read_property(&_17$$6, this_ptr, SL("accessToken"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_18$$6, &_17$$6, SL("oauth_token_secret"), PH_NOISY | PH_READONLY, "ice/auth/social/twitter.zep", 107 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16$$6, this_ptr, "prepareurlparams", &_4, 65, &getDataUrl, &params, &_18$$6);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&params, &_16$$6);
			ZVAL_LONG(&_19$$6, 0);
			ZEPHIR_CALL_METHOD(&userInfo, this_ptr, "call", NULL, 0, &_19$$6, &getDataUrl, &params);
			zephir_check_call_status();
			if (zephir_array_isset_string(&userInfo, SL("id"))) {
				zephir_update_property_zval(this_ptr, SL("userInfo"), &userInfo);
				result = 1;
			}
		}
	}
	RETURN_MM_BOOL(result);

}

/**
 * Prepare params for authentication url.
 *
 * @return array
 */
PHP_METHOD(Ice_Auth_Social_Twitter, prepareAuthParams) {

	zval _0, _4;
	zval requestTokenUrl, requestTokens, params, _1, _2, _3, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestTokenUrl);
	ZVAL_UNDEF(&requestTokens);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&requestTokenUrl);
	ZVAL_STRING(&requestTokenUrl, "https://api.twitter.com/oauth/request_token");
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("redirectUri"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("oauth_callback"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&params, this_ptr, "prepareurlparams", NULL, 65, &requestTokenUrl, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_METHOD(&requestTokens, this_ptr, "call", NULL, 0, &_2, &requestTokenUrl, &params, &_3);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&requestTokens);
	ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 66, &requestTokens, &requestTokens);
	ZEPHIR_UNREF(&requestTokens);
	zephir_check_call_status();
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("auth_url"), SL("https://api.twitter.com/oauth/authenticate"));
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	if (zephir_array_isset_string(&requestTokens, SL("oauth_token"))) {
		ZEPHIR_OBS_NVAR(&_5);
		zephir_array_fetch_string(&_5, &requestTokens, SL("oauth_token"), PH_NOISY, "ice/auth/social/twitter.zep", 136 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_NULL(&_5);
	}
	zephir_array_update_string(&_4, SL("oauth_token"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("auth_params"), &_4, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Prepare url-params with signature.
 *
 * @return array
 */
PHP_METHOD(Ice_Auth_Social_Twitter, prepareUrlParams) {

	zval _1;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *params = NULL, params_sub, *oauthToken_param = NULL, *type_param = NULL, __$true, sigBaseStr, key, _0, _2, _3, _4, _5, _6, _8, _9, _10, _11, _12, _13;
	zval url, oauthToken, type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&oauthToken);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&params_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&sigBaseStr);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &url_param, &params, &oauthToken_param, &type_param);

	zephir_get_strval(&url, url_param);
	if (!params) {
		params = &params_sub;
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		ZEPHIR_SEPARATE_PARAM(params);
	}
	if (!oauthToken_param) {
		ZEPHIR_INIT_VAR(&oauthToken);
		ZVAL_STRING(&oauthToken, "");
	} else {
		zephir_get_strval(&oauthToken, oauthToken_param);
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "GET");
	} else {
		zephir_get_strval(&type, type_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("clientId"), PH_NOISY_CC);
	zephir_array_update_string(&_1, SL("oauth_consumer_key"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CALL_FUNCTION(&_4, "rand", NULL, 40);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "uniqid", NULL, 67, &_4, &__$true);
	zephir_check_call_status();
	zephir_md5(&_3, &_5);
	zephir_array_update_string(&_1, SL("oauth_nonce"), &_3, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_1, SL("oauth_signature_method"), SL("HMAC-SHA1"));
	ZEPHIR_INIT_NVAR(&_3);
	zephir_time(&_3);
	zephir_array_update_string(&_1, SL("oauth_timestamp"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("oauth_token"), &oauthToken, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_1, SL("oauth_version"), SL("1.0"));
	zephir_fast_array_merge(&_0, &_1, params TSRMLS_CC);
	ZEPHIR_CPY_WRT(params, &_0);
	ZEPHIR_MAKE_REF(params);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 68, params);
	ZEPHIR_UNREF(params);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "urlencode", &_7, 69, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_8, "http_build_query", NULL, 18, params);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_9, "urlencode", &_7, 69, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sigBaseStr);
	ZEPHIR_CONCAT_VSVSV(&sigBaseStr, &type, "&", &_6, "&", &_9);
	zephir_read_property(&_10, this_ptr, SL("clientSecret"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&key);
	ZEPHIR_CONCAT_VSV(&key, &_10, "&", &oauthToken);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "sha1");
	ZEPHIR_CALL_FUNCTION(&_11, "hash_hmac", NULL, 26, &_0, &sigBaseStr, &key, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_12, "base64_encode", NULL, 14, &_11);
	zephir_check_call_status();
	zephir_array_update_string(params, SL("oauth_signature"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "urlencode");
	ZEPHIR_CALL_FUNCTION(&_13, "array_map", NULL, 48, &_0, params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(params, &_13);
	RETVAL_ZVAL(params, 1, 0);
	RETURN_MM();

}

