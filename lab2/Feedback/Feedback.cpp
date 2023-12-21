#include "Feedback.h"

Feedback::Feedback(const std::string exhibitionName, const int rating) : rating(rating), exhibitionName(exhibitionName) { }

int Feedback::getRating() {
	return rating;
}

std::string Feedback::getExhibitionName() {
	return exhibitionName;
}