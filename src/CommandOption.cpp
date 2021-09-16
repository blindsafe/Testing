/*
 * CommandOption.cpp
 *
 *  Created on: Sep 15, 2021
 *      Author: Donald Trummell
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Searches an array of character strings, like command line arguments, and locates the named option
 *
 * Adapted directly from https://gist.github.com/plasticbox/3708a6cdfbece8cd224487f9ca9794cd
 *
 * Examples:
 * // simple.exe -ip="127.0.0.1" -port=1000
 * std::string ip = getCmdOption(argc, argv, "-ip=");
 * std::string port = getCmdOption(argc, argv, "-port=");
 *
 */
std::string getCmdOption(const int argc, const char *argv[],
		const std::string &option) {
	std::string cmd;
	for (int i = 0; i < argc; ++i) {
		std::string arg = argv[i];
		if (0 == arg.find(option)) {
			std::size_t found = arg.find_first_of(option);
			cmd = arg.substr(found + 1);
			return cmd;
		}
	}
	return cmd;
}

/**
 * Split a string into tokens based on a delimiter character
 *
 * Adapted directly from https://www.techiedelight.com/split-string-cpp-using-delimiter/
 */
void tokenize(std::string const &str, const char delim,
		std::vector<std::string> &out) {
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}
