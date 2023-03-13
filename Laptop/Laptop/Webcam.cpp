#include "Webcam.h"

Webcam::Webcam(): firm(""), VideoQuality("") {}

Webcam::Webcam(std::string firm, std::string VideoQuality) : firm(firm), VideoQuality(VideoQuality) {}

void Webcam::Show() { std::cout << "Firm: " << firm << std::endl << "Video quality: " << VideoQuality << std::endl; }