#pragma once
#include <iostream>

using namespace std;

class Set
{
private:
    int* elements;
    int size;
    int capacity;
    void resize();
    void copy(const Set& other);
    void erase();
public:
    Set(int capacity = 16);
    Set(const Set& other);
    Set& operator=(const Set& other);
    ~Set();
    void addElement(int element);
    void pop(int index);
    void removeElement(int element);
    bool isEmpty() const;
    bool containsElement(int element) const;
    int getSize() const;
    void print() const;

    Set operator+(const Set& other) const;
    Set operator-(const Set& other) const;
    Set operator*(const Set& other) const;
    Set operator^(const Set& other) const;
    bool operator!() const;
    operator bool() const;
    bool operator<=(const Set& other) const;
    bool operator>=(const Set& other) const;
    bool operator==(const Set& other) const;
    Set& operator+=(const Set& other);
    Set& operator-=(const Set& other);
    friend ostream& operator<<(ostream& out, const Set& set);
};
