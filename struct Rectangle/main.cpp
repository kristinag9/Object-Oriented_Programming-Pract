#include <iostream>
#include <cmath>

using namespace std;

struct Rectangle
{
    double a;
    double b;
};
Rectangle createRectangle()
{
    Rectangle rect;
    cout << "Enter a length: ";
    cin >> rect.a;
    cout << "Enter a height: ";
    cin >> rect.b;
    return rect;
}
void printRectangle(const Rectangle& rect)
{
    cout << "Rectangle with length " << rect.a << " and height " << rect.b << endl;
}
double getRadius(const Rectangle& rect)
{
    return sqrt((rect.a*rect.a + rect.b*rect.b))/2;
}
double getArea(const Rectangle& rect)
{
    return rect.a*rect.b;
}
double getPerimeter(const Rectangle& rect)
{
    return 2*(rect.a + rect.b);
}

int main()
{
    Rectangle ourRect = createRectangle();
    printRectangle(ourRect);
    cout << "Radius: " << getRadius(ourRect) << endl;
    cout << "Area: " << getArea(ourRect) << endl;
    cout << "Perimeter: " << getPerimeter(ourRect) << endl;
    return 0;
}

