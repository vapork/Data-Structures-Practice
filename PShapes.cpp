#include <iostream>
using namespace std;
class Shape{
public:
    double x,y,a;
    Shape(int a,int b):x(a),y(b),a(0){}
    virtual double area()=0;
};

class Rect:public Shape{
public:
    double w,h;
    Rect(int a,int b,int w,int h):Shape(a,b),w(w),h(h){}
    double area();
};

double Rect::area() {
    a=w*h;
    return a;
}

class Circle:public Shape{
public:
    double r;
    Circle(int a,int b,int c):Shape(a,b),r(c){}
    double area();
};

double Circle::area() {
    a= 3.14159265358979*r*r;
    return a;
}


class Line:public Shape{
public:
    double x1,y1;
    Line(int a,int b,int c,int d):Shape(a,b),x1(c),y1(d){}
    double area();
};

double Line::area() {
    a=0;
    return a;
}

int main() {
    Rect r1(100, 50, 20, 40);  // Rect(x,y, width, height)
    cout << r1.area() << '\n'; // area should be width*height
    Circle c1(400, 300, 50); // Circle(x,y,radius)
    cout << c1.area() << '\n'; // area should be pi * radius squared
    Line L1(0,0, 300, 400);
    cout << L1.area() << '\n'; // area should be 0
    Shape* shapes[6];
    shapes[0] = &r1;
    shapes[1] = &c1;
    shapes[2] = &L1;
    cout<<"\nloop\n";
    for (int i = 0; i < 3; i++)
        cout << shapes[i]->area() << '\n';
    cout<<"\nauto\n";
    for (auto s : shapes)
        if (s != nullptr)
            cout << s->area() << '\n';
}