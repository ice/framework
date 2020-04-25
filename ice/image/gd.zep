
namespace Ice\Image;

use Ice\Image;
use Ice\Exception;

/**
 * Gd image driver.
 *
 * @package     Ice/Image
 * @category    Driver
 * @author      Ice Team
 * @copyright   (c) 2014-2020 Ice Team
 * @license     http://iceframework.org/license
 */
class Gd extends Image
{
    protected static bundled;

    protected image;
    protected createFunction;

    /**
     * Run install check and load the image.
     *
     * @param string file Image file path
     *
     * @return void
     * @throws Exception
     */
    public function __construct(string file)
    {
        var create;

        if !self::checked {
            // Run the install check
            self::check();
        }

        parent::__construct(file);

        // Set the image creation function name
        switch this->type {
            case IMAGETYPE_JPEG:
                let create = "imagecreatefromjpeg";
                break;
            case IMAGETYPE_GIF:
                let create = "imagecreatefromgif";
                break;
            case IMAGETYPE_PNG:
                let create = "imagecreatefrompng";
                break;
        }

        if !create || !function_exists(create) {
            throw new Exception(["Installed GD does not support %s images", image_type_to_extension(this->type, false)]);
        }

        // Save function for future use
        let this->createFunction = create;

        // Save filename for lazy loading
        let this->image = this->file;
    }

    /**
     * Checks if GD is enabled and bundled. Bundled GD is required for some methods to work.
     * Exceptions will be thrown from those methods when GD is not bundled.
     *
     * @return boolean
     */
    public static function check() -> boolean
    {
        var version;

        if !function_exists("gd_info") {
            throw new Exception("GD is either not installed or not enabled, check your configuration");
        }

        if defined("GD_BUNDLED") {
            // Get the version via a constant
            let self::bundled = GD_BUNDLED;
        }

        if defined("GD_VERSION") {
            // Get the version via a constant
            let version = GD_VERSION;
        }

        if !version_compare(version, "2.0.1", ">=") {
            throw new Exception(["GD requires GD version %s or greater, you have %s", "2.0.1", version]);
        }

        let self::checked = true;

        return self::checked;
    }

    /**
     * Destroys the loaded image to free up resources.
     *
     * @return void
     */
    public function __destruct()
    {
        if is_resource(this->image) {
            // Free all resources
            imagedestroy(this->image);
        }
    }

    /**
     * Loads an image into GD.
     *
     * @return void
     */
    protected function loadImage() -> void
    {
        var create;

        if !is_resource(this->image) {
            // Gets create function
            let create = this->createFunction;

            // Open the temporary image
            let this->image = {create}(this->file);

            // Preserve transparency when saving
            imagesavealpha(this->image, true);
        }
    }

    /**
     * Execute a resize.
     *
     * @param integer width New width
     * @param integer height New height
     *
     * @return void
     */
    protected function doResize(int width, int height) -> void
    {
        var preWidth, preHeight, reductionWidth, reductionHeight, image;

        // Presize width and height
        let preWidth = this->width,
            preHeight = this->height;

        // Loads image if not yet loaded
        this->loadImage();

        // Test if we can do a resize without resampling to speed up the final resize
        if width > (this->width / 2) && height > (this->height / 2) {
            // The maximum reduction is 10% greater than the final size
            let reductionWidth = round(width * 1.1),
                reductionHeight = round(height * 1.1);

            while preWidth / 2 > reductionWidth && preHeight / 2 > reductionHeight {
                // Reduce the size using an O(2n) algorithm, until it reaches the maximum reduction
                let preWidth /= 2,
                    preHeight /= 2;
            }

            // Create the temporary image to copy to
            let image = this->create(preWidth, preHeight);

            if imagecopyresized(image, this->image, 0, 0, 0, 0, preWidth, preHeight, this->width, this->height) {
                // Swap the new image for the old one
                imagedestroy(this->image);

                let this->image = image;
            }
        }

        // Create the temporary image to copy to
        let image = this->create(width, height);

        // Execute the resize
        if imagecopyresampled(image, this->image, 0, 0, 0, 0, width, height, preWidth, preHeight) {
            // Swap the new image for the old one
            imagedestroy(this->image);

            let this->image = image;

            // Reset the width and height
            let this->width = imagesx(image),
                this->height = imagesy(image);
        }
    }

