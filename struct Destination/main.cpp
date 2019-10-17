#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Destination
{
    char city[32];
    int kilometers;
};

int main()
{
    Destination plovdiv = {"Plovdiv", 165};
    Destination varna = {"Varna", 469};

    cout << setw(8) << left << plovdiv.city << plovdiv.kilometers << endl;
    cout << setw(8) << left << varna.city << varna.kilometers << endl;

    Destination destArray[30];

    for(int i = 0; i < 30; i++)
    {
        strcpy(destArray[i].city, "");
        destArray[i].kilometers = 0;
    }
    for(int i = 0; i < 30; i++)
    {
        cout << setw(8) << destArray[i].city << destArray[i].kilometers << endl;
    }

    Destination initializedArray[5] =
    {   {"Plovdiv", 165},
        {"Varna", 469},
        {"Burgas", 393},
        {"Vidin", 199},
        {"Dobrich", 512}
    };
    for(int i = 0; i < 5; i++)
    {
        cout << setw(8) << initializedArray[i].city << initializedArray[i].kilometers << endl;
    }


    return 0;
}
