#include "Set.h"
#include <cassert>

void Set::resize()
{
    int* tempElements = new int[2 * this->capacity + 1];
    this->capacity = 2 * this->capacity + 1;
    for(size_t i = 0; i < this->size; i++)
    {
        tempElements[i] = this->elements[i];
    }
    delete [] this->elements;
    this->elements = tempElements;
}
void Set::copy(const Set& other)
{
    this->elements = new int[other.capacity];
    this->capacity = other.capacity;
    this->size = other.size;
    for(size_t i = 0; i < this->size; i++)
    {
        this->elements[i] = other.elements[i];
    }
}
void Set::erase()
{
    delete [] this->elements;
}

Set::Set(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->elements = new int[capacity];
}

Set::Set(const Set& other)
{
    this->copy(other);
}
Set& Set::operator=(const Set& other)
{
    if(this != &other)
    {
        this->erase();
    }
}

Set::~Set()
{
    this->erase();
}

void Set::addElement(int element)
{
    if(this->size >= this->capacity)
    {
        this->resize();
    }
    if(containsElement(element))
    {
        cout << "The element is already in the set.\n";
        return;
    }
    else
    {
        this->elements[this->size] = element;
        this->size++;
    }
}

void Set::pop(int index)
  {
    for(int i = index; i < this->size; i++)
    {
      this->elements[i] = this->elements[i + 1];
    }
    this->size--;
}

void Set::removeElement(int element)
{
    if(containsElement(element))
    {
        for(int i = 0; i < this->size; i++)
        {
            if(this->elements[i] == element)
            {
                this->pop(i);
                break;
            }
        }
    }
    else
    {
        cout << "The element is not in the set.\n";
    }
}
bool Set::isEmpty() const
{
    return this->size == 0;
}

bool Set::containsElement(int element) const
{
    for(size_t i = 0; i < this->size; i++)
    {
        if(this->elements[i] == element)
        {
            return true;
        }
    }
    return false;
}

int Set::getSize() const
{
    return this->size;
}

Set Set::operator+(const Set& other) const
{
    Set result;
    result.size = 0;
    result.capacity = this->capacity + other.capacity;
    result.elements = new int [result.capacity];
    for (int i = 0; i < this->size; i++)
    {
        result.elements[result.size] = this->elements[i];
        result.size++;
    }
    for(int i = 0; i < other.size; i++)
    {
        if(containsElement(other.elements[i]) == false)
        {
            result.elements[result.size] = other.elements[i];
            result.size++;
        }
    }
    return result;

}
Set Set::operator-(const Set& other) const
{
    Set result;
    result.size = 0;
    result.capacity = this->capacity + other.capacity;
    result.elements = new int [result.capacity];
    for(int i = 0; i < this->size; i++)
    {
        if (other.containsElement(this->elements[i]) == false)
        {
            result.elements[result.size] = this->elements[i];
            result.size++;
        }
    }
    return result;
}
Set Set::operator*(const Set& other) const
{
    Set result;
    result.size = 0;
    result.capacity = this->capacity + other.capacity;
    result.elements = new int [result.capacity];
    for(int i = 0; i < this->size; i++)
    {
        if (other.containsElement(this->elements[i]))
        {
            result.elements[result.size] = this->elements[i];
            result.size++;
        }
    }
    return result;
}
Set Set::operator^(const Set& other) const
{
    Set result;
    result.size = 0;
    result.capacity = this->capacity + other.capacity;
    result.elements = new int [result.capacity];
    for(int i = 0; i < this->size; i++)
    {
        if(other.containsElement(this->elements[i]) == false)
        {
            result.elements[result.size] = this->elements[i];
            result.size++;
        }
    }
    for(int i = 0; i < other.size; ++i)
    {
        if (containsElement(other.elements[i]) == false)
        {
            result.elements[result.size] = other.elements[i];
            result.size++;
        }
    }
    return result;
}
bool Set::operator!() const
{
    if(isEmpty())
    {
        return true;
    }
    return false;
}
Set::operator bool() const
{
    for (int i = 0; i < this->size; i++)
	{
		if (elements[i] != 0)
			return true;
	}
	return false;
}
bool Set::operator<=(const Set& other) const
{
    for (int i = 0; i < other.size; i++)
    {
        if(!(containsElement(other.elements[i])))
        {
            return false;
        }
    }
    return true;
}
bool Set::operator>=(const Set& other) const
{
    for(int i = 0; i < this->size; i++)
    {
        if (!(other.containsElement(this->elements[i])))
        {
            return false;
        }
    }
    return true;
}
bool Set::operator==(const Set& other) const
{
    for (int i = 0; i < this->size; i++)
	{
		if (elements[i] != other.elements[i])
		{
			return false;
		}
	}
	return true;
}
Set& Set::operator+=(const Set& other)
{
    Set result = *this;
    *this = (result + other);
	return *this;
}
Set& Set::operator-=(const Set& other)
{
    Set result;
    *this = (result - other);
	return *this;
}

ostream& operator<<(ostream& out, const Set& set)
{
	for (int i = 0; i < set.getSize(); i++)
	{
		out << set.elements[i] << " ";
	}
	return out;
}

void Set::print() const
{
    for(int i = 0; i < this->size; i++)
    {
        cout << this->elements[i] << " ";
    }
    cout << endl;
}
