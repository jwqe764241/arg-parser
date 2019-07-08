#include <iostream>

#include "parser.hpp"

int main(int argc, char * argv[])
{
	parser parser(argc, argv, {
		line_option("-a", 3),
		line_option("-b", 2),
		line_option("-c", 4),
		line_option("-d", 1)
	});

	std::vector<std::string> a = parser.get_arguments("-a");
	std::cout << "a options" << std::endl;
	for (std::string s : a)
	{
		std::cout << s << std::endl;
	}

	std::vector<std::string> b = parser.get_arguments("-b");
	std::cout << "b options" << std::endl;
	for (std::string s : b)
	{
		std::cout << s << std::endl;
	}

	std::vector<std::string> c = parser.get_arguments("-c");
	std::cout << "c options" << std::endl;
	for (std::string s : c)
	{
		std::cout << s << std::endl;
	}

	std::vector<std::string> d = parser.get_arguments("-d");
	std::cout << "d options" << std::endl;
	for (std::string s : d)
	{
		std::cout << s << std::endl;
	}
}