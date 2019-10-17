#pragma once
#include "Character.h"

using namespace std;

class Mob : public Character
{
private:
	int experience;
public:
    Mob();
	Mob(const char*, int, int, int);
	int giveExperience() const;

	friend ostream& operator<<(ostream& os, const Mob& mob)
	{
	    os << (Character&)mob;
	    os << mob.experience << endl;
	}
};
