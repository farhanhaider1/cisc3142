#include <stdio.h>
#include <iostream>
using namespace std;

class Rectangle
{
    float length, width;

public:
    Rectangle(float l, float w)
    {
        length = l;
        width = w;
    }

    void setLength(float l)
    {
        length = l;
    }

    void setWidth(float w)
    {
        width = w;
    }

    float perimeter()
    {
        float perimeter = 2 * (length + width);

        return perimeter;
    }

    float area()
    {
        float area = length * width;
        return area;
    }

    void show()
    {
        cout << "length of rectangle is " << length << endl;
        cout << "width of rectangle is " << width << endl;
    }

    int sameArea(Rectangle r)
    {
        float area1 = area();
        float area2 = r.length * r.width;
        if (area1 == area2)
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    Rectangle r1 = Rectangle(5, 2.5);
    Rectangle r2 = Rectangle(5, 18.9);

    r1.show();
    r2.show();

    cout << "area of rectangle 1: " << r1.area() << endl;
    cout << "area of rectangle 2: " << r2.area() << endl;

    cout << "perimeter of rectangle 1: " << r1.perimeter() << endl;
    cout << "perimeter of rectangle 2: " << r2.perimeter() << endl;

    // if equal
    if (r1.area() == r2.area())
    {
        cout << "The area of the two rectangles is equal" << endl;
    }
    else
    {
        cout << "The area of the two rectangles is not equal" << endl;
    };

    // set values
    r1.setLength(15);
    r1.setWidth(6.3);

    // display again
    r1.show();
    r2.show();

    cout << "area of rectangle 1: " << r1.area() << endl;
    cout << "area of rectangle 2: " << r2.area() << endl;

    cout << "perimeter of rectangle 1: " << r1.perimeter() << endl;
    cout << "perimeter of rectangle 2: " << r2.perimeter() << endl;

    if (r1.area() == r2.area())
    {
        cout << "The area of the two rectangles is equal" << endl;
    }
    else
    {
        cout << "The area of the two rectangles is not equal" << endl;
    };

    return 0;
}