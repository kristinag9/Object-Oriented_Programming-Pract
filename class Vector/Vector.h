#pragma once
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Vector
{
private:
    double coordinates[3];
public:
    Vector(double = 0, double = 0, double = 0);

    void sum(const Vector&);
    void scale(double);
    double dotProduct(const Vector&) const;
    double getLength() const;

    void setX(double);
    void setY(double);
    void setZ(double);
    void setCoordinate(int, double);

    double getX() const;
	double getY() const;
	double getZ() const;
	double getCoordinate(int) const;

    void print() const;

    Vector operator+(const Vector&) const;
    Vector& operator+=(const Vector&);
    bool operator<(const Vector&) const;
    bool operator>(const Vector&) const;
    bool operator<=(const Vector&) const;
    bool operator>=(const Vector&) const;
    bool operator==(const Vector&) const;
    bool operator!=(const Vector&) const;

    Vector& operator++();
    Vector operator++(int);
    Vector& operator*=(int);

    friend Vector operator-(const Vector&, const Vector&);

    friend istream& operator>>(istream& in, Vector& vector);
	friend ostream& operator<<(ostream& out, const Vector& vector);

	double operator[](int index) const;
	double& operator[](int index);
};

