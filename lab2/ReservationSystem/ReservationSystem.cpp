#include "ReservationSystem.h"

void ReservationSystem::add(const std::string exhibition) {
	int pos = -1;
	for (int i = 0; i < reservations.size(); i++) {
		if (reservations[i].getExhibtionName() == exhibition) {
			pos = i;
			break;
		}
	}
	if (pos == -1)
		reservations.emplace_back(exhibition);
}

int ReservationSystem::getReservationPosition(const std::string exhibition) {
	int pos = -1;
	for (int i = 0; i < reservations.size(); i++) {
		if (reservations[i].getExhibtionName() == exhibition) {
			pos = i;
			break;
		}
	}
	return pos;
}

void ReservationSystem::remove(const std::string exhibition) {
	int pos = getReservationPosition(exhibition);
	if (pos != -1) {
		reservations.erase(reservations.begin() + pos);
	}
}

int ReservationSystem::getVisitorCount(const std::string exhibition) {
	int pos = getReservationPosition(exhibition);
	if (pos != -1) {
		return reservations[pos].getCount();
	}
	return 0;
}

void ReservationSystem::incrementCustomerCount(const std::string exhibition) {
	int pos = getReservationPosition(exhibition);
	if (pos != -1) {
		reservations[pos].incrementCount();
	}
}