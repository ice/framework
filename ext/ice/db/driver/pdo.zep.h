
extern zend_class_entry *ice_db_driver_pdo_ce;

ZEPHIR_INIT_CLASS(Ice_Db_Driver_Pdo);

PHP_METHOD(Ice_Db_Driver_Pdo, getId);
PHP_METHOD(Ice_Db_Driver_Pdo, getType);
PHP_METHOD(Ice_Db_Driver_Pdo, getClient);
PHP_METHOD(Ice_Db_Driver_Pdo, __construct);
PHP_METHOD(Ice_Db_Driver_Pdo, getIdValue);
PHP_METHOD(Ice_Db_Driver_Pdo, findOne);
PHP_METHOD(Ice_Db_Driver_Pdo, find);
PHP_METHOD(Ice_Db_Driver_Pdo, where);
PHP_METHOD(Ice_Db_Driver_Pdo, select);
PHP_METHOD(Ice_Db_Driver_Pdo, insert);
PHP_METHOD(Ice_Db_Driver_Pdo, update);
PHP_METHOD(Ice_Db_Driver_Pdo, remove);
PHP_METHOD(Ice_Db_Driver_Pdo, getLastInsertId);
PHP_METHOD(Ice_Db_Driver_Pdo, getError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_getidvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_findone, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_find, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_where, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, values, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_select, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_insert, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_update, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_db_driver_pdo_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_db_driver_pdo_method_entry) {
	PHP_ME(Ice_Db_Driver_Pdo, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, getClient, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, __construct, arginfo_ice_db_driver_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Db_Driver_Pdo, getIdValue, arginfo_ice_db_driver_pdo_getidvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, findOne, arginfo_ice_db_driver_pdo_findone, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, find, arginfo_ice_db_driver_pdo_find, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, where, arginfo_ice_db_driver_pdo_where, ZEND_ACC_PRIVATE)
	PHP_ME(Ice_Db_Driver_Pdo, select, arginfo_ice_db_driver_pdo_select, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, insert, arginfo_ice_db_driver_pdo_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, update, arginfo_ice_db_driver_pdo_update, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, remove, arginfo_ice_db_driver_pdo_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, getLastInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Db_Driver_Pdo, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
