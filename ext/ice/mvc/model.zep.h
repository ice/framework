
extern zend_class_entry *ice_mvc_model_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Model);

PHP_METHOD(Ice_Mvc_Model, getDi);
PHP_METHOD(Ice_Mvc_Model, getDb);
PHP_METHOD(Ice_Mvc_Model, setFrom);
PHP_METHOD(Ice_Mvc_Model, setFields);
PHP_METHOD(Ice_Mvc_Model, getFields);
PHP_METHOD(Ice_Mvc_Model, getRelations);
PHP_METHOD(Ice_Mvc_Model, setLabels);
PHP_METHOD(Ice_Mvc_Model, getMessages);
PHP_METHOD(Ice_Mvc_Model, __construct);
PHP_METHOD(Ice_Mvc_Model, loadOne);
PHP_METHOD(Ice_Mvc_Model, load);
PHP_METHOD(Ice_Mvc_Model, findOne);
PHP_METHOD(Ice_Mvc_Model, find);
PHP_METHOD(Ice_Mvc_Model, fields);
PHP_METHOD(Ice_Mvc_Model, create);
PHP_METHOD(Ice_Mvc_Model, update);
PHP_METHOD(Ice_Mvc_Model, save);
PHP_METHOD(Ice_Mvc_Model, remove);
PHP_METHOD(Ice_Mvc_Model, getError);
PHP_METHOD(Ice_Mvc_Model, belongsTo);
PHP_METHOD(Ice_Mvc_Model, hasOne);
PHP_METHOD(Ice_Mvc_Model, hasMany);
PHP_METHOD(Ice_Mvc_Model, getRelated);
PHP_METHOD(Ice_Mvc_Model, setRules);
PHP_METHOD(Ice_Mvc_Model, serialize);
PHP_METHOD(Ice_Mvc_Model, unserialize);
PHP_METHOD(Ice_Mvc_Model, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setfields, 0, 0, 1)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setlabels, 0, 0, 1)
	ZEND_ARG_INFO(0, labels)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_loadone, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_load, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_findone, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_find, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_fields, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_create, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_OBJ_INFO(0, extra, Ice\\Validation, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_update, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_OBJ_INFO(0, extra, Ice\\Validation, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_save, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_OBJ_INFO(0, extra, Ice\\Validation, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_remove, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_belongsto, 0, 0, 3)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedField)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_hasone, 0, 0, 3)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedField)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_hasmany, 0, 0, 3)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedField)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getrelated, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_ARRAY_INFO(0, filters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setrules, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, rules, 1)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_model_method_entry) {
	PHP_ME(Ice_Mvc_Model, getDi, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, getDb, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, setFrom, arginfo_ice_mvc_model_setfrom, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, setFields, arginfo_ice_mvc_model_setfields, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, getFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, getRelations, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, setLabels, arginfo_ice_mvc_model_setlabels, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, __construct, arginfo_ice_mvc_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Mvc_Model, loadOne, arginfo_ice_mvc_model_loadone, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, load, arginfo_ice_mvc_model_load, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, findOne, arginfo_ice_mvc_model_findone, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Mvc_Model, find, arginfo_ice_mvc_model_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Mvc_Model, fields, arginfo_ice_mvc_model_fields, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, create, arginfo_ice_mvc_model_create, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, update, arginfo_ice_mvc_model_update, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, save, arginfo_ice_mvc_model_save, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, remove, arginfo_ice_mvc_model_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, belongsTo, arginfo_ice_mvc_model_belongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, hasOne, arginfo_ice_mvc_model_hasone, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, hasMany, arginfo_ice_mvc_model_hasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, getRelated, arginfo_ice_mvc_model_getrelated, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, setRules, arginfo_ice_mvc_model_setrules, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, unserialize, arginfo_ice_mvc_model_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, __call, arginfo_ice_mvc_model___call, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
