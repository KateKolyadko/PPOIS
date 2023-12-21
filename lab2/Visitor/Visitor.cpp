#include "Visitor.h"

bool Visitor::spendMoney(int money) {
	if (this->money >= money) {
		this->money -= money;
		return true;
	}
	return false;
}

Visitor::Visitor(const std::string name, const std::string number, int money) : name(name), number(number), money(money) { }

void Visitor::addMoney(int money) {
	this->money += money;
}

void Visitor::addTicket(std::string exhibition) {
	tickets.emplace_back(exhibition);
}

std::string Visitor::getName() const {
	return name;
}

std::string Visitor::getNumber() const {
	return number;
}

int Visitor::getMoney() const {
	return money;
}