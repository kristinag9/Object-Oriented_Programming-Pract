#pragma once
#include <iostream>
#include <cassert>

using namespace std;

enum Color
{
	BLACK, WHITE
};

class Figure
{
private:
protected:
    Color color;
    bool inGame;
    char horizontalPosition;
    int verticalPosition;
public:
    Figure();
    Figure(Color, char, int);
    char getHPosition() const;
    int getVPosition() const;
    bool getColor() const;
    bool getInGame() const;
    void setInGame(bool);

    bool canMove(char, int);
    void move(char, int);
    void capture(Figure& other);
    void revive(char, int);
};
