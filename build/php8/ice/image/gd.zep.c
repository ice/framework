
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/math.h"
#include "kernel/string.h"


/**
 * Gd image driver.
 *
 * @package     Ice/Image
 * @category    Driver
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Image_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Image, Gd, ice, image_gd, ice_image_ce, ice_image_gd_method_entry, 0);

	zend_declare_property_null(ice_image_gd_ce, SL("bundled"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	zend_declare_property_null(ice_image_gd_ce, SL("image"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_image_gd_ce, SL("createFunction"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Run install check and load the image.
 *
 * @param string file Image file path
 *
 * @return void
 * @throws Exception
 */
PHP_METHOD(Ice_Image_Gd, __construct) {

	zval _5$$7;
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, __$false, create, _0, _2, _9, _4$$7, _6$$7, _7$$7, _8$$7;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&create);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_5$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(&file, file_param);


	zephir_read_static_property_ce(&_0, ice_image_gd_ce, SL("checked"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_SELF(NULL, "check", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, ice_image_gd_ce, getThis(), "__construct", &_1, 0, &file);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_LONG(&_2, 2)) {
			ZEPHIR_INIT_VAR(&create);
			ZVAL_STRING(&create, "imagecreatefromjpeg");
			break;
		}
		if (ZEPHIR_IS_LONG(&_2, 1)) {
			ZEPHIR_INIT_NVAR(&create);
			ZVAL_STRING(&create, "imagecreatefromgif");
			break;
		}
		if (ZEPHIR_IS_LONG(&_2, 3)) {
			ZEPHIR_INIT_NVAR(&create);
			ZVAL_STRING(&create, "imagecreatefrompng");
			break;
		}
	} while(0);

	_3 = !zephir_is_true(&create);
	if (!(_3)) {
		_3 = !((zephir_function_exists(&create) == SUCCESS));
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_4$$7);
		object_init_ex(&_4$$7, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$7);
		zephir_create_array(&_5$$7, 2, 0);
		ZEPHIR_INIT_VAR(&_6$$7);
		ZVAL_STRING(&_6$$7, "Installed GD does not support %s images");
		zephir_array_fast_append(&_5$$7, &_6$$7);
		zephir_read_property(&_7$$7, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_8$$7, "image_type_to_extension", NULL, 57, &_7$$7, &__$false);
		zephir_check_call_status();
		zephir_array_fast_append(&_5$$7, &_8$$7);
		ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 12, &_5$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$7, "ice/image/gd.zep", 56);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("createFunction"), &create);
	zephir_read_property(&_9, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &_9);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if GD is enabled and bundled. Bundled GD is required for some methods to work.
 * Exceptions will be thrown from those methods when GD is not bundled.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Image_Gd, check) {

	zval _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, version, _0, _1, _4, _5, _6, _11, _3$$4, _7$$6, _9$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_10 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_8$$6);


	ZEPHIR_MM_GROW();

	if (!((zephir_function_exists_ex(ZEND_STRL("gd_info")) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "GD is either not installed or not enabled, check your configuration", "ice/image/gd.zep", 77);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GD_BUNDLED");
	ZEPHIR_CALL_FUNCTION(&_1, "defined", &_2, 151, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_ZVAL_NREF(_3$$4);
		ZVAL_LONG(&_3$$4, 1);
		zephir_update_static_property_ce(ice_image_gd_ce, ZEND_STRL("bundled"), &_3$$4);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "GD_VERSION");
	ZEPHIR_CALL_FUNCTION(&_4, "defined", &_2, 151, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&version);
		ZEPHIR_GET_CONSTANT(&version, "GD_VERSION");
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "2.0.1");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, ">=");
	ZEPHIR_CALL_FUNCTION(&_6, "version_compare", NULL, 98, &version, &_0, &_5);
	zephir_check_call_status();
	if (!(zephir_is_true(&_6))) {
		ZEPHIR_INIT_VAR(&_7$$6);
		object_init_ex(&_7$$6, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_8$$6);
		zephir_create_array(&_8$$6, 3, 0);
		ZEPHIR_INIT_VAR(&_9$$6);
		ZVAL_STRING(&_9$$6, "GD requires GD version %s or greater, you have %s");
		zephir_array_fast_append(&_8$$6, &_9$$6);
		ZEPHIR_INIT_NVAR(&_9$$6);
		ZVAL_STRING(&_9$$6, "2.0.1");
		zephir_array_fast_append(&_8$$6, &_9$$6);
		zephir_array_fast_append(&_8$$6, &version);
		ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", &_10, 12, &_8$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$6, "ice/image/gd.zep", 91);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(ice_image_gd_ce, ZEND_STRL("checked"), &__$true);
	zephir_read_static_property_ce(&_11, ice_image_gd_ce, SL("checked"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_11);

}

/**
 * Destroys the loaded image to free up resources.
 *
 * @return void
 */
PHP_METHOD(Ice_Image_Gd, __destruct) {

	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_RESOURCE) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 152, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Loads an image into GD.
 *
 * @return void
 */
PHP_METHOD(Ice_Image_Gd, loadImage) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, create, _0, _1$$3, _2$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&create);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_RESOURCE)) {
		ZEPHIR_OBS_VAR(&create);
		zephir_read_property(&create, this_ptr, ZEND_STRL("createFunction"), PH_NOISY_CC);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_2$$3, &create, NULL, 0, &_1$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &_2$$3);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 153, &_3$$3, &__$true);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a resize.
 *
 * @param integer width New width
 * @param integer height New height
 *
 * @return void
 */
