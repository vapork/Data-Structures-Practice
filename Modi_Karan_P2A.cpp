#include <iostream>
#include <cmath>
using namespace std;

void vc()
{
    double v,t;
    double wc;
    cout<<"   ";
    for(int i=40; i>=-45;i-=5)
    {
        if(i>=0)                //for correct spacing, tab(\t) leads to elements into next line
            cout<<" ";
        if(i/10==0)
        cout<<i<<"  ";
        else
        cout<<i<<" ";
    }
    cout<<endl<<" ";
    for(v=5;v<=60;v+=5)
    {
        if(v/10==0)
            cout<<v<<"  ";
        else
            cout<<v<<" ";
        for(t=40;t>=-45;t-=5)
        {
            wc=35.74+(0.6215*t)-35.75*(pow(v,0.16))+0.4275*t*pow(v,0.16);
            int x=round(wc);
            if(x>=0)
                cout<<" ";
            if(x/10==0)
                cout<<x<<"  ";
            else
                cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vc();
    return 0;
}