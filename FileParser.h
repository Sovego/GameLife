//
// Created by egors on 11/15/2022.
//

#ifndef OOP_LAB_2_FILEPARSER_H
#define OOP_LAB_2_FILEPARSER_H


#include <vector>
#include <string>

class FileParser {

public:
    std::vector<std::vector<unsigned int>> field;
    int survive;
    int birth;
    static void readfile(const std::string& filename);
};


#endif //OOP_LAB_2_FILEPARSER_H
