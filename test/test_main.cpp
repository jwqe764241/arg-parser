#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "get_option.hpp"

TEST_CASE("Parse test 1", "[parser]")
{
	using namespace cmd;
	
	int length = 9;
	char* arguments[9] = {
		"name",
		"-a",
		"1",
		"-b",
		"2",
		"-c",
		"3",
		"-d",
		"4"
	};
	
	parser parser(length, arguments, {
		option("-a", 1),
		option("-b", 1),
		option("-c", 1),
		option("-d", 1)
	});
	
	REQUIRE(parser.get_arguments("-a")[0] == "1");
	REQUIRE(parser.get_arguments("-b")[0] == "2");
	REQUIRE(parser.get_arguments("-c")[0] == "3");
	REQUIRE(parser.get_arguments("-d")[0] == "4");
}