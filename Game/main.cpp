#include "Weapon.h"
#include "Fighter.h"

int main()
{
    Weapon w1("sword", 5, 5);
    Weapon w2("mechka", 7, 3);
    Fighter f1("name1", 5, 100, w1);
    Fighter f2("name2", 8, 90, w2);

    Weapon weapons[10];

    while(!f1.isDead() && !f2.isDead())
    {
        f1.attack(f2);
        if(f2.isDead()) break;
        f2.attack(f1);
    }

    if(f1.isDead()) cout << f2.getName() << " won!" << endl;
    else cout<< f1.getName() << " won! " << endl;

    return 0;
}
