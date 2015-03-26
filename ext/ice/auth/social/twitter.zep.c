
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/time.h"


/**
 * Twitter Auth social adapter.
 *
 * @package     Ice/Auth
 * @category    Adapter
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
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

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *config = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "twitter", 1);
	zephir_update_property_this(this_ptr, SL("_provider"), _0 TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, ice_auth_social_twitter_ce, this_ptr, "__construct", &_1, config);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 7);
	add_assoc_stringl_ex(_2, SS("socialId"), SL("id"), 1);
	add_assoc_stringl_ex(_2, SS("email"), SL("email"), 1);
	add_assoc_stringl_ex(_2, SS("name"), SL("name"), 1);
	add_assoc_stringl_ex(_2, SS("sex"), SL("sex"), 1);
	add_assoc_stringl_ex(_2, SS("birthday"), SL("bdate"), 1);
	zephir_update_property_this(this_ptr, SL("_socialFieldsMap"), _2 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "oauth_token", 1);
	zephir_update_property_this(this_ptr, SL("_responseType"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get user social id or null if it is not set.
 *
 * @return string|null
 */
PHP_METHOD(Ice_Auth_Social_Twitter, getSocialPage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "screen_name", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "screen_name", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "get", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SV(return_value, "http://twitter.com/", _2);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "profile_image_url", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "profile_image_url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "get", NULL, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_fast_explode_str(_1, SL("_normal"), _2, LONG_MAX TSRMLS_CC);
		zephir_fast_join_str(return_value, SL(""), _1 TSRMLS_CC);
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

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, *accessTokenUrl, *accessTokens = NULL, *getDataUrl, *userInfo = NULL, *_GET, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_5, *_7;
	zend_bool result, _0;

	ZEPHIR_MM_GROW();

	result = 0;
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	_0 = zephir_array_isset_string(_GET, SS("oauth_token"));
	if (_0) {
		_0 = zephir_array_isset_string(_GET, SS("oauth_verifier"));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(params);
		array_init_size(params, 3);
		ZEPHIR_OBS_VAR(_1);
		zephir_array_fetch_string(&_1, _GET, SL("oauth_token"), PH_NOISY, "ice/auth/social/twitter.zep", 78 TSRMLS_CC);
		zephir_array_update_string(&params, SL("oauth_token"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_1);
		zephir_array_fetch_string(&_1, _GET, SL("oauth_verifier"), PH_NOISY, "ice/auth/social/twitter.zep", 80 TSRMLS_CC);
		zephir_array_update_string(&params, SL("oauth_verifier"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(accessTokenUrl);
		ZVAL_STRING(accessTokenUrl, "https://api.twitter.com/oauth/access_token", 1);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "prepareurlparams", &_3, accessTokenUrl, params);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(params, _2);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 0);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_BOOL(_5, 0);
		ZEPHIR_CALL_METHOD(&accessTokens, this_ptr, "call", NULL, _4, accessTokenUrl, params, _5);
		zephir_check_call_status();
		Z_SET_ISREF_P(accessTokens);
		ZEPHIR_CALL_FUNCTION(NULL, "parse_str", &_6, accessTokens, accessTokens);
		Z_UNSET_ISREF_P(accessTokens);
		zephir_check_call_status();
		if (zephir_array_isset_string(accessTokens, SS("oauth_token"))) {
			ZEPHIR_INIT_VAR(getDataUrl);
			ZVAL_STRING(getDataUrl, "https://api.twitter.com/1.1/users/show.json", 1);
			ZEPHIR_INIT_NVAR(params);
			array_init_size(params, 4);
			ZEPHIR_OBS_NVAR(_1);
			zephir_array_fetch_string(&_1, accessTokens, SL("oauth_token"), PH_NOISY, "ice/auth/social/twitter.zep", 91 TSRMLS_CC);
			zephir_array_update_string(&params, SL("oauth_token"), &_1, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_1);
			zephir_array_fetch_string(&_1, accessTokens, SL("screen_name"), PH_NOISY, "ice/auth/social/twitter.zep", 92 TSRMLS_CC);
			zephir_array_update_string(&params, SL("screen_name"), &_1, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(params, SS("include_entities"), SL("false"), 1);
			zephir_array_fetch_string(&_7, accessTokens, SL("oauth_token_secret"), PH_NOISY | PH_READONLY, "ice/auth/social/twitter.zep", 95 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "prepareurlparams", &_3, getDataUrl, params, _7);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(params, _2);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_LONG(_4, 0);
			ZEPHIR_CALL_METHOD(&userInfo, this_ptr, "call", NULL, _4, getDataUrl, params);
			zephir_check_call_status();
			if (zephir_array_isset_string(userInfo, SS("id"))) {
				zephir_update_property_this(this_ptr, SL("_userInfo"), userInfo TSRMLS_CC);
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

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_6;
	zval *requestTokenUrl, *requestTokens = NULL, *params = NULL, *_1, *_3, *_4, *_7 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(requestTokenUrl);
	ZVAL_STRING(requestTokenUrl, "https://api.twitter.com/oauth/request_token", 1);
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_redirectUri"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("oauth_callback"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&params, this_ptr, "prepareurlparams", &_2, requestTokenUrl, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, 0);
	ZEPHIR_CALL_METHOD(&requestTokens, this_ptr, "call", NULL, _3, requestTokenUrl, params, _4);
	zephir_check_call_status();
	Z_SET_ISREF_P(requestTokens);
	ZEPHIR_CALL_FUNCTION(NULL, "parse_str", &_5, requestTokens, requestTokens);
	Z_UNSET_ISREF_P(requestTokens);
	zephir_check_call_status();
	array_init_size(return_value, 3);
	add_assoc_stringl_ex(return_value, SS("auth_url"), SL("https://api.twitter.com/oauth/authenticate"), 1);
	ZEPHIR_INIT_VAR(_6);
	array_init_size(_6, 2);
	ZEPHIR_INIT_VAR(_7);
	if (zephir_array_isset_string(requestTokens, SS("oauth_token"))) {
		ZEPHIR_OBS_NVAR(_7);
		zephir_array_fetch_string(&_7, requestTokens, SL("oauth_token"), PH_NOISY, "ice/auth/social/twitter.zep", 124 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_NULL(_7);
	}
	zephir_array_update_string(&_6, SL("oauth_token"), &_7, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("auth_params"), &_6, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Prepare url-params with signature.
 *
 * @return array
 */
PHP_METHOD(Ice_Auth_Social_Twitter, prepareUrlParams) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL, *_18 = NULL, *_20 = NULL;
	zval *_1;
	zval *url_param = NULL, *params = NULL, *oauthToken_param = NULL, *type_param = NULL, *sigBaseStr, *key, *_0, *_2, *_3 = NULL, *_4 = NULL, *_6 = NULL, *_9 = NULL, *_11 = NULL, *_13 = NULL, *_14, _15 = zval_used_for_init, *_16 = NULL, *_17 = NULL, *_19 = NULL;
	zval *url = NULL, *oauthToken = NULL, *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &url_param, &params, &oauthToken_param, &type_param);

	zephir_get_strval(url, url_param);
	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		ZEPHIR_SEPARATE_PARAM(params);
	}
	if (!oauthToken_param) {
		ZEPHIR_INIT_VAR(oauthToken);
		ZVAL_STRING(oauthToken, "", 1);
	} else {
		zephir_get_strval(oauthToken, oauthToken_param);
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "GET", 1);
	} else {
		zephir_get_strval(type, type_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 8);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("_clientId"), PH_NOISY_CC);
	zephir_array_update_string(&_1, SL("oauth_consumer_key"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CALL_FUNCTION(&_4, "rand", &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "uniqid", &_7, _4, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zephir_md5(_3, _6);
	zephir_array_update_string(&_1, SL("oauth_nonce"), &_3, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_1, SS("oauth_signature_method"), SL("HMAC-SHA1"), 1);
	ZEPHIR_INIT_NVAR(_3);
	zephir_time(_3);
	zephir_array_update_string(&_1, SL("oauth_timestamp"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("oauth_token"), &oauthToken, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_1, SS("oauth_version"), SL("1.0"), 1);
	zephir_fast_array_merge(_0, &(_1), &(params) TSRMLS_CC);
	ZEPHIR_CPY_WRT(params, _0);
	Z_SET_ISREF_P(params);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", &_8, params);
	Z_UNSET_ISREF_P(params);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_9, "urlencode", &_10, url);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_11, "http_build_query", &_12, params);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_13, "urlencode", &_10, _11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sigBaseStr);
	ZEPHIR_CONCAT_VSVSV(sigBaseStr, type, "&", _9, "&", _13);
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("_clientSecret"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(key);
	ZEPHIR_CONCAT_VSV(key, _14, "&", oauthToken);
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_STRING(&_15, "sha1", 0);
	ZEPHIR_CALL_FUNCTION(&_16, "hash_hmac", NULL, &_15, sigBaseStr, key, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_17, "base64_encode", &_18, _16);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("oauth_signature"), &_17, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_NVAR(_15);
	ZVAL_STRING(&_15, "urlencode", 0);
	ZEPHIR_CALL_FUNCTION(&_19, "array_map", &_20, &_15, params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(params, _19);
	RETVAL_ZVAL(params, 1, 0);
	RETURN_MM();

}

