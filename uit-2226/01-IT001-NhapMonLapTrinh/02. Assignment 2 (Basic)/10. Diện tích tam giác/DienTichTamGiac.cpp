#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    float a, b, c, p, dientich;
    cin >> a >> b >>c;
    p =(a+b+c)/2;
    dientich= sqrt(p*(p - a)*(p - b)*(p - c));
    cout << setprecision(2) << fixed << dientich << endl;
    return 0;
}
