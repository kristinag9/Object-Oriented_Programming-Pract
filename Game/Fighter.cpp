#include "Fighter.h"

Fighter::Fighter(const char* newName, int newStrength, int newHealth, Weapon newWeapon)
{
    strcpy(name, newName);
    assert(newStrength >= 0);
    strength = newStrength;
    assert(newHealth >= 0);
    health = newHealth;
    weapon = newWeapon;
    cout << "Fighter " << name << " created with strength " << strength << " , health " << health << " and weapon " << weapon.getName() << endl;
}

const char* Fighter::getName()
{
    return name;
}

void Fighter::attack(Fighter& enemy)
{
    int weaponAttack = weapon.use();
    int totalAttack = weaponAttack + strength;
    enemy.health -= totalAttack;
    cout << "Fighter " << name << " attacked " << enemy.name << " with attack " << totalAttack << endl;
    cout << enemy.name << " left with " << enemy.health << endl;
}

bool Fighter::isDead()
{
    return health <= 0;
}

void Fighter::equip(const Weapon& newWeapon)
{
    weapon = newWeapon;
}


