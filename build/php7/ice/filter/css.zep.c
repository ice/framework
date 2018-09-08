
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
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * Minify css string.
 *
 * @package     Ice/Filter
 * @category    Minification
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        cssmin.c www.ryanday.org
 */
ZEPHIR_INIT_CLASS(Ice_Filter_Css) {

	ZEPHIR_REGISTER_CLASS(Ice\\Filter, Css, ice, filter_css, ice_filter_css_method_entry, 0);

	zephir_declare_class_constant_long(ice_filter_css_ce, SL("FREE"), 1);

	zephir_declare_class_constant_long(ice_filter_css_ce, SL("ATRULE"), 2);

	zephir_declare_class_constant_long(ice_filter_css_ce, SL("SELECTOR"), 3);

	zephir_declare_class_constant_long(ice_filter_css_ce, SL("BLOCK"), 4);

	zephir_declare_class_constant_long(ice_filter_css_ce, SL("DECLARATION"), 5);

	zephir_declare_class_constant_long(ice_filter_css_ce, SL("COMMENT"), 6);

	return SUCCESS;

}

/**
 * Minify the css.
 * Removes comments, removes newlines and line feeds keeping, removes last semicolon from last property
 *
 * @param string css CSS code to minify
 * @return string
 */
PHP_METHOD(Ice_Filter_Css, sanitize) {

	unsigned char _2$$3;
	zend_bool _1$$3, _3$$5, _4$$7, _5$$11, _6$$16, _7$$19, _8$$33;
	long _0;
	zend_long i = 0, tmp = 0, state, inParen;
	char c = 0, next = 0;
	zval *css_param = NULL;
	zval css, min;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&css);
	ZVAL_UNDEF(&min);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &css_param);

	zephir_get_strval(&css, css_param);


	ZEPHIR_INIT_VAR(&min);
	ZVAL_STRING(&min, "");
	state = 1;
	inParen = 0;
	for (_0 = 0; _0 < Z_STRLEN_P(&css); _0++) {
		i = _0; 
		c = ZEPHIR_STRING_OFFSET(&css, _0);
		next = ZEPHIR_STRING_OFFSET(&css, (i + 1));
		next = next;
		_1$$3 = c == '/';
		if (_1$$3) {
			_2$$3 = ZEPHIR_STRING_OFFSET(&css, (i - 1));
			_1$$3 = _2$$3 == '*';
		}
		if (_1$$3) {
			continue;
		}
		if (state != 6) {
			_3$$5 = c == '/';
			if (_3$$5) {
				_3$$5 = next == '*';
			}
			if (_3$$5) {
				tmp = state;
				state = 6;
			}
		}
		do {
			if (state == 1) {
				_4$$7 = c == ' ';
				if (_4$$7) {
					_4$$7 = c == '\n';
				}
				if (_4$$7) {
					c = 0;
				} else if (c == '@') {
					state = 2;
					break;
				} else if (c > 0) {
					state = 3;
				}
			}
			if (state == 3) {
				_5$$11 = c == ' ';
				if (_5$$11) {
					_5$$11 = next == '{';
				}
				if (c == '{') {
					state = 4;
				} else if (c == '\n') {
					c = 0;
				} else if (c == '@') {
					state = 2;
				} else if (_5$$11) {
					c = 0;
				}
				break;
			}
			if (state == 2) {
				_6$$16 = c == '\n';
				if (!(_6$$16)) {
					_6$$16 = c == ';';
				}
				if (_6$$16) {
					c = ';';
					state = 1;
				} else if (c == '{') {
					state = 4;
				}
				break;
			}
			if (state == 4) {
				_7$$19 = c == ' ';
				if (!(_7$$19)) {
					_7$$19 = c == '\n';
				}
				if (_7$$19) {
					c = 0;
					break;
				} else if (c == '}') {
					state = 1;
					break;
				} else {
					state = 5;
				}
			}
			if (state == 5) {
				if (c == '(') {
					inParen = 1;
				}
				if (inParen == 0) {
					if (c == ';') {
						state = 4;
						if (next == '}') {
							c = 0;
						}
					} else if (c == '}') {
						state = 1;
					} else if (c == '\n') {
						c = 0;
					} else if (c == ' ') {
						if (next == c) {
							c = 0;
						}
					}
				} else if (c == ')') {
					inParen = 0;
				}
				break;
			}
			if (state == 6) {
				_8$$33 = c == '*';
				if (_8$$33) {
					_8$$33 = next == '/';
				}
				if (_8$$33) {
					state = tmp;
				}
				c = 0;
				break;
			}
		} while(0);

		if (c != 0) {
			zephir_concat_self_char(&min, c TSRMLS_CC);
		}
	}
	RETURN_CTOR(&min);

}

