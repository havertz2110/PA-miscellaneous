#include <bits/stdc++.h>
using namespace std;

long long a, b, res;

int main() {
    long long tmp = 1, remain;
    cin >> a >> b;
    while (tmp <= a) tmp *=10;
    if (b% tmp >= a) res = 1;
    b /= tmp;
    tmp=1;
    while (b) {
        remain = b%10;
        res += remain * tmp;
        b/=10;
        tmp *=10;
    }
    cout << res;
}
