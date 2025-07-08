#include <bits/stdc++.h>
using namespace std;

const int mN = 1e5 + 10;
int n, sum_change, sum_origin;
int a[mN];

int main() {
    int ideven = 0, idodd = 0, value_even = 0, value_odd = 1e9;
    cin >> n;
    for ( int i = 1; i <=n; i++) {
        cin >> a[i];
        if (i&1) sum_origin += a[i];
        else sum_origin -= a[i];
        if (i&1 && a[i] < value_odd) {
            value_odd = a[i];
            idodd = i;
        }
        if (i%2 == 0 && a[i] > value_even) {
            value_even = a[i];
            ideven = i;
        }
    }
    if (ideven != 0 && idodd != 0) swap(a[ideven], a[idodd]);
    for (int i = 1; i <=n; i++) {
        if (i&1) sum_change += a[i];
        else sum_change -= a[i];
    }
    cout << max(sum_change,sum_origin);
}
