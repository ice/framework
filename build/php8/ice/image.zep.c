
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/math.h"
#include "kernel/string.h"


/**
 * Image manipulation support.
 *
 * @package     Ice/Image
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Image) {

	ZEPHIR_REGISTER_CLASS(Ice, Image, ice, image, ice_image_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_bool(ice_image_ce, SL("checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	zend_declare_property_null(ice_image_ce, SL("file"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_image_ce, SL("width"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_image_ce, SL("height"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_image_ce, SL("type"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_image_ce, SL("mime"), ZEND_ACC_PROTECTED);

	zephir_declare_class_constant_long(ice_image_ce, SL("NONE"), 1);

	zephir_declare_class_constant_long(ice_image_ce, SL("WIDTH"), 2);

	zephir_declare_class_constant_long(ice_image_ce, SL("HEIGHT"), 3);

	zephir_declare_class_constant_long(ice_image_ce, SL("AUTO"), 4);

	zephir_declare_class_constant_long(ice_image_ce, SL("INVERSE"), 5);

	zephir_declare_class_constant_long(ice_image_ce, SL("PRECISE"), 6);

	zephir_declare_class_constant_long(ice_image_ce, SL("HORIZONTAL"), 11);

	zephir_declare_class_constant_long(ice_image_ce, SL("VERTICAL"), 12);

	return SUCCESS;

}

PHP_METHOD(Ice_Image, getFile) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "file");

}

PHP_METHOD(Ice_Image, getWidth) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "width");

}

PHP_METHOD(Ice_Image, getHeight) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "height");

}

PHP_METHOD(Ice_Image, getType) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "type");

}

PHP_METHOD(Ice_Image, getMime) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "mime");

}

/**
 * Loads an image and prepares it for manipulation.
 *
 * <pre><code>
 *  $image = new Image('upload/test.jpg');
 * </code></pre>
 *
 * @param string file Image file path
 * @param string driver Driver class name
 *
 * @throws Exception
 */
PHP_METHOD(Ice_Image, factory) {

	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *driver_param = NULL, instance, _0;
	zval file, driver;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&driver);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(driver)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &driver_param);

	zephir_get_strval(&file, file_param);
	if (!driver_param) {
		ZEPHIR_INIT_VAR(&driver);
		ZVAL_STRING(&driver, "");
	} else {
		zephir_get_strval(&driver, driver_param);
	}


	if (!(!(Z_TYPE_P(&driver) == IS_UNDEF) && Z_STRLEN_P(&driver))) {
		ZEPHIR_INIT_NVAR(&driver);
		ZVAL_STRING(&driver, "Ice\\Image\\Gd");
	}
	ZEPHIR_INIT_VAR(&instance);
	zephir_fetch_safe_class(&_0, &driver);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(&instance, _1);
	if (zephir_has_constructor(&instance)) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0, &file);
		zephir_check_call_status();
	}
	if (!(zephir_instance_of_ev(&instance, ice_image_ce))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Driver must be an Image", "ice/image.zep", 60);
		return;
	}
	RETURN_CCTOR(&instance);

}

/**
 * Loads information about the image. Will throw an exception if the image does not exist or is not an image.
 *
 * @param string file Image file path
 *
 * @return void
 * @throws Exception
 */
PHP_METHOD(Ice_Image, __construct) {

	zval _5$$5;
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval file, *file_param = NULL, info, _1, _2, _7, _8, _9, _10, _11, _0$$3, _4$$5, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_5$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(&file, file_param);



	/* try_start_1: */

		ZEPHIR_CALL_FUNCTION(&_0$$3, "realpath", NULL, 47, &file);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(&file, &_0$$3);
		ZEPHIR_CALL_FUNCTION(&info, "getimagesize", NULL, 48, &file);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		ZEPHIR_INIT_VAR(&_2);
		if (zephir_instance_of_ev(&_1, ice_exception_ce)) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&_2, &_1);
		}
	}
	_3 = ZEPHIR_IS_EMPTY(&file);
	if (!(_3)) {
		_3 = ZEPHIR_IS_EMPTY(&info);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_4$$5);
		object_init_ex(&_4$$5, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_create_array(&_5$$5, 2, 0);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "Not an image or invalid image: %s");
		zephir_array_fast_append(&_5$$5, &_6$$5);
		zephir_array_fast_append(&_5$$5, &file);
		ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", NULL, 12, &_5$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$5, "ice/image.zep", 89);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("file"), &file);
	zephir_array_fetch_long(&_7, &info, 0, PH_NOISY | PH_READONLY, "ice/image.zep", 94);
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_7);
	zephir_array_fetch_long(&_8, &info, 1, PH_NOISY | PH_READONLY, "ice/image.zep", 95);
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_8);
	zephir_array_fetch_long(&_9, &info, 2, PH_NOISY | PH_READONLY, "ice/image.zep", 96);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_9);
	zephir_read_property(&_10, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_11, "image_type_to_mime_type", NULL, 49, &_10);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_11);
	ZEPHIR_MM_RESTORE();

}

