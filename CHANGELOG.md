-------------------------------------------------------------------
Wed Jan 16 13:15:56 UTC 2019

- Ice 1.4.1
 * Build, add support for php 7.3 fix #251
 * Model, remove primary keys
 * Composer, update zephir to 0.11.9
 * Pdo, fixed sql error if emtpy filter
 * Model, refresh new data after update
 * Router, default router fix

-------------------------------------------------------------------
Tue Oct 30 07:19:50 UTC 2018

- Ice 1.4.0
 * Exception, add a hook for pretty exceptions, fix #234
 * Session, robust start a session
 * Pdo, fixed things for different DBMS
 * Response, add toJson and toXml
 * Db, Model, rename the remove method to delete fix #221
 * Env, add environment helper
 * Auth, token enhancement, rename Model driver to Db
 * Router, refactor, rename old router to FastRouter
 * Auth, password hash enhancement
 * Di, hook bug fixed #208
 * Model, clear save status #205
 * Pdo, add query method fix #166
 * Model, fixed retry to save invalid model bug #202
 * Cli, add websocket component #201
 * Auth, make model classes in users configurable #199
 * Request, allow for empty string on get, post #197
 * Model, enhanced and bugs fix #185
 * Pdo, make it competitable with other dbms #188
 * Di, resolve bug fix #190
 * View, allow to render file with specific engine
 * Tests, add db and model tests
 * Dispatcher, add reset
 * Always return this from setters
 * Response, send file
 * App, add new module to the app
 * App, allow to render page without main layout fix #169
 * Response, set response content in controller fail fix #168
 * Request, implement interface
 * Config, load config from php file
 * PHP, fix declaration errors
 * Travis, update to xenial dist
 * Composer, use zephir v0.11.0 and zephir-parser v1.1.2
 * View, stop finding view when it meets the right engine and file
 * Modules, use loader from di and pass it to autoloaders fix #156
 * Loader, no namespace classes loading for the loader fix #154

-------------------------------------------------------------------
Sun Mar 25 12:26:06 UTC 2018

- Ice 1.3.0
 * Model, add db service name as a property
 * Db, add options, oracle fix #150
 * Dump, use the reflection class instead of each function
 * PHP 5.5, drop support
 * Travis, enable PHP 7.2, remove legacy mongo
 * Composer, use working zephir
 * Assets, memory observe fix phalcon/zephir#1538

-------------------------------------------------------------------
Sat May 20 12:38:11 UTC 2017

- Ice 1.2.11
 * Tag, make public input
 * Db, fix mongo driver

-------------------------------------------------------------------
Thu Mar 30 22:10:11 UTC 2017

- Ice 1.2.10
 * Auth, facebook fix

-------------------------------------------------------------------
Fri Feb 24 00:26:18 UTC 2017

- Ice 1.2.9
 * Unique validator, fix mongodb

-------------------------------------------------------------------
Sat Feb 18 18:50:05 UTC 2017

- Ice 1.2.8
 * Facebook, add fields to API call

-------------------------------------------------------------------
Sat Feb 18 15:05:57 UTC 2017

- Ice 1.2.7
 * Social auth, get scope from options, use static url

-------------------------------------------------------------------
Fri Feb 10 21:20:56 UTC 2017

- Ice 1.2.6
 * Unique, fix mongodb driver
 * Mongodb, fix timestamp if value is NULL on getDateTime
 * Tag, add end_form()
 * Validators, update doc
 * Validation, fix revalidate, add more tests

-------------------------------------------------------------------
Sun Jan 22 18:57:00 UTC 2017

- Ice 1.2.5
 * Model, set rules if there is no validation rules on create
 * Unique, fix case insensitive on mongodb
 * Url, fix uri starts with # or ?
 * Fix memory leak in preg_match
 * Auth, add force login

-------------------------------------------------------------------
Sun Jan 15 18:05:25 UTC 2017

- Ice 1.2.4
 * Model, add autoincrement property

-------------------------------------------------------------------
Sun Jan  8 18:39:44 UTC 2017

- Ice 1.2.3
 * Mongodb, timestamp fix

-------------------------------------------------------------------
Sat Nov 19 15:14:58 UTC 2016

- Ice 1.2.2
 * DB, detect timestamp on toDateTime
 * Exception, allow for Throwable in PHP7

-------------------------------------------------------------------
Sat Nov 12 10:30:34 UTC 2016

- Ice 1.2.1
 * Db, remove legacy mongo from php 7
 * Digit validator, allow for int
 * Dump, add plain text attribute
 * Model, get date time
 * Mongodb, result as associative array

