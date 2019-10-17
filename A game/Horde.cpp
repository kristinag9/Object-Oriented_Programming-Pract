#include <iostream>
#include "Horde.h"
#include "Character.h"
#include "Hero.h"

using namespace std;

Horde::Horde() : Stack<Mob>()
{
    this->hordeName = new char[strlen(hordeName) + 1];
    strcpy(this->hordeName, "Default");
}

Horde::Horde(const Horde& other) : Stack<Mob>(other)
{
    this->copy(other);
}

Horde& Horde::operator=(const Horde& other)
{

    if(this != &other)
    {
        Stack<Mob>::operator=(other);
        this->erase();
        this->copy(other);
    }
    return *this;
}

Horde::~Horde()
{
    this->erase();
}

Horde::Horde(const Mob* mobs, int stackSize, const char* hordeName) : Stack<Mob>()
{
    this->hordeName = new char[strlen(hordeName) + 1];
    strcpy(this->hordeName, hordeName);
    for(int i = 0; i < getSize(); i++)
    {
        push(mobs[i]);
    }
}

const char* Horde::getHordeName() const
{
    return this->hordeName;
}

void Horde::addMob(const Mob& mob)
{
    /*Stack::*/push(mob);
}

void Horde::battle(Hero& hero)
{
    while(!hero.isDead() && (!isEmpty()))
    {
        while(top().isDead() && hero.isDead())
        {
            if(top().isDead())
            {
                //cout << this->top() << " is dead. " << hero.getName() << " is the winner." << endl;
                break;
            }
        top().attack(hero);
        cout << top().getName() << " attacked " << hero.getName() << " causing " << top().getDamage() << endl;
        cout << top() << " with name " << getHordeName() << " is the winner." << endl;
        }
        if(this->top().isDead())
        {
           pop();
        }
    }
}
