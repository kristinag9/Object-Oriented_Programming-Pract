#pragma once
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class Weapon
{
private:
    char name[20];
    int power;
    int durability;
public:
    Weapon();
    Weapon(const char*, int, int);
    int use();
    const char* getName() const;
};
