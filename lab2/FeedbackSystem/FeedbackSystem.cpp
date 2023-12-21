#include "FeedbackSystem.h"

void FeedbackSystem::addFeeback(const std::string exhibitionName, const int rating) {
	feedbacks.emplace_back(exhibitionName, rating);
}

float FeedbackSystem::calculateAverage() {
	float avg = 0.f;
	for (int i = 0; i < feedbacks.size(); i++) {
		avg += feedbacks[i].getRating();
	}
	return avg / feedbacks.size();
}

float FeedbackSystem::calculateAverageExhibition(std::string exhibitionName) {
	float avg = 0.f;
	int count = 0;
	for (int i = 0; i < feedbacks.size(); i++) {
		if (exhibitionName == feedbacks[i].getExhibitionName()) {
			avg += feedbacks[i].getRating();
			count++;
		}
	}
	if (!count) {
		return 0;
	}
	return avg / count;
}