#include "Figure.h"
#include <cstring>

Figure::Figure()
{
    this->color = WHITE;
    this->horizontalPosition = 'A';
    this->verticalPosition = 1;
    this->inGame = true;
}

Figure::Figure(Color color, char horizontalPosition, int verticalPosition)
{
    this->color = color;
    if(horizontalPosition >= 'A' && horizontalPosition <= 'H')
    {
        this->horizontalPosition = horizontalPosition;
    }
    else
        cout << "Not on the board!" << endl;
    if(verticalPosition >= 1 && verticalPosition <= 8)
    {
        this->verticalPosition = verticalPosition;
    }
    else
        cout << "Not on the board!" << endl;
    this->inGame = true;
}

char Figure::getHPosition() const
{
    return this->horizontalPosition;
}
int Figure::getVPosition() const
{
    return this->verticalPosition;
}

bool Figure::getColor() const
{
    return this->color;
}

bool Figure::getInGame() const
{
    return this->inGame;
}

void Figure::setInGame(bool inGame)
{
    this->inGame = inGame;
}

bool Figure::canMove(char horizontalPosition, int verticalPosition)
{
    if(horizontalPosition >= 'A' && horizontalPosition <= 'H')
    {
        if(verticalPosition >= 1 && verticalPosition <= 8)
        {
            return true;
        }
    }
    return false;
}

void Figure::move(char horizontalPosition, int verticalPosition)
{
    if(canMove(horizontalPosition, verticalPosition))
    {
        cout << this->color << " figure moved from " << this->horizontalPosition << this->verticalPosition;
        this->horizontalPosition = horizontalPosition;
        this->verticalPosition = verticalPosition;
        cout << " to " << this->horizontalPosition << verticalPosition;
    }
    else
    {
        cout << "The figure can't be moved!" << endl;
    }
}

void Figure::capture(Figure& other)
{
    if(this->color != other.color && canMove(other.horizontalPosition, other.verticalPosition))
    {
        this->move(other.horizontalPosition, other.verticalPosition);
        other.inGame = false;
        cout << " and captured " << other.color << " figure." << endl;
    }
    else
    {
        cout << "The figure can't be captured!" << endl;
    }
}

void Figure::revive(char horizontalPosition, int verticalPosition)
{
    if(canMove(horizontalPosition, verticalPosition))
    {
        this->horizontalPosition = horizontalPosition;
        this->verticalPosition = verticalPosition;
        this->inGame = true;
    }
    else
    {
        cout << "The figure can't be revived!" << endl;
    }
}



