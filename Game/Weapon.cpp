#include "Weapon.h"

Weapon::Weapon()
{
    strcpy(this->name, "Default");
    this->power = 0;
    this->durability = 0;
}

Weapon::Weapon(const char* name = " " , int power = 1, int durability = 5)
{
    strcpy(this->name, name);
    assert(power >= 0);
    this->power = 2*power;
    assert(durability >= 0);
    this->durability = durability;
    cout << "Weapon " << name << " with power " << power << " and durability " << durability << endl;
}
int Weapon::use()
{
    int durability = 5;
    if(this->durability <= 0)
    {
        return 0;
    }
    this->durability--;
    return power;
}
const char* Weapon::getName() const
{
    return name;
}
