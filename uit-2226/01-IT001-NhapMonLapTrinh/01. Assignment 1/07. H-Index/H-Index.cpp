#include <bits/stdc++.h>
using namespace std;

const int mN = 5e5 +10;
int n;
int a[mN];

int main(){
    int cnt = 0, res = 0;
    cin >> n;
    for ( int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
    for ( int i = n; i; i--) {
            cnt++;
    if (a[i] >= cnt) res = n - i + 1;
    }
    cout << res;
}
