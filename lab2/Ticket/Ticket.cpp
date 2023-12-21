#include "Ticket.h" 

Ticket::Ticket(const std::string exhibitionName) : exhibitionName(exhibitionName), isUsed(false) {

}

void Ticket::useTicket() {
	isUsed = true;
}