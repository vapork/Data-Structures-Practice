#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int g=0,s=0;
    g=100*(100+1)/2;
    for(int i=1; i<=100; i++)
    s+=i;
    cout<<"Gauss Result : "<<g;
    cout<<"\nLoop Result : "<<s;
    if(g==s)
        cout<<"\nBoth results are the same.\n(Where "<<s<<" is the numerical result.)";
    return 0;
}

