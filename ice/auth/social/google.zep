
namespace Ice\Auth\Social;

/**
 * Google Auth social adapter.
 *
 * @package     Ice/Auth
 * @category    Adapter
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
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
        let this->provider = "google";

        parent::__construct(config);

        let this->socialFieldsMap = [
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
            let this->userInfo["birthday"] = str_replace("0000", date("Y"), this->userInfo["birthday"]);

            return date("d.m.Y", strtotime(this->userInfo["birthday"]));
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
                "client_id":     this->clientId,
                "client_secret": this->clientSecret,
                "redirect_uri":  this->redirectUri,
                "grant_type":    "authorization_code",
                "code":          _GET["code"]
            ];

            // Be able to store access_token in the session (invalid_grant: Code was already redeemed)
            if !this->accessToken {
                let tokenInfo = this->call(parent::POST, "https://accounts.google.com/o/oauth2/token", params);

                if isset tokenInfo["access_token"] {
                    let this->accessToken = tokenInfo["access_token"];
                }
            }

            if this->accessToken {
                let params["access_token"] = this->accessToken,
                    userInfo = this->call(parent::GET, "https://www.googleapis.com/oauth2/v1/userinfo", params);

                if isset userInfo[this->socialFieldsMap["socialId"]] {
                    let this->userInfo = userInfo,
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
                "redirect_uri":  this->redirectUri,
                "response_type": "code",
                "client_id":     this->clientId,
                "scope":         this->getOption("scope", "https://www.googleapis.com/auth/userinfo.email https://www.googleapis.com/auth/userinfo.profile")
            ]
        ];
    }
}
