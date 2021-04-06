#include "ArrayService.h"
#include <iostream>
#include <unordered_set>
#include <algorithm>

void ArrayService::ShowArray(std::vector<int>& myArray)
{
    for (int value : myArray) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void ArrayService::SortArray(std::vector<int>& myArray, SortingType sortingType)
{
    bool pass = false;
    int temp;
    while (!pass) {
        pass = true;
        for (int i = 0; i < myArray.size() - 1; i++) {
            //TODO refactore ...
            if (sortingType == SortingType::ASC) {
                if (myArray[i] > myArray[i + 1]) {
                    pass = false;
                    temp = myArray[i];
                    myArray[i] = myArray[i + 1];
                    myArray[i + 1] = temp;
                }
            }
            else 
            {
                if (myArray[i] < myArray[i + 1]) {
                    pass = false;
                    temp = myArray[i];
                    myArray[i] = myArray[i + 1];
                    myArray[i + 1] = temp;
                }
            }
        }
    }
}

std::vector<int> ArrayService::GetIntersectionOfTheTwoLargestArrays(std::vector<std::vector<int>>& myArrays)
{
    int max, middle, min;
    std::tie(min, middle, max) = ArrayService::GetSizesOfArrays(myArrays);

    return ArrayService::Intersection(myArrays[middle], myArrays[max]);
}

std::vector<int> ArrayService::GetIntersectionOfTheArrays(std::vector<std::vector<int>>& myArrays)
{
    int max, middle, min;
    std::tie(min, middle, max) = ArrayService::GetSizesOfArrays(myArrays);
    std::vector<int> intersectionOfTheTwoLargestArrays = ArrayService::Intersection(myArrays[middle], myArrays[max]);
    std::vector<int> res = std::vector<int>();

    if (intersectionOfTheTwoLargestArrays.size() < min) {
        res = ArrayService::Intersection(intersectionOfTheTwoLargestArrays, myArrays[min]);
    }
    else 
    {
        res = ArrayService::Intersection(myArrays[min], intersectionOfTheTwoLargestArrays);
    }

    return res;
}

std::vector<int> ArrayService::GetUniqueArray(std::vector<std::vector<int>>& myArrays, SortingType sortingType)
{
    std::vector<int> res = std::vector<int>();
    
    // TODO ...
    std::vector<int> intersectionOfTheArrays = ArrayService::Intersection(myArrays[0], myArrays[1]);
    std::vector<int> intersectionOfTheArrays1 = ArrayService::Intersection(myArrays[0], myArrays[2]);
    std::vector<int> intersectionOfTheArrays2 = ArrayService::Intersection(myArrays[1], myArrays[2]);
    intersectionOfTheArrays.insert(intersectionOfTheArrays.end(), intersectionOfTheArrays1.begin(), intersectionOfTheArrays1.end());
    intersectionOfTheArrays.insert(intersectionOfTheArrays.end(), intersectionOfTheArrays2.begin(), intersectionOfTheArrays2.end());
    
    
    ArrayService::UniqueValueForArray(intersectionOfTheArrays);
    for (std::vector<int> oneArray : myArrays) {
        for (int possibleItem : oneArray) {
            bool isExist = false;
            for (int intersectionValue : intersectionOfTheArrays) {
                if (possibleItem == intersectionValue) {
                    isExist = true;
                    break;
                }
            }
            if (!isExist) {
                res.push_back(possibleItem);
            }

        }
    }

    ArrayService::UniqueValueForArray(res);
    ArrayService::SortArray(res, sortingType);

    return res;
}

std::vector<int> ArrayService::Intersection(std::vector<int>& myArray, std::vector<int>& largerArray) {
    if (myArray.empty() || largerArray.empty()) {
        return std::vector<int>();
    }
    std::unordered_set<int> set{ myArray.cbegin(), myArray.cend() };
    std::vector<int> intersections;
    for (auto n : largerArray) {
        if (set.erase(n) > 0) {
            intersections.push_back(n);
        }
    }
    return intersections;
}

void ArrayService::UniqueValueForArray(std::vector<int>& myArray)
{
    auto end = myArray.end();
    for (auto it = myArray.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }

    myArray.erase(end, myArray.end());
}

std::tuple<int, int, int> ArrayService::GetSizesOfArrays(std::vector<std::vector<int>>& myArrays)
{
    int max = 0, middle = -1, min = 0;
    for (int i = 1; i < myArrays.size(); i++) {

        if (max != i && min != i && middle < 0) {
            middle = i;
        }

        if (myArrays[max].size() < myArrays[i].size()) {
            max = i;
        }

        if (myArrays[min].size() > myArrays[i].size()) {
            min = i;
        }

        if (max != i && min != i) {
            middle = i;
        }
    }

    return std::make_tuple(min, middle, max);
}
