#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Planet
{
    char name[26];
    double sunDistance;
    double diameter;
    double mass;
};

void setPlanet(Planet& planet)
{
    cout << "Enter a name: ";
    cin >> planet.name;
    cout << "Enter distance between planet and the Sun: ";
    cin >> planet.sunDistance;
    cout << "Enter planet diameter: ";
    cin >> planet.diameter;
    cout << "Enter planet mass: ";
    cin >> planet.mass;
}
void printPlanet(const Planet& planet)
{
    cout << "Printing planet...";
    cout << "Planet name: " << planet.name << endl;
    cout << "Distance between the planet and the Sun: " << planet.sunDistance << endl;
    cout << "Planet diameter: " << planet.diameter << endl;
    cout << "Planet mass: " << planet.mass << endl;
}
int getSecondsFromSun(const Planet& p)
{
    int speedOfLight = 299792;
    return p.sunDistance/speedOfLight;
}
Planet getPlanetWithBiggestDiameter(Planet planets[], int planetCount)
{
    Planet max = planets[0];
    for(int i = 1; i < planetCount; i++)
    {
        if(planets[i].diameter > max.diameter)
        {
            max = planets[i];
        }
    }
    return max;
}
Planet getPlanetWithSmallestMass(Planet planets[], int planetCount)
{
    Planet min = planets[0];
    for(int i = 1; i < planetCount; i++)
    {
        if(planets[i].mass < min.mass)
        {
            min = planets[i];
        }
    }
    return min;
}
Planet getFurthestPlanet(Planet planets[], int planetCount)
{
    Planet furthest = planets[0];
    for(int i = 1; i < planetCount; i++)
    {
        if(planets[i].sunDistance > furthest.sunDistance)
        {
            furthest = planets[i];
        }
    }
    return furthest;
}
Planet getClosestPlanet(Planet planets[], int planerCount)
{
    Planet closest = planets[0];
    for(int i = 1; i < planerCount; i++)
    {
        if(planets[i].sunDistance < closest.sunDistance)
        {
            closest = planets[i];
        }
    }
    return closest;
}

int main()
{
    const int PLANET_COUNT = 3;
    Planet planets[PLANET_COUNT];
    for(int i = 0; i < PLANET_COUNT; i++)
    {
        cout << "Planet: " << i + 1 << ":" << endl;
        setPlanet(planets[i]);
    }

    for(int i = 0; i < PLANET_COUNT; i++)
    {
        printPlanet(planets[i]);
    }

    Planet biggestDiameter = getPlanetWithBiggestDiameter(planets, PLANET_COUNT);
    cout << "Planet with biggest diameter: " << endl;
    printPlanet(biggestDiameter);

    Planet smallestMass = getPlanetWithSmallestMass(planets, PLANET_COUNT);
    cout << "Planet with smallest mass: " << endl;
    printPlanet(smallestMass);

    Planet furthest = getFurthestPlanet(planets, PLANET_COUNT);
    cout << "The furthest planet: " << endl;
    printPlanet(furthest);

    Planet closest = getClosestPlanet(planets, PLANET_COUNT);
    cout << "The closest planet: " << endl;
    printPlanet(closest);

    return 0;
}
