
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
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 * @uses        Ice\Mvc\Url
 */
ZEPHIR_INIT_CLASS(Ice_Tag)
{
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

PHP_METHOD(Ice_Tag, getDi)
{

	RETURN_MEMBER(getThis(), "di");
}

PHP_METHOD(Ice_Tag, getValues)
{

	RETURN_MEMBER(getThis(), "values");
}

PHP_METHOD(Ice_Tag, setDocType)
{
	zval *docType, docType_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&docType_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("docType", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(docType)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &docType);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 263, docType);
	RETURN_THISW();
}

PHP_METHOD(Ice_Tag, setTitle)
{
	zval *title, title_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("title", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(title)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &title);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 264, title);
	RETURN_THISW();
}

PHP_METHOD(Ice_Tag, getTitle)
{

	RETURN_MEMBER(getThis(), "title");
}

PHP_METHOD(Ice_Tag, setTitleSeparator)
{
	zval *titleSeparator, titleSeparator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&titleSeparator_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("titleSeparator", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(titleSeparator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &titleSeparator);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 265, titleSeparator);
	RETURN_THISW();
}

PHP_METHOD(Ice_Tag, getTitleSeparator)
{

	RETURN_MEMBER(getThis(), "titleSeparator");
}

PHP_METHOD(Ice_Tag, setMeta)
{
	zval *meta, meta_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&meta_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("meta", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(meta)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &meta);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 266, meta);
	RETURN_THISW();
}

PHP_METHOD(Ice_Tag, getMeta)
{

	RETURN_MEMBER(getThis(), "meta");
}

PHP_METHOD(Ice_Tag, setEscape)
{
	zval *escape, escape_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escape_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("escape", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(escape)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &escape);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 267, escape);
	RETURN_THISW();
}

/**
 * Tag constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Tag, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("di", 2, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 268, &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Appends a text to current document title.
 *
 * @param string title
 * @param string separator
 * @return object Tag
 */
