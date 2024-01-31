#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int r, c,x = 0,a,b;
    ofstream out("rc.dat");
    cout << " Enter Rows and Columns";
    cin >> r >> c;
    out << r << " "<<c<<"\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> x;
            out << x <<" ";
        }
        out << "\n";
    }
    out.close();

    ifstream f("rc.dat");
    f>>a>>b;
    int y[15][15],t=0,rt=0,ct=0;
    for (int i = 0; i < a; i++) {
        rt=0;
        for (int j = 0; j < b; j++) {
            f >> x;
            rt+=x;
            t+=x;
            y[i][j]=x;
            cout <<y[i][j]<<"\t";
        }
        cout<<"rowsum = "<<rt<<endl;
    }
    cout<<"--------------------------------"<<endl;
    for (int i = 0; i < b; i++) {
        ct = 0;
        for (int j = 0; j < a; j++) {
            ct+=y[j][i];
        }
        cout <<ct<<"\t";
    }
    cout<<"totalsum = "<<t;
    f.close();
    return 0;
}