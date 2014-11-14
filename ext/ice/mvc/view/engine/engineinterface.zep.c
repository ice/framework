
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_EngineInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Mvc\\View\\Engine, EngineInterface, ice, mvc_view_engine_engineinterface, ice_mvc_view_engine_engineinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Ice_Mvc_View_Engine_EngineInterface, __construct);

ZEPHIR_DOC_METHOD(Ice_Mvc_View_Engine_EngineInterface, render);