    /**
     * Execute a crop.
     *
     * @param integer width New width
     * @param integer height New height
     * @param integer offsetX Offset from the left
     * @param integer offsetY Offset from the top
     *
     * @return void
     */
    protected function doCrop(int width, int height, int offsetX, int offsetY) -> void
    {
        var image;

        // Create the temporary image to copy to
        let image = this->create(width, height);

        // Loads image if not yet loaded
        this->loadImage();

        // Execute the crop
        if imagecopyresampled(image, this->image, 0, 0, offsetX, offsetY, width, height, width, height) {
            // Swap the new image for the old one
            imagedestroy(this->image);

            let this->image = image;

            // Reset the width and height
            let this->width = imagesx(image),
                this->height = imagesy(image);
        }
    }

    /**
     * Execute a rotation.
     *
     * @param integer degrees Degrees to rotate
     *
     * @return void
     */
    protected function doRotate(int degrees) -> void
    {
        var transparent, image, width, height;

        if !self::bundled {
            throw new Exception(["This method requires %s, which is only available in the bundled version of GD", "imagerotate"]);
        }

        // Loads image if not yet loaded
        this->loadImage();

        // Transparent black will be used as the background for the uncovered region
        let transparent = imagecolorallocatealpha(this->image, 0, 0, 0, 127);

        // Rotate, setting the transparent color
        let image = imagerotate(this->image, 360 - degrees, transparent, 1);

        // Save the alpha of the rotated image
        imagesavealpha(image, true);

        // Get the width and height of the rotated image
        let width = imagesx(image),
            height = imagesy(image);

        if imagecopymerge(this->image, image, 0, 0, 0, 0, width, height, 100) {
            // Swap the new image for the old one
            imagedestroy(this->image);

            let this->image = image;

            // Reset the width and height
            let this->width = width,
                this->height = height;
        }
    }

    /**
     * Execute a flip.
     *
     * @param integer direction Direction to flip
     *
     * @return void
     */
    protected function doFlip(int direction) -> void
    {
        var flipped;

        // Create the flipped image
        let flipped = this->create(this->width, this->height);

        // Loads image if not yet loaded
        this->loadImage();

        if direction === Image::HORIZONTAL {
            int x = 0;

            while x < this->width {
                // Flip each row from top to bottom
                imagecopy(flipped, this->image, x, 0, this->width - x - 1, 0, 1, this->height);

                let x++;
            }
        } else {
            int y = 0;

            while y < this->height {
                // Flip each column from left to right
                imagecopy(flipped, this->image, 0, y, 0, this->height - y - 1, this->width, 1);

                let y++;
            }
        }

        // Swap the new image for the old one
        imagedestroy(this->image);

        let this->image = flipped;

        // Reset the width and height
        let this->width = imagesx(flipped),
            this->height = imagesy(flipped);
    }

    /**
     * Execute a sharpen.
     *
     * @param integer amount Amount to sharpen
     *
     * @return void
     */
    protected function doSharpen(int amount) -> void
    {
        var tmp, matrix;

        if !self::bundled {
            throw new Exception(["This method requires %s, which is only available in the bundled version of GD", "imageconvolution"]);
        }

        // Loads image if not yet loaded
        this->loadImage();

        // Amount should be in the range of 18-10
        let tmp = round(abs(-18 + (amount * 0.08)), 2),
            amount = (int) tmp;

        // Gaussian blur matrix
        let matrix = [
            [-1, -1, -1],
            [-1, amount, -1],
            [-1, -1, -1]
        ];

        // Perform the sharpen
        if imageconvolution(this->image, matrix, amount - 8, 0) {
            // Reset the width and height
            let this->width = imagesx(this->image),
                this->height = imagesy(this->image);
        }
    }

