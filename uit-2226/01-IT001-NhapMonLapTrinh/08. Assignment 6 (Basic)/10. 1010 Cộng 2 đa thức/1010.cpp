#code này chỉ được 94/100, sai 1 test, các bạn kiểm tra thử nhé, đây là kết quả tốt nhất của lớp mình rùi
#include <bits/stdc++.h>
using namespace std;
 
const int mN = 100;
 
struct DATHUC {
    int n;
    double a[mN + 10];
    DATHUC() {
        for (int i = 0; i <= mN; i++) a[i] = 0;
        n = 0;
    }
};
 
DATHUC *Nhap() {
    double val;
    int deg;
    DATHUC *C = new DATHUC;
    cin >> C->n;
    for (int i = 0; i < mN; i++) C->a[i] = 0;
    for (int i = 1; i <= C->n; i++) {
        cin >> val >> deg;
        C->a[deg]= val;
    }
    return C;
}
 
DATHUC Tong2DaThuc(DATHUC *A, DATHUC *B) {
    DATHUC *C = new DATHUC;
    for (int i = mN - 1; i >= 0; i--) C->a[i] = A->a[i] + B->a[i];
    return *C;
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
}
