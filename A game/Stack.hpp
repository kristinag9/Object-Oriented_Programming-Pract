#include "Vector.cpp"

template<typename T>
class Stack : private Vector<T>
{
private:
	int stackSize;
public:
	Stack();

	void push(const T&);
	void pop();
	T& top();
	bool isEmpty() const;
	int getSize() const;
};

template<typename T>
Stack<T>::Stack() : Vector<T>(8)
{
	this->stackSize = 0;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
	return this->stackSize == 0;
}

template<typename T>
int Stack<T>::getSize() const
{
	return this->stackSize;
}

template<typename T>
T& Stack<T>::top()
{
	assert(this->stackSize > 0);
	return (*this)[this->stackSize - 1];
}

template<typename T>
void Stack<T>::pop()
{
	assert(this->stackSize > 0);
	this->stackSize--;
}

template<typename T>
void Stack<T>::push(const T& element)
{
	if (Vector<T>::getSize() == this->stackSize)
	{
		this->doubleSize();
	}
	(*this)[this->stackSize] = element;
	this->stackSize++;
}
