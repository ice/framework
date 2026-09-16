
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * This component allows to create CLI applications.
 *
 * @package     Ice/Cli
 * @category    Application
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Console)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Cli, Console, ice, cli_console, ice_di_access_ce, ice_cli_console_method_entry, 0);

	zend_declare_property_null(ice_cli_console_ce, SL("modules"), ZEND_ACC_PROTECTED);
	zephir_declare_class_constant_long(ice_cli_console_ce, SL("NORMAL"), 0);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BOLD_BRIGHT"), 1);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("UNDERLINE"), 4);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("INVERSE"), 7);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BLACK"), 30);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("RED"), 31);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("GREEN"), 32);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("YELLOW"), 33);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BLUE"), 34);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("MAGENTA"), 35);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("CYAN"), 36);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("LIGHTGRAY"), 37);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("WHITE"), 97);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BG_BLACK"), 40);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BG_RED"), 41);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BG_GREEN"), 42);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BG_YELLOW"), 43);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BG_BLUE"), 44);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BG_MAGENTA"), 45);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BG_CYAN"), 46);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BG_LIGHTGRAY"), 47);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BG_WHITE"), 107);

	return SUCCESS;
}

PHP_METHOD(Ice_Cli_Console, getModules)
{

	RETURN_MEMBER(getThis(), "modules");
}

PHP_METHOD(Ice_Cli_Console, setModules)
{
	zval *modules, modules_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modules_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modules", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(modules)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &modules);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 110, modules);
	RETURN_THISW();
}

/**
 * Console constructor
 *
 * @param Di $di
 */
PHP_METHOD(Ice_Cli_Console, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di = NULL, di_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("di", 2, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(di, ice_di_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &di);
	if (!di) {
		di = &di_sub;
		di = &__$null;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 111, di);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 111, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "console");
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_1, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Add module with its dir path, initial class name and namespace
 *
 * @param string name
 * @param array options The keys can be [path|class|namespace]
 * @return object Console
 */
PHP_METHOD(Ice_Cli_Console, addModule)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zval name_zv, *options_param = NULL;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	options_param = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_get_arrval(&options, options_param);
	zephir_update_property_array(this_ptr, SL("modules"), &name_zv, &options);
	RETURN_THIS();
}

/**
 * Handle an command-line request.
 *
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Ice_Cli_Console, handle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, arguments_sub, __$null, router, response, dispatcher, _0, _1, _2, _3, _4, _5, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("di", 2, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("modules", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &arguments);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 111, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "router");
	ZEPHIR_CALL_METHOD(&router, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &router, "handle", NULL, 0, arguments);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 111, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "dispatcher");
	ZEPHIR_CALL_METHOD(&dispatcher, &_2, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 110, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodules", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_memory_observe(&_4);
	zephir_array_fetch_string(&_4, &response, SL("module"), PH_NOISY, "ice/cli/console.zep", 89);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodule", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_memory_observe(&_5);
	zephir_array_fetch_string(&_5, &response, SL("handler"), PH_NOISY, "ice/cli/console.zep", 90);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "sethandler", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_memory_observe(&_6);
	zephir_array_fetch_string(&_6, &response, SL("action"), PH_NOISY, "ice/cli/console.zep", 91);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setaction", NULL, 0, &_6);
	zephir_check_call_status();
	zephir_memory_observe(&_7);
	zephir_array_fetch_string(&_7, &response, SL("params"), PH_NOISY, "ice/cli/console.zep", 92);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setparams", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&response);
}

/**
 * Returns the given text with the correct color codes for a foreground and optionally a background color.
 *
 * @param string text The text to color
 * @param int color The foreground color
 * @param int decoration Formatting type
 * @param int bgColor The background color
 * @return string Coded string
 */
PHP_METHOD(Ice_Cli_Console, color)
{
	zval _3$$3;
	zend_bool colors;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long color, decoration, bgColor;
	zval text_zv, *color_param = NULL, *decoration_param = NULL, *bgColor_param = NULL, colored, e, _0$$3, _1$$3, _2$$3, _4$$4, _5$$4;
	zend_string *text = NULL;

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&colored);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_3$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(color, is_null_true)
		Z_PARAM_LONG(decoration)
		Z_PARAM_LONG_OR_NULL(bgColor, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		color_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		decoration_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		bgColor_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!color_param) {
		color = 0;
	} else {
		}
	if (!decoration_param) {
		decoration = 0;
	} else {
		}
	if (!bgColor_param) {
		bgColor = 0;
	} else {
		}
	colors = ZEPHIR_GLOBAL(cli_colors);
	if (colors) {
		ZEPHIR_INIT_VAR(&e);
		ZVAL_STRING(&e, "\033");
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_LONG(&_0$$3, decoration);
		ZEPHIR_INIT_VAR(&_1$$3);
		if (color) {
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_LONG(&_2$$3, color);
			ZEPHIR_INIT_VAR(&_3$$3);
			ZEPHIR_CONCAT_SV(&_3$$3, ";", &_2$$3);
			ZEPHIR_CPY_WRT(&_1$$3, &_3$$3);
		} else {
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "");
		}
		ZEPHIR_INIT_VAR(&colored);
		ZEPHIR_CONCAT_VSVVS(&colored, &e, "[", &_0$$3, &_1$$3, "m");
		if (bgColor) {
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_LONG(&_4$$4, bgColor);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_CONCAT_VSVS(&_5$$4, &e, "[", &_4$$4, "m");
			zephir_concat_self(&colored, &_5$$4);
		}
		ZEPHIR_CONCAT_VVVS(return_value, &colored, &text_zv, &e, "[0m");
		RETURN_MM();
	} else {
		RETURN_MM_STR(zend_string_copy(text));
	}
}

/**
 * Returns info text.
 *
 * @param string text
 * @return string
 */
PHP_METHOD(Ice_Cli_Console, info)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, _0;
	zend_string *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZVAL_LONG(&_0, 36);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "color", NULL, 0, &text_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns success text.
 *
 * @param string text
 * @return string
 */
PHP_METHOD(Ice_Cli_Console, success)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, _0;
	zend_string *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZVAL_LONG(&_0, 32);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "color", NULL, 0, &text_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns warning text.
 *
 * @param string text
 * @return string
 */
PHP_METHOD(Ice_Cli_Console, warning)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, _0;
	zend_string *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZVAL_LONG(&_0, 33);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "color", NULL, 0, &text_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns error text.
 *
 * @param string text
 * @return string
 */
PHP_METHOD(Ice_Cli_Console, error)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, _0;
	zend_string *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZVAL_LONG(&_0, 31);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "color", NULL, 0, &text_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

