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

int main()
{
    long n;
    bool p;
    cout<<"Enter any Positive Number : ";
    cin>>n;
    if(n>0)
    {
        p = isPrime(n);
        if (p == true)
            cout << n << " is Prime Number";
        else
            cout << n << " is not a Prime Number ";
    }
    else
        cout<<"Enter a positive number";
    return 0;
}