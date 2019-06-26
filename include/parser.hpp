#pragma once

class parser
{
private:
	void parse(int count, char** options);
public:
	parser(int argc, char** argv);
};