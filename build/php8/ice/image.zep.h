
extern zend_class_entry *ice_image_ce;

ZEPHIR_INIT_CLASS(Ice_Image);

PHP_METHOD(Ice_Image, getFile);
PHP_METHOD(Ice_Image, getWidth);
PHP_METHOD(Ice_Image, getHeight);
PHP_METHOD(Ice_Image, getType);
PHP_METHOD(Ice_Image, getMime);
PHP_METHOD(Ice_Image, factory);
PHP_METHOD(Ice_Image, __construct);
PHP_METHOD(Ice_Image, __toString);
PHP_METHOD(Ice_Image, resize);
PHP_METHOD(Ice_Image, crop);
PHP_METHOD(Ice_Image, rotate);
PHP_METHOD(Ice_Image, flip);
PHP_METHOD(Ice_Image, sharpen);
PHP_METHOD(Ice_Image, reflection);
PHP_METHOD(Ice_Image, watermark);
PHP_METHOD(Ice_Image, background);
PHP_METHOD(Ice_Image, save);
PHP_METHOD(Ice_Image, render);
PHP_METHOD(Ice_Image, doResize);
PHP_METHOD(Ice_Image, doCrop);
PHP_METHOD(Ice_Image, doRotate);
PHP_METHOD(Ice_Image, doFlip);
PHP_METHOD(Ice_Image, doSharpen);
PHP_METHOD(Ice_Image, doReflection);
PHP_METHOD(Ice_Image, doWatermark);
PHP_METHOD(Ice_Image, doBackground);
PHP_METHOD(Ice_Image, doSave);
PHP_METHOD(Ice_Image, doRender);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_image_getfile, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_image_getwidth, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_image_getheight, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_image_gettype, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_image_getmime, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_image_factory, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, driver, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_image___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_image_resize, 0, 0, Ice\\Image, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, master, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_image_crop, 0, 2, Ice\\Image, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_image_rotate, 0, 1, Ice\\Image, 0)
	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_image_flip, 0, 1, Ice\\Image, 0)
	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_image_sharpen, 0, 1, Ice\\Image, 0)
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_image_reflection, 0, 0, Ice\\Image, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fadeIn, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_image_watermark, 0, 1, Ice\\Image, 0)
	ZEND_ARG_OBJ_INFO(0, watermark, Ice\\Image, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_image_background, 0, 1, Ice\\Image, 0)
	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_save, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_render, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_doresize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_docrop, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset_x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset_y, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_dorotate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_doflip, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_dosharpen, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_doreflection, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fadeIn, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_dowatermark, 0, 4, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, image, Ice\\Image, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_dobackground, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_dosave, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_image_dorender, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_image_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Image, getFile, arginfo_ice_image_getfile, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Image, getFile, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Image, getWidth, arginfo_ice_image_getwidth, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Image, getWidth, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Image, getHeight, arginfo_ice_image_getheight, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Image, getHeight, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Image, getType, arginfo_ice_image_gettype, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Image, getType, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Image, getMime, arginfo_ice_image_getmime, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Image, getMime, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Image, factory, arginfo_ice_image_factory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Image, __construct, arginfo_ice_image___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Image, __toString, arginfo_ice_image___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Image, resize, arginfo_ice_image_resize, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Image, crop, arginfo_ice_image_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Image, rotate, arginfo_ice_image_rotate, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Image, flip, arginfo_ice_image_flip, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Image, sharpen, arginfo_ice_image_sharpen, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Image, reflection, arginfo_ice_image_reflection, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Image, watermark, arginfo_ice_image_watermark, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Image, background, arginfo_ice_image_background, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Image, save, arginfo_ice_image_save, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Image, render, arginfo_ice_image_render, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Image, doResize, arginfo_ice_image_doresize, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image, doCrop, arginfo_ice_image_docrop, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image, doRotate, arginfo_ice_image_dorotate, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image, doFlip, arginfo_ice_image_doflip, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image, doSharpen, arginfo_ice_image_dosharpen, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image, doReflection, arginfo_ice_image_doreflection, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image, doWatermark, arginfo_ice_image_dowatermark, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image, doBackground, arginfo_ice_image_dobackground, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image, doSave, arginfo_ice_image_dosave, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Image, doRender, arginfo_ice_image_dorender, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
