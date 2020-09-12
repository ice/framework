
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_ICE_H
#define PHP_ICE_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_ICE_NAME        "ice"
#define PHP_ICE_VERSION     "1.6.2"
#define PHP_ICE_EXTNAME     "ice"
#define PHP_ICE_AUTHOR      "Ice Team"
#define PHP_ICE_ZEPVERSION  "0.12.18-$Id$"
#define PHP_ICE_DESCRIPTION "Simple and fast PHP framework delivered as C-extension.<br>Copyright (c) 2014-2020 Ice Team."



ZEND_BEGIN_MODULE_GLOBALS(ice)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
	zend_bool cli_colors;


ZEND_END_MODULE_GLOBALS(ice)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(ice)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(ice, v)
#else
	#define ZEPHIR_GLOBAL(v) (ice_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_ice_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(ice_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(ice_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def ice_globals
#define zend_zephir_globals_def zend_ice_globals

extern zend_module_entry ice_module_entry;
#define phpext_ice_ptr &ice_module_entry

#endif
