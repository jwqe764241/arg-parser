#include "parser.hpp"

parser::parser(int argc, char** argv, std::initializer_list<option> options)
{
	parse(argc, argv, options);
}

void parser::parse(int argc, char** argv, std::vector<option> options)
{

}

auto parser::find(std::string name)
{
	auto it = std::find_if(option_map.begin(), option_map.end(), [name](const std::pair<option, std::vector<std::string>> e) {
		const option o = e.first;
		return o.get_name() == name || o.get_short_name() == name;
	});

	return it;
}

bool parser::has_option(std::string name)
{
	auto it = find(name);

	return it != option_map.end() ? true : false;
}

std::vector<std::string> parser::get_arguments(std::string name)
{
	auto it = find(name);

	if (it != option_map.end())
	{
		return it->second;
	}
	else
	{
		return {};
	}
}
