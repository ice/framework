
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
 * @copyright   (c) 2014-2020 Ice Team
 * @license     http://iceframework.org/license
 * @uses        Ice\Mvc\Url
 */
ZEPHIR_INIT_CLASS(Ice_Tag) {

	ZEPHIR_REGISTER_CLASS(Ice, Tag, ice, tag, ice_tag_method_entry, 0);

	zend_declare_property_null(ice_tag_ce, SL("di"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_tag_ce, SL("values"), ZEND_ACC_PROTECTED);

	zend_declare_property_long(ice_tag_ce, SL("docType"), 5, ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_tag_ce, SL("title"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(ice_tag_ce, SL("titleSeparator"), " - ", ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_tag_ce, SL("meta"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(ice_tag_ce, SL("escape"), 1, ZEND_ACC_PROTECTED);

	ice_tag_ce->create_object = zephir_init_properties_Ice_Tag;
	zephir_declare_class_constant_long(ice_tag_ce, SL("HTML32"), 1);

	zephir_declare_class_constant_long(ice_tag_ce, SL("HTML401_STRICT"), 2);

	zephir_declare_class_constant_long(ice_tag_ce, SL("HTML401_TRANSITIONAL"), 3);

	zephir_declare_class_constant_long(ice_tag_ce, SL("HTML401_FRAMESET"), 4);

	zephir_declare_class_constant_long(ice_tag_ce, SL("HTML5"), 5);

	zephir_declare_class_constant_long(ice_tag_ce, SL("XHTML10_STRICT"), 6);

	zephir_declare_class_constant_long(ice_tag_ce, SL("XHTML10_TRANSITIONAL"), 7);

	zephir_declare_class_constant_long(ice_tag_ce, SL("XHTML10_FRAMESET"), 8);

	zephir_declare_class_constant_long(ice_tag_ce, SL("XHTML11"), 9);

	zephir_declare_class_constant_long(ice_tag_ce, SL("XHTML20"), 10);

	zephir_declare_class_constant_long(ice_tag_ce, SL("XHTML5"), 11);

	return SUCCESS;

}

PHP_METHOD(Ice_Tag, getDi) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "di");

}

PHP_METHOD(Ice_Tag, getValues) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "values");

}

PHP_METHOD(Ice_Tag, setDocType) {

	zval *docType, docType_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&docType_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &docType);



	zephir_update_property_zval(this_ptr, ZEND_STRL("docType"), docType);
	RETURN_THISW();

}

PHP_METHOD(Ice_Tag, setTitle) {

	zval *title, title_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &title);



	zephir_update_property_zval(this_ptr, ZEND_STRL("title"), title);
	RETURN_THISW();

}

PHP_METHOD(Ice_Tag, getTitle) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "title");

}

PHP_METHOD(Ice_Tag, setTitleSeparator) {

	zval *titleSeparator, titleSeparator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&titleSeparator_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &titleSeparator);



	zephir_update_property_zval(this_ptr, ZEND_STRL("titleSeparator"), titleSeparator);
	RETURN_THISW();

}

PHP_METHOD(Ice_Tag, getTitleSeparator) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "titleSeparator");

}

PHP_METHOD(Ice_Tag, setMeta) {

	zval *meta, meta_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&meta_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &meta);



	zephir_update_property_zval(this_ptr, ZEND_STRL("meta"), meta);
	RETURN_THISW();

}

PHP_METHOD(Ice_Tag, getMeta) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "meta");

}

PHP_METHOD(Ice_Tag, setEscape) {

	zval *escape, escape_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escape_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &escape);



	zephir_update_property_zval(this_ptr, ZEND_STRL("escape"), escape);
	RETURN_THISW();

}

/**
 * Tag constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Tag, __construct) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("di"), &_0);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *title_param = NULL, *separator_param = NULL, _0, _1, _2;
	zval title, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &title_param, &separator_param);

	zephir_get_strval(&title, title_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "");
	} else {
		zephir_get_strval(&separator, separator_param);
	}


	zephir_read_property(&_0, this_ptr, SL("title"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (!(Z_TYPE_P(&separator) == IS_UNDEF) && Z_STRLEN_P(&separator)) {
		ZEPHIR_CPY_WRT(&_1, &separator);
	} else {
		ZEPHIR_OBS_NVAR(&_1);
		zephir_read_property(&_1, this_ptr, SL("titleSeparator"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VVV(&_2, &_0, &_1, &title);
	zephir_update_property_zval(this_ptr, ZEND_STRL("title"), &_2);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *title_param = NULL, *separator_param = NULL, _0, _1, _2;
	zval title, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &title_param, &separator_param);

	zephir_get_strval(&title, title_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "");
	} else {
		zephir_get_strval(&separator, separator_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&separator) == IS_UNDEF) && Z_STRLEN_P(&separator)) {
		ZEPHIR_CPY_WRT(&_0, &separator);
	} else {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property(&_0, this_ptr, SL("titleSeparator"), PH_NOISY_CC);
	}
	zephir_read_property(&_1, this_ptr, SL("title"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VVV(&_2, &title, &_0, &_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("title"), &_2);
	RETURN_THIS();

}

/**
 * Add meta tag to the container.
 *
 * @param array parameters
 * @return object this
 */
PHP_METHOD(Ice_Tag, addMeta) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "meta", NULL, 0, &parameters);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("meta"), &_0);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "text");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, &_0, &parameters);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "password");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, &_0, &parameters);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "hidden");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, &_0, &parameters);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "file");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, &_0, &parameters);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "submit");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, &_0, &parameters);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, defaultParams, _1, _2, _3;
	zval parameters, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 4, 0);
	add_assoc_long_ex(&defaultParams, SL("id"), 0);
	add_assoc_long_ex(&defaultParams, SL("name"), 0);
	add_assoc_long_ex(&defaultParams, SL("content"), 1);
	add_assoc_stringl_ex(&defaultParams, SL("type"), SL("submit"));
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "content");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "button");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "content");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, &_1, &parameters, &defaultParams, &_0, &_2, &_3);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "checkbox");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, &_0, &parameters);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "radio");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "input", NULL, 0, &_0, &parameters);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *type_param = NULL, *parameters_param = NULL, defaultParams, _0, _1, _2, _3, _4, _5;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &parameters_param);

	zephir_get_strval(&type, type_param);
	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 4, 0);
	add_assoc_long_ex(&defaultParams, SL("id"), 0);
	add_assoc_long_ex(&defaultParams, SL("name"), 0);
	add_assoc_long_ex(&defaultParams, SL("value"), 1);
	zephir_array_update_string(&defaultParams, SL("type"), &type, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "input");
	ZVAL_NULL(&_2);
	ZVAL_BOOL(&_3, 0);
	ZVAL_BOOL(&_4, 0);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, &_1, &parameters, &defaultParams, &_0, &_2, &_3, &_4, &_5);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, defaultParams, action, local, _6, _0$$5, _1$$6, _2$$6, _3$$6, _4$$6;
	zval parameters, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 2, 0);
	add_assoc_long_ex(&defaultParams, SL("action"), 0);
	add_assoc_stringl_ex(&defaultParams, SL("method"), SL("post"));
	ZEPHIR_OBS_VAR(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	if (zephir_is_true(&local)) {
		ZEPHIR_OBS_VAR(&action);
		if (!(zephir_array_isset_string_fetch(&action, &parameters, SL("action"), 0))) {
			ZEPHIR_OBS_NVAR(&action);
			zephir_array_fetch_string(&_0$$5, &defaultParams, SL("action"), PH_READONLY, "ice/tag.zep", 299);
			zephir_array_isset_fetch(&action, &parameters, &_0$$5, 0);
		}
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&action)) {
			zephir_read_property(&_1$$6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_3$$6);
			ZVAL_STRING(&_3$$6, "url");
			ZEPHIR_CALL_METHOD(&_2$$6, &_1$$6, "get", NULL, 0, &_3$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$6, &_2$$6, "get", NULL, 0, &action);
			zephir_check_call_status();
			zephir_array_update_string(&parameters, SL("action"), &_4$$6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "local");
	zephir_array_fast_append(&_5, &_6);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "form");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, &_6, &parameters, &defaultParams, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a FORM close tag.
 *
 * @return string
 */
