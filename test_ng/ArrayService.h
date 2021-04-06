#pragma once
#include <vector>
#include "SortingType.h"

class ArrayService
{
public:
	static void ShowArray(std::vector<int>&);
	static void SortArray(std::vector<int>&, SortingType);
	
	static std::vector<int> GetIntersectionOfTheTwoLargestArrays(std::vector<std::vector<int>>&);
	static std::vector<int> GetIntersectionOfTheArrays(std::vector<std::vector<int>>&);
	static std::vector<int> GetUniqueArray(std::vector<std::vector<int>>&, SortingType);

private:
	static std::tuple<int, int, int> GetSizesOfArrays(std::vector<std::vector<int>>&);
	static std::vector<int> Intersection(std::vector<int>&, std::vector<int>&);
	static void UniqueValueForArray(std::vector<int>&);
};

