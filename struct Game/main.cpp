#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

struct Weapon
{
    char name[20];
    int power;
    int durability;

    int use()
    {
        if(durability <= 0)
     {
         return 0;
     }
     durability--;
     return power;
    }

     void inizializeWeapon(const char newName[20], int newPower, int newDurability)
     {
         strcpy(name, newName);
         assert(newPower >= 0);
         power = newPower;
         assert(newDurability >= 0);
         durability = newDurability;
         cout << "Weapon " << name << " created with power " << power << " and durability " << durability << endl;
     }
};

struct Fighter
{
    char name[20];
    int strength;
    int health;
    Weapon weapon;

    void initializeFighter(const char newName[20], int newStrength, int newHealth, Weapon newWeapon)
    {
        strcpy(name, newName);
        assert(newStrength >= 0);
        strength = newStrength;
        assert(newHealth >= 0);
        health = newHealth;
        weapon = newWeapon;
        cout << "Fighter " << name << " with strength " << strength << " , health " << health << " and weapon " << weapon.name << endl;
    }

    void attack(Fighter& enemy)
    {
        int weaponAttack = weapon.use();
        int totalAttack = weaponAttack + strength;
        enemy.health -= totalAttack;
        cout << "Fighter " << name << " attacked " << enemy.name << "with attack " << totalAttack << endl;
        cout << enemy.name << " left with " << health << " health " << endl;
    }

    bool isDeath()
    {
        return health <= 0;
    }

    void equip(const Weapon& newWeapon)
    {
        weapon = newWeapon;
    }
};

int main()
{
    Weapon w1;
    w1.inizializeWeapon("sword", 5, 5);
    Weapon w2;
    w2.inizializeWeapon("mechka", 7, 3);
    Fighter f1;
    f1.initializeFighter("Pesho", 5, 100, w1);
    Fighter f2;
    f2.initializeFighter("Gosho", 8, 89, w2);

    while(!f1.isDeath() && !f2.isDeath())
    {
        f1.attack(f2);
        if(f2.isDeath()) break;
        f2.attack(f1);
    }
    if(f1.isDeath())
        cout << f2.name << " won!" << endl;
    else
        cout << f1.name << " won!" << endl;



    return 0;
}
