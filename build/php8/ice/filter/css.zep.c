
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
#include "kernel/string.h"
#include "kernel/object.h"


/**
 * Minify css string.
 *
 * @package     Ice/Filter
 * @category    Minification
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 * @uses        cssmin.c www.ryanday.org
 */
ZEPHIR_INIT_CLASS(Ice_Filter_Css)
{
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
PHP_METHOD(Ice_Filter_Css, sanitize)
{
	zend_bool _1$$3, _2$$6, _3$$8, _4$$12, _5$$17, _6$$20, _7$$34;
	zend_long _0;
	zend_long i = 0, tmp, state, inParen;
	char c = 0, next = 0, prev = 0;
	zval min;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval css_zv;
	zend_string *css = NULL;

	ZVAL_UNDEF(&css_zv);
	ZVAL_UNDEF(&min);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(css)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&css_zv);
	ZVAL_STR_COPY(&css_zv, css);
	ZEPHIR_INIT_VAR(&min);
	ZVAL_STRING(&min, "");
	tmp = 0;
	state = 1;
	inParen = 0;
	for (_0 = 0; _0 < Z_STRLEN_P(&css_zv); _0++) {
		i = _0; 
		c = ZEPHIR_STRING_OFFSET(&css_zv, _0);
		next = zephir_string_offset_byte(&css_zv, (i + 1), PH_NOISY);
		next = next;
		prev = 0;
		if (i > 0) {
			prev = zephir_string_offset_byte(&css_zv, (i - 1), PH_NOISY);
			prev = prev;
		}
		_1$$3 = c == '/';
		if (_1$$3) {
			_1$$3 = prev == '*';
		}
		if (_1$$3) {
			continue;
		}
		if (state != 6) {
			_2$$6 = c == '/';
			if (_2$$6) {
				_2$$6 = next == '*';
			}
			if (_2$$6) {
				tmp = state;
				state = 6;
			}
		}
		if (state == 1) { goto zephir_switch_0_clause_0; }
		if (state == 3) { goto zephir_switch_0_clause_1; }
		if (state == 2) { goto zephir_switch_0_clause_2; }
		if (state == 4) { goto zephir_switch_0_clause_3; }
		if (state == 5) { goto zephir_switch_0_clause_4; }
		if (state == 6) { goto zephir_switch_0_clause_5; }
		goto zephir_switch_0_end;
		zephir_switch_0_clause_0: ;
			_3$$8 = c == ' ';
			if (_3$$8) {
				_3$$8 = c == '\n';
			}
			if (_3$$8) {
				c = 0;
			} else if (c == '@') {
				state = 2;
				goto zephir_switch_0_end;
			} else if (c > 0) {
				state = 3;
			}
		zephir_switch_0_clause_1: ;
			if (c == '{') {
				state = 4;
			} else if (c == '\n') {
				c = 0;
			} else if (c == '@') {
				state = 2;
			} else {
				_4$$12 = c == ' ';
				if (_4$$12) {
					_4$$12 = next == '{';
				}
				if (_4$$12) {
					c = 0;
				}
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_2: ;
			_5$$17 = c == '\n';
			if (!(_5$$17)) {
				_5$$17 = c == ';';
			}
			if (_5$$17) {
				c = ';';
				state = 1;
			} else if (c == '{') {
				state = 4;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_3: ;
			_6$$20 = c == ' ';
			if (!(_6$$20)) {
				_6$$20 = c == '\n';
			}
			if (_6$$20) {
				c = 0;
				goto zephir_switch_0_end;
			} else if (c == '}') {
				state = 1;
				goto zephir_switch_0_end;
			} else {
				state = 5;
			}
		zephir_switch_0_clause_4: ;
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
			goto zephir_switch_0_end;
		zephir_switch_0_clause_5: ;
			_7$$34 = c == '*';
			if (_7$$34) {
				_7$$34 = next == '/';
			}
			if (_7$$34) {
				state = tmp;
			}
			c = 0;
			goto zephir_switch_0_end;
		zephir_switch_0_end: ;

		if (c != 0) {
			zephir_concat_self_char(&min, c);
		}
	}
	RETURN_CTOR(&min);
}

