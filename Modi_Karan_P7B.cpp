#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

static int rr,gg,bb;

class Shape {
public:
    int ra,ga,ba;
    int ox,oy;
    Shape(int x,int y):ox(x),oy(y){}
  virtual void draw(ostream& s) = 0;
};

class FilledRect : public Shape {
    int x,y;
public:
    FilledRect(int a,int b,int c,int d):Shape(a,b),x(c),y(d){
        ra=rr;
        ga=gg;
        ba=bb;
    }
 void draw(ostream& s) {
    s<<ra<<" "<<ga<<" "<<ba<<" setrgbcolor"<<endl;
    s<<ox<<" "<<oy<<" moveto"<<endl;
    s<<x<<" "<<oy<<" lineto"<<endl;
    s<<x<<" "<<y<<" lineto"<<endl;
    s<<ox<<" "<<y<<" lineto"<<endl;
    s<<"fill"<<endl;
 }
};

class Rect : public Shape {
    int x,y;
public:
    Rect(int a,int b,int c,int d):Shape(a,b),x(c),y(d){
        ra=rr;
        ga=gg;
        ba=bb;
    }
    void draw(ostream& s) {
        s<<ra<<" "<<ga<<" "<<ba<<" setrgbcolor"<<endl;
        s<<ox<<" "<<oy<<" moveto"<<endl;
        s<<x<<" "<<oy<<" lineto"<<endl;
        s<<x<<" "<<y<<" lineto"<<endl;
        s<<ox<<" "<<y<<" lineto"<<endl;
        s<<"stroke"<<endl;
    }
};

class FilledCircle : public Shape {
    int rad;
public:
    FilledCircle(int a,int b,int c):Shape(a,b),rad(c){
        ra=rr;
        ga=gg;
        ba=bb;
    }
    void draw(ostream& s) {
        s<<ra<<" "<<ga<<" "<<ba<<" setrgbcolor"<<endl;
        s<<ox<<" "<<oy<<" "<<rad<<" 0 360 arc"<<endl;
        s<<"fill"<<endl;
    }
};

class Circle : public Shape {
    int rad;
public:
    Circle(int a,int b,int c):Shape(a,b),rad(c){
        ra=rr;
        ga=gg;
        ba=bb;
    }
    void draw(ostream& s) {
        s<<ra<<" "<<ga<<" "<<ba<<" setrgbcolor"<<endl;
        s<<ox<<" "<<oy<<" "<<rad<<" 0 360 arc"<<endl;
        s<<"stroke"<<endl;
    }
};

class Line : public Shape {
    int x,y;
public:
    Line(int a,int b,int c,int d):Shape(a,b),x(c),y(d){
        ra=rr;
        ga=gg;
        ba=bb;
    }
    void draw(ostream& s) {
        s<<ra<<" "<<ga<<" "<<ba<<" setrgbcolor"<<endl;
        s<<ox<<" "<<oy<<" moveto"<<endl;
        s<<x<<" "<<y<<" lineto"<<endl;
        s<<"stroke"<<endl;
    }
};

class Polygon : public Shape {
    int rad,n;
public:
    Polygon(int a,int b,int c,int d):Shape(a,b),rad(c),n(d){
        ra=rr;
        ga=gg;
        ba=bb;
    }
    void draw(ostream& s) {
        s<<ra<<" "<<ga<<" "<<ba<<" setrgbcolor"<<endl;
        s<<ox<<" "<<oy<<" moveto"<<endl;
        double side=360/n;
        for(int i=0;i<n;i++)
            s<<rad<<" "<<0<<" rlineto "<<side<<" rotate"<<endl;
        s<<"stroke"<<endl;
    }
};

class Drawing {
private:
    ofstream f;
    int numShapes;
    vector<Shape*> shapes;
public:
    Drawing(string filename) : f(filename.c_str()), shapes() {
        f<<"newpath"<<endl;
    }
    void add( Shape* s ) {
        shapes.push_back(s);
    }

    void draw() {
        numShapes = shapes.size();
        for (int i = 0; i < numShapes; i++)
            shapes[i]->draw(f);
        f<<"closepath"<<endl;
    }
    void setrgb(int a,int b,int c) {
        rr=a;
        gg=b;
        bb=c;
    }
};

int main() {
    ofstream f(  );
    Drawing d("test2.ps");
    d.setrgb(1,0,0); // set drawing color to be bright red:  1 0 0 setrgbcolor
    d.add(new FilledRect(100.0, 150.0, 200.0, 50)); // x y moveto x y lineto ... fill
    d.add(new Rect(100.0, 150.0, 200.0, 50));       // x y moveto x y lineto ... stroke
    for (int x = 0; x < 600; x += 100)
        d.add(new FilledCircle(x,200,50.0)); // x y r 0 360 arc fill
      d.setrgb(0,1,0); // the rest are green

      d.add(new Circle(0,0, 100)); // 0 0 100 0 360 stroke
      d.add(new Line(400,500, 600,550));
      d.add(new Polygon(200,200, 50, 6));
    d.draw();
}