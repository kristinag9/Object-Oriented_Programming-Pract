#include <iostream>
const int MAX_SIZE = 100;
using namespace std;

class Stack
{
private:
    char elements[MAX_SIZE];
    int top;
public:
    Stack();
    Stack(const Stack&);
    void push(char elem);
    char pop();
    bool isEmpty() const;
    bool isFull() const;
    void print();
};

Stack::Stack()
{
    top = 0;
}
Stack::Stack(const Stack& other)
{
    top = other.top;
    for(int i = 0; i <= top; i++)
        elements[i] = other.elements[i];
}
void Stack::push(char elem)
{
    if(!isFull())
        elements[++top] = elem;
    else
        cout << "The stack is full!" << endl;
}
char Stack::pop()
{
    if(isEmpty())
    {
        cout << "The stack is empty!" << endl;
        return '\0';
    }
    return elements[top--];

}

bool Stack::isFull() const
{
    return top == MAX_SIZE - 1;
}
bool Stack::isEmpty() const
{
    return top == 0;
}
void Stack::print()
{
    for(int i = top; i >= 0; i--)
        cout << pop() << endl;
}

int main()
{
    Stack s;
    s.push('a');
    s.push('b');
    s.push('c');

    Stack t = s;
    s.print();
    if(!t.isEmpty())
        cout << t.pop() << endl;
    t.print();

    return 0;
}
