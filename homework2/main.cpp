#include "Set.h"

int main()
{
    Set s1;
    s1.addElement(4);
    s1.addElement(5);
    s1.addElement(6);
    s1.addElement(7);
    s1.addElement(8);
    cout << "Set1: " << endl;
    s1.print();
    /*
    s1.addElement(5);
    s1.print();
    s1.removeElement(2);
    s1.removeElement(4);
    s1.print();*/

    Set s2;
    s2.addElement(1);
    s2.addElement(3);
    s2.addElement(5);
    s2.addElement(7);
    s2.addElement(9);
    cout << "Set2: " << endl;
    s2.print();
    Set s3 = s2 + s1;
    cout << "Set3: " << endl;
    s3.print();
    Set s4 = s2 - s1;
    cout << "Set4: " << endl;
    s4.print();
    Set s5 = s4 * s2;
    cout << "Set5: " << endl;
    s5.print();
    Set s6 = s2 ^ s1;
    cout <<"Set6:" << endl;
    s6.print();
    cout << endl;

    cout << boolalpha << (s1 <= s2) << endl;
    cout << boolalpha << (s3 >= s4) << endl;
    cout << boolalpha << (s6 == s5) << endl;
    cout << boolalpha << (s4 == s5) << endl;

    return 0;
}