PHP_METHOD(Ice_Image_Gd, doResize) {

	zend_bool _1, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_16 = NULL;
	zval *width_param = NULL, *height_param = NULL, preWidth, preHeight, reductionWidth, reductionHeight, image, _0, _2, _17, _18, _19, _20, _21, _22, _23, _24, _3$$3, _4$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$5, _25$$6, _26$$6, _27$$6;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&preWidth);
	ZVAL_UNDEF(&preHeight);
	ZVAL_UNDEF(&reductionWidth);
	ZVAL_UNDEF(&reductionHeight);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZEPHIR_OBS_VAR(&preWidth);
	zephir_read_property(&preWidth, this_ptr, ZEND_STRL("width"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&preHeight);
	zephir_read_property(&preHeight, this_ptr, ZEND_STRL("height"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadimage", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	_1 = width > (zephir_safe_div_zval_long(&_0, 2));
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		_1 = height > (zephir_safe_div_zval_long(&_2, 2));
	}
	if (_1) {
		ZVAL_LONG(&_3$$3, (width * 1.1));
		ZEPHIR_INIT_VAR(&reductionWidth);
		zephir_round(&reductionWidth, &_3$$3, NULL, NULL);
		ZVAL_LONG(&_4$$3, (height * 1.1));
		ZEPHIR_INIT_VAR(&reductionHeight);
		zephir_round(&reductionHeight, &_4$$3, NULL, NULL);
		while (1) {
			_5$$3 = ZEPHIR_LT_LONG(&reductionWidth, zephir_safe_div_zval_long(&preWidth, 2));
			if (_5$$3) {
				_5$$3 = ZEPHIR_LT_LONG(&reductionHeight, zephir_safe_div_zval_long(&preHeight, 2));
			}
			if (!(_5$$3)) {
				break;
			}
			ZEPHIR_INIT_NVAR(&preWidth);
			ZVAL_DOUBLE(&preWidth, 2);
			ZEPHIR_INIT_NVAR(&preHeight);
			ZVAL_DOUBLE(&preHeight, 2);
		}
		ZEPHIR_CALL_METHOD(&image, this_ptr, "create", &_6, 0, &preWidth, &preHeight);
		zephir_check_call_status();
		zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_10$$3, 0);
		ZVAL_LONG(&_11$$3, 0);
		ZVAL_LONG(&_12$$3, 0);
		ZVAL_LONG(&_13$$3, 0);
		ZEPHIR_CALL_FUNCTION(&_14$$3, "imagecopyresized", NULL, 154, &image, &_7$$3, &_10$$3, &_11$$3, &_12$$3, &_13$$3, &preWidth, &preHeight, &_8$$3, &_9$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_14$$3)) {
			zephir_read_property(&_15$$5, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_16, 152, &_15$$5);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &image);
		}
	}
	ZVAL_LONG(&_17, width);
	ZVAL_LONG(&_18, height);
	ZEPHIR_CALL_METHOD(&image, this_ptr, "create", &_6, 0, &_17, &_18);
	zephir_check_call_status();
	zephir_read_property(&_17, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_18, 0);
	ZVAL_LONG(&_19, 0);
	ZVAL_LONG(&_20, 0);
	ZVAL_LONG(&_21, 0);
	ZVAL_LONG(&_22, width);
	ZVAL_LONG(&_23, height);
	ZEPHIR_CALL_FUNCTION(&_24, "imagecopyresampled", NULL, 155, &image, &_17, &_18, &_19, &_20, &_21, &_22, &_23, &preWidth, &preHeight);
	zephir_check_call_status();
	if (zephir_is_true(&_24)) {
		zephir_read_property(&_25$$6, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_16, 152, &_25$$6);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &image);
		ZEPHIR_CALL_FUNCTION(&_26$$6, "imagesx", NULL, 156, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_26$$6);
		ZEPHIR_CALL_FUNCTION(&_27$$6, "imagesy", NULL, 157, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_27$$6);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a crop.
 *
 * @param integer width New width
 * @param integer height New height
 * @param integer offsetX Offset from the left
 * @param integer offsetY Offset from the top
 *
 * @return void
 */
