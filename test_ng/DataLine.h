#pragma once
#include <string>
#include <vector>

class DataLine
{
public:
	DataLine(std::string, std::vector<std::vector<int>>);
	std::string BaseDataOfLine;
	std::vector<std::vector<int>> Arrays;
};