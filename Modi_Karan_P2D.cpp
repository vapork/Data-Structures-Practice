#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    cout<<"Enter a string :\n";
    getline(cin,a);
    int x = 1;
    uint32_t c;
    c = a.size() - 1;
    cout<<"The string backwards is : ";
    for(int i=c;i>=0;i--) {
        cout<<a[i];
        if(a[i]!=a[c-i])
            x=0;
    }
    if(x==1)
        cout<<"\nThe string is a Palindrome";
    else
        cout<<"\nThe string is NOT a Palindrome";
    cout<<"\nThe string without vowels : ";
    for(x=0;a[x]!='\0';x++)
        if(a[x]!='a' && a[x]!='A' && a[x]!='e' && a[x]!='E' && a[x]!='i' && a[x]!='I' && a[x]!='o' && a[x]!='O' && a[x]!='u' && a[x]!='U')
            cout<<a[x];
    return 0;
}
#pragma clang diagnostic pop