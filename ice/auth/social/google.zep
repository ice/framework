
namespace Ice\Auth\Social;

/**
 * Google Auth social adapter.
 *
 * @package     Ice/Auth
 * @category    Adapter
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Google extends Adapter
{

    /**
     * Google adapter constructor.
     *
     * @param array config
     */
    public function __construct(config = [])
    {
        let this->_provider = "google";

        parent::__construct(config);

        let this->_socialFieldsMap = [
            "socialId":   "id",
            "email":      "email",
            "name":       "name",
            "sex":        "gender",
            "socialPage": "link",
            "image":      "picture"
        ];
    }

    /**
     * Get user birthday or null if it is not set
     *
     * @return string|null
     */
    public function getBirthday()
    {
        if this->has("birthday") {
            let this->_userInfo["birthday"] = str_replace("0000", date("Y"), this->_userInfo["birthday"]);

            return date("d.m.Y", strtotime(this->_userInfo["birthday"]));
        }

        return null;
    }

    /**
     * Authenticate and return bool result of authentication
     *
     * @return bool
     */
    public function authenticate()
    {
        var result, params, tokenInfo, userInfo;

        let result = false;

        if isset _GET["code"] {
            let params = [
                "client_id":     this->_clientId,
                "client_secret": this->_clientSecret,
                "redirect_uri":  this->_redirectUri,
                "grant_type":    "authorization_code",
                "code":          _GET["code"]
            ];

            // Be able to store access_token in the session (invalid_grant: Code was already redeemed)
            if !this->_accessToken {
                let tokenInfo = this->call(parent::POST, "https://accounts.google.com/o/oauth2/token", params);

                if isset tokenInfo["access_token"] {
                    let this->_accessToken = tokenInfo["access_token"];
                }
            }

            if this->_accessToken {
                let params["access_token"] = this->_accessToken,
                    userInfo = this->call(parent::GET, "https://www.googleapis.com/oauth2/v1/userinfo", params);

                if isset userInfo[this->_socialFieldsMap["socialId"]] {
                    let this->_userInfo = userInfo,
                        result = true;
                }
            }
        }
        return result;
    }

    /**
     * Prepare params for authentication url
     *
     * @return array
     */
    public function prepareAuthParams()
    {
        return [
            "auth_url":    "https://accounts.google.com/o/oauth2/auth",
            "auth_params": [
                "redirect_uri":  this->_redirectUri,
                "response_type": "code",
                "client_id":     this->_clientId,
                "scope":         "https://www.googleapis.com/auth/userinfo.email https://www.googleapis.com/auth/userinfo.profile"
            ]
        ];
    }
}
