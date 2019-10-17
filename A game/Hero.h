#pragma once
#include "Character.h"
#include "Mob.h"

class Hero : public Character
{
	char* job;
	int exp;

public:
	Hero();
	~Hero();
	Hero(const Hero&);
	Hero& operator=(const Hero&);

	Hero(const char*, int, int, const char*);

	void getLoot(const Mob& mob);

	void talk(const char*);
	const char* getJob() const;
	int getExp() const;

	friend ostream& operator<<(ostream& os, const Hero& hero)
	{
	    os << (Character&)hero;
	    os << hero.job << endl;
	    os << hero.exp << endl;
	}

private:
	void levelUp();
};
