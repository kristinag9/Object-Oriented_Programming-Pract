#pragma once
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Drawer
{
private:
    T* objects[50];
    size_t index;
    size_t capacity;
public:
    Drawer(size_t capacity);
    void push(const T element, size_t _index);
    void addElem(const T element);
    void pop(size_t _index);
    void removeElem(const T element);
    size_t getObjects() const;
    bool isEmpty() const;
    bool isFull() const;
    bool isIn(const T element) const;
    void printDrawer() const;

    bool operator==(const Drawer<T>& other) const;
    friend ostream& operator<<(ostream& out, const Drawer<T>& drawer);
};

template <typename T>
Drawer<T>::Drawer(size_t capacity)
{
    if(this->capacity >= 0 && this->capacity <= 50)
    {
        this->index = 0;
        this->capacity = capacity;
    }
    else
    {
        cout << "Out of capacity." << endl;
    }
}
template <typename T>
void Drawer<T>::push(const T element, size_t _index)
{
    this->index++;
    if (isFull())
    {
       cout << "You are not allowed to push this element." << endl;
       this->index--;
    }
    for(size_t i = this->index -1; i > _index;i--)
    {
      this->objects[i] = this->objects[i-1];
    }

    this->objects[_index] = element;
}
template <typename T>
void Drawer<T>::addElem(const T element)
{
    if(isFull())
    {
        cout << "The drawer is full!" << endl;
        return;
    }
    else
    {
        this->objects[this->index] = element;
        this->index++;
    }
}
template <typename T>
void Drawer<T>::pop(size_t _index)
{
    for(size_t i = _index; i < this->index; i++)
    {
      this->objects[i] = this->objects[i + 1];
    }
    this->index--;

}
template <typename T>
void Drawer<T>::removeElem(const T element)
{
    if(isIn(element))
    {
        for(size_t i = 0; i < this->index; i++)
        {
            if(this->objects[i] == element)
            {
                this->pop(i);
            }
        }
    }
    else
    {
        cout << "There is no such an element." << endl;
    }
}
template <typename T>
size_t Drawer<T>::getObjects() const
{
    return this->index + 1;
}
template <typename T>
bool Drawer<T>::isEmpty() const
{
    return this->index == 0;
}
template <typename T>
bool Drawer<T>::isFull() const
{
    return this->index >= this->capacity;
}
template <typename T>
bool Drawer<T>::isIn(const T element) const
{
    assert(!isEmpty());
    for(size_t i = 0; i < this->index; i++)
    {
        if(this->objects[i] == element)
        {
            return true;
        }
        return false;
    }
}
template <typename T>
void Drawer<T>::printDrawer() const
{
    for(size_t i = 0; i < this->index; i++)
    {
        cout << this->elements[i] << " ";
    }
    cout << endl;
}
template <typename T>
bool Drawer<T>::operator==(const Drawer<T>& other) const
{
    for (size_t i = 0; i < this->index; ++i)
    {
        if (this->objects[i] != other.objects[i])
        {
            return false;
        }
    }
    return true;
}
template <typename T>
ostream& operator<<(ostream& out, const Drawer<T>& drawer)
{
	for (size_t i = 0; i < drawer.index; i++)
	{
		out << drawer.objects[i] << " ";
	}
	return out;
}

/* Class Cabinet */
template <typename T>
class Cabinet
{
private:
    Drawer<T>& drawers;
    size_t numberOfObjects;
    size_t capacity;
    void erase();
    void copy(const Cabinet<T>& other);
public:
    Cabinet(const Drawer<T>* arr, size_t numberOfObjects);
    Cabinet(const Cabinet<T>& other);
    Cabinet<T>& operator=(const Cabinet<T>& other);
    ~Cabinet();
    void addObject(const T element, size_t index);
    void removeObject(const T element, size_t index);
    void removeFromFirst(const T element);
    void printCabinet() const;
};

template <typename T>
void Cabinet<T>::erase()
{
    delete [] this->drawers;
}
template <typename T>
void Cabinet<T>::copy(const Cabinet<T>& other)
{
    this->numberOfObjects = other.numberOfObjects;
    this->capacity = other.capacity;
    this->drawers = new T[this->capacity];
    for(size_t i = 0; i < this->numberOfObjects; i++)
    {
        this->drawers[i] = other.drawers[i];
    }
}
template <typename T>
Cabinet<T>::Cabinet(const Drawer<T>* arr, size_t numberOfObjects)
{
    this->numberOfObjects = numberOfObjects;
    this->drawers = new Drawer<T>[this->numberOfObjects];
    for (int i = 0; i < this->numberOfObjects; ++i)
    {
        this->drawers[i] = drawers[i];
    }
}
template<typename T>
Cabinet<T>::Cabinet(const Cabinet<T>& other)
{
    this->copy(other);
}
template<typename T>
Cabinet<T>& Cabinet<T>::operator=(const Cabinet<T>& other)
{
    if (this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}
template <typename T>
Cabinet<T>::~Cabinet()
{
    this->erase();
}
template<typename T>
void Cabinet<T>::addObject(const T element, size_t index)
{
    drawers[index].push(element, index);
}
template <typename T>
void Cabinet<T>::removeObject(const T element, size_t index)
{
    for (size_t i = 0; i < this->numberOfObjects; ++i)
    {
        if(drawers[i].isIn(element))
        {
            drawers[i].addElem(element);
            break;
        }
    }
    if(!isIn(element))
    {
        cout << "The drawer does not contain this element." << endl;
    }
}
template <typename T>
void Cabinet<T>::printCabinet() const
{
    for(size_t i = 0; i < this->numberOfObjects; ++i)
    {
        drawers[i].printDrawer();
    }
    cout << endl;
}