PHP_METHOD(Ice_Image_Gd, doCrop) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, image, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10$$3, _11$$3, _12$$3;
	zend_long width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(offsetX)
		Z_PARAM_LONG(offsetY)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offsetX_param, &offsetY_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);


	ZVAL_LONG(&_0, width);
	ZVAL_LONG(&_1, height);
	ZEPHIR_CALL_METHOD(&image, this_ptr, "create", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadimage", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, offsetX);
	ZVAL_LONG(&_4, offsetY);
	ZVAL_LONG(&_5, width);
	ZVAL_LONG(&_6, height);
	ZVAL_LONG(&_7, width);
	ZVAL_LONG(&_8, height);
	ZEPHIR_CALL_FUNCTION(&_9, "imagecopyresampled", NULL, 155, &image, &_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8);
	zephir_check_call_status();
	if (zephir_is_true(&_9)) {
		zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 152, &_10$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &image);
		ZEPHIR_CALL_FUNCTION(&_11$$3, "imagesx", NULL, 156, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_11$$3);
		ZEPHIR_CALL_FUNCTION(&_12$$3, "imagesy", NULL, 157, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_12$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a rotation.
 *
 * @param integer degrees Degrees to rotate
 *
 * @return void
 */
PHP_METHOD(Ice_Image_Gd, doRotate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *degrees_param = NULL, __$true, transparent, image, width, height, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9$$3;
	zend_long degrees, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&transparent);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(degrees)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadimage", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 127);
	ZEPHIR_CALL_FUNCTION(&transparent, "imagecolorallocatealpha", NULL, 158, &_0, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, (360 - degrees));
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&image, "imagerotate", NULL, 159, &_1, &_2, &transparent, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 153, &image, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&width, "imagesx", NULL, 156, &image);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&height, "imagesy", NULL, 157, &image);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 0);
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 100);
	ZEPHIR_CALL_FUNCTION(&_8, "imagecopymerge", NULL, 160, &_2, &image, &_3, &_4, &_5, &_6, &width, &height, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 152, &_9$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &image);
		zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &width);
		zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &height);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a flip.
 *
 * @param integer direction Direction to flip
 *
 * @return void
 */
