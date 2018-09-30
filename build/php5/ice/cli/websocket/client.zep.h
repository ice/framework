
extern zend_class_entry *ice_cli_websocket_client_ce;

ZEPHIR_INIT_CLASS(Ice_Cli_Websocket_Client);

PHP_METHOD(Ice_Cli_Websocket_Client, connect);
PHP_METHOD(Ice_Cli_Websocket_Client, generateKey);
PHP_METHOD(Ice_Cli_Websocket_Client, normalizeHeaders);
PHP_METHOD(Ice_Cli_Websocket_Client, send);
PHP_METHOD(Ice_Cli_Websocket_Client, run);
PHP_METHOD(Ice_Cli_Websocket_Client, onMessage);
PHP_METHOD(Ice_Cli_Websocket_Client, onTick);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_client_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, address)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_client_normalizeheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_client_send, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, opcode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_client_onmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_client_ontick, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_cli_websocket_client_method_entry) {
	PHP_ME(Ice_Cli_Websocket_Client, connect, arginfo_ice_cli_websocket_client_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Client, generateKey, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Cli_Websocket_Client, normalizeHeaders, arginfo_ice_cli_websocket_client_normalizeheaders, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Cli_Websocket_Client, send, arginfo_ice_cli_websocket_client_send, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Client, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Client, onMessage, arginfo_ice_cli_websocket_client_onmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Client, onTick, arginfo_ice_cli_websocket_client_ontick, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
