
extern zend_class_entry *ice_di_ce;

ZEPHIR_INIT_CLASS(Ice_Di);

PHP_METHOD(Ice_Di, __construct);
PHP_METHOD(Ice_Di, fetch);
PHP_METHOD(Ice_Di, set);
PHP_METHOD(Ice_Di, resolve);
PHP_METHOD(Ice_Di, errors);
PHP_METHOD(Ice_Di, hook);
PHP_METHOD(Ice_Di, applyHook);
PHP_METHOD(Ice_Di, getHooks);
PHP_METHOD(Ice_Di, clearHooks);
PHP_METHOD(Ice_Di, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_resolve, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_errors, 0, 0, 0)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_hook, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_applyhook, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_gethooks, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_clearhooks, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_di_method_entry) {
	PHP_ME(Ice_Di, __construct, arginfo_ice_di___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Di, fetch, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Di, set, arginfo_ice_di_set, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, resolve, arginfo_ice_di_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, errors, arginfo_ice_di_errors, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, hook, arginfo_ice_di_hook, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, applyHook, arginfo_ice_di_applyhook, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, getHooks, arginfo_ice_di_gethooks, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, clearHooks, arginfo_ice_di_clearhooks, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, __call, arginfo_ice_di___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