PHP_METHOD(Ice_Tag, appendTitle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval title_zv, separator_zv, _0, _1, _2;
	zend_string *title = NULL, *separator = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title_zv);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("title", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("titleSeparator", 14, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(title)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(separator)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&title_zv);
	ZVAL_STR_COPY(&title_zv, title);
	if (!separator) {
		ZEPHIR_INIT_VAR(&separator_zv);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 264, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (!(ZEPHIR_IS_EMPTY(&separator_zv))) {
		ZEPHIR_CPY_WRT(&_1, &separator_zv);
	} else {
		ZEPHIR_OBS_NVAR(&_1);
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 265, PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VVV(&_2, &_0, &_1, &title_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 264, &_2);
	RETURN_THIS();
}

/**
 * Prepends a text to current document title.
 *
 * @param string title
 * @param string separator
 * @return object Tag
 */
PHP_METHOD(Ice_Tag, prependTitle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval title_zv, separator_zv, _0, _1, _2;
	zend_string *title = NULL, *separator = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title_zv);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("titleSeparator", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("title", 5, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(title)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(separator)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&title_zv);
	ZVAL_STR_COPY(&title_zv, title);
	if (!separator) {
		ZEPHIR_INIT_VAR(&separator_zv);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	ZEPHIR_INIT_VAR(&_0);
	if (!(ZEPHIR_IS_EMPTY(&separator_zv))) {
		ZEPHIR_CPY_WRT(&_0, &separator_zv);
	} else {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 265, PH_NOISY_CC);
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 264, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VVV(&_2, &title_zv, &_0, &_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 264, &_2);
	RETURN_THIS();
}

/**
 * Add meta tag to the container.
 *
 * @param array parameters
 * @return object this
 */
PHP_METHOD(Ice_Tag, addMeta)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, textField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, passwordField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, hiddenField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, fileField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, submitButton)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, button)
{
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, checkField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, radioField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, input)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval type_zv, *parameters_param = NULL, defaultParams, _0, _1, _2, _3, _4, _5;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&parameters);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	parameters_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_get_arrval(&parameters, parameters_param);
	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 4, 0);
	add_assoc_long_ex(&defaultParams, SL("id"), 0);
	add_assoc_long_ex(&defaultParams, SL("name"), 0);
	add_assoc_long_ex(&defaultParams, SL("value"), 1);
	zephir_array_update_string(&defaultParams, SL("type"), &type_zv, PH_COPY | PH_SEPARATE);
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
PHP_METHOD(Ice_Tag, form)
{
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("di", 2, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters_param);
	zephir_get_arrval(&parameters, parameters_param);
	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 2, 0);
	add_assoc_long_ex(&defaultParams, SL("action"), 0);
	add_assoc_stringl_ex(&defaultParams, SL("method"), SL("post"));
	zephir_memory_observe(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	if (zephir_is_true(&local)) {
		zephir_memory_observe(&action);
		if (!(zephir_array_isset_string_fetch(&action, &parameters, SL("action"), 0))) {
			ZEPHIR_OBS_NVAR(&action);
			zephir_memory_observe(&_0$$5);
			zephir_array_fetch_string(&_0$$5, &defaultParams, SL("action"), 0, "ice/tag.zep", 299);
			zephir_array_isset_fetch(&action, &parameters, &_0$$5, 0);
		}
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&action)) {
			zephir_read_property_cached(&_1$$6, this_ptr, _zephir_prop_0, 268, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_3$$6);
			ZVAL_STRING(&_3$$6, "url");
			ZEPHIR_CALL_METHOD(&_2$$6, &_1$$6, "get", NULL, 0, &_3$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$6, &_2$$6, "rel", NULL, 0, &action);
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
PHP_METHOD(Ice_Tag, endForm)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
PHP_METHOD(Ice_Tag, textArea)
{
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, image)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, img)
{
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("di", 2, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters_param);
	zephir_get_arrval(&parameters, parameters_param);
	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 2, 0);
	add_assoc_long_ex(&defaultParams, SL("src"), 0);
	add_assoc_long_ex(&defaultParams, SL("alt"), 1);
	zephir_memory_observe(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	if (zephir_is_true(&local)) {
		zephir_memory_observe(&src);
		if (!(zephir_array_isset_string_fetch(&src, &parameters, SL("src"), 0))) {
			ZEPHIR_OBS_NVAR(&src);
			zephir_memory_observe(&_0$$5);
			zephir_array_fetch_string(&_0$$5, &defaultParams, SL("src"), 0, "ice/tag.zep", 385);
			zephir_array_isset_fetch(&src, &parameters, &_0$$5, 0);
		}
		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_0, 268, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "url");
		ZEPHIR_CALL_METHOD(&_2$$4, &_1$$4, "get", NULL, 0, &_3$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, &_2$$4, "href", NULL, 0, &src);
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
PHP_METHOD(Ice_Tag, linkTo)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, a)
{
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("di", 2, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters_param);
	zephir_get_arrval(&parameters, parameters_param);
	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 3, 0);
	add_assoc_long_ex(&defaultParams, SL("href"), 0);
	add_assoc_long_ex(&defaultParams, SL("text"), 1);
	add_assoc_long_ex(&defaultParams, SL("title"), 2);
	zephir_memory_observe(&href);
	if (!(zephir_array_isset_string_fetch(&href, &parameters, SL("href"), 0))) {
		ZEPHIR_OBS_NVAR(&href);
		zephir_memory_observe(&_0$$3);
		zephir_array_fetch_string(&_0$$3, &defaultParams, SL("href"), 0, "ice/tag.zep", 427);
		zephir_array_isset_fetch(&href, &parameters, &_0$$3, 0);
	}
	zephir_memory_observe(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	zephir_memory_observe(&query);
	zephir_array_isset_string_fetch(&query, &parameters, SL("query"), 0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 268, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "url");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_2, "rel", NULL, 0, &href, &query, &local);
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
PHP_METHOD(Ice_Tag, link)
{
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("di", 2, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters_param);
	zephir_get_arrval(&parameters, parameters_param);
	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 3, 0);
	add_assoc_long_ex(&defaultParams, SL("href"), 0);
	add_assoc_stringl_ex(&defaultParams, SL("type"), SL("text/css"));
	add_assoc_stringl_ex(&defaultParams, SL("rel"), SL("stylesheet"));
	zephir_memory_observe(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	if (zephir_is_true(&local)) {
		zephir_memory_observe(&href);
		if (!(zephir_array_isset_string_fetch(&href, &parameters, SL("href"), 0))) {
			ZEPHIR_OBS_NVAR(&href);
			zephir_memory_observe(&_0$$5);
			zephir_array_fetch_string(&_0$$5, &defaultParams, SL("href"), 0, "ice/tag.zep", 471);
			zephir_array_isset_fetch(&href, &parameters, &_0$$5, 0);
		}
		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_0, 268, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "url");
		ZEPHIR_CALL_METHOD(&_2$$4, &_1$$4, "get", NULL, 0, &_3$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, &_2$$4, "href", NULL, 0, &href);
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
PHP_METHOD(Ice_Tag, script)
{
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("di", 2, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters_param);
	zephir_get_arrval(&parameters, parameters_param);
	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 2, 0);
	add_assoc_long_ex(&defaultParams, SL("src"), 0);
	add_assoc_stringl_ex(&defaultParams, SL("type"), SL("text/javascript"));
	zephir_memory_observe(&local);
	if (!(zephir_array_isset_string_fetch(&local, &parameters, SL("local"), 0))) {
		ZEPHIR_INIT_NVAR(&local);
		ZVAL_BOOL(&local, 1);
	}
	if (zephir_is_true(&local)) {
		zephir_memory_observe(&src);
		if (!(zephir_array_isset_string_fetch(&src, &parameters, SL("src"), 0))) {
			ZEPHIR_OBS_NVAR(&src);
			zephir_memory_observe(&_0$$5);
			zephir_array_fetch_string(&_0$$5, &defaultParams, SL("src"), 0, "ice/tag.zep", 509);
			zephir_array_isset_fetch(&src, &parameters, &_0$$5, 0);
		}
		if (zephir_is_true(&src)) {
			zephir_read_property_cached(&_1$$6, this_ptr, _zephir_prop_0, 268, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_3$$6);
			ZVAL_STRING(&_3$$6, "url");
			ZEPHIR_CALL_METHOD(&_2$$6, &_1$$6, "get", NULL, 0, &_3$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$6, &_2$$6, "href", NULL, 0, &src);
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
PHP_METHOD(Ice_Tag, style)
{
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, meta)
{
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Tag, select)
{
	zend_bool _56$$10, _25$$12, _73$$20;
	zend_string *_9$$10, *_14$$12, *_62$$20;
	zend_ulong _8$$10, _13$$12, _61$$20;
	zval _4$$8, _15$$13, _26$$15, _46$$17, _63$$21, _74$$23, _94$$25;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, defaultParams, name, options, option, selected, tmp, value, text, group, subvalue, subtext, suboptions, _2, _106, _107, _108, _109, _0$$3, _1$$4, _3$$5, *_5$$10, _6$$10, *_7$$10, _55$$10, _103$$10, _104$$10, *_10$$12, _11$$12, *_12$$12, _24$$12, _35$$12, _36$$12, _37$$12, _38$$12, _39$$12, _40$$12, _41$$12, _43$$12, _44$$12, _45$$12, _17$$13, _18$$13, _20$$13, _21$$13, _22$$13, _16$$14, _27$$15, _29$$15, _30$$15, _32$$15, _33$$15, _34$$15, _28$$16, _47$$17, _49$$17, _50$$17, _52$$17, _53$$17, _54$$17, _48$$18, _57$$20, *_58$$20, _59$$20, *_60$$20, _72$$20, _83$$20, _84$$20, _85$$20, _86$$20, _87$$20, _88$$20, _89$$20, _91$$20, _92$$20, _93$$20, _64$$21, _66$$21, _67$$21, _69$$21, _70$$21, _71$$21, _65$$22, _75$$23, _77$$23, _78$$23, _80$$23, _81$$23, _82$$23, _76$$24, _95$$25, _97$$25, _98$$25, _100$$25, _101$$25, _102$$25, _96$$26;
	zval parameters, _105, _42$$12, _19$$13, _31$$15, _51$$17, _90$$20, _68$$21, _79$$23, _99$$25;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_105);
	ZVAL_UNDEF(&_42$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_51$$17);
	ZVAL_UNDEF(&_90$$20);
	ZVAL_UNDEF(&_68$$21);
	ZVAL_UNDEF(&_79$$23);
	ZVAL_UNDEF(&_99$$25);
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
	ZVAL_UNDEF(&_106);
	ZVAL_UNDEF(&_107);
	ZVAL_UNDEF(&_108);
	ZVAL_UNDEF(&_109);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_55$$10);
	ZVAL_UNDEF(&_103$$10);
	ZVAL_UNDEF(&_104$$10);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_35$$12);
	ZVAL_UNDEF(&_36$$12);
	ZVAL_UNDEF(&_37$$12);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&_39$$12);
	ZVAL_UNDEF(&_40$$12);
	ZVAL_UNDEF(&_41$$12);
	ZVAL_UNDEF(&_43$$12);
	ZVAL_UNDEF(&_44$$12);
	ZVAL_UNDEF(&_45$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_34$$15);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_49$$17);
	ZVAL_UNDEF(&_50$$17);
	ZVAL_UNDEF(&_52$$17);
	ZVAL_UNDEF(&_53$$17);
	ZVAL_UNDEF(&_54$$17);
	ZVAL_UNDEF(&_48$$18);
	ZVAL_UNDEF(&_57$$20);
	ZVAL_UNDEF(&_59$$20);
	ZVAL_UNDEF(&_72$$20);
	ZVAL_UNDEF(&_83$$20);
	ZVAL_UNDEF(&_84$$20);
	ZVAL_UNDEF(&_85$$20);
	ZVAL_UNDEF(&_86$$20);
	ZVAL_UNDEF(&_87$$20);
	ZVAL_UNDEF(&_88$$20);
	ZVAL_UNDEF(&_89$$20);
	ZVAL_UNDEF(&_91$$20);
	ZVAL_UNDEF(&_92$$20);
	ZVAL_UNDEF(&_93$$20);
	ZVAL_UNDEF(&_64$$21);
	ZVAL_UNDEF(&_66$$21);
	ZVAL_UNDEF(&_67$$21);
	ZVAL_UNDEF(&_69$$21);
	ZVAL_UNDEF(&_70$$21);
	ZVAL_UNDEF(&_71$$21);
	ZVAL_UNDEF(&_65$$22);
	ZVAL_UNDEF(&_75$$23);
	ZVAL_UNDEF(&_77$$23);
	ZVAL_UNDEF(&_78$$23);
	ZVAL_UNDEF(&_80$$23);
	ZVAL_UNDEF(&_81$$23);
	ZVAL_UNDEF(&_82$$23);
	ZVAL_UNDEF(&_76$$24);
	ZVAL_UNDEF(&_95$$25);
	ZVAL_UNDEF(&_97$$25);
	ZVAL_UNDEF(&_98$$25);
	ZVAL_UNDEF(&_100$$25);
	ZVAL_UNDEF(&_101$$25);
	ZVAL_UNDEF(&_102$$25);
	ZVAL_UNDEF(&_96$$26);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_63$$21);
	ZVAL_UNDEF(&_74$$23);
	ZVAL_UNDEF(&_94$$25);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters_param);
	zephir_get_arrval(&parameters, parameters_param);
	ZEPHIR_INIT_VAR(&defaultParams);
	zephir_create_array(&defaultParams, 3, 0);
	add_assoc_long_ex(&defaultParams, SL("id"), 0);
	add_assoc_long_ex(&defaultParams, SL("name"), 0);
	add_assoc_long_ex(&defaultParams, SL("options"), 1);
	zephir_memory_observe(&name);
	if (!(zephir_array_isset_string_fetch(&name, &parameters, SL("name"), 0))) {
		ZEPHIR_OBS_NVAR(&name);
		zephir_memory_observe(&_0$$3);
		zephir_array_fetch_string(&_0$$3, &defaultParams, SL("name"), 0, "ice/tag.zep", 591);
		zephir_array_isset_fetch(&name, &parameters, &_0$$3, 0);
	}
	zephir_memory_observe(&options);
	if (!(zephir_array_isset_string_fetch(&options, &parameters, SL("options"), 0))) {
		ZEPHIR_OBS_NVAR(&options);
		zephir_memory_observe(&_1$$4);
		zephir_array_fetch_string(&_1$$4, &defaultParams, SL("options"), 0, "ice/tag.zep", 595);
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
			zephir_cast_to_string(&_4$$8, &selected);
			zephir_array_fast_append(&tmp, &_4$$8);
			ZEPHIR_CPY_WRT(&selected, &tmp);
		}
	}
	if (ZEPHIR_IS_EMPTY(&options)) {
		ZEPHIR_INIT_NVAR(&options);
		ZVAL_STRING(&options, "");
	} else {
		if (Z_TYPE_P(&options) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_6$$10);
			zephir_string_to_char_array(&_6$$10, &options);
			_5$$10 = &_6$$10;
		} else {
			_5$$10 = &options;
		}
		zephir_is_iterable(_5$$10, 0, "ice/tag.zep", 667);
		if (Z_TYPE_P(_5$$10) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_5$$10), _8$$10, _9$$10, _7$$10)
			{
				ZEPHIR_INIT_NVAR(&value);
				if (_9$$10 != NULL) { 
					ZVAL_STR_COPY(&value, _9$$10);
				} else {
					ZVAL_LONG(&value, _8$$10);
				}
				ZEPHIR_INIT_NVAR(&text);
				ZVAL_COPY(&text, _7$$10);
				if (Z_TYPE_P(&text) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&group);
					zephir_create_array(&group, 1, 0);
					zephir_array_update_string(&group, SL("label"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&suboptions);
					array_init(&suboptions);
					if (Z_TYPE_P(&text) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_11$$12);
						zephir_string_to_char_array(&_11$$12, &text);
						_10$$12 = &_11$$12;
					} else {
						_10$$12 = &text;
					}
					zephir_is_iterable(_10$$12, 0, "ice/tag.zep", 646);
					if (Z_TYPE_P(_10$$12) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_10$$12), _13$$12, _14$$12, _12$$12)
						{
							ZEPHIR_INIT_NVAR(&subvalue);
							if (_14$$12 != NULL) { 
								ZVAL_STR_COPY(&subvalue, _14$$12);
							} else {
								ZVAL_LONG(&subvalue, _13$$12);
							}
							ZEPHIR_INIT_NVAR(&subtext);
							ZVAL_COPY(&subtext, _12$$12);
							zephir_cast_to_string(&_15$$13, &subvalue);
							ZEPHIR_CPY_WRT(&subvalue, &_15$$13);
							ZEPHIR_INIT_NVAR(&option);
							zephir_create_array(&option, 1, 0);
							zephir_array_update_string(&option, SL("value"), &subvalue, PH_COPY | PH_SEPARATE);
							if (zephir_fast_in_array(&subvalue, &selected)) {
								ZEPHIR_INIT_NVAR(&_16$$14);
								ZVAL_STRING(&_16$$14, "selected");
								zephir_array_update_string(&option, SL("selected"), &_16$$14, PH_COPY | PH_SEPARATE);
							}
							zephir_array_update_string(&option, SL("content"), &subtext, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_18$$13);
							array_init(&_18$$13);
							ZEPHIR_INIT_NVAR(&_19$$13);
							zephir_create_array(&_19$$13, 1, 0);
							ZEPHIR_INIT_NVAR(&_20$$13);
							ZVAL_STRING(&_20$$13, "content");
							zephir_array_fast_append(&_19$$13, &_20$$13);
							ZEPHIR_INIT_NVAR(&_20$$13);
							ZVAL_STRING(&_20$$13, "option");
							ZEPHIR_INIT_NVAR(&_21$$13);
							ZVAL_STRING(&_21$$13, "content");
							ZVAL_BOOL(&_22$$13, 1);
							ZEPHIR_CALL_METHOD(&_17$$13, this_ptr, "taghtml", &_23, 0, &_20$$13, &option, &_18$$13, &_19$$13, &_21$$13, &_22$$13);
							zephir_check_call_status();
							zephir_array_append(&suboptions, &_17$$13, PH_SEPARATE, "ice/tag.zep", 642);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _10$$12, "rewind", NULL, 0);
						zephir_check_call_status();
						_25$$12 = 1;
						while (1) {
							if (_25$$12) {
								_25$$12 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _10$$12, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_24$$12, _10$$12, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_24$$12)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&subvalue, _10$$12, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&subtext, _10$$12, "current", NULL, 0);
							zephir_check_call_status();
								zephir_cast_to_string(&_26$$15, &subvalue);
								ZEPHIR_CPY_WRT(&subvalue, &_26$$15);
								ZEPHIR_INIT_NVAR(&_27$$15);
								zephir_create_array(&_27$$15, 1, 0);
								zephir_array_update_string(&_27$$15, SL("value"), &subvalue, PH_COPY | PH_SEPARATE);
								ZEPHIR_CPY_WRT(&option, &_27$$15);
								if (zephir_fast_in_array(&subvalue, &selected)) {
									ZEPHIR_INIT_NVAR(&_28$$16);
									ZVAL_STRING(&_28$$16, "selected");
									zephir_array_update_string(&option, SL("selected"), &_28$$16, PH_COPY | PH_SEPARATE);
								}
								zephir_array_update_string(&option, SL("content"), &subtext, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_30$$15);
								array_init(&_30$$15);
								ZEPHIR_INIT_NVAR(&_31$$15);
								zephir_create_array(&_31$$15, 1, 0);
								ZEPHIR_INIT_NVAR(&_32$$15);
								ZVAL_STRING(&_32$$15, "content");
								zephir_array_fast_append(&_31$$15, &_32$$15);
								ZEPHIR_INIT_NVAR(&_32$$15);
								ZVAL_STRING(&_32$$15, "option");
								ZEPHIR_INIT_NVAR(&_33$$15);
								ZVAL_STRING(&_33$$15, "content");
								ZVAL_BOOL(&_34$$15, 1);
								ZEPHIR_CALL_METHOD(&_29$$15, this_ptr, "taghtml", &_23, 0, &_32$$15, &option, &_30$$15, &_31$$15, &_33$$15, &_34$$15);
								zephir_check_call_status();
								zephir_array_append(&suboptions, &_29$$15, PH_SEPARATE, "ice/tag.zep", 642);
						}
					}
					ZEPHIR_INIT_NVAR(&subtext);
					ZEPHIR_INIT_NVAR(&subvalue);
					ZEPHIR_INIT_NVAR(&_35$$12);
					ZEPHIR_GET_CONSTANT(&_35$$12, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_36$$12);
					ZEPHIR_INIT_NVAR(&_37$$12);
					ZEPHIR_GET_CONSTANT(&_37$$12, "PHP_EOL");
					zephir_fast_join(&_36$$12, &_37$$12, &suboptions);
					ZEPHIR_INIT_NVAR(&_38$$12);
					ZEPHIR_GET_CONSTANT(&_38$$12, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_39$$12);
					ZEPHIR_CONCAT_VVV(&_39$$12, &_35$$12, &_36$$12, &_38$$12);
					zephir_array_update_string(&group, SL("content"), &_39$$12, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_41$$12);
					array_init(&_41$$12);
					ZEPHIR_INIT_NVAR(&_42$$12);
					zephir_create_array(&_42$$12, 1, 0);
					ZEPHIR_INIT_NVAR(&_43$$12);
					ZVAL_STRING(&_43$$12, "content");
					zephir_array_fast_append(&_42$$12, &_43$$12);
					ZEPHIR_INIT_NVAR(&_43$$12);
					ZVAL_STRING(&_43$$12, "optgroup");
					ZEPHIR_INIT_NVAR(&_44$$12);
					ZVAL_STRING(&_44$$12, "content");
					ZVAL_BOOL(&_45$$12, 1);
					ZEPHIR_CALL_METHOD(&_40$$12, this_ptr, "taghtml", &_23, 0, &_43$$12, &group, &_41$$12, &_42$$12, &_44$$12, &_45$$12);
					zephir_check_call_status();
					zephir_array_update_zval(&options, &value, &_40$$12, PH_COPY | PH_SEPARATE);
				} else {
					zephir_cast_to_string(&_46$$17, &value);
					ZEPHIR_CPY_WRT(&value, &_46$$17);
					ZEPHIR_INIT_NVAR(&_47$$17);
					zephir_create_array(&_47$$17, 1, 0);
					zephir_array_update_string(&_47$$17, SL("value"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&option, &_47$$17);
					if (zephir_fast_in_array(&value, &selected)) {
						ZEPHIR_INIT_NVAR(&_48$$18);
						ZVAL_STRING(&_48$$18, "selected");
						zephir_array_update_string(&option, SL("selected"), &_48$$18, PH_COPY | PH_SEPARATE);
					}
					zephir_array_update_string(&option, SL("content"), &text, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_50$$17);
					array_init(&_50$$17);
					ZEPHIR_INIT_NVAR(&_51$$17);
					zephir_create_array(&_51$$17, 1, 0);
					ZEPHIR_INIT_NVAR(&_52$$17);
					ZVAL_STRING(&_52$$17, "content");
					zephir_array_fast_append(&_51$$17, &_52$$17);
					ZEPHIR_INIT_NVAR(&_52$$17);
					ZVAL_STRING(&_52$$17, "option");
					ZEPHIR_INIT_NVAR(&_53$$17);
					ZVAL_STRING(&_53$$17, "content");
					ZVAL_BOOL(&_54$$17, 1);
					ZEPHIR_CALL_METHOD(&_49$$17, this_ptr, "taghtml", &_23, 0, &_52$$17, &option, &_50$$17, &_51$$17, &_53$$17, &_54$$17);
					zephir_check_call_status();
					zephir_array_update_zval(&options, &value, &_49$$17, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _5$$10, "rewind", NULL, 0);
			zephir_check_call_status();
			_56$$10 = 1;
			while (1) {
				if (_56$$10) {
					_56$$10 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _5$$10, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_55$$10, _5$$10, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_55$$10)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&value, _5$$10, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&text, _5$$10, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&text) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_57$$20);
						zephir_create_array(&_57$$20, 1, 0);
						zephir_array_update_string(&_57$$20, SL("label"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&group, &_57$$20);
						ZEPHIR_INIT_NVAR(&suboptions);
						array_init(&suboptions);
						if (Z_TYPE_P(&text) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_59$$20);
							zephir_string_to_char_array(&_59$$20, &text);
							_58$$20 = &_59$$20;
						} else {
							_58$$20 = &text;
						}
						zephir_is_iterable(_58$$20, 0, "ice/tag.zep", 646);
						if (Z_TYPE_P(_58$$20) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_58$$20), _61$$20, _62$$20, _60$$20)
							{
								ZEPHIR_INIT_NVAR(&subvalue);
								if (_62$$20 != NULL) { 
									ZVAL_STR_COPY(&subvalue, _62$$20);
								} else {
									ZVAL_LONG(&subvalue, _61$$20);
								}
								ZEPHIR_INIT_NVAR(&subtext);
								ZVAL_COPY(&subtext, _60$$20);
								zephir_cast_to_string(&_63$$21, &subvalue);
								ZEPHIR_CPY_WRT(&subvalue, &_63$$21);
								ZEPHIR_INIT_NVAR(&_64$$21);
								zephir_create_array(&_64$$21, 1, 0);
								zephir_array_update_string(&_64$$21, SL("value"), &subvalue, PH_COPY | PH_SEPARATE);
								ZEPHIR_CPY_WRT(&option, &_64$$21);
								if (zephir_fast_in_array(&subvalue, &selected)) {
									ZEPHIR_INIT_NVAR(&_65$$22);
									ZVAL_STRING(&_65$$22, "selected");
									zephir_array_update_string(&option, SL("selected"), &_65$$22, PH_COPY | PH_SEPARATE);
								}
								zephir_array_update_string(&option, SL("content"), &subtext, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_67$$21);
								array_init(&_67$$21);
								ZEPHIR_INIT_NVAR(&_68$$21);
								zephir_create_array(&_68$$21, 1, 0);
								ZEPHIR_INIT_NVAR(&_69$$21);
								ZVAL_STRING(&_69$$21, "content");
								zephir_array_fast_append(&_68$$21, &_69$$21);
								ZEPHIR_INIT_NVAR(&_69$$21);
								ZVAL_STRING(&_69$$21, "option");
								ZEPHIR_INIT_NVAR(&_70$$21);
								ZVAL_STRING(&_70$$21, "content");
								ZVAL_BOOL(&_71$$21, 1);
								ZEPHIR_CALL_METHOD(&_66$$21, this_ptr, "taghtml", &_23, 0, &_69$$21, &option, &_67$$21, &_68$$21, &_70$$21, &_71$$21);
								zephir_check_call_status();
								zephir_array_append(&suboptions, &_66$$21, PH_SEPARATE, "ice/tag.zep", 642);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _58$$20, "rewind", NULL, 0);
							zephir_check_call_status();
							_73$$20 = 1;
							while (1) {
								if (_73$$20) {
									_73$$20 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _58$$20, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_72$$20, _58$$20, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_72$$20)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&subvalue, _58$$20, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&subtext, _58$$20, "current", NULL, 0);
								zephir_check_call_status();
									zephir_cast_to_string(&_74$$23, &subvalue);
									ZEPHIR_CPY_WRT(&subvalue, &_74$$23);
									ZEPHIR_INIT_NVAR(&_75$$23);
									zephir_create_array(&_75$$23, 1, 0);
									zephir_array_update_string(&_75$$23, SL("value"), &subvalue, PH_COPY | PH_SEPARATE);
									ZEPHIR_CPY_WRT(&option, &_75$$23);
									if (zephir_fast_in_array(&subvalue, &selected)) {
										ZEPHIR_INIT_NVAR(&_76$$24);
										ZVAL_STRING(&_76$$24, "selected");
										zephir_array_update_string(&option, SL("selected"), &_76$$24, PH_COPY | PH_SEPARATE);
									}
									zephir_array_update_string(&option, SL("content"), &subtext, PH_COPY | PH_SEPARATE);
									ZEPHIR_INIT_NVAR(&_78$$23);
									array_init(&_78$$23);
									ZEPHIR_INIT_NVAR(&_79$$23);
									zephir_create_array(&_79$$23, 1, 0);
									ZEPHIR_INIT_NVAR(&_80$$23);
									ZVAL_STRING(&_80$$23, "content");
									zephir_array_fast_append(&_79$$23, &_80$$23);
									ZEPHIR_INIT_NVAR(&_80$$23);
									ZVAL_STRING(&_80$$23, "option");
									ZEPHIR_INIT_NVAR(&_81$$23);
									ZVAL_STRING(&_81$$23, "content");
									ZVAL_BOOL(&_82$$23, 1);
									ZEPHIR_CALL_METHOD(&_77$$23, this_ptr, "taghtml", &_23, 0, &_80$$23, &option, &_78$$23, &_79$$23, &_81$$23, &_82$$23);
									zephir_check_call_status();
									zephir_array_append(&suboptions, &_77$$23, PH_SEPARATE, "ice/tag.zep", 642);
							}
						}
						ZEPHIR_INIT_NVAR(&subtext);
						ZEPHIR_INIT_NVAR(&subvalue);
						ZEPHIR_INIT_NVAR(&_83$$20);
						ZEPHIR_GET_CONSTANT(&_83$$20, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_84$$20);
						ZEPHIR_INIT_NVAR(&_85$$20);
						ZEPHIR_GET_CONSTANT(&_85$$20, "PHP_EOL");
						zephir_fast_join(&_84$$20, &_85$$20, &suboptions);
						ZEPHIR_INIT_NVAR(&_86$$20);
						ZEPHIR_GET_CONSTANT(&_86$$20, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_87$$20);
						ZEPHIR_CONCAT_VVV(&_87$$20, &_83$$20, &_84$$20, &_86$$20);
						zephir_array_update_string(&group, SL("content"), &_87$$20, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_89$$20);
						array_init(&_89$$20);
						ZEPHIR_INIT_NVAR(&_90$$20);
						zephir_create_array(&_90$$20, 1, 0);
						ZEPHIR_INIT_NVAR(&_91$$20);
						ZVAL_STRING(&_91$$20, "content");
						zephir_array_fast_append(&_90$$20, &_91$$20);
						ZEPHIR_INIT_NVAR(&_91$$20);
						ZVAL_STRING(&_91$$20, "optgroup");
						ZEPHIR_INIT_NVAR(&_92$$20);
						ZVAL_STRING(&_92$$20, "content");
						ZVAL_BOOL(&_93$$20, 1);
						ZEPHIR_CALL_METHOD(&_88$$20, this_ptr, "taghtml", &_23, 0, &_91$$20, &group, &_89$$20, &_90$$20, &_92$$20, &_93$$20);
						zephir_check_call_status();
						zephir_array_update_zval(&options, &value, &_88$$20, PH_COPY | PH_SEPARATE);
					} else {
						zephir_cast_to_string(&_94$$25, &value);
						ZEPHIR_CPY_WRT(&value, &_94$$25);
						ZEPHIR_INIT_NVAR(&_95$$25);
						zephir_create_array(&_95$$25, 1, 0);
						zephir_array_update_string(&_95$$25, SL("value"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&option, &_95$$25);
						if (zephir_fast_in_array(&value, &selected)) {
							ZEPHIR_INIT_NVAR(&_96$$26);
							ZVAL_STRING(&_96$$26, "selected");
							zephir_array_update_string(&option, SL("selected"), &_96$$26, PH_COPY | PH_SEPARATE);
						}
						zephir_array_update_string(&option, SL("content"), &text, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_98$$25);
						array_init(&_98$$25);
						ZEPHIR_INIT_NVAR(&_99$$25);
						zephir_create_array(&_99$$25, 1, 0);
						ZEPHIR_INIT_NVAR(&_100$$25);
						ZVAL_STRING(&_100$$25, "content");
						zephir_array_fast_append(&_99$$25, &_100$$25);
						ZEPHIR_INIT_NVAR(&_100$$25);
						ZVAL_STRING(&_100$$25, "option");
						ZEPHIR_INIT_NVAR(&_101$$25);
						ZVAL_STRING(&_101$$25, "content");
						ZVAL_BOOL(&_102$$25, 1);
						ZEPHIR_CALL_METHOD(&_97$$25, this_ptr, "taghtml", &_23, 0, &_100$$25, &option, &_98$$25, &_99$$25, &_101$$25, &_102$$25);
						zephir_check_call_status();
						zephir_array_update_zval(&options, &value, &_97$$25, PH_COPY | PH_SEPARATE);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&text);
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_VAR(&_103$$10);
		ZEPHIR_INIT_VAR(&_104$$10);
		ZEPHIR_GET_CONSTANT(&_104$$10, "PHP_EOL");
		zephir_fast_join(&_103$$10, &_104$$10, &options);
		zephir_array_update_string(&parameters, SL("content"), &_103$$10, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_105);
	zephir_create_array(&_105, 3, 0);
	ZEPHIR_INIT_VAR(&_106);
	ZVAL_STRING(&_106, "content");
	zephir_array_fast_append(&_105, &_106);
	ZEPHIR_INIT_NVAR(&_106);
	ZVAL_STRING(&_106, "options");
	zephir_array_fast_append(&_105, &_106);
	ZEPHIR_INIT_NVAR(&_106);
	ZVAL_STRING(&_106, "value");
	zephir_array_fast_append(&_105, &_106);
	ZEPHIR_INIT_NVAR(&_106);
	ZVAL_STRING(&_106, "select");
	ZEPHIR_INIT_VAR(&_107);
	ZVAL_STRING(&_107, "content");
	ZVAL_BOOL(&_108, 1);
	ZVAL_BOOL(&_109, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "taghtml", &_23, 0, &_106, &parameters, &defaultParams, &_105, &_107, &_108, &_109);
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
PHP_METHOD(Ice_Tag, tagHtml)
{
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool close, eol, single, _4, _7, _11$$14, _12$$14;
	zval parameters, defaultParams, skip;
	zval name_zv, *parameters_param = NULL, *defaultParams_param = NULL, *skip_param = NULL, content_zv, *close_param = NULL, *eol_param = NULL, *single_param = NULL, params, param, key, value, attributes, code, *_0, _3, *_5, _6, _8, _9, _10$$13, _13$$14, _14$$14, _15$$15, _16$$17, _17$$17, _18$$17, _19$$17;
	zend_string *name = NULL, *content = NULL, *_2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&content_zv);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&defaultParams);
	ZVAL_UNDEF(&skip);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 8)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
		ZEPHIR_Z_PARAM_ARRAY(defaultParams, defaultParams_param)
		ZEPHIR_Z_PARAM_ARRAY(skip, skip_param)
		Z_PARAM_STR_OR_NULL(content)
		Z_PARAM_BOOL(close)
		Z_PARAM_BOOL(eol)
		Z_PARAM_BOOL(single)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		parameters_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		defaultParams_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		skip_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 5) {
		close_param = ZEND_CALL_ARG(execute_data, 6);
	}
	if (ZEND_NUM_ARGS() > 6) {
		eol_param = ZEND_CALL_ARG(execute_data, 7);
	}
	if (ZEND_NUM_ARGS() > 7) {
		single_param = ZEND_CALL_ARG(execute_data, 8);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
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
	if (!content) {
		ZEPHIR_INIT_VAR(&content_zv);
	} else {
		zephir_memory_observe(&content_zv);
	ZVAL_STR_COPY(&content_zv, content);
	}
	if (!close_param) {
		close = 0;
	} else {
		}
	if (!eol_param) {
		eol = 0;
	} else {
		}
	if (!single_param) {
		single = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&attributes);
	array_init(&attributes);
	ZEPHIR_CPY_WRT(&params, &parameters);
	zephir_is_iterable(&defaultParams, 0, "ice/tag.zep", 703);
	if (Z_TYPE_P(&defaultParams) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&defaultParams), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&param);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&param, _2);
			} else {
				ZVAL_LONG(&param, _1);
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
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &defaultParams, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &defaultParams, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
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
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&param);
	zephir_is_iterable(&defaultParams, 0, "ice/tag.zep", 707);
	if (Z_TYPE_P(&defaultParams) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&defaultParams), _5)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _5);
			zephir_array_unset(&params, &key, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &defaultParams, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &defaultParams, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &defaultParams, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &defaultParams, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_unset(&params, &key, PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_8);
	zephir_fast_array_merge(&_8, &attributes, &params);
	ZEPHIR_CPY_WRT(&attributes, &_8);
	if (single) {
		ZVAL_BOOL(&_9, 1);
	} else {
		ZVAL_BOOL(&_9, 0);
	}
	ZEPHIR_CALL_METHOD(&code, this_ptr, "preparetag", NULL, 0, &name_zv, &attributes, &skip, &_9);
	zephir_check_call_status();
	if (eol) {
		ZEPHIR_INIT_VAR(&_10$$13);
		ZEPHIR_GET_CONSTANT(&_10$$13, "PHP_EOL");
		zephir_concat_self(&code, &_10$$13);
	}
	if (!(ZEPHIR_IS_EMPTY(&content_zv))) {
		_11$$14 = ZEPHIR_IS_STRING(&name_zv, "textarea");
		if (_11$$14) {
			_11$$14 = zephir_array_isset_value_string(&attributes, SL("name"));
		}
		_12$$14 = _11$$14;
		if (_12$$14) {
			zephir_memory_observe(&_14$$14);
			zephir_array_fetch_string(&_14$$14, &attributes, SL("name"), PH_NOISY, "ice/tag.zep", 716);
			ZEPHIR_CALL_METHOD(&_13$$14, this_ptr, "hasvalue", NULL, 0, &_14$$14);
			zephir_check_call_status();
			_12$$14 = zephir_is_true(&_13$$14);
		}
		if (_12$$14) {
			zephir_memory_observe(&_15$$15);
			zephir_array_fetch_string(&_15$$15, &attributes, SL("name"), PH_NOISY, "ice/tag.zep", 717);
			ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0, &_15$$15);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_isset_fetch(&value, &attributes, &content_zv, 0);
		}
		zephir_concat_self(&code, &value);
	}
	if (close) {
		ZEPHIR_INIT_VAR(&_16$$17);
		if (eol) {
			ZEPHIR_INIT_NVAR(&_16$$17);
			ZEPHIR_GET_CONSTANT(&_16$$17, "PHP_EOL");
		} else {
			ZEPHIR_INIT_NVAR(&_16$$17);
			ZVAL_STRING(&_16$$17, "");
		}
		if (eol) {
			ZVAL_BOOL(&_18$$17, 1);
		} else {
			ZVAL_BOOL(&_18$$17, 0);
		}
		ZEPHIR_CALL_METHOD(&_17$$17, this_ptr, "endtag", NULL, 0, &name_zv, &_18$$17);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_19$$17);
		ZEPHIR_CONCAT_VV(&_19$$17, &_16$$17, &_17$$17);
		zephir_concat_self(&code, &_19$$17);
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
PHP_METHOD(Ice_Tag, endTag)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool eol;
	zval name_zv, *eol_param = NULL, _0;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(eol)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		eol_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!eol_param) {
		eol = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	if (eol) {
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	}
	ZEPHIR_CONCAT_SVSV(return_value, "</", &name_zv, ">", &_0);
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
PHP_METHOD(Ice_Tag, prepareTag)
{
	zend_ulong _12;
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool single, _4$$5, _14$$8, _15$$8, _16$$8;
	zval attributes, skip;
	zval name_zv, *attributes_param = NULL, *skip_param = NULL, *single_param = NULL, order, keys, attrs, code, type, tmp, value, key, _0, _1, *_10, *_11, _3$$3, _5$$5, _6$$5, _8$$6, _9$$7, _17$$9, _22$$9, _18$$10, _19$$10, _20$$10, _21$$10, _23$$11, _24$$11;
	zend_string *name = NULL, *_13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
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
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&skip);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("escape", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("di", 2, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("docType", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(name)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(skip, skip_param)
		Z_PARAM_BOOL(single)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	attributes_param = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		skip_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		single_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
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
	ZEPHIR_CALL_FUNCTION(&_1, "array_flip", NULL, 9, &order);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&keys, "array_intersect_key", NULL, 10, &_1, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&attrs);
	zephir_fast_array_merge(&attrs, &keys, &attributes);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "<", &name_zv);
	ZEPHIR_CPY_WRT(&code, &_2);
	zephir_memory_observe(&tmp);
	if (zephir_array_isset_string_fetch(&tmp, &attrs, SL("name"), 0)) {
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "hasvalue", NULL, 0, &tmp);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			zephir_memory_observe(&type);
			zephir_array_isset_string_fetch(&type, &attrs, SL("type"), 0);
			if (ZEPHIR_IS_STRING(&type, "radio")) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_STRING(&type, "checkbox")) { goto zephir_switch_0_clause_1; }
			goto zephir_switch_0_clause_2;
			zephir_switch_0_clause_0: ;
			zephir_switch_0_clause_1: ;
				_4$$5 = zephir_array_isset_value_string(&attrs, SL("value"));
				if (_4$$5) {
					zephir_memory_observe(&_5$$5);
					zephir_array_fetch_string(&_5$$5, &attrs, SL("value"), PH_NOISY, "ice/tag.zep", 776);
					ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "getvalue", &_7, 0, &tmp);
					zephir_check_call_status();
					_4$$5 = ZEPHIR_IS_EQUAL(&_5$$5, &_6$$5);
				}
				if (_4$$5) {
					ZEPHIR_INIT_VAR(&_8$$6);
					ZVAL_STRING(&_8$$6, "checked");
					zephir_array_update_string(&attrs, SL("checked"), &_8$$6, PH_COPY | PH_SEPARATE);
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
				ZEPHIR_CALL_METHOD(&_9$$7, this_ptr, "getvalue", &_7, 0, &tmp);
				zephir_check_call_status();
				zephir_array_update_string(&attrs, SL("value"), &_9$$7, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_end: ;

		}
	}
	if (Z_TYPE_P(&attrs) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_string_to_char_array(&_0, &attrs);
		_10 = &_0;
	} else {
		_10 = &attrs;
	}
	zephir_is_iterable(_10, 0, "ice/tag.zep", 796);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_10), _12, _13, _11)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_13 != NULL) { 
			ZVAL_STR_COPY(&key, _13);
		} else {
			ZVAL_LONG(&key, _12);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _11);
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
			zephir_read_property_cached(&_17$$9, this_ptr, _zephir_prop_0, 267, PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_17$$9)) {
				zephir_read_property_cached(&_18$$10, this_ptr, _zephir_prop_1, 268, PH_NOISY_CC | PH_READONLY);
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
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (single) {
		ZEPHIR_INIT_VAR(&_23$$11);
		zephir_read_property_cached(&_24$$11, this_ptr, _zephir_prop_2, 263, PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT_LONG(&_24$$11, 5)) {
			ZEPHIR_INIT_NVAR(&_23$$11);
			ZVAL_STRING(&_23$$11, " />");
		} else {
			ZEPHIR_INIT_NVAR(&_23$$11);
			ZVAL_STRING(&_23$$11, ">");
		}
		zephir_concat_self(&code, &_23$$11);
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
PHP_METHOD(Ice_Tag, hasValue)
{
	zval name_zv, _POST, _0$$4;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_0$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("values", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_get_global(&_POST, SL("_POST"));
	ZVAL_STR(&name_zv, name);
	if (zephir_array_isset_value(&_POST, &name_zv)) {
		RETURN_BOOL(1);
	} else {
		zephir_read_property_cached(&_0$$4, this_ptr, _zephir_prop_0, 269, PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value(&_0$$4, &name_zv)) {
			RETURN_BOOL(1);
		}
	}
	RETURN_BOOL(0);
}

/**
 * Assigns default values to generated tags by helpers.
 *
 * @param string id
 * @param mixed value
 * @return object Tag
 */
PHP_METHOD(Ice_Tag, setValue)
{
	zend_bool _0$$3;
	zval id_zv, *value, value_sub;
	zend_string *id = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(id)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&id_zv, id);
	if (Z_TYPE_P(value) != IS_NULL) {
		_0$$3 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_0$$3)) {
			_0$$3 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(ice_exception_ce, "Only scalar values can be assigned to UI components", "ice/tag.zep", 837);
			return;
		}
	}
	zephir_update_property_array(this_ptr, SL("values"), &id_zv, value);
	RETURN_THISW();
}

