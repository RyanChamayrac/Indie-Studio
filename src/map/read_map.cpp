//
// EPITECH PROJECT, 2019
// Event
// File description:
// Indie Studio
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool getFileContent(std::string fileName, std::vector<std::string> &vecOfStrs)
{

    std::ifstream in(fileName.c_str());

    if (!in) {
        std::cerr << "Loading map failed: "<<fileName<<std::endl;
        return false;
    }

    std::string str;
    while (std::getline(in, str)) {
        if(str.size() > 0)
            vecOfStrs.push_back(str);
    }
    in.close();
    return true;
}

int read_map()
{
    std::vector<std::string> vecOfStr;
    bool result = getFileContent("map.txt", vecOfStr);

    if(result) {
        for(std::string &line:vecOfStr)
            std::cout<<line<<std::endl;
    }
}