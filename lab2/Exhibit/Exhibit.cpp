#include "Exhibit.h"

Exhibit::Exhibit(const std::string name, const std::string theme) : name(name), theme(theme), isClosed(false) { }

void Exhibit::addArtifact(const std::string name) {
	artifacts.emplace_back(name);
}

int Exhibit::getArtifactPosition(const std::string name) {
	int pos = -1;
	for (int i = 0; i < artifacts.size(); i++) {
		if (name == artifacts[i].getArtifactName()) {
			pos = i;
			break;
		}
	}
	return pos;
}

void Exhibit::removeArtifact(const std::string name) {
	int pos = getArtifactPosition(name);
	if (pos != -1) {
		artifacts.erase(artifacts.begin() + pos);
	}
}

const std::vector<Artifact>& Exhibit::getArtifacts() const {
	return artifacts;
}

std::string Exhibit::getName() const {
	return name;
}

std::string Exhibit::getTheme() const {
	return theme;
}

bool Exhibit::getStatus() const {
	return isClosed;
}

void Exhibit::close() {
	isClosed = true;
}

void Exhibit::open() {
	isClosed = false;
}

void Exhibit::switchStatus() {
	isClosed = !isClosed;
}