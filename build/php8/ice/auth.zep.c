
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


/**
 * User authorization library. Handles user login and logout, as well as secure password hashing.
 *
 * @package     Ice/Auth
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $options = ['hash_key' => 'secret key'];
 *  $this->di->auth = new \Ice\Auth($options);
 *
 *  $login = $this->auth->login($this->request->getPost('username'), $this->request->getPost('password'), $this->request->getPost('remember') ? TRUE : FALSE);
 *  if (!$login) {
 *      // Login failed, send back to form with error message
 *  } else {
 *      // Login successful
 *  }
 * </code></pre>
 *
 * <pre><code>
 *  if ($this->auth->loggedIn()) {
 *      // User is logged in, continue on
 *      $user = $this->auth->getUser();
 *      $username = $user->username;
 *  } else {
 *      // User isn't logged in, redirect to the login form.
 *  }
 * </code></pre>
 *
 * <pre><code>
 *  if ($this->auth->loggedIn('admin')) {
 *      // Admin privileges
 *  } else {
 *      // No access
 *  }
 * </code></pre>
 *
 * <pre><code>
 *  // Log out a user
 *  $this->auth->logout();
 * </code></pre>
 *
 * Seet usage:
 * <pre><code>
 *  {% if this.auth.loggedIn() %}
 *      {{ this.auth.getUser().username }}
 *  {% endif %}
 * </code></pre>
 */
ZEPHIR_INIT_CLASS(Ice_Auth)
{
	ZEPHIR_REGISTER_CLASS(Ice, Auth, ice, auth, NULL, 0);

	return SUCCESS;
}

