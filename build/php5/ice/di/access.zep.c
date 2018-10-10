
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * This class allows to access services in the services container by just only accessing a public property with the same
 * name of a registered service.
 *
 * @package     Ice/Di
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Di_Access) {

	ZEPHIR_REGISTER_CLASS(Ice\\Di, Access, ice, di_access, ice_di_access_method_entry, 0);

	zend_declare_property_null(ice_di_access_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Magic get to easy retrieve service from the di.
 */
PHP_METHOD(Ice_Di_Access, __get) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *property_param = NULL, *di = NULL, *service = NULL, *_0, *_2, *_5, *_3$$3 = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	zephir_get_strval(property, property_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("di"), PH_NOISY_CC);
	_1 = Z_TYPE_P(_0) != IS_OBJECT;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property_this(&_2, this_ptr, SL("di"), PH_NOISY_CC);
		_1 = !(zephir_instance_of_ev(_2, ice_di_ce TSRMLS_CC));
	}
	if (_1) {
		ZEPHIR_CALL_CE_STATIC(&_3$$3, ice_di_ce, "fetch", &_4, 1);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("di"), _3$$3 TSRMLS_CC);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(di, _5);
	if (ZEPHIR_IS_STRING(property, "di")) {
		RETURN_CCTOR(di);
	}
	ZEPHIR_CALL_METHOD(&service, di, "get", NULL, 0, property);
	zephir_check_call_status();
	zephir_update_property_zval_zval(getThis(), property, service TSRMLS_CC);
	RETURN_CCTOR(service);

}

PHP_METHOD(Ice_Di_Access, __set) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *property_param = NULL, *value, *_0, *_2, *_5, *_3$$3 = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	zephir_get_strval(property, property_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("di"), PH_NOISY_CC);
	_1 = Z_TYPE_P(_0) != IS_OBJECT;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property_this(&_2, this_ptr, SL("di"), PH_NOISY_CC);
		_1 = !(zephir_instance_of_ev(_2, ice_di_ce TSRMLS_CC));
	}
	if (_1) {
		ZEPHIR_CALL_CE_STATIC(&_3$$3, ice_di_ce, "fetch", &_4, 1);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("di"), _3$$3 TSRMLS_CC);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_5, "set", NULL, 0, property, value);
	zephir_check_call_status();
	RETURN_MM();

}

