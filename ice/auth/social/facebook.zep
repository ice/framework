
namespace Ice\Auth\Social;

/**
 * Facebook Auth social adapter.
 *
 * @package     Ice/Auth
 * @category    Adapter
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Facebook extends Adapter
{

    /**
     * Facebook adapter constructor.
     *
     * @param array config
     */
    public function __construct(config = [])
    {
        let this->provider = "facebook";

        parent::__construct(config);

        let this->socialFieldsMap = [
            "socialId":   "id",
            "email":      "email",
            "name":       "name",
            "sex":        "gender",
            "socialPage": "link",
            "birthday":   "birthday"
        ];
    }

    /**
     * Get url of user's avatar or null if it is not set.
     *
     * @return string|null
     */
    public function getImage()
    {
        if this->has("id") {
            return "http://graph.facebook.com/" . this->get("id") . "/picture?type=large";
        }

        return null;
    }

    /**
     * Authenticate and return bool result of authentication.
     *
     * @return bool
     */
    public function authenticate()
    {
        var result, params, tokenInfo, userInfo;

        let result = false;

        if isset _GET["code"] {
            let params = [
                "client_id":     this->clientId,
                "redirect_uri":  this->redirectUri,
                "client_secret": this->clientSecret,
                "code":          _GET["code"]
            ];

            // Be able to store access_token in the session (message: This_authorization_code_has_expired_)
            if !this->accessToken {
                let tokenInfo = this->call(parent::GET, "https://graph.facebook.com/oauth/access_token", params);

                if isset tokenInfo["access_token"] {
                    let this->accessToken = tokenInfo["access_token"];
                }
            }

            if this->accessToken {
                let params = [
                    "access_token": this->accessToken,
                    "fields": this->getOption("fields", "id,name,email,gender,link,verified,first_name,last_name,birthday,locale,timezone")
                ],
                    userInfo = this->call(parent::GET, "https://graph.facebook.com/me", params);

                if isset userInfo[this->socialFieldsMap["socialId"]] {
                    let this->userInfo = userInfo,
                        result = true;
                }
            }
        }
        return result;
    }

    /**
     * Prepare params for authentication url.
     *
     * @return array
     */
    public function prepareAuthParams()
    {
        return [
            "auth_url":    "https://www.facebook.com/dialog/oauth",
            "auth_params": [
                "client_id":     this->clientId,
                "redirect_uri":  this->redirectUri,
                "response_type": "code",
                "scope":         this->getOption("scope", "email,public_profile")
            ]
        ];
    }
}
