
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"


/**
 * Get version of the framework.
 *
 * @package     Ice/Version
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Version) {

	ZEPHIR_REGISTER_CLASS(Ice, Version, ice, version, ice_version_method_entry, 0);

	zend_declare_class_constant_long(ice_version_ce, SL("DEV"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("ALPHA"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("BETA"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("RC"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(ice_version_ce, SL("STABLE"), 4 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Get array version of the framework.
 *
 * @return array
 */
PHP_METHOD(Ice_Version, current) {


	array_init_size(return_value, 7);
	add_assoc_long_ex(return_value, SS("major"), 1);
	add_assoc_long_ex(return_value, SS("minor"), 0);
	add_assoc_long_ex(return_value, SS("patch"), 6);
	add_assoc_long_ex(return_value, SS("stage"), 4);
	add_assoc_long_ex(return_value, SS("build"), 1);
	return;

}

/**
 * Get version of the framework.
 * 
 * 1.0.0-dev
 * 1.0.0-alpha3
 * 1.0.0-beta2
 * 1.0.0-rc5
 * 1.0.0
 *
 * @return string
 */
PHP_METHOD(Ice_Version, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *current = NULL, *suffix = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_SELF(&current, "current", NULL);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, current, SL("stage"), PH_NOISY | PH_READONLY, "ice/version.zep", 56 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_0, 0)) {
			ZEPHIR_INIT_VAR(suffix);
			ZVAL_STRING(suffix, "-dev", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 1)) {
			zephir_array_fetch_string(&_1, current, SL("build"), PH_NOISY | PH_READONLY, "ice/version.zep", 61 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(suffix);
			ZEPHIR_CONCAT_SV(suffix, "-alpha", _1);
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 2)) {
			zephir_array_fetch_string(&_1, current, SL("build"), PH_NOISY | PH_READONLY, "ice/version.zep", 64 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(suffix);
			ZEPHIR_CONCAT_SV(suffix, "-beta", _1);
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 3)) {
			zephir_array_fetch_string(&_1, current, SL("build"), PH_NOISY | PH_READONLY, "ice/version.zep", 67 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(suffix);
			ZEPHIR_CONCAT_SV(suffix, "-RC", _1);
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 4)) {
			ZEPHIR_INIT_NVAR(suffix);
			ZVAL_STRING(suffix, "", 1);
			break;
		}
	} while(0);

	zephir_array_fetch_string(&_1, current, SL("major"), PH_NOISY | PH_READONLY, "ice/version.zep", 74 TSRMLS_CC);
	zephir_array_fetch_string(&_2, current, SL("minor"), PH_NOISY | PH_READONLY, "ice/version.zep", 74 TSRMLS_CC);
	zephir_array_fetch_string(&_3, current, SL("patch"), PH_NOISY | PH_READONLY, "ice/version.zep", 74 TSRMLS_CC);
	ZEPHIR_CONCAT_VSVSVV(return_value, _1, ".", _2, ".", _3, suffix);
	RETURN_MM();

}

/**
 * Get version id of the framework.
 * [major][minor(2 digits)][patch (2 digits)][stage][build], eg. id for 1.4.2-rc5 is 1040235
 *
 * @return string
 */
PHP_METHOD(Ice_Version, id) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *current = NULL, *_0, *_1, _2 = zval_used_for_init, *_3 = NULL, *_5, *_6 = NULL, *_7, *_8;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_SELF(&current, "current", NULL);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, current, SL("major"), PH_NOISY | PH_READONLY, "ice/version.zep", 89 TSRMLS_CC);
	zephir_array_fetch_string(&_1, current, SL("minor"), PH_NOISY | PH_READONLY, "ice/version.zep", 89 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "%02s", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", &_4, &_2, _1);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, current, SL("patch"), PH_NOISY | PH_READONLY, "ice/version.zep", 89 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_STRING(&_2, "%02s", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_4, &_2, _5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_7, current, SL("stage"), PH_NOISY | PH_READONLY, "ice/version.zep", 89 TSRMLS_CC);
	zephir_array_fetch_string(&_8, current, SL("build"), PH_NOISY | PH_READONLY, "ice/version.zep", 89 TSRMLS_CC);
	ZEPHIR_CONCAT_VVVVV(return_value, _0, _3, _6, _7, _8);
	RETURN_MM();

}

