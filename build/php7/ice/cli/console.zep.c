
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

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("NORMAL"), 0);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("BOLD_BRIGHT"), 1);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("UNDERLINE"), 4);

	zephir_declare_class_constant_long(ice_cli_console_ce, SL("INVERSE"), 7);

	return SUCCESS;

}

PHP_METHOD(Ice_Cli_Console, getModules) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "modules");

}

PHP_METHOD(Ice_Cli_Console, setModules) {

	zval *modules, modules_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modules_sub);

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_zval(this_ptr, SL("modules"), modules);
	RETURN_THISW();

}

/**
 * Console constructor
 *
 * @param Di $di
 */
PHP_METHOD(Ice_Cli_Console, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di = NULL, di_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &di);

	if (!di) {
		di = &di_sub;
		di = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("di"), di);
	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Ice_Cli_Console, addModule) {

	zval options;
	zval *name_param = NULL, *options_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &options_param);

	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&options, options_param);


	zephir_update_property_array(this_ptr, SL("modules"), &name, &options TSRMLS_CC);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "router");
	ZEPHIR_CALL_METHOD(&router, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &router, "handle", NULL, 0, arguments);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "dispatcher");
	ZEPHIR_CALL_METHOD(&dispatcher, &_2, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("modules"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodules", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, &response, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 70 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodule", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, &response, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 71 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "sethandler", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_6, &response, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 72 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setaction", NULL, 0, &_6);
	zephir_check_call_status();
	zephir_array_fetch_string(&_7, &response, SL("params"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 73 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setparams", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&response);

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
	zval *text_param = NULL, *color_param = NULL, *decoration_param = NULL, *bgColor_param = NULL, colors, bgColors, colored, e, foreground, background, _0, _1, _2$$3;
	zval text, color, bgColor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&bgColor);
	ZVAL_UNDEF(&colors);
	ZVAL_UNDEF(&bgColors);
	ZVAL_UNDEF(&colored);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&foreground);
	ZVAL_UNDEF(&background);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &color_param, &decoration_param, &bgColor_param);

	zephir_get_strval(&text, text_param);
	if (!color_param) {
		ZEPHIR_INIT_VAR(&color);
		ZVAL_STRING(&color, "");
	} else {
		zephir_get_strval(&color, color_param);
	}
	if (!decoration_param) {
		decoration = 0;
	} else {
		decoration = zephir_get_intval(decoration_param);
	}
	if (!bgColor_param) {
		ZEPHIR_INIT_VAR(&bgColor);
		ZVAL_STRING(&bgColor, "");
	} else {
		zephir_get_strval(&bgColor, bgColor_param);
	}


	ZEPHIR_INIT_VAR(&colors);
	zephir_create_array(&colors, 9, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&colors, SL("black"), SL("30"));
	add_assoc_stringl_ex(&colors, SL("red"), SL("31"));
	add_assoc_stringl_ex(&colors, SL("green"), SL("32"));
	add_assoc_stringl_ex(&colors, SL("yellow"), SL("33"));
	add_assoc_stringl_ex(&colors, SL("blue"), SL("34"));
	add_assoc_stringl_ex(&colors, SL("magenta"), SL("35"));
	add_assoc_stringl_ex(&colors, SL("cyan"), SL("36"));
	add_assoc_stringl_ex(&colors, SL("lightgray"), SL("37"));
	add_assoc_stringl_ex(&colors, SL("white"), SL("97"));
	ZEPHIR_INIT_VAR(&bgColors);
	zephir_create_array(&bgColors, 9, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&bgColors, SL("black"), SL("40"));
	add_assoc_stringl_ex(&bgColors, SL("red"), SL("41"));
	add_assoc_stringl_ex(&bgColors, SL("green"), SL("42"));
	add_assoc_stringl_ex(&bgColors, SL("yellow"), SL("43"));
	add_assoc_stringl_ex(&bgColors, SL("blue"), SL("44"));
	add_assoc_stringl_ex(&bgColors, SL("magenta"), SL("45"));
	add_assoc_stringl_ex(&bgColors, SL("cyan"), SL("46"));
	add_assoc_stringl_ex(&bgColors, SL("lightgray"), SL("47"));
	add_assoc_stringl_ex(&bgColors, SL("white"), SL("107"));
	zephir_array_isset_fetch(&foreground, &colors, &color, 1 TSRMLS_CC);
	zephir_array_isset_fetch(&background, &bgColors, &bgColor, 1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&e);
	ZVAL_STRING(&e, "\e");
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, decoration);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_is_true(&foreground)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZEPHIR_CONCAT_SV(&_1, ";", &foreground);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "");
	}
	ZEPHIR_INIT_VAR(&colored);
	ZEPHIR_CONCAT_VSVVS(&colored, &e, "[", &_0, &_1, "m");
	if (zephir_is_true(&background)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VSVS(&_2$$3, &e, "[", &background, "m");
		zephir_concat_self(&colored, &_2$$3 TSRMLS_CC);
	}
	ZEPHIR_CONCAT_VVVS(return_value, &colored, &text, &e, "[0m");
	RETURN_MM();

}

