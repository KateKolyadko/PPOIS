#pragma once
#include "Artifact.h"
#include <vector>
#include <string>

class Exhibit {
public:
	Exhibit(const std::string name, const std::string theme);
	void addArtifact(const std::string name);
	void removeArtifact(const std::string name);
	const std::vector<Artifact>& getArtifacts() const;
	std::string getName() const;
	std::string getTheme() const;
	bool getStatus() const;
	void close();
	void open();
	void switchStatus();
private:
	int getArtifactPosition(const std::string name);
	std::vector<Artifact> artifacts;
	std::string name;
	std::string theme;
	bool isClosed;
};