    /**
     * Execute a reflection.
     *
     * @param integer height Reflection height
     * @param integer opacity Reflection opacity
     * @param boolean fadeIn True to fade out, false to fade in
     *
     * @return void
     */
    protected function doReflection(int height, int opacity, boolean fadeIn) -> void
    {
        var tmp, srcY, dstY, dstOpacity, stepping, reflection, line;

        if !self::bundled {
            throw new Exception(["This method requires %s, which is only available in the bundled version of GD", "imagefilter"]);
        }

        // Loads image if not yet loaded
        this->loadImage();

        // Convert an opacity range of 0-100 to 127-0
        let tmp = round(abs((opacity * 127 / 100) - 127)),
            opacity = (int) tmp;

        if opacity < 127 {
            // Calculate the opacity stepping
            let stepping = (127 - opacity) / height;
        } else {
            // Avoid a "divide by zero" error
            let stepping = 127 / height;
        }

        // Create the reflection image
        let reflection = this->create(this->width, this->height + height);

        // Copy the image to the reflection
        imagecopy(reflection, this->image, 0, 0, 0, 0, this->width, this->height);

        int offset = 0;

        while height >= offset {
            // Read the next line down
            let srcY = this->height - offset - 1;

            // Place the line at the bottom of the reflection
            let dstY = this->height + offset;

            if fadeIn === true {
                // Start with the most transparent line first
                let dstOpacity = round(opacity + (stepping * (height - offset)));
            } else {
                // Start with the most opaque line first
                let dstOpacity = round(opacity + (stepping * offset));
            }

            // Create a single line of the image
            let line = this->create(this->width, 1);

            // Copy a single line from the current image into the line
            imagecopy(line, this->image, 0, 0, 0, srcY, this->width, 1);

            // Colorize the line to add the correct alpha level
            imagefilter(line, IMG_FILTER_COLORIZE, 0, 0, 0, dstOpacity);

            // Copy a the line into the reflection
            imagecopy(reflection, line, 0, dstY, 0, 0, this->width, 1);

            let offset++;
        }

        // Swap the new image for the old one
        imagedestroy(this->image);

        let this->image = reflection;

        // Reset the width and height
        let this->width = imagesx(reflection),
            this->height = imagesy(reflection);
    }

    /**
     * Execute a watermarking.
     *
     * @param Image image Watermarking Image
     * @param integer offsetX Offset from the left
     * @param integer offsetY Offset from the top
     * @param integer opacity Opacity of watermark
     *
     * @return void
     */
    protected function doWatermark(<Image> watermark, int offsetX, int offsetY, int opacity) -> void
    {
        var tmp, overlay, width, height, color;

        if !self::bundled {
            throw new Exception(["This method requires %s, which is only available in the bundled version of GD", "imagelayereffect"]);
        }

        // Loads image if not yet loaded
        this->loadImage();

        // Create the watermark image resource
        let overlay = imagecreatefromstring(watermark->render());

        imagesavealpha(overlay, true);

        // Get the width and height of the watermark
        let width = imagesx(overlay),
            height = imagesy(overlay);

        if opacity < 100 {
            // Convert an opacity range of 0-100 to 127-0
            let tmp = round(abs((opacity * 127 / 100) - 127)),
                opacity = (int) tmp;

            // Allocate transparent gray
            let color = imagecolorallocatealpha(overlay, 127, 127, 127, opacity);

            // The transparent image will overlay the watermark
            imagelayereffect(overlay, IMG_EFFECT_OVERLAY);

            // Fill the background with the transparent color
            imagefilledrectangle(overlay, 0, 0, width, height, color);
        }

        // Alpha blending must be enabled on the background!
        imagealphablending(this->image, true);

        if imagecopy(this->image, overlay, offsetX, offsetY, 0, 0, width, height) {
            // Destroy the overlay image
            imagedestroy(overlay);
        }
    }

