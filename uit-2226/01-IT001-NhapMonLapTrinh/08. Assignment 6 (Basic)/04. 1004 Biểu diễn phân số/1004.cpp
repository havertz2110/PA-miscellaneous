#include <bits/stdc++.h>
using namespace std;
 
struct PhanSo {
    int u, v;
};
 
void Nhap(PhanSo &a) {
    cin >> a.u >> a.v;
    if (a.v < 0) {
        a.u *= -1;
        a.v *= -1;
    }
}
 
PhanSo Nhap() {
    PhanSo k;
    cin >> k.u >> k.v;
    if (k.v < 0) {
        k.v *= -1;
        k.u *= -1;
    }
    return k;
}
 
PhanSo Chia(PhanSo a, PhanSo b) {
    PhanSo k;
    return k = {a.u * b.v, a.v * b.u};
}
 
void Xuat(PhanSo k) {
    int c = k.u;
    int d = k.v;
    int tmp = __gcd(abs(c), abs(d));
    c /= tmp;
    d /= tmp;
    if (d < 0) {
        c *= -1;
        d *= -1;
    }
    if (c == 0) cout << 0;
    else {
        cout << c;
        if (d != 1) cout << "/" << d;
    }
}