#pragma once
#include "Figure.h"
#include <cmath>

class Bishop : virtual public Figure
{
public:
    Bishop(Color, char, int);
    bool canMove(char, int);
    void move(char, int);
    void capture(Figure& other);
};
