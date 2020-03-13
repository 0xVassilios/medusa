#include <iostream>
#include <string.h>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "cxxopts.hpp"
#include "helper.h"


int main(int argc, char** argv) {
	cxxopts::Options arguments("Medusa", "Medusa turns images into ASCII filled texts.");

	// Parsing the arguments provided by the user.
	arguments.add_options()
		("f, file", "File Name", cxxopts::value<std::string>())
		("w, width", "Image Width", cxxopts::value<int>()->default_value("100"));
	auto result = arguments.parse(argc, argv);
	
	// Obtaining the values from the arguments.
	std::string fileName = result["file"].as<std::string>();
	int imageWidth = result["width"].as<int>();

    // Checking if the file provided exists.
	if (!fileExists(fileName)) {
		printf("[Medusa] %s does not exist!", fileName.c_str());
	}

	// Reading the image provided as we know it exists.
	cv::Mat image = cv::imread(fileName, cv::IMREAD_COLOR);

    resize(&image, imageWidth);
    grayify(&image);
    std::vector<std::string> pixels = getPixels(&image);
    writeToFile(pixels, "image", imageWidth);

    return 0;
}
