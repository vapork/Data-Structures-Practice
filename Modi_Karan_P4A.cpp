#include <iostream>
using namespace std;

class Vec3d {
private:
    double x,y,z;

public:

    Vec3d(double a = 0, double b = 0, double c = 0) : x(a), y(b), z(c) {}

    friend double dot(const Vec3d& a,const Vec3d& b){
        return a.x*b.x+a.y*b.y+a.z*b.z;
    }

    double dot(const Vec3d& b) const{
        return x*b.x+y*b.y+z*b.z;
    }

    double mag() const{
        return sqrt((x*x) + (y*y) + (z*z));
    }

    double magSq() const{
        return (x*x) + (y*y) + (z*z);
    }

    double dist(const Vec3d& b) const{
        double a=x-b.x,c=y-b.y,d=z-b.z;
        return sqrt(a*a+c*c+d*d);
    }

    friend ostream& operator <<(ostream& s, const Vec3d& V) {
        return s << "("<< V.x<< "," << V.y <<"," << V.z<<")";
    }
    friend Vec3d operator + (Vec3d i, Vec3d j) {
        Vec3d k(i.x+j.x,i.y+j.y,i.z+j.z);
        return k;
    }
    friend Vec3d operator - (Vec3d i, Vec3d j) {
        Vec3d k(i.x-j.x,i.y-j.y,i.z-j.z);
        return k;
    }
    Vec3d operator -() const {
        return Vec3d(-x,-y,-z);
    }

};


int main() {
    // Main() Section 1
    const Vec3d a(1.0,2.5,3.5); // double precision!
    const Vec3d b(2.0);         //(2,0,0)
    const Vec3d c(2.0,3.5);     //(2,3.5,0)
    const Vec3d d;              //(0,0,0)

    // Main() Section 2
    const Vec3d e = a + d;
    const Vec3d f = c - b;
    const Vec3d g = -e;

    // Main() Section 3
    double r = dot(e, f); // regular function  e.x*f.x + e.y*f.y + e.z*f.z
    double s = e.dot(f); // method

    // Main() Section 4
    double x = e.mag(); // square root of sum of square
    double y = e.magSq(); // sum of square
    double z = e.dist(f); // sqrt or sum of square of diff

    // Main() Section 5
    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << "c: " << c << '\n';
    cout << "d: " << d << '\n';
    cout << "e: " << e << '\n';
    cout << "f: " << f << '\n';
    cout << "g: " << g << '\n';
    cout << "r: " << r << '\n';
    cout << "s: " << s << '\n';
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';
    cout << "z: " << z << '\n';
}