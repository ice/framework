
extern zend_class_entry *ice_cli_websocket_websocket_ce;

ZEPHIR_INIT_CLASS(Ice_Cli_Websocket_Websocket);

PHP_METHOD(Ice_Cli_Websocket_Websocket, sendClear);
PHP_METHOD(Ice_Cli_Websocket_Websocket, sendData);
PHP_METHOD(Ice_Cli_Websocket_Websocket, receiveClear);
PHP_METHOD(Ice_Cli_Websocket_Websocket, receive);
PHP_METHOD(Ice_Cli_Websocket_Websocket, encode);
PHP_METHOD(Ice_Cli_Websocket_Websocket, setParams);
PHP_METHOD(Ice_Cli_Websocket_Websocket, getParams);
PHP_METHOD(Ice_Cli_Websocket_Websocket, getParam);
PHP_METHOD(Ice_Cli_Websocket_Websocket, console);
PHP_METHOD(Ice_Cli_Websocket_Websocket, getUptime);
PHP_METHOD(Ice_Cli_Websocket_Websocket, getMemoryUsage);
void zephir_init_static_properties_Ice_Cli_Websocket_Websocket(TSRMLS_D);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_websocket_sendclear, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_websocket_sendclear, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, socket)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, data)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_websocket_senddata, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_websocket_senddata, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, socket)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, data)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, opcode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, opcode)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, masked, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, masked)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_websocket_receiveclear, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_websocket_receiveclear, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, socket)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_receive, 0, 0, 1)
	ZEND_ARG_INFO(0, socket)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_websocket_encode, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_websocket_encode, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, data)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, opcode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, opcode)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, masked, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, masked)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fin, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, fin)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_cli_websocket_websocket_setparams, 0, 1, Ice\\Cli\\Websocket\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_websocket_setparams, 0, 1, IS_OBJECT, "Ice\\Cli\\Websocket\\self", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_websocket_getparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_websocket_getparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_getparam, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_console, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, color)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, decoration, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, decoration)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, bgColor, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, bgColor)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, exit, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, exit)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_getuptime, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, human, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, human)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_getmemoryusage, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, human, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, human)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_cli_websocket_websocket_method_entry) {
	PHP_ME(Ice_Cli_Websocket_Websocket, sendClear, arginfo_ice_cli_websocket_websocket_sendclear, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, sendData, arginfo_ice_cli_websocket_websocket_senddata, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, receiveClear, arginfo_ice_cli_websocket_websocket_receiveclear, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, receive, arginfo_ice_cli_websocket_websocket_receive, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, encode, arginfo_ice_cli_websocket_websocket_encode, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Cli_Websocket_Websocket, setParams, arginfo_ice_cli_websocket_websocket_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, getParams, arginfo_ice_cli_websocket_websocket_getparams, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, getParam, arginfo_ice_cli_websocket_websocket_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, console, arginfo_ice_cli_websocket_websocket_console, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, getUptime, arginfo_ice_cli_websocket_websocket_getuptime, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, getMemoryUsage, arginfo_ice_cli_websocket_websocket_getmemoryusage, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
