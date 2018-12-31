
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
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Tag helper is designed to simplify building of HTML tags.
 *
 * @package     Ice/Tag
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
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

	zend_declare_property_null(ice_tag_ce, SL("meta"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_tag_ce, SL("escape"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_tag_ce->create_object = zephir_init_properties_Ice_Tag;
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

	

	RETURN_MEMBER(getThis(), "di");

}

PHP_METHOD(Ice_Tag, getValues) {

	

	RETURN_MEMBER(getThis(), "values");

}

PHP_METHOD(Ice_Tag, setDocType) {

	zval *docType;

	zephir_fetch_params(0, 1, 0, &docType);



	zephir_update_property_this(getThis(), SL("docType"), docType TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Tag, setTitle) {

	zval *title;

	zephir_fetch_params(0, 1, 0, &title);



	zephir_update_property_this(getThis(), SL("title"), title TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Tag, getTitle) {

	

	RETURN_MEMBER(getThis(), "title");

}

PHP_METHOD(Ice_Tag, setTitleSeparator) {

	zval *titleSeparator;

	zephir_fetch_params(0, 1, 0, &titleSeparator);



	zephir_update_property_this(getThis(), SL("titleSeparator"), titleSeparator TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Tag, getTitleSeparator) {

	

	RETURN_MEMBER(getThis(), "titleSeparator");

}

PHP_METHOD(Ice_Tag, setMeta) {

	zval *meta;

	zephir_fetch_params(0, 1, 0, &meta);



	zephir_update_property_this(getThis(), SL("meta"), meta TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Tag, getMeta) {

	

	RETURN_MEMBER(getThis(), "meta");

}

PHP_METHOD(Ice_Tag, setEscape) {

	zval *escape;

	zephir_fetch_params(0, 1, 0, &escape);



	zephir_update_property_this(getThis(), SL("escape"), escape TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Tag constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Tag, __construct) {

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
 * Appends a text to current document title.
 *
 * @param string title
 * @param string separator
 * @return object Tag
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
	if (!(!separator) && Z_STRLEN_P(separator)) {
		ZEPHIR_CPY_WRT(_1, separator);
	} else {
		ZEPHIR_OBS_NVAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("titleSeparator"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VVV(_2, _0, _1, title);
	zephir_update_property_this(getThis(), SL("title"), _2 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Prepends a text to current document title.
 *
 * @param string title
 * @param string separator
 * @return object Tag
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
	if (!(!separator) && Z_STRLEN_P(separator)) {
		ZEPHIR_CPY_WRT(_0, separator);
	} else {
		ZEPHIR_OBS_NVAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("titleSeparator"), PH_NOISY_CC);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("title"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VVV(_2, title, _0, _1);
	zephir_update_property_this(getThis(), SL("title"), _2 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Add meta tag to the container.
 *
 * @param array parameters
 * @return object this
 */
PHP_METHOD(Ice_Tag, addMeta) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0 = NULL;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "meta", NULL, 0, parameters);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("meta"), _0 TSRMLS_CC);
	RETURN_THIS();

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "text", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, _0, parameters);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "password", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, _0, parameters);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "hidden", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, _0, parameters);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "file", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, _0, parameters);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "submit", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, _0, parameters);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams = NULL, *_1 = NULL, *_2, *_3;
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "checkbox", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, _0, parameters);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *_0;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "radio", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, _0, parameters);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL;
	zval *type_param = NULL, *parameters_param = NULL, *defaultParams = NULL, *_0, *_1, *_2, *_3, *_4, *_5;
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams = NULL, *action = NULL, *local = NULL, *_6 = NULL, *_0$$5, *_1$$6, *_2$$6 = NULL, *_3$$6, *_4$$6 = NULL;
	zval *parameters = NULL, *_5;

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
			zephir_array_fetch_string(&_0$$5, defaultParams, SL("action"), PH_READONLY, "ice/tag.zep", 300 TSRMLS_CC);
			zephir_array_isset_fetch(&action, parameters, _0$$5, 0 TSRMLS_CC);
		}
		if (!ZEPHIR_IS_FALSE_IDENTICAL(action)) {
			_1$$6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_3$$6);
			ZVAL_STRING(_3$$6, "url", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_2$$6, _1$$6, "get", NULL, 0, _3$$6);
			zephir_check_temp_parameter(_3$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$6, _2$$6, "get", NULL, 0, action);
			zephir_check_call_status();
			zephir_array_update_string(&parameters, SL("action"), &_4$$6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "local", 1);
	zephir_array_fast_append(_5, _6);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "form", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _6, parameters, defaultParams, _5);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a FORM close tag.
 *
 * @return string
 */
PHP_METHOD(Ice_Tag, endForm) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "form", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "endtag", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams = NULL, *_1 = NULL, *_2, *_3;
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams = NULL, *src = NULL, *local = NULL, *_6 = NULL, *_7, *_8, *_9, *_10, *_0$$5, *_1$$4, *_2$$4 = NULL, *_3$$4, *_4$$4 = NULL;
	zval *parameters = NULL, *_5;

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
			zephir_array_fetch_string(&_0$$5, defaultParams, SL("src"), PH_READONLY, "ice/tag.zep", 386 TSRMLS_CC);
			zephir_array_isset_fetch(&src, parameters, _0$$5, 0 TSRMLS_CC);
		}
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_STRING(_3$$4, "url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2$$4, _1$$4, "get", NULL, 0, _3$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, _2$$4, "getstatic", NULL, 0, src);
		zephir_check_call_status();
		zephir_array_update_string(&parameters, SL("src"), &_4$$4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "local", 1);
	zephir_array_fast_append(_5, _6);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "img", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_NULL(_7);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_BOOL(_8, 0);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_BOOL(_9, 0);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_BOOL(_10, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _6, parameters, defaultParams, _5, _7, _8, _9, _10);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of the `a` method.
 */
PHP_METHOD(Ice_Tag, linkTo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams = NULL, *href = NULL, *local = NULL, *query = NULL, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_6, *_7, *_0$$3;
	zval *parameters = NULL, *_5;

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
		zephir_array_fetch_string(&_0$$3, defaultParams, SL("href"), PH_READONLY, "ice/tag.zep", 428 TSRMLS_CC);
		zephir_array_isset_fetch(&href, parameters, _0$$3, 0 TSRMLS_CC);
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
	ZEPHIR_CALL_METHOD(&_2, _1, "get", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _2, "get", NULL, 0, href, query, local);
	zephir_check_call_status();
	zephir_array_update_string(&parameters, SL("href"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "text", 1);
	zephir_array_fast_append(_5, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "local", 1);
	zephir_array_fast_append(_5, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "query", 1);
	zephir_array_fast_append(_5, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "a", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "text", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_BOOL(_7, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _3, parameters, defaultParams, _5, _6, _7);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_6);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams = NULL, *href = NULL, *local = NULL, *_6 = NULL, *_7, *_8, *_9, *_10, *_0$$5, *_1$$4, *_2$$4 = NULL, *_3$$4, *_4$$4 = NULL;
	zval *parameters = NULL, *_5;

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
			zephir_array_fetch_string(&_0$$5, defaultParams, SL("href"), PH_READONLY, "ice/tag.zep", 472 TSRMLS_CC);
			zephir_array_isset_fetch(&href, parameters, _0$$5, 0 TSRMLS_CC);
		}
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_STRING(_3$$4, "url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2$$4, _1$$4, "get", NULL, 0, _3$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, _2$$4, "getstatic", NULL, 0, href);
		zephir_check_call_status();
		zephir_array_update_string(&parameters, SL("href"), &_4$$4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "local", 1);
	zephir_array_fast_append(_5, _6);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "link", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_NULL(_7);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_BOOL(_8, 0);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_BOOL(_9, 1);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_BOOL(_10, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _6, parameters, defaultParams, _5, _7, _8, _9, _10);
	zephir_check_temp_parameter(_6);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams = NULL, *src = NULL, *local = NULL, *_5 = NULL, *_7 = NULL, *_8, *_9, *_0$$5, *_1$$6, *_2$$6 = NULL, *_3$$6, *_4$$6 = NULL;
	zval *parameters = NULL, *_6;

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
			zephir_array_fetch_string(&_0$$5, defaultParams, SL("src"), PH_READONLY, "ice/tag.zep", 510 TSRMLS_CC);
			zephir_array_isset_fetch(&src, parameters, _0$$5, 0 TSRMLS_CC);
		}
		if (zephir_is_true(src)) {
			_1$$6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_3$$6);
			ZVAL_STRING(_3$$6, "url", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_2$$6, _1$$6, "get", NULL, 0, _3$$6);
			zephir_check_temp_parameter(_3$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$6, _2$$6, "getstatic", NULL, 0, src);
			zephir_check_call_status();
			zephir_array_update_string(&parameters, SL("src"), &_4$$6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "local", 1);
	zephir_array_fast_append(_6, _7);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "content", 1);
	zephir_array_fast_append(_6, _7);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "script", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "content", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_BOOL(_9, 1);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "taghtml", NULL, 0, _7, parameters, defaultParams, _6, _8, _9);
	zephir_check_temp_parameter(_7);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_7);
	ZEPHIR_GET_CONSTANT(_7, "PHP_EOL");
	ZEPHIR_CONCAT_VV(return_value, _5, _7);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams = NULL, *_1 = NULL, *_2, *_3, *_4;
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
 * Builds a META tag.
 *
 * <pre><code>
 *  // Phtml <meta name="keywords" content="ice, framework">
 *  $this->tag->meta(['ice, framework', 'keywords']);
 *  
 *  // Sleet <meta property="og:description" content="Your description">
 *  {{ meta(['Your description', 'property': 'og:description']) }}
 * </code></pre>
 *
 * @param array parameters
 * @return string
 */
