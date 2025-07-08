#include <bits/stdc++.h>
using namespace std;

char a, c;
int x;

int main() {
    cin >> a >> c >> x;
    cout << "Ma ASCII cua ky tu '" << a << "', '" << c << "' lan luot la " << int(a) << " va " << int(c) << "\n";
    cout << "Khoang cach giua hai ky tu '" << a << "', '" << c << "' la " << abs(c - a) << "\n";
    cout << "Dang viet hoa cua ky tu '" << a << "' la '" << char(a - 32) << "'\n";
    cout << x << " la ma ASCII cua ky tu '" << char(x) << "'";
}
