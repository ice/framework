
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Console) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Cli, Console, ice, cli_console, ice_di_access_ce, ice_cli_console_method_entry, 0);

	zend_declare_property_null(ice_cli_console_ce, SL("modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(ice_cli_console_ce, SL("NORMAL"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_cli_console_ce, SL("BOLD_BRIGHT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_cli_console_ce, SL("UNDERLINE"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(ice_cli_console_ce, SL("INVERSE"), 7 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Cli_Console, getModules) {

	

	RETURN_MEMBER(getThis(), "modules");

}

PHP_METHOD(Ice_Cli_Console, setModules) {

	zval *modules;

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_this(getThis(), SL("modules"), modules TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Console constructor
 *
 * @param Di $di
 */
PHP_METHOD(Ice_Cli_Console, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &di);

	if (!di) {
		di = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(getThis(), SL("di"), di TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "console", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, _1, this_ptr);
	zephir_check_temp_parameter(_1);
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
PHP_METHOD(Ice_Cli_Console, addModule) {

	zval *options = NULL;
	zval *name_param = NULL, *options_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &options_param);

	zephir_get_strval(name, name_param);
	zephir_get_arrval(options, options_param);


	zephir_update_property_array(this_ptr, SL("modules"), name, options TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Handle an command-line request.
 *
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Ice_Cli_Console, handle) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, *router = NULL, *response = NULL, *dispatcher = NULL, *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&router, _0, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, router, "handle", NULL, 0, arguments);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&dispatcher, _2, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodules", NULL, 0, _3);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, response, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 70 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodule", NULL, 0, _4);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, response, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 71 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "sethandler", NULL, 0, _5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_6, response, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 72 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setaction", NULL, 0, _6);
	zephir_check_call_status();
	zephir_array_fetch_string(&_7, response, SL("params"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 73 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, 0, _7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(response);

}

/**
 * Returns the given text with the correct color codes for a foreground and optionally a background color.
 * Colors: black, red, green, yellow, blue, magenta, cyan, lightgray, white*
 *
 * @param string text The text to color
 * @param string color The foreground color
 * @param int decoration Formatting type
 * @param string bgColor The background color
 * @return string Coded string
 */
PHP_METHOD(Ice_Cli_Console, color) {

	zend_long decoration;
	zval *text_param = NULL, *color_param = NULL, *decoration_param = NULL, *bgColor_param = NULL, *colors = NULL, *bgColors = NULL, *colored = NULL, *e = NULL, *foreground = NULL, *background = NULL, _0, *_1 = NULL, *_2$$3;
	zval *text = NULL, *color = NULL, *bgColor = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &color_param, &decoration_param, &bgColor_param);

	zephir_get_strval(text, text_param);
	if (!color_param) {
		ZEPHIR_INIT_VAR(color);
		ZVAL_EMPTY_STRING(color);
	} else {
		zephir_get_strval(color, color_param);
	}
	if (!decoration_param) {
		decoration = 0;
	} else {
		decoration = zephir_get_intval(decoration_param);
	}
	if (!bgColor_param) {
		ZEPHIR_INIT_VAR(bgColor);
		ZVAL_EMPTY_STRING(bgColor);
	} else {
		zephir_get_strval(bgColor, bgColor_param);
	}


	ZEPHIR_INIT_VAR(colors);
	zephir_create_array(colors, 9, 0 TSRMLS_CC);
	add_assoc_stringl_ex(colors, SS("black"), SL("30"), 1);
	add_assoc_stringl_ex(colors, SS("red"), SL("31"), 1);
	add_assoc_stringl_ex(colors, SS("green"), SL("32"), 1);
	add_assoc_stringl_ex(colors, SS("yellow"), SL("33"), 1);
	add_assoc_stringl_ex(colors, SS("blue"), SL("34"), 1);
	add_assoc_stringl_ex(colors, SS("magenta"), SL("35"), 1);
	add_assoc_stringl_ex(colors, SS("cyan"), SL("36"), 1);
	add_assoc_stringl_ex(colors, SS("lightgray"), SL("37"), 1);
	add_assoc_stringl_ex(colors, SS("white"), SL("97"), 1);
	ZEPHIR_INIT_VAR(bgColors);
	zephir_create_array(bgColors, 9, 0 TSRMLS_CC);
	add_assoc_stringl_ex(bgColors, SS("black"), SL("40"), 1);
	add_assoc_stringl_ex(bgColors, SS("red"), SL("41"), 1);
	add_assoc_stringl_ex(bgColors, SS("green"), SL("42"), 1);
	add_assoc_stringl_ex(bgColors, SS("yellow"), SL("43"), 1);
	add_assoc_stringl_ex(bgColors, SS("blue"), SL("44"), 1);
	add_assoc_stringl_ex(bgColors, SS("magenta"), SL("45"), 1);
	add_assoc_stringl_ex(bgColors, SS("cyan"), SL("46"), 1);
	add_assoc_stringl_ex(bgColors, SS("lightgray"), SL("47"), 1);
	add_assoc_stringl_ex(bgColors, SS("white"), SL("107"), 1);
	zephir_array_isset_fetch(&foreground, colors, color, 1 TSRMLS_CC);
	zephir_array_isset_fetch(&background, bgColors, bgColor, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(e);
	ZVAL_STRING(e, "\e", 1);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, decoration);
	ZEPHIR_INIT_VAR(_1);
	if (zephir_is_true(foreground)) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_CONCAT_SV(_1, ";", foreground);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "", 1);
	}
	ZEPHIR_INIT_VAR(colored);
	ZEPHIR_CONCAT_VSVVS(colored, e, "[", &_0, _1, "m");
	if (zephir_is_true(background)) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_VSVS(_2$$3, e, "[", background, "m");
		zephir_concat_self(&colored, _2$$3 TSRMLS_CC);
	}
	ZEPHIR_CONCAT_VVVS(return_value, colored, text, e, "[0m");
	RETURN_MM();

}

