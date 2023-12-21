#pragma once
#include "Feedback.h"
#include <vector>

class FeedbackSystem {
public:
	void addFeeback(const std::string exhitionName, const int rating);
	float calculateAverage();
	float calculateAverageExhibition(std::string exhibitionName);
private:
	std::vector<Feedback> feedbacks;
};