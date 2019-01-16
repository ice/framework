
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_ICE_H
#define PHP_ICE_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_ICE_NAME        "ice"
#define PHP_ICE_VERSION     "1.4.1"
#define PHP_ICE_EXTNAME     "ice"
#define PHP_ICE_AUTHOR      "Ice Team"
#define PHP_ICE_ZEPVERSION  "0.11.9-$Id$"
#define PHP_ICE_DESCRIPTION "Simple and fast PHP framework delivered as C-extension.<br>Copyright (c) 2014-2018 Ice Team."



ZEND_BEGIN_MODULE_GLOBALS(ice)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(ice)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(ice)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(ice_globals_id, zend_ice_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (ice_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_ice_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(ice_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(ice_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def ice_globals
#define zend_zephir_globals_def zend_ice_globals

extern zend_module_entry ice_module_entry;
#define phpext_ice_ptr &ice_module_entry

#endif
