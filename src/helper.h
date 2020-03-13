#ifndef HELPER_H
#define HELPER_H

void resize(cv::Mat *image, int width=100);
void grayify(cv::Mat *image);
bool fileExists(std::string &name);
std::vector<std::string> getPixels(cv::Mat *image, int buckets=25);
void display(cv::Mat *image);
void writeToFile(std::vector<std::string> pixels, std::string fileName, int width=100);

#endif 
