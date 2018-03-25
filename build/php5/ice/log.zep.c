
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


/**
 * PSR-3 logger class.
 *
 * @package     Ice/Log
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Log) {

	ZEPHIR_REGISTER_CLASS(Ice, Log, ice, log, NULL, 0);

	zend_declare_class_constant_string(ice_log_ce, SL("EMERGENCY"), "emergency" TSRMLS_CC);

	zend_declare_class_constant_string(ice_log_ce, SL("ALERT"), "alert" TSRMLS_CC);

	zend_declare_class_constant_string(ice_log_ce, SL("CRITICAL"), "critical" TSRMLS_CC);

	zend_declare_class_constant_string(ice_log_ce, SL("ERROR"), "error" TSRMLS_CC);

	zend_declare_class_constant_string(ice_log_ce, SL("WARNING"), "warning" TSRMLS_CC);

	zend_declare_class_constant_string(ice_log_ce, SL("NOTICE"), "notice" TSRMLS_CC);

	zend_declare_class_constant_string(ice_log_ce, SL("INFO"), "info" TSRMLS_CC);

	zend_declare_class_constant_string(ice_log_ce, SL("DEBUG"), "debug" TSRMLS_CC);

	return SUCCESS;

}

