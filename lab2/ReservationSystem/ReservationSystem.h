#pragma once
#include "Reservation.h"
#include <vector>

class ReservationSystem {
public:
	void add(const std::string exhibition);
	void remove(const std::string exhibition);
	int getVisitorCount(const std::string exhibition);
	void incrementCustomerCount(const std::string exhibition);
private:
	int getReservationPosition(const std::string exhibition);
	std::vector<Reservation> reservations;
};