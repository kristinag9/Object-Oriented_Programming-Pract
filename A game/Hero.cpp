#include "Hero.h"

Hero::Hero()
{
	this->job = new char[30];
	strcpy(job, "mage");
	exp = 0;
}

Hero::~Hero()
{
	delete[] this->job;
}

Hero::Hero(const Hero& other) : Character(other)
{
	this->job = new char[strlen(other.job) + 1];
	strcpy(job, other.job);
	this->exp = other.exp;
}

Hero& Hero::operator=(const Hero& other)
{
	if (this != &other)
	{
		Character::operator=(other);
		delete[] job;
		this->job = new char[strlen(other.job) + 1];
		strcpy(job, other.job);
		this->exp = other.exp;
	}
	return *this;
}

Hero::Hero(const char* name, int hp, int damage, const char* job) : Character(name, hp, damage)
{
	this->job = new char[strlen(job) + 1];
	strcpy(this->job, job);
	this->exp = 0;
}

void Hero::talk(const char* something)
{
	cout << getName() << " the " << job << " said: " << something << endl;
}

const char* Hero::getJob() const
{
	return this->job;
}

void Hero::getLoot(const Mob& mob)
{
	if (mob.isDead())
	{
		this->exp += mob.giveExperience();
		if (this->exp >= 100)
        {
            levelUp();
        }
	}
}

int Hero::getExp() const
{
	return this->exp;
}

void Hero::levelUp()
{
	this->exp -= 100;
	this->gainHP(100);
	this->gainDamage(20);
}
