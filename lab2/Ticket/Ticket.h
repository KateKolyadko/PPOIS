#pragma once
#include <string>

class Ticket {
public:
	Ticket(const std::string exhibitionName);
	void useTicket();
private:
	std::string exhibitionName;
	bool isUsed;
};