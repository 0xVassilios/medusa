#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <sys/stat.h>
#include <vector>
#include <math.h>
#include <fstream>

void resize(cv::Mat *image, int width=100) {
	double scale = float(width) / image->size().width;
	cv::resize(*image, *image, cv::Size(), scale, scale);
}

void grayify(cv::Mat *image) {
	cv::cvtColor(*image, *image, cv::COLOR_BGR2GRAY);
}

bool fileExists(std::string &name) {
	struct stat buffer;
	return (stat (name.c_str(), &buffer) == 0);
}

void display(cv::Mat *image) {
	cv::imshow("Display Window", *image);
	cv::waitKey(0);
}

std::vector<std::string> getPixels(cv::Mat *image, int buckets=25) {
	// The characters used to draw the image based on intensity.
	char ascii[11] = { '@', '#', '$', '%', '?', '*', '+', ';', ':', ',', '.' };
	std::vector<std::string> pixels;

	for (int y=0; y<image->rows; y++) {
		for (int x=0; x<image->cols; x++) {
			int pixel = (int) image->at<uchar>(y, x);
			std::string value = std::to_string(pixel);
			pixels.push_back(value);
		}
	}

	for (std::vector<int>::size_type i = 0; i != pixels.size(); i++)
		pixels[i] = ascii[(int) floor(std::stoi(pixels[i]) / buckets)];

	return pixels;
}

bool endsWith(const std::string &str, const std::string &suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

void writeToFile(std::vector<std::string> pixels, std::string fileName, int width=100) {
	std::ofstream myFile;
	
	if (endsWith(fileName, ".txt"))
		myFile.open(fileName);
	else
		myFile.open(fileName + ".txt");

	int count = 0;
	for (int x=0; x<pixels.size(); x++) {
		count++;

		myFile << pixels[x];

		if (count == width) {
			myFile << "\n";
			count = 0;
		} else {
			myFile << " ";
		}
	}

	myFile.close();
}
