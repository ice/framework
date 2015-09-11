
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * Get version of the framework.
 *
 * @package     Ice/Version
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 * @see         http://semver.org (Semantic Versioning 2.0.0)
 */
ZEPHIR_INIT_CLASS(Ice_Version) {

	ZEPHIR_REGISTER_CLASS(Ice, Version, ice, version, ice_version_method_entry, 0);

	zend_declare_class_constant_long(ice_version_ce, SL("DEV"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("ALPHA"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("BETA"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("RC"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("STABLE"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("MAJOR"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("MINOR"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("PATCH"), 28 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("STAGE"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("BUILD"), 1 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Get version array.
 *
 * @return array
 */
PHP_METHOD(Ice_Version, current) {


	zephir_create_array(return_value, 5, 0 TSRMLS_CC);
	add_assoc_long_ex(return_value, SS("major"), 1);
	add_assoc_long_ex(return_value, SS("minor"), 0);
	add_assoc_long_ex(return_value, SS("patch"), 28);
	add_assoc_long_ex(return_value, SS("stage"), 4);
	add_assoc_long_ex(return_value, SS("build"), 1);
	return;

}

/**
 * Get version string.
 * 
 * 1.0.0-dev
 * 1.0.0-alpha.3
 * 1.0.0-beta.2
 * 1.0.0-rc.5
 * 1.0.0
 *
 * @return string
 */
PHP_METHOD(Ice_Version, get) {

	zval *_2 = NULL;
	int _0;
	zval *suffix = NULL, _1 = zval_used_for_init, _3, _4;

	ZEPHIR_MM_GROW();

	do {
		_0 = 4;
		if (_0 == 0) {
			ZEPHIR_INIT_VAR(suffix);
			ZVAL_STRING(suffix, "-dev", 1);
			break;
		}
		if (_0 == 1) {
			ZEPHIR_SINIT_VAR(_1);
			ZVAL_LONG(&_1, 1);
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_SV(_2, "-alpha.", &_1);
			ZEPHIR_CPY_WRT(suffix, _2);
			break;
		}
		if (_0 == 2) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 1);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SV(_2, "-beta.", &_1);
			ZEPHIR_CPY_WRT(suffix, _2);
			break;
		}
		if (_0 == 3) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 1);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SV(_2, "-rc.", &_1);
			ZEPHIR_CPY_WRT(suffix, _2);
			break;
		}
		if (_0 == 4) {
			ZEPHIR_INIT_NVAR(suffix);
			ZVAL_STRING(suffix, "", 1);
			break;
		}
	} while(0);

	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 28);
	ZEPHIR_CONCAT_VSVSVV(return_value, &_1, ".", &_3, ".", &_4, suffix);
	RETURN_MM();

}

/**
 * Get version id.
 *
 * [major][minor(2 digits)][patch (2 digits)][stage][build]
 * eg. id for 1.4.12-rc.5 is 1041235
 *
 * @return int
 */
PHP_METHOD(Ice_Version, id) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *id, _0, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "%02s", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", &_4, 1, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "%02s", 0);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 28);
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", &_4, 1, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 4);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_INIT_VAR(id);
	ZEPHIR_CONCAT_VVVVV(id, &_0, _3, _5, &_1, &_2);
	RETURN_MM_LONG(zephir_get_intval(id));

}

