
extern zend_class_entry *ice_image_gd_ce;

ZEPHIR_INIT_CLASS(Ice_Image_Gd);

PHP_METHOD(Ice_Image_Gd, __construct);
PHP_METHOD(Ice_Image_Gd, check);
PHP_METHOD(Ice_Image_Gd, __destruct);
PHP_METHOD(Ice_Image_Gd, loadImage);
PHP_METHOD(Ice_Image_Gd, doResize);
PHP_METHOD(Ice_Image_Gd, doCrop);
PHP_METHOD(Ice_Image_Gd, doRotate);
PHP_METHOD(Ice_Image_Gd, doFlip);
PHP_METHOD(Ice_Image_Gd, doSharpen);
PHP_METHOD(Ice_Image_Gd, doReflection);
PHP_METHOD(Ice_Image_Gd, doWatermark);
PHP_METHOD(Ice_Image_Gd, doBackground);
PHP_METHOD(Ice_Image_Gd, doSave);
PHP_METHOD(Ice_Image_Gd, doRender);
PHP_METHOD(Ice_Image_Gd, saveFunction);
PHP_METHOD(Ice_Image_Gd, create);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_image_gd___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_image_gd___destruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_loadimage, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_doresize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_docrop, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_dorotate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_doflip, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_dosharpen, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_doreflection, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fadeIn, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_dowatermark, 0, 4, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, watermark, Ice\\Image, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_dobackground, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_dosave, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_dorender, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_gd_savefunction, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, extension, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_image_gd_create, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_image_gd_method_entry) {
	PHP_ME(Ice_Image_Gd, __construct, arginfo_ice_image_gd___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Image_Gd, check, arginfo_ice_image_gd_check, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Image_Gd, __destruct, arginfo_ice_image_gd___destruct, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#else
	PHP_ME(Ice_Image_Gd, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#endif
	PHP_ME(Ice_Image_Gd, loadImage, arginfo_ice_image_gd_loadimage, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, doResize, arginfo_ice_image_gd_doresize, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, doCrop, arginfo_ice_image_gd_docrop, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, doRotate, arginfo_ice_image_gd_dorotate, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, doFlip, arginfo_ice_image_gd_doflip, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, doSharpen, arginfo_ice_image_gd_dosharpen, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, doReflection, arginfo_ice_image_gd_doreflection, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, doWatermark, arginfo_ice_image_gd_dowatermark, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, doBackground, arginfo_ice_image_gd_dobackground, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, doSave, arginfo_ice_image_gd_dosave, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, doRender, arginfo_ice_image_gd_dorender, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, saveFunction, arginfo_ice_image_gd_savefunction, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image_Gd, create, arginfo_ice_image_gd_create, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
