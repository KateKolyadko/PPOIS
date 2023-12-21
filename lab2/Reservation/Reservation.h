#pragma once
#include <string>

class Reservation {
public:
	Reservation(const std::string exhibitionName);
	void incrementCount();
	int getCount();
	std::string getExhibtionName();
private:
	int count;
	std::string exhibitionName;
};