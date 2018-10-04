
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_sendclear, 0, 0, 2)
	ZEND_ARG_INFO(0, socket)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_senddata, 0, 0, 2)
	ZEND_ARG_INFO(0, socket)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, opcode)
	ZEND_ARG_INFO(0, masked)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_receiveclear, 0, 0, 1)
	ZEND_ARG_INFO(0, socket)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_receive, 0, 0, 1)
	ZEND_ARG_INFO(0, socket)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_encode, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, opcode)
	ZEND_ARG_INFO(0, masked)
	ZEND_ARG_INFO(0, fin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_setparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_console, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, decoration)
	ZEND_ARG_INFO(0, bgColor)
	ZEND_ARG_INFO(0, exit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_getuptime, 0, 0, 0)
	ZEND_ARG_INFO(0, human)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_websocket_websocket_getmemoryusage, 0, 0, 0)
	ZEND_ARG_INFO(0, human)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_cli_websocket_websocket_method_entry) {
	PHP_ME(Ice_Cli_Websocket_Websocket, sendClear, arginfo_ice_cli_websocket_websocket_sendclear, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, sendData, arginfo_ice_cli_websocket_websocket_senddata, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, receiveClear, arginfo_ice_cli_websocket_websocket_receiveclear, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, receive, arginfo_ice_cli_websocket_websocket_receive, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, encode, arginfo_ice_cli_websocket_websocket_encode, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Cli_Websocket_Websocket, setParams, arginfo_ice_cli_websocket_websocket_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, getParam, arginfo_ice_cli_websocket_websocket_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, console, arginfo_ice_cli_websocket_websocket_console, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, getUptime, arginfo_ice_cli_websocket_websocket_getuptime, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Websocket_Websocket, getMemoryUsage, arginfo_ice_cli_websocket_websocket_getmemoryusage, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
