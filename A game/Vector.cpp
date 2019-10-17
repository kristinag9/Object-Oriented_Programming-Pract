#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class Vector
{
	T* arr;
	int size;

public:
    Vector(int = 4);
	~Vector();
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);

	void set(int, const T&);
	const T& get(int) const;
	void readArray();
	int getSize() const;
	void print() const;
	T& operator[](int index);
	const T& operator[](int index) const;

protected:
	void doubleSize();

	friend ostream& operator<<(ostream& out, const Vector& vector)
{
	for (int i = 0; i < 3; i++)
	{
		out << vector.coordinates[i] << " ";
	}
	return out;
}

};

template<typename T>
Vector<T>::Vector(int size)
{
	this->size = size;
	arr = new T[size];
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] arr;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->size = other.size;
	this->arr = new T[this->size];

	for (int i = 0; i < size; i++)
	{
	    arr[i] = other.arr[i];
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		delete[] this->arr;
		this->size = other.size;
		this->arr = new T[this->size];
		for (int i = 0; i < this->size; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	return *this;
}

template<typename T>
void Vector<T>::set(int index, const T& value)
{
	if (index < 0 || index >= size)
	{
		cout << "Wrong index!" << endl;
	}
	else
	{
		arr[index] = value;
	}
}

template<typename T>
const T& Vector<T>::get(int index) const
{
	assert(index >= 0 && index < size);
	return this->arr[index];
}

template<typename T>
void Vector<T>::readArray()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << "Enter element " << i + 1 << ": ";
		cin >> arr[i];
	}
}

template<typename T>
int Vector<T>::getSize() const
{
	return this->size;
}

template<typename T>
void Vector<T>::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<typename T>
T& Vector<T>::operator[](int index)
{
	assert(index >= 0 && index < size);
	return arr[index];
}

template<typename T>
const T& Vector<T>::operator[](int index) const
{
	assert(index >= 0 && index < size);
	return arr[index];
}

template<typename T>
void Vector<T>::doubleSize()
{
	T* newArr = new T[this->size * 2];
	for (int i = 0; i < this->size; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] this->arr;
	this->arr = newArr;
	this->size *= 2;
}
