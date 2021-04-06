#pragma once
#include "FileService.h"
#include "DataLine.h"
#include "ArrayService.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

std::vector<std::string> FileService::ReadFile(std::string pathToFile)
{
    std::string str;
    std::vector<std::string> data = std::vector<std::string>();

    std::ifstream MyReadFile(pathToFile);

    while (getline(MyReadFile, str)) {
        data.push_back(str);
    }

    MyReadFile.close();

	return data;
}

std::vector<DataLine> FileService::ParseDataOfFile(std::vector<std::string> dataFile, std::string delimiterForArrays)
{
    std::vector<DataLine> dataLines = std::vector<DataLine>();

    size_t pos_start = 0, pos_end, delim_len = delimiterForArrays.length();
    

    for (std::string str : dataFile) {
        //Init
        DataLine dataLine = DataLine(str, std::vector<std::vector<int>>());
        std::vector<std::string> stringOfArrays;

        while ((pos_end = str.find(delimiterForArrays, pos_start)) != std::string::npos) {
            std::string childString = str.substr(pos_start, pos_end - pos_start);
            str = str.substr(pos_end + delim_len, str.length());
            stringOfArrays.push_back(childString);
        }

        if (str.length() > 0) {
            stringOfArrays.push_back(str);
        }

        {
            size_t pos_start = 0, pos_end, delim_len;
            std::string delimiterForString;

            std::vector<std::vector<int>> myArrays;

            for (std::string stringOfArray : stringOfArrays)
            {
                std::vector<int> myArray;

                delimiterForString = GetDelimiterForString(stringOfArray);
                delim_len = delimiterForString.length();

                while ((pos_end = stringOfArray.find(delimiterForString, pos_start)) != std::string::npos) {
                    std::string item = stringOfArray.substr(pos_start, pos_end - pos_start);
                    stringOfArray = stringOfArray.substr(pos_end + delim_len, stringOfArray.length());
                    myArray.push_back(std::stoi(item));
                }

                if (stringOfArray.length() > 0) {
                    myArray.push_back(std::stoi(stringOfArray));
                }

                dataLine.Arrays.push_back(myArray);

            }
        }
        dataLines.push_back(dataLine);
    }

    return dataLines;
}

void FileService::ShowDataFromFile(std::vector<DataLine> data)
{
    for (DataLine item : data) {
        std::cout << std::endl << "String of line:" << std::endl;
        std::cout << item.BaseDataOfLine << std::endl << std::endl;
        std::int16_t index = 1;

        for (std::vector<int> myArray : item.Arrays) {
            std::cout << "Array (" << index << "): " << std::endl;
            ArrayService::ShowArray(myArray);
            index++;
            std::cout << std::endl;
        }
    }
}

std::string FileService::GetDelimiterForString(std::string str)
{
    std::map<std::string, std::string> defaultDelimitersForArray{
          {"Comma and Space", ", "},
          {"Comma", ","},
          {"Space", " "}
    };

    std::string delimiterForString = defaultDelimitersForArray["Space"];

    if (str.find(defaultDelimitersForArray["Comma and Space"], 0) != std::string::npos) {
        delimiterForString = defaultDelimitersForArray["Comma and Space"];
    }

    if (str.find(defaultDelimitersForArray["Comma"], 0) != std::string::npos) {
        delimiterForString = defaultDelimitersForArray["Comma"];
    }

    return delimiterForString;
}
