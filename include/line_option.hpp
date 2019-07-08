#pragma once

#include <string>

class line_option
{
private:
	std::string name;
	std::string short_name;
	int argument_count;

public:
	line_option(std::string name, int argument_count);
	line_option(std::string name, std::string short_name, int argument_count);

	std::string get_name() const;
	std::string get_short_name() const;
	int get_argument_count() const;
};