/**
 * Assigns default values to generated tags by helpers.
 *
 * @param array values
 * @param boolean merge
 * @return object Tag
 */
PHP_METHOD(Ice_Tag, setValues)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *values_param = NULL, *merge_param = NULL, current, _0$$5;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&_0$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("values", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &values_param, &merge_param);
	zephir_get_arrval(&values, values_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "An array is required as default values", "ice/tag.zep", 857);
		return;
	}
	if (merge) {
		zephir_memory_observe(&current);
		zephir_read_property_cached(&current, this_ptr, _zephir_prop_0, 269, PH_NOISY_CC);
		if (Z_TYPE_P(&current) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$5);
			zephir_fast_array_merge(&_0$$5, &current, &values);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 269, &_0$$5);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 269, &values);
		}
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 269, &values);
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
PHP_METHOD(Ice_Tag, getValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, _POST, value, _0$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("values", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_POST, SL("_POST"));
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&value);
	if (!(zephir_array_isset_fetch(&value, &_POST, &name_zv, 0))) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 269, PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_fetch(&value, &_0$$3, &name_zv, 0))) {
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
PHP_METHOD(Ice_Tag, friendlyTitle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_21 = NULL;
	zend_bool lowercase, _8$$4, _15$$6;
	zend_string *separator = NULL;
	zval *text_param = NULL, separator_zv, *lowercase_param = NULL, *replace = NULL, replace_sub, __$null, friendly, locale, search, _0, _1, _20, _23, _3$$3, _4$$3, _6$$3, _7$$3, *_9$$6, _10$$6, *_11$$6, _14$$6, _12$$7, _13$$7, _16$$8, _17$$8, _18$$9, _19$$9, _22$$10, _24$$11;
	zval text;

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&replace_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&friendly);
	ZVAL_UNDEF(&locale);
	ZVAL_UNDEF(&search);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_24$$11);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_ZVAL(text_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(separator)
		Z_PARAM_BOOL(lowercase)
		Z_PARAM_ZVAL_OR_NULL(replace)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	text_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		lowercase_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		replace = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_get_strval(&text, text_param);
	if (!separator) {
		separator = zend_string_init(ZEND_STRL("-"), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!lowercase_param) {
		lowercase = 1;
	} else {
		}
	if (!replace) {
		replace = &replace_sub;
		replace = &__$null;
	}
	ZEPHIR_INIT_VAR(&locale);
	ZVAL_NULL(&locale);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "iconv");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, 212, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZVAL_LONG(&_3$$3, 6);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "en_US.UTF-8");
		ZEPHIR_CALL_FUNCTION(&locale, "setlocale", &_5, 213, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "UTF-8");
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "ASCII//TRANSLIT");
		ZEPHIR_CALL_FUNCTION(&_7$$3, "iconv", NULL, 214, &_4$$3, &_6$$3, &text);
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
			if (Z_TYPE_P(replace) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_10$$6);
				zephir_string_to_char_array(&_10$$6, replace);
				_9$$6 = &_10$$6;
			} else {
				_9$$6 = replace;
			}
			zephir_is_iterable(_9$$6, 0, "ice/tag.zep", 931);
			if (Z_TYPE_P(_9$$6) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$6), _11$$6)
				{
					ZEPHIR_INIT_NVAR(&search);
					ZVAL_COPY(&search, _11$$6);
					ZEPHIR_INIT_NVAR(&_12$$7);
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZVAL_STRING(&_13$$7, " ");
					zephir_fast_str_replace(&_12$$7, &search, &_13$$7, &text);
					zephir_get_strval(&text, &_12$$7);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _9$$6, "rewind", NULL, 0);
				zephir_check_call_status();
				_15$$6 = 1;
				while (1) {
					if (_15$$6) {
						_15$$6 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _9$$6, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_14$$6, _9$$6, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_14$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&search, _9$$6, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_16$$8);
						ZEPHIR_INIT_NVAR(&_17$$8);
						ZVAL_STRING(&_17$$8, " ");
						zephir_fast_str_replace(&_16$$8, &search, &_17$$8, &text);
						zephir_get_strval(&text, &_16$$8);
				}
			}
			ZEPHIR_INIT_NVAR(&search);
		} else {
			ZEPHIR_INIT_VAR(&_18$$9);
			ZEPHIR_INIT_VAR(&_19$$9);
			ZVAL_STRING(&_19$$9, " ");
			zephir_fast_str_replace(&_18$$9, replace, &_19$$9, &text);
			zephir_get_strval(&text, &_18$$9);
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/[^a-zA-Z0-9\\/_|+ -]/");
	ZEPHIR_INIT_VAR(&_20);
	ZVAL_STRING(&_20, "");
	ZEPHIR_CALL_FUNCTION(&friendly, "preg_replace", &_21, 53, &_0, &_20, &text);
	zephir_check_call_status();
	if (lowercase) {
		ZEPHIR_INIT_VAR(&_22$$10);
		zephir_fast_strtolower(&_22$$10, &friendly);
		ZEPHIR_CPY_WRT(&friendly, &_22$$10);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/[\\/_|+ -]+/");
	ZEPHIR_CALL_FUNCTION(&_23, "preg_replace", &_21, 53, &_0, &separator_zv, &friendly);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&friendly, &_23);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_trim(&_0, &friendly, &separator_zv, ZEPHIR_TRIM_BOTH);
	ZEPHIR_CPY_WRT(&friendly, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "iconv");
	ZEPHIR_CALL_FUNCTION(&_23, "extension_loaded", &_2, 212, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_23)) {
		ZVAL_LONG(&_24$$11, 6);
		ZEPHIR_CALL_FUNCTION(NULL, "setlocale", &_5, 213, &_24$$11, &locale);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&friendly);
}

