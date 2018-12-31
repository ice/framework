
extern zend_class_entry *ice_validation_ce;

ZEPHIR_INIT_CLASS(Ice_Validation);

PHP_METHOD(Ice_Validation, getDi);
PHP_METHOD(Ice_Validation, getData);
PHP_METHOD(Ice_Validation, setRules);
PHP_METHOD(Ice_Validation, getRules);
PHP_METHOD(Ice_Validation, setFilters);
PHP_METHOD(Ice_Validation, setLabels);
PHP_METHOD(Ice_Validation, setAliases);
PHP_METHOD(Ice_Validation, setTranslate);
PHP_METHOD(Ice_Validation, getTranslate);
PHP_METHOD(Ice_Validation, setHumanLabels);
PHP_METHOD(Ice_Validation, __construct);
PHP_METHOD(Ice_Validation, resolve);
PHP_METHOD(Ice_Validation, rule);
PHP_METHOD(Ice_Validation, rules);
PHP_METHOD(Ice_Validation, validate);
PHP_METHOD(Ice_Validation, valid);
PHP_METHOD(Ice_Validation, hasValue);
PHP_METHOD(Ice_Validation, getValue);
PHP_METHOD(Ice_Validation, getValues);
PHP_METHOD(Ice_Validation, getLabel);
PHP_METHOD(Ice_Validation, setDefaultMessages);
PHP_METHOD(Ice_Validation, getDefaultMessage);
PHP_METHOD(Ice_Validation, addMessage);
PHP_METHOD(Ice_Validation, getMessages);
zend_object_value zephir_init_properties_Ice_Validation(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_setrules, 0, 0, 1)
	ZEND_ARG_INFO(0, rules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_setfilters, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_setlabels, 0, 0, 1)
	ZEND_ARG_INFO(0, labels)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_setaliases, 0, 0, 1)
	ZEND_ARG_INFO(0, aliases)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_settranslate, 0, 0, 1)
	ZEND_ARG_INFO(0, translate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_sethumanlabels, 0, 0, 1)
	ZEND_ARG_INFO(0, humanLabels)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_resolve, 0, 0, 2)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_rule, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, validators)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_rules, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_validate, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, clear)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_hasvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, filtered)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_getvalues, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, filtered)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_getlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_setdefaultmessages, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, messages, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_getdefaultmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_addmessage, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_validation_method_entry) {
	PHP_ME(Ice_Validation, getDi, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, setRules, arginfo_ice_validation_setrules, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, getRules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, setFilters, arginfo_ice_validation_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, setLabels, arginfo_ice_validation_setlabels, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, setAliases, arginfo_ice_validation_setaliases, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, setTranslate, arginfo_ice_validation_settranslate, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, getTranslate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, setHumanLabels, arginfo_ice_validation_sethumanlabels, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, __construct, arginfo_ice_validation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Validation, resolve, arginfo_ice_validation_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, rule, arginfo_ice_validation_rule, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, rules, arginfo_ice_validation_rules, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, validate, arginfo_ice_validation_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, hasValue, arginfo_ice_validation_hasvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, getValue, arginfo_ice_validation_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, getValues, arginfo_ice_validation_getvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, getLabel, arginfo_ice_validation_getlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, setDefaultMessages, arginfo_ice_validation_setdefaultmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, getDefaultMessage, arginfo_ice_validation_getdefaultmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, addMessage, arginfo_ice_validation_addmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
