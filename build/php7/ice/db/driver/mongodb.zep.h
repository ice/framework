
extern zend_class_entry *ice_db_driver_mongodb_ce;

ZEPHIR_INIT_CLASS(Ice_Db_Driver_Mongodb);

PHP_METHOD(Ice_Db_Driver_Mongodb, getId);
PHP_METHOD(Ice_Db_Driver_Mongodb, getType);
PHP_METHOD(Ice_Db_Driver_Mongodb, getClient);
PHP_METHOD(Ice_Db_Driver_Mongodb, getLastInsertId);
PHP_METHOD(Ice_Db_Driver_Mongodb, __construct);
PHP_METHOD(Ice_Db_Driver_Mongodb, getIdValue);
PHP_METHOD(Ice_Db_Driver_Mongodb, getDateTime);
PHP_METHOD(Ice_Db_Driver_Mongodb, findOne);
PHP_METHOD(Ice_Db_Driver_Mongodb, find);
PHP_METHOD(Ice_Db_Driver_Mongodb, select);
PHP_METHOD(Ice_Db_Driver_Mongodb, insert);
PHP_METHOD(Ice_Db_Driver_Mongodb, update);
PHP_METHOD(Ice_Db_Driver_Mongodb, delete);
PHP_METHOD(Ice_Db_Driver_Mongodb, getError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongodb___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dsn, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dsn)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dbname, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, dbname)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_db_driver_mongodb_getidvalue, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_db_driver_mongodb_getidvalue, 0, 1, IS_OBJECT, "NULL", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongodb_getdatetime, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongodb_findone, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, from)
#endif
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongodb_find, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, from)
#endif
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongodb_select, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, from)
#endif
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongodb_insert, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, from)
#endif
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongodb_update, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, from)
#endif
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongodb_delete, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, from)
#endif
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_db_driver_mongodb_method_entry) {
	PHP_ME(Ice_Db_Driver_Mongodb, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, getClient, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, getLastInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, __construct, arginfo_ice_db_driver_mongodb___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Db_Driver_Mongodb, getIdValue, arginfo_ice_db_driver_mongodb_getidvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, getDateTime, arginfo_ice_db_driver_mongodb_getdatetime, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, findOne, arginfo_ice_db_driver_mongodb_findone, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, find, arginfo_ice_db_driver_mongodb_find, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, select, arginfo_ice_db_driver_mongodb_select, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, insert, arginfo_ice_db_driver_mongodb_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, update, arginfo_ice_db_driver_mongodb_update, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, delete, arginfo_ice_db_driver_mongodb_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongodb, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
