#include "Vector.h"

 Vector::Vector(double x, double y, double z)
 {
     coordinates[0] = x;
     coordinates[1] = y;
     coordinates[2] = z;
 }

void Vector::sum(const Vector& other)
{
    for(int i = 0; i < 3; i++)
    {
        coordinates[i] = coordinates[i] + other.coordinates[i];
    }
}
void Vector::scale(double k)
{
    for(int i = 0; i < 3; i++)
    {
        coordinates[i] = coordinates[i] * k;
    }
}

double Vector::dotProduct(const Vector& other) const
{
    double product = 0;
    for(int i = 0; i < 3; i++)
    {
        product += coordinates[i] * other.coordinates[i];
    }
    return product;
}

double Vector::getLength() const
{
    double length = 0;
    for(int i = 0; i < 3; i++)
    {
        length += coordinates[i] * coordinates[i];
    }
    return sqrt(length);
}
void Vector::setX(double x)
{
    coordinates[0] = x;
}
void Vector::setY(double y)
{
    coordinates[1] = y;
}
void Vector::setZ(double z)
{
    coordinates[2] = z;
}
void Vector::setCoordinate(int i, double value)
{
    coordinates[i] = value;
}
double Vector::getX() const
{
    return coordinates[0];
}
double Vector::getY() const
{
    return coordinates[1];
}
double Vector::getZ() const
{
    return coordinates[2];
}
double Vector::getCoordinate(int i) const
{
    return coordinates[i];
}
void Vector::print() const
{
    for(int i = 0; i < 3; i++)
    {
        cout << "(" << coordinates[0] << "," << coordinates[1] << "," << coordinates[2] << ")" << endl;
    }
}

Vector Vector::operator+(const Vector& other) const
{
    Vector result;
    for(int i = 0; i < 3; i++)
    {
        result.setCoordinate(i, coordinates[i] + other.coordinates[i]);
    }
    return result;
}
Vector& Vector::operator+=(const Vector& other)
{
    *this = *this + other;
    return *this;
}

bool Vector::operator<(const Vector& other) const
{
    for(int i = 0; i < 3; i++)
    {
        if(coordinates[i] >= other.coordinates[i])
        {
            return false;
        }
    }
    return true;
}
bool Vector::operator>(const Vector& other) const
{
    return other < (*this);
}
bool Vector::operator<=(const Vector& other) const
{
    return (*this < other) || (*this == other);
}
bool Vector::operator>=(const Vector& other) const
{
    return (*this > other) || (*this == other);
}
bool Vector::operator==(const Vector& other) const
{
    for(int i = 0; i < 3; i++)
    {
        if(coordinates[i] != other.coordinates[i])
        {
            return false;
        }
    }
    return true;
}
bool Vector::operator!=(const Vector& other) const
{
    return !(*this == other);
}
Vector& Vector::operator++()
{
    for(int i = 0; i < 3; i++)
    {
        coordinates[i] += 1;
    }
    return *this;
}
Vector Vector::operator++(int a)
{
    Vector oldValue = *this;
    ++(*this);
    return oldValue;
}
Vector& Vector::operator*=(int scalar)
{
    for(int i = 0; i < 3; i++)
    {
        coordinates[i] *= scalar;
    }
    return *this;
}
istream& operator>>(istream& in, Vector& vector)
{
    for(int i = 0; i < 3; i++)
    {
        cout << "Enter " << i << "th coordinate: ";
        in >> vector.coordinates[i];
    }
    return in;
}
ostream& operator<<(ostream& out, const Vector& vector)
{
    for(int i = 0; i < 3; i++)
    {
        out << vector.coordinates[i];
    }
    return out;
}
double Vector::operator[](int index) const
{
    assert(index >= 0 || index < 3);
    cout << "operator[]" << endl;
    return coordinates[index];
}
double& Vector::operator[](int index)
{
    assert(index >= 0 || index < 3);
    cout << "operator[]" << endl;
    return coordinates[index];
}