-------------------------------------------------------------------
Mon Aug 29 11:42:20 UTC 2016

- Ice 1.2.0
 * Db, add mongodb driver
 * Validation, translate fields on With validator fix #123
 * Url, uri starts with // fix #121

-------------------------------------------------------------------
Wed Jun 15 13:24:17 UTC 2016

- Ice 1.1.5
 * Router, fastRoute code improvements
 * Di, fix url auto-resolving
 * Response, move messages to function, remove di property
 * Router, add default routes, remove di property
 * Dump, add skip di property
 * FastRoute, fix #120 and update to nikic/FastRoute@30470b6
 * Copyright, update year
 * Sleet, allow for multi-line tags, fix #118

-------------------------------------------------------------------
Fri Jun  3 08:57:28 UTC 2016

- Ice 1.1.4
 * Pdo, change where to protected, fix #116
 * View, add setLayout alias of setMainView
 * Response, detect redirect loop
 * Assets, add collections
 * Tag, allow to clear meta tags
 * Flash, allow to overwrite options later
 * Validation, merge revalidate into validate
 * Validation, add revalidate method
 * Tag, Pagination, services are predefined
 * Validation, use arr object to store data
 * Arr, add only() and getValue() methods
 * View, looking for a view in multiple dirs if viewsDir is an array
 * Build, change directories to lowercase

-------------------------------------------------------------------
Tue Apr 26 08:00:11 UTC 2016

- Ice 1.1.3
 * Loader, fix php7 refcount zephir/issues/1140
 * Pagination, get current URL if uri is false

-------------------------------------------------------------------
Fri Mar 11 10:12:42 UTC 2016

- Ice 1.1.2
 * Dispatcher, add limit of forwards
 * Sleet parser, add NEW, INSTANCEOF tokens
 * File validator, doc fix
 * Pagination, add ability to change li, a, span HTML class
 * Filter, add boolean filter

-------------------------------------------------------------------
Sat Jan 30 15:34:07 UTC 2016

- Ice 1.1.1
 * Di, return null if type of service is null
 * Crypt, use setter
 * Pdo, add detecting IN condition, fix #102

-------------------------------------------------------------------
Tue Jan 26 11:20:40 UTC 2016

- Ice 1.1.0
 * Services, update to auto-resolving
 * Text, remove static from random method
 * Di, add auto-resolving services and constructor parameter fix #99

-------------------------------------------------------------------
Sun Jan  3 13:53:41 UTC 2016

- Ice 1.0.37
 * The json-c is not needed anymore
 * Tag, fix #97 overwrite radio values
 * Install extension, cd fix
 * Update readme
 * Travis, update token
 * Travis, zephir fullclean is unnecessary
 * Build, get only generated files by zephir
 * Ignore ext/ directory
 * Delete ext/ directory
 * Travis, implement automated source regenerating

-------------------------------------------------------------------
Thu Nov 26 13:15:06 UTC 2015

- Ice 1.0.36
 * Core, use the latest zephir
 * Pdo, don't require pdo extension to build/run ice
 * Auth social, allow to store twitter access token in the session

-------------------------------------------------------------------
Thu Nov  5 12:36:03 UTC 2015

- Ice 1.0.35
 * Mvc, add service

-------------------------------------------------------------------
Fri Oct 16 11:58:34 UTC 2015

- Ice 1.0.34
 * Unique, add case insensitive

-------------------------------------------------------------------
Wed Oct 14 13:37:38 UTC 2015

- Ice 1.0.33
 * Pagination, first page fix

-------------------------------------------------------------------
Tue Oct  6 15:28:35 UTC 2015

- Ice 1.0.32
 * Model, unset primary key on create
 * Model, don't unset primary keys on multi column

-------------------------------------------------------------------
Fri Oct  2 13:13:25 UTC 2015

- Ice 1.0.31
 * Travis, remove valgrind
 * Travis, migrate to new container infrastructure
 * Core, use the latest zephir

-------------------------------------------------------------------
Fri Oct  2 09:06:39 UTC 2015

- Ice 1.0.30
 * Model, update and valid fields to save

-------------------------------------------------------------------
Tue Sep 29 09:33:20 UTC 2015

- Ice 1.0.29
 * Console, fix argument 1 passed to `construct()` must be an instance of Ice\Cli\Di
 * Model, create/update improvements

-------------------------------------------------------------------
Fri Sep 11 09:55:05 UTC 2015

- Ice 1.0.28
 * Access, register the app/console itself as a service
 * Model, add options for loadOne findOne

-------------------------------------------------------------------
Sat Sep  5 10:54:31 UTC 2015

