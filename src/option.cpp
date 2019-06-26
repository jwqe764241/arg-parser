#include "option.hpp"

option::option(std::string prefix, std::string name, int argument_count)
	: prefix(prefix), name(name), argument_count(argument_count)
{
}

std::string option::get_prefix()
{
	return prefix;
}

std::string option::get_name()
{
	return name;
}

std::string option::get_full_name()
{
	return prefix + name;
}

int option::get_argument_count()
{
	return argument_count;
}