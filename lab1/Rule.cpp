#include  "NMA.h" 
#include <iostream>

using namespace std;

NMA::Rule::Rule(string fragment_, string replacement_) {
	fragment = fragment_;
	replacement = replacement_;
}

string NMA::Rule::getFragment() {
	return fragment;
}

string NMA::Rule::getReplacement() {
	return replacement;
}

