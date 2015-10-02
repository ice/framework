
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/**
 * This class allows to access services in the services container by just only accessing a public property with the same
 * name of a registered service.
 *
 * @package     Ice/Di
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Di_Access) {

	ZEPHIR_REGISTER_CLASS(Ice\\Di, Access, ice, di_access, ice_di_access_method_entry, 0);

	zend_declare_property_null(ice_di_access_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Access constructor. Fetch di if not specified.
 *
 * @param Di di
 */
PHP_METHOD(Ice_Di_Access, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *di = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &di);

	if (!di) {
		di = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_true(di))) {
		ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 8);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("di"), _0 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic get to easy retrieve service from the di.
 */
PHP_METHOD(Ice_Di_Access, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *di = NULL, *service = NULL, *_0, *_1 = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	zephir_get_strval(property, property_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(di, _0);
	if (ZEPHIR_IS_STRING(property, "di")) {
		zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
		RETURN_CCTOR(di);
	}
	ZEPHIR_CALL_METHOD(&_1, di, "has", NULL, 0, property);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_CALL_METHOD(&service, di, "get", NULL, 0, property);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, property, service TSRMLS_CC);
		RETURN_CCTOR(service);
	}
	ZEPHIR_MM_RESTORE();

}

