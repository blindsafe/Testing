//============================================================================
// Name        : Testing.cpp
// Author      : Donald Trummell
// Version     : 0.1.0
// Copyright   : (c) 2021
// Description : Test Harness for blindSafe
//============================================================================

#include "Testing.hpp"

void arguments_tester(int argc, char *argv[]);
void token_tester(std::string const &label, std::string const &str,
		const char delim);

int main(int argc, char *argv[]) {
	cout << "blindSafe Test Harness" << endl;
	arguments_tester(argc, argv);

	cout << endl << "Tokenizer Test" << endl;
	token_tester("empty    ", "", ';');
	token_tester("one arg  ", "/prog.exe", ';');
	token_tester("one+empty", "/prog.exe;", ';');
	token_tester("two args ", "/prog.exe;param1", ';');

	return 0;
}

void arguments_tester(int argc, char *argv[]) {
	cout << endl << "The " << argc << " arguments are:" << endl;
	for (int i = 0; i < argc; i++) {
		cout << "\t[" << i << "] -> '" << argv[i] << "'" << endl;
	}
}

void token_tester(std::string const &label, std::string const &str,
		const char delim) {
	cout << label << " [" << delim << "] --- '" << str << "'";
	std::vector<std::string> out;
	const int nadded = tokenize(str, delim, out);
	cout << " ==>> [" << nadded << "] --- '";
	for (int i = 0; i < nadded; i++) {
		if (i > 0) {
			cout << " | ";
		}
		cout << out[i];
	}
	cout << "'" << endl;
}
