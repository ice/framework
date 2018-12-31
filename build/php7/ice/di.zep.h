
extern zend_class_entry *ice_di_ce;

ZEPHIR_INIT_CLASS(Ice_Di);

PHP_METHOD(Ice_Di, setDefaults);
PHP_METHOD(Ice_Di, __construct);
PHP_METHOD(Ice_Di, fetch);
PHP_METHOD(Ice_Di, get);
PHP_METHOD(Ice_Di, set);
PHP_METHOD(Ice_Di, getDefaults);
PHP_METHOD(Ice_Di, resolve);
PHP_METHOD(Ice_Di, build);
PHP_METHOD(Ice_Di, getParameters);
PHP_METHOD(Ice_Di, getDependencies);
PHP_METHOD(Ice_Di, resolveNonClass);
PHP_METHOD(Ice_Di, errors);
PHP_METHOD(Ice_Di, hook);
PHP_METHOD(Ice_Di, applyHook);
PHP_METHOD(Ice_Di, getHooks);
PHP_METHOD(Ice_Di, clearHooks);
PHP_METHOD(Ice_Di, __call);
zend_object *zephir_init_properties_Ice_Di(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_setdefaults, 0, 0, 1)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_di_fetch, 0, 0, Ice\\Di, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_di_fetch, 0, 0, IS_OBJECT, "Ice\\Di", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_resolve, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_build, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_getparameters, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, dependencies, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_getdependencies, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
	ZEND_ARG_ARRAY_INFO(0, primitives, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_resolvenonclass, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, parameter, ReflectionParameter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_errors, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_hook, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, context)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_applyhook, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, args, 1)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_di_gethooks, 0, 0, IS_ARRAY, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_di_gethooks, 0, 0, IS_ARRAY, NULL, 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_clearhooks, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di___call, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_di_method_entry) {
	PHP_ME(Ice_Di, setDefaults, arginfo_ice_di_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, __construct, arginfo_ice_di___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Di, fetch, arginfo_ice_di_fetch, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Di, get, arginfo_ice_di_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, set, arginfo_ice_di_set, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, getDefaults, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, resolve, arginfo_ice_di_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, build, arginfo_ice_di_build, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, getParameters, arginfo_ice_di_getparameters, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Di, getDependencies, arginfo_ice_di_getdependencies, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, resolveNonClass, arginfo_ice_di_resolvenonclass, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, errors, arginfo_ice_di_errors, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, hook, arginfo_ice_di_hook, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, applyHook, arginfo_ice_di_applyhook, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, getHooks, arginfo_ice_di_gethooks, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, clearHooks, arginfo_ice_di_clearhooks, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di, __call, arginfo_ice_di___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
