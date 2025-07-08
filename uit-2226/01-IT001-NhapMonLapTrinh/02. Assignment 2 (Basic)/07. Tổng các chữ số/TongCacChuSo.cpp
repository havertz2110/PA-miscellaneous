#include <iostream>

using namespace std;

int main()
{
    int a, sotemp;
    int tong = 0;
    cin >> a;
    sotemp = a;
    while ( sotemp !=0) {
        tong += sotemp %10;
        sotemp /= 10;
    }
    cout << tong;
}
