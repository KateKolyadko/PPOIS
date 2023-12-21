#include "Reservation.h"

Reservation::Reservation(const std::string exhibitionName) : exhibitionName(exhibitionName), count(0) { }

void Reservation::incrementCount() {
	count++;
}

int Reservation::getCount() {
	return count;
}

std::string Reservation::getExhibtionName() {
	return exhibitionName;
}