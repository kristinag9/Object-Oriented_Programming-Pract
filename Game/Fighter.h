#pragma once
#include "Weapon.h"

class Fighter
{
private:
    char name[32];
    int strength;
    int health;
    Weapon weapon;
public:
    Fighter(const char*, int, int, Weapon);

    const char* getName();

    void attack(Fighter&);

    bool isDead();

    void equip(const Weapon&);
};