    /**
     * Execute a background.
     *
     * @param integer r Red
     * @param integer g Green
     * @param integer b Blue
     * @param integer opacity Opacity
     *
     * @return void
     */
    protected function doBackground(int r, int g, int b, int opacity) -> void
    {
        var tmp, background, color;

        // Loads image if not yet loaded
        this->loadImage();

        // Convert an opacity range of 0-100 to 127-0
        let tmp = round(abs((opacity * 127 / 100) - 127)),
            opacity = (int) tmp;

        // Create a new background
        let background = this->create(this->width, this->height);

        // Allocate the color
        let color = imagecolorallocatealpha(background, r, g, b, opacity);

        // Fill the image with white
        imagefilledrectangle(background, 0, 0, this->width, this->height, color);

        // Alpha blending must be enabled on the background!
        imagealphablending(background, true);

        // Copy the image onto a white background to remove all transparency
        if imagecopy(background, this->image, 0, 0, 0, 0, this->width, this->height) {
            // Swap the new image for the old one
            imagedestroy(this->image);

            let this->image = background;
        }
    }

    /**
     * Execute a save.
     *
     * @param string file New image filename
     * @param integer quality Quality
     *
     * @return boolean
     */
    protected function doSave(string file, var quality = null) -> boolean
    {
        var tmp, extension, save, type, status;

        // Loads image if not yet loaded
        this->loadImage();

        // Get the extension of the file
        let extension = pathinfo(file, PATHINFO_EXTENSION);

        // Get the save function and IMAGETYPE
        let tmp = this->saveFunction(extension, quality),
            save = tmp[0],
            type = tmp[1],
            quality = tmp[2];

        // Save the image to a file
        let status = quality ? {save}(this->image, file, quality) : {save}(this->image, file);

        if status === true && type !== this->type {
            // Reset the image type and mime type
            let this->type = type,
                this->mime = image_type_to_mime_type(type);
        }

        return true;
    }

    /**
     * Execute a render.
     *
     * @param string type Image type: png, jpg, gif, etc
     * @param integer quality Quality
     *
     * @return string
     */
    protected function doRender(string type, quality) -> string
    {
        var tmp, save, type, status;

        // Loads image if not yet loaded
        this->loadImage();

        // Get the save function and IMAGETYPE
        let tmp = this->saveFunction(type, quality),
            save = tmp[0],
            type = tmp[1],
            quality = tmp[2];

        // Capture the output
        ob_start();

        // Render the image
        let status = quality ? {save}(this->image, null, quality) : {save}(this->image, null);

        if status === true && type !== this->type {
            // Reset the image type and mime type
            let this->type = type,
                this->mime = image_type_to_mime_type(type);
        }

        return ob_get_clean();
    }

    /**
     * Get the GD saving function and image type for this extension.
     * Also normalizes the quality setting
     *
     * @param string extension Image type: png, jpg, etc
     * @param integer quality Image quality

     * @return array Save function, IMAGETYPE_* constant
     * @throws Exception
     */
    protected function saveFunction(string extension, int quality) -> array
    {
        var tmp, save, type;

        if !extension {
            // Use the current image type
            let tmp = image_type_to_extension(this->type, false),
                extension = (string) tmp;
        }

        switch strtolower(extension) {
            case "jpg":
            case "jpeg":
                // Save a JPG file
                let save = "imagejpeg",
                    type = IMAGETYPE_JPEG;
                break;
            case "gif":
                // Save a GIF file
                let save = "imagegif",
                    type = IMAGETYPE_GIF;

                // GIFs do not a quality setting
                let quality = null;
                break;
            case "png":
                // Save a PNG file
                let save = "imagepng",
                    type = IMAGETYPE_PNG;

                // Use a compression level of 9 (does not affect quality!)
                let quality = 9;
                break;
            default:
                throw new Exception(["Installed GD does not support %s images", extension]);
        }

        return [save, type, quality];
    }

    /**
     * Create an empty image with the given width and height.
     *
     * @param integer width Image width
     * @param integer height Image height
     *
     * @return resource
     */
    protected function create(int width, int height) -> resource
    {
        var image;

        // Create an empty image
        let image = imagecreatetruecolor(width, height);

        // Do not apply alpha blending
        imagealphablending(image, false);

        // Save alpha levels
        imagesavealpha(image, true);

        return image;
    }

}