PHP_METHOD(Ice_Image_Gd, doFlip) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zval *direction_param = NULL, flipped, _0, _1, _21, _22, _23, _2$$3, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _12$$5, _13$$6, _14$$6, _15$$6, _16$$6, _17$$6, _18$$6, _19$$6, _20$$6;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS, x$$3, y$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&flipped);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(direction)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&flipped, this_ptr, "create", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadimage", NULL, 0);
	zephir_check_call_status();
	if (direction == 11) {
		x$$3 = 0;
		while (1) {
			zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_GT_LONG(&_2$$3, x$$3))) {
				break;
			}
			zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_6$$4, x$$3);
			ZVAL_LONG(&_7$$4, 0);
			ZVAL_LONG(&_8$$4, ((zephir_get_numberval(&_4$$4) - x$$3) - 1));
			ZVAL_LONG(&_9$$4, 0);
			ZVAL_LONG(&_10$$4, 1);
			ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_11, 161, &flipped, &_3$$4, &_6$$4, &_7$$4, &_8$$4, &_9$$4, &_10$$4, &_5$$4);
			zephir_check_call_status();
			x$$3++;
		}
	} else {
		y$$5 = 0;
		while (1) {
			zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_GT_LONG(&_12$$5, y$$5))) {
				break;
			}
			zephir_read_property(&_13$$6, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_14$$6, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_15$$6, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_16$$6, 0);
			ZVAL_LONG(&_17$$6, y$$5);
			ZVAL_LONG(&_18$$6, 0);
			ZVAL_LONG(&_19$$6, ((zephir_get_numberval(&_14$$6) - y$$5) - 1));
			ZVAL_LONG(&_20$$6, 1);
			ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_11, 161, &flipped, &_13$$6, &_16$$6, &_17$$6, &_18$$6, &_19$$6, &_15$$6, &_20$$6);
			zephir_check_call_status();
			y$$5++;
		}
	}
	zephir_read_property(&_21, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 152, &_21);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &flipped);
	ZEPHIR_CALL_FUNCTION(&_22, "imagesx", NULL, 156, &flipped);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_22);
	ZEPHIR_CALL_FUNCTION(&_23, "imagesy", NULL, 157, &flipped);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_23);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a sharpen.
 *
 * @param integer amount Amount to sharpen
 *
 * @return void
 */
PHP_METHOD(Ice_Image_Gd, doSharpen) {

	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *amount_param = NULL, tmp, matrix, _0, _1, _3, _4, _5, _6, _7, _8$$3, _9$$3, _10$$3, _11$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&matrix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadimage", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, (-18 + ((amount * 0.08))));
	ZEPHIR_CALL_FUNCTION(&_1, "abs", NULL, 147, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 2);
	ZEPHIR_INIT_VAR(&tmp);
	zephir_round(&tmp, &_1, &_0, NULL);
	amount = zephir_get_intval(&tmp);
	ZEPHIR_INIT_VAR(&matrix);
	zephir_create_array(&matrix, 3, 0);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_3, -1);
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, -1);
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, -1);
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&matrix, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, -1);
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, amount);
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, -1);
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&matrix, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, -1);
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, -1);
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, -1);
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&matrix, &_2);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, (amount - 8));
	ZVAL_LONG(&_6, 0);
	ZEPHIR_CALL_FUNCTION(&_7, "imageconvolution", NULL, 162, &_4, &matrix, &_5, &_6);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_9$$3, "imagesx", NULL, 156, &_8$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_9$$3);
		zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_11$$3, "imagesy", NULL, 157, &_10$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_11$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a reflection.
 *
 * @param integer height Reflection height
 * @param integer opacity Reflection opacity
 * @param boolean fadeIn True to fade out, false to fade in
 *
 * @return void
 */
