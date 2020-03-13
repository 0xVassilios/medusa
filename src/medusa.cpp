#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string.h>
#include "helper.h"
#include <vector>

std::string getFileName(int argc, char** argv) {
    std::string fileName;

    if (argc == 1) {
        printf("[Medusa] Medusa is a program which turns your images into text files or images filled with characters.\n");
        exit(1);
    } else if (argc != 2) {
        printf("[Medusa] You have provided insufficient information. Medusa accepts one argument, the name of your image.\n");
        exit(1);
    } else {
        fileName = argv[1];

        if (fileExists(fileName)) {
            return fileName;
        } else {
            printf("[Medusa] The file %s does not exist!\n", fileName.c_str());
            exit(1);
        }
    }
}

int main(int argc, char** argv) {
    std::string fileName = getFileName(argc, argv);	// The name of the file that the user has provided.
    cv::Mat image = cv::imread(fileName, cv::IMREAD_COLOR);

    resize(&image);
    grayify(&image);
    std::vector<std::string> pixels = getPixels(&image);
    writeToFile(pixels, "image");

    return 0;
}
