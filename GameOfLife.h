//
// Created by egors on 11/15/2022.
//

#ifndef OOP_LAB_2_GAMEOFLIFE_H
#define OOP_LAB_2_GAMEOFLIFE_H
#include <vector>
#include <iostream>

class GameOfLife{

public:
    GameOfLife();
    GameOfLife(const unsigned &, const unsigned &,const std::vector<unsigned> &,const std::vector<unsigned> & );
    ~GameOfLife();
    void display() const;
    void toggleCell(const unsigned &,const unsigned &);
    void updateField();

private:
    unsigned Xmax, Ymax;
    unsigned XSize, YSize;
    std::vector<unsigned> birth, survive;
    std::vector<std::vector<unsigned>> field;
    unsigned newValCell(const unsigned &, const unsigned &) const;
};


#endif //OOP_LAB_2_GAMEOFLIFE_H
