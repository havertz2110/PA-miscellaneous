#include <bits/stdc++.h>
using namespace std;
 
const int mN = 100;
 
struct DATHUC {
    int n;
    double a[mN + 10];
};
 
double pow(double a, long long b) {
    double ans = 1;
    for(; b; b>>=1) {
        if (b&1) ans *= a;
        a *= a;
    }
    return ans;
}
 
DATHUC *Nhap() {
    double val;
    int deg;
    DATHUC *C = new DATHUC;
    cin >> C->n;
    for (int i = 0; i < mN; i++) C->a[i] = 0;
    for (int i = 1; i <= C->n; i++) {
        cin >> val >> deg;
        C->a[deg] += val;
    }
    return C;
}
 
void Xuat(DATHUC C) {
    bool flag = false;
    for (int i = mN - 1; i >= 0; i--) if (C.a[i] != 0) {
        if (flag && C.a[i] > 0) cout << "+";
        else if (C.a[i] < 0) cout << "-";
        flag = true;
        if (abs(C.a[i]) != 1 || i == 0) cout << abs(C.a[i]);
        if (i > 1) cout << "x^" << i;
        if (i == 1) cout << "x";
    }
    if (!flag) cout << "0";
    cout << "\n";
}
 
double TinhDaThuc(DATHUC C, double x) {
    double res = 0;
    for (int i = 0; i < mN; i++) {
        res += 1.0 * C.a[i] * pow(x, i);
    }
    return res;
}