PHP_METHOD(Ice_Image_Gd, doReflection) {

	double stepping = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_11 = NULL, *_23 = NULL;
	zend_bool fadeIn;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, tmp, srcY, dstY, dstOpacity, reflection, line, _0, _1, _2, _3, _5, _6, _7, _8, _9, _10, _25, _26, _12$$5, _13$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5, _21$$5, _22$$5, _24$$5, _14$$6, _15$$7;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS, offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&srcY);
	ZVAL_UNDEF(&dstY);
	ZVAL_UNDEF(&dstOpacity);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(opacity)
		Z_PARAM_BOOL(fadeIn)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);

	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fadeIn = zephir_get_boolval(fadeIn_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadimage", NULL, 0);
	zephir_check_call_status();
	ZVAL_DOUBLE(&_0, ((zephir_safe_div_long_long((opacity * 127), 100)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_1, "abs", NULL, 147, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&tmp);
	zephir_round(&tmp, &_1, NULL, NULL);
	opacity = zephir_get_intval(&tmp);
	if (opacity < 127) {
		stepping = zephir_safe_div_long_long(((127 - opacity)), height);
	} else {
		stepping = zephir_safe_div_long_long(127, height);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, (zephir_get_numberval(&_2) + height));
	ZEPHIR_CALL_METHOD(&reflection, this_ptr, "create", &_4, 0, &_0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_11, 161, &reflection, &_3, &_7, &_8, &_9, &_10, &_5, &_6);
	zephir_check_call_status();
	offset = 0;
	while (1) {
		if (!(height >= offset)) {
			break;
		}
		zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&srcY);
		ZVAL_LONG(&srcY, ((zephir_get_numberval(&_12$$5) - offset) - 1));
		zephir_read_property(&_13$$5, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&dstY);
		ZVAL_LONG(&dstY, (zephir_get_numberval(&_13$$5) + offset));
		if (fadeIn == 1) {
			ZVAL_LONG(&_14$$6, (opacity + ((stepping * (double) ((height - offset))))));
			ZEPHIR_INIT_NVAR(&dstOpacity);
			zephir_round(&dstOpacity, &_14$$6, NULL, NULL);
		} else {
			ZVAL_LONG(&_15$$7, (opacity + ((stepping *  (double) offset))));
			ZEPHIR_INIT_NVAR(&dstOpacity);
			zephir_round(&dstOpacity, &_15$$7, NULL, NULL);
		}
		zephir_read_property(&_16$$5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_17$$5, 1);
		ZEPHIR_CALL_METHOD(&line, this_ptr, "create", &_4, 0, &_16$$5, &_17$$5);
		zephir_check_call_status();
		zephir_read_property(&_17$$5, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_18$$5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_19$$5, 0);
		ZVAL_LONG(&_20$$5, 0);
		ZVAL_LONG(&_21$$5, 0);
		ZVAL_LONG(&_22$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_11, 161, &line, &_17$$5, &_19$$5, &_20$$5, &_21$$5, &srcY, &_18$$5, &_22$$5);
		zephir_check_call_status();
		ZVAL_LONG(&_19$$5, 4);
		ZVAL_LONG(&_20$$5, 0);
		ZVAL_LONG(&_21$$5, 0);
		ZVAL_LONG(&_22$$5, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_23, 163, &line, &_19$$5, &_20$$5, &_21$$5, &_22$$5, &dstOpacity);
		zephir_check_call_status();
		zephir_read_property(&_19$$5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_20$$5, 0);
		ZVAL_LONG(&_21$$5, 0);
		ZVAL_LONG(&_22$$5, 0);
		ZVAL_LONG(&_24$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_11, 161, &reflection, &line, &_20$$5, &dstY, &_21$$5, &_22$$5, &_19$$5, &_24$$5);
		zephir_check_call_status();
		offset++;
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 152, &_7);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &reflection);
	ZEPHIR_CALL_FUNCTION(&_25, "imagesx", NULL, 156, &reflection);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_25);
	ZEPHIR_CALL_FUNCTION(&_26, "imagesy", NULL, 157, &reflection);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_26);
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Ice_Image_Gd, doWatermark) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *watermark, watermark_sub, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, __$true, tmp, overlay, width, height, color, _0, _6, _7, _8, _9, _10, _11, _12, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&watermark_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&overlay);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(watermark, ice_image_ce)
		Z_PARAM_LONG(offsetX)
		Z_PARAM_LONG(offsetY)
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &watermark, &offsetX_param, &offsetY_param, &opacity_param);

	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadimage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, watermark, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&overlay, "imagecreatefromstring", NULL, 164, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 153, &overlay, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&width, "imagesx", NULL, 156, &overlay);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&height, "imagesy", NULL, 157, &overlay);
	zephir_check_call_status();
	if (opacity < 100) {
		ZVAL_DOUBLE(&_1$$3, ((zephir_safe_div_long_long((opacity * 127), 100)) - (double) (127)));
		ZEPHIR_CALL_FUNCTION(&_2$$3, "abs", NULL, 147, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&tmp);
		zephir_round(&tmp, &_2$$3, NULL, NULL);
		opacity = zephir_get_intval(&tmp);
		ZVAL_LONG(&_1$$3, 127);
		ZVAL_LONG(&_3$$3, 127);
		ZVAL_LONG(&_4$$3, 127);
		ZVAL_LONG(&_5$$3, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 158, &overlay, &_1$$3, &_3$$3, &_4$$3, &_5$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_1$$3, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "imagelayereffect", NULL, 165, &overlay, &_1$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_1$$3, 0);
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", NULL, 166, &overlay, &_1$$3, &_3$$3, &width, &height, &color);
		zephir_check_call_status();
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 167, &_6, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_8, offsetX);
	ZVAL_LONG(&_9, offsetY);
	ZVAL_LONG(&_10, 0);
	ZVAL_LONG(&_11, 0);
	ZEPHIR_CALL_FUNCTION(&_12, "imagecopy", NULL, 161, &_7, &overlay, &_8, &_9, &_10, &_11, &width, &height);
	zephir_check_call_status();
	if (zephir_is_true(&_12)) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 152, &overlay);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Ice_Image_Gd, doBackground) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, __$true, tmp, background, color, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13$$3;
	zend_long r, g, b, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&background);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(r)
		Z_PARAM_LONG(g)
		Z_PARAM_LONG(b)
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &r_param, &g_param, &b_param, &opacity_param);

	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadimage", NULL, 0);
	zephir_check_call_status();
	ZVAL_DOUBLE(&_0, ((zephir_safe_div_long_long((opacity * 127), 100)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_1, "abs", NULL, 147, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&tmp);
	zephir_round(&tmp, &_1, NULL, NULL);
	opacity = zephir_get_intval(&tmp);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&background, this_ptr, "create", NULL, 0, &_0, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_3, r);
	ZVAL_LONG(&_4, g);
	ZVAL_LONG(&_5, b);
	ZVAL_LONG(&_6, opacity);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 158, &background, &_3, &_4, &_5, &_6);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", NULL, 166, &background, &_5, &_6, &_3, &_4, &color);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 167, &background, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, 0);
	ZVAL_LONG(&_11, 0);
	ZEPHIR_CALL_FUNCTION(&_12, "imagecopy", NULL, 161, &background, &_5, &_8, &_9, &_10, &_11, &_6, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_12)) {
		zephir_read_property(&_13$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 152, &_13$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &background);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a save.
 *
 * @param string file New image filename
 * @param integer quality Quality
 *
 * @return boolean
 */
PHP_METHOD(Ice_Image_Gd, doSave) {

	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality = NULL, quality_sub, __$null, tmp, extension, save, type, status, _0, _1, _3, _4$$3;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&quality_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&save);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(quality)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &quality);

	zephir_get_strval(&file, file_param);
	if (!quality) {
		quality = &quality_sub;
		ZEPHIR_CPY_WRT(quality, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(quality);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadimage", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 55, &file, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "savefunction", NULL, 0, &extension, quality);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&save);
	zephir_array_fetch_long(&save, &tmp, 0, PH_NOISY, "ice/image/gd.zep", 531);
	ZEPHIR_OBS_VAR(&type);
	zephir_array_fetch_long(&type, &tmp, 1, PH_NOISY, "ice/image/gd.zep", 532);
	ZEPHIR_OBS_NVAR(quality);
	zephir_array_fetch_long(quality, &tmp, 2, PH_NOISY, "ice/image/gd.zep", 533);
	if (zephir_is_true(quality)) {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_ZVAL_FUNCTION(&status, &save, NULL, 0, &_0, &file, quality);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_ZVAL_FUNCTION(&status, &save, NULL, 0, &_1, &file);
		zephir_check_call_status();
	}
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&status);
	if (_2) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		_2 = !ZEPHIR_IS_IDENTICAL(&type, &_3);
	}
	if (_2) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "image_type_to_mime_type", NULL, 49, &type);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_4$$3);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Execute a render.
 *
 * @param string type Image type: png, jpg, gif, etc
 * @param integer quality Quality
 *
 * @return string
 */
