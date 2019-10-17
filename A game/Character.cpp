#include "Character.h"

Character::Character()
{
	this->name = new char[30];
	strcpy(name, "Average Joe");
	this->hp = 10;
	this->damage = 3;
}

Character::Character(const Character& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(name,other.name);
	this->hp = other.hp;
	this->damage = other.damage;
}
Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		delete[] this->name;
		this->name = new char[strlen(other.name) + 1];
		strcpy(name,other.name);
		this->hp = other.hp;
		this->damage = other.damage;
	}
	return *this;
}

Character::~Character()
{
	delete[] this->name;
}

Character::Character(const char* name, int hp, int damage)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name,name);
	this->hp = hp;
	this->damage = damage;
}

bool Character::isDead() const
{
	return hp <= 0;
}

const char* Character::getName() const
{
	return this->name;
}

int Character::getHP() const
{
	return this->hp;
}

int Character::getDamage() const
{
	return this->damage;
}

void Character::attack(Character& other)
{
	other.hp -= this->damage;
	cout << this->name << " attacked " << other.name << " causing " << this->damage << " damage." << endl;
}

void Character::gainHP(int bonus)
{
	this->hp += bonus;
}

void Character::gainDamage(int bonus)
{
	this->damage += bonus;
}
