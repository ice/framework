
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

// TODO: Deprecated. Will be removed in future
#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "ice.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *ice_i18n_plural_pluralinterface_ce;
zend_class_entry *ice_auth_social_socialinterface_ce;
zend_class_entry *ice_mvc_view_engine_engineinterface_ce;
zend_class_entry *ice_auth_driver_driverinterface_ce;
zend_class_entry *ice_db_dbinterface_ce;
zend_class_entry *ice_log_loggerinterface_ce;
zend_class_entry *ice_mvc_route_datagenerator_datageneratorinterface_ce;
zend_class_entry *ice_mvc_route_dispatcher_dispatcherinterface_ce;
zend_class_entry *ice_http_request_requestinterface_ce;
zend_class_entry *ice_http_response_headersinterface_ce;
zend_class_entry *ice_http_response_responseinterface_ce;
zend_class_entry *ice_mvc_route_parser_parserinterface_ce;
zend_class_entry *ice_mvc_view_viewinterface_ce;
zend_class_entry *ice_mvc_moduleinterface_ce;
zend_class_entry *ice_arr_ce;
zend_class_entry *ice_validation_validator_ce;
zend_class_entry *ice_di_access_ce;
zend_class_entry *ice_mvc_model_ce;
zend_class_entry *ice_auth_social_adapter_ce;
zend_class_entry *ice_config_ce;
zend_class_entry *ice_auth_driver_ce;
zend_class_entry *ice_cli_websocket_websocket_ce;
zend_class_entry *ice_dispatcher_ce;
zend_class_entry *ice_mvc_view_engine_ce;
zend_class_entry *ice_config_ini_ce;
zend_class_entry *ice_log_driver_ce;
zend_class_entry *ice_mvc_route_datagenerator_regex_ce;
zend_class_entry *ice_mvc_route_dispatcher_regex_ce;
zend_class_entry *ice_assets_ce;
zend_class_entry *ice_auth_ce;
zend_class_entry *ice_auth_driver_db_ce;
zend_class_entry *ice_auth_driver_file_ce;
zend_class_entry *ice_auth_driver_model_roles_ce;
zend_class_entry *ice_auth_driver_model_roles_users_ce;
zend_class_entry *ice_auth_driver_model_users_ce;
zend_class_entry *ice_auth_driver_model_users_social_ce;
zend_class_entry *ice_auth_driver_model_users_tokens_ce;
zend_class_entry *ice_auth_social_ce;
zend_class_entry *ice_auth_social_facebook_ce;
zend_class_entry *ice_auth_social_google_ce;
zend_class_entry *ice_auth_social_twitter_ce;
zend_class_entry *ice_cli_console_ce;
zend_class_entry *ice_cli_dispatcher_ce;
zend_class_entry *ice_cli_router_ce;
zend_class_entry *ice_cli_task_ce;
zend_class_entry *ice_cli_websocket_client_ce;
zend_class_entry *ice_cli_websocket_server_ce;
zend_class_entry *ice_config_env_ce;
zend_class_entry *ice_config_json_ce;
zend_class_entry *ice_cookies_ce;
zend_class_entry *ice_crypt_ce;
zend_class_entry *ice_db_ce;
zend_class_entry *ice_db_driver_mongodb_ce;
zend_class_entry *ice_db_driver_pdo_ce;
zend_class_entry *ice_di_ce;
zend_class_entry *ice_dump_ce;
zend_class_entry *ice_exception_ce;
zend_class_entry *ice_filter_ce;
zend_class_entry *ice_filter_css_ce;
zend_class_entry *ice_filter_js_ce;
zend_class_entry *ice_flash_ce;
zend_class_entry *ice_http_request_ce;
zend_class_entry *ice_http_response_ce;
zend_class_entry *ice_http_response_headers_ce;
zend_class_entry *ice_i18n_ce;
zend_class_entry *ice_i18n_plural_arabic_ce;
zend_class_entry *ice_i18n_plural_balkan_ce;
zend_class_entry *ice_i18n_plural_czech_ce;
zend_class_entry *ice_i18n_plural_french_ce;
zend_class_entry *ice_i18n_plural_none_ce;
zend_class_entry *ice_i18n_plural_one_ce;
zend_class_entry *ice_i18n_plural_polish_ce;
zend_class_entry *ice_i18n_plural_romanian_ce;
zend_class_entry *ice_i18n_plural_two_ce;
zend_class_entry *ice_i18n_plural_zero_ce;
zend_class_entry *ice_loader_ce;
zend_class_entry *ice_log_ce;
zend_class_entry *ice_log_driver_file_ce;
zend_class_entry *ice_mvc_app_ce;
zend_class_entry *ice_mvc_controller_ce;
zend_class_entry *ice_mvc_dispatcher_ce;
zend_class_entry *ice_mvc_fastroute_ce;
zend_class_entry *ice_mvc_fastrouter_ce;
zend_class_entry *ice_mvc_route_ce;
zend_class_entry *ice_mvc_route_collector_ce;
zend_class_entry *ice_mvc_route_datagenerator_groupcount_ce;
zend_class_entry *ice_mvc_route_dispatcher_groupcount_ce;
zend_class_entry *ice_mvc_route_parser_std_ce;
zend_class_entry *ice_mvc_router_ce;
zend_class_entry *ice_mvc_service_ce;
zend_class_entry *ice_mvc_url_ce;
zend_class_entry *ice_mvc_view_ce;
zend_class_entry *ice_mvc_view_engine_php_ce;
zend_class_entry *ice_mvc_view_engine_sleet_ce;
zend_class_entry *ice_mvc_view_engine_sleet_compiler_ce;
zend_class_entry *ice_mvc_view_engine_sleet_parser_ce;
zend_class_entry *ice_pagination_ce;
zend_class_entry *ice_session_ce;
zend_class_entry *ice_tag_ce;
zend_class_entry *ice_text_ce;
zend_class_entry *ice_validation_ce;
zend_class_entry *ice_validation_validator_alnum_ce;
zend_class_entry *ice_validation_validator_alpha_ce;
zend_class_entry *ice_validation_validator_between_ce;
zend_class_entry *ice_validation_validator_digit_ce;
zend_class_entry *ice_validation_validator_email_ce;
zend_class_entry *ice_validation_validator_file_ce;
zend_class_entry *ice_validation_validator_in_ce;
zend_class_entry *ice_validation_validator_length_ce;
zend_class_entry *ice_validation_validator_notin_ce;
zend_class_entry *ice_validation_validator_regex_ce;
zend_class_entry *ice_validation_validator_required_ce;
zend_class_entry *ice_validation_validator_same_ce;
zend_class_entry *ice_validation_validator_unique_ce;
zend_class_entry *ice_validation_validator_url_ce;
zend_class_entry *ice_validation_validator_with_ce;
zend_class_entry *ice_validation_validator_without_ce;
zend_class_entry *ice_version_ce;

