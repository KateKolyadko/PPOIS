#include "Artifact.h"

Artifact::Artifact(const std::string name) : name(name) {

}

std::string Artifact::getArtifactName() const {
	return name;
}