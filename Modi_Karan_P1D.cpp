#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float f1=0,f2=0;
    double d1=0,d2=0;
    for(float i=1.0; i<=100; i++)
    {
        f1+=1/i;
        f2+=1/(101-i);
    }
    for(double i=1.0; i<=100; i++)
    {
        d1+=1/i;
        d2+=1/(101-i);
    }
    cout<<"sum1F = "<<f1<<", sum2F = "<<f2;
    cout<<"\nsum1D = "<<d1<<", sum2D = "<<d2;
    cout<<"\nsum1F - sum2F = "<<f2-f1;
    cout<<"\nsum1D - sum2D = "<<d2-d1;
    return 0;
}

