#pragma once
#include <iostream>

class Mouse {
private:
	std::string firm;
	float ReactionSpeed;

public:
	Mouse();
	Mouse(std::string firm, float ReactionSpeed);

	void Show();
};