/**
 * Render the current image.
 *
 * <pre><code>
 *  echo $image;
 * </code></pre>
 *
 * @return string Binary string, it must be rendered with the appropriate Content-Type header
 */
PHP_METHOD(Ice_Image, __toString) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_0);
		ZVAL_OBJ(&_0, EG(exception));
		Z_ADDREF_P(&_0);
		ZEPHIR_INIT_VAR(&_1);
		if (zephir_instance_of_ev(&_0, ice_exception_ce)) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&_1, &_0);
		}
	}

}

/**
 * Resize the image to the given size. Either the width or the height can be omitted and the image will be resized proportionally.
 *
 * <pre><code>
 *  // Resize to 200 pixels on the shortest side
 *  $image->resize(200, 200);
 *
 *  // Resize to 200x200 pixels, keeping aspect ratio
 *  $image->resize(200, 200, Image::INVERSE);
 *
 *  // Resize to 500 pixel width, keeping aspect ratio
 *  $image->resize(500, null);
 *
 *  // Resize to 500 pixel height, keeping aspect ratio
 *  $image->resize(null, 500);
 *
 *  // Resize to 200x500 pixels, ignoring aspect ratio
 *  $image->resize(200, 500, Image::NONE);
 * </code></pre>
 *
 * @param integer width New width
 * @param integer height New height
 * @param integer master Master dimension
 *
 * @return Image
 */
