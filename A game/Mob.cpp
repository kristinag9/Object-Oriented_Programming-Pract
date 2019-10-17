#include "Mob.h"
#include "Character.h"

Mob::Mob()
{
    this->experience = 0;
}

Mob::Mob(const char* name, int hp, int damage, int experience) : Character(name, hp, damage)
{
	this->experience = experience;
}

int Mob::giveExperience() const
{
	return this->experience;
}
