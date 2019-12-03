#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "get_option.hpp"

TEST_CASE("parse command line argument with one value", "[parser]")
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

TEST_CASE("parse command line argument with multiple value", "[parser]")
{
	using namespace cmd;

	int length = 15;
	char* arguments[15] = {
		"name",
		"-a",
		"1",
		"2",
		"3",
		"-b",
		"4",
		"5",
		"-c",
		"6",
		"-d",
		"7",
		"8",
		"9",
		"10"
	};

	parser parser(length, arguments, {
		option("-a", 3),
		option("-b", 2),
		option("-c", 1),
		option("-d", 4)
	});

	std::vector<std::string> a_values = parser.get_arguments("-a");
	std::vector<std::string> b_values = parser.get_arguments("-b");
	std::vector<std::string> c_values = parser.get_arguments("-c");
	std::vector<std::string> d_values = parser.get_arguments("-d");

	SECTION("checking parsed arguments size is right")
	{
		REQUIRE(a_values.size() == 3);
		REQUIRE(b_values.size() == 2);
		REQUIRE(c_values.size() == 1);
		REQUIRE(d_values.size() == 4);
	}

	SECTION("checking parsed arguments value is right")
	{
		REQUIRE(a_values[0] == "1");
		REQUIRE(a_values[1] == "2");
		REQUIRE(a_values[2] == "3");

		REQUIRE(b_values[0] == "4");
		REQUIRE(b_values[1] == "5");

		REQUIRE(c_values[0] == "6");

		REQUIRE(d_values[0] == "7");
		REQUIRE(d_values[1] == "8");
		REQUIRE(d_values[2] == "9");
		REQUIRE(d_values[3] == "10");
	}
}

TEST_CASE("parse option is more than argument count", "[parser]")
{
	using namespace cmd;

	int length = 15;
	char* arguments[15] = {
		"name",
		"-a",
		"1",
		"2",
		"3",
		"-b",
		"4",
		"5",
		"-c",
		"6",
		"-d",
		"7",
		"8",
		"9",
		"10"
	};

	parser parser(length, arguments, {
		option("-a", 2),
		option("-b", 2),
		option("-c", 2),
		option("-d", 2)
	});

	std::vector<std::string> a_values = parser.get_arguments("-a");
	std::vector<std::string> b_values = parser.get_arguments("-b");
	std::vector<std::string> c_values = parser.get_arguments("-c");
	std::vector<std::string> d_values = parser.get_arguments("-d");

	SECTION("checking parsed arguments size is right")
	{
		REQUIRE(a_values.size() == 2);
		REQUIRE(b_values.size() == 2);
		REQUIRE(c_values.size() == 1);
		REQUIRE(d_values.size() == 2);
	}

	SECTION("checking parsed arguments value is right")
	{
		REQUIRE(a_values[0] == "1");
		REQUIRE(a_values[1] == "2");

		REQUIRE(b_values[0] == "4");
		REQUIRE(b_values[1] == "5");

		REQUIRE(c_values[0] == "6");

		REQUIRE(d_values[0] == "7");
		REQUIRE(d_values[1] == "8");
	}
}

TEST_CASE("parse exceptional case", "[parser]")
{
	using namespace cmd;

	int length = 12;
	char* arguments[12] = {
		"name",
		"-a",
		"1",
		"2",
		"3",
		"-c",
		"6",
		"-d",
		"7",
		"8",
		"9",
		"10"
	};

	parser parser(length, arguments, {
		option("-a", 2),
		option("-b", 2),
		option("-c", 2),
		option("-d", 2)
		});

	std::vector<std::string> a_values = parser.get_arguments("-a");
	std::vector<std::string> c_values = parser.get_arguments("-c");
	std::vector<std::string> d_values = parser.get_arguments("-d");

	SECTION("checking parsed arguments size is right")
	{
		REQUIRE(a_values.size() == 2);
		REQUIRE(!parser.has_option("-b"));
		REQUIRE(c_values.size() == 1);
		REQUIRE(d_values.size() == 2);

		REQUIRE_THROWS(parser.get_arguments("-b"));
		REQUIRE_THROWS(parser.get_argument_size("-b"));
	}
}

TEST_CASE("test short name", "[parser]")
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
		option("-a", "--a", 1),
		option("-b", "--b", 1),
		option("-c", "--c", 1),
		option("-d", "--d", 1)
	});

	REQUIRE(parser.get_arguments("--a")[0] == "1");
	REQUIRE(parser.get_arguments("--b")[0] == "2");
	REQUIRE(parser.get_arguments("--c")[0] == "3");
	REQUIRE(parser.get_arguments("--d")[0] == "4");
}