ZEND_DECLARE_MODULE_GLOBALS(ice)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(ice)
{
// TODO: Deprecated. Will be removed in future
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Ice_I18n_Plural_PluralInterface);
	ZEPHIR_INIT(Ice_Auth_Social_SocialInterface);
	ZEPHIR_INIT(Ice_Mvc_View_Engine_EngineInterface);
	ZEPHIR_INIT(Ice_Auth_Driver_DriverInterface);
	ZEPHIR_INIT(Ice_Db_DbInterface);
	ZEPHIR_INIT(Ice_Log_LoggerInterface);
	ZEPHIR_INIT(Ice_Mvc_Route_DataGenerator_DataGeneratorInterface);
	ZEPHIR_INIT(Ice_Mvc_Route_Dispatcher_DispatcherInterface);
	ZEPHIR_INIT(Ice_Http_Request_RequestInterface);
	ZEPHIR_INIT(Ice_Http_Response_HeadersInterface);
	ZEPHIR_INIT(Ice_Http_Response_ResponseInterface);
	ZEPHIR_INIT(Ice_Mvc_Route_Parser_ParserInterface);
	ZEPHIR_INIT(Ice_Mvc_View_ViewInterface);
	ZEPHIR_INIT(Ice_Mvc_ModuleInterface);
	ZEPHIR_INIT(Ice_Arr);
	ZEPHIR_INIT(Ice_Validation_Validator);
	ZEPHIR_INIT(Ice_Di_Access);
	ZEPHIR_INIT(Ice_Mvc_Model);
	ZEPHIR_INIT(Ice_Auth_Social_Adapter);
	ZEPHIR_INIT(Ice_Config);
	ZEPHIR_INIT(Ice_Auth_Driver);
	ZEPHIR_INIT(Ice_Cli_Websocket_Websocket);
	ZEPHIR_INIT(Ice_Dispatcher);
	ZEPHIR_INIT(Ice_Mvc_View_Engine);
	ZEPHIR_INIT(Ice_Config_Ini);
	ZEPHIR_INIT(Ice_Log_Driver);
	ZEPHIR_INIT(Ice_Mvc_Route_DataGenerator_Regex);
	ZEPHIR_INIT(Ice_Mvc_Route_Dispatcher_Regex);
	ZEPHIR_INIT(Ice_Assets);
	ZEPHIR_INIT(Ice_Auth);
	ZEPHIR_INIT(Ice_Auth_Driver_Db);
	ZEPHIR_INIT(Ice_Auth_Driver_File);
	ZEPHIR_INIT(Ice_Auth_Driver_Model_Roles);
	ZEPHIR_INIT(Ice_Auth_Driver_Model_Roles_Users);
	ZEPHIR_INIT(Ice_Auth_Driver_Model_Users);
	ZEPHIR_INIT(Ice_Auth_Driver_Model_Users_Social);
	ZEPHIR_INIT(Ice_Auth_Driver_Model_Users_Tokens);
	ZEPHIR_INIT(Ice_Auth_Social);
	ZEPHIR_INIT(Ice_Auth_Social_Facebook);
	ZEPHIR_INIT(Ice_Auth_Social_Google);
	ZEPHIR_INIT(Ice_Auth_Social_Twitter);
	ZEPHIR_INIT(Ice_Cli_Console);
	ZEPHIR_INIT(Ice_Cli_Dispatcher);
	ZEPHIR_INIT(Ice_Cli_Router);
	ZEPHIR_INIT(Ice_Cli_Task);
	ZEPHIR_INIT(Ice_Cli_Websocket_Client);
	ZEPHIR_INIT(Ice_Cli_Websocket_Server);
	ZEPHIR_INIT(Ice_Config_Env);
	ZEPHIR_INIT(Ice_Config_Json);
	ZEPHIR_INIT(Ice_Cookies);
	ZEPHIR_INIT(Ice_Crypt);
	ZEPHIR_INIT(Ice_Db);
	ZEPHIR_INIT(Ice_Db_Driver_Mongodb);
	ZEPHIR_INIT(Ice_Db_Driver_Pdo);
	ZEPHIR_INIT(Ice_Di);
	ZEPHIR_INIT(Ice_Dump);
	ZEPHIR_INIT(Ice_Exception);
	ZEPHIR_INIT(Ice_Filter);
	ZEPHIR_INIT(Ice_Filter_Css);
	ZEPHIR_INIT(Ice_Filter_Js);
	ZEPHIR_INIT(Ice_Flash);
	ZEPHIR_INIT(Ice_Http_Request);
	ZEPHIR_INIT(Ice_Http_Response);
	ZEPHIR_INIT(Ice_Http_Response_Headers);
	ZEPHIR_INIT(Ice_I18n);
	ZEPHIR_INIT(Ice_I18n_Plural_Arabic);
	ZEPHIR_INIT(Ice_I18n_Plural_Balkan);
	ZEPHIR_INIT(Ice_I18n_Plural_Czech);
	ZEPHIR_INIT(Ice_I18n_Plural_French);
	ZEPHIR_INIT(Ice_I18n_Plural_None);
	ZEPHIR_INIT(Ice_I18n_Plural_One);
	ZEPHIR_INIT(Ice_I18n_Plural_Polish);
	ZEPHIR_INIT(Ice_I18n_Plural_Romanian);
	ZEPHIR_INIT(Ice_I18n_Plural_Two);
	ZEPHIR_INIT(Ice_I18n_Plural_Zero);
	ZEPHIR_INIT(Ice_Loader);
	ZEPHIR_INIT(Ice_Log);
	ZEPHIR_INIT(Ice_Log_Driver_File);
	ZEPHIR_INIT(Ice_Mvc_App);
	ZEPHIR_INIT(Ice_Mvc_Controller);
	ZEPHIR_INIT(Ice_Mvc_Dispatcher);
	ZEPHIR_INIT(Ice_Mvc_FastRoute);
	ZEPHIR_INIT(Ice_Mvc_FastRouter);
	ZEPHIR_INIT(Ice_Mvc_Route);
	ZEPHIR_INIT(Ice_Mvc_Route_Collector);
	ZEPHIR_INIT(Ice_Mvc_Route_DataGenerator_GroupCount);
	ZEPHIR_INIT(Ice_Mvc_Route_Dispatcher_GroupCount);
	ZEPHIR_INIT(Ice_Mvc_Route_Parser_Std);
	ZEPHIR_INIT(Ice_Mvc_Router);
	ZEPHIR_INIT(Ice_Mvc_Service);
	ZEPHIR_INIT(Ice_Mvc_Url);
	ZEPHIR_INIT(Ice_Mvc_View);
	ZEPHIR_INIT(Ice_Mvc_View_Engine_Php);
	ZEPHIR_INIT(Ice_Mvc_View_Engine_Sleet);
	ZEPHIR_INIT(Ice_Mvc_View_Engine_Sleet_Compiler);
	ZEPHIR_INIT(Ice_Mvc_View_Engine_Sleet_Parser);
	ZEPHIR_INIT(Ice_Pagination);
	ZEPHIR_INIT(Ice_Session);
	ZEPHIR_INIT(Ice_Tag);
	ZEPHIR_INIT(Ice_Text);
	ZEPHIR_INIT(Ice_Validation);
	ZEPHIR_INIT(Ice_Validation_Validator_Alnum);
	ZEPHIR_INIT(Ice_Validation_Validator_Alpha);
	ZEPHIR_INIT(Ice_Validation_Validator_Between);
	ZEPHIR_INIT(Ice_Validation_Validator_Digit);
	ZEPHIR_INIT(Ice_Validation_Validator_Email);
	ZEPHIR_INIT(Ice_Validation_Validator_File);
	ZEPHIR_INIT(Ice_Validation_Validator_In);
	ZEPHIR_INIT(Ice_Validation_Validator_Length);
	ZEPHIR_INIT(Ice_Validation_Validator_NotIn);
	ZEPHIR_INIT(Ice_Validation_Validator_Regex);
	ZEPHIR_INIT(Ice_Validation_Validator_Required);
	ZEPHIR_INIT(Ice_Validation_Validator_Same);
	ZEPHIR_INIT(Ice_Validation_Validator_Unique);
	ZEPHIR_INIT(Ice_Validation_Validator_Url);
	ZEPHIR_INIT(Ice_Validation_Validator_With);
	ZEPHIR_INIT(Ice_Validation_Validator_Without);
	ZEPHIR_INIT(Ice_Version);
	

