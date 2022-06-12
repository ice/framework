
extern zend_class_entry *ice_db_driver_pdo_ce;

ZEPHIR_INIT_CLASS(Ice_Db_Driver_Pdo);

PHP_METHOD(Ice_Db_Driver_Pdo, getId);
PHP_METHOD(Ice_Db_Driver_Pdo, getType);
PHP_METHOD(Ice_Db_Driver_Pdo, getClient);
PHP_METHOD(Ice_Db_Driver_Pdo, getDriverName);
PHP_METHOD(Ice_Db_Driver_Pdo, __construct);
PHP_METHOD(Ice_Db_Driver_Pdo, getIdValue);
PHP_METHOD(Ice_Db_Driver_Pdo, getDateTime);
PHP_METHOD(Ice_Db_Driver_Pdo, findOne);
PHP_METHOD(Ice_Db_Driver_Pdo, find);
PHP_METHOD(Ice_Db_Driver_Pdo, count);
PHP_METHOD(Ice_Db_Driver_Pdo, where);
PHP_METHOD(Ice_Db_Driver_Pdo, select);
PHP_METHOD(Ice_Db_Driver_Pdo, insert);
PHP_METHOD(Ice_Db_Driver_Pdo, update);
PHP_METHOD(Ice_Db_Driver_Pdo, delete);
PHP_METHOD(Ice_Db_Driver_Pdo, query);
PHP_METHOD(Ice_Db_Driver_Pdo, getLastInsertId);
PHP_METHOD(Ice_Db_Driver_Pdo, getError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_getid, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_gettype, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_getclient, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_getdrivername, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, dsn, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, user, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, password, IS_STRING, 1)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_db_driver_pdo_getidvalue, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_getdatetime, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_findone, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
	ZEND_ARG_INFO(0, filters)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fields, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_find, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
	ZEND_ARG_INFO(0, filters)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fields, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_db_driver_pdo_count, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_db_driver_pdo_where, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, filters)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, values, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, values, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_select, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
	ZEND_ARG_INFO(0, filters)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fields, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_insert, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fields, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_update, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
	ZEND_ARG_INFO(0, filters)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fields, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_delete, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_query, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, sql, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, values, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, values, 0)
#endif
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_db_driver_pdo_getlastinsertid, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_geterror, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_db_driver_pdo_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Db_Driver_Pdo, getId, arginfo_ice_db_driver_pdo_getid, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Db_Driver_Pdo, getId, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Db_Driver_Pdo, getType, arginfo_ice_db_driver_pdo_gettype, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Db_Driver_Pdo, getType, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Db_Driver_Pdo, getClient, arginfo_ice_db_driver_pdo_getclient, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Db_Driver_Pdo, getClient, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Db_Driver_Pdo, getDriverName, arginfo_ice_db_driver_pdo_getdrivername, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Db_Driver_Pdo, getDriverName, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Db_Driver_Pdo, __construct, arginfo_ice_db_driver_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Db_Driver_Pdo, getIdValue, arginfo_ice_db_driver_pdo_getidvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, getDateTime, arginfo_ice_db_driver_pdo_getdatetime, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, findOne, arginfo_ice_db_driver_pdo_findone, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, find, arginfo_ice_db_driver_pdo_find, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, count, arginfo_ice_db_driver_pdo_count, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, where, arginfo_ice_db_driver_pdo_where, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Db_Driver_Pdo, select, arginfo_ice_db_driver_pdo_select, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, insert, arginfo_ice_db_driver_pdo_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, update, arginfo_ice_db_driver_pdo_update, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, delete, arginfo_ice_db_driver_pdo_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, query, arginfo_ice_db_driver_pdo_query, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, getLastInsertId, arginfo_ice_db_driver_pdo_getlastinsertid, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Db_Driver_Pdo, getError, arginfo_ice_db_driver_pdo_geterror, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Db_Driver_Pdo, getError, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
