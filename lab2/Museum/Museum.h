#pragma once
#include <string>
#include <vector>
#include "ReservationSystem.h"
#include "FeedbackSystem.h"
#include "Artifact.h"
#include "Visitor.h"
#include "Exhibit.h"
#include "Curator.h"

class Museum {
public:
	Museum(const std::string museumName);
	~Museum();
	void addExhibit(const std::string name, const std::string theme);
	void removeExhibit(const std::string name);
	std::string getExhibitTheme(const std::string name);
	void addExhibitArtifact(const std::string exhibit, const std::string name);
	void removeExhibitArtifact(const std::string exhibit, const std::string name);
	const std::vector<Artifact>& getExhibitionArtifacts(const std::string exhibit) const;
	void closeExhibition(const std::string exhibit);
	void openExhibition(const std::string exhibit);
	bool getStatus(const std::string exhibit);
	void switchStatus(const std::string exhibit);

	void addVisitor(const std::string name, const std::string number, int money);
	void removeVisitor(const std::string name);
	int getVisotorMoney(const std::string name) const;
	void addVisitorMoney(const std::string name, int money);
	std::string getVisitorNumber(const std::string name) const;
	void buyVisitorTicket(const std::string name, const std::string exhibit, int price);
	void makeVisitorFeedback(const std::string visitorName, const std::string exhibitName, int rating);

	void addCurator(const std::string name, const std::string number);
	void removeCurator(const std::string name);
	std::string getCuratorNumber(const std::string name);

	float getAverageRating();
	float getAverageExhitionRating(const std::string exhibittionName);

	void addReservation(const std::string exhibition);
	void removeReservation(const std::string exhibition);
	int getReservationVisitorsCount(const std::string exhibition);
private:
	int getExhibitionPosition(const std::string name) const;
	int getVisitorPosition(const std::string name) const;
	int getCuratorPosition(const std::string name) const;
	std::string museumName;
	std::vector<Visitor> visitors;
	std::vector<Exhibit> exhibitions;
	std::vector<Curator> curators;
	ReservationSystem* reservationSystem;
	FeedbackSystem* feedbackSystem;
};