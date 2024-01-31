#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    double e,a[10],l,s,m=0,v=0;
    int c=0,i=0;
    char ch='n';
    ofstream out("3B.dat");
    do{
        cout<<" Enter value";
        cin>>e;
        out<<e<<" ";
        cout<<"Do you want enter again(Y/N) \n";
        cin>>ch;
        c++;
    }while(ch=='y'||ch=='Y');
    out.close();

    ifstream f("3B.dat");
    for(i=0;i<c;i++)
    {
        f>>a[i];
        l=a[i];
        s=a[i];
    }
    for(i=0;i<c;i++)
    {
        if(a[i]>l)
            l=a[i];
        if(a[i]<s)
            s=a[i];
        m+=a[i];
    }
    f.close();
    m=m/c;
    for(i=0;i<c;i++)
    {
        v+=pow((a[i] - m),2) / c;
    }
    cout<<"Elements = "<<c<<"\nMax = "<<l<<"\nMin = "<<s<<"\nMean = "<<m<<"\nVariance = "<<v;
    return 0;
}