PHP_METHOD(Ice_Image, resize) {

	zend_bool _0, _1;
	double ratio = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_24 = NULL;
	zval *width_param = NULL, *height_param = NULL, *master_param = NULL, tmp, _21, _22, _23, _25, _26, _27, _2$$7, _3$$10, _4$$12, _5$$12, _6$$12, _7$$13, _8$$13, _9$$13, _10$$14, _11$$14, _12$$15, _13$$15, _14$$16, _15$$16, _16$$16, _17$$17, _18$$17, _19$$18, _20$$18;
	zend_long width, height, master, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_4$$12);
	ZVAL_UNDEF(&_5$$12);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_20$$18);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(width, is_null_true)
		Z_PARAM_LONG_OR_NULL(height, is_null_true)
		Z_PARAM_LONG_OR_NULL(master, is_null_true)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &width_param, &height_param, &master_param);

	if (!width_param) {
		width = 0;
	} else {
		width = zephir_get_intval(width_param);
	}
	if (!height_param) {
		height = 0;
	} else {
		height = zephir_get_intval(height_param);
	}
	if (!master_param) {
		master = 0;
	} else {
		master = zephir_get_intval(master_param);
	}


	_0 = master == 2;
	if (_0) {
		_0 = ((width) ? 1 : 0);
	}
	_1 = master == 3;
	if (_1) {
		_1 = ((height) ? 1 : 0);
	}
	if (1 == 0) {
		master = 4;
	} else if (_0) {
		master = 4;
		height = 0;
	} else if (_1) {
		master = 4;
		width = 0;
	}
	if (!(width)) {
		if (master == 1) {
			zephir_read_property(&_2$$7, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			width = zephir_get_numberval(&_2$$7);
		} else {
			master = 3;
		}
	}
	if (!(height)) {
		if (master == 1) {
			zephir_read_property(&_3$$10, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			height = zephir_get_numberval(&_3$$10);
		} else {
			master = 2;
		}
	}
	do {
		if (master == 4) {
			ZEPHIR_INIT_VAR(&_4$$12);
			zephir_read_property(&_5$$12, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_6$$12, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			if ((zephir_safe_div_zval_long(&_5$$12, width)) > (int) (zephir_safe_div_zval_long(&_6$$12, height))) {
				ZEPHIR_INIT_NVAR(&_4$$12);
				ZVAL_LONG(&_4$$12, 2);
			} else {
				ZEPHIR_INIT_NVAR(&_4$$12);
				ZVAL_LONG(&_4$$12, 3);
			}
			master = zephir_get_numberval(&_4$$12);
			break;
		}
		if (master == 5) {
			ZEPHIR_INIT_VAR(&_7$$13);
			zephir_read_property(&_8$$13, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_9$$13, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			if ((zephir_safe_div_zval_long(&_8$$13, width)) > (int) (zephir_safe_div_zval_long(&_9$$13, height))) {
				ZEPHIR_INIT_NVAR(&_7$$13);
				ZVAL_LONG(&_7$$13, 3);
			} else {
				ZEPHIR_INIT_NVAR(&_7$$13);
				ZVAL_LONG(&_7$$13, 2);
			}
			master = zephir_get_numberval(&_7$$13);
			break;
		}
	} while(0);

	do {
		if (master == 2) {
			zephir_read_property(&_10$$14, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_11$$14, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			height = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_10$$14) * width), &_11$$14));
			break;
		}
		if (master == 3) {
			zephir_read_property(&_12$$15, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_13$$15, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			width = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_12$$15) * height), &_13$$15));
			break;
		}
		if (master == 6) {
			zephir_read_property(&_14$$16, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_15$$16, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_16$$16);
			div_function(&_16$$16, &_14$$16, &_15$$16);
			ratio = zephir_get_numberval(&_16$$16);
			if (zephir_safe_div_long_long(width, height) > ratio) {
				zephir_read_property(&_17$$17, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_18$$17, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
				height = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_17$$17) * width), &_18$$17));
			} else {
				zephir_read_property(&_19$$18, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_20$$18, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				width = (long) (zephir_safe_div_long_zval((zephir_get_numberval(&_19$$18) * height), &_20$$18));
			}
			break;
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_21);
	ZVAL_LONG(&_22, width);
	zephir_round(&_21, &_22, NULL, NULL);
	ZVAL_LONG(&_23, 1);
	ZEPHIR_CALL_FUNCTION(&tmp, "max", &_24, 50, &_21, &_23);
	zephir_check_call_status();
	width = zephir_get_intval(&tmp);
	ZEPHIR_INIT_VAR(&_25);
	ZVAL_LONG(&_23, height);
	zephir_round(&_25, &_23, NULL, NULL);
	ZVAL_LONG(&_26, 1);
	ZEPHIR_CALL_FUNCTION(&tmp, "max", &_24, 50, &_25, &_26);
	zephir_check_call_status();
	height = zephir_get_intval(&tmp);
	ZVAL_LONG(&_26, width);
	ZVAL_LONG(&_27, height);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "doresize", NULL, 0, &_26, &_27);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Crop an image to the given size. Either the width or the height can be omitted and the current width or height will be used.
 *
 * If no offset is specified, the center of the axis will be used.
 * If an offset of true is specified, the bottom of the axis will be used.
 *
 * <pre><code>
 *  // Crop the image to 200x200 pixels, from the center
 *  $image->crop(200, 200);
 * </code></pre>
 *
 * @param integer width New width
 * @param integer height New height
 * @param mixed offsetX Offset from the left
 * @param mixed offsetY Offset from the top
 *
 * @return Image
 */
