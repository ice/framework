
extern zend_class_entry *ice_cli_websocket_server_ce;

ZEPHIR_INIT_CLASS(Ice_Cli_Websocket_Server);

PHP_METHOD(Ice_Cli_Websocket_Server, setVerbose);
PHP_METHOD(Ice_Cli_Websocket_Server, getServer);
PHP_METHOD(Ice_Cli_Websocket_Server, getClients);
PHP_METHOD(Ice_Cli_Websocket_Server, __construct);
PHP_METHOD(Ice_Cli_Websocket_Server, run);
PHP_METHOD(Ice_Cli_Websocket_Server, connect);
PHP_METHOD(Ice_Cli_Websocket_Server, disconnect);
PHP_METHOD(Ice_Cli_Websocket_Server, onValidate);
PHP_METHOD(Ice_Cli_Websocket_Server, onConnect);
PHP_METHOD(Ice_Cli_Websocket_Server, onDisconnect);
PHP_METHOD(Ice_Cli_Websocket_Server, onMessage);
PHP_METHOD(Ice_Cli_Websocket_Server, onTick);
PHP_METHOD(Ice_Cli_Websocket_Server, onBoot);
PHP_METHOD(Ice_Cli_Websocket_Server, callback);
zend_object *zephir_init_properties_Ice_Cli_Websocket_Server(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_server_setverbose, 0, 0, 1)
	ZEND_ARG_INFO(0, verbose)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_server___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, address, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, address)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_server_connect, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_server_connect, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, socket)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_server_disconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, socket)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_cli_websocket_server_onvalidate, 0, 1, Ice\\Cli\\Websocket\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_server_onvalidate, 0, 1, IS_OBJECT, "Ice\\Cli\\Websocket\\self", 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_cli_websocket_server_onconnect, 0, 1, Ice\\Cli\\Websocket\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_server_onconnect, 0, 1, IS_OBJECT, "Ice\\Cli\\Websocket\\self", 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_cli_websocket_server_ondisconnect, 0, 1, Ice\\Cli\\Websocket\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_server_ondisconnect, 0, 1, IS_OBJECT, "Ice\\Cli\\Websocket\\self", 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_cli_websocket_server_onmessage, 0, 1, Ice\\Cli\\Websocket\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_server_onmessage, 0, 1, IS_OBJECT, "Ice\\Cli\\Websocket\\self", 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_cli_websocket_server_ontick, 0, 1, Ice\\Cli\\Websocket\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_server_ontick, 0, 1, IS_OBJECT, "Ice\\Cli\\Websocket\\self", 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_cli_websocket_server_onboot, 0, 1, Ice\\Cli\\Websocket\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_server_onboot, 0, 1, IS_OBJECT, "Ice\\Cli\\Websocket\\self", 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_cli_websocket_server_callback, 0, 2, Ice\\Cli\\Websocket\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_websocket_server_callback, 0, 2, IS_OBJECT, "Ice\\Cli\\Websocket\\self", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_cli_websocket_server_method_entry) {
	PHP_ME(Ice_Cli_Websocket_Server, setVerbose, arginfo_ice_cli_websocket_server_setverbose, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Server, getServer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Server, getClients, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Server, __construct, arginfo_ice_cli_websocket_server___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Cli_Websocket_Server, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Server, connect, arginfo_ice_cli_websocket_server_connect, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Cli_Websocket_Server, disconnect, arginfo_ice_cli_websocket_server_disconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Server, onValidate, arginfo_ice_cli_websocket_server_onvalidate, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Server, onConnect, arginfo_ice_cli_websocket_server_onconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Server, onDisconnect, arginfo_ice_cli_websocket_server_ondisconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Server, onMessage, arginfo_ice_cli_websocket_server_onmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Server, onTick, arginfo_ice_cli_websocket_server_ontick, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Server, onBoot, arginfo_ice_cli_websocket_server_onboot, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Server, callback, arginfo_ice_cli_websocket_server_callback, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
