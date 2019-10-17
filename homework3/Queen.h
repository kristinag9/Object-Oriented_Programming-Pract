#pragma once
#include "Rook.h"
#include "Bishop.h"

class Queen : public Rook, public Bishop
{
public:
    Queen(Color, char, int);
    bool canMove(char, int);
    void move(char, int);
    void capture(Figure& other);
};
