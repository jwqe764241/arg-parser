#include <iostream>

#include "get_option.hpp"

int main(int argc, char * argv[])
{
	using namespace cmd;

	parser parser(argc, argv, {
		option("-a", 3),
		option("-b", 2),
		option("-c", 4),
		option("-d", 1)
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