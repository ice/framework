
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "ice.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *ice_mvc_route_datagenerator_datageneratorinterface_ce;
zend_class_entry *ice_mvc_view_engine_engineinterface_ce;
zend_class_entry *ice_auth_driver_driverinterface_ce;
zend_class_entry *ice_db_dbinterface_ce;
zend_class_entry *ice_log_loggerinterface_ce;
zend_class_entry *ice_di_diinterface_ce;
zend_class_entry *ice_http_response_headersinterface_ce;
zend_class_entry *ice_http_response_responseinterface_ce;
zend_class_entry *ice_mvc_route_dispatcher_dispatcherinterface_ce;
zend_class_entry *ice_mvc_route_parser_parserinterface_ce;
zend_class_entry *ice_mvc_view_viewinterface_ce;
zend_class_entry *ice_http_request_requestinterface_ce;
zend_class_entry *ice_mvc_moduleinterface_ce;
zend_class_entry *ice_arr_ce;
zend_class_entry *ice_validation_validator_ce;
zend_class_entry *ice_di_access_ce;
zend_class_entry *ice_mvc_model_ce;
zend_class_entry *ice_auth_driver_ce;
zend_class_entry *ice_dispatcher_ce;
zend_class_entry *ice_mvc_view_engine_ce;
zend_class_entry *ice_config_ce;
zend_class_entry *ice_log_driver_ce;
zend_class_entry *ice_mvc_route_datagenerator_regex_ce;
zend_class_entry *ice_auth_ce;
zend_class_entry *ice_auth_driver_file_ce;
zend_class_entry *ice_auth_driver_model_ce;
zend_class_entry *ice_auth_driver_model_roles_ce;
zend_class_entry *ice_auth_driver_model_roles_users_ce;
zend_class_entry *ice_auth_driver_model_users_ce;
zend_class_entry *ice_auth_driver_model_users_tokens_ce;
zend_class_entry *ice_cli_console_ce;
zend_class_entry *ice_cli_dispatcher_ce;
zend_class_entry *ice_cli_router_ce;
zend_class_entry *ice_cli_task_ce;
zend_class_entry *ice_config_ini_ce;
zend_class_entry *ice_cookies_ce;
zend_class_entry *ice_crypt_ce;
zend_class_entry *ice_db_ce;
zend_class_entry *ice_db_driver_mongo_ce;
zend_class_entry *ice_db_driver_pdo_ce;
zend_class_entry *ice_di_ce;
zend_class_entry *ice_dump_ce;
zend_class_entry *ice_exception_ce;
zend_class_entry *ice_filter_ce;
zend_class_entry *ice_flash_ce;
zend_class_entry *ice_http_request_ce;
zend_class_entry *ice_http_response_ce;
zend_class_entry *ice_http_response_headers_ce;
zend_class_entry *ice_i18n_ce;
zend_class_entry *ice_loader_ce;
zend_class_entry *ice_log_ce;
zend_class_entry *ice_log_driver_file_ce;
zend_class_entry *ice_mvc_app_ce;
zend_class_entry *ice_mvc_controller_ce;
zend_class_entry *ice_mvc_dispatcher_ce;
zend_class_entry *ice_mvc_route_ce;
zend_class_entry *ice_mvc_route_collector_ce;
zend_class_entry *ice_mvc_route_datagenerator_groupcount_ce;
zend_class_entry *ice_mvc_route_dispatcher_groupcount_ce;
zend_class_entry *ice_mvc_route_parser_std_ce;
zend_class_entry *ice_mvc_router_ce;
zend_class_entry *ice_mvc_url_ce;
zend_class_entry *ice_mvc_view_ce;
zend_class_entry *ice_mvc_view_engine_php_ce;
zend_class_entry *ice_mvc_view_engine_sleet_ce;
zend_class_entry *ice_mvc_view_engine_sleet_compiler_ce;
zend_class_entry *ice_mvc_view_engine_sleet_parser_ce;
zend_class_entry *ice_session_ce;
zend_class_entry *ice_tag_ce;
zend_class_entry *ice_text_ce;
zend_class_entry *ice_validation_ce;
zend_class_entry *ice_validation_validator_alnum_ce;
zend_class_entry *ice_validation_validator_alpha_ce;
zend_class_entry *ice_validation_validator_between_ce;
zend_class_entry *ice_validation_validator_digit_ce;
zend_class_entry *ice_validation_validator_email_ce;
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

