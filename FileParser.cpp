//
// Created by egors on 11/15/2022.
//

#include "FileParser.h"


GameOfLife& FileParser::readfile(const std::string& filename) {
    std::ifstream ifile;

    std::string buf;
    ifile.open(filename);
    std::vector<unsigned> birth;
    std::vector<unsigned> survive;
    getline(ifile,buf);
    getline(ifile,buf);
    buf.erase(0,3);
    char a = buf.front();
    buf.erase(0,1);
    if (a=='B')
    {
        a = buf.front();
        while(a!='/')
        {
            buf.erase(0,1);
            int num = a - '0';
            birth.push_back(num);
            a = buf.front();
        }
    } else
    {
        throw std::invalid_argument("Divide by zero");
    }
    buf.erase(0,1);
    a = buf.front();
    buf.erase(0,1);
    if (a=='S')
    {
        a = buf.front();
        while(buf.length())
        {
            buf.erase(0,1);
            int num = a - '0';
            survive.push_back(num);
            if (buf.length())
            {
            a = buf.front();
            }
        }
    } else
    {
        throw std::invalid_argument("Divide by zero");
    }
    GameOfLife& obj = *new GameOfLife(778,514,birth,survive);
    while(getline(ifile,buf))
    {
        a = buf.front();
        buf.erase(0,2);
        int x = a - '0';
        a = buf.front();
        int y = a - '0';
        obj.toggleCell(x,y);
    }
    return obj;
}
