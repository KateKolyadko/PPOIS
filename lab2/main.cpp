#include "D:\лабы\ппоис\museum\museum\Museum.h"

int main() {
	Museum mus("name");
	mus.addExhibit("Ancient", "Old");
	mus.addExhibitArtifact("Ancient", "Knife");
	mus.addVisitor("Kate", "33", 20);
	mus.makeVisitorFeedback("Kate", "Ancient", 10);
	mus.getAverageExhitionRating("Ancient");
}
