#include "../project1/NMA.h"
#include <iostream>
using namespace std;



int main() {
	NMA first;
	string str_, alphabet_;
	cin >> alphabet_;
	first.createAlphabet(alphabet_);
	first.showAlphabet();
	cin >> str_;
	first.createStr(str_);
	cout << "rules" << endl;
	string fragm, repl;
	for (int i = 0; i < 4; i++) {
		cin >> fragm >> repl;
		first.addRule(fragm, repl);
	}

	first.showRules();
	first.algorithm();
	cout << "result\n" << first.resultStr() << endl;

	return 0;
}





