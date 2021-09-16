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
void option_finder_test(std::string const &label, std::string const &str,
		const char delim, std::string const &opt_name);

int main(int argc, char *argv[]) {
	cout << "blindSafe Test Harness" << endl;
	arguments_tester(argc, argv);

	cout << endl << "Tokenizer Test" << endl;
	token_tester("empty    ", "", ';');
	token_tester("one arg  ", "/prog.exe", ';');
	token_tester("one+empty", "/prog.exe;", ';');
	token_tester("two args ", "/prog.exe;param1", ';');

	cout << endl << "Option Finder Test" << endl;
	std::string const cmd_line = "simple.exe -ip=\"127.0.0.1\" -port=1000";
	option_finder_test("second arg", cmd_line, ' ', "-port=");
	option_finder_test("first arg", cmd_line, ' ', "-ip=");

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

void option_finder_test(std::string const &label, std::string const &str,
		const char delim, std::string const &opt_name) {
	std::vector<std::string> out;
	const int nadded = tokenize(str, delim, out);
	cout << label << " [N:" << nadded << "] --- '" << str << "'";
	if (nadded < 1) {
		cout << " *** Nothing to test!!" << endl;
		return;
	}
	cout << " {" << opt_name << "}";
	std::string option_value = getCmdOptionStr(out, opt_name);
	cout << " ==> '" << option_value << "'" << endl;
}
