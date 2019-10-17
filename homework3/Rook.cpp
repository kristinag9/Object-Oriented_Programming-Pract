#include <cstring>
#include "Rook.h"

Rook::Rook(Color color, char horizontalPosition, int verticalPosition) : Figure(color, horizontalPosition, verticalPosition) {}

bool Rook::canMove(char rookHPosition, int rookVPodition)
{

    if(rookHPosition == getHPosition() || rookVPodition == getVPosition())
    {
        if(rookHPosition >= 'A' && rookHPosition <= 'H')
        {
            if(rookVPodition >= 1 && rookVPodition <= 8)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}

void Rook::move(char rookHPosition, int rookVPosition)
{
    if(canMove(rookHPosition, rookVPosition))
    {
        cout << this->color << " rook moved from " << this->horizontalPosition << this->verticalPosition;
        this->horizontalPosition = rookHPosition;
        this->verticalPosition = rookVPosition;
        cout << " to " << this->horizontalPosition << verticalPosition << endl;
    }
    else
    {
        cout << "The rook can't be moved!" << endl;
    }
}

void Rook::capture(Figure& other)
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
