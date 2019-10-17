#include "Vector.h"

Vector operator-(const Vector& v1, const Vector& v2)
{
    Vector result;
    for(int i = 0; i < 3; i++)
    {
        result.coordinates[i] = v1.coordinates[i] - v2.coordinates[i];
    }
    return result;
}
Vector operator*(const Vector& v, int scalar)
{
    Vector result;
    for(int i = 0; i < 3; i++)
    {
        result.setCoordinate(i, v.getCoordinate(i) * scalar);
    }
    return result;
}
Vector operator*(int scalar, const Vector& v)
{
    return v * scalar;
}

int main()
{
    Vector v(1,2,3), v1(3,4,5), v2(1,3,0), v3(5,6), v4(1,2,3);
    cout << boolalpha << (v == v3) << endl;
    cout << boolalpha << (v == v4) << endl;
    cout << boolalpha << (v < v3) << endl;

    (v + v1).print();
    (v2 - v).print();

    (v++).print();
	v.print();
	(++v).print();
	v.print();

	cout << v[1] << endl;
	v[1] = 5;
	cout << v[1] << endl;

    cin >> v;
	cout << v;
	return 0;
}

