#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a,b,c,p,dientich;
    cin >> a >> b>> c;
    p=(a+b+c)/2;
    dientich= sqrt(p*(p - a)*(p - b)*(p - c));
    if ( a + b <= c || a + c <= b ||  b + c <= a)
    {
        cout << "Khong phai tam giac" << endl;
    }
    else if (a==b && b==c ){
        cout << "Tam giac deu, dien tich = " <<  setprecision(2) << fixed << dientich << endl;
    }
    else if ( a==b || a==c || b==c ){
        cout <<  "Tam giac can, dien tich = " <<  setprecision(2) << fixed << dientich << endl;
    }
    else if ( a*a==b*b+c*c || b*b==a*a+c*c||c*c==a*a+b*b ) {
        cout << "Tam giac vuong, dien tich = " <<  setprecision(2) << fixed << dientich << endl;
    }
    else
        cout << "Tam giac thuong,  dien tich = " <<  setprecision(2) << fixed << dientich << endl;
    }
