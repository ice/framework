
extern zend_class_entry *ice_dispatcher_ce;

ZEPHIR_INIT_CLASS(Ice_Dispatcher);

PHP_METHOD(Ice_Dispatcher, getDefaultNamespace);
PHP_METHOD(Ice_Dispatcher, setDefaultNamespace);
PHP_METHOD(Ice_Dispatcher, getActiveHandler);
PHP_METHOD(Ice_Dispatcher, getLastHandler);
PHP_METHOD(Ice_Dispatcher, getLoops);
PHP_METHOD(Ice_Dispatcher, setLoops);
PHP_METHOD(Ice_Dispatcher, getFinished);
PHP_METHOD(Ice_Dispatcher, getForwards);
PHP_METHOD(Ice_Dispatcher, getForwarded);
PHP_METHOD(Ice_Dispatcher, setSilent);
PHP_METHOD(Ice_Dispatcher, getModules);
PHP_METHOD(Ice_Dispatcher, setModules);
PHP_METHOD(Ice_Dispatcher, getModule);
PHP_METHOD(Ice_Dispatcher, setModule);
PHP_METHOD(Ice_Dispatcher, getNamespace);
PHP_METHOD(Ice_Dispatcher, setNamespace);
PHP_METHOD(Ice_Dispatcher, getHandler);
PHP_METHOD(Ice_Dispatcher, setHandler);
PHP_METHOD(Ice_Dispatcher, getAction);
PHP_METHOD(Ice_Dispatcher, setAction);
PHP_METHOD(Ice_Dispatcher, getParams);
PHP_METHOD(Ice_Dispatcher, setParams);
PHP_METHOD(Ice_Dispatcher, getReturnedValue);
PHP_METHOD(Ice_Dispatcher, setReturnedValue);
PHP_METHOD(Ice_Dispatcher, getHandlers);
PHP_METHOD(Ice_Dispatcher, setHandlers);
PHP_METHOD(Ice_Dispatcher, getHandlerSuffix);
PHP_METHOD(Ice_Dispatcher, setHandlerSuffix);
PHP_METHOD(Ice_Dispatcher, getActionSuffix);
PHP_METHOD(Ice_Dispatcher, setActionSuffix);
PHP_METHOD(Ice_Dispatcher, __construct);
PHP_METHOD(Ice_Dispatcher, hasParam);
PHP_METHOD(Ice_Dispatcher, setParam);
PHP_METHOD(Ice_Dispatcher, getParam);
PHP_METHOD(Ice_Dispatcher, getActiveMethod);
PHP_METHOD(Ice_Dispatcher, addModule);
PHP_METHOD(Ice_Dispatcher, dispatch);
PHP_METHOD(Ice_Dispatcher, forward);
PHP_METHOD(Ice_Dispatcher, reset);
zend_object_value zephir_init_properties_Ice_Dispatcher(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultNamespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_setloops, 0, 0, 1)
	ZEND_ARG_INFO(0, loops)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_setsilent, 0, 0, 1)
	ZEND_ARG_INFO(0, silent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_setmodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_setmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_setnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_sethandler, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_setaction, 0, 0, 1)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_setreturnedvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, returnedValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_sethandlers, 0, 0, 1)
	ZEND_ARG_INFO(0, handlers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_sethandlersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, handlerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_hasparam, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_getparam, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, allowEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_addmodule, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dispatcher_forward, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, forward, 0)
	ZEND_ARG_INFO(0, force)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_dispatcher_method_entry) {
	PHP_ME(Ice_Dispatcher, getDefaultNamespace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setDefaultNamespace, arginfo_ice_dispatcher_setdefaultnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getActiveHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getLastHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getLoops, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setLoops, arginfo_ice_dispatcher_setloops, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getFinished, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getForwards, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getForwarded, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setSilent, arginfo_ice_dispatcher_setsilent, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setModules, arginfo_ice_dispatcher_setmodules, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setModule, arginfo_ice_dispatcher_setmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getNamespace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setNamespace, arginfo_ice_dispatcher_setnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setHandler, arginfo_ice_dispatcher_sethandler, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setAction, arginfo_ice_dispatcher_setaction, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setParams, arginfo_ice_dispatcher_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getReturnedValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setReturnedValue, arginfo_ice_dispatcher_setreturnedvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getHandlers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setHandlers, arginfo_ice_dispatcher_sethandlers, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getHandlerSuffix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setHandlerSuffix, arginfo_ice_dispatcher_sethandlersuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getActionSuffix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setActionSuffix, arginfo_ice_dispatcher_setactionsuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Dispatcher, hasParam, arginfo_ice_dispatcher_hasparam, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, setParam, arginfo_ice_dispatcher_setparam, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getParam, arginfo_ice_dispatcher_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, getActiveMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, addModule, arginfo_ice_dispatcher_addmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, forward, arginfo_ice_dispatcher_forward, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dispatcher, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
