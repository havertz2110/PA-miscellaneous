#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

using ll = long long;
ll n,k,a[N],l = 1e9, r = 0, ans;
ll check(ll ms) {
    ll t = 0, cnt = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] > ms) return 1e9;
        if(t + a[i] > ms) {
            t = 0;
            cnt++;
        }
        t += a[i];
    }
    return cnt;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        l = min(l, a[i]);
        r += a[i];
    }
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(check(mid) <= k) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
	return 0;
}
#code trong bài này somehow chỉ được 93/100 thôi nhé