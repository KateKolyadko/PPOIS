#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NMA {
public:
	void addRule(string fragment_, string replacement_);
	string getReplacement(int number_);
	string getFragment(int number_);
	void showRules();
	void deleteRule(int number);
	void createStr(string str_);
	string resultStr();
	void algorithm();
	void createAlphabet(string alphabet_);
	void showAlphabet();
private:
	string str;
	string result;
	void replace(int numb_rule);
	bool alphabetCheck(string& str_check);

	class Alphabet {
	public:
		void createAlphabet(string letters_);
		void showAlphabet();
		string getAlphabet();
		string letters;
	};


	class Rule {
	public:
		Rule(string fragment_, string replacement_);
		string getFragment();
		string getReplacement();
		string replacement;
		string  fragment;
	};

	Alphabet alphabet;

	vector <Rule> rules;
};
