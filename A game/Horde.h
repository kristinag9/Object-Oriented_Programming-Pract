#pragma once
#include "Mob.h"
#include "Hero.h"
#include "Stack.hpp"

class Horde : public Stack<Mob>
{
private:
    char* hordeName;

    void copy(const Horde& other)
    {
        this->hordeName = new char[strlen(other.hordeName) + 1];
        strcpy(hordeName,other.hordeName);
    }
    void erase()
    {
        delete [] this->hordeName;
    }

public:
    Horde();
    Horde(const Horde&);
    Horde& operator=(const Horde&);
    ~Horde();

    Horde(const Mob* mobs, int stackSize, const char* hordeName);
    const char* getHordeName() const;
    void addMob(const Mob&);
    void battle(Hero&);

    friend ostream& operator<<(ostream& os, const Horde& horde)
    {
        os << (Mob&)horde;
        os << (Character&)horde;
        os << horde.hordeName << endl;
    }

};
