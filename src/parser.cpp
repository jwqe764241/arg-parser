#include "parser.hpp"

parser::parser(int argc, char** argv, std::initializer_list<option> options)
{
	parse(argc, argv, options);
}

void parser::parse(int argc, char** argv, std::vector<option> options)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string current_value = argv[i];

		auto it = std::find_if(options.begin(), options.end(), [current_value](const option& o){
			return o.get_real_name() == current_value || o.get_real_short_name() == current_value;
		});

		if (it != options.end())
		{
			option o = *it;
			std::vector<std::string> arguments;

			for (int j = i + 1; j < i + 1 + o.get_argument_count(); ++j)
			{
				std::string argument = argv[j];

				auto it = std::find_if(options.begin(), options.end(), [argument](const option& o) {
					return o.get_real_name() == argument || o.get_real_short_name() == argument;
				});

				if (it == options.end())
				{
					arguments.push_back(argument);
				}
				else
				{
					break;
				}
			}

			add_option(o, arguments);
		}
	}
}

auto parser::find(std::string name)
{
	auto it = std::find_if(parsed_option.begin(), parsed_option.end(), [name](const std::pair<option, std::vector<std::string>>& e) {
		const option o = e.first;
		return o.get_real_name() == name || o.get_real_short_name() == name;
	});

	return it;
}

void parser::add_option(option o, std::vector<std::string> values)
{
	parsed_option.push_back(std::pair<option, std::vector<std::string>>(o, values));
}


bool parser::has_option(std::string name)
{
	auto it = find(name);

	return it != parsed_option.end() ? true : false;
}

std::vector<std::string> parser::get_arguments(std::string name)
{
	auto it = find(name);

	if (it != parsed_option.end())
	{
		return it->second;
	}
	else
	{
		return {};
	}
}
