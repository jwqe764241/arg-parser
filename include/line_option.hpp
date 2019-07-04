#pragma once

#include <string>

class line_option
{
	using name_pair = std::pair<std::string, std::string>;

private:
	name_pair name;
	name_pair short_name;
	int argument_count;

public:
	line_option(name_pair name, int argument_count);
	line_option(name_pair name, name_pair short_name, int argument_count);
	line_option(std::string prefix, std::string name, int argument_count);
	line_option(std::string prefix, std::string name,
		std::string short_prefix, std::string short_name,
		int argument_count);

	std::string get_prefix() const;
	std::string get_name() const;
	std::string get_short_prefix() const;
	std::string get_short_name() const;
	std::string get_real_name() const;
	std::string get_real_short_name() const;
	int get_argument_count() const;
};