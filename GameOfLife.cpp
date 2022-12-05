//
// Created by egors on 11/15/2022.
//

#include "GameOfLife.h"


GameOfLife::GameOfLife() {
    this->Xmax = 10;
    this->Ymax = 10;
    this->XSize = Xmax + 2;
    this->YSize = Ymax + 2;
    for (unsigned i = 0; i != this->XSize; i++)
    {
        std::vector<unsigned> inter;
        for (unsigned j = 0; j != this->YSize; j++)
        {
            inter.push_back(0);
        }
        this->field.push_back(inter);
    }
}

GameOfLife::GameOfLife(const unsigned &x, const unsigned &y,const std::vector<unsigned> & birth, const std::vector<unsigned> & survive) {
    this->Xmax = x;
    this->Ymax = y;
    this->XSize = Xmax + 2;
    this->YSize = Ymax + 2;
    this->birth = birth;
    this->survive = survive;
    for (unsigned i = 0; i != this->XSize; i++)
    {
        std::vector<unsigned> inter;
        for (unsigned j = 0; j != this->YSize; j++)
        {
            inter.push_back(0);
        }
        this->field.push_back(inter);
    }
}

GameOfLife::~GameOfLife()
{
    this->field.clear();
}

void GameOfLife::toggleCell(const unsigned &x, const unsigned &y)
{
    this->field[x][y] = !this->field[x][y];
}

// return the new value of a cell depending on the surrounding values
unsigned GameOfLife::newValCell(const unsigned &x, const unsigned &y)
{
    unsigned stok;
    stok = this->field[x-1][y-1]
           + this->field[x-1][y]
           + this->field[x-1][y+1]
           + this->field[x][y-1]
           + this->field[x][y+1]
           + this->field[x+1][y-1]
           + this->field[x+1][y]
           + this->field[x+1][y+1];
    std::vector<unsigned>::iterator it;
    it = find(this->birth.begin(),this->birth.end(),stok);
    if (it != this->birth.end())
    {
        return 1;
    }
    it = find(this->survive.begin(),this->survive.end(),stok);
    if (it != this->survive.end())
    {
        return this->field[x][y];
    }
    return 0;
}

void GameOfLife::updateField()
{
    std::vector<std::vector<unsigned>> stockField = this->field;
    for (unsigned i = 1; i != Xmax + 1; i++)
    {
        for (unsigned j = 1; j != Ymax + 1; j++)
        {
            stockField[i][j] = newValCell(i,j);
        }
    }
    this->field = stockField;
}

void GameOfLife::display() const
{
    for (int i = 1; i != Xmax + 1; i++)
    {
        for (int j = 1; j != Ymax + 1; j++)
        {
            std::cout << this->field[i][j] << " ";
        }
        std::cout << "\n";
    }
}
