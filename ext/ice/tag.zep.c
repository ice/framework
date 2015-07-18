
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
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Tag helper is designed to simplify building of HTML tags.
 *
 * @package     Ice/Tag
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 * @uses        Ice\Mvc\Url
 */
ZEPHIR_INIT_CLASS(Ice_Tag) {

	ZEPHIR_REGISTER_CLASS(Ice, Tag, ice, tag, ice_tag_method_entry, 0);

	zend_declare_property_null(ice_tag_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_tag_ce, SL("values"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_tag_ce, SL("docType"), 5, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_tag_ce, SL("title"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_tag_ce, SL("titleSeparator"), " - ", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_tag_ce, SL("escape"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(ice_tag_ce, SL("HTML32"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_tag_ce, SL("HTML401_STRICT"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_tag_ce, SL("HTML401_TRANSITIONAL"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(ice_tag_ce, SL("HTML401_FRAMESET"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(ice_tag_ce, SL("HTML5"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(ice_tag_ce, SL("XHTML10_STRICT"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(ice_tag_ce, SL("XHTML10_TRANSITIONAL"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(ice_tag_ce, SL("XHTML10_FRAMESET"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(ice_tag_ce, SL("XHTML11"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(ice_tag_ce, SL("XHTML20"), 10 TSRMLS_CC);

	zend_declare_class_constant_long(ice_tag_ce, SL("XHTML5"), 11 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Tag, getDi) {


	RETURN_MEMBER(this_ptr, "di");

}

PHP_METHOD(Ice_Tag, getValues) {


	RETURN_MEMBER(this_ptr, "values");

}

PHP_METHOD(Ice_Tag, setDocType) {

	zval *docType;

	zephir_fetch_params(0, 1, 0, &docType);



	zephir_update_property_this(this_ptr, SL("docType"), docType TSRMLS_CC);

}

PHP_METHOD(Ice_Tag, setTitle) {

	zval *title;

	zephir_fetch_params(0, 1, 0, &title);



	zephir_update_property_this(this_ptr, SL("title"), title TSRMLS_CC);

}

PHP_METHOD(Ice_Tag, getTitle) {


	RETURN_MEMBER(this_ptr, "title");

}

PHP_METHOD(Ice_Tag, setTitleSeparator) {

	zval *titleSeparator;

	zephir_fetch_params(0, 1, 0, &titleSeparator);



	zephir_update_property_this(this_ptr, SL("titleSeparator"), titleSeparator TSRMLS_CC);

}

PHP_METHOD(Ice_Tag, getTitleSeparator) {


	RETURN_MEMBER(this_ptr, "titleSeparator");

}

PHP_METHOD(Ice_Tag, setEscape) {

	zval *escape;

	zephir_fetch_params(0, 1, 0, &escape);



	zephir_update_property_this(this_ptr, SL("escape"), escape TSRMLS_CC);

}

/**
 * Tag constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Tag, __construct) {

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
 * Appends a text to current document title.
 *
 * @param string title
 * @param string separator
 * @return void
 */
PHP_METHOD(Ice_Tag, appendTitle) {

	zval *title_param = NULL, *separator_param = NULL, *_0, *_1 = NULL, *_2;
	zval *title = NULL, *separator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &title_param, &separator_param);

	zephir_get_strval(title, title_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(separator);
		ZVAL_EMPTY_STRING(separator);
	} else {
		zephir_get_strval(separator, separator_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("title"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	if (separator && Z_STRLEN_P(separator)) {
		ZEPHIR_CPY_WRT(_1, separator);
	} else {
		ZEPHIR_OBS_NVAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("titleSeparator"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VVV(_2, _0, _1, title);
	zephir_update_property_this(this_ptr, SL("title"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Prepends a text to current document title.
 *
 * @param string title
 * @param string separator
 * @return void
 */
PHP_METHOD(Ice_Tag, prependTitle) {

	zval *title_param = NULL, *separator_param = NULL, *_0 = NULL, *_1, *_2;
	zval *title = NULL, *separator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &title_param, &separator_param);

	zephir_get_strval(title, title_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(separator);
		ZVAL_EMPTY_STRING(separator);
	} else {
		zephir_get_strval(separator, separator_param);
	}


	ZEPHIR_INIT_VAR(_0);
	if (separator && Z_STRLEN_P(separator)) {
		ZEPHIR_CPY_WRT(_0, separator);
	} else {
		ZEPHIR_OBS_NVAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("titleSeparator"), PH_NOISY_CC);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("title"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VVV(_2, title, _0, _1);
	zephir_update_property_this(this_ptr, SL("title"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Builds a HTML INPUT[type="text"] tag.
 *
 * <pre><code>
 *  // Phtml <input type="text" id="some" name="some" value="some_value">
 *  $this->tag->textField(['some', 'some_value']);
 *  
 *  // Sleet <input type="text" id="some1" name="some" value="some_value" class="field" style="width: 100%">
 *  {{ text_field(['some', 'some_value', 'id' => 'some1', 'class' => 'field', 'style' => 'width: 100%']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, textField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "text", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 152, _0, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML INPUT[type="password"] tag.
 *
 * <pre><code>
 *  // Phtml <input type="password" id="pass" name="pass" class="form-control">
 *  $this->tag->passwordField(['pass', 'class': 'form-control']);
 *  
 *  // Sleet <input type="password" id="pass" name="pass" placeholder="My secret password">
 *  {{ password_field(['pass', 'placeholder': 'My secret password']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, passwordField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "password", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 152, _0, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML INPUT[type="hidden"] tag.
 *
 * <pre><code>
 *  // Phtml <input type="hidden" id="secret" name="secret" value="some value">
 *  $this->tag->hiddenField(['secret', 'some value']);
 *  
 *  // Sleet <input type="hidden" id="my_id" name="secret" value="hidden value">
 *  {{ hidden_field(['secret', 'hidden value', 'id': 'my_id']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, hiddenField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "hidden", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 152, _0, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML INPUT[type="file"] tag.
 *
 * <pre><code>
 *  // Sleet <input type="file" id="some" name="some" >
 *  {{ file_field(['some']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, fileField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "file", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 152, _0, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML INPUT[type="submit"] tag.
 *
 * <pre><code>
 *  // Phtml <input type="submit" id="some" name="some" value="Submit">
 *  $this->tag->submitButton(['some', 'Submit']);
 *  
 *  // Sleet <input type="submit" id="some1" name="some" value="Submit" class="btn">
 *  {{ submit_button(['some', 'value' => 'Submit', 'id' => 'some1', 'class' => 'btn']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, submitButton) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "submit", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 152, _0, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML BUTTON tag.
 *
 * <pre><code>
 *  // Phtml <button type="submit" id="some" name="some">content</button>
 *  $this->tag->button(['some', 'content']);
 *  
 *  // Sleet <button type="button" id="some1" name="some"><i class="icon">+</i> Submit</button>
 *  {{ button(['some', '<i class="icon">+</i> ' . 'Submit', 'type' => 'button', 'id' => 'some1']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, button) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams, *_1 = NULL, *_2, *_3;
	zval *parameters = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(defaultParams);
	zephir_create_array(defaultParams, 4, 0 TSRMLS_CC);
	add_assoc_long_ex(defaultParams, SS("id"), 0);
	add_assoc_long_ex(defaultParams, SS("name"), 0);
	add_assoc_long_ex(defaultParams, SS("content"), 1);
	add_assoc_stringl_ex(defaultParams, SS("type"), SL("submit"), 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "content", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "button", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "content", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _1, parameters, defaultParams, _0, _2, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML INPUT[type="checkbox"] tag.
 *
 * <pre><code>
 *  // Phtml <input type="checkbox" id="agree" name="agree" value="yes">
 *  $this->tag->checkField(['agree', 'yes']);
 *  
 *  // Sleet <input type="checkbox" id="remember" name="remember" value="on" checked="checked">
 *  {{ check_field(['remember', 'on', 'checked': 'checked']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, checkField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "checkbox", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 152, _0, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML INPUT[type="radio"] tag.
 *
 * <pre><code>
 *  // Phtml <input type="radio" id="sex" name="sex" value="male">
 *  $this->tag->radioField(['sex', 'male']);
 *  
 *  // Sleet <input type="radio" id="sex" name="sex" value="female" checked="checked">
 *  {{ radio_field(['sex', 'female', 'checked': 'checked']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, radioField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "radio", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 152, _0, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds generic INPUT tags.
 *
 * @param string type
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, input) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL;
	zval *type_param = NULL, *parameters_param = NULL, *defaultParams, *_0, *_1, *_2, *_3, *_4, *_5;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &parameters_param);

	zephir_get_strval(type, type_param);
	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(defaultParams);
	zephir_create_array(defaultParams, 4, 0 TSRMLS_CC);
	add_assoc_long_ex(defaultParams, SS("id"), 0);
	add_assoc_long_ex(defaultParams, SS("name"), 0);
	add_assoc_long_ex(defaultParams, SS("value"), 1);
	zephir_array_update_string(&defaultParams, SL("type"), &type, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "input", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, 0);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_BOOL(_5, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _1, parameters, defaultParams, _0, _2, _3, _4, _5);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML FORM tag.
 *
 * <pre><code>
 *  // Phtml <form action="/post/add" method="post">
 *  $this->tag->form(['post/add']);
 *  
 *  // <form action="http://example.com" method="post">
 *  $this->tag->form(['http://example.com', 'local' => false]);
 *  
 *  // Sleet <form method="post">
 *  {{ form([false]) }}
 *  
 *  // <form action="/post/add" class="form-horizontal" method="post" enctype="multipart/form-data">
 *  {{ form(['post/add', 'enctype' => 'multipart/form-data', 'class' => 'form-horizontal']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, form) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams, *action = NULL, *local = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL;
	zval *parameters = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(defaultParams);
	zephir_create_array(defaultParams, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(defaultParams, SS("action"), 0);
	add_assoc_stringl_ex(defaultParams, SS("method"), SL("post"), 1);
	ZEPHIR_OBS_VAR(local);
	if (!(zephir_array_isset_string_fetch(&local, parameters, SS("local"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(local);
		ZVAL_BOOL(local, 1);
	}
	if (zephir_is_true(local)) {
		ZEPHIR_OBS_VAR(action);
		if (!(zephir_array_isset_string_fetch(&action, parameters, SS("action"), 0 TSRMLS_CC))) {
			ZEPHIR_OBS_NVAR(action);
			zephir_array_fetch_string(&_0, defaultParams, SL("action"), PH_READONLY, "ice/tag.zep", 282 TSRMLS_CC);
			zephir_array_isset_fetch(&action, parameters, _0, 0 TSRMLS_CC);
		}
		if (!ZEPHIR_IS_FALSE_IDENTICAL(action)) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "url", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_2, _1, "has", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			if (zephir_is_true(_2)) {
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "url", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_5, _4, "get", NULL, 0, _3);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6, _5, "get", NULL, 0, action);
				zephir_check_call_status();
				zephir_array_update_string(&parameters, SL("action"), &_6, PH_COPY | PH_SEPARATE);
			}
		}
	}
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "local", 1);
	zephir_array_fast_append(_7, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "form", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _3, parameters, defaultParams, _7);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML TEXTAREA tag.
 *
 * <pre><code>
 *  // Phtml <textarea id="description" name="description">content</textarea>
 *  $this->tag->textArea(['description', 'content']);
 *  
 *  // Sleet <textarea id="some" name="some" placeholder="Say something"></textarea>
 *  {{ text_area(['some', 'placeholder' => 'Say something']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, textArea) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams, *_1 = NULL, *_2, *_3;
	zval *parameters = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(defaultParams);
	zephir_create_array(defaultParams, 3, 0 TSRMLS_CC);
	add_assoc_long_ex(defaultParams, SS("id"), 0);
	add_assoc_long_ex(defaultParams, SS("name"), 0);
	add_assoc_long_ex(defaultParams, SS("content"), 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "content", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "value", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "textarea", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "content", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _1, parameters, defaultParams, _0, _2, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of the `img` method.
 */
PHP_METHOD(Ice_Tag, image) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "img", NULL, 0, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds HTML IMG tags.
 *
 * <pre><code>
 *  // Phtml <img src="/img/logo.png" alt="Logo">
 *  $this->tag->img(['img/logo.png', 'Logo']);
 *  
 *  // Sleet <img src="http://example.com/img/logo.png" alt="Logo">
 *  {{ image(['http://example.com/img/logo.png', 'Logo', 'local' => false]) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, img) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams, *src = NULL, *local = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL, *_8, *_9, *_10, *_11;
	zval *parameters = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(defaultParams);
	zephir_create_array(defaultParams, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(defaultParams, SS("src"), 0);
	add_assoc_long_ex(defaultParams, SS("alt"), 1);
	ZEPHIR_OBS_VAR(local);
	if (!(zephir_array_isset_string_fetch(&local, parameters, SS("local"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(local);
		ZVAL_BOOL(local, 1);
	}
	if (zephir_is_true(local)) {
		ZEPHIR_OBS_VAR(src);
		if (!(zephir_array_isset_string_fetch(&src, parameters, SS("src"), 0 TSRMLS_CC))) {
			ZEPHIR_OBS_NVAR(src);
			zephir_array_fetch_string(&_0, defaultParams, SL("src"), PH_READONLY, "ice/tag.zep", 360 TSRMLS_CC);
			zephir_array_isset_fetch(&src, parameters, _0, 0 TSRMLS_CC);
		}
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, _1, "has", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "url", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_5, _4, "get", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6, _5, "getstatic", NULL, 0, src);
			zephir_check_call_status();
			zephir_array_update_string(&parameters, SL("src"), &_6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "local", 1);
	zephir_array_fast_append(_7, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "img", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_NULL(_8);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_BOOL(_9, 0);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_BOOL(_10, 0);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_BOOL(_11, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _3, parameters, defaultParams, _7, _8, _9, _10, _11);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of the `a` method.
 */
PHP_METHOD(Ice_Tag, linkTo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "a", NULL, 0, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML A tag using framework conventions.
 *
 * <pre><code>
 *  // Phtml <a href="/post/add" title="Add a post">Add</a>
 *  $this->tag->a(['post/add', 'Add', 'Add a post']);
 *  
 *  // Sleet <a href="http://google.com">Google</a>
 *  {{ link_to(['http://google.com', 'Google', 'local' => false]) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, a) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams, *href = NULL, *local = NULL, *query, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL, *_8, *_9;
	zval *parameters = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(defaultParams);
	zephir_create_array(defaultParams, 3, 0 TSRMLS_CC);
	add_assoc_long_ex(defaultParams, SS("href"), 0);
	add_assoc_long_ex(defaultParams, SS("text"), 1);
	add_assoc_long_ex(defaultParams, SS("title"), 2);
	ZEPHIR_OBS_VAR(href);
	if (!(zephir_array_isset_string_fetch(&href, parameters, SS("href"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(href);
		zephir_array_fetch_string(&_0, defaultParams, SL("href"), PH_READONLY, "ice/tag.zep", 404 TSRMLS_CC);
		zephir_array_isset_fetch(&href, parameters, _0, 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(local);
	if (!(zephir_array_isset_string_fetch(&local, parameters, SS("local"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(local);
		ZVAL_BOOL(local, 1);
	}
	ZEPHIR_OBS_VAR(query);
	zephir_array_isset_string_fetch(&query, parameters, SS("query"), 0 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "url", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, _1, "has", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, _4, "get", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6, _5, "get", NULL, 0, href, query, local);
		zephir_check_call_status();
		zephir_array_update_string(&parameters, SL("href"), &_6, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "text", 1);
	zephir_array_fast_append(_7, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "local", 1);
	zephir_array_fast_append(_7, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "query", 1);
	zephir_array_fast_append(_7, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "a", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "text", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_BOOL(_9, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _3, parameters, defaultParams, _7, _8, _9);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a LINK[rel="stylesheet"] tag.
 *
 * <pre><code>
 *  // Phtml <link rel="stylesheet" type="text/css" href="/css/app.css">
 *  $this->tag->link(['css/app.css']);
 *  
 *  // Sleet <link rel="icon" type="image/x-icon" href="http://example.com/favicon.ico">
 *  {{ link(['http://example.com/favicon.ico', 'type' => 'image/x-icon', 'rel' => 'icon', 'local' => false]) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, link) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams, *href = NULL, *local = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL, *_8, *_9, *_10, *_11;
	zval *parameters = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(defaultParams);
	zephir_create_array(defaultParams, 3, 0 TSRMLS_CC);
	add_assoc_long_ex(defaultParams, SS("href"), 0);
	add_assoc_stringl_ex(defaultParams, SS("type"), SL("text/css"), 1);
	add_assoc_stringl_ex(defaultParams, SS("rel"), SL("stylesheet"), 1);
	ZEPHIR_OBS_VAR(local);
	if (!(zephir_array_isset_string_fetch(&local, parameters, SS("local"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(local);
		ZVAL_BOOL(local, 1);
	}
	if (zephir_is_true(local)) {
		ZEPHIR_OBS_VAR(href);
		if (!(zephir_array_isset_string_fetch(&href, parameters, SS("href"), 0 TSRMLS_CC))) {
			ZEPHIR_OBS_NVAR(href);
			zephir_array_fetch_string(&_0, defaultParams, SL("href"), PH_READONLY, "ice/tag.zep", 450 TSRMLS_CC);
			zephir_array_isset_fetch(&href, parameters, _0, 0 TSRMLS_CC);
		}
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, _1, "has", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "url", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_5, _4, "get", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6, _5, "getstatic", NULL, 0, href);
			zephir_check_call_status();
			zephir_array_update_string(&parameters, SL("href"), &_6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "local", 1);
	zephir_array_fast_append(_7, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "link", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_NULL(_8);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_BOOL(_9, 0);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_BOOL(_10, 1);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_BOOL(_11, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _3, parameters, defaultParams, _7, _8, _9, _10, _11);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a SCRIPT[type="javascript"] tag.
 *
 * <pre><code>
 *  // Phtml <script type="text/javascript" src="/js/plugins.js"></script>
 *  $this->tag->script(['js/plugins.js']);
 *  
 *  // Sleet <script type="text/javascript">alert("OK");</script>
 *  {{ script(['content' => 'alert("OK");']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, script) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1;
	zval *parameters_param = NULL, *defaultParams, *src = NULL, *local = NULL, *_0, *_2, *_3 = NULL, *_4 = NULL, *_5, *_6 = NULL, *_7 = NULL, *_9, *_10;
	zval *parameters = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(defaultParams);
	zephir_create_array(defaultParams, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(defaultParams, SS("src"), 0);
	add_assoc_stringl_ex(defaultParams, SS("type"), SL("text/javascript"), 1);
	ZEPHIR_OBS_VAR(local);
	if (!(zephir_array_isset_string_fetch(&local, parameters, SS("local"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(local);
		ZVAL_BOOL(local, 1);
	}
	if (zephir_is_true(local)) {
		ZEPHIR_OBS_VAR(src);
		if (!(zephir_array_isset_string_fetch(&src, parameters, SS("src"), 0 TSRMLS_CC))) {
			ZEPHIR_OBS_NVAR(src);
			zephir_array_fetch_string(&_0, defaultParams, SL("src"), PH_READONLY, "ice/tag.zep", 490 TSRMLS_CC);
			zephir_array_isset_fetch(&src, parameters, _0, 0 TSRMLS_CC);
		}
		_1 = zephir_is_true(src);
		if (_1) {
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "url", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_3, _2, "has", NULL, 0, _4);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			_1 = zephir_is_true(_3);
		}
		if (_1) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "url", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_6, _5, "get", NULL, 0, _4);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7, _6, "getstatic", NULL, 0, src);
			zephir_check_call_status();
			zephir_array_update_string(&parameters, SL("src"), &_7, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "local", 1);
	zephir_array_fast_append(_8, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "content", 1);
	zephir_array_fast_append(_8, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "script", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_STRING(_9, "content", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_BOOL(_10, 1);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "taghtml", NULL, 0, _4, parameters, defaultParams, _8, _9, _10);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_9);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_4);
	ZEPHIR_GET_CONSTANT(_4, "PHP_EOL");
	ZEPHIR_CONCAT_VV(return_value, _3, _4);
	RETURN_MM();

}

/**
 * Builds a STYLE tag.
 *
 * <pre><code>
 *  // Sleet <style type="text/css">body { color: #444 }</style>
 *  {{ style(['body { color: #444 }']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, style) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams, *_1 = NULL, *_2, *_3, *_4;
	zval *parameters = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(defaultParams);
	zephir_create_array(defaultParams, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(defaultParams, SS("content"), 0);
	add_assoc_stringl_ex(defaultParams, SS("type"), SL("text/css"), 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "content", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "style", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "content", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _1, parameters, defaultParams, _0, _2, _3, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a SELECT tag.
 *
 * <pre><code>
 *  $countries = [1 => 'England', 2 => 'Poland'];
 *  $this->tag->select('country', $countries);
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, select) {

	zephir_fcall_cache_entry *_17 = NULL;
	HashTable *_5, *_8;
	HashPosition _4, _7;
	zval *_3 = NULL, *_10 = NULL, *_23 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams, *name = NULL, *options = NULL, *option = NULL, *selected = NULL, *tmp, *value = NULL, *text = NULL, *group = NULL, *subvalue = NULL, *subtext = NULL, *suboptions = NULL, *_0, *_1 = NULL, *_2 = NULL, **_6, **_9, *_11 = NULL, *_12 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL;
	zval *parameters = NULL, *_13 = NULL, *_24;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(defaultParams);
	zephir_create_array(defaultParams, 3, 0 TSRMLS_CC);
	add_assoc_long_ex(defaultParams, SS("id"), 0);
	add_assoc_long_ex(defaultParams, SS("name"), 0);
	add_assoc_long_ex(defaultParams, SS("options"), 1);
	ZEPHIR_OBS_VAR(name);
	if (!(zephir_array_isset_string_fetch(&name, parameters, SS("name"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(name);
		zephir_array_fetch_string(&_0, defaultParams, SL("name"), PH_READONLY, "ice/tag.zep", 546 TSRMLS_CC);
		zephir_array_isset_fetch(&name, parameters, _0, 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(options);
	if (!(zephir_array_isset_string_fetch(&options, parameters, SS("options"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(options);
		zephir_array_fetch_string(&_0, defaultParams, SL("options"), PH_READONLY, "ice/tag.zep", 550 TSRMLS_CC);
		zephir_array_isset_fetch(&options, parameters, _0, 0 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasvalue", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_CALL_METHOD(&selected, this_ptr, "getvalue", NULL, 0, name);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(selected);
		ZVAL_NULL(selected);
	}
	if (Z_TYPE_P(selected) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "multiple", 1);
		zephir_array_update_string(&parameters, SL("multiple"), &_2, PH_COPY | PH_SEPARATE);
	}
	if (Z_TYPE_P(selected) != IS_ARRAY) {
		if (Z_TYPE_P(selected) == IS_NULL) {
			ZEPHIR_INIT_NVAR(selected);
			array_init(selected);
		} else {
			ZEPHIR_INIT_VAR(tmp);
			zephir_create_array(tmp, 1, 0 TSRMLS_CC);
			zephir_get_strval(_3, selected);
			zephir_array_fast_append(tmp, _3);
			ZEPHIR_CPY_WRT(selected, tmp);
		}
	}
	if (ZEPHIR_IS_EMPTY(options)) {
		ZEPHIR_INIT_NVAR(options);
		ZVAL_STRING(options, "", 1);
	} else {
		zephir_is_iterable(options, &_5, &_4, 1, 0, "ice/tag.zep", 622);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HMKEY(value, _5, _4);
			ZEPHIR_GET_HVALUE(text, _6);
			if (Z_TYPE_P(text) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(group);
				zephir_create_array(group, 1, 0 TSRMLS_CC);
				zephir_array_update_string(&group, SL("label"), &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(suboptions);
				array_init(suboptions);
				zephir_is_iterable(text, &_8, &_7, 0, 0, "ice/tag.zep", 601);
				for (
				  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
				  ; zephir_hash_move_forward_ex(_8, &_7)
				) {
					ZEPHIR_GET_HMKEY(subvalue, _8, _7);
					ZEPHIR_GET_HVALUE(subtext, _9);
					zephir_get_strval(_10, subvalue);
					ZEPHIR_CPY_WRT(subvalue, _10);
					ZEPHIR_INIT_NVAR(option);
					zephir_create_array(option, 1, 0 TSRMLS_CC);
					zephir_array_update_string(&option, SL("value"), &subvalue, PH_COPY | PH_SEPARATE);
					if (zephir_fast_in_array(subvalue, selected TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(_2);
						ZVAL_STRING(_2, "selected", 1);
						zephir_array_update_string(&option, SL("selected"), &_2, PH_COPY | PH_SEPARATE);
					}
					zephir_array_update_string(&option, SL("content"), &subtext, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(_12);
					array_init(_12);
					ZEPHIR_INIT_NVAR(_13);
					zephir_create_array(_13, 1, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_14);
					ZVAL_STRING(_14, "content", 1);
					zephir_array_fast_append(_13, _14);
					ZEPHIR_INIT_NVAR(_14);
					ZVAL_STRING(_14, "option", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_STRING(_15, "content", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_INIT_NVAR(_16);
					ZVAL_BOOL(_16, 1);
					ZEPHIR_CALL_METHOD(&_11, this_ptr, "taghtml", &_17, 0, _14, option, _12, _13, _15, _16);
					zephir_check_temp_parameter(_14);
					zephir_check_temp_parameter(_15);
					zephir_check_call_status();
					zephir_array_append(&suboptions, _11, PH_SEPARATE, "ice/tag.zep", 597);
				}
				ZEPHIR_INIT_NVAR(_12);
				ZEPHIR_GET_CONSTANT(_12, "PHP_EOL");
				ZEPHIR_INIT_NVAR(_14);
				ZEPHIR_INIT_NVAR(_15);
				ZEPHIR_GET_CONSTANT(_15, "PHP_EOL");
				zephir_fast_join(_14, _15, suboptions TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_16);
				ZEPHIR_GET_CONSTANT(_16, "PHP_EOL");
				ZEPHIR_INIT_LNVAR(_18);
				ZEPHIR_CONCAT_VVV(_18, _12, _14, _16);
				zephir_array_update_string(&group, SL("content"), &_18, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_19);
				array_init(_19);
				ZEPHIR_INIT_NVAR(_13);
				zephir_create_array(_13, 1, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_20);
				ZVAL_STRING(_20, "content", 1);
				zephir_array_fast_append(_13, _20);
				ZEPHIR_INIT_NVAR(_20);
				ZVAL_STRING(_20, "optgroup", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_STRING(_21, "content", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_22);
				ZVAL_BOOL(_22, 1);
				ZEPHIR_CALL_METHOD(&_11, this_ptr, "taghtml", &_17, 0, _20, group, _19, _13, _21, _22);
				zephir_check_temp_parameter(_20);
				zephir_check_temp_parameter(_21);
				zephir_check_call_status();
				zephir_array_update_zval(&options, value, &_11, PH_COPY | PH_SEPARATE);
			} else {
				zephir_get_strval(_23, value);
				ZEPHIR_CPY_WRT(value, _23);
				ZEPHIR_INIT_NVAR(option);
				zephir_create_array(option, 1, 0 TSRMLS_CC);
				zephir_array_update_string(&option, SL("value"), &value, PH_COPY | PH_SEPARATE);
				if (zephir_fast_in_array(value, selected TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_19);
					ZVAL_STRING(_19, "selected", 1);
					zephir_array_update_string(&option, SL("selected"), &_19, PH_COPY | PH_SEPARATE);
				}
				zephir_array_update_string(&option, SL("content"), &text, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_12);
				array_init(_12);
				ZEPHIR_INIT_NVAR(_13);
				zephir_create_array(_13, 1, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_14);
				ZVAL_STRING(_14, "content", 1);
				zephir_array_fast_append(_13, _14);
				ZEPHIR_INIT_NVAR(_14);
				ZVAL_STRING(_14, "option", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_STRING(_15, "content", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_16);
				ZVAL_BOOL(_16, 1);
				ZEPHIR_CALL_METHOD(&_11, this_ptr, "taghtml", &_17, 0, _14, option, _12, _13, _15, _16);
				zephir_check_temp_parameter(_14);
				zephir_check_temp_parameter(_15);
				zephir_check_call_status();
				zephir_array_update_zval(&options, value, &_11, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(_14);
		ZEPHIR_INIT_NVAR(_15);
		ZEPHIR_GET_CONSTANT(_15, "PHP_EOL");
		zephir_fast_join(_14, _15, options TSRMLS_CC);
		zephir_array_update_string(&parameters, SL("content"), &_14, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_24);
	zephir_create_array(_24, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "content", 1);
	zephir_array_fast_append(_24, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "options", 1);
	zephir_array_fast_append(_24, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "value", 1);
	zephir_array_fast_append(_24, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "select", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_16);
	ZVAL_STRING(_16, "content", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_19);
	ZVAL_BOOL(_19, 1);
	ZEPHIR_INIT_NVAR(_20);
	ZVAL_BOOL(_20, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", &_17, 0, _2, parameters, defaultParams, _24, _16, _19, _20);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML tag.
 *
 * @param string name Name of tag
 * @param array parameters Parameters like id, style
 * @param array defaultParams Default parameters
 * @param array skip Skip parameters
 * @param string content Parameter name to append content
 * @param boolean close Close tag
 * @param boolean eol Add end of line
 * @param boolean single Void element, close a tag by " />" (depending on doctype)
 * @return string
 */
PHP_METHOD(Ice_Tag, tagHtml) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_4;
	HashPosition _0, _3;
	zend_bool close, eol, single, _7, _8;
	zval *parameters = NULL, *defaultParams = NULL, *skip = NULL;
	zval *name_param = NULL, *parameters_param = NULL, *defaultParams_param = NULL, *skip_param = NULL, *content_param = NULL, *close_param = NULL, *eol_param = NULL, *single_param = NULL, *params = NULL, *param = NULL, *key = NULL, *value = NULL, *attributes = NULL, *code = NULL, **_2, **_5, *_6 = NULL, *_9 = NULL, *_10, *_11, *_12 = NULL, *_13;
	zval *name = NULL, *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 7, &name_param, &parameters_param, &defaultParams_param, &skip_param, &content_param, &close_param, &eol_param, &single_param);

	zephir_get_strval(name, name_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	} else {
	parameters = parameters_param;

	}
	if (!defaultParams_param) {
		ZEPHIR_INIT_VAR(defaultParams);
		array_init(defaultParams);
	} else {
		zephir_get_arrval(defaultParams, defaultParams_param);
	}
	if (!skip_param) {
		ZEPHIR_INIT_VAR(skip);
		array_init(skip);
	} else {
		zephir_get_arrval(skip, skip_param);
	}
	if (!content_param) {
		ZEPHIR_INIT_VAR(content);
		ZVAL_EMPTY_STRING(content);
	} else {
		zephir_get_strval(content, content_param);
	}
	if (!close_param) {
		close = 0;
	} else {
		close = zephir_get_boolval(close_param);
	}
	if (!eol_param) {
		eol = 0;
	} else {
		eol = zephir_get_boolval(eol_param);
	}
	if (!single_param) {
		single = 0;
	} else {
		single = zephir_get_boolval(single_param);
	}


	ZEPHIR_INIT_VAR(attributes);
	array_init(attributes);
	ZEPHIR_CPY_WRT(params, parameters);
	zephir_is_iterable(defaultParams, &_1, &_0, 0, 0, "ice/tag.zep", 658);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(param, _1, _0);
		ZEPHIR_GET_HVALUE(key, _2);
		if (zephir_is_numeric(key)) {
			ZEPHIR_OBS_NVAR(value);
			if (zephir_array_isset_fetch(&value, params, key, 0 TSRMLS_CC)) {
				zephir_array_update_zval(&attributes, param, &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_zval(&attributes, param, &key, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_is_iterable(defaultParams, &_4, &_3, 0, 0, "ice/tag.zep", 662);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(key, _5);
		zephir_array_unset(&params, key, PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_6);
	zephir_fast_array_merge(_6, &(attributes), &(params) TSRMLS_CC);
	ZEPHIR_CPY_WRT(attributes, _6);
	ZEPHIR_CALL_METHOD(&code, this_ptr, "preparetag", NULL, 0, name, attributes, skip, (single ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	if (eol) {
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_GET_CONSTANT(_6, "PHP_EOL");
		zephir_concat_self(&code, _6 TSRMLS_CC);
	}
	if (content && Z_STRLEN_P(content)) {
		_7 = ZEPHIR_IS_STRING(name, "textarea");
		if (_7) {
			_7 = zephir_array_isset_string(attributes, SS("name"));
		}
		_8 = _7;
		if (_8) {
			zephir_array_fetch_string(&_10, attributes, SL("name"), PH_NOISY | PH_READONLY, "ice/tag.zep", 671 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_9, this_ptr, "hasvalue", NULL, 0, _10);
			zephir_check_call_status();
			_8 = zephir_is_true(_9);
		}
		if (_8) {
			zephir_array_fetch_string(&_11, attributes, SL("name"), PH_NOISY | PH_READONLY, "ice/tag.zep", 672 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0, _11);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(value);
			zephir_array_isset_fetch(&value, attributes, content, 0 TSRMLS_CC);
		}
		zephir_concat_self(&code, value TSRMLS_CC);
	}
	if (close) {
		ZEPHIR_INIT_VAR(_12);
		if (eol) {
			ZEPHIR_INIT_NVAR(_12);
			ZEPHIR_GET_CONSTANT(_12, "PHP_EOL");
		} else {
			ZEPHIR_INIT_NVAR(_12);
			ZVAL_STRING(_12, "", 1);
		}
		ZEPHIR_CALL_METHOD(&_9, this_ptr, "endtag", NULL, 0, name, (eol ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_13);
		ZEPHIR_CONCAT_VV(_13, _12, _9);
		zephir_concat_self(&code, _13 TSRMLS_CC);
	}
	RETURN_CCTOR(code);

}

/**
 * Builds a HTML close tag.
 *
 * <pre><code>
 *  // Sleet </form>
 *  {{ end_tag('form') }}
 * </code></pre>
 *
 * @param string name
 * @param boolean eol
 * @return string
 */
PHP_METHOD(Ice_Tag, endTag) {

	zend_bool eol;
	zval *name_param = NULL, *eol_param = NULL, *_0 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &eol_param);

	zephir_get_strval(name, name_param);
	if (!eol_param) {
		eol = 1;
	} else {
		eol = zephir_get_boolval(eol_param);
	}


	ZEPHIR_INIT_VAR(_0);
	if (eol) {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "", 1);
	}
	ZEPHIR_CONCAT_SVSV(return_value, "</", name, ">", _0);
	RETURN_MM();

}

/**
 * Renders parameters keeping order in html attributes.
 *
 * @param string name
 * @param array attributes
 * @param array skip
 * @param boolean single
 * @return string
 */
PHP_METHOD(Ice_Tag, prepareTag) {

	HashTable *_9;
	HashPosition _8;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool single, _6, _7, _11, _13;
	zval *attributes = NULL, *skip = NULL;
	zval *name_param = NULL, *attributes_param = NULL, *skip_param = NULL, *single_param = NULL, *order, *keys = NULL, *attrs, *code = NULL, *tmp = NULL, *value = NULL, *key = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5, **_10, *_12, *_14, *_15 = NULL, *_16, *_17 = NULL, *_18 = NULL;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &name_param, &attributes_param, &skip_param, &single_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	attributes = attributes_param;

	if (!skip_param) {
		ZEPHIR_INIT_VAR(skip);
		array_init(skip);
	} else {
		zephir_get_arrval(skip, skip_param);
	}
	if (!single_param) {
		single = 0;
	} else {
		single = zephir_get_boolval(single_param);
	}


	ZEPHIR_INIT_VAR(order);
	zephir_create_array(order, 11, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "rel", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "type", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "for", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "src", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "href", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "action", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "id", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "name", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "value", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "class", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "style", 1);
	zephir_array_fast_append(order, _0);
	ZEPHIR_CALL_FUNCTION(&_1, "array_flip", NULL, 11, order);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&keys, "array_intersect_key", NULL, 12, _1, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(attrs);
	zephir_fast_array_merge(attrs, &(keys), &(attributes) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "<", name);
	ZEPHIR_CPY_WRT(code, _2);
	ZEPHIR_OBS_VAR(tmp);
	if (zephir_array_isset_string_fetch(&tmp, attrs, SS("name"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "hasvalue", NULL, 0, tmp);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			ZEPHIR_CALL_METHOD(&_4, this_ptr, "getvalue", NULL, 0, tmp);
			zephir_check_call_status();
			zephir_array_update_string(&attrs, SL("value"), &_4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(tmp);
			if (zephir_array_isset_string_fetch(&tmp, attrs, SS("type"), 0 TSRMLS_CC)) {
				zephir_array_fetch_string(&_5, attrs, SL("value"), PH_NOISY | PH_READONLY, "ice/tag.zep", 728 TSRMLS_CC);
				_6 = zephir_is_true(_5);
				if (_6) {
					_7 = ZEPHIR_IS_STRING(tmp, "checkbox");
					if (!(_7)) {
						_7 = ZEPHIR_IS_STRING(tmp, "radio");
					}
					_6 = _7;
				}
				if (_6) {
					ZEPHIR_INIT_NVAR(_0);
					ZVAL_STRING(_0, "checked", 1);
					zephir_array_update_string(&attrs, SL("checked"), &_0, PH_COPY | PH_SEPARATE);
				}
			}
		}
	}
	zephir_is_iterable(attrs, &_9, &_8, 0, 0, "ice/tag.zep", 744);
	for (
	  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
	  ; zephir_hash_move_forward_ex(_9, &_8)
	) {
		ZEPHIR_GET_HMKEY(key, _9, _8);
		ZEPHIR_GET_HVALUE(value, _10);
		_6 = Z_TYPE_P(key) == IS_STRING;
		if (_6) {
			_6 = Z_TYPE_P(value) != IS_NULL;
		}
		_7 = _6;
		if (_7) {
			_7 = !ZEPHIR_IS_FALSE_IDENTICAL(value);
		}
		_11 = _7;
		if (_11) {
			_11 = !(zephir_fast_in_array(key, skip TSRMLS_CC));
		}
		if (_11) {
			_12 = zephir_fetch_nproperty_this(this_ptr, SL("escape"), PH_NOISY_CC);
			_13 = zephir_is_true(_12);
			if (_13) {
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_STRING(_15, "filter", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_3, _14, "has", NULL, 0, _15);
				zephir_check_temp_parameter(_15);
				zephir_check_call_status();
				_13 = zephir_is_true(_3);
			}
			if (_13) {
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_STRING(_15, "filter", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_4, _16, "get", NULL, 0, _15);
				zephir_check_temp_parameter(_15);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_STRING(_15, "escape", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_17, _4, "sanitize", NULL, 0, value, _15);
				zephir_check_temp_parameter(_15);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(value, _17);
			}
			ZEPHIR_INIT_LNVAR(_18);
			ZEPHIR_CONCAT_SVSVS(_18, " ", key, "=\"", value, "\"");
			zephir_concat_self(&code, _18 TSRMLS_CC);
		}
	}
	if (single) {
		ZEPHIR_INIT_LNVAR(_18);
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("docType"), PH_NOISY_CC);
		if (ZEPHIR_GT_LONG(_12, 5)) {
			ZEPHIR_INIT_NVAR(_18);
			ZVAL_STRING(_18, " />", 1);
		} else {
			ZEPHIR_INIT_NVAR(_18);
			ZVAL_STRING(_18, ">", 1);
		}
		zephir_concat_self(&code, _18 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&code, SL(">") TSRMLS_CC);
	}
	RETURN_CCTOR(code);

}

/**
 * Check if a helper has a default value set using Ice\Tag::setValues or value from _POST.
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Ice_Tag, hasValue) {

	zval *name_param = NULL, *_POST, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	if (zephir_array_isset(_POST, name)) {
		RETURN_MM_BOOL(1);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
		if (zephir_array_isset(_0, name)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Assigns default values to generated tags by helpers.
 *
 * @param string id
 * @param mixed value
 * @return void
 */
PHP_METHOD(Ice_Tag, setValue) {

	zend_bool _0;
	zval *id_param = NULL, *value;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &value);

	if (unlikely(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(id, id_param);
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}


	if (Z_TYPE_P(value) != IS_NULL) {
		_0 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_0)) {
			_0 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (_0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Only scalar values can be assigned to UI components", "ice/tag.zep", 785);
			return;
		}
	}
	zephir_update_property_array(this_ptr, SL("values"), id, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Assigns default values to generated tags by helpers.
 *
 * @param array values
 * @param boolean merge
 * @return void
 */
PHP_METHOD(Ice_Tag, setValues) {

	zend_bool merge;
	zval *values_param = NULL, *merge_param = NULL, *current, *_0;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values_param, &merge_param);

	zephir_get_arrval(values, values_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "An array is required as default values", "ice/tag.zep", 803);
		return;
	}
	if (merge) {
		ZEPHIR_OBS_VAR(current);
		zephir_read_property_this(&current, this_ptr, SL("values"), PH_NOISY_CC);
		if (Z_TYPE_P(current) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0);
			zephir_fast_array_merge(_0, &(current), &(values) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("values"), _0 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("values"), values TSRMLS_CC);
		}
	} else {
		zephir_update_property_this(this_ptr, SL("values"), values TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Every helper calls this function to check whether a component has a predefined value using Ice\Tag::setValue
 * or value from _POST.
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Ice_Tag, getValue) {

	zval *name_param = NULL, *value = NULL, *_POST, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_fetch(&value, _POST, name, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(value);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
		if (!(zephir_array_isset_fetch(&value, _0, name, 0 TSRMLS_CC))) {
			RETURN_MM_NULL();
		}
	}
	RETURN_CCTOR(value);

}

/**
 * Converts texts into URL-friendly titles.
 *
 * <pre><code>
 *  $title = "Mess'd up --text-- just (to) stress /test/ ?our! `little` \\clean\\ url fun.ction!?-->";
 *  // 'messd-up-text-just-to-stress-test-our-little-clean-url-function'
 *  $friendly = $this->tag->friendlyTitle($title);
 * </code></pre>
 *
 * @param string text
 * @param string separator
 * @param boolean lowercase
 * @param mixed replace
 * @return string
 */
PHP_METHOD(Ice_Tag, friendlyTitle) {

	HashTable *_8;
	HashPosition _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_13 = NULL;
	zend_bool lowercase, _6;
	zval *text_param = NULL, *separator_param = NULL, *lowercase_param = NULL, *replace = NULL, *friendly = NULL, *locale = NULL, *search = NULL, _0 = zval_used_for_init, *_1 = NULL, _3 = zval_used_for_init, *_5 = NULL, **_9, *_10 = NULL, *_11 = NULL, *_12;
	zval *text = NULL, *separator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &separator_param, &lowercase_param, &replace);

	zephir_get_strval(text, text_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(separator);
		ZVAL_STRING(separator, "-", 1);
	} else {
		zephir_get_strval(separator, separator_param);
	}
	if (!lowercase_param) {
		lowercase = 1;
	} else {
		lowercase = zephir_get_boolval(lowercase_param);
	}
	if (!replace) {
		replace = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "iconv", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, 153, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 6);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "en_US.UTF-8", 0);
		ZEPHIR_CALL_FUNCTION(&locale, "setlocale", &_4, 154, &_0, &_3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "UTF-8", 0);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "ASCII//TRANSLIT", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "iconv", NULL, 155, &_0, &_3, text);
		zephir_check_call_status();
		zephir_get_strval(text, _5);
	}
	if (zephir_is_true(replace)) {
		_6 = Z_TYPE_P(replace) != IS_ARRAY;
		if (_6) {
			_6 = Z_TYPE_P(replace) != IS_STRING;
		}
		if (_6) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Parameter replace must be an array or a string", "ice/tag.zep", 868);
			return;
		}
		if (Z_TYPE_P(replace) == IS_ARRAY) {
			zephir_is_iterable(replace, &_8, &_7, 0, 0, "ice/tag.zep", 875);
			for (
			  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
			  ; zephir_hash_move_forward_ex(_8, &_7)
			) {
				ZEPHIR_GET_HVALUE(search, _9);
				ZEPHIR_INIT_NVAR(_10);
				ZEPHIR_SINIT_NVAR(_0);
				ZVAL_STRING(&_0, " ", 0);
				zephir_fast_str_replace(&_10, search, &_0, text TSRMLS_CC);
				zephir_get_strval(text, _10);
			}
		} else {
			ZEPHIR_INIT_NVAR(_10);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, " ", 0);
			zephir_fast_str_replace(&_10, replace, &_3, text TSRMLS_CC);
			zephir_get_strval(text, _10);
		}
	}
	ZEPHIR_INIT_VAR(_11);
	ZVAL_STRING(_11, "/[^a-zA-Z0-9\\/_|+ -]/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_STRING(_12, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&friendly, "preg_replace", &_13, 92, _11, _12, text);
	zephir_check_temp_parameter(_11);
	zephir_check_temp_parameter(_12);
	zephir_check_call_status();
	if (lowercase) {
		ZEPHIR_INIT_NVAR(_11);
		zephir_fast_strtolower(_11, friendly);
		ZEPHIR_CPY_WRT(friendly, _11);
	}
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "/[\\/_|+ -]+/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_5, "preg_replace", &_13, 92, _11, separator, friendly);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(friendly, _5);
	ZEPHIR_INIT_NVAR(_11);
	zephir_fast_trim(_11, friendly, separator, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(friendly, _11);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_STRING(&_3, "iconv", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "extension_loaded", &_2, 153, &_3);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 6);
		ZEPHIR_CALL_FUNCTION(NULL, "setlocale", &_4, 154, &_3, locale);
		zephir_check_call_status();
	}
	RETURN_CCTOR(friendly);

}

/**
 * Get the document type declaration of content.
 *
 * @return string
 */
PHP_METHOD(Ice_Tag, getDocType) {

	zval *_0, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("docType"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(_0, 1)) {
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">", _1);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 2)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"", _1, "\t\"http://www.w3.org/TR/html4/strict.dtd\">", _2);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 3)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"", _1, "\t\"http://www.w3.org/TR/html4/loose.dtd\">", _2);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 4)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"", _1, "\t\"http://www.w3.org/TR/html4/frameset.dtd\">", _2);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 5)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", _1);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 6)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"", _1, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">", _2);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 7)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"", _1, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">", _2);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 8)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"", _1, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">", _2);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 9)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"", _1, "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">", _2);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 10)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"", _1, "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">", _2);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 11)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", _1);
			RETURN_MM();
		}
	} while(0);

	RETURN_MM_STRING("", 1);

}

