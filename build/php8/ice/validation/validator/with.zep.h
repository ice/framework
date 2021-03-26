
extern zend_class_entry *ice_validation_validator_with_ce;

ZEPHIR_INIT_CLASS(Ice_Validation_Validator_With);

PHP_METHOD(Ice_Validation_Validator_With, validate);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_validation_validator_with_validate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Ice\\Validation, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_validation_validator_with_method_entry) {
	PHP_ME(Ice_Validation_Validator_With, validate, arginfo_ice_validation_validator_with_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
