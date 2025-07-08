#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mN = 1e5 + 10;
int n, m, res, cnt;
int a[mN], b[mN];
vector <pair<int, int>> sto;

bool check(int x){
    bool flag;
    int ptr = 1;
    for (int i = 1; i <= n; i++) {
        flag = false;
        if (a[i] >= x) continue;
        if (a[i] < x && ptr > m) return false;
        if (a[i] + b[ptr] >= x) flag = true;
        while (a[i] + b[ptr] < x && ptr <= m) {
            ptr++;
            flag = true;
        }
        if (a[i] + b[ptr] < x) return false;
        if (flag) ptr++;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i];
    int l = 1, r = 1e9, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            res = max(res, mid);
            l = mid + 1;
        } else r = mid - 1;
    }
    bool flag;
    int ptr = 1;
    for (int i = 1; i <= n; i++) {
        flag = false;
        if (a[i] >= res) continue;
        if (a[i] + b[ptr] >= res) flag = true;
        while (a[i] + b[ptr] < res && ptr <= m) {
            ptr++;
            flag = true;
        }
        if (flag) {
            cnt++;
            sto.push_back({i, ptr});
            ptr++;
        }
    }
    cout << res << " " << cnt << "\n";
    for (int i = 0; i < sto.size(); i++)
        cout << sto[i].first << " " << sto[i].second << "\n";
}
