#pragma once
#include <iostream>

class Webcam {
private:
	std::string firm;
	std::string VideoQuality;

public:
	Webcam();
	Webcam(std::string firm, std::string VideoQuality);

	void Show();
};