#include "NMA.h"


void NMA::Alphabet::createAlphabet(string letters_) {
	letters = letters_;
}

void NMA::Alphabet::showAlphabet() {
	cout << letters << endl;
};

string NMA::Alphabet::getAlphabet() {
	return letters;
}