#pragma once
#include <string>
#include <vector>
#include "DataLine.h"

class FileService
{
public:
	std::vector<std::string> ReadFile(std::string);
	std::vector<DataLine> ParseDataOfFile(std::vector<std::string>, std::string);
	
	void ShowDataFromFile(std::vector<DataLine>);

private:
	std::string GetDelimiterForString(std::string);
};

