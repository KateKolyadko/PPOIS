#pragma once
#include <string>

class Feedback {
public:
	Feedback(const std::string exhibitionName, const int rating);
	int getRating();
	std::string getExhibitionName();
private:
	std::string exhibitionName;
	int rating;
};