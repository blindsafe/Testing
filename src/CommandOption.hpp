/*
 * CommandOption.hpp
 *
 *  Created on: Sep 15, 2021
 *      Author: Donald Trummell
 */

#ifndef COMMANDOPTION_HPP_
#define COMMANDOPTION_HPP_

#include <string>
#include <vector>
#include <windows.h>
using namespace std;

int findFirstOptionInArray(const int argc, const char *argv[],
		const std::string &option);

int findFirstOptionInVector(const std::vector<std::string> &out,
		const std::string &option);

std::string getCmdOption(const int argc, const char *argv[],
		const std::string &option);

std::string getCmdOptionVec(const std::vector<std::string> &out,
		const std::string &option);

int tokenize(std::string const &str, const char delim,
		std::vector<std::string> &out);

#endif /* COMMANDOPTION_HPP_ */
