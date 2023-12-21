#pragma once
#include <string>

class Artifact {
public:
	Artifact(const std::string name);
	std::string getArtifactName() const;
private:
	std::string name;
};