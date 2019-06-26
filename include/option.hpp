#pragma once

#include <string>

class option
{
private:
	std::string prefix;
	std::string name;
	int argument_count;

public:
	option(std::string prefix, std::string name, int argument_count);

	std::string get_prefix();
	std::string get_name();
	std::string get_full_name();
	int get_argument_count();
};