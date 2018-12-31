
extern zend_class_entry *ice_cli_websocket_client_ce;

ZEPHIR_INIT_CLASS(Ice_Cli_Websocket_Client);

PHP_METHOD(Ice_Cli_Websocket_Client, connect);
PHP_METHOD(Ice_Cli_Websocket_Client, generateKey);
PHP_METHOD(Ice_Cli_Websocket_Client, normalizeHeaders);
PHP_METHOD(Ice_Cli_Websocket_Client, send);
PHP_METHOD(Ice_Cli_Websocket_Client, run);
PHP_METHOD(Ice_Cli_Websocket_Client, onMessage);
PHP_METHOD(Ice_Cli_Websocket_Client, onTick);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_cli_websocket_client_connect, 0, 0, Ice\\Cli\\Websocket\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_client_connect, 0, 0, IS_OBJECT, "Ice\\Cli\\Websocket\\self", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, address, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, address)
#endif
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_client_generatekey, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_client_generatekey, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_client_normalizeheaders, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_client_normalizeheaders, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_client_send, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_client_send, 0, 1, _IS_BOOL, NULL, 0)
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
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_cli_websocket_client_onmessage, 0, 1, Ice\\Cli\\Websocket\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_client_onmessage, 0, 1, IS_OBJECT, "Ice\\Cli\\Websocket\\self", 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_cli_websocket_client_ontick, 0, 1, Ice\\Cli\\Websocket\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_client_ontick, 0, 1, IS_OBJECT, "Ice\\Cli\\Websocket\\self", 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_cli_websocket_client_method_entry) {
	PHP_ME(Ice_Cli_Websocket_Client, connect, arginfo_ice_cli_websocket_client_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Client, generateKey, arginfo_ice_cli_websocket_client_generatekey, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Cli_Websocket_Client, normalizeHeaders, arginfo_ice_cli_websocket_client_normalizeheaders, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Cli_Websocket_Client, send, arginfo_ice_cli_websocket_client_send, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Client, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Client, onMessage, arginfo_ice_cli_websocket_client_onmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Client, onTick, arginfo_ice_cli_websocket_client_ontick, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
