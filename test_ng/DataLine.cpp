#pragma once
#include "DataLine.h"

DataLine::DataLine(std::string baseDataOfLine, std::vector<std::vector<int>> arrays)
{
	BaseDataOfLine = baseDataOfLine;
	Arrays = arrays;
}
