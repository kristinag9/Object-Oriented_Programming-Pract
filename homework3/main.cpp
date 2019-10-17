#include <iostream>
#include "Figure.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"


using namespace std;

int main()
{
    Rook r1(BLACK, 'A', 8);
    r1.move('A', 1);
    r1.move('C', 9);
    Rook r2(WHITE, 'H', 1);
    r2.capture(r1);

    Bishop b1(BLACK, 'C', 8);
    b1.move('A', 6);
    b1.move('H', 8);
    Bishop b2(WHITE, 'F', 1);
    b1.capture(b2);

    Queen q1(BLACK, 'D', 8);
    q1.move('A', 5);
    q1.move('F', 4);
    Queen q2(WHITE, 'E', 1);
    q1.capture(q2);

    return 0;
}
