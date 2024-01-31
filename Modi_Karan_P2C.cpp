#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long x)
{
    bool f=true;
    for(long i=2;i<=sqrt(x);i++)
    {
        if(x%i == 0)
        {
            f=false;
            break;
        }
    }
    return f;
}

void countPrimes(long x,long y)
{
    bool p;
    if(x>0 && y>0) {
        if (x > y) {
            x = x + y;      // to switch the variables if b>a
            y = x - y;
            x = x - y;
        }

        int c=0;
        for (long i = x; i <= y; i++) {
            p = isPrime(i);
            if (p == true)
                c++;
        }
        cout<<"\nThere are "<<c<<" primes in the range ["<<x<<","<<y<<"].";
    }
    else
    {
        cout<<"Enter positive numbers";
    }
}

int main()
{
    long a,b;
    cout<<" Please enter a positive integer as the minimum: ";
    cin>>a;
    cout<<"Please enter a positive integer as the maximum: ";
    cin>>b;

    countPrimes(a,b);
    return 0;
}