#define ZEPHIR_NUM_PREALLOCATED_FRAMES 25

void zephir_initialize_memory(zend_zephir_globals_def *zephir_globals_ptr TSRMLS_DC)
{
	zephir_memory_entry *start;
	size_t i;

	start = (zephir_memory_entry *) pecalloc(ZEPHIR_NUM_PREALLOCATED_FRAMES, sizeof(zephir_memory_entry), 1);
/* pecalloc() will take care of these members for every frame
	start->pointer      = 0;
	start->hash_pointer = 0;
	start->prev = NULL;
	start->next = NULL;
*/
	for (i = 0; i < ZEPHIR_NUM_PREALLOCATED_FRAMES; ++i) {
		start[i].addresses       = pecalloc(24, sizeof(zval*), 1);
		start[i].capacity        = 24;
		start[i].hash_addresses  = pecalloc(8, sizeof(zval*), 1);
		start[i].hash_capacity   = 8;

#ifndef ZEPHIR_RELEASE
		start[i].permanent = 1;
#endif
	}

	start[0].next = &start[1];
	start[ZEPHIR_NUM_PREALLOCATED_FRAMES - 1].prev = &start[ZEPHIR_NUM_PREALLOCATED_FRAMES - 2];

	for (i = 1; i < ZEPHIR_NUM_PREALLOCATED_FRAMES - 1; ++i) {
		start[i].next = &start[i + 1];
		start[i].prev = &start[i - 1];
	}

	zephir_globals_ptr->start_memory = start;
	zephir_globals_ptr->end_memory   = start + ZEPHIR_NUM_PREALLOCATED_FRAMES;

	zephir_globals_ptr->fcache = pemalloc(sizeof(HashTable), 1);
	zend_hash_init(zephir_globals_ptr->fcache, 128, NULL, NULL, 1); // zephir_fcall_cache_dtor

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_null);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_null, 2);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_false);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_false, 2);
	ZVAL_FALSE(zephir_globals_ptr->global_false);

	/* 'Allocator sizeof operand mismatch' warning can be safely ignored */
	ALLOC_INIT_ZVAL(zephir_globals_ptr->global_true);
	Z_SET_REFCOUNT_P(zephir_globals_ptr->global_true, 2);
	ZVAL_TRUE(zephir_globals_ptr->global_true);

	zephir_globals_ptr->initialized = 1;
}

/**
 * Cleans the function/method cache up
 */
