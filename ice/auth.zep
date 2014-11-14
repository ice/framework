
namespace Ice;

/**
 * User authorization library. Handles user login and logout, as well as secure password hashing.
 *
 *<code>
 *  $options = ['hash_key' => 'secret key'];
 *  $this->di->auth = new \Ice\Auth($options);
 *
 *  $login = $this->auth->login($this->request->getPost('username'), $this->request->getPost('password'), $this->request->getPost('remember') ? TRUE : FALSE);
 *  if (!$login) {
 *      // Login failed, send back to form with error message
 *  } else {
 *      // Login successful
 *  }
 *</code>
 *
 *<code>
 *  if ($this->auth->loggedIn()) {
 *      // User is logged in, continue on
 *      $user = $this->auth->getUser();
 *      $username = $user->username;
 *  } else {
 *      // User isn't logged in, redirect to the login form.
 *  }
 *</code>
 *
 *<code>
 *  if ($this->auth->loggedIn('admin')) {
 *      // Admin privileges
 *  } else {
 *      // No access
 *  }
 *</code>
 *
 *<code>
 *  // Log out a user
 *  $this->auth->logout();
 *</code>
 */
class Auth
{
    
}