#ifndef HELPER_H
#define HELPER_H

/**
 * Resizes an image while keeping aspect ratio.
 *
 * @param image The image that will be resized.
 * @param width The width that the image should have.
 */
void resize(cv::Mat *image, int width=100);

/**
 * Turns an image to grayscale.
 *
 * @param image The image that will be turned.
 */
void grayify(cv::Mat *image);

/**
 * Checks if a file exists.
 *
 * @param name The name of the file to be searched.
 */
bool fileExists(std::string &name);

/**
 * Retrieves a vector of ASCII characters which resemble an image given.
 *
 * @param image The image to be turned into ASCII.
 * @param buckets The intensity of the darkness/light.
 */
std::vector<std::string> getPixels(cv::Mat *image, int buckets=25);

/**
 * Displays an image.
 *
 * @image The image to be displayed.
 */
void display(cv::Mat *image);

/**
 * Writes a vector of ASCII pixels onto a file.
 *
 * @param pixels The pixels from getPixels.
 * @param fileName How the file should be named.
 * @param width The width that the drawn image should have.
 */
void writeToFile(std::vector<std::string> pixels, std::string fileName, int width=100);

#endif 
