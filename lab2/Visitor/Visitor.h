#pragma once
#include <string>
#include <vector>
#include "Ticket.h"

class Visitor {
public:
	Visitor(const std::string name, const std::string number, int money);
	void addMoney(int money);
	bool spendMoney(int money);
	void addTicket(std::string exhibition);
	std::string getName() const;
	std::string getNumber() const;
	int getMoney() const;
private:
	int money;
	std::string number;
	std::string name;
	std::vector<Ticket> tickets;
};