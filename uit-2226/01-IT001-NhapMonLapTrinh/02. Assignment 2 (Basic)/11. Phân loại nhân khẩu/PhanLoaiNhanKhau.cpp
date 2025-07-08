#include <iostream>

using namespace std;

int main()
{
    int tuoi;
    cin >> tuoi;
    char x;
    cin >> x;
    if ( (x=='M' || x == 'm') && tuoi >=21){
        cout << "1";
    }
    else if ( (x=='F' || x == 'f') && tuoi >=21){
        cout << "2";
    }
    else if ( (x=='M' || x == 'm') && tuoi <21){
        cout << "3";
    }
    else if ( (x=='F' || x == 'f') && tuoi <21) {
        cout << "4";
    }
    else
        cout << "I do not know why";
}
