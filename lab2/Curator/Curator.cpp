#include "Curator.h"

Curator::Curator(const std::string name, const std::string number) : name(name), number(number) { }

std::string Curator::getNumber() const {
	return number;
}

std::string Curator::getName() const {
	return name;
}