#include <iostream>

using namespace std;

struct Point
{
    double x;
	double y;
};

Point createPoint(double x, double y)
{
	Point p;
	p.x = x;
	p.y = y;

  return p = {x, y};
}

struct Rectangle
{
    Point pointRect;
    double length;
    double width;
};

Rectangle createRectangle(Point p, double length, double width)
{
	Rectangle myRect;
	myRect.pointRect.x = p.x;
	myRect.pointRect.y = p.y;
	myRect.length = length;
	myRect.width = width;

  return myRect;
}

//A function that checks if the rectangle is empty
bool isEmpty(const Rectangle& myRect)
{
    return myRect.length == 0 && myRect.width == 0;
}

//A function that receives two rectangles and return a new one – their cross section
Rectangle createNewRect(Rectangle& rect1, Rectangle& rect2)
{
    Rectangle newRect;
    if(isEmpty(newRect))          //A check for an empty rectangle
    {
        newRect.pointRect.x = 0;
        newRect.pointRect.y = 0;
        newRect.length = 0;
        newRect.width = 0;
      return newRect;
    }

//Creating the point of the rectangle
    if(rect1.pointRect.x > rect2.pointRect.x)
    {
        newRect.pointRect.x = rect1.pointRect.x;    //Creating a x coordinate
    }
    else
    {
        newRect.pointRect.x = rect2.pointRect.x;
    }
    if(rect1.pointRect.y < rect2.pointRect.y)       //Creating an y coordinate
    {
        newRect.pointRect.y = rect1.pointRect.y;
    }
    else
    {
        newRect.pointRect.y = rect2.pointRect.y;
    }

    double bestLeftPoint;                           //The leftmost point of the rectangle
    if (rect1.pointRect.x < rect2.pointRect.x)
    {
        bestLeftPoint = rect1.pointRect.x;
    }
    else
    {
        bestLeftPoint = rect2.pointRect.x;
    }

    double bestRightPoint;                                                      //The rightmost point of the rectangle
    if ((rect1.pointRect.x + rect1.length) > (rect2.pointRect.x + rect2.length))
    {
        bestRightPoint = (rect1.pointRect.x + rect1.length);
    }
    else
    {
        bestRightPoint = (rect2.pointRect.x + rect2.length);
    }
    newRect.length = (rect1.length + rect2.length) - (bestRightPoint - bestLeftPoint);    //The length of the new rectangle

    double topLeftPoint;                       //The point in the upper left corner
    if (rect1.pointRect.y > rect2.pointRect.y)
    {
        topLeftPoint = rect1.pointRect.y;
    }
    else
    {
        topLeftPoint = rect2.pointRect.y;
    }
    double downPoint;                          //The point in the bottom corner
    if ((rect1.pointRect.y - rect1.width) < (rect2.pointRect.y - rect2.width))
    {
        downPoint = rect1.pointRect.y - rect1.width;
    }
    else
    {
        downPoint = rect2.pointRect.y - rect2.width;
    }
    newRect.width = (rect1.width + rect2.width) - (topLeftPoint - downPoint);           //The height of the new rectangle
  return newRect;
}

//A function which gives an information about a rectangle
void printRectangle(const Rectangle& myRect)
{
    if(isEmpty(myRect))
    {
        cout << "The rectangle doesn't exist.";
    }
    else
    {
        cout << "Printing the rectangle ..." << endl;
        cout << "The point of the rectangle: " << "( " << myRect.pointRect.x << "," << myRect.pointRect.y << " )" << endl;
        cout << "The rectangle has length " << myRect.length << " and width " << myRect.width << endl;
    }
    cout << endl;
}

//A function that takes an array of rectangles and its length, and returns their cross section
Rectangle newRectArr(Rectangle rect[], int n) //n = size
{
    Rectangle newRectToCreate;
    newRectToCreate = rect[0];
    for(int i = 1; i < n; i++)
    {
        newRectToCreate = createNewRect(newRectToCreate, rect[i]);
        if(!isEmpty(newRectToCreate))      //A check for and empty rectangle
        {
            return newRectToCreate;
        }
    }
    return newRectToCreate;
}

int main()
{
    //Initialization of two rectangles
    cout << "The first new rectangle: " << endl;
    Rectangle myRect1 = createRectangle(createPoint(4,4),4,3);
    Rectangle myRect2 = createRectangle(createPoint(5,5),2,3);
    Rectangle newRect1 = createNewRect(myRect1,myRect2);
    printRectangle(newRect1);
    cout << endl;

    //Initialization of two rectangles
    cout << "The second new rectangle: " << endl;
    Rectangle myRect3 = createRectangle(createPoint(3,2),5,6);
    Rectangle myRect4 = createRectangle(createPoint(7,6),8,5);
    Rectangle newRect2 = createNewRect(myRect3, myRect4);
    printRectangle(newRect2);
    cout << endl;

    //Initialize a rectangle with zero length and width
    cout << "The third new rectangle: " << endl;
    Rectangle myRect5 = createRectangle(createPoint(0,0),0,0);
    Rectangle myRect6 = createRectangle(createPoint(0,0),0,0);
    Rectangle newRect3 = createNewRect(myRect5, myRect6);
    printRectangle(newRect3);
    cout << endl;

    //Creating an array with rectangles
    cout << "Creating an array with three rectangles: " << endl;
    Rectangle myRectArr1[2];
    myRectArr1[0] = createRectangle(createPoint(3,5), 2, 4);
    myRectArr1[1] = createRectangle(createPoint(8,7), 5, 6);
    myRectArr1[2] = createRectangle(createPoint(2,4), 3, 1);
    Rectangle myNewRectArr1 = newRectArr(myRectArr1, 3);
    printRectangle(myNewRectArr1);

    return 0;
}