- Ice 1.0.27
 * Dispatcher, gets variable from params attribute applying filters if needed
 * Model, allow to apply Validation on update, fetch validation's values on create
 * Auth File, return Arr object on getUser()
 * Pagination, move the repeated data to the prepareButton method

-------------------------------------------------------------------
Mon Aug 31 08:17:27 UTC 2015

- Ice 1.0.26
 * Auth, return null if user not found during login
 * Db, create driver for given options

-------------------------------------------------------------------
Wed Aug 19 16:52:40 UTC 2015

- Ice 1.0.25
 * Assets, fix option name for source

-------------------------------------------------------------------
Wed Aug 19 13:36:47 UTC 2015

- Ice 1.0.24
 * Tag, add meta tag

-------------------------------------------------------------------
Tue Aug 18 02:00:45 UTC 2015

- Ice 1.0.23
 * Model, findOne make sure to return false if result not found
 * Dispatcher, forward force backward compatibility
 * Dispatcher, add force forward option

-------------------------------------------------------------------
Wed Aug  5 13:10:08 UTC 2015

- Ice 1.0.22
 * Response, return object on redirect

-------------------------------------------------------------------
Mon Aug  3 11:31:59 UTC 2015

- Ice 1.0.21
 * Url, mailto fix
 * Model, add options on getRelated method

-------------------------------------------------------------------
Thu Jul 30 14:44:19 UTC 2015

- Ice 1.0.20
 * Assets, add forceMinified option

-------------------------------------------------------------------
Thu Jul 30 15:13:21 UTC 2015

- Ice 1.0.19
 * Assets, do not add a version if not specified
 * Filter js, clear the output
 * Assets, add helper to manage css/js resources
 * Filter, implement jsmin

-------------------------------------------------------------------
Thu Jul 23 11:17:58 UTC 2015

- Ice 1.0.18
 * Validation, add getValues method for getting all filtered values

-------------------------------------------------------------------
Wed Jul 22 17:22:22 UTC 2015

- Ice 1.0.17
 * Dump, skip debuging di, fix detecting private/protected properties

-------------------------------------------------------------------
Sat Jul 18 14:42:04 UTC 2015

- Ice 1.0.16
 * Zephir, use the working wersion
 * Route, update fast route to the latest commit
 * Model, add getRules method

-------------------------------------------------------------------
Sat Jun 27 08:09:22 UTC 2015

- Ice 1.0.15
 * PSR-2, Properties name should not be prefixed with an underscore to indicate visibility

-------------------------------------------------------------------
Fri Jun 26 13:00:45 UTC 2015

- Ice 1.0.14
 * Session, PHP Strict Standards fix
 * Tag, add radio input
 * Validation, docs & examples fixes

-------------------------------------------------------------------
Sun Jun  7 08:55:44 UTC 2015

- Ice 1.0.13
 * Mongo, select document by MongoId
 * Validation, add doc with examples
 * Tag, add doc with examples

-------------------------------------------------------------------
Thu May  7 10:58:30 UTC 2015

- Ice 1.0.12
 * Response, add setContent method
 * Mvc app, get the response from handler

-------------------------------------------------------------------
Tue May  5 18:14:45 UTC 2015

- Ice 1.0.11
 * Filter, get propper type fix #58
 * Unique validator, mongo id fix #59

- Ice 1.0.10
 * FastRoute, cached dispatcher fix

- Ice 1.0.9
 * Di, improve performance on getting services & use the latest Zephir

-------------------------------------------------------------------
Fri Apr 10 15:56:09 UTC 2015

- Ice 1.0.8
 * Core, use the latest zephir
 * Auth, improvements for mongo driver
 * I18n, add global alias to translate function

-------------------------------------------------------------------
Tue Apr  7 06:33:40 UTC 2015

- Ice 1.0.7
 * Di, set root path in the constructor
 * Back to working zephir

-------------------------------------------------------------------
Sat Mar 28 14:18:14 UTC 2015

- Ice 1.0.6
 * Model, change serialize/unserialize to json_encode/json_decode, fix #37
 * Exception, add getFullTraceAsString method

-------------------------------------------------------------------
Thu Mar 26 18:04:16 UTC 2015

- Ice 1.0.5
 * Config ini, better decode values due to parse_ini_file() has a poor implementation
 * Mongo driver, compatybility with Pdo
 * Get the latest Zephir

-------------------------------------------------------------------
Fri Mar 20 08:24:40 UTC 2015

- Ice 1.0.4
 * Db, mongo driver fixes

-------------------------------------------------------------------
Fri Mar  6 10:07:19 UTC 2015

