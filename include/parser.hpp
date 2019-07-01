#pragma once

#include <map>
#include <vector>
#include <array>
#include <algorithm>
#include <initializer_list>

#include "option.hpp"

class parser
{
private:
	//store parsed options
	std::map<option, std::vector<std::string>> option_map;

private:
	void parse(int argc, char** argv, std::vector<option> options);
	auto find(std::string name);

public:
	parser(int argc, char** argv, std::initializer_list<option> options);

	bool has_option(std::string name);
	std::vector<std::string> get_arguments(std::string name);
};