/**
 * Get the document type declaration of content.
 *
 * @return string
 */
PHP_METHOD(Ice_Tag, getDocType)
{
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("docType", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 263, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 1)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&_0, 2)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&_0, 3)) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_LONG(&_0, 4)) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_LONG(&_0, 5)) { goto zephir_switch_0_clause_4; }
	if (ZEPHIR_IS_LONG(&_0, 6)) { goto zephir_switch_0_clause_5; }
	if (ZEPHIR_IS_LONG(&_0, 7)) { goto zephir_switch_0_clause_6; }
	if (ZEPHIR_IS_LONG(&_0, 8)) { goto zephir_switch_0_clause_7; }
	if (ZEPHIR_IS_LONG(&_0, 9)) { goto zephir_switch_0_clause_8; }
	if (ZEPHIR_IS_LONG(&_0, 10)) { goto zephir_switch_0_clause_9; }
	if (ZEPHIR_IS_LONG(&_0, 11)) { goto zephir_switch_0_clause_10; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_GET_CONSTANT(&_1$$3, "PHP_EOL");
		ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">", &_1$$3);
		RETURN_MM();
	zephir_switch_0_clause_1: ;
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_GET_CONSTANT(&_2$$4, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_GET_CONSTANT(&_3$$4, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"", &_2$$4, "\t\"http://www.w3.org/TR/html4/strict.dtd\">", &_3$$4);
		RETURN_MM();
	zephir_switch_0_clause_2: ;
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_GET_CONSTANT(&_4$$5, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_5$$5);
		ZEPHIR_GET_CONSTANT(&_5$$5, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"", &_4$$5, "\t\"http://www.w3.org/TR/html4/loose.dtd\">", &_5$$5);
		RETURN_MM();
	zephir_switch_0_clause_3: ;
		ZEPHIR_INIT_VAR(&_6$$6);
		ZEPHIR_GET_CONSTANT(&_6$$6, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_7$$6);
		ZEPHIR_GET_CONSTANT(&_7$$6, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"", &_6$$6, "\t\"http://www.w3.org/TR/html4/frameset.dtd\">", &_7$$6);
		RETURN_MM();
	zephir_switch_0_clause_4: ;
		ZEPHIR_INIT_VAR(&_8$$7);
		ZEPHIR_GET_CONSTANT(&_8$$7, "PHP_EOL");
		ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", &_8$$7);
		RETURN_MM();
	zephir_switch_0_clause_5: ;
		ZEPHIR_INIT_VAR(&_9$$8);
		ZEPHIR_GET_CONSTANT(&_9$$8, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_10$$8);
		ZEPHIR_GET_CONSTANT(&_10$$8, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"", &_9$$8, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">", &_10$$8);
		RETURN_MM();
	zephir_switch_0_clause_6: ;
		ZEPHIR_INIT_VAR(&_11$$9);
		ZEPHIR_GET_CONSTANT(&_11$$9, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_12$$9);
		ZEPHIR_GET_CONSTANT(&_12$$9, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"", &_11$$9, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">", &_12$$9);
		RETURN_MM();
	zephir_switch_0_clause_7: ;
		ZEPHIR_INIT_VAR(&_13$$10);
		ZEPHIR_GET_CONSTANT(&_13$$10, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_14$$10);
		ZEPHIR_GET_CONSTANT(&_14$$10, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"", &_13$$10, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">", &_14$$10);
		RETURN_MM();
	zephir_switch_0_clause_8: ;
		ZEPHIR_INIT_VAR(&_15$$11);
		ZEPHIR_GET_CONSTANT(&_15$$11, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_16$$11);
		ZEPHIR_GET_CONSTANT(&_16$$11, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"", &_15$$11, "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">", &_16$$11);
		RETURN_MM();
	zephir_switch_0_clause_9: ;
		ZEPHIR_INIT_VAR(&_17$$12);
		ZEPHIR_GET_CONSTANT(&_17$$12, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_18$$12);
		ZEPHIR_GET_CONSTANT(&_18$$12, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"", &_17$$12, "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">", &_18$$12);
		RETURN_MM();
	zephir_switch_0_clause_10: ;
		ZEPHIR_INIT_VAR(&_19$$13);
		ZEPHIR_GET_CONSTANT(&_19$$13, "PHP_EOL");
		ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", &_19$$13);
		RETURN_MM();
	zephir_switch_0_end: ;

	RETURN_MM_STRING("");
}

zend_object *zephir_init_properties_Ice_Tag(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("meta"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("meta"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

