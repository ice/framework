
extern zend_class_entry *ice_validation_validator_ce;

ZEPHIR_INIT_CLASS(Ice_Validation_Validator);

PHP_METHOD(Ice_Validation_Validator, __construct);
PHP_METHOD(Ice_Validation_Validator, validate);
PHP_METHOD(Ice_Validation_Validator, has);
PHP_METHOD(Ice_Validation_Validator, get);
PHP_METHOD(Ice_Validation_Validator, set);
PHP_METHOD(Ice_Validation_Validator, getOptions);
zend_object_value zephir_init_properties_Ice_Validation_Validator(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_validator___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_validator_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Ice\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_validator_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_validator_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_validator_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_validation_validator_getoptions, 0, 0, 0)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_validation_validator_method_entry) {
	PHP_ME(Ice_Validation_Validator, __construct, arginfo_ice_validation_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Validation_Validator, validate, arginfo_ice_validation_validator_validate, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Ice_Validation_Validator, has, arginfo_ice_validation_validator_has, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation_Validator, get, arginfo_ice_validation_validator_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation_Validator, set, arginfo_ice_validation_validator_set, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Validation_Validator, getOptions, arginfo_ice_validation_validator_getoptions, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
