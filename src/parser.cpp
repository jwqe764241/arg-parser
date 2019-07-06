#include "parser.hpp"

auto find_option(std::string name, std::vector<line_option>& options)
{
	auto it = std::find_if(options.begin(), options.end(), [&name](const line_option& o) {
		return o.get_real_name() == name || o.get_real_short_name() == name;
	});

	return it;
}

parser::parser(int argc, char** argv, std::initializer_list<line_option> options)
{
	parse(argc, argv, options);
}

void parser::parse(int argc, char** argv, std::vector<line_option> options)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string current_value = argv[i];

		auto it = find_option(current_value, options);

		if (it != options.end())
		{
			line_option option = *it;
			std::vector<std::string> arguments;

			int range_end = i + 1 + option.get_argument_count();

			if (range_end > argc)
			{
				range_end = argc;
			}

			for (int j = i + 1; j < range_end; ++j)
			{
				std::string argument = argv[j];

				auto it = find_option(argument, options);

				if (it == options.end())
				{
					arguments.push_back(argument);
				}
				else
				{
					break;
				}
			}

			add_option(option, arguments);

			i += arguments.size();
		}
	}
}

auto parser::find(std::string name)
{
	auto it = std::find_if(parsed_option.begin(), parsed_option.end(), [name](const std::pair<line_option, std::vector<std::string>>& e) {
		const line_option o = e.first;
		return o.get_real_name() == name || o.get_real_short_name() == name;
	});

	return it;
}

void parser::add_option(line_option o, std::vector<std::string> values)
{
	parsed_option.push_back(std::pair<line_option, std::vector<std::string>>(o, values));
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