PHP_METHOD(Ice_Image_Gd, doRender) {

	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *quality = NULL, quality_sub, tmp, save, status, _0, _2, _3, _4, _6$$3;
	zval type, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&quality_sub);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&save);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_ZVAL(quality)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &quality);

	zephir_get_strval(&type, type_param);
	ZEPHIR_SEPARATE_PARAM(quality);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadimage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "savefunction", NULL, 0, &type, quality);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&save);
	zephir_array_fetch_long(&save, &tmp, 0, PH_NOISY, "ice/image/gd.zep", 564);
	ZEPHIR_OBS_VAR(&_0);
	zephir_array_fetch_long(&_0, &tmp, 1, PH_NOISY, "ice/image/gd.zep", 565);
	zephir_get_strval(&_1, &_0);
	ZEPHIR_CPY_WRT(&type, &_1);
	ZEPHIR_OBS_NVAR(quality);
	zephir_array_fetch_long(quality, &tmp, 2, PH_NOISY, "ice/image/gd.zep", 566);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 168);
	zephir_check_call_status();
	if (zephir_is_true(quality)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_NULL(&_3);
		ZEPHIR_CALL_ZVAL_FUNCTION(&status, &save, NULL, 0, &_2, &_3, quality);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_NULL(&_4);
		ZEPHIR_CALL_ZVAL_FUNCTION(&status, &save, NULL, 0, &_3, &_4);
		zephir_check_call_status();
	}
	_5 = ZEPHIR_IS_TRUE_IDENTICAL(&status);
	if (_5) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		_5 = !ZEPHIR_IS_IDENTICAL(&type, &_4);
	}
	if (_5) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "image_type_to_mime_type", NULL, 49, &type);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_6$$3);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 169);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the GD saving function and image type for this extension.
 * Also normalizes the quality setting
 *
 * @param string extension Image type: png, jpg, etc
 * @param integer quality Image quality

 * @return array Save function, IMAGETYPE_* constant
 * @throws Exception
 */
