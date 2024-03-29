
extern zend_class_entry *ice_mvc_model_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Model);

PHP_METHOD(Ice_Mvc_Model, getDi);
PHP_METHOD(Ice_Mvc_Model, getDb);
PHP_METHOD(Ice_Mvc_Model, setFrom);
PHP_METHOD(Ice_Mvc_Model, setPrimary);
PHP_METHOD(Ice_Mvc_Model, getPrimary);
PHP_METHOD(Ice_Mvc_Model, setAutoincrement);
PHP_METHOD(Ice_Mvc_Model, setFilters);
PHP_METHOD(Ice_Mvc_Model, getFilters);
PHP_METHOD(Ice_Mvc_Model, setFields);
PHP_METHOD(Ice_Mvc_Model, getFields);
PHP_METHOD(Ice_Mvc_Model, setValidation);
PHP_METHOD(Ice_Mvc_Model, getValidation);
PHP_METHOD(Ice_Mvc_Model, getRelations);
PHP_METHOD(Ice_Mvc_Model, setLabels);
PHP_METHOD(Ice_Mvc_Model, getMessages);
PHP_METHOD(Ice_Mvc_Model, setMessages);
PHP_METHOD(Ice_Mvc_Model, __construct);
PHP_METHOD(Ice_Mvc_Model, getId);
PHP_METHOD(Ice_Mvc_Model, getIdKey);
PHP_METHOD(Ice_Mvc_Model, getDateTime);
PHP_METHOD(Ice_Mvc_Model, loadOne);
PHP_METHOD(Ice_Mvc_Model, load);
PHP_METHOD(Ice_Mvc_Model, findOne);
PHP_METHOD(Ice_Mvc_Model, find);
PHP_METHOD(Ice_Mvc_Model, fields);
PHP_METHOD(Ice_Mvc_Model, create);
PHP_METHOD(Ice_Mvc_Model, update);
PHP_METHOD(Ice_Mvc_Model, save);
PHP_METHOD(Ice_Mvc_Model, delete);
PHP_METHOD(Ice_Mvc_Model, exists);
PHP_METHOD(Ice_Mvc_Model, loaded);
PHP_METHOD(Ice_Mvc_Model, getError);
PHP_METHOD(Ice_Mvc_Model, belongsTo);
PHP_METHOD(Ice_Mvc_Model, hasOne);
PHP_METHOD(Ice_Mvc_Model, hasMany);
PHP_METHOD(Ice_Mvc_Model, getRelated);
PHP_METHOD(Ice_Mvc_Model, getRules);
PHP_METHOD(Ice_Mvc_Model, setRules);
PHP_METHOD(Ice_Mvc_Model, __serialize);
PHP_METHOD(Ice_Mvc_Model, __unserialize);
PHP_METHOD(Ice_Mvc_Model, __call);
zend_object *zephir_init_properties_Ice_Mvc_Model(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getdi, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getdb, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setprimary, 0, 0, 1)
	ZEND_ARG_INFO(0, primary)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getprimary, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setautoincrement, 0, 0, 1)
	ZEND_ARG_INFO(0, autoincrement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setfilters, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getfilters, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setfields, 0, 0, 1)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getfields, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setvalidation, 0, 0, 1)
	ZEND_ARG_INFO(0, validation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getvalidation, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getrelations, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setlabels, 0, 0, 1)
	ZEND_ARG_INFO(0, labels)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getmessages, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setmessages, 0, 0, 1)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getid, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_model_getidkey, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getdatetime, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_loadone, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_load, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_findone, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_find, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_fields, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, primary, _IS_BOOL, 0)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_delete, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_model_loaded, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_geterror, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_belongsto, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, referenceModel, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, referencedField, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_hasone, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, referenceModel, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, referencedField, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_hasmany, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, referenceModel, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, referencedField, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getrelated, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filters, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_getrules, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_setrules, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, rules, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, rules, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_model___serialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model___unserialize, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, serialized, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model___call, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_model_zephir_init_properties_ice_mvc_model, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_model_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Model, getDi, arginfo_ice_mvc_model_getdi, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Model, getDi, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Model, getDb, arginfo_ice_mvc_model_getdb, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Model, getDb, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Mvc_Model, setFrom, arginfo_ice_mvc_model_setfrom, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, setPrimary, arginfo_ice_mvc_model_setprimary, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Model, getPrimary, arginfo_ice_mvc_model_getprimary, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Model, getPrimary, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Mvc_Model, setAutoincrement, arginfo_ice_mvc_model_setautoincrement, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, setFilters, arginfo_ice_mvc_model_setfilters, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Model, getFilters, arginfo_ice_mvc_model_getfilters, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Model, getFilters, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Mvc_Model, setFields, arginfo_ice_mvc_model_setfields, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Model, getFields, arginfo_ice_mvc_model_getfields, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Model, getFields, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Mvc_Model, setValidation, arginfo_ice_mvc_model_setvalidation, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Model, getValidation, arginfo_ice_mvc_model_getvalidation, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Model, getValidation, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Model, getRelations, arginfo_ice_mvc_model_getrelations, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Model, getRelations, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Mvc_Model, setLabels, arginfo_ice_mvc_model_setlabels, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Model, getMessages, arginfo_ice_mvc_model_getmessages, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Model, getMessages, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Mvc_Model, setMessages, arginfo_ice_mvc_model_setmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, __construct, arginfo_ice_mvc_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Model, getId, arginfo_ice_mvc_model_getid, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Model, getId, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Mvc_Model, getIdKey, arginfo_ice_mvc_model_getidkey, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, getDateTime, arginfo_ice_mvc_model_getdatetime, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, loadOne, arginfo_ice_mvc_model_loadone, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, load, arginfo_ice_mvc_model_load, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, findOne, arginfo_ice_mvc_model_findone, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Mvc_Model, find, arginfo_ice_mvc_model_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Mvc_Model, fields, arginfo_ice_mvc_model_fields, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Mvc_Model, create, arginfo_ice_mvc_model_create, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, update, arginfo_ice_mvc_model_update, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, save, arginfo_ice_mvc_model_save, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, delete, arginfo_ice_mvc_model_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, exists, arginfo_ice_mvc_model_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, loaded, arginfo_ice_mvc_model_loaded, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Model, getError, arginfo_ice_mvc_model_geterror, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Model, getError, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Mvc_Model, belongsTo, arginfo_ice_mvc_model_belongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, hasOne, arginfo_ice_mvc_model_hasone, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, hasMany, arginfo_ice_mvc_model_hasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, getRelated, arginfo_ice_mvc_model_getrelated, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, getRules, arginfo_ice_mvc_model_getrules, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, setRules, arginfo_ice_mvc_model_setrules, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, __serialize, arginfo_ice_mvc_model___serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, __unserialize, arginfo_ice_mvc_model___unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Model, __call, arginfo_ice_mvc_model___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