PHP_METHOD(Ice_Tag, meta) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams = NULL, *_0, *_1, *_2, *_3, *_4, *_5;
	zval *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(parameters, parameters_param);


	ZEPHIR_INIT_VAR(defaultParams);
	zephir_create_array(defaultParams, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(defaultParams, SS("content"), 0);
	add_assoc_long_ex(defaultParams, SS("name"), 1);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "meta", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, 1);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_BOOL(_5, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, _1, parameters, defaultParams, _0, _2, _3, _4, _5);
	zephir_check_temp_parameter(_1);
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

	HashTable *_6$$10, *_9$$12;
	HashPosition _5$$10, _8$$12;
	zval *_4$$8 = NULL, *_11$$13 = NULL, *_31$$15 = NULL;
	zephir_fcall_cache_entry *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *defaultParams = NULL, *name = NULL, *options = NULL, *option = NULL, *selected = NULL, *tmp = NULL, *value = NULL, *text = NULL, *group = NULL, *subvalue = NULL, *subtext = NULL, *suboptions = NULL, *_2 = NULL, *_42 = NULL, *_43, *_44, *_45, *_0$$3, *_1$$4, *_3$$5, **_7$$10, *_39$$10, *_40$$10, **_10$$12, *_20$$12 = NULL, *_21$$12 = NULL, *_22$$12 = NULL, *_23$$12 = NULL, *_24$$12 = NULL, *_25$$12 = NULL, *_26$$12 = NULL, *_28$$12 = NULL, *_29$$12 = NULL, *_30$$12 = NULL, *_13$$13 = NULL, *_14$$13 = NULL, *_16$$13 = NULL, *_17$$13 = NULL, *_18$$13 = NULL, *_12$$14 = NULL, *_33$$15 = NULL, *_34$$15 = NULL, *_36$$15 = NULL, *_37$$15 = NULL, *_38$$15 = NULL, *_32$$16 = NULL;
	zval *parameters = NULL, *_41, *_27$$12 = NULL, *_15$$13 = NULL, *_35$$15 = NULL;

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
		zephir_array_fetch_string(&_0$$3, defaultParams, SL("name"), PH_READONLY, "ice/tag.zep", 592 TSRMLS_CC);
		zephir_array_isset_fetch(&name, parameters, _0$$3, 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(options);
	if (!(zephir_array_isset_string_fetch(&options, parameters, SS("options"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(options);
		zephir_array_fetch_string(&_1$$4, defaultParams, SL("options"), PH_READONLY, "ice/tag.zep", 596 TSRMLS_CC);
		zephir_array_isset_fetch(&options, parameters, _1$$4, 0 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "hasvalue", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_CALL_METHOD(&selected, this_ptr, "getvalue", NULL, 0, name);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(selected);
		ZVAL_NULL(selected);
	}
	if (Z_TYPE_P(selected) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_3$$5);
		ZVAL_STRING(_3$$5, "multiple", 1);
		zephir_array_update_string(&parameters, SL("multiple"), &_3$$5, PH_COPY | PH_SEPARATE);
	}
	if (Z_TYPE_P(selected) != IS_ARRAY) {
		if (Z_TYPE_P(selected) == IS_NULL) {
			ZEPHIR_INIT_NVAR(selected);
			array_init(selected);
		} else {
			ZEPHIR_INIT_VAR(tmp);
			zephir_create_array(tmp, 1, 0 TSRMLS_CC);
			zephir_get_strval(_4$$8, selected);
			zephir_array_fast_append(tmp, _4$$8);
			ZEPHIR_CPY_WRT(selected, tmp);
		}
	}
	if (ZEPHIR_IS_EMPTY(options)) {
		ZEPHIR_INIT_NVAR(options);
		ZVAL_STRING(options, "", 1);
	} else {
		zephir_is_iterable(options, &_6$$10, &_5$$10, 1, 0, "ice/tag.zep", 668);
		for (
		  ; zend_hash_get_current_data_ex(_6$$10, (void**) &_7$$10, &_5$$10) == SUCCESS
		  ; zend_hash_move_forward_ex(_6$$10, &_5$$10)
		) {
			ZEPHIR_GET_HMKEY(value, _6$$10, _5$$10);
			ZEPHIR_GET_HVALUE(text, _7$$10);
			if (Z_TYPE_P(text) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(group);
				zephir_create_array(group, 1, 0 TSRMLS_CC);
				zephir_array_update_string(&group, SL("label"), &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(suboptions);
				array_init(suboptions);
				zephir_is_iterable(text, &_9$$12, &_8$$12, 0, 0, "ice/tag.zep", 647);
				for (
				  ; zend_hash_get_current_data_ex(_9$$12, (void**) &_10$$12, &_8$$12) == SUCCESS
				  ; zend_hash_move_forward_ex(_9$$12, &_8$$12)
				) {
					ZEPHIR_GET_HMKEY(subvalue, _9$$12, _8$$12);
					ZEPHIR_GET_HVALUE(subtext, _10$$12);
					zephir_get_strval(_11$$13, subvalue);
					ZEPHIR_CPY_WRT(subvalue, _11$$13);
					ZEPHIR_INIT_NVAR(option);
					zephir_create_array(option, 1, 0 TSRMLS_CC);
					zephir_array_update_string(&option, SL("value"), &subvalue, PH_COPY | PH_SEPARATE);
					if (zephir_fast_in_array(subvalue, selected TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(_12$$14);
						ZVAL_STRING(_12$$14, "selected", 1);
						zephir_array_update_string(&option, SL("selected"), &_12$$14, PH_COPY | PH_SEPARATE);
					}
					zephir_array_update_string(&option, SL("content"), &subtext, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(_14$$13);
					array_init(_14$$13);
					ZEPHIR_INIT_NVAR(_15$$13);
					zephir_create_array(_15$$13, 1, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_16$$13);
					ZVAL_STRING(_16$$13, "content", 1);
					zephir_array_fast_append(_15$$13, _16$$13);
					ZEPHIR_INIT_NVAR(_16$$13);
					ZVAL_STRING(_16$$13, "option", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_INIT_NVAR(_17$$13);
					ZVAL_STRING(_17$$13, "content", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_INIT_NVAR(_18$$13);
					ZVAL_BOOL(_18$$13, 1);
					ZEPHIR_CALL_METHOD(&_13$$13, this_ptr, "taghtml", &_19, 0, _16$$13, option, _14$$13, _15$$13, _17$$13, _18$$13);
					zephir_check_temp_parameter(_16$$13);
					zephir_check_temp_parameter(_17$$13);
					zephir_check_call_status();
					zephir_array_append(&suboptions, _13$$13, PH_SEPARATE, "ice/tag.zep", 643);
				}
				ZEPHIR_INIT_NVAR(_20$$12);
				ZEPHIR_GET_CONSTANT(_20$$12, "PHP_EOL");
				ZEPHIR_INIT_NVAR(_21$$12);
				ZEPHIR_INIT_NVAR(_22$$12);
				ZEPHIR_GET_CONSTANT(_22$$12, "PHP_EOL");
				zephir_fast_join(_21$$12, _22$$12, suboptions TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_23$$12);
				ZEPHIR_GET_CONSTANT(_23$$12, "PHP_EOL");
				ZEPHIR_INIT_LNVAR(_24$$12);
				ZEPHIR_CONCAT_VVV(_24$$12, _20$$12, _21$$12, _23$$12);
				zephir_array_update_string(&group, SL("content"), &_24$$12, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_26$$12);
				array_init(_26$$12);
				ZEPHIR_INIT_NVAR(_27$$12);
				zephir_create_array(_27$$12, 1, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_28$$12);
				ZVAL_STRING(_28$$12, "content", 1);
				zephir_array_fast_append(_27$$12, _28$$12);
				ZEPHIR_INIT_NVAR(_28$$12);
				ZVAL_STRING(_28$$12, "optgroup", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_29$$12);
				ZVAL_STRING(_29$$12, "content", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_30$$12);
				ZVAL_BOOL(_30$$12, 1);
				ZEPHIR_CALL_METHOD(&_25$$12, this_ptr, "taghtml", &_19, 0, _28$$12, group, _26$$12, _27$$12, _29$$12, _30$$12);
				zephir_check_temp_parameter(_28$$12);
				zephir_check_temp_parameter(_29$$12);
				zephir_check_call_status();
				zephir_array_update_zval(&options, value, &_25$$12, PH_COPY | PH_SEPARATE);
			} else {
				zephir_get_strval(_31$$15, value);
				ZEPHIR_CPY_WRT(value, _31$$15);
				ZEPHIR_INIT_NVAR(option);
				zephir_create_array(option, 1, 0 TSRMLS_CC);
				zephir_array_update_string(&option, SL("value"), &value, PH_COPY | PH_SEPARATE);
				if (zephir_fast_in_array(value, selected TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_32$$16);
					ZVAL_STRING(_32$$16, "selected", 1);
					zephir_array_update_string(&option, SL("selected"), &_32$$16, PH_COPY | PH_SEPARATE);
				}
				zephir_array_update_string(&option, SL("content"), &text, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_34$$15);
				array_init(_34$$15);
				ZEPHIR_INIT_NVAR(_35$$15);
				zephir_create_array(_35$$15, 1, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_36$$15);
				ZVAL_STRING(_36$$15, "content", 1);
				zephir_array_fast_append(_35$$15, _36$$15);
				ZEPHIR_INIT_NVAR(_36$$15);
				ZVAL_STRING(_36$$15, "option", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_37$$15);
				ZVAL_STRING(_37$$15, "content", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_38$$15);
				ZVAL_BOOL(_38$$15, 1);
				ZEPHIR_CALL_METHOD(&_33$$15, this_ptr, "taghtml", &_19, 0, _36$$15, option, _34$$15, _35$$15, _37$$15, _38$$15);
				zephir_check_temp_parameter(_36$$15);
				zephir_check_temp_parameter(_37$$15);
				zephir_check_call_status();
				zephir_array_update_zval(&options, value, &_33$$15, PH_COPY | PH_SEPARATE);
			}
		}
		zend_hash_destroy(_6$$10);
		FREE_HASHTABLE(_6$$10);
		ZEPHIR_INIT_VAR(_39$$10);
		ZEPHIR_INIT_VAR(_40$$10);
		ZEPHIR_GET_CONSTANT(_40$$10, "PHP_EOL");
		zephir_fast_join(_39$$10, _40$$10, options TSRMLS_CC);
		zephir_array_update_string(&parameters, SL("content"), &_39$$10, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_41);
	zephir_create_array(_41, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_42);
	ZVAL_STRING(_42, "content", 1);
	zephir_array_fast_append(_41, _42);
	ZEPHIR_INIT_NVAR(_42);
	ZVAL_STRING(_42, "options", 1);
	zephir_array_fast_append(_41, _42);
	ZEPHIR_INIT_NVAR(_42);
	ZVAL_STRING(_42, "value", 1);
	zephir_array_fast_append(_41, _42);
	ZEPHIR_INIT_NVAR(_42);
	ZVAL_STRING(_42, "select", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_43);
	ZVAL_STRING(_43, "content", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_44);
	ZVAL_BOOL(_44, 1);
	ZEPHIR_INIT_VAR(_45);
	ZVAL_BOOL(_45, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", &_19, 0, _42, parameters, defaultParams, _41, _43, _44, _45);
	zephir_check_temp_parameter(_42);
	zephir_check_temp_parameter(_43);
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

	HashTable *_1, *_4;
	HashPosition _0, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool close, eol, single, _8$$9, _9$$9;
	zval *parameters = NULL, *defaultParams = NULL, *skip = NULL;
	zval *name_param = NULL, *parameters_param = NULL, *defaultParams_param = NULL, *skip_param = NULL, *content_param = NULL, *close_param = NULL, *eol_param = NULL, *single_param = NULL, *params = NULL, *param = NULL, *key = NULL, *value = NULL, *attributes = NULL, *code = NULL, **_2, **_5, *_6 = NULL, *_7$$8, *_10$$9 = NULL, *_11$$9, *_12$$10, *_13$$12 = NULL, *_14$$12 = NULL, *_15$$12, *_16$$12;
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
	zephir_is_iterable(defaultParams, &_1, &_0, 0, 0, "ice/tag.zep", 704);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
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
	zephir_is_iterable(defaultParams, &_4, &_3, 0, 0, "ice/tag.zep", 708);
	for (
	  ; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(key, _5);
		zephir_array_unset(&params, key, PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_6);
	zephir_fast_array_merge(_6, &(attributes), &(params) TSRMLS_CC);
	ZEPHIR_CPY_WRT(attributes, _6);
	ZEPHIR_INIT_NVAR(_6);
	if (single) {
		ZVAL_BOOL(_6, 1);
	} else {
		ZVAL_BOOL(_6, 0);
	}
	ZEPHIR_CALL_METHOD(&code, this_ptr, "preparetag", NULL, 0, name, attributes, skip, _6);
	zephir_check_call_status();
	if (eol) {
		ZEPHIR_INIT_VAR(_7$$8);
		ZEPHIR_GET_CONSTANT(_7$$8, "PHP_EOL");
		zephir_concat_self(&code, _7$$8 TSRMLS_CC);
	}
	if (!(!content) && Z_STRLEN_P(content)) {
		_8$$9 = ZEPHIR_IS_STRING(name, "textarea");
		if (_8$$9) {
			_8$$9 = zephir_array_isset_string(attributes, SS("name"));
		}
		_9$$9 = _8$$9;
		if (_9$$9) {
			zephir_array_fetch_string(&_11$$9, attributes, SL("name"), PH_NOISY | PH_READONLY, "ice/tag.zep", 717 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10$$9, this_ptr, "hasvalue", NULL, 0, _11$$9);
			zephir_check_call_status();
			_9$$9 = zephir_is_true(_10$$9);
		}
		if (_9$$9) {
			zephir_array_fetch_string(&_12$$10, attributes, SL("name"), PH_NOISY | PH_READONLY, "ice/tag.zep", 718 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0, _12$$10);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(value);
			zephir_array_isset_fetch(&value, attributes, content, 0 TSRMLS_CC);
		}
		zephir_concat_self(&code, value TSRMLS_CC);
	}
	if (close) {
		ZEPHIR_INIT_VAR(_13$$12);
		if (eol) {
			ZEPHIR_INIT_NVAR(_13$$12);
			ZEPHIR_GET_CONSTANT(_13$$12, "PHP_EOL");
		} else {
			ZEPHIR_INIT_NVAR(_13$$12);
			ZVAL_STRING(_13$$12, "", 1);
		}
		ZEPHIR_INIT_VAR(_15$$12);
		if (eol) {
			ZVAL_BOOL(_15$$12, 1);
		} else {
			ZVAL_BOOL(_15$$12, 0);
		}
		ZEPHIR_CALL_METHOD(&_14$$12, this_ptr, "endtag", NULL, 0, name, _15$$12);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_16$$12);
		ZEPHIR_CONCAT_VV(_16$$12, _13$$12, _14$$12);
		zephir_concat_self(&code, _16$$12 TSRMLS_CC);
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

	HashTable *_11;
	HashPosition _10;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool single, _4$$5, _13$$8, _14$$8, _15$$8;
	zval *attributes = NULL, *skip = NULL;
	zval *name_param = NULL, *attributes_param = NULL, *skip_param = NULL, *single_param = NULL, *order = NULL, *keys = NULL, *attrs = NULL, *code = NULL, *type = NULL, *tmp = NULL, *value = NULL, *key = NULL, *_0 = NULL, *_1 = NULL, **_12, *_3$$3 = NULL, *_5$$5, *_6$$5 = NULL, *_8$$6, *_9$$7 = NULL, *_16$$9, *_21$$9 = NULL, *_17$$10, *_18$$10 = NULL, *_19$$10 = NULL, *_20$$10 = NULL, *_22$$11 = NULL, *_23$$11;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &name_param, &attributes_param, &skip_param, &single_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
	ZEPHIR_CALL_FUNCTION(&_1, "array_flip", NULL, 9, order);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&keys, "array_intersect_key", NULL, 10, _1, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(attrs);
	zephir_fast_array_merge(attrs, &(keys), &(attributes) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "<", name);
	ZEPHIR_CPY_WRT(code, _2);
	ZEPHIR_OBS_VAR(tmp);
	if (zephir_array_isset_string_fetch(&tmp, attrs, SS("name"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "hasvalue", NULL, 0, tmp);
		zephir_check_call_status();
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_OBS_VAR(type);
			zephir_array_isset_string_fetch(&type, attrs, SS("type"), 0 TSRMLS_CC);
			do {
				if (ZEPHIR_IS_STRING(type, "radio") || ZEPHIR_IS_STRING(type, "checkbox")) {
					_4$$5 = zephir_array_isset_string(attrs, SS("value"));
					if (_4$$5) {
						zephir_array_fetch_string(&_5$$5, attrs, SL("value"), PH_NOISY | PH_READONLY, "ice/tag.zep", 777 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "getvalue", &_7, 0, tmp);
						zephir_check_call_status();
						_4$$5 = ZEPHIR_IS_EQUAL(_5$$5, _6$$5);
					}
					if (_4$$5) {
						ZEPHIR_INIT_VAR(_8$$6);
						ZVAL_STRING(_8$$6, "checked", 1);
						zephir_array_update_string(&attrs, SL("checked"), &_8$$6, PH_COPY | PH_SEPARATE);
					}
					break;
				}
				ZEPHIR_CALL_METHOD(&_9$$7, this_ptr, "getvalue", &_7, 0, tmp);
				zephir_check_call_status();
				zephir_array_update_string(&attrs, SL("value"), &_9$$7, PH_COPY | PH_SEPARATE);
				break;
			} while(0);

		}
	}
	zephir_is_iterable(attrs, &_11, &_10, 0, 0, "ice/tag.zep", 797);
	for (
	  ; zend_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
	  ; zend_hash_move_forward_ex(_11, &_10)
	) {
		ZEPHIR_GET_HMKEY(key, _11, _10);
		ZEPHIR_GET_HVALUE(value, _12);
		_13$$8 = Z_TYPE_P(key) == IS_STRING;
		if (_13$$8) {
			_13$$8 = Z_TYPE_P(value) != IS_NULL;
		}
		_14$$8 = _13$$8;
		if (_14$$8) {
			_14$$8 = !ZEPHIR_IS_FALSE_IDENTICAL(value);
		}
		_15$$8 = _14$$8;
		if (_15$$8) {
			_15$$8 = !(zephir_fast_in_array(key, skip TSRMLS_CC));
		}
		if (_15$$8) {
			_16$$9 = zephir_fetch_nproperty_this(this_ptr, SL("escape"), PH_NOISY_CC);
			if (zephir_is_true(_16$$9)) {
				_17$$10 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_19$$10);
				ZVAL_STRING(_19$$10, "filter", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_18$$10, _17$$10, "get", NULL, 0, _19$$10);
				zephir_check_temp_parameter(_19$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_19$$10);
				ZVAL_STRING(_19$$10, "escape", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_20$$10, _18$$10, "sanitize", NULL, 0, value, _19$$10);
				zephir_check_temp_parameter(_19$$10);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(value, _20$$10);
			}
			ZEPHIR_INIT_LNVAR(_21$$9);
			ZEPHIR_CONCAT_SVSVS(_21$$9, " ", key, "=\"", value, "\"");
			zephir_concat_self(&code, _21$$9 TSRMLS_CC);
		}
	}
	if (single) {
		ZEPHIR_INIT_VAR(_22$$11);
		_23$$11 = zephir_fetch_nproperty_this(this_ptr, SL("docType"), PH_NOISY_CC);
		if (ZEPHIR_GT_LONG(_23$$11, 5)) {
			ZEPHIR_INIT_NVAR(_22$$11);
			ZVAL_STRING(_22$$11, " />", 1);
		} else {
			ZEPHIR_INIT_NVAR(_22$$11);
			ZVAL_STRING(_22$$11, ">", 1);
		}
		zephir_concat_self(&code, _22$$11 TSRMLS_CC);
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

	zval *name_param = NULL, *_POST, *_0$$4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	if (zephir_array_isset(_POST, name)) {
		RETURN_MM_BOOL(1);
	} else {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
		if (zephir_array_isset(_0$$4, name)) {
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
 * @return object Tag
 */
PHP_METHOD(Ice_Tag, setValue) {

	zend_bool _0$$3;
	zval *id_param = NULL, *value;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &value);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(id, id_param);
	} else {
		ZEPHIR_INIT_VAR(id);
		ZVAL_EMPTY_STRING(id);
	}


	if (Z_TYPE_P(value) != IS_NULL) {
		_0$$3 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_0$$3)) {
			_0$$3 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Only scalar values can be assigned to UI components", "ice/tag.zep", 838);
			return;
		}
	}
	zephir_update_property_array(this_ptr, SL("values"), id, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Assigns default values to generated tags by helpers.
 *
 * @param array values
 * @param boolean merge
 * @return object Tag
 */
PHP_METHOD(Ice_Tag, setValues) {

	zend_bool merge;
	zval *values_param = NULL, *merge_param = NULL, *current = NULL, *_0$$5;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "An array is required as default values", "ice/tag.zep", 858);
		return;
	}
	if (merge) {
		ZEPHIR_OBS_VAR(current);
		zephir_read_property_this(&current, this_ptr, SL("values"), PH_NOISY_CC);
		if (Z_TYPE_P(current) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$5);
			zephir_fast_array_merge(_0$$5, &(current), &(values) TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("values"), _0$$5 TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("values"), values TSRMLS_CC);
		}
	} else {
		zephir_update_property_this(getThis(), SL("values"), values TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Every helper calls this function to check whether a component has a predefined value using Ice\Tag::setValue
 * or value from _POST.
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Ice_Tag, getValue) {

	zval *name_param = NULL, *_POST, *value = NULL, *_0$$3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_fetch(&value, _POST, name, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(value);
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("values"), PH_NOISY_CC);
		if (!(zephir_array_isset_fetch(&value, _0$$3, name, 0 TSRMLS_CC))) {
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

	HashTable *_9$$6;
	HashPosition _8$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_17 = NULL;
	zend_bool lowercase, _7$$4;
	zval *text_param = NULL, *separator_param = NULL, *lowercase_param = NULL, *replace = NULL, *friendly = NULL, *locale = NULL, *search = NULL, _0 = zval_used_for_init, *_1 = NULL, *_15 = NULL, *_16, *_19 = NULL, _3$$3 = zval_used_for_init, _4$$3 = zval_used_for_init, *_6$$3 = NULL, **_10$$6, *_11$$7 = NULL, _12$$7 = zval_used_for_init, *_13$$8, _14$$8, *_18$$9, _20$$10;
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
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, 202, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, 6);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_STRING(&_4$$3, "en_US.UTF-8", 0);
		ZEPHIR_CALL_FUNCTION(&locale, "setlocale", &_5, 203, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_STRING(&_3$$3, "UTF-8", 0);
		ZEPHIR_SINIT_NVAR(_4$$3);
		ZVAL_STRING(&_4$$3, "ASCII//TRANSLIT", 0);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "iconv", NULL, 204, &_3$$3, &_4$$3, text);
		zephir_check_call_status();
		zephir_get_strval(text, _6$$3);
	}
	if (zephir_is_true(replace)) {
		_7$$4 = Z_TYPE_P(replace) != IS_ARRAY;
		if (_7$$4) {
			_7$$4 = Z_TYPE_P(replace) != IS_STRING;
		}
		if (_7$$4) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Parameter replace must be an array or a string", "ice/tag.zep", 925);
			return;
		}
		if (Z_TYPE_P(replace) == IS_ARRAY) {
			zephir_is_iterable(replace, &_9$$6, &_8$$6, 0, 0, "ice/tag.zep", 932);
			for (
			  ; zend_hash_get_current_data_ex(_9$$6, (void**) &_10$$6, &_8$$6) == SUCCESS
			  ; zend_hash_move_forward_ex(_9$$6, &_8$$6)
			) {
				ZEPHIR_GET_HVALUE(search, _10$$6);
				ZEPHIR_INIT_NVAR(_11$$7);
				ZEPHIR_SINIT_NVAR(_12$$7);
				ZVAL_STRING(&_12$$7, " ", 0);
				zephir_fast_str_replace(&_11$$7, search, &_12$$7, text TSRMLS_CC);
				zephir_get_strval(text, _11$$7);
			}
		} else {
			ZEPHIR_INIT_VAR(_13$$8);
			ZEPHIR_SINIT_VAR(_14$$8);
			ZVAL_STRING(&_14$$8, " ", 0);
			zephir_fast_str_replace(&_13$$8, replace, &_14$$8, text TSRMLS_CC);
			zephir_get_strval(text, _13$$8);
		}
	}
	ZEPHIR_INIT_VAR(_15);
	ZVAL_STRING(_15, "/[^a-zA-Z0-9\\/_|+ -]/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_STRING(_16, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&friendly, "preg_replace", &_17, 93, _15, _16, text);
	zephir_check_temp_parameter(_15);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
	if (lowercase) {
		ZEPHIR_INIT_VAR(_18$$9);
		zephir_fast_strtolower(_18$$9, friendly);
		ZEPHIR_CPY_WRT(friendly, _18$$9);
	}
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "/[\\/_|+ -]+/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_19, "preg_replace", &_17, 93, _15, separator, friendly);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(friendly, _19);
	ZEPHIR_INIT_NVAR(_15);
	zephir_fast_trim(_15, friendly, separator, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(friendly, _15);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "iconv", 0);
	ZEPHIR_CALL_FUNCTION(&_19, "extension_loaded", &_2, 202, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_19)) {
		ZEPHIR_SINIT_VAR(_20$$10);
		ZVAL_LONG(&_20$$10, 6);
		ZEPHIR_CALL_FUNCTION(NULL, "setlocale", &_5, 203, &_20$$10, locale);
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

	zval *_0, *_1$$3, *_2$$4, *_3$$4, *_4$$5, *_5$$5, *_6$$6, *_7$$6, *_8$$7, *_9$$8, *_10$$8, *_11$$9, *_12$$9, *_13$$10, *_14$$10, *_15$$11, *_16$$11, *_17$$12, *_18$$12, *_19$$13;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("docType"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(_0, 1)) {
			ZEPHIR_INIT_VAR(_1$$3);
			ZEPHIR_GET_CONSTANT(_1$$3, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">", _1$$3);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 2)) {
			ZEPHIR_INIT_VAR(_2$$4);
			ZEPHIR_GET_CONSTANT(_2$$4, "PHP_EOL");
			ZEPHIR_INIT_VAR(_3$$4);
			ZEPHIR_GET_CONSTANT(_3$$4, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"", _2$$4, "\t\"http://www.w3.org/TR/html4/strict.dtd\">", _3$$4);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 3)) {
			ZEPHIR_INIT_VAR(_4$$5);
			ZEPHIR_GET_CONSTANT(_4$$5, "PHP_EOL");
			ZEPHIR_INIT_VAR(_5$$5);
			ZEPHIR_GET_CONSTANT(_5$$5, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"", _4$$5, "\t\"http://www.w3.org/TR/html4/loose.dtd\">", _5$$5);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 4)) {
			ZEPHIR_INIT_VAR(_6$$6);
			ZEPHIR_GET_CONSTANT(_6$$6, "PHP_EOL");
			ZEPHIR_INIT_VAR(_7$$6);
			ZEPHIR_GET_CONSTANT(_7$$6, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"", _6$$6, "\t\"http://www.w3.org/TR/html4/frameset.dtd\">", _7$$6);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 5)) {
			ZEPHIR_INIT_VAR(_8$$7);
			ZEPHIR_GET_CONSTANT(_8$$7, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", _8$$7);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 6)) {
			ZEPHIR_INIT_VAR(_9$$8);
			ZEPHIR_GET_CONSTANT(_9$$8, "PHP_EOL");
			ZEPHIR_INIT_VAR(_10$$8);
			ZEPHIR_GET_CONSTANT(_10$$8, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"", _9$$8, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">", _10$$8);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 7)) {
			ZEPHIR_INIT_VAR(_11$$9);
			ZEPHIR_GET_CONSTANT(_11$$9, "PHP_EOL");
			ZEPHIR_INIT_VAR(_12$$9);
			ZEPHIR_GET_CONSTANT(_12$$9, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"", _11$$9, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">", _12$$9);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 8)) {
			ZEPHIR_INIT_VAR(_13$$10);
			ZEPHIR_GET_CONSTANT(_13$$10, "PHP_EOL");
			ZEPHIR_INIT_VAR(_14$$10);
			ZEPHIR_GET_CONSTANT(_14$$10, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"", _13$$10, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">", _14$$10);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 9)) {
			ZEPHIR_INIT_VAR(_15$$11);
			ZEPHIR_GET_CONSTANT(_15$$11, "PHP_EOL");
			ZEPHIR_INIT_VAR(_16$$11);
			ZEPHIR_GET_CONSTANT(_16$$11, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"", _15$$11, "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">", _16$$11);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 10)) {
			ZEPHIR_INIT_VAR(_17$$12);
			ZEPHIR_GET_CONSTANT(_17$$12, "PHP_EOL");
			ZEPHIR_INIT_VAR(_18$$12);
			ZEPHIR_GET_CONSTANT(_18$$12, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"", _17$$12, "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">", _18$$12);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_0, 11)) {
			ZEPHIR_INIT_VAR(_19$$13);
			ZEPHIR_GET_CONSTANT(_19$$13, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", _19$$13);
			RETURN_MM();
		}
	} while(0);

	RETURN_MM_STRING("", 1);

}

zend_object_value zephir_init_properties_Ice_Tag(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

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

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("meta"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("meta"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