PHP_METHOD(Ice_Image_Gd, saveFunction) {

	zval _4$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *extension_param = NULL, *quality_param = NULL, __$false, tmp, save, type, _2, _6, _0$$3, _3$$7, _5$$7;
	zval extension, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&save);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_4$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(extension)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &extension_param, &quality_param);

	zephir_get_strval(&extension, extension_param);
	quality = zephir_get_intval(quality_param);


	if (!(!(Z_TYPE_P(&extension) == IS_UNDEF) && Z_STRLEN_P(&extension))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&tmp, "image_type_to_extension", NULL, 57, &_0$$3, &__$false);
		zephir_check_call_status();
		zephir_get_strval(&_1$$3, &tmp);
		ZEPHIR_CPY_WRT(&extension, &_1$$3);
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strtolower(&_2, &extension);
	do {
		if (ZEPHIR_IS_STRING(&_2, "jpg") || ZEPHIR_IS_STRING(&_2, "jpeg")) {
			ZEPHIR_INIT_VAR(&save);
			ZVAL_STRING(&save, "imagejpeg");
			ZEPHIR_INIT_VAR(&type);
			ZVAL_LONG(&type, 2);
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "gif")) {
			ZEPHIR_INIT_NVAR(&save);
			ZVAL_STRING(&save, "imagegif");
			ZEPHIR_INIT_NVAR(&type);
			ZVAL_LONG(&type, 1);
			quality = 0;
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "png")) {
			ZEPHIR_INIT_NVAR(&save);
			ZVAL_STRING(&save, "imagepng");
			ZEPHIR_INIT_NVAR(&type);
			ZVAL_LONG(&type, 3);
			quality = 9;
			break;
		}
		ZEPHIR_INIT_VAR(&_3$$7);
		object_init_ex(&_3$$7, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$7);
		zephir_create_array(&_4$$7, 2, 0);
		ZEPHIR_INIT_VAR(&_5$$7);
		ZVAL_STRING(&_5$$7, "Installed GD does not support %s images");
		zephir_array_fast_append(&_4$$7, &_5$$7);
		zephir_array_fast_append(&_4$$7, &extension);
		ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", NULL, 12, &_4$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$7, "ice/image/gd.zep", 627);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	zephir_create_array(return_value, 3, 0);
	zephir_array_fast_append(return_value, &save);
	zephir_array_fast_append(return_value, &type);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_LONG(&_6, quality);
	zephir_array_fast_append(return_value, &_6);
	RETURN_MM();

}

/**
 * Create an empty image with the given width and height.
 *
 * @param integer width Image width
 * @param integer height Image height
 *
 * @return resource
 */
PHP_METHOD(Ice_Image_Gd, create) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, __$false, __$true, image, _0, _1;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZVAL_LONG(&_0, width);
	ZVAL_LONG(&_1, height);
	ZEPHIR_CALL_FUNCTION(&image, "imagecreatetruecolor", NULL, 170, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 167, &image, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 153, &image, &__$true);
	zephir_check_call_status();
	RETURN_CCTOR(&image);

}

