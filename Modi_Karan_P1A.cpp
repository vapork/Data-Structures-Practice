#include <iostream>

using namespace std;

int main()
{
    long n=0;
    cout<<"Please enter a positive integer: ";
    cin>>n;
    cout<<n<<"\t";
    if(n>0)
    {
        while(n>1){

            if(n%2==0)
                n=n/2;
            else
                n=n*3+1;
            cout <<n<<"\t";
        }
    }
    else
        cout<<"The number is not positive";
    return 0;
}

