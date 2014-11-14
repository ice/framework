
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Ice_Db_DbInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Db, DbInterface, ice, db_dbinterface, ice_db_dbinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Ice_Db_DbInterface, findOne);

ZEPHIR_DOC_METHOD(Ice_Db_DbInterface, find);

ZEPHIR_DOC_METHOD(Ice_Db_DbInterface, select);

ZEPHIR_DOC_METHOD(Ice_Db_DbInterface, insert);

ZEPHIR_DOC_METHOD(Ice_Db_DbInterface, update);