- Ice 1.0.3
 * Module, simplify declaration of one module application

-------------------------------------------------------------------
Wed Mar  4 13:37:43 UTC 2015

- Ice 1.0.2
 * Config, constructor improvements
 * Travis, try to add PHP 7
 * FastRoute, support adding the same route for multiple HTTP methods

-------------------------------------------------------------------
Mon Mar  2 14:32:50 UTC 2015

- Ice 1.0.1
 * I18n, translate with different contexts eg. for male/female or plural form

-------------------------------------------------------------------
Thu Feb 26 12:13:16 UTC 2015

- Ice 1.0.0
 * Get the latest zephir

-------------------------------------------------------------------
Tue Feb 17 18:31:09 UTC 2015

- Ice 1.0.0-rc3
 * Auth social, allow refreshing access token from google & facebook

-------------------------------------------------------------------
Tue Feb 17 11:08:02 UTC 2015

- Ice 1.0.0-rc2
 * Social model, fix alias
 * PHPDoc, fix examples in `code`

-------------------------------------------------------------------
Mon Feb 16 15:29:16 UTC 2015

- Ice 1.0.0-rc1
 * Auth, add sign in with Facebook, Google, Twitter
 * Composer, update phpunit
 * Readme, add badges

-------------------------------------------------------------------
Thu Feb  5 17:34:46 UTC 2015

- Ice 1.0.0-beta2
 * Model, unserialize fix #37
 * Model, validation's getMessages returns Arr object

-------------------------------------------------------------------
Fri Jan 30 15:41:15 UTC 2015

- Ice 1.0.0-beta1
 * Get the latest zephir, Model, add extra validation on update
 * Documentation, add some comments for the PHPDoc
 * Travis, run gdb after faliure
 * Exception, exit with 1 after handle

-------------------------------------------------------------------
Sun Jan 25 10:24:40 UTC 2015

- Ice 1.0.0-alpha2
 * Auth, logout and remove all tokens for user

-------------------------------------------------------------------
Sat Jan 24 23:28:06 UTC 2015

- Ice dev build 25012015
 * Exception, add handlers for error/exception/shutdown

-------------------------------------------------------------------
Sun Jan 11 19:07:46 UTC 2015

- Ice 1.0.0-alpha1
 * Version, Ice 1.0.0-alpha1
 * Request, remove _url from GET during getQuery
 * Pagination, translate improvements
 * Validation, move translate into validators
 * Tests, sleet parser skip tag
 * View, angular fix, add comment block
 * Model, unset primary key on create/update

-------------------------------------------------------------------
Fri Dec 19 09:27:56 UTC 2014

- Ice dev build 19122014
 * Auth, fix delete expired tokens
 * Filter, minify css and base for minify js
 * I18n, add iso method
 * Unique validator fix
 * App, add hooks
 * Flash, getMessage fix

-------------------------------------------------------------------
Fri Dec 12 15:34:07 UTC 2014

- Ice dev build 12122014
 * Console, add colored echo and improvements to CLI router
 * App, remove unnecessary declaration
 * Dispatcher, move module settings to the dispatcher
 * PDO, return false if row is not fetched
 * Tag, use url service if available
 * Filter, repeats fix
 * PDO, order by typo fix

-------------------------------------------------------------------
Tue Dec  9 14:25:34 UTC 2014

- Ice dev build 09122014
 * Sleet parser, short if and functions fix
 * CLI response fix, remove defaultModule from App
 * Validation, file validator message
 * Model, apply custom validation and filters
 * Validation, translate labels and doc
 * Request, add hasFile() method
 * Tag, autocheck fix

-------------------------------------------------------------------
Sat Dec  6 12:25:05 UTC 2014

- Ice dev build 06122014
 * Di fetch, remove DiInterface
 * Pagination improvements
 * Tag, HTML `select` Tag

-------------------------------------------------------------------
Thu Dec  4 14:56:32 UTC 2014

- Ice dev build 04122014

-------------------------------------------------------------------
Sat Nov 29 10:49:20 UTC 2014

- Ice dev build 29112014v2

-------------------------------------------------------------------
Thu Nov 27 08:37:47 UTC 2014

- Ice dev build 27112014

-------------------------------------------------------------------
Mon Nov 17 21:40:17 UTC 2014

- Ice release 1.0.0dev 17112014

-------------------------------------------------------------------
Sat Nov 15 07:42:31 UTC 2014

- Ice release 1.0.0dev 15112014

-------------------------------------------------------------------
Sat Nov 15 07:35:12 UTC 2014

- Ice release 1.0.0-dev 15112014
