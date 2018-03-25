
namespace Ice\Validation\Validator;

use Ice\Exception;
use Ice\Validation;
use Ice\Validation\Validator;

/**
 * File validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *  
 *  $validation->rules([
 *      'picture' => [
 *          'file' => [
 *              'maxSize' => '6M',
 *              'allowedTypes' => ['image/jpeg', 'image/png'],
 *              'minResolution' => '400x300',
 *              'maxResolution' => '1600x1200',
 *          ]
 *      ]
 *  ]);
 *  
 *  $valid = $validation->validate($_FILES);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
class File extends Validator
{

    /**
     * Validate the validator
     * Options: label, messageIniSize, allowEmpty, messageEmpty, messageValid, maxSize, messageSize, allowedTypes, messageType
     * minResolution, maxResolution, messageMinResolution, messageMaxResolution
     *
     * @param Validation validation
     * @param string field
     * @return boolean
     */
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var value, message, label, i18n, replace, types, byteUnits, unit, maxSize, matches, bytes, mime, tmp, width, height, minResolution, maxResolution, minWidth, maxWidth, minHeight, maxHeight;

        let value = validation->getValue(field);

        if this->has("label") {
            let label = this->get("label");
        } else {
            let label = validation->getLabel(field);
        }

        // Upload is larger than PHP allowed size (post_max_size or upload_max_filesize)
        if _SERVER["REQUEST_METHOD"] == "POST" && empty _POST && empty _FILES && _SERVER["CONTENT_LENGTH"] > 0 || isset value["error"] && value["error"] === UPLOAD_ERR_INI_SIZE {
            if this->has("messageIniSize") {
                let message = this->get("messageIniSize");
            } else {
                let message = validation->getDefaultMessage("fileIniSize");
            }

            // Translate strings
            if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                let i18n = validation->getDi()->get("i18n"),
                    label = i18n->translate(label),
                    message = i18n->translate(message);
            }

            let replace = [":field": label];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        if this->has("allowEmpty") && (empty value || isset value["error"] && value["error"] === UPLOAD_ERR_NO_FILE) {
            return true;
        }

        if !isset value["error"] || ! isset value["tmp_name"] || value["error"] !== UPLOAD_ERR_OK || !is_uploaded_file(value["tmp_name"]) {
            if this->has("messageEmpty") {
                let message = this->get("messageEmpty");
            } else {
                let message = validation->getDefaultMessage("fileEmpty");
            }

            // Translate strings
            if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                let i18n = validation->getDi()->get("i18n"),
                    label = i18n->translate(label),
                    message = i18n->translate(message);
            }

            let replace = [":field": label];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        if !isset value["name"] || !isset value["type"] || !isset value["size"] {
            if this->has("messageValid") {
                let message = this->get("messageValid");
            } else {
                let message = validation->getDefaultMessage("default");
            }

            // Translate strings
            if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                let i18n = validation->getDi()->get("i18n"),
                    label = i18n->translate(label),
                    message = i18n->translate(message);
            }
            
            let replace = [":field": label];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        if this->has("maxSize") {
            let byteUnits = ["B": 0, "K": 10, "M": 20, "G": 30, "T": 40, "KB": 10, "MB": 20, "GB": 30, "TB": 40],
                maxSize = this->get("maxSize"),
                matches = null,
                unit = "B";

            preg_match("/^([0-9]+(?:\\.[0-9]+)?)(".implode("|", array_keys(byteUnits)).")?$/Di", maxSize, matches);

            if isset matches[2] {
                let unit = matches[2];
            }

            let bytes = floatval(matches[1]) * pow(2, byteUnits[unit]);

            if floatval(value["size"]) > floatval(bytes) {
                if this->has("messageSize") {
                    let message = this->get("messageSize");
                } else {
                    let message = validation->getDefaultMessage("fileSize");
                }

                // Translate strings
                if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                    let i18n = validation->getDi()->get("i18n"),
                        label = i18n->translate(label),
                        message = i18n->translate(message);
                }

                let replace = [":field": label, ":max": maxSize];

                validation->addMessage(field, strtr(message, replace));
                return false;
            }
        }

        if this->has("allowedTypes") {
            let types = this->get("allowedTypes");

            if typeof types != "array" {
                throw new Exception("Option 'allowedTypes' must be an array");
            }

            if function_exists("finfo_open") {
                let tmp = finfo_open(FILEINFO_MIME_TYPE),
                    mime = finfo_file(tmp, value["tmp_name"]);

                finfo_close(tmp);
            } else {
                let mime = value["type"];
            }

            if !in_array(mime, types) {
                if this->has("messageType") {
                    let message = this->get("messageType");
                } else {
                    let message = validation->getDefaultMessage("fileType");
                }

                // Translate strings
                if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                    let i18n = validation->getDi()->get("i18n"),
                        label = i18n->translate(label),
                        message = i18n->translate(message);
                }

                let replace = [":field": label, ":types": join(", ", types)];

                validation->addMessage(field, strtr(message, replace));
                return false;
            }
        }

        if this->has("minResolution") || this->has("maxResolution") {
            let tmp = getimagesize(value["tmp_name"]),
                width = tmp[0],
                height = tmp[1];

            if this->has("minResolution") {
                let minResolution = explode("x", this->get("minResolution")),
                    minWidth = minResolution[0],
                    minHeight = minResolution[1];
            } else {
                let minWidth = 1,
                    minHeight = 1;
            }

            if width < minWidth || height < minHeight {
                if this->has("messageMinResolution") {
                    let message = this->get("messageMinResolution");
                } else {
                    let message = validation->getDefaultMessage("fileMinResolution");
                }

                // Translate strings
                if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                    let i18n = validation->getDi()->get("i18n"),
                        label = i18n->translate(label),
                        message = i18n->translate(message);
                }

                let replace = [":field": label, ":min": this->get("minResolution")];

                validation->addMessage(field, strtr(message, replace));
                return false;
            }

            if this->has("maxResolution") {

                let maxResolution = explode("x", this->get("maxResolution")),
                    maxWidth = maxResolution[0],
                    maxHeight = maxResolution[1];

                if width > maxWidth || height > maxHeight {
                    if this->has("messageMaxResolution") {
                        let message = this->get("messageMaxResolution");
                    } else {
                        let message = validation->getDefaultMessage("fileMaxResolution");
                    }

                    // Translate strings
                    if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                        let i18n = validation->getDi()->get("i18n"),
                            label = i18n->translate(label),
                            message = i18n->translate(message);
                    }

                    let replace = [":field": label, ":max": this->get("maxResolution")];

                    validation->addMessage(field, strtr(message, replace));
                    return false;
                }
            }
        }
        return true;
    }
}
