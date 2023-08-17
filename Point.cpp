#include <iostream>
#include <string>
#include "Point.h"

using namespace std;

void Point::setX(int val) // :: ---> is a SCOPE RESOLUTION operator.
{
    x = val;
}
void Point::setY(int val)
{
    y = val;
}

Point::Point()
{
    cout << "Default Constructor Called!!" << endl;
    x = 0;
    y = 0;
}
Point::Point(int z)
{
    cout << "Overloaded Contructor Called!! (1 Parameters)" << endl;
    x = z;
    y = z;
}
Point ::Point(int a, int b)
{
    cout << "Overloaded Contructor Called!! (2 Parameters)" << endl;
    x = a;
    y = b;
}
/*int Point::getX() const
{

    return x;
}
int Point::getY() const
{

    return y;
}*/
void Point::displayPoint() const
{
    cout << "(" << x << ", " << y << ")\n";
    // cout << "(" << getX() << ", " << getY() << ")\n"; // ERROR: Non constant functions can't be called in constant function
}
void Point::setCoordinates(int v1, int v2)
{
    x = v1;
    y = v2;

    // setX(v1);
    // setY(v2);
}
