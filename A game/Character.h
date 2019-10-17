#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Character
{
private:
	char* name;
	int hp;
	int damage;

protected:
	void gainHP(int);
	void gainDamage(int);

public:
	Character();
	Character(const Character&);
	Character& operator=(const Character&);
	~Character();

	Character(const char*, int, int);

	bool isDead() const;
	void attack(Character&);
	const char* getName() const;
	int getHP() const;
	int getDamage() const;

	friend ostream& operator<<(ostream& os, const Character& character)
	{
	    os << character.name << endl;
	    os << character.hp << endl;
	    os << character.damage << endl;

	    return os;
	}
};
