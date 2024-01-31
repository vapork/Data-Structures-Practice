#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double r=1,c=10;
    for(double i=3;c<=1000000; i++) {
        r = r / cos(22 / (7 * i));
        if (fmod(i, c) == 0) {
            cout << "\nn = " << i << " radius = " << r;
            c*=10;
        }
    }
    return 0;
}

