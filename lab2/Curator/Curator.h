#pragma once
#include <string>

class Curator {
public:
	Curator(const std::string name, const std::string number);
	std::string getNumber() const;
	std::string getName() const;
private:
	std::string number;
	std::string name;
};