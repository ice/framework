
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Ice_Di_DiInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Di, DiInterface, ice, di_diinterface, ice_di_diinterface_method_entry);

	zend_class_implements(ice_di_diinterface_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Return the last DI created
 *
 * @return DiInterface
 */
ZEPHIR_DOC_METHOD(Ice_Di_DiInterface, fetch);

