#include "Figure.h"
#include "Bishop.h"

Bishop::Bishop(Color color, char horizontalPosition, int verticalPosition) : Figure(color, horizontalPosition, verticalPosition) {}

bool Bishop::canMove(char bishopHPosition, int bishopVPosition)
{
    if(abs(this->horizontalPosition - bishopHPosition) == abs(this->verticalPosition - bishopVPosition))
    {
        if(bishopHPosition >= 'A' && bishopHPosition <= 'H')
        {
            if(bishopVPosition >= 1 && bishopVPosition <= 8)
            {
                return true;
            }
        }
    }
    return false;
}

void Bishop::move(char bishopHPosition, int bishopVPosition)
{
    if(canMove(bishopHPosition, bishopVPosition))
    {
        cout << this->color << " bishop moved from " << this->horizontalPosition << this->verticalPosition;
        this->horizontalPosition = bishopHPosition;
        this->verticalPosition = bishopVPosition;
        cout << " to " << this->horizontalPosition << this->verticalPosition << endl;
    }
    else
    {
        cout << "The bishop can't be moved!" << endl;
    }
}

void Bishop::capture(Figure& other)
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
