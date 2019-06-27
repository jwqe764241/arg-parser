#include "option.hpp"

option::option(name_pair name, int argument_count)
	: name(name), argument_count(argument_count)
{
}

option::option(std::string prefix, std::string name, int argument_count)
	: option(std::make_pair(prefix, name), argument_count)
{
}

option::option(name_pair name, name_pair short_name, int argument_count)
	: name(name), short_name(short_name), argument_count(argument_count)
{
}

option::option(std::string prefix, std::string name,
	std::string short_prefix, std::string short_name, int argument_count)
	: option(std::make_pair(prefix, name), std::make_pair(short_prefix, short_name), argument_count)
{
}

std::string option::get_prefix()
{
	return name.first;
}

std::string option::get_name()
{
	return name.second;
}

std::string option::get_short_prefix()
{
	return short_name.first;
}

std::string option::get_short_name()
{
	return short_name.second;
}

std::string option::get_real_name()
{
	return name.first + name.second;
}

std::string option::get_real_short_name()
{
	return short_name.first + short_name.second;
}

int option::get_argument_count()
{
	return argument_count;
}