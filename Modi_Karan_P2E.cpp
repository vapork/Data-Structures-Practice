#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
constexpr double PI = 3.14159265358979;
constexpr double d2r = PI / 180;

void polar2Rect(double r,double theta,double &dx,double &dy)
{
    double x, y;
    x= r*cos(theta*d2r);
    y= r*sin(theta*d2r);
    dx=dx+x;
    dy=dy+y;
}

int main()
{
    double r,t,dx=0,dy=0;
    ofstream out("hw2e.dat");
    do{
        cout<<" Enter Theta and R";
        cin>>t>>r;
        out<<r<<" "<<t<<"\n";
    }while(r>=0 && t>=0);
    out.close();

    ifstream f("hw2e.dat");
    while (!f.eof())
    {
        f>>r>>t;
        if(r>=0 && t>=0) {
            polar2Rect(r, 450-t, dx, dy);
            cout<<"New robot position (X,Y) : ("<< fixed << setprecision(4) <<dx<< "," << dy << ")." << endl;  // setprecision because since we are using an approx value of pi, the answer will deviate a bit
        }
        else {
            cout<<"Robot has reached final destination.";
            break;
        }
    }
    f.close();
    return 0;
}