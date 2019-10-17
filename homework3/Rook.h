#pragma once
#include "Figure.h"

class Rook : virtual public Figure
{
public:
    Rook(Color, char, int);
    bool canMove(char, int);
    void move(char, int);
    void capture(Figure& other);
};



