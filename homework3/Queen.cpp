#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

Queen::Queen(Color color, char horizontalPosition, int verticalPosition) : Figure(color, horizontalPosition, verticalPosition),
       Rook(color, horizontalPosition, verticalPosition),Bishop(color, horizontalPosition, verticalPosition) {}
bool Queen::canMove(char queenHPosition, int queenVPosition)
{
    if(Rook::canMove(queenHPosition,queenVPosition) || Bishop::canMove(queenHPosition,queenVPosition))
    {
        return true;
    }
    return false;
}

void Queen::move(char queenHPosition, int queenVPosition)
{
    if(canMove(queenHPosition, queenVPosition))
    {
        cout << this->color << " queen moved from " << this->horizontalPosition << this->verticalPosition;
        this->horizontalPosition = queenHPosition;
        this->verticalPosition = queenVPosition;
        cout << " to " << this->horizontalPosition << this->verticalPosition << endl;
    }
    else
    {
        cout << "The queen can't be moved!" << endl;
    }
}

void Queen::capture(Figure& other)
{
    if(this->color != other.getColor() && canMove(other.getHPosition(), other.getVPosition()))
    {
        this->move(other.getHPosition(), other.getVPosition());
        other.setInGame(false);
        cout << " and captured " << other.getColor() << " figure." << endl;
    }
    else
    {
        cout << "The figure can't be captured!" << endl;
    }
}
