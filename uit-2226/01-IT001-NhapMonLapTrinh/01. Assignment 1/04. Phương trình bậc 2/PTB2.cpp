#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a,b,c;
    cin >> a >> b >> c;
    double delta= b*b - 4*a*c;
        if (delta <0 ) {
            cout << "PTVN";
        } else if (delta==0) {
            cout << "PT co nghiem kep: x1 = x2 = " << (b-2*b)/ (2*a);
        } else {
            cout <<"PT co hai nghiem phan biet:"<<"\n";
            cout << "\n";
            cout << "x1 = " << (b-2*b+sqrt(delta)) / (2*a) << "\n";
            cout << "x2 = " << (b-2*b-sqrt(delta)) / (2*a) << "\n";
        }
return 0;
}
