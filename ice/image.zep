
namespace Ice;

use Ice\Exception;

/**
 * Image manipulation support.
 *
 * @package     Ice/Image
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2020 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Image
{

    // Resizing constraints
    const NONE = 1;
    const WIDTH = 2;
    const HEIGHT = 3;
    const AUTO = 4;
    const INVERSE = 5;
    const PRECISE = 6;

    // Flipping directions
    const HORIZONTAL = 11;
    const VERTICAL = 12;

    protected static checked = false;

    protected file { get };
    protected width { get };
    protected height { get };
    protected type { get };
    protected mime { get };

    /**
     * Loads an image and prepares it for manipulation.
     *
     * <pre><code>
     *  $image = new Image('upload/test.jpg');
     * </code></pre>
     *
     * @param string file Image file path
     * @param string driver Driver class name
     *
     * @throws Exception
     */
    public static function factory(string file, string driver = null)
    {
        var instance;

        if !driver {
            let driver = "Ice\\Image\\Gd";
        }

        let instance = new {driver}(file);

        if !(instance instanceof Image) {
            throw new Exception("Driver must be an Image");
        }

        return instance;
    }

    /**
     * Loads information about the image. Will throw an exception if the image does not exist or is not an image.
     *
     * @param string file Image file path
     *
     * @return void
     * @throws Exception
     */
    public function __construct(string file)
    {
        var file, info;

        try {
            // Get the real path to the file
            let file = realpath(file);

            // Get the image information
            let info = getimagesize(file);
        } catch Exception {
            // Ignore all errors while reading the image
        }

        if empty file || empty info {
            throw new Exception(["Not an image or invalid image: %s", file]);
        }

        // Store the image information
        let this->file = file,
            this->width = info[0],
            this->height = info[1],
            this->type = info[2],
            this->mime = image_type_to_mime_type(this->type);
    }

    /**
     * Render the current image.
     *
     * <pre><code>
     *  echo $image;
     * </code></pre>
     *
     * @return string Binary string, it must be rendered with the appropriate Content-Type header
     */
    public function __toString() -> string
    {
        try {
            // Render the current image
            return this->render();
        } catch Exception {
            // Ignore all errors
        }
    }

    /**
     * Resize the image to the given size. Either the width or the height can be omitted and the image will be resized proportionally.
     *
     * <pre><code>
     *  // Resize to 200 pixels on the shortest side
     *  $image->resize(200, 200);
     *
     *  // Resize to 200x200 pixels, keeping aspect ratio
     *  $image->resize(200, 200, Image::INVERSE);
     *
     *  // Resize to 500 pixel width, keeping aspect ratio
     *  $image->resize(500, null);
     *
     *  // Resize to 500 pixel height, keeping aspect ratio
     *  $image->resize(null, 500);
     *
     *  // Resize to 200x500 pixels, ignoring aspect ratio
     *  $image->resize(200, 500, Image::NONE);
     * </code></pre>
     *
     * @param integer width New width
     * @param integer height New height
     * @param integer master Master dimension
     *
     * @return Image
     */
    public function resize(int width = null, int height = null, int master = null) -> <Image>
    {
        var ratio, tmp;

        if typeof master == "null" {
            // Choose the master dimension automatically
            let master = Image::AUTO;
        } elseif master == Image::WIDTH && width {
            // You should pass empty value for non-master dimension
            let master = Image::AUTO;

            // Set empty height for backward compatibility
            let height = null;
        } elseif master == Image::HEIGHT && height {
            let master = Image::AUTO;

            // Set empty width for backward compatibility
            let width = null;
        }

        if !width {
            if master === Image::NONE {
                // Use the current width
                let width = this->width;
            } else {
                // If width not set, master will be height
                let master = Image::HEIGHT;
            }
        }

        if !height {
            if master === Image::NONE {
                // Use the current height
                let height = this->height;
            } else {
                // If height not set, master will be width
                let master = Image::WIDTH;
            }
        }

        switch master {
            case Image::AUTO:
                // Choose direction with the greatest reduction ratio
                let master = (this->width / width) > (this->height / height) ? Image::WIDTH : Image::HEIGHT;
                break;
            case Image::INVERSE:
                // Choose direction with the minimum reduction ratio
                let master = (this->width / width) > (this->height / height) ? Image::HEIGHT : Image::WIDTH;
                break;
        }

        switch master {
            case Image::WIDTH:
                // Recalculate the height based on the width proportions
                let height = this->height * width / this->width;
                break;
            case Image::HEIGHT:
                // Recalculate the width based on the height proportions
                let width = this->width * height / this->height;
                break;
            case Image::PRECISE:
                // Resize to precise size
                let ratio = this->width / this->height;

                if width / height > ratio {
                    let height = this->height * width / this->width;
                } else {
                    let width = this->width * height / this->height;
                }
                break;
        }

        // Convert the width and height to integers, minimum value is 1px
        let tmp = max(round(width), 1),
            width = (int) tmp,
            tmp = max(round(height), 1),
            height = (int) tmp;

        this->doResize(width, height);

        return this;
    }

    /**
     * Crop an image to the given size. Either the width or the height can be omitted and the current width or height will be used.
     *
     * If no offset is specified, the center of the axis will be used.
     * If an offset of true is specified, the bottom of the axis will be used.
     *
     * <pre><code>
     *  // Crop the image to 200x200 pixels, from the center
     *  $image->crop(200, 200);
     * </code></pre>
     *
     * @param integer width New width
     * @param integer height New height
     * @param mixed offsetX Offset from the left
     * @param mixed offsetY Offset from the top
     *
     * @return Image
     */
    public function crop(int width, int height, offsetX = null, offsetY = null) -> <Image>
    {
        if width > this->width {
            // Use the current width
            let width = this->width;
        }

        if height > this->height {
            // Use the current height
            let height = this->height;
        }

        if typeof offsetX == "null" {
            // Center the X offset
            let offsetX = round((this->width - width) / 2);
        } elseif offsetX === true {
            // Bottom the X offset
            let offsetX = this->width - width;
        } elseif offsetX < 0 {
            // Set the X offset from the right
            let offsetX = this->width - width + offsetX;
        }

        if typeof offsetY == "null" {
            // Center the Y offset
            let offsetY = round((this->height - height) / 2);
        } elseif offsetY === true {
            // Bottom the Y offset
            let offsetY = this->height - height;
        } elseif offsetY < 0 {
            // Set the Y offset from the bottom
            let offsetY = this->height - height + offsetY;
        }

        if width > (this->width - offsetX) {
            // Use the maximum available width
            let width = this->width - offsetX;
        }

        if height > (this->height - offsetY) {
            // Use the maximum available height
            let height = this->height - offsetY;
        }

        this->doCrop(width, height, offsetX, offsetY);

        return this;
    }

    /**
     * Rotate the image by a given amount.
     *
     * <pre><code>
     *  // Rotate 45 degrees clockwise
     *  $image->rotate(45);
     *
     *  // Rotate 90% counter-clockwise
     *  $image->rotate(-90);
     * </code></pre>
     *
     * @param integer degrees Degrees to rotate: -360-360
     *
     * @return Image
     */
    public function rotate(int degrees) -> <Image>
    {
        if degrees > 180 {
            do {
                // Keep subtracting full circles until the degrees have normalized
                let degrees -= 360;
            } while degrees > 180;
        }

        if degrees < -180 {
            do {
                // Keep adding full circles until the degrees have normalized
                let degrees += 360;
            } while degrees < -180;
        }

        this->doRotate(degrees);

        return this;
    }

    /**
     * Flip the image along the horizontal or vertical axis.
     *
     * <pre><code>
     *  // Flip the image from top to bottom
     *  $image->flip(Image::HORIZONTAL);
     *
     *  // Flip the image from left to right
     *  $image->flip(Image::VERTICAL);
     * </code></pre>
     *
     * @param integer direction Direction: Image::HORIZONTAL, Image::VERTICAL
     *
     * @return Image
     */
    public function flip(int direction) -> <Image>
    {
        if direction !== Image::HORIZONTAL {
            // Flip vertically
            let direction = Image::VERTICAL;
        }

        this->doFlip(direction);

        return this;
    }

    /**
     * Sharpen the image by a given amount.
     *
     * <pre><code>
     *  // Sharpen the image by 20%
     *  $image->sharpen(20);
     * </code></pre>
     *
     * @param integer amount Amount to sharpen: 1-100
     *
     * @return Image
     */
    public function sharpen(int amount) -> <Image>
    {
        var tmp;

        // The amount must be in the range of 1 to 100
        let tmp = min(max(amount, 1), 100),
            amount = (int) tmp;

        this->doSharpen(amount);

        return this;
    }

    /**
     * Add a reflection to an image. The most opaque part of the reflection will be equal to the opacity setting and fade out to full transparent.
     * Alpha transparency is preserved.
     *
     * <pre><code>
     *  // Create a 50 pixel reflection that fades from 0-100% opacity
     *  $image->reflection(50);
     *
     *  // Create a 50 pixel reflection that fades from 100-0% opacity
     *  $image->reflection(50, 100, true);
     *
     *  // Create a 50 pixel reflection that fades from 0-60% opacity
     *  $image->reflection(50, 60, true);
     * </code></pre>
     *
     * [!!] By default, the reflection will be go from transparent at the top to opaque at the bottom.
     *
     * @param integer height Reflection height
     * @param integer opacity Reflection opacity: 0-100
     * @param boolean fadeIn True to fade in, false to fade out
     *
     * @return Image
     */
    public function reflection(int height = null, int opacity = 100, boolean fadeIn = false) -> <Image>
    {
        var tmp;

        if typeof height == "null" || height > this->height {
            // Use the current height
            let height = this->height;
        }

        // The opacity must be in the range of 0 to 100
        let tmp = min(max(opacity, 0), 100),
            opacity = (int) tmp;

        this->doReflection(height, opacity, fadeIn);

        return this;
    }

    /**
     * Add a watermark to an image with a specified opacity. Alpha transparency will be preserved.
     *
     * If no offset is specified, the center of the axis will be used.
     * If an offset of true is specified, the bottom of the axis will be used.
     *
     * <pre><code>
     *  // Add a watermark to the bottom right of the image
     *  $mark = new Image('upload/watermark.png');
     *  $image->watermark($mark, true, true);
     * </code></pre>
     *
     * @param Image watermark Watermark Image instance
     * @param integer offsetX Offset from the left
     * @param integer offsetY Offset from the top
     * @param integer opacity Opacity of watermark: 1-100
     *
     * @return Image
     */
    public function watermark(<Image> watermark, int offsetX = null, int offsetY = null, int opacity = 100) -> <Image>
    {
        var tmp;

        if typeof offsetX == "null" {
            // Center the X offset
            let tmp = round((this->width - watermark->getWidth()) / 2),
                offsetX = (int) tmp;
        } elseif offsetX === true {
            // Bottom the X offset
            let offsetX = this->width - watermark->getWidth();
        } elseif offsetX < 0 {
            // Set the X offset from the right
            let offsetX = this->width - watermark->getWidth() + offsetX;
        }

        if typeof offsetY == "null" {
            // Center the Y offset
            let tmp = round((this->height - watermark->getHeight()) / 2),
                offsetY = (int) tmp;
        } elseif offsetY === true {
            // Bottom the Y offset
            let offsetY = this->height - watermark->getHeight();
        } elseif offsetY < 0 {
            // Set the Y offset from the bottom
            let offsetY = this->height - watermark->getHeight() + offsetY;
        }

        // The opacity must be in the range of 1 to 100
        let tmp = min(max(opacity, 1), 100),
            opacity = (int) tmp;

        this->doWatermark(watermark, offsetX, offsetY, opacity);

        return this;
    }

    /**
     * Set the background color of an image. This is only useful for images with alpha transparency.
     *
     * <pre><code>
     *  // Make the image background black
     *  $image->background('#000');
     *
     *  // Make the image background black with 50% opacity
     *  $image->background('#000', 50);
     * </code></pre>
     *
     * @param string color Hexadecimal color value
     * @param integer opacity Background opacity: 0-100

     * @return Image
     */
    public function background(string color, int opacity = 100) -> <Image>
    {
        var tmp, r, g, b;

        if color[0] === '#' {
            // Remove the hash
            let color = substr(color, 1);
        }

        if strlen(color) === 3 {
            // Convert shorthand into longhand hex notation
            let color = preg_replace("/./", "00", color);
        }

        // Convert the hex into RGB values
        let tmp = array_map("hexdec", str_split(color, 2)),
            r = tmp[0],
            g = tmp[1],
            b = tmp[2];

        // The opacity must be in the range of 0 to 100
        let tmp = min(max(opacity, 0), 100),
            opacity = (int) tmp;

        this->doBackground(r, g, b, opacity);

        return this;
    }

    /**
     * Save the image. If the filename is omitted, the original image will be overwritten.
     *
     * <pre><code>
     *  // Save the image as a PNG
     *  $image->save('saved/cool.png');
     *
     *  // Overwrite the original image
     *  $image->save();
     * </code></pre>
     *
     * [!!] If the file exists, but is not writable, an exception will be thrown.
     * [!!] If the file does not exist, and the directory is not writable, an exception will be thrown.
     *
     * @param string file New image path
     * @param integer quality Quality of image: 1-100

     * @return boolean
     * @throws Exception
     */
    public function save(string file = null, int quality = 100) -> boolean
    {
        var tmp, directory;

        if typeof file == "null" {
            // Overwrite the file
            let file = this->file;
        }

        if is_file(file) {
            if !is_writable(file) {
                throw new Exception(["File must be writable: %s", file]);
            }
        } else {
            // Get the directory of the file
            let directory = realpath(pathinfo(file, PATHINFO_DIRNAME));

            if !is_dir(directory) || !is_writable(directory) {
                throw new Exception(["Directory must be writable: %s", directory]);
            }
        }

        // The quality must be in the range of 1 to 100
        let tmp = min(max(quality, 1), 100),
            quality = (int) tmp;

        return this->doSave(file, quality);
    }

    /**
     * Render the image and return the binary string.
     *
     * <pre><code>
     *  // Render the image at 50% quality
     *  $data = image->render(null, 50);
     *
     *  // Render the image as a PNG
     *  $data = image->render('png');
     * </code></pre>
     *
     * @param string type Image type to return: png, jpg, gif, etc
     * @param integer quality Quality of image: 1-100

     * @return string
     */
    public function render(string type = null, int quality = 100) -> string
    {
        var tmp;

        if typeof type == "null" {
            // Use the current image type
            let tmp = image_type_to_extension(this->type, false),
                type = (string) tmp;
        }

        return this->doRender(type, quality);
    }

    /**
     * Execute a resize.
     *
     * @param integer width New width
     * @param integer height New height
     *
     * @return void
     */
    abstract protected function doResize(int width, int height) -> void;

    /**
     * Execute a crop.
     *
     * @param integer width New width
     * @param integer height New height
     * @param integer offset_x offset From the left
     * @param integer offset_y offset From the top
     *
     * @return void
     */
    abstract protected function doCrop(int width, int height, int offset_x, int offset_y) -> void;

    /**
     * Execute a rotation.
     *
     * @param integer degrees Degrees to rotate
     *
     * @return void
     */
    abstract protected function doRotate(int degrees) -> void;

    /**
     * Execute a flip.
     *
     * @param integer direction Direction to flip
     *
     * @return void
     */
    abstract protected function doFlip(int direction) -> void;

    /**
     * Execute a sharpen.
     *
     * @param integer amount Amount to sharpen
     *
     * @return void
     */
    abstract protected function doSharpen(int amount) -> void;

    /**
     * Execute a reflection.
     *
     * @param integer height Reflection height
     * @param integer opacity Reflection opacity
     * @param boolean fadeIn TRUE to fade out, FALSE to fade in
     *
     * @return void
     */
    abstract protected function doReflection(int height, int opacity, boolean fadeIn) -> void;

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
    abstract protected function doWatermark(<Image> image, int offsetX, int offsetY, int opacity) -> void;

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
    abstract protected function doBackground(int r, int g, int b, int opacity) -> void;

    /**
     * Execute a save.
     *
     * @param string file New image filename
     * @param integer quality Quality
     *
     * @return boolean
     */
    abstract protected function doSave(string file, int quality) -> boolean;

    /**
     * Execute a render.
     *
     * @param string type Image type: png, jpg, gif, etc
     * @param integer quality Quality
     *
     * @return string
     */
    abstract protected function doRender(string type, int quality) -> string;
}