#include "line_option.hpp"

line_option::line_option(std::string name, int argument_count)
	: name(name), argument_count(argument_count)
{
}

line_option::line_option(std::string name, std::string short_name, int argument_count)
	: name(name), short_name(short_name), argument_count(argument_count)
{
}

std::string line_option::get_name() const
{
	return name;
}

std::string line_option::get_short_name() const
{
	return short_name;
}

int line_option::get_argument_count() const
{
	return argument_count;
}