int zephir_cleanup_fcache(void *pDest TSRMLS_DC, int num_args, va_list args, zend_hash_key *hash_key)
{
	zephir_fcall_cache_entry **entry = (zephir_fcall_cache_entry**) pDest;
	zend_class_entry *scope;
	uint len = hash_key->nKeyLength;

	assert(hash_key->arKey != NULL);
	assert(hash_key->nKeyLength > 2 * sizeof(zend_class_entry**));

	memcpy(&scope, &hash_key->arKey[len - 2 * sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

/*
#ifndef PHALCON_RELEASE
	{
		zend_class_entry *cls;
		memcpy(&cls, &hash_key->arKey[len - sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

		fprintf(stderr, "func: %s, cls: %s, scope: %s [%u]\n", (*entry)->f->common.function_name, (cls ? cls->name : "N/A"), (scope ? scope->name : "N/A"), (uint)(*entry)->times);
	}
#endif
*/

#ifndef ZEPHIR_RELEASE
	if ((*entry)->f->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if ((*entry)->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

#if PHP_VERSION_ID >= 50400
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->info.internal.module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

	return ZEND_HASH_APPLY_KEEP;
}

void zephir_deinitialize_memory(TSRMLS_D)
{
	size_t i;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	if (zephir_globals_ptr->initialized != 1) {
		zephir_globals_ptr->initialized = 0;
		return;
	}

	if (zephir_globals_ptr->start_memory != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	zend_hash_apply_with_arguments(zephir_globals_ptr->fcache TSRMLS_CC, zephir_cleanup_fcache, 0);

#ifndef ZEPHIR_RELEASE
	assert(zephir_globals_ptr->start_memory != NULL);
#endif

	for (i = 0; i < ZEPHIR_NUM_PREALLOCATED_FRAMES; ++i) {
		pefree(zephir_globals_ptr->start_memory[i].hash_addresses, 1);
		pefree(zephir_globals_ptr->start_memory[i].addresses, 1);
	}

	pefree(zephir_globals_ptr->start_memory, 1);
	zephir_globals_ptr->start_memory = NULL;

	zend_hash_destroy(zephir_globals_ptr->fcache);
	pefree(zephir_globals_ptr->fcache, 1);
	zephir_globals_ptr->fcache = NULL;

	for (i = 0; i < 2; i++) {
		zval_ptr_dtor(&zephir_globals_ptr->global_null);
		zval_ptr_dtor(&zephir_globals_ptr->global_false);
		zval_ptr_dtor(&zephir_globals_ptr->global_true);
	}

	zephir_globals_ptr->initialized = 0;
}

static PHP_MINIT_FUNCTION(ice)
{
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

	ZEPHIR_INIT(Ice_Mvc_Route_DataGenerator_DataGeneratorInterface);
	ZEPHIR_INIT(Ice_Mvc_View_Engine_EngineInterface);
	ZEPHIR_INIT(Ice_Auth_Driver_DriverInterface);
	ZEPHIR_INIT(Ice_Db_DbInterface);
	ZEPHIR_INIT(Ice_Log_LoggerInterface);
	ZEPHIR_INIT(Ice_Di_DiInterface);
	ZEPHIR_INIT(Ice_Http_Response_HeadersInterface);
	ZEPHIR_INIT(Ice_Http_Response_ResponseInterface);
	ZEPHIR_INIT(Ice_Mvc_Route_Dispatcher_DispatcherInterface);
	ZEPHIR_INIT(Ice_Mvc_Route_Parser_ParserInterface);
	ZEPHIR_INIT(Ice_Mvc_View_ViewInterface);
	ZEPHIR_INIT(Ice_Http_Request_RequestInterface);
	ZEPHIR_INIT(Ice_Mvc_ModuleInterface);
	ZEPHIR_INIT(Ice_Arr);
	ZEPHIR_INIT(Ice_Validation_Validator);
	ZEPHIR_INIT(Ice_Di_Access);
	ZEPHIR_INIT(Ice_Mvc_Model);
	ZEPHIR_INIT(Ice_Auth_Driver);
	ZEPHIR_INIT(Ice_Dispatcher);
	ZEPHIR_INIT(Ice_Mvc_View_Engine);
	ZEPHIR_INIT(Ice_Config);
	ZEPHIR_INIT(Ice_Log_Driver);
	ZEPHIR_INIT(Ice_Mvc_Route_DataGenerator_Regex);
	ZEPHIR_INIT(Ice_Auth);
	ZEPHIR_INIT(Ice_Auth_Driver_File);
	ZEPHIR_INIT(Ice_Auth_Driver_Model);
	ZEPHIR_INIT(Ice_Auth_Driver_Model_Roles);
	ZEPHIR_INIT(Ice_Auth_Driver_Model_Roles_Users);
	ZEPHIR_INIT(Ice_Auth_Driver_Model_Users);
	ZEPHIR_INIT(Ice_Auth_Driver_Model_Users_Tokens);
	ZEPHIR_INIT(Ice_Cli_Console);
	ZEPHIR_INIT(Ice_Cli_Dispatcher);
	ZEPHIR_INIT(Ice_Cli_Router);
	ZEPHIR_INIT(Ice_Cli_Task);
	ZEPHIR_INIT(Ice_Config_Ini);
	ZEPHIR_INIT(Ice_Cookies);
	ZEPHIR_INIT(Ice_Crypt);
	ZEPHIR_INIT(Ice_Db);
	ZEPHIR_INIT(Ice_Db_Driver_Mongo);
	ZEPHIR_INIT(Ice_Db_Driver_Pdo);
	ZEPHIR_INIT(Ice_Di);
	ZEPHIR_INIT(Ice_Dump);
	ZEPHIR_INIT(Ice_Exception);
	ZEPHIR_INIT(Ice_Filter);
	ZEPHIR_INIT(Ice_Flash);
	ZEPHIR_INIT(Ice_Http_Request);
	ZEPHIR_INIT(Ice_Http_Response);
	ZEPHIR_INIT(Ice_Http_Response_Headers);
	ZEPHIR_INIT(Ice_I18n);
	ZEPHIR_INIT(Ice_Loader);
	ZEPHIR_INIT(Ice_Log);
	ZEPHIR_INIT(Ice_Log_Driver_File);
	ZEPHIR_INIT(Ice_Mvc_App);
	ZEPHIR_INIT(Ice_Mvc_Controller);
	ZEPHIR_INIT(Ice_Mvc_Dispatcher);
	ZEPHIR_INIT(Ice_Mvc_Route);
	ZEPHIR_INIT(Ice_Mvc_Route_Collector);
	ZEPHIR_INIT(Ice_Mvc_Route_DataGenerator_GroupCount);
	ZEPHIR_INIT(Ice_Mvc_Route_Dispatcher_GroupCount);
	ZEPHIR_INIT(Ice_Mvc_Route_Parser_Std);
	ZEPHIR_INIT(Ice_Mvc_Router);
	ZEPHIR_INIT(Ice_Mvc_Url);
	ZEPHIR_INIT(Ice_Mvc_View);
	ZEPHIR_INIT(Ice_Mvc_View_Engine_Php);
	ZEPHIR_INIT(Ice_Mvc_View_Engine_Sleet);
	ZEPHIR_INIT(Ice_Mvc_View_Engine_Sleet_Compiler);
	ZEPHIR_INIT(Ice_Mvc_View_Engine_Sleet_Parser);
	ZEPHIR_INIT(Ice_Session);
	ZEPHIR_INIT(Ice_Tag);
	ZEPHIR_INIT(Ice_Text);
	ZEPHIR_INIT(Ice_Validation);
	ZEPHIR_INIT(Ice_Validation_Validator_Alnum);
	ZEPHIR_INIT(Ice_Validation_Validator_Alpha);
	ZEPHIR_INIT(Ice_Validation_Validator_Between);
	ZEPHIR_INIT(Ice_Validation_Validator_Digit);
	ZEPHIR_INIT(Ice_Validation_Validator_Email);
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

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_ice_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
#if PHP_VERSION_ID < 50600
	zephir_globals->cache_enabled = 1;
#else
	zephir_globals->cache_enabled = 0;
#endif

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(ice)
{

	zend_ice_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

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
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_ICE_ZEPVERSION);
	php_info_print_table_end();

	php_info_print_table_start();
	php_info_print_table_row(2, "Website", "http://www.iceframework.org");
	php_info_print_table_row(2, "Email", "info@iceframework.org");
	php_info_print_table_row(2, "FreeNode", "#iceframework");
	php_info_print_table_row(2, "Twitter", "iceframework");
	php_info_print_table_row(2, "Github", "ice");
	php_info_print_table_end();

}

static PHP_GINIT_FUNCTION(ice)
{
	php_zephir_init_globals(ice_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(ice)
{

}

zend_module_entry ice_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_ICE_EXTNAME,
	NULL,
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
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_ICE
ZEND_GET_MODULE(ice)
#endif
