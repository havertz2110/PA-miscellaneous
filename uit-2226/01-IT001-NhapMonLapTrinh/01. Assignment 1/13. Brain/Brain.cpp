#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mN = 1e5 + 10;
int n;
int a[mN], mulpreffix[mN], mulsuffix[mN], gcdpreffix[mN], gcdsuffix[mN];

int gcd(int u, int v) {
    if (v == 0) return u;
    return gcd(v, u%v);
}

int32_t main() {
    cin >> n;
    mulpreffix[0] = mulsuffix[n + 1] = 1;
    int gcdnow = 0, id = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        gcdpreffix[i] = gcd(a[i], gcdpreffix[i - 1]);
    for (int i = n; i; i--)
        gcdsuffix[i] = gcd(a[i], gcdsuffix[i + 1]);
    for ( int i = 1; i <= n; i++) {
        if (gcd(gcdpreffix[i - 1], gcdsuffix[i + 1]) > gcdnow ) {
            gcdnow = gcd(gcdpreffix[i - 1], gcdsuffix[i + 1]);
            id = i;
        }
    }
    cout << id << " " << gcdnow;
}
