#include "Hero.h"
#include "Mob.h"
#include "Horde.h"

int main()
{

    Hero hero("Manastorm", 100, 50, "Magician");
	Mob mob("Jaraxxus", 90, 10, 50);

	hero.talk("Hi");
	cout << "Hero name: " << hero.getName() << endl;
	cout << "Hero job: " << hero.getJob() << endl;
	cout << "Hero damage: " << hero.getDamage() << endl;
	cout << "Hero HP: " << hero.getHP() << endl;
	cout << "Hero exp: " << hero.getExp() << endl;
	cout << "Is he dead? " << boolalpha << hero.isDead() << endl << endl;

	cout << "Mob name: " << mob.getName() << endl;
	cout << "Mob damage: " << mob.getDamage() << endl;
	cout << "Mob HP: " << mob.getHP() << endl;
	cout << "Mob experience: " << mob.giveExperience() << endl;
	cout << "Is he dead? " << boolalpha << mob.isDead() << endl << endl;

	hero.attack(mob);
	hero.getLoot(mob);

	cout << endl << "Mob damage: " << mob.getDamage() << endl;
	cout << "Mob HP: " << mob.getHP() << endl;
	cout << "Mob experience: " << mob.giveExperience() << endl;
	cout << "Is he dead? " << boolalpha << mob.isDead() << endl << endl;

	mob.attack(hero);

	cout << endl << "Hero damage: " << hero.getDamage() << endl;
	cout << "Hero HP: " << hero.getHP() << endl;
	cout << "Hero exp: " << hero.getExp() << endl;
	cout << "Is he dead? " << boolalpha << hero.isDead() << endl << endl;

	hero.attack(mob);
	hero.getLoot(mob);

	cout << endl << "Hero damage: " << hero.getDamage() << endl;
	cout << "Hero HP: " << hero.getHP() << endl;
	cout << "Hero exp: " << hero.getExp() << endl;
	cout << "Is he dead? " << boolalpha << hero.isDead() << endl << endl;

	cout << "Mob damage: " << mob.getDamage() << endl;
	cout << "Mob HP: " << mob.getHP() << endl;
	cout << "Mob experience: " << mob.giveExperience() << endl;
	cout << "Is he dead? " << boolalpha << mob.isDead() << endl;

    Mob mob1, mob2;
    Mob mobs[2] = {mob, mob1};
    Horde horde(mobs, 3, "DefaultHordeName");
    Hero hero1("Default hero", 80, 2, "Something");
    horde.battle(hero1);

    return 0;
}
