
extern zend_class_entry *ice_db_driver_mongo_ce;

ZEPHIR_INIT_CLASS(Ice_Db_Driver_Mongo);

PHP_METHOD(Ice_Db_Driver_Mongo, getId);
PHP_METHOD(Ice_Db_Driver_Mongo, getType);
PHP_METHOD(Ice_Db_Driver_Mongo, getClient);
PHP_METHOD(Ice_Db_Driver_Mongo, getLastInsertId);
PHP_METHOD(Ice_Db_Driver_Mongo, __construct);
PHP_METHOD(Ice_Db_Driver_Mongo, getIdValue);
PHP_METHOD(Ice_Db_Driver_Mongo, getDateTime);
PHP_METHOD(Ice_Db_Driver_Mongo, findOne);
PHP_METHOD(Ice_Db_Driver_Mongo, find);
PHP_METHOD(Ice_Db_Driver_Mongo, select);
PHP_METHOD(Ice_Db_Driver_Mongo, insert);
PHP_METHOD(Ice_Db_Driver_Mongo, update);
PHP_METHOD(Ice_Db_Driver_Mongo, remove);
PHP_METHOD(Ice_Db_Driver_Mongo, getError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, dbname)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongo_getidvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongo_getdatetime, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongo_findone, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongo_find, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongo_select, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongo_insert, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongo_update, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_mongo_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_db_driver_mongo_method_entry) {
	PHP_ME(Ice_Db_Driver_Mongo, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, getClient, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, getLastInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, __construct, arginfo_ice_db_driver_mongo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Db_Driver_Mongo, getIdValue, arginfo_ice_db_driver_mongo_getidvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, getDateTime, arginfo_ice_db_driver_mongo_getdatetime, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, findOne, arginfo_ice_db_driver_mongo_findone, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, find, arginfo_ice_db_driver_mongo_find, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, select, arginfo_ice_db_driver_mongo_select, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, insert, arginfo_ice_db_driver_mongo_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, update, arginfo_ice_db_driver_mongo_update, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, remove, arginfo_ice_db_driver_mongo_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Mongo, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