PHP_METHOD(Ice_Tag, endForm) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "form");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "endtag", NULL, 0, &_0);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, defaultParams, _1, _2, _3;
	zval parameters, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 3, 0);
	add_assoc_long_ex(&defaultParams, SL("id"), 0);
	add_assoc_long_ex(&defaultParams, SL("name"), 0);
	add_assoc_long_ex(&defaultParams, SL("content"), 1);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "content");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "value");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "textarea");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "content");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, &_1, &parameters, &defaultParams, &_0, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of the `img` method.
 */
PHP_METHOD(Ice_Tag, image) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "img", NULL, 0, &parameters);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, defaultParams, src, local, _6, _7, _8, _9, _10, _0$$5, _1$$4, _2$$4, _3$$4, _4$$4;
	zval parameters, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 2, 0);
	add_assoc_long_ex(&defaultParams, SL("src"), 0);
	add_assoc_long_ex(&defaultParams, SL("alt"), 1);
	ZEPHIR_OBS_VAR(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	if (zephir_is_true(&local)) {
		ZEPHIR_OBS_VAR(&src);
		if (!(zephir_array_isset_string_fetch(&src, &parameters, SL("src"), 0))) {
			ZEPHIR_OBS_NVAR(&src);
			zephir_array_fetch_string(&_0$$5, &defaultParams, SL("src"), PH_READONLY, "ice/tag.zep", 385);
			zephir_array_isset_fetch(&src, &parameters, &_0$$5, 0);
		}
		zephir_read_property(&_1$$4, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "url");
		ZEPHIR_CALL_METHOD(&_2$$4, &_1$$4, "get", NULL, 0, &_3$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, &_2$$4, "getstatic", NULL, 0, &src);
		zephir_check_call_status();
		zephir_array_update_string(&parameters, SL("src"), &_4$$4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "local");
	zephir_array_fast_append(&_5, &_6);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "img");
	ZVAL_NULL(&_7);
	ZVAL_BOOL(&_8, 0);
	ZVAL_BOOL(&_9, 0);
	ZVAL_BOOL(&_10, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, &_6, &parameters, &defaultParams, &_5, &_7, &_8, &_9, &_10);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of the `a` method.
 */
PHP_METHOD(Ice_Tag, linkTo) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "a", NULL, 0, &parameters);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, defaultParams, href, local, query, _1, _2, _3, _4, _6, _7, _0$$3;
	zval parameters, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 3, 0);
	add_assoc_long_ex(&defaultParams, SL("href"), 0);
	add_assoc_long_ex(&defaultParams, SL("text"), 1);
	add_assoc_long_ex(&defaultParams, SL("title"), 2);
	ZEPHIR_OBS_VAR(&href);
	if (!(zephir_array_isset_string_fetch(&href, &parameters, SL("href"), 0))) {
		ZEPHIR_OBS_NVAR(&href);
		zephir_array_fetch_string(&_0$$3, &defaultParams, SL("href"), PH_READONLY, "ice/tag.zep", 427);
		zephir_array_isset_fetch(&href, &parameters, &_0$$3, 0);
	}
	ZEPHIR_OBS_VAR(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	ZEPHIR_OBS_VAR(&query);
	zephir_array_isset_string_fetch(&query, &parameters, SL("query"), 0);
	zephir_read_property(&_1, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "url");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_2, "get", NULL, 0, &href, &query, &local);
	zephir_check_call_status();
	zephir_array_update_string(&parameters, SL("href"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 3, 0);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "text");
	zephir_array_fast_append(&_5, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "local");
	zephir_array_fast_append(&_5, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "query");
	zephir_array_fast_append(&_5, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "a");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "text");
	ZVAL_BOOL(&_7, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, &_3, &parameters, &defaultParams, &_5, &_6, &_7);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, defaultParams, href, local, _6, _7, _8, _9, _10, _0$$5, _1$$4, _2$$4, _3$$4, _4$$4;
	zval parameters, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 3, 0);
	add_assoc_long_ex(&defaultParams, SL("href"), 0);
	add_assoc_stringl_ex(&defaultParams, SL("type"), SL("text/css"));
	add_assoc_stringl_ex(&defaultParams, SL("rel"), SL("stylesheet"));
	ZEPHIR_OBS_VAR(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	if (zephir_is_true(&local)) {
		ZEPHIR_OBS_VAR(&href);
		if (!(zephir_array_isset_string_fetch(&href, &parameters, SL("href"), 0))) {
			ZEPHIR_OBS_NVAR(&href);
			zephir_array_fetch_string(&_0$$5, &defaultParams, SL("href"), PH_READONLY, "ice/tag.zep", 471);
			zephir_array_isset_fetch(&href, &parameters, &_0$$5, 0);
		}
		zephir_read_property(&_1$$4, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "url");
		ZEPHIR_CALL_METHOD(&_2$$4, &_1$$4, "get", NULL, 0, &_3$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, &_2$$4, "getstatic", NULL, 0, &href);
		zephir_check_call_status();
		zephir_array_update_string(&parameters, SL("href"), &_4$$4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "local");
	zephir_array_fast_append(&_5, &_6);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "link");
	ZVAL_NULL(&_7);
	ZVAL_BOOL(&_8, 0);
	ZVAL_BOOL(&_9, 1);
	ZVAL_BOOL(&_10, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, &_6, &parameters, &defaultParams, &_5, &_7, &_8, &_9, &_10);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, defaultParams, src, local, _5, _7, _8, _9, _0$$5, _1$$6, _2$$6, _3$$6, _4$$6;
	zval parameters, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 2, 0);
	add_assoc_long_ex(&defaultParams, SL("src"), 0);
	add_assoc_stringl_ex(&defaultParams, SL("type"), SL("text/javascript"));
	ZEPHIR_OBS_VAR(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	if (zephir_is_true(&local)) {
		ZEPHIR_OBS_VAR(&src);
		if (!(zephir_array_isset_string_fetch(&src, &parameters, SL("src"), 0))) {
			ZEPHIR_OBS_NVAR(&src);
			zephir_array_fetch_string(&_0$$5, &defaultParams, SL("src"), PH_READONLY, "ice/tag.zep", 509);
			zephir_array_isset_fetch(&src, &parameters, &_0$$5, 0);
		}
		if (zephir_is_true(&src)) {
			zephir_read_property(&_1$$6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_3$$6);
			ZVAL_STRING(&_3$$6, "url");
			ZEPHIR_CALL_METHOD(&_2$$6, &_1$$6, "get", NULL, 0, &_3$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$6, &_2$$6, "getstatic", NULL, 0, &src);
			zephir_check_call_status();
			zephir_array_update_string(&parameters, SL("src"), &_4$$6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "local");
	zephir_array_fast_append(&_6, &_7);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "content");
	zephir_array_fast_append(&_6, &_7);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "script");
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "content");
	ZVAL_BOOL(&_9, 1);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "taghtml", NULL, 0, &_7, &parameters, &defaultParams, &_6, &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_7);
	ZEPHIR_GET_CONSTANT(&_7, "PHP_EOL");
	ZEPHIR_CONCAT_VV(return_value, &_5, &_7);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, defaultParams, _1, _2, _3, _4;
	zval parameters, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 2, 0);
	add_assoc_long_ex(&defaultParams, SL("content"), 0);
	add_assoc_stringl_ex(&defaultParams, SL("type"), SL("text/css"));
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "content");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "style");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "content");
	ZVAL_BOOL(&_3, 1);
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, &_1, &parameters, &defaultParams, &_0, &_2, &_3, &_4);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, defaultParams, _0, _1, _2, _3, _4, _5;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 2, 0);
	add_assoc_long_ex(&defaultParams, SL("content"), 0);
	add_assoc_long_ex(&defaultParams, SL("name"), 1);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "meta");
	ZVAL_NULL(&_2);
	ZVAL_BOOL(&_3, 0);
	ZVAL_BOOL(&_4, 1);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", NULL, 0, &_1, &parameters, &defaultParams, &_0, &_2, &_3, &_4, &_5);
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

	zend_string *_8$$10, *_12$$12, *_55$$20;
	zend_ulong _7$$10, _11$$12, _54$$20;
	zval _4$$8, _13$$13, _22$$15, _42$$17, _56$$21, _65$$23, _85$$25;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, defaultParams, name, options, option, selected, tmp, value, text, group, subvalue, subtext, suboptions, _2, _97, _98, _99, _100, _0$$3, _1$$4, _3$$5, *_5$$10, _6$$10, _94$$10, _95$$10, *_9$$12, _10$$12, _31$$12, _32$$12, _33$$12, _34$$12, _35$$12, _36$$12, _37$$12, _39$$12, _40$$12, _41$$12, _15$$13, _16$$13, _18$$13, _19$$13, _20$$13, _14$$14, _23$$15, _25$$15, _26$$15, _28$$15, _29$$15, _30$$15, _24$$16, _43$$17, _45$$17, _46$$17, _48$$17, _49$$17, _50$$17, _44$$18, _51$$20, *_52$$20, _53$$20, _74$$20, _75$$20, _76$$20, _77$$20, _78$$20, _79$$20, _80$$20, _82$$20, _83$$20, _84$$20, _57$$21, _59$$21, _60$$21, _62$$21, _63$$21, _64$$21, _58$$22, _66$$23, _68$$23, _69$$23, _71$$23, _72$$23, _73$$23, _67$$24, _86$$25, _88$$25, _89$$25, _91$$25, _92$$25, _93$$25, _87$$26;
	zval parameters, _96, _38$$12, _17$$13, _27$$15, _47$$17, _81$$20, _61$$21, _70$$23, _90$$25;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_96);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_81$$20);
	ZVAL_UNDEF(&_61$$21);
	ZVAL_UNDEF(&_70$$23);
	ZVAL_UNDEF(&_90$$25);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&selected);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&subvalue);
	ZVAL_UNDEF(&subtext);
	ZVAL_UNDEF(&suboptions);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_97);
	ZVAL_UNDEF(&_98);
	ZVAL_UNDEF(&_99);
	ZVAL_UNDEF(&_100);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_94$$10);
	ZVAL_UNDEF(&_95$$10);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_35$$12);
	ZVAL_UNDEF(&_36$$12);
	ZVAL_UNDEF(&_37$$12);
	ZVAL_UNDEF(&_39$$12);
	ZVAL_UNDEF(&_40$$12);
	ZVAL_UNDEF(&_41$$12);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_48$$17);
	ZVAL_UNDEF(&_49$$17);
	ZVAL_UNDEF(&_50$$17);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_51$$20);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_74$$20);
	ZVAL_UNDEF(&_75$$20);
	ZVAL_UNDEF(&_76$$20);
	ZVAL_UNDEF(&_77$$20);
	ZVAL_UNDEF(&_78$$20);
	ZVAL_UNDEF(&_79$$20);
	ZVAL_UNDEF(&_80$$20);
	ZVAL_UNDEF(&_82$$20);
	ZVAL_UNDEF(&_83$$20);
	ZVAL_UNDEF(&_84$$20);
	ZVAL_UNDEF(&_57$$21);
	ZVAL_UNDEF(&_59$$21);
	ZVAL_UNDEF(&_60$$21);
	ZVAL_UNDEF(&_62$$21);
	ZVAL_UNDEF(&_63$$21);
	ZVAL_UNDEF(&_64$$21);
	ZVAL_UNDEF(&_58$$22);
	ZVAL_UNDEF(&_66$$23);
	ZVAL_UNDEF(&_68$$23);
	ZVAL_UNDEF(&_69$$23);
	ZVAL_UNDEF(&_71$$23);
	ZVAL_UNDEF(&_72$$23);
	ZVAL_UNDEF(&_73$$23);
	ZVAL_UNDEF(&_67$$24);
	ZVAL_UNDEF(&_86$$25);
	ZVAL_UNDEF(&_88$$25);
	ZVAL_UNDEF(&_89$$25);
	ZVAL_UNDEF(&_91$$25);
	ZVAL_UNDEF(&_92$$25);
	ZVAL_UNDEF(&_93$$25);
	ZVAL_UNDEF(&_87$$26);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_42$$17);
	ZVAL_UNDEF(&_56$$21);
	ZVAL_UNDEF(&_65$$23);
	ZVAL_UNDEF(&_85$$25);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 3, 0);
	add_assoc_long_ex(&defaultParams, SL("id"), 0);
	add_assoc_long_ex(&defaultParams, SL("name"), 0);
	add_assoc_long_ex(&defaultParams, SL("options"), 1);
	ZEPHIR_OBS_VAR(&name);
	if (!(zephir_array_isset_string_fetch(&name, &parameters, SL("name"), 0))) {
		ZEPHIR_OBS_NVAR(&name);
		zephir_array_fetch_string(&_0$$3, &defaultParams, SL("name"), PH_READONLY, "ice/tag.zep", 591);
		zephir_array_isset_fetch(&name, &parameters, &_0$$3, 0);
	}
	ZEPHIR_OBS_VAR(&options);
	if (!(zephir_array_isset_string_fetch(&options, &parameters, SL("options"), 0))) {
		ZEPHIR_OBS_NVAR(&options);
		zephir_array_fetch_string(&_1$$4, &defaultParams, SL("options"), PH_READONLY, "ice/tag.zep", 595);
		zephir_array_isset_fetch(&options, &parameters, &_1$$4, 0);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "hasvalue", NULL, 0, &name);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&selected, this_ptr, "getvalue", NULL, 0, &name);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&selected);
		ZVAL_NULL(&selected);
	}
	if (Z_TYPE_P(&selected) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "multiple");
		zephir_array_update_string(&parameters, SL("multiple"), &_3$$5, PH_COPY | PH_SEPARATE);
	}
	if (Z_TYPE_P(&selected) != IS_ARRAY) {
		if (Z_TYPE_P(&selected) == IS_NULL) {
			ZEPHIR_INIT_NVAR(&selected);
			array_init(&selected);
		} else {
			ZEPHIR_INIT_VAR(&tmp);
			zephir_create_array(&tmp, 1, 0);
			zephir_get_strval(&_4$$8, &selected);
			zephir_array_fast_append(&tmp, &_4$$8);
			ZEPHIR_CPY_WRT(&selected, &tmp);
		}
	}
	if (ZEPHIR_IS_EMPTY(&options)) {
		ZEPHIR_INIT_NVAR(&options);
		ZVAL_STRING(&options, "");
	} else {
		zephir_is_iterable(&options, 1, "ice/tag.zep", 667);
		if (Z_TYPE_P(&options) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _7$$10, _8$$10, _5$$10)
			{
				ZEPHIR_INIT_NVAR(&value);
				if (_8$$10 != NULL) { 
					ZVAL_STR_COPY(&value, _8$$10);
				} else {
					ZVAL_LONG(&value, _7$$10);
				}
				ZEPHIR_INIT_NVAR(&text);
				ZVAL_COPY(&text, _5$$10);
				if (Z_TYPE_P(&text) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&group);
					zephir_create_array(&group, 1, 0);
					zephir_array_update_string(&group, SL("label"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&suboptions);
					array_init(&suboptions);
					zephir_is_iterable(&text, 0, "ice/tag.zep", 646);
					if (Z_TYPE_P(&text) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&text), _11$$12, _12$$12, _9$$12)
						{
							ZEPHIR_INIT_NVAR(&subvalue);
							if (_12$$12 != NULL) { 
								ZVAL_STR_COPY(&subvalue, _12$$12);
							} else {
								ZVAL_LONG(&subvalue, _11$$12);
							}
							ZEPHIR_INIT_NVAR(&subtext);
							ZVAL_COPY(&subtext, _9$$12);
							zephir_get_strval(&_13$$13, &subvalue);
							ZEPHIR_CPY_WRT(&subvalue, &_13$$13);
							ZEPHIR_INIT_NVAR(&option);
							zephir_create_array(&option, 1, 0);
							zephir_array_update_string(&option, SL("value"), &subvalue, PH_COPY | PH_SEPARATE);
							if (zephir_fast_in_array(&subvalue, &selected)) {
								ZEPHIR_INIT_NVAR(&_14$$14);
								ZVAL_STRING(&_14$$14, "selected");
								zephir_array_update_string(&option, SL("selected"), &_14$$14, PH_COPY | PH_SEPARATE);
							}
							zephir_array_update_string(&option, SL("content"), &subtext, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_16$$13);
							array_init(&_16$$13);
							ZEPHIR_INIT_NVAR(&_17$$13);
							zephir_create_array(&_17$$13, 1, 0);
							ZEPHIR_INIT_NVAR(&_18$$13);
							ZVAL_STRING(&_18$$13, "content");
							zephir_array_fast_append(&_17$$13, &_18$$13);
							ZEPHIR_INIT_NVAR(&_18$$13);
							ZVAL_STRING(&_18$$13, "option");
							ZEPHIR_INIT_NVAR(&_19$$13);
							ZVAL_STRING(&_19$$13, "content");
							ZVAL_BOOL(&_20$$13, 1);
							ZEPHIR_CALL_METHOD(&_15$$13, this_ptr, "taghtml", &_21, 0, &_18$$13, &option, &_16$$13, &_17$$13, &_19$$13, &_20$$13);
							zephir_check_call_status();
							zephir_array_append(&suboptions, &_15$$13, PH_SEPARATE, "ice/tag.zep", 642);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &text, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_10$$12, &text, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_10$$12)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&subvalue, &text, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&subtext, &text, "current", NULL, 0);
							zephir_check_call_status();
								zephir_get_strval(&_22$$15, &subvalue);
								ZEPHIR_CPY_WRT(&subvalue, &_22$$15);
								ZEPHIR_INIT_NVAR(&_23$$15);
								zephir_create_array(&_23$$15, 1, 0);
								zephir_array_update_string(&_23$$15, SL("value"), &subvalue, PH_COPY | PH_SEPARATE);
								ZEPHIR_CPY_WRT(&option, &_23$$15);
								if (zephir_fast_in_array(&subvalue, &selected)) {
									ZEPHIR_INIT_NVAR(&_24$$16);
									ZVAL_STRING(&_24$$16, "selected");
									zephir_array_update_string(&option, SL("selected"), &_24$$16, PH_COPY | PH_SEPARATE);
								}
								zephir_array_update_string(&option, SL("content"), &subtext, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_26$$15);
								array_init(&_26$$15);
								ZEPHIR_INIT_NVAR(&_27$$15);
								zephir_create_array(&_27$$15, 1, 0);
								ZEPHIR_INIT_NVAR(&_28$$15);
								ZVAL_STRING(&_28$$15, "content");
								zephir_array_fast_append(&_27$$15, &_28$$15);
								ZEPHIR_INIT_NVAR(&_28$$15);
								ZVAL_STRING(&_28$$15, "option");
								ZEPHIR_INIT_NVAR(&_29$$15);
								ZVAL_STRING(&_29$$15, "content");
								ZVAL_BOOL(&_30$$15, 1);
								ZEPHIR_CALL_METHOD(&_25$$15, this_ptr, "taghtml", &_21, 0, &_28$$15, &option, &_26$$15, &_27$$15, &_29$$15, &_30$$15);
								zephir_check_call_status();
								zephir_array_append(&suboptions, &_25$$15, PH_SEPARATE, "ice/tag.zep", 642);
							ZEPHIR_CALL_METHOD(NULL, &text, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&subtext);
					ZEPHIR_INIT_NVAR(&subvalue);
					ZEPHIR_INIT_NVAR(&_31$$12);
					ZEPHIR_GET_CONSTANT(&_31$$12, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_32$$12);
					ZEPHIR_INIT_NVAR(&_33$$12);
					ZEPHIR_GET_CONSTANT(&_33$$12, "PHP_EOL");
					zephir_fast_join(&_32$$12, &_33$$12, &suboptions);
					ZEPHIR_INIT_NVAR(&_34$$12);
					ZEPHIR_GET_CONSTANT(&_34$$12, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_35$$12);
					ZEPHIR_CONCAT_VVV(&_35$$12, &_31$$12, &_32$$12, &_34$$12);
					zephir_array_update_string(&group, SL("content"), &_35$$12, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_37$$12);
					array_init(&_37$$12);
					ZEPHIR_INIT_NVAR(&_38$$12);
					zephir_create_array(&_38$$12, 1, 0);
					ZEPHIR_INIT_NVAR(&_39$$12);
					ZVAL_STRING(&_39$$12, "content");
					zephir_array_fast_append(&_38$$12, &_39$$12);
					ZEPHIR_INIT_NVAR(&_39$$12);
					ZVAL_STRING(&_39$$12, "optgroup");
					ZEPHIR_INIT_NVAR(&_40$$12);
					ZVAL_STRING(&_40$$12, "content");
					ZVAL_BOOL(&_41$$12, 1);
					ZEPHIR_CALL_METHOD(&_36$$12, this_ptr, "taghtml", &_21, 0, &_39$$12, &group, &_37$$12, &_38$$12, &_40$$12, &_41$$12);
					zephir_check_call_status();
					zephir_array_update_zval(&options, &value, &_36$$12, PH_COPY | PH_SEPARATE);
				} else {
					zephir_get_strval(&_42$$17, &value);
					ZEPHIR_CPY_WRT(&value, &_42$$17);
					ZEPHIR_INIT_NVAR(&_43$$17);
					zephir_create_array(&_43$$17, 1, 0);
					zephir_array_update_string(&_43$$17, SL("value"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&option, &_43$$17);
					if (zephir_fast_in_array(&value, &selected)) {
						ZEPHIR_INIT_NVAR(&_44$$18);
						ZVAL_STRING(&_44$$18, "selected");
						zephir_array_update_string(&option, SL("selected"), &_44$$18, PH_COPY | PH_SEPARATE);
					}
					zephir_array_update_string(&option, SL("content"), &text, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_46$$17);
					array_init(&_46$$17);
					ZEPHIR_INIT_NVAR(&_47$$17);
					zephir_create_array(&_47$$17, 1, 0);
					ZEPHIR_INIT_NVAR(&_48$$17);
					ZVAL_STRING(&_48$$17, "content");
					zephir_array_fast_append(&_47$$17, &_48$$17);
					ZEPHIR_INIT_NVAR(&_48$$17);
					ZVAL_STRING(&_48$$17, "option");
					ZEPHIR_INIT_NVAR(&_49$$17);
					ZVAL_STRING(&_49$$17, "content");
					ZVAL_BOOL(&_50$$17, 1);
					ZEPHIR_CALL_METHOD(&_45$$17, this_ptr, "taghtml", &_21, 0, &_48$$17, &option, &_46$$17, &_47$$17, &_49$$17, &_50$$17);
					zephir_check_call_status();
					zephir_array_update_zval(&options, &value, &_45$$17, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$10, &options, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$10)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&value, &options, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&text, &options, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&text) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_51$$20);
						zephir_create_array(&_51$$20, 1, 0);
						zephir_array_update_string(&_51$$20, SL("label"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&group, &_51$$20);
						ZEPHIR_INIT_NVAR(&suboptions);
						array_init(&suboptions);
						zephir_is_iterable(&text, 0, "ice/tag.zep", 646);
						if (Z_TYPE_P(&text) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&text), _54$$20, _55$$20, _52$$20)
							{
								ZEPHIR_INIT_NVAR(&subvalue);
								if (_55$$20 != NULL) { 
									ZVAL_STR_COPY(&subvalue, _55$$20);
								} else {
									ZVAL_LONG(&subvalue, _54$$20);
								}
								ZEPHIR_INIT_NVAR(&subtext);
								ZVAL_COPY(&subtext, _52$$20);
								zephir_get_strval(&_56$$21, &subvalue);
								ZEPHIR_CPY_WRT(&subvalue, &_56$$21);
								ZEPHIR_INIT_NVAR(&_57$$21);
								zephir_create_array(&_57$$21, 1, 0);
								zephir_array_update_string(&_57$$21, SL("value"), &subvalue, PH_COPY | PH_SEPARATE);
								ZEPHIR_CPY_WRT(&option, &_57$$21);
								if (zephir_fast_in_array(&subvalue, &selected)) {
									ZEPHIR_INIT_NVAR(&_58$$22);
									ZVAL_STRING(&_58$$22, "selected");
									zephir_array_update_string(&option, SL("selected"), &_58$$22, PH_COPY | PH_SEPARATE);
								}
								zephir_array_update_string(&option, SL("content"), &subtext, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_60$$21);
								array_init(&_60$$21);
								ZEPHIR_INIT_NVAR(&_61$$21);
								zephir_create_array(&_61$$21, 1, 0);
								ZEPHIR_INIT_NVAR(&_62$$21);
								ZVAL_STRING(&_62$$21, "content");
								zephir_array_fast_append(&_61$$21, &_62$$21);
								ZEPHIR_INIT_NVAR(&_62$$21);
								ZVAL_STRING(&_62$$21, "option");
								ZEPHIR_INIT_NVAR(&_63$$21);
								ZVAL_STRING(&_63$$21, "content");
								ZVAL_BOOL(&_64$$21, 1);
								ZEPHIR_CALL_METHOD(&_59$$21, this_ptr, "taghtml", &_21, 0, &_62$$21, &option, &_60$$21, &_61$$21, &_63$$21, &_64$$21);
								zephir_check_call_status();
								zephir_array_append(&suboptions, &_59$$21, PH_SEPARATE, "ice/tag.zep", 642);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &text, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_53$$20, &text, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_53$$20)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&subvalue, &text, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&subtext, &text, "current", NULL, 0);
								zephir_check_call_status();
									zephir_get_strval(&_65$$23, &subvalue);
									ZEPHIR_CPY_WRT(&subvalue, &_65$$23);
									ZEPHIR_INIT_NVAR(&_66$$23);
									zephir_create_array(&_66$$23, 1, 0);
									zephir_array_update_string(&_66$$23, SL("value"), &subvalue, PH_COPY | PH_SEPARATE);
									ZEPHIR_CPY_WRT(&option, &_66$$23);
									if (zephir_fast_in_array(&subvalue, &selected)) {
										ZEPHIR_INIT_NVAR(&_67$$24);
										ZVAL_STRING(&_67$$24, "selected");
										zephir_array_update_string(&option, SL("selected"), &_67$$24, PH_COPY | PH_SEPARATE);
									}
									zephir_array_update_string(&option, SL("content"), &subtext, PH_COPY | PH_SEPARATE);
									ZEPHIR_INIT_NVAR(&_69$$23);
									array_init(&_69$$23);
									ZEPHIR_INIT_NVAR(&_70$$23);
									zephir_create_array(&_70$$23, 1, 0);
									ZEPHIR_INIT_NVAR(&_71$$23);
									ZVAL_STRING(&_71$$23, "content");
									zephir_array_fast_append(&_70$$23, &_71$$23);
									ZEPHIR_INIT_NVAR(&_71$$23);
									ZVAL_STRING(&_71$$23, "option");
									ZEPHIR_INIT_NVAR(&_72$$23);
									ZVAL_STRING(&_72$$23, "content");
									ZVAL_BOOL(&_73$$23, 1);
									ZEPHIR_CALL_METHOD(&_68$$23, this_ptr, "taghtml", &_21, 0, &_71$$23, &option, &_69$$23, &_70$$23, &_72$$23, &_73$$23);
									zephir_check_call_status();
									zephir_array_append(&suboptions, &_68$$23, PH_SEPARATE, "ice/tag.zep", 642);
								ZEPHIR_CALL_METHOD(NULL, &text, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&subtext);
						ZEPHIR_INIT_NVAR(&subvalue);
						ZEPHIR_INIT_NVAR(&_74$$20);
						ZEPHIR_GET_CONSTANT(&_74$$20, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_75$$20);
						ZEPHIR_INIT_NVAR(&_76$$20);
						ZEPHIR_GET_CONSTANT(&_76$$20, "PHP_EOL");
						zephir_fast_join(&_75$$20, &_76$$20, &suboptions);
						ZEPHIR_INIT_NVAR(&_77$$20);
						ZEPHIR_GET_CONSTANT(&_77$$20, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_78$$20);
						ZEPHIR_CONCAT_VVV(&_78$$20, &_74$$20, &_75$$20, &_77$$20);
						zephir_array_update_string(&group, SL("content"), &_78$$20, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_80$$20);
						array_init(&_80$$20);
						ZEPHIR_INIT_NVAR(&_81$$20);
						zephir_create_array(&_81$$20, 1, 0);
						ZEPHIR_INIT_NVAR(&_82$$20);
						ZVAL_STRING(&_82$$20, "content");
						zephir_array_fast_append(&_81$$20, &_82$$20);
						ZEPHIR_INIT_NVAR(&_82$$20);
						ZVAL_STRING(&_82$$20, "optgroup");
						ZEPHIR_INIT_NVAR(&_83$$20);
						ZVAL_STRING(&_83$$20, "content");
						ZVAL_BOOL(&_84$$20, 1);
						ZEPHIR_CALL_METHOD(&_79$$20, this_ptr, "taghtml", &_21, 0, &_82$$20, &group, &_80$$20, &_81$$20, &_83$$20, &_84$$20);
						zephir_check_call_status();
						zephir_array_update_zval(&options, &value, &_79$$20, PH_COPY | PH_SEPARATE);
					} else {
						zephir_get_strval(&_85$$25, &value);
						ZEPHIR_CPY_WRT(&value, &_85$$25);
						ZEPHIR_INIT_NVAR(&_86$$25);
						zephir_create_array(&_86$$25, 1, 0);
						zephir_array_update_string(&_86$$25, SL("value"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&option, &_86$$25);
						if (zephir_fast_in_array(&value, &selected)) {
							ZEPHIR_INIT_NVAR(&_87$$26);
							ZVAL_STRING(&_87$$26, "selected");
							zephir_array_update_string(&option, SL("selected"), &_87$$26, PH_COPY | PH_SEPARATE);
						}
						zephir_array_update_string(&option, SL("content"), &text, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_89$$25);
						array_init(&_89$$25);
						ZEPHIR_INIT_NVAR(&_90$$25);
						zephir_create_array(&_90$$25, 1, 0);
						ZEPHIR_INIT_NVAR(&_91$$25);
						ZVAL_STRING(&_91$$25, "content");
						zephir_array_fast_append(&_90$$25, &_91$$25);
						ZEPHIR_INIT_NVAR(&_91$$25);
						ZVAL_STRING(&_91$$25, "option");
						ZEPHIR_INIT_NVAR(&_92$$25);
						ZVAL_STRING(&_92$$25, "content");
						ZVAL_BOOL(&_93$$25, 1);
						ZEPHIR_CALL_METHOD(&_88$$25, this_ptr, "taghtml", &_21, 0, &_91$$25, &option, &_89$$25, &_90$$25, &_92$$25, &_93$$25);
						zephir_check_call_status();
						zephir_array_update_zval(&options, &value, &_88$$25, PH_COPY | PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&text);
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_VAR(&_94$$10);
		ZEPHIR_INIT_VAR(&_95$$10);
		ZEPHIR_GET_CONSTANT(&_95$$10, "PHP_EOL");
		zephir_fast_join(&_94$$10, &_95$$10, &options);
		zephir_array_update_string(&parameters, SL("content"), &_94$$10, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_96);
	zephir_create_array(&_96, 3, 0);
	ZEPHIR_INIT_VAR(&_97);
	ZVAL_STRING(&_97, "content");
	zephir_array_fast_append(&_96, &_97);
	ZEPHIR_INIT_NVAR(&_97);
	ZVAL_STRING(&_97, "options");
	zephir_array_fast_append(&_96, &_97);
	ZEPHIR_INIT_NVAR(&_97);
	ZVAL_STRING(&_97, "value");
	zephir_array_fast_append(&_96, &_97);
	ZEPHIR_INIT_NVAR(&_97);
	ZVAL_STRING(&_97, "select");
	ZEPHIR_INIT_VAR(&_98);
	ZVAL_STRING(&_98, "content");
	ZVAL_BOOL(&_99, 1);
	ZVAL_BOOL(&_100, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", &_21, 0, &_97, &parameters, &defaultParams, &_96, &_98, &_99, &_100);
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

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool close, eol, single, _9$$14, _10$$14;
	zval parameters, defaultParams, skip;
	zval *name_param = NULL, *parameters_param = NULL, *defaultParams_param = NULL, *skip_param = NULL, *content_param = NULL, *close_param = NULL, *eol_param = NULL, *single_param = NULL, params, param, key, value, attributes, code, *_0, _1, *_4, _5, _6, _7, _8$$13, _11$$14, _12$$14, _13$$15, _14$$17, _15$$17, _16$$17, _17$$17;
	zval name, content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&skip);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 7, &name_param, &parameters_param, &defaultParams_param, &skip_param, &content_param, &close_param, &eol_param, &single_param);

	zephir_get_strval(&name, name_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&parameters, parameters_param);
	}
	if (!defaultParams_param) {
		ZEPHIR_INIT_VAR(&defaultParams);
		array_init(&defaultParams);
	} else {
		zephir_get_arrval(&defaultParams, defaultParams_param);
	}
	if (!skip_param) {
		ZEPHIR_INIT_VAR(&skip);
		array_init(&skip);
	} else {
		zephir_get_arrval(&skip, skip_param);
	}
	if (!content_param) {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_STRING(&content, "");
	} else {
		zephir_get_strval(&content, content_param);
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


	ZEPHIR_INIT_VAR(&attributes);
	array_init(&attributes);
	ZEPHIR_CPY_WRT(&params, &parameters);
	zephir_is_iterable(&defaultParams, 0, "ice/tag.zep", 703);
	if (Z_TYPE_P(&defaultParams) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&defaultParams), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&param);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&param, _3);
			} else {
				ZVAL_LONG(&param, _2);
			}
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _0);
			if (zephir_is_numeric(&key)) {
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_array_isset_fetch(&value, &params, &key, 0)) {
					zephir_array_update_zval(&attributes, &param, &value, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_array_update_zval(&attributes, &param, &key, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &defaultParams, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &defaultParams, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&param, &defaultParams, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&key, &defaultParams, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_is_numeric(&key)) {
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_array_isset_fetch(&value, &params, &key, 0)) {
						zephir_array_update_zval(&attributes, &param, &value, PH_COPY | PH_SEPARATE);
					}
				} else {
					zephir_array_update_zval(&attributes, &param, &key, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &defaultParams, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&param);
	zephir_is_iterable(&defaultParams, 0, "ice/tag.zep", 707);
	if (Z_TYPE_P(&defaultParams) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&defaultParams), _4)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _4);
			zephir_array_unset(&params, &key, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &defaultParams, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &defaultParams, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &defaultParams, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_unset(&params, &key, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &defaultParams, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_array_merge(&_6, &attributes, &params);
	ZEPHIR_CPY_WRT(&attributes, &_6);
	if (single) {
		ZVAL_BOOL(&_7, 1);
	} else {
		ZVAL_BOOL(&_7, 0);
	}
	ZEPHIR_CALL_METHOD(&code, this_ptr, "preparetag", NULL, 0, &name, &attributes, &skip, &_7);
	zephir_check_call_status();
	if (eol) {
		ZEPHIR_INIT_VAR(&_8$$13);
		ZEPHIR_GET_CONSTANT(&_8$$13, "PHP_EOL");
		zephir_concat_self(&code, &_8$$13);
	}
	if (!(Z_TYPE_P(&content) == IS_UNDEF) && Z_STRLEN_P(&content)) {
		_9$$14 = ZEPHIR_IS_STRING(&name, "textarea");
		if (_9$$14) {
			_9$$14 = zephir_array_isset_string(&attributes, SL("name"));
		}
		_10$$14 = _9$$14;
		if (_10$$14) {
			zephir_array_fetch_string(&_12$$14, &attributes, SL("name"), PH_NOISY | PH_READONLY, "ice/tag.zep", 716);
			ZEPHIR_CALL_METHOD(&_11$$14, this_ptr, "hasvalue", NULL, 0, &_12$$14);
			zephir_check_call_status();
			_10$$14 = zephir_is_true(&_11$$14);
		}
		if (_10$$14) {
			zephir_array_fetch_string(&_13$$15, &attributes, SL("name"), PH_NOISY | PH_READONLY, "ice/tag.zep", 717);
			ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0, &_13$$15);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_isset_fetch(&value, &attributes, &content, 0);
		}
		zephir_concat_self(&code, &value);
	}
	if (close) {
		ZEPHIR_INIT_VAR(&_14$$17);
		if (eol) {
			ZEPHIR_INIT_NVAR(&_14$$17);
			ZEPHIR_GET_CONSTANT(&_14$$17, "PHP_EOL");
		} else {
			ZEPHIR_INIT_NVAR(&_14$$17);
			ZVAL_STRING(&_14$$17, "");
		}
		if (eol) {
			ZVAL_BOOL(&_16$$17, 1);
		} else {
			ZVAL_BOOL(&_16$$17, 0);
		}
		ZEPHIR_CALL_METHOD(&_15$$17, this_ptr, "endtag", NULL, 0, &name, &_16$$17);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_17$$17);
		ZEPHIR_CONCAT_VV(&_17$$17, &_14$$17, &_15$$17);
		zephir_concat_self(&code, &_17$$17);
	}
	RETURN_CCTOR(&code);

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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool eol;
	zval *name_param = NULL, *eol_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &eol_param);

	zephir_get_strval(&name, name_param);
	if (!eol_param) {
		eol = 1;
	} else {
		eol = zephir_get_boolval(eol_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (eol) {
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	}
	ZEPHIR_CONCAT_SVSV(return_value, "</", &name, ">", &_0);
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

	zend_string *_13;
	zend_ulong _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool single, _4$$5, _14$$8, _15$$8, _16$$8, _23$$11, _24$$11, _25$$11;
	zval attributes, skip;
	zval *name_param = NULL, *attributes_param = NULL, *skip_param = NULL, *single_param = NULL, order, keys, attrs, code, type, tmp, value, key, _0, _1, *_10, _11, _3$$3, _5$$5, _6$$5, _8$$6, _9$$7, _17$$9, _22$$9, _18$$10, _19$$10, _20$$10, _21$$10, _26$$12, _31$$12, _27$$13, _28$$13, _29$$13, _30$$13, _32$$14, _33$$14;
	zval name, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_33$$14);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&skip);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &name_param, &attributes_param, &skip_param, &single_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	if (!skip_param) {
		ZEPHIR_INIT_VAR(&skip);
		array_init(&skip);
	} else {
		zephir_get_arrval(&skip, skip_param);
	}
	if (!single_param) {
		single = 0;
	} else {
		single = zephir_get_boolval(single_param);
	}


	ZEPHIR_INIT_VAR(&order);
	zephir_create_array(&order, 11, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "rel");
	zephir_array_fast_append(&order, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "type");
	zephir_array_fast_append(&order, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "for");
	zephir_array_fast_append(&order, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "src");
	zephir_array_fast_append(&order, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "href");
	zephir_array_fast_append(&order, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "action");
	zephir_array_fast_append(&order, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "id");
	zephir_array_fast_append(&order, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "name");
	zephir_array_fast_append(&order, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "value");
	zephir_array_fast_append(&order, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "class");
	zephir_array_fast_append(&order, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "style");
	zephir_array_fast_append(&order, &_0);
	ZEPHIR_CALL_FUNCTION(&_1, "array_flip", NULL, 8, &order);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&keys, "array_intersect_key", NULL, 9, &_1, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&attrs);
	zephir_fast_array_merge(&attrs, &keys, &attributes);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "<", &name);
	ZEPHIR_CPY_WRT(&code, &_2);
	ZEPHIR_OBS_VAR(&tmp);
	if (zephir_array_isset_string_fetch(&tmp, &attrs, SL("name"), 0)) {
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "hasvalue", NULL, 0, &tmp);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			ZEPHIR_OBS_VAR(&type);
			zephir_array_isset_string_fetch(&type, &attrs, SL("type"), 0);
			do {
				if (ZEPHIR_IS_STRING(&type, "radio") || ZEPHIR_IS_STRING(&type, "checkbox")) {
					_4$$5 = zephir_array_isset_string(&attrs, SL("value"));
					if (_4$$5) {
						zephir_array_fetch_string(&_5$$5, &attrs, SL("value"), PH_NOISY | PH_READONLY, "ice/tag.zep", 776);
						ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "getvalue", &_7, 0, &tmp);
						zephir_check_call_status();
						_4$$5 = ZEPHIR_IS_EQUAL(&_5$$5, &_6$$5);
					}
					if (_4$$5) {
						ZEPHIR_INIT_VAR(&_8$$6);
						ZVAL_STRING(&_8$$6, "checked");
						zephir_array_update_string(&attrs, SL("checked"), &_8$$6, PH_COPY | PH_SEPARATE);
					}
					break;
				}
				ZEPHIR_CALL_METHOD(&_9$$7, this_ptr, "getvalue", &_7, 0, &tmp);
				zephir_check_call_status();
				zephir_array_update_string(&attrs, SL("value"), &_9$$7, PH_COPY | PH_SEPARATE);
				break;
			} while(0);

		}
	}
	zephir_is_iterable(&attrs, 0, "ice/tag.zep", 796);
	if (Z_TYPE_P(&attrs) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attrs), _12, _13, _10)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_13 != NULL) { 
				ZVAL_STR_COPY(&key, _13);
			} else {
				ZVAL_LONG(&key, _12);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _10);
			_14$$8 = Z_TYPE_P(&key) == IS_STRING;
			if (_14$$8) {
				_14$$8 = Z_TYPE_P(&value) != IS_NULL;
			}
			_15$$8 = _14$$8;
			if (_15$$8) {
				_15$$8 = !ZEPHIR_IS_FALSE_IDENTICAL(&value);
			}
			_16$$8 = _15$$8;
			if (_16$$8) {
				_16$$8 = !(zephir_fast_in_array(&key, &skip));
			}
			if (_16$$8) {
				zephir_read_property(&_17$$9, this_ptr, SL("escape"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_17$$9)) {
					zephir_read_property(&_18$$10, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_20$$10);
					ZVAL_STRING(&_20$$10, "filter");
					ZEPHIR_CALL_METHOD(&_19$$10, &_18$$10, "get", NULL, 0, &_20$$10);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_20$$10);
					ZVAL_STRING(&_20$$10, "escape");
					ZEPHIR_CALL_METHOD(&_21$$10, &_19$$10, "sanitize", NULL, 0, &value, &_20$$10);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&value, &_21$$10);
				}
				ZEPHIR_INIT_NVAR(&_22$$9);
				ZEPHIR_CONCAT_SVSVS(&_22$$9, " ", &key, "=\"", &value, "\"");
				zephir_concat_self(&code, &_22$$9);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attrs, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_11, &attrs, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &attrs, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &attrs, "current", NULL, 0);
			zephir_check_call_status();
				_23$$11 = Z_TYPE_P(&key) == IS_STRING;
				if (_23$$11) {
					_23$$11 = Z_TYPE_P(&value) != IS_NULL;
				}
				_24$$11 = _23$$11;
				if (_24$$11) {
					_24$$11 = !ZEPHIR_IS_FALSE_IDENTICAL(&value);
				}
				_25$$11 = _24$$11;
				if (_25$$11) {
					_25$$11 = !(zephir_fast_in_array(&key, &skip));
				}
				if (_25$$11) {
					zephir_read_property(&_26$$12, this_ptr, SL("escape"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_26$$12)) {
						zephir_read_property(&_27$$13, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_29$$13);
						ZVAL_STRING(&_29$$13, "filter");
						ZEPHIR_CALL_METHOD(&_28$$13, &_27$$13, "get", NULL, 0, &_29$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_29$$13);
						ZVAL_STRING(&_29$$13, "escape");
						ZEPHIR_CALL_METHOD(&_30$$13, &_28$$13, "sanitize", NULL, 0, &value, &_29$$13);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&value, &_30$$13);
					}
					ZEPHIR_INIT_NVAR(&_31$$12);
					ZEPHIR_CONCAT_SVSVS(&_31$$12, " ", &key, "=\"", &value, "\"");
					zephir_concat_self(&code, &_31$$12);
				}
			ZEPHIR_CALL_METHOD(NULL, &attrs, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (single) {
		ZEPHIR_INIT_VAR(&_32$$14);
		zephir_read_property(&_33$$14, this_ptr, SL("docType"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT_LONG(&_33$$14, 5)) {
			ZEPHIR_INIT_NVAR(&_32$$14);
			ZVAL_STRING(&_32$$14, " />");
		} else {
			ZEPHIR_INIT_NVAR(&_32$$14);
			ZVAL_STRING(&_32$$14, ">");
		}
		zephir_concat_self(&code, &_32$$14);
	} else {
		zephir_concat_self_str(&code, SL(">"));
	}
	RETURN_CCTOR(&code);

}

/**
 * Check if a helper has a default value set using Ice\Tag::setValues or value from _POST.
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Ice_Tag, hasValue) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _POST, _0$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	if (zephir_array_isset(&_POST, &name)) {
		RETURN_MM_BOOL(1);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_0$$4, &name)) {
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *id_param = NULL, *value, value_sub;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &value);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(&id, id_param);
	} else {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_EMPTY_STRING(&id);
	}


	if (Z_TYPE_P(value) != IS_NULL) {
		_0$$3 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_0$$3)) {
			_0$$3 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Only scalar values can be assigned to UI components", "ice/tag.zep", 837);
			return;
		}
	}
	zephir_update_property_array(this_ptr, SL("values"), &id, value);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *values_param = NULL, *merge_param = NULL, current, _0$$5;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&_0$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values_param, &merge_param);

	zephir_get_arrval(&values, values_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "An array is required as default values", "ice/tag.zep", 857);
		return;
	}
	if (merge) {
		ZEPHIR_OBS_VAR(&current);
		zephir_read_property(&current, this_ptr, SL("values"), PH_NOISY_CC);
		if (Z_TYPE_P(&current) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$5);
			zephir_fast_array_merge(&_0$$5, &current, &values);
			zephir_update_property_zval(this_ptr, ZEND_STRL("values"), &_0$$5);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("values"), &values);
		}
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("values"), &values);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _POST, value, _0$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_fetch(&value, &_POST, &name, 0))) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_read_property(&_0$$3, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_fetch(&value, &_0$$3, &name, 0))) {
			RETURN_MM_NULL();
		}
	}
	RETURN_CCTOR(&value);

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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_18 = NULL;
	zend_bool lowercase, _8$$4;
	zval *text_param = NULL, *separator_param = NULL, *lowercase_param = NULL, *replace = NULL, replace_sub, __$null, friendly, locale, search, _0, _1, _17, _20, _3$$3, _4$$3, _6$$3, _7$$3, *_9$$6, _10$$6, _11$$7, _12$$7, _13$$8, _14$$8, _15$$9, _16$$9, _19$$10, _21$$11;
	zval text, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&replace_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&friendly);
	ZVAL_UNDEF(&locale);
	ZVAL_UNDEF(&search);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_21$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &text_param, &separator_param, &lowercase_param, &replace);

	zephir_get_strval(&text, text_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "-");
	} else {
		zephir_get_strval(&separator, separator_param);
	}
	if (!lowercase_param) {
		lowercase = 1;
	} else {
		lowercase = zephir_get_boolval(lowercase_param);
	}
	if (!replace) {
		replace = &replace_sub;
		replace = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "iconv");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, 210, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZVAL_LONG(&_3$$3, 6);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "en_US.UTF-8");
		ZEPHIR_CALL_FUNCTION(&locale, "setlocale", &_5, 211, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "UTF-8");
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "ASCII//TRANSLIT");
		ZEPHIR_CALL_FUNCTION(&_7$$3, "iconv", NULL, 212, &_4$$3, &_6$$3, &text);
		zephir_check_call_status();
		zephir_get_strval(&text, &_7$$3);
	}
	if (zephir_is_true(replace)) {
		_8$$4 = Z_TYPE_P(replace) != IS_ARRAY;
		if (_8$$4) {
			_8$$4 = Z_TYPE_P(replace) != IS_STRING;
		}
		if (_8$$4) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Parameter replace must be an array or a string", "ice/tag.zep", 924);
			return;
		}
		if (Z_TYPE_P(replace) == IS_ARRAY) {
			zephir_is_iterable(replace, 0, "ice/tag.zep", 931);
			if (Z_TYPE_P(replace) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(replace), _9$$6)
				{
					ZEPHIR_INIT_NVAR(&search);
					ZVAL_COPY(&search, _9$$6);
					ZEPHIR_INIT_NVAR(&_11$$7);
					ZEPHIR_INIT_NVAR(&_12$$7);
					ZVAL_STRING(&_12$$7, " ");
					zephir_fast_str_replace(&_11$$7, &search, &_12$$7, &text);
					zephir_get_strval(&text, &_11$$7);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, replace, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_10$$6, replace, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_10$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&search, replace, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_13$$8);
						ZEPHIR_INIT_NVAR(&_14$$8);
						ZVAL_STRING(&_14$$8, " ");
						zephir_fast_str_replace(&_13$$8, &search, &_14$$8, &text);
						zephir_get_strval(&text, &_13$$8);
					ZEPHIR_CALL_METHOD(NULL, replace, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&search);
		} else {
			ZEPHIR_INIT_VAR(&_15$$9);
			ZEPHIR_INIT_VAR(&_16$$9);
			ZVAL_STRING(&_16$$9, " ");
			zephir_fast_str_replace(&_15$$9, replace, &_16$$9, &text);
			zephir_get_strval(&text, &_15$$9);
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/[^a-zA-Z0-9\\/_|+ -]/");
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, "");
	ZEPHIR_CALL_FUNCTION(&friendly, "preg_replace", &_18, 51, &_0, &_17, &text);
	zephir_check_call_status();
	if (lowercase) {
		ZEPHIR_INIT_VAR(&_19$$10);
		zephir_fast_strtolower(&_19$$10, &friendly);
		ZEPHIR_CPY_WRT(&friendly, &_19$$10);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/[\\/_|+ -]+/");
	ZEPHIR_CALL_FUNCTION(&_20, "preg_replace", &_18, 51, &_0, &separator, &friendly);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&friendly, &_20);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_trim(&_0, &friendly, &separator, ZEPHIR_TRIM_BOTH);
	ZEPHIR_CPY_WRT(&friendly, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "iconv");
	ZEPHIR_CALL_FUNCTION(&_20, "extension_loaded", &_2, 210, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_20)) {
		ZVAL_LONG(&_21$$11, 6);
		ZEPHIR_CALL_FUNCTION(NULL, "setlocale", &_5, 211, &_21$$11, &locale);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&friendly);

}

/**
 * Get the document type declaration of content.
 *
 * @return string
 */
PHP_METHOD(Ice_Tag, getDocType) {

	zval _0, _1$$3, _2$$4, _3$$4, _4$$5, _5$$5, _6$$6, _7$$6, _8$$7, _9$$8, _10$$8, _11$$9, _12$$9, _13$$10, _14$$10, _15$$11, _16$$11, _17$$12, _18$$12, _19$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$13);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("docType"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_LONG(&_0, 1)) {
			ZEPHIR_INIT_VAR(&_1$$3);
			ZEPHIR_GET_CONSTANT(&_1$$3, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">", &_1$$3);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 2)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_GET_CONSTANT(&_2$$4, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_GET_CONSTANT(&_3$$4, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"", &_2$$4, "\t\"http://www.w3.org/TR/html4/strict.dtd\">", &_3$$4);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 3)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZEPHIR_GET_CONSTANT(&_4$$5, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_5$$5);
			ZEPHIR_GET_CONSTANT(&_5$$5, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"", &_4$$5, "\t\"http://www.w3.org/TR/html4/loose.dtd\">", &_5$$5);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 4)) {
			ZEPHIR_INIT_VAR(&_6$$6);
			ZEPHIR_GET_CONSTANT(&_6$$6, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_7$$6);
			ZEPHIR_GET_CONSTANT(&_7$$6, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"", &_6$$6, "\t\"http://www.w3.org/TR/html4/frameset.dtd\">", &_7$$6);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 5)) {
			ZEPHIR_INIT_VAR(&_8$$7);
			ZEPHIR_GET_CONSTANT(&_8$$7, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", &_8$$7);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 6)) {
			ZEPHIR_INIT_VAR(&_9$$8);
			ZEPHIR_GET_CONSTANT(&_9$$8, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_10$$8);
			ZEPHIR_GET_CONSTANT(&_10$$8, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"", &_9$$8, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">", &_10$$8);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 7)) {
			ZEPHIR_INIT_VAR(&_11$$9);
			ZEPHIR_GET_CONSTANT(&_11$$9, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_12$$9);
			ZEPHIR_GET_CONSTANT(&_12$$9, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"", &_11$$9, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">", &_12$$9);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 8)) {
			ZEPHIR_INIT_VAR(&_13$$10);
			ZEPHIR_GET_CONSTANT(&_13$$10, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_14$$10);
			ZEPHIR_GET_CONSTANT(&_14$$10, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"", &_13$$10, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">", &_14$$10);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 9)) {
			ZEPHIR_INIT_VAR(&_15$$11);
			ZEPHIR_GET_CONSTANT(&_15$$11, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_16$$11);
			ZEPHIR_GET_CONSTANT(&_16$$11, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"", &_15$$11, "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">", &_16$$11);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 10)) {
			ZEPHIR_INIT_VAR(&_17$$12);
			ZEPHIR_GET_CONSTANT(&_17$$12, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_18$$12);
			ZEPHIR_GET_CONSTANT(&_18$$12, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"", &_17$$12, "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">", &_18$$12);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 11)) {
			ZEPHIR_INIT_VAR(&_19$$13);
			ZEPHIR_GET_CONSTANT(&_19$$13, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", &_19$$13);
			RETURN_MM();
		}
	} while(0);

	RETURN_MM_STRING("");

}

zend_object *zephir_init_properties_Ice_Tag(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("meta"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zend_update_property(Z_OBJCE_P(this_ptr), this_ptr, ZEND_STRL("meta"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

