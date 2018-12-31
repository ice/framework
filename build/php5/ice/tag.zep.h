
extern zend_class_entry *ice_tag_ce;

ZEPHIR_INIT_CLASS(Ice_Tag);

PHP_METHOD(Ice_Tag, getDi);
PHP_METHOD(Ice_Tag, getValues);
PHP_METHOD(Ice_Tag, setDocType);
PHP_METHOD(Ice_Tag, setTitle);
PHP_METHOD(Ice_Tag, getTitle);
PHP_METHOD(Ice_Tag, setTitleSeparator);
PHP_METHOD(Ice_Tag, getTitleSeparator);
PHP_METHOD(Ice_Tag, setMeta);
PHP_METHOD(Ice_Tag, getMeta);
PHP_METHOD(Ice_Tag, setEscape);
PHP_METHOD(Ice_Tag, __construct);
PHP_METHOD(Ice_Tag, appendTitle);
PHP_METHOD(Ice_Tag, prependTitle);
PHP_METHOD(Ice_Tag, addMeta);
PHP_METHOD(Ice_Tag, textField);
PHP_METHOD(Ice_Tag, passwordField);
PHP_METHOD(Ice_Tag, hiddenField);
PHP_METHOD(Ice_Tag, fileField);
PHP_METHOD(Ice_Tag, submitButton);
PHP_METHOD(Ice_Tag, button);
PHP_METHOD(Ice_Tag, checkField);
PHP_METHOD(Ice_Tag, radioField);
PHP_METHOD(Ice_Tag, input);
PHP_METHOD(Ice_Tag, form);
PHP_METHOD(Ice_Tag, endForm);
PHP_METHOD(Ice_Tag, textArea);
PHP_METHOD(Ice_Tag, image);
PHP_METHOD(Ice_Tag, img);
PHP_METHOD(Ice_Tag, linkTo);
PHP_METHOD(Ice_Tag, a);
PHP_METHOD(Ice_Tag, link);
PHP_METHOD(Ice_Tag, script);
PHP_METHOD(Ice_Tag, style);
PHP_METHOD(Ice_Tag, meta);
PHP_METHOD(Ice_Tag, select);
PHP_METHOD(Ice_Tag, tagHtml);
PHP_METHOD(Ice_Tag, endTag);
PHP_METHOD(Ice_Tag, prepareTag);
PHP_METHOD(Ice_Tag, hasValue);
PHP_METHOD(Ice_Tag, setValue);
PHP_METHOD(Ice_Tag, setValues);
PHP_METHOD(Ice_Tag, getValue);
PHP_METHOD(Ice_Tag, friendlyTitle);
PHP_METHOD(Ice_Tag, getDocType);
zend_object_value zephir_init_properties_Ice_Tag(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_setdoctype, 0, 0, 1)
	ZEND_ARG_INFO(0, docType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_settitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_settitleseparator, 0, 0, 1)
	ZEND_ARG_INFO(0, titleSeparator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_setmeta, 0, 0, 1)
	ZEND_ARG_INFO(0, meta)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_setescape, 0, 0, 1)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_appendtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_prependtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_addmeta, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_textfield, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_passwordfield, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_hiddenfield, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_filefield, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_submitbutton, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_button, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_checkfield, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_radiofield, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_input, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_form, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_textarea, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_image, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_img, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_linkto, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_a, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_link, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_script, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_style, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_meta, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_select, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_taghtml, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
	ZEND_ARG_ARRAY_INFO(0, defaultParams, 0)
	ZEND_ARG_ARRAY_INFO(0, skip, 0)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, close)
	ZEND_ARG_INFO(0, eol)
	ZEND_ARG_INFO(0, single)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_endtag, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, eol)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_preparetag, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
	ZEND_ARG_ARRAY_INFO(0, skip, 0)
	ZEND_ARG_INFO(0, single)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_hasvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_setvalue, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_setvalues, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_tag_friendlytitle, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, separator)
	ZEND_ARG_INFO(0, lowercase)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_tag_method_entry) {
	PHP_ME(Ice_Tag, getDi, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, getValues, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, setDocType, arginfo_ice_tag_setdoctype, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, setTitle, arginfo_ice_tag_settitle, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, getTitle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, setTitleSeparator, arginfo_ice_tag_settitleseparator, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, getTitleSeparator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, setMeta, arginfo_ice_tag_setmeta, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, getMeta, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, setEscape, arginfo_ice_tag_setescape, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Tag, appendTitle, arginfo_ice_tag_appendtitle, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, prependTitle, arginfo_ice_tag_prependtitle, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, addMeta, arginfo_ice_tag_addmeta, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, textField, arginfo_ice_tag_textfield, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, passwordField, arginfo_ice_tag_passwordfield, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, hiddenField, arginfo_ice_tag_hiddenfield, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, fileField, arginfo_ice_tag_filefield, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, submitButton, arginfo_ice_tag_submitbutton, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, button, arginfo_ice_tag_button, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, checkField, arginfo_ice_tag_checkfield, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, radioField, arginfo_ice_tag_radiofield, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, input, arginfo_ice_tag_input, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, form, arginfo_ice_tag_form, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, endForm, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, textArea, arginfo_ice_tag_textarea, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, image, arginfo_ice_tag_image, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, img, arginfo_ice_tag_img, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, linkTo, arginfo_ice_tag_linkto, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, a, arginfo_ice_tag_a, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, link, arginfo_ice_tag_link, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, script, arginfo_ice_tag_script, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, style, arginfo_ice_tag_style, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, meta, arginfo_ice_tag_meta, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, select, arginfo_ice_tag_select, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, tagHtml, arginfo_ice_tag_taghtml, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, endTag, arginfo_ice_tag_endtag, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, prepareTag, arginfo_ice_tag_preparetag, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, hasValue, arginfo_ice_tag_hasvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, setValue, arginfo_ice_tag_setvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, setValues, arginfo_ice_tag_setvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, getValue, arginfo_ice_tag_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, friendlyTitle, arginfo_ice_tag_friendlytitle, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Tag, getDocType, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
