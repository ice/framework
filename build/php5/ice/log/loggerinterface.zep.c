
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Describes a logger instance
 *
 * The message MUST be a string or object implementing __toString().
 *
 * The message MAY contain placeholders in the form: {foo} where foo
 * will be replaced by the context data in key "foo".
 *
 * The context array can contain arbitrary data, the only assumption that
 * can be made by implementors is that if an Exception instance is given
 * to produce a stack trace, it MUST be in a key named "exception".
 *
 * See https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-3-logger-interface.md
 * for the full interface specification.
 *
 * @package     Ice/Log
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Log_LoggerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Log, LoggerInterface, ice, log_loggerinterface, ice_log_loggerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Ice_Log_LoggerInterface, emergency);

ZEPHIR_DOC_METHOD(Ice_Log_LoggerInterface, alert);

ZEPHIR_DOC_METHOD(Ice_Log_LoggerInterface, critical);

ZEPHIR_DOC_METHOD(Ice_Log_LoggerInterface, error);

ZEPHIR_DOC_METHOD(Ice_Log_LoggerInterface, warning);

ZEPHIR_DOC_METHOD(Ice_Log_LoggerInterface, notice);

ZEPHIR_DOC_METHOD(Ice_Log_LoggerInterface, info);

ZEPHIR_DOC_METHOD(Ice_Log_LoggerInterface, debug);

ZEPHIR_DOC_METHOD(Ice_Log_LoggerInterface, log);