// TODO: Deprecated. Will be removed in future
#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(ice)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_ice_globals *ice_globals TSRMLS_DC)
{
	ice_globals->initialized = 0;

	/* Memory options */
	ice_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	ice_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	ice_globals->cache_enabled = 1;

	/* Recursive Lock */
	ice_globals->recursive_lock = 0;

	/* Static cache */
	memset(ice_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_ice_globals *ice_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(ice)
{
	zend_ice_globals *ice_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(ice_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);
	zephir_initialize_memory(ice_globals_ptr TSRMLS_CC);

		zephir_init_static_properties_Ice_Cli_Websocket_Websocket(TSRMLS_C);
	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(ice)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(ice)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_ICE_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_ICE_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_ICE_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_ICE_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_ICE_ZEPVERSION);
	php_info_print_table_end();
		php_info_print_table_start();
	php_info_print_table_row(2, "Website", "http://www.iceframework.org");
	php_info_print_table_row(2, "Email", "info@iceframework.org");
	php_info_print_table_row(2, "FreeNode", "#iceframework");
	php_info_print_table_row(2, "Twitter, Packagist", "iceframework");
	php_info_print_table_row(2, "GitHub", "ice");
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(ice)
{
	php_zephir_init_globals(ice_globals TSRMLS_CC);
	php_zephir_init_module_globals(ice_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(ice)
{
	
}

PHP_FUNCTION(g_ice__t);
ZEND_BEGIN_ARG_INFO_EX(arginfo_g_ice__t, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_ARRAY_INFO(0, values, 1)
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_INFO(0, lang)
ZEND_END_ARG_INFO()


zend_function_entry php_ice_functions[] = {
	ZEND_NAMED_FE(_t, ZEND_FN(g_ice__t), arginfo_g_ice__t)
ZEND_FE_END

};

zend_module_entry ice_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_ICE_EXTNAME,
	php_ice_functions,
	PHP_MINIT(ice),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(ice),
#else
	NULL,
#endif
	PHP_RINIT(ice),
	PHP_RSHUTDOWN(ice),
	PHP_MINFO(ice),
	PHP_ICE_VERSION,
	ZEND_MODULE_GLOBALS(ice),
	PHP_GINIT(ice),
	PHP_GSHUTDOWN(ice),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(ice),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_ICE
ZEND_GET_MODULE(ice)
#endif
