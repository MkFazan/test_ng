#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "FileService.h"
#include "DataLine.h"
#include "SortingType.h"
#include "ArrayService.h"


int main()
{
    std::string delimiter = "; ";
    //std::cout << "Please, enter delimiter for arrays:" << std::endl;
    //std::getline(std::cin, delimiter);

    std::string pathToFile = "test_file.txt";
    FileService fileService = FileService();
    std::vector<std::string> data = fileService.ReadFile(pathToFile);
    std::vector<DataLine> arrays = fileService.ParseDataOfFile(data, delimiter);
    fileService.ShowDataFromFile(arrays);
    
    // SORT DESC
    ArrayService::ShowArray(arrays.front().Arrays.front());
    ArrayService::SortArray(arrays.front().Arrays.front(), SortingType::DESC);
    ArrayService::ShowArray(arrays.front().Arrays.front());

    // SORT ASC
    ArrayService::ShowArray(arrays.front().Arrays[1]);
    ArrayService::SortArray(arrays.front().Arrays[1], SortingType::ASC);
    ArrayService::ShowArray(arrays.front().Arrays[1]);

    // Intersection
    fileService.ShowDataFromFile(arrays);
    std::vector<int> intersectionOfTheTwoLargestArrays = ArrayService::GetIntersectionOfTheTwoLargestArrays(arrays.front().Arrays);
    std::vector<int> intersectionOfTheArrays = ArrayService::GetIntersectionOfTheArrays(arrays.front().Arrays);

    // Unique
    std::vector<int> uniqeArray = ArrayService::GetUniqueArray(arrays.front().Arrays, SortingType::ASC);

    auto x = "awfawf";
}
