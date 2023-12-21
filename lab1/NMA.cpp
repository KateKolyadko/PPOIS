#include  "NMA.h"
#include <chrono>



void NMA::createAlphabet(string alphabet_) {
	alphabet.createAlphabet(alphabet_);
}


void NMA::showAlphabet() {
	alphabet.showAlphabet();
}

string NMA::getFragment(int number_) {
	int number = number_ - 1;
	return rules[number].getFragment();
}

string NMA::getReplacement(int number_) {
	int number = number_ - 1;
	return rules[number].getReplacement();
}


bool NMA::alphabetCheck(string& str_check) {
	if (str_check == "^") { return true; }
	size_t found = str_check.find_first_not_of(alphabet.getAlphabet());
	return (found == string::npos);
}

void NMA::addRule(string fragment_, string replacement_) {
	if (!alphabetCheck(fragment_) || !alphabetCheck(replacement_) || fragment_ == "^") {
		cout << "does not correspond to the alphabet"  << endl;
	}
	else {
		Rule rule(fragment_, replacement_);
		rules.push_back(rule);
	}
}



void NMA::showRules() {
	for (int i = 0; i < rules.size(); i++) {
		cout << "'" << rules[i].getFragment() << "'" << "\t -> \t" << "'" << rules[i].getReplacement() << "'" << endl;
	}
}

void NMA::deleteRule(int number) {
	rules.erase(rules.begin() + number - 1);
}


void NMA::createStr(string str_) {
	if (alphabetCheck(str_)) {
		str = str_;
		result = str;
	}
	else { cout << "does not correspond to the alphabet" << endl; }
}





void NMA::replace(int numb_rule) {
	if (rules[numb_rule].getReplacement() == "^") { result.erase(result.find(rules[numb_rule].getFragment()), rules[numb_rule].getFragment().size()); }
	else  result.replace(result.find(rules[numb_rule].getFragment()), rules[numb_rule].getFragment().size(), rules[numb_rule].getReplacement());
}

void NMA::algorithm() {
	int numb_rule = 0;
	auto start = chrono::steady_clock::now();
	while (numb_rule != rules.size()) {
		if (result.find(rules[numb_rule].getFragment()) != string::npos) {
			replace(numb_rule);
			numb_rule = 0;
		}
		else { numb_rule++; }
		auto end = chrono::steady_clock::now();
		auto diff = end - start;
		if (diff > chrono::seconds(10)) {
			cout << "the cycle is considered endless\n";
			break;
		}
	}
}

string  NMA::resultStr() {
	return result;
}
