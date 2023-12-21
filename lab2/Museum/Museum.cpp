#include "Museum.h"

Museum::Museum(const std::string museumName) : museumName(museumName) {
	reservationSystem = new ReservationSystem;
	feedbackSystem = new FeedbackSystem;
}

void Museum::addExhibit(const std::string name, const std::string theme) {
	exhibitions.emplace_back(name, theme);
}

void Museum::removeExhibit(const std::string name) {
	int pos = getExhibitionPosition(name);
	if (pos != -1) {
		exhibitions.erase(exhibitions.begin() + pos);
	}
}

int Museum::getExhibitionPosition(const std::string name) const {
	int pos = -1;
	for (int i = 0; i < exhibitions.size(); i++) {
		if (exhibitions[i].getName() == name) {
			pos = i;
			break;
		}
	}
	return pos;
}

std::string Museum::getExhibitTheme(const std::string name) {
	int pos = getExhibitionPosition(name);
	if (pos != -1) {
		return exhibitions[pos].getTheme();
	}
	return 0;
}

void Museum::addExhibitArtifact(const std::string exhibit, const std::string name) {
	int pos = getExhibitionPosition(exhibit);
	if (pos != -1) {
		exhibitions[pos].addArtifact(name);
	}
}

void Museum::removeExhibitArtifact(const std::string exhibit, const std::string name) {
	int pos = getExhibitionPosition(exhibit);
	if (pos != -1) {
		exhibitions[pos].removeArtifact(name);
	}
}

const std::vector<Artifact>& Museum::getExhibitionArtifacts(const std::string exhibit) const {
	int pos = getExhibitionPosition(exhibit);
	if (pos != -1) {
		return exhibitions[pos].getArtifacts();
	}
	throw;
}

void Museum::addVisitor(const std::string name, const std::string number, int money) {
	visitors.emplace_back(name, number, money);
}

int Museum::getVisitorPosition(const std::string name) const {
	int pos = -1;
	for (int i = 0; i < exhibitions.size(); i++) {
		if (visitors[i].getName() == name) {
			pos = i;
			break;
		}
	}
	return pos;
}

void Museum::removeVisitor(const std::string name) {
	int pos = getVisitorPosition(name);
	if (pos != -1) {
		visitors.erase(visitors.begin() + pos);
	}
}

int Museum::getVisotorMoney(const std::string name) const {
	int pos = getVisitorPosition(name);
	if (pos != -1) {
		return visitors[pos].getMoney();
	}
}

std::string Museum::getVisitorNumber(const std::string name) const {
	int pos = getVisitorPosition(name);
	if (pos != -1) {
		return visitors[pos].getNumber();
	}
}

void Museum::buyVisitorTicket(const std::string name, const std::string exhibit, int price){
	int pos = getVisitorPosition(name);
	if (pos != -1) {
		if (visitors[pos].spendMoney(price)) {
			visitors[pos].addTicket(exhibit);
			reservationSystem->add(exhibit);
			reservationSystem->incrementCustomerCount(exhibit);
		}
	}
}

void Museum::makeVisitorFeedback(const std::string visitorName, const std::string exhibitName, int rating) {
	int pos = getVisitorPosition(visitorName);
	if (pos != -1) {
		feedbackSystem->addFeeback(exhibitName, rating);
	}
}

void Museum::addCurator(const std::string name, const std::string number) {
	curators.emplace_back(name, number);
}

void Museum::addVisitorMoney(const std::string name, int money) {
	for (int i = 0; i < visitors.size(); i++) {
		if (visitors[i].getName() == name) {
			visitors[i].addMoney(money);
		}
	}
}

int Museum::getCuratorPosition(const std::string name) const {
	int pos = -1;
	for (int i = 0; i < curators.size(); i++) {
		if (curators[i].getName() == name) {
			pos = i;
			break;
		}
	}
	return pos;
}

void Museum::removeCurator(const std::string name) {
	int pos = getCuratorPosition(name);
	if (pos != -1) {
		curators.erase(curators.begin() + pos);
	}
}

std::string Museum::getCuratorNumber(const std::string name) {
	int pos = getCuratorPosition(name);
	if (pos != -1) {
		return curators[pos].getNumber();
	}
	return "None";
}

float Museum::getAverageRating() {
	return feedbackSystem->calculateAverage();
}

float Museum::getAverageExhitionRating(const std::string exhibittionName) {
	return feedbackSystem->calculateAverageExhibition(exhibittionName);
}

void Museum::addReservation(const std::string exhibition) {
	reservationSystem->add(exhibition);
}

void Museum::removeReservation(const std::string exhibition) {
	reservationSystem->remove(exhibition);
}

int Museum::getReservationVisitorsCount(const std::string exhibition) {
	return reservationSystem->getVisitorCount(exhibition);
}

Museum::~Museum() {
	delete reservationSystem;
	delete feedbackSystem;
}

void Museum::closeExhibition(const std::string exhibit) {
	int pos = getExhibitionPosition(exhibit);
	if (pos != -1) {
		exhibitions[pos].close();
	}
}
void Museum::openExhibition(const std::string exhibit) {
	int pos = getExhibitionPosition(exhibit);
	if (pos != -1) {
		exhibitions[pos].open();
	}
}
bool Museum::getStatus(const std::string exhibit) {
	int pos = getExhibitionPosition(exhibit);
	if (pos != -1) {
		return exhibitions[pos].getStatus();
	}
	return false;
}
void Museum::switchStatus(const std::string exhibit) {
	int pos = getExhibitionPosition(exhibit);
	if (pos != -1) {
		exhibitions[pos].switchStatus();
	}
}