PHP_METHOD(Ice_Image, crop) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, __$null, _0, _2, _14, _15, _18, _21, _1$$3, _3$$4, _4$$5, _5$$5, _6$$6, _7$$7, _9$$8, _10$$8, _11$$9, _12$$10, _16$$11, _17$$11, _19$$12, _20$$12;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS, _8$$7, _13$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(offsetX)
		Z_PARAM_ZVAL(offsetY)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &width_param, &height_param, &offsetX, &offsetY);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	if (!offsetX) {
		offsetX = &offsetX_sub;
		ZEPHIR_CPY_WRT(offsetX, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(offsetX);
	}
	if (!offsetY) {
		offsetY = &offsetY_sub;
		ZEPHIR_CPY_WRT(offsetY, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(offsetY);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_LT_LONG(&_0, width)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		width = zephir_get_numberval(&_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_LT_LONG(&_2, height)) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		height = zephir_get_numberval(&_3$$4);
	}
	if (Z_TYPE_P(offsetX) == IS_NULL) {
		zephir_read_property(&_4$$5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_DOUBLE(&_5$$5, zephir_safe_div_long_long(((zephir_get_numberval(&_4$$5) - width)), 2));
		ZEPHIR_INIT_NVAR(offsetX);
		zephir_round(offsetX, &_5$$5, NULL, NULL);
	} else if (ZEPHIR_IS_TRUE_IDENTICAL(offsetX)) {
		zephir_read_property(&_6$$6, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(offsetX);
		ZVAL_LONG(offsetX, (zephir_get_numberval(&_6$$6) - width));
	} else if (ZEPHIR_LT_LONG(offsetX, 0)) {
		zephir_read_property(&_7$$7, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		_8$$7 = ((zephir_get_numberval(&_7$$7) - width) + zephir_get_numberval(offsetX));
		ZEPHIR_INIT_NVAR(offsetX);
		ZVAL_LONG(offsetX, _8$$7);
	}
	if (Z_TYPE_P(offsetY) == IS_NULL) {
		zephir_read_property(&_9$$8, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZVAL_DOUBLE(&_10$$8, zephir_safe_div_long_long(((zephir_get_numberval(&_9$$8) - height)), 2));
		ZEPHIR_INIT_NVAR(offsetY);
		zephir_round(offsetY, &_10$$8, NULL, NULL);
	} else if (ZEPHIR_IS_TRUE_IDENTICAL(offsetY)) {
		zephir_read_property(&_11$$9, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(offsetY);
		ZVAL_LONG(offsetY, (zephir_get_numberval(&_11$$9) - height));
	} else if (ZEPHIR_LT_LONG(offsetY, 0)) {
		zephir_read_property(&_12$$10, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		_13$$10 = ((zephir_get_numberval(&_12$$10) - height) + zephir_get_numberval(offsetY));
		ZEPHIR_INIT_NVAR(offsetY);
		ZVAL_LONG(offsetY, _13$$10);
	}
	zephir_read_property(&_14, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_15);
	zephir_sub_function(&_15, &_14, offsetX);
	if (ZEPHIR_LT_LONG(&_15, width)) {
		zephir_read_property(&_16$$11, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_17$$11);
		zephir_sub_function(&_17$$11, &_16$$11, offsetX);
		width = zephir_get_numberval(&_17$$11);
	}
	zephir_read_property(&_14, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_18);
	zephir_sub_function(&_18, &_14, offsetY);
	if (ZEPHIR_LT_LONG(&_18, height)) {
		zephir_read_property(&_19$$12, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_20$$12);
		zephir_sub_function(&_20$$12, &_19$$12, offsetY);
		height = zephir_get_numberval(&_20$$12);
	}
	ZVAL_LONG(&_14, width);
	ZVAL_LONG(&_21, height);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docrop", NULL, 0, &_14, &_21, offsetX, offsetY);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Rotate the image by a given amount.
 *
 * <pre><code>
 *  // Rotate 45 degrees clockwise
 *  $image->rotate(45);
 *
 *  // Rotate 90% counter-clockwise
 *  $image->rotate(-90);
 * </code></pre>
 *
 * @param integer degrees Degrees to rotate: -360-360
 *
 * @return Image
 */
PHP_METHOD(Ice_Image, rotate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *degrees_param = NULL, _0;
	zend_long degrees, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(degrees)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	if (degrees > 180) {
		do {
			degrees -= 360;
		} while (degrees > 180);
	}
	if (degrees < -180) {
		do {
			degrees += 360;
		} while (degrees < -180);
	}
	ZVAL_LONG(&_0, degrees);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "dorotate", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Flip the image along the horizontal or vertical axis.
 *
 * <pre><code>
 *  // Flip the image from top to bottom
 *  $image->flip(Image::HORIZONTAL);
 *
 *  // Flip the image from left to right
 *  $image->flip(Image::VERTICAL);
 * </code></pre>
 *
 * @param integer direction Direction: Image::HORIZONTAL, Image::VERTICAL
 *
 * @return Image
 */
PHP_METHOD(Ice_Image, flip) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *direction_param = NULL, _0;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(direction)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	if (direction != 11) {
		direction = 12;
	}
	ZVAL_LONG(&_0, direction);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "doflip", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sharpen the image by a given amount.
 *
 * <pre><code>
 *  // Sharpen the image by 20%
 *  $image->sharpen(20);
 * </code></pre>
 *
 * @param integer amount Amount to sharpen: 1-100
 *
 * @return Image
 */
PHP_METHOD(Ice_Image, sharpen) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *amount_param = NULL, tmp, _0, _1, _2;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZVAL_LONG(&_0, amount);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_2, "max", NULL, 50, &_0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 100);
	ZEPHIR_CALL_FUNCTION(&tmp, "min", NULL, 31, &_2, &_0);
	zephir_check_call_status();
	amount = zephir_get_intval(&tmp);
	ZVAL_LONG(&_0, amount);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "dosharpen", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Add a reflection to an image. The most opaque part of the reflection will be equal to the opacity setting and fade out to full transparent.
 * Alpha transparency is preserved.
 *
 * <pre><code>
 *  // Create a 50 pixel reflection that fades from 0-100% opacity
 *  $image->reflection(50);
 *
 *  // Create a 50 pixel reflection that fades from 100-0% opacity
 *  $image->reflection(50, 100, true);
 *
 *  // Create a 50 pixel reflection that fades from 0-60% opacity
 *  $image->reflection(50, 60, true);
 * </code></pre>
 *
 * [!!] By default, the reflection will be go from transparent at the top to opaque at the bottom.
 *
 * @param integer height Reflection height
 * @param integer opacity Reflection opacity: 0-100
 * @param boolean fadeIn True to fade in, false to fade out
 *
 * @return Image
 */
PHP_METHOD(Ice_Image, reflection) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool fadeIn, _0;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, tmp, _1, _3, _4, _5, _6, _2$$3;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(height, is_null_true)
		Z_PARAM_LONG(opacity)
		Z_PARAM_BOOL(fadeIn)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &height_param, &opacity_param, &fadeIn_param);

	if (!height_param) {
		height = 0;
	} else {
		height = zephir_get_intval(height_param);
	}
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}
	if (!fadeIn_param) {
		fadeIn = 0;
	} else {
		fadeIn = zephir_get_boolval(fadeIn_param);
	}


	_0 = 1 == 0;
	if (!(_0)) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		_0 = ZEPHIR_LT_LONG(&_1, height);
	}
	if (_0) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		height = zephir_get_numberval(&_2$$3);
	}
	ZVAL_LONG(&_3, opacity);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_FUNCTION(&_5, "max", NULL, 50, &_3, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 100);
	ZEPHIR_CALL_FUNCTION(&tmp, "min", NULL, 31, &_5, &_3);
	zephir_check_call_status();
	opacity = zephir_get_intval(&tmp);
	ZVAL_LONG(&_3, height);
	ZVAL_LONG(&_4, opacity);
	if (fadeIn) {
		ZVAL_BOOL(&_6, 1);
	} else {
		ZVAL_BOOL(&_6, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "doreflection", NULL, 0, &_3, &_4, &_6);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Add a watermark to an image with a specified opacity. Alpha transparency will be preserved.
 *
 * If no offset is specified, the center of the axis will be used.
 * If an offset of true is specified, the bottom of the axis will be used.
 *
 * <pre><code>
 *  // Add a watermark to the bottom right of the image
 *  $mark = new Image('upload/watermark.png');
 *  $image->watermark($mark, true, true);
 * </code></pre>
 *
 * @param Image watermark Watermark Image instance
 * @param integer offsetX Offset from the left
 * @param integer offsetY Offset from the top
 * @param integer opacity Opacity of watermark: 1-100
 *
 * @return Image
 */
PHP_METHOD(Ice_Image, watermark) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *watermark, watermark_sub, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, tmp, _18, _19, _20, _21, _0$$3, _1$$3, _2$$3, _3$$4, _4$$4, _5$$4, _6$$5, _7$$5, _8$$5, _9$$6, _10$$6, _11$$6, _12$$7, _13$$7, _14$$7, _15$$8, _16$$8, _17$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&watermark_sub);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_OBJECT_OF_CLASS(watermark, ice_image_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(offsetX, is_null_true)
		Z_PARAM_LONG_OR_NULL(offsetY, is_null_true)
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &watermark, &offsetX_param, &offsetY_param, &opacity_param);

	if (!offsetX_param) {
		offsetX = 0;
	} else {
		offsetX = zephir_get_intval(offsetX_param);
	}
	if (!offsetY_param) {
		offsetY = 0;
	} else {
		offsetY = zephir_get_intval(offsetY_param);
	}
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}


	if (1 == 0) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$3, watermark, "getwidth", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_sub_function(&_2$$3, &_0$$3, &_1$$3);
		ZVAL_DOUBLE(&_0$$3, zephir_safe_div_zval_long(&_2$$3, 2));
		ZEPHIR_INIT_VAR(&tmp);
		zephir_round(&tmp, &_0$$3, NULL, NULL);
		offsetX = zephir_get_intval(&tmp);
	} else if (offsetX == 1) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$4, watermark, "getwidth", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_sub_function(&_5$$4, &_3$$4, &_4$$4);
		offsetX = zephir_get_numberval(&_5$$4);
	} else if (offsetX < 0) {
		zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7$$5, watermark, "getwidth", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$5);
		zephir_sub_function(&_8$$5, &_6$$5, &_7$$5);
		offsetX = (zephir_get_numberval(&_8$$5) + offsetX);
	}
	if (1 == 0) {
		zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_10$$6, watermark, "getheight", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$6);
		zephir_sub_function(&_11$$6, &_9$$6, &_10$$6);
		ZVAL_DOUBLE(&_9$$6, zephir_safe_div_zval_long(&_11$$6, 2));
		ZEPHIR_INIT_NVAR(&tmp);
		zephir_round(&tmp, &_9$$6, NULL, NULL);
		offsetY = zephir_get_intval(&tmp);
	} else if (offsetY == 1) {
		zephir_read_property(&_12$$7, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_13$$7, watermark, "getheight", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_14$$7);
		zephir_sub_function(&_14$$7, &_12$$7, &_13$$7);
		offsetY = zephir_get_numberval(&_14$$7);
	} else if (offsetY < 0) {
		zephir_read_property(&_15$$8, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_16$$8, watermark, "getheight", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_17$$8);
		zephir_sub_function(&_17$$8, &_15$$8, &_16$$8);
		offsetY = (zephir_get_numberval(&_17$$8) + offsetY);
	}
	ZVAL_LONG(&_18, opacity);
	ZVAL_LONG(&_19, 1);
	ZEPHIR_CALL_FUNCTION(&_20, "max", NULL, 50, &_18, &_19);
	zephir_check_call_status();
	ZVAL_LONG(&_18, 100);
	ZEPHIR_CALL_FUNCTION(&tmp, "min", NULL, 31, &_20, &_18);
	zephir_check_call_status();
	opacity = zephir_get_intval(&tmp);
	ZVAL_LONG(&_18, offsetX);
	ZVAL_LONG(&_19, offsetY);
	ZVAL_LONG(&_21, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "dowatermark", NULL, 0, watermark, &_18, &_19, &_21);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set the background color of an image. This is only useful for images with alpha transparency.
 *
 * <pre><code>
 *  // Make the image background black
 *  $image->background('#000');
 *
 *  // Make the image background black with 50% opacity
 *  $image->background('#000', 50);
 * </code></pre>
 *
 * @param string color Hexadecimal color value
 * @param integer opacity Background opacity: 0-100

 * @return Image
 */
PHP_METHOD(Ice_Image, background) {

	unsigned char _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *color_param = NULL, *opacity_param = NULL, tmp, r, g, b, _6, _7, _8, _9, _10, _1$$3, _2$$3, _3$$4, _4$$4, _5$$4;
	zval color;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&g);
	ZVAL_UNDEF(&b);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(color)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &color_param, &opacity_param);

	zephir_get_strval(&color, color_param);
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}


	_0 = ZEPHIR_STRING_OFFSET(&color, 0);
	if (_0 == '#') {
		ZVAL_LONG(&_1$$3, 1);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_substr(&_2$$3, &color, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(&color, &_2$$3);
	}
	if (zephir_fast_strlen_ev(&color) == 3) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "/./");
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "00");
		ZEPHIR_CALL_FUNCTION(&_5$$4, "preg_replace", NULL, 51, &_3$$4, &_4$$4, &color);
		zephir_check_call_status();
		zephir_get_strval(&color, &_5$$4);
	}
	ZVAL_LONG(&_6, 2);
	ZEPHIR_CALL_FUNCTION(&_7, "str_split", NULL, 38, &color, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "hexdec");
	ZEPHIR_CALL_FUNCTION(&tmp, "array_map", NULL, 52, &_8, &_7);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&r);
	zephir_array_fetch_long(&r, &tmp, 0, PH_NOISY, "ice/image.zep", 512);
	ZEPHIR_OBS_VAR(&g);
	zephir_array_fetch_long(&g, &tmp, 1, PH_NOISY, "ice/image.zep", 513);
	ZEPHIR_OBS_VAR(&b);
	zephir_array_fetch_long(&b, &tmp, 2, PH_NOISY, "ice/image.zep", 514);
	ZVAL_LONG(&_6, opacity);
	ZVAL_LONG(&_9, 0);
	ZEPHIR_CALL_FUNCTION(&_10, "max", NULL, 50, &_6, &_9);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 100);
	ZEPHIR_CALL_FUNCTION(&tmp, "min", NULL, 31, &_10, &_6);
	zephir_check_call_status();
	opacity = zephir_get_intval(&tmp);
	ZVAL_LONG(&_6, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "dobackground", NULL, 0, &r, &g, &b, &_6);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Save the image. If the filename is omitted, the original image will be overwritten.
 *
 * <pre><code>
 *  // Save the image as a PNG
 *  $image->save('saved/cool.png');
 *
 *  // Overwrite the original image
 *  $image->save();
 * </code></pre>
 *
 * [!!] If the file exists, but is not writable, an exception will be thrown.
 * [!!] If the file does not exist, and the directory is not writable, an exception will be thrown.
 *
 * @param string file New image path
 * @param integer quality Quality of image: 1-100

 * @return boolean
 * @throws Exception
 */
PHP_METHOD(Ice_Image, save) {

	zend_bool _11$$6;
	zval _5$$5, _14$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, tmp, directory, _1, _16, _17, _18, _0$$3, _2$$4, _4$$5, _6$$5, _8$$6, _9$$6, _10$$6, _12$$6, _13$$7, _15$$7;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_14$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(file)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file_param, &quality_param);

	if (!file_param) {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_STRING(&file, "");
	} else {
		zephir_get_strval(&file, file_param);
	}
	if (!quality_param) {
		quality = 100;
	} else {
		quality = zephir_get_intval(quality_param);
	}


	if (1 == 0) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		zephir_get_strval(&file, &_0$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", NULL, 53, &file);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_FUNCTION(&_2$$4, "is_writable", &_3, 54, &file);
		zephir_check_call_status();
		if (!(zephir_is_true(&_2$$4))) {
			ZEPHIR_INIT_VAR(&_4$$5);
			object_init_ex(&_4$$5, ice_exception_ce);
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_create_array(&_5$$5, 2, 0);
			ZEPHIR_INIT_VAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "File must be writable: %s");
			zephir_array_fast_append(&_5$$5, &_6$$5);
			zephir_array_fast_append(&_5$$5, &file);
			ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", &_7, 12, &_5$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$5, "ice/image.zep", 556);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZVAL_LONG(&_8$$6, 1);
		ZEPHIR_CALL_FUNCTION(&_9$$6, "pathinfo", NULL, 55, &file, &_8$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&directory, "realpath", NULL, 47, &_9$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_10$$6, "is_dir", NULL, 56, &directory);
		zephir_check_call_status();
		_11$$6 = !zephir_is_true(&_10$$6);
		if (!(_11$$6)) {
			ZEPHIR_CALL_FUNCTION(&_12$$6, "is_writable", &_3, 54, &directory);
			zephir_check_call_status();
			_11$$6 = !zephir_is_true(&_12$$6);
		}
		if (_11$$6) {
			ZEPHIR_INIT_VAR(&_13$$7);
			object_init_ex(&_13$$7, ice_exception_ce);
			ZEPHIR_INIT_VAR(&_14$$7);
			zephir_create_array(&_14$$7, 2, 0);
			ZEPHIR_INIT_VAR(&_15$$7);
			ZVAL_STRING(&_15$$7, "Directory must be writable: %s");
			zephir_array_fast_append(&_14$$7, &_15$$7);
			zephir_array_fast_append(&_14$$7, &directory);
			ZEPHIR_CALL_METHOD(NULL, &_13$$7, "__construct", &_7, 12, &_14$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_13$$7, "ice/image.zep", 563);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZVAL_LONG(&_16, quality);
	ZVAL_LONG(&_17, 1);
	ZEPHIR_CALL_FUNCTION(&_18, "max", NULL, 50, &_16, &_17);
	zephir_check_call_status();
	ZVAL_LONG(&_16, 100);
	ZEPHIR_CALL_FUNCTION(&tmp, "min", NULL, 31, &_18, &_16);
	zephir_check_call_status();
	quality = zephir_get_intval(&tmp);
	ZVAL_LONG(&_16, quality);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dosave", NULL, 0, &file, &_16);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Render the image and return the binary string.
 *
 * <pre><code>
 *  // Render the image at 50% quality
 *  $data = image->render(null, 50);
 *
 *  // Render the image as a PNG
 *  $data = image->render('png');
 * </code></pre>
 *
 * @param string type Image type to return: png, jpg, gif, etc
 * @param integer quality Quality of image: 1-100

 * @return string
 */
PHP_METHOD(Ice_Image, render) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *quality_param = NULL, __$false, tmp, _2, _0$$3;
	zval type, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(type)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &type_param, &quality_param);

	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "");
	} else {
		zephir_get_strval(&type, type_param);
	}
	if (!quality_param) {
		quality = 100;
	} else {
		quality = zephir_get_intval(quality_param);
	}


	if (1 == 0) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&tmp, "image_type_to_extension", NULL, 57, &_0$$3, &__$false);
		zephir_check_call_status();
		zephir_get_strval(&_1$$3, &tmp);
		ZEPHIR_CPY_WRT(&type, &_1$$3);
	}
	ZVAL_LONG(&_2, quality);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dorender", NULL, 0, &type, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Execute a resize.
 *
 * @param integer width New width
 * @param integer height New height
 *
 * @return void
 */
