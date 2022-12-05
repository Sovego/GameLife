//
// Created by egors on 11/15/2022.
//

#ifndef OOP_LAB_2_FILEPARSER_H
#define OOP_LAB_2_FILEPARSER_H


#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "GameOfLife.h"
class FileParser {
public:
    static GameOfLife& readfile(const std::string& filename);
};


#endif //OOP_LAB_2_FILEPARSER_H
