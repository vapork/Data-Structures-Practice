#include <iostream>
#include <iomanip>
using namespace std;

class Complex {
private:
    double real, im;
public:
    Complex(double r = 0, double i =0)  {real = r;   im = i;}

    friend Complex operator + (Complex i, Complex j) {
        Complex k(i.real+j.real,i.im+j.im);
        return k;
    }
    void print () const
    { cout << fixed << setprecision(1)<< "("<<real << "," << im << ")"<<endl; }

    Complex add(const Complex& obj) const{
        Complex res;
        res.real = real + obj.real;
        res.im = im + obj.im;
        return res;
    }
    Complex operator -() const {
        return Complex(-real,-im);
    }
};


int main() {
    const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
    const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
    const Complex c = a + b;   // overload operator + using a friend function
    c.print(); // should print the following to cout: (1.5,2.0)
    // (member syntax).  Should look the same as method add where the name add
    // is replaced by operator +
    const Complex d = a.add(b); // this should be the same as the above except the name
    d.print();
    Complex e = -d; // implement unary - using a member operator. Since it has one parameter which is this should have ZERO PARAMETERS!!!
    e.print();
}