#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    double toan, ly, hoa, avr;
    cin >> toan >> ly >> hoa;
    avr = (toan+ly+hoa)/3;
    if ( avr >= 9 && avr <= 10){
        cout << setprecision(2) << fixed <<"DTB = " << avr << endl;
        cout << "Loai: XUAT SAC";
    }
    else if ( avr >= 8 && avr <9) {
        cout << setprecision(2) << fixed <<"DTB = " << avr << endl;
        cout << "Loai: GIOI";
    }
    else if ( avr >=7 && avr <8 ) {
        cout << setprecision(2) << fixed <<"DTB = " << avr << endl;
        cout << "Loai: KHA";
    }
    else if ( avr >=6 && avr <7) {
        cout << setprecision(2) << fixed <<"DTB = " << avr << endl;
        cout << "Loai: TB KHA";
    }
    else if ( avr >=5 && avr <6) {
        cout << setprecision(2) << fixed <<"DTB = " << avr << endl;
        cout << "Loai: TB";
    }
    else if ( avr >=4 && avr <5) {
        cout << setprecision(2) << fixed <<"DTB = " << avr << endl;
        cout << "Loai: YEU";
    }
    else if( avr <4) {
        cout << setprecision(2) << fixed <<"DTB = " << avr << endl;
        cout << "Loai: KEM";
    }

}