PHP_METHOD(Ice_Image, doResize) {

}

/**
 * Execute a crop.
 *
 * @param integer width New width
 * @param integer height New height
 * @param integer offset_x offset From the left
 * @param integer offset_y offset From the top
 *
 * @return void
 */
PHP_METHOD(Ice_Image, doCrop) {

}

/**
 * Execute a rotation.
 *
 * @param integer degrees Degrees to rotate
 *
 * @return void
 */
PHP_METHOD(Ice_Image, doRotate) {

}

/**
 * Execute a flip.
 *
 * @param integer direction Direction to flip
 *
 * @return void
 */
PHP_METHOD(Ice_Image, doFlip) {

}

/**
 * Execute a sharpen.
 *
 * @param integer amount Amount to sharpen
 *
 * @return void
 */
PHP_METHOD(Ice_Image, doSharpen) {

}

/**
 * Execute a reflection.
 *
 * @param integer height Reflection height
 * @param integer opacity Reflection opacity
 * @param boolean fadeIn TRUE to fade out, FALSE to fade in
 *
 * @return void
 */
PHP_METHOD(Ice_Image, doReflection) {

}

/**
 * Execute a watermarking.
 *
 * @param Image image Watermarking Image
 * @param integer offsetX Offset from the left
 * @param integer offsetY Offset from the top
 * @param integer opacity Opacity of watermark
 *
 * @return void
 */
PHP_METHOD(Ice_Image, doWatermark) {

}

/**
 * Execute a background.
 *
 * @param integer r Red
 * @param integer g Green
 * @param integer b Blue
 * @param integer opacity Opacity
 *
 * @return void
 */
PHP_METHOD(Ice_Image, doBackground) {

}

/**
 * Execute a save.
 *
 * @param string file New image filename
 * @param integer quality Quality
 *
 * @return boolean
 */
PHP_METHOD(Ice_Image, doSave) {

}

/**
 * Execute a render.
 *
 * @param string type Image type: png, jpg, gif, etc
 * @param integer quality Quality
 *
 * @return string
 */
PHP_METHOD(Ice_Image, doRender) {

}

