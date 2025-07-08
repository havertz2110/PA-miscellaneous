#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
 
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
using veci = vector<int>;
using vecl = vector<ll>;
using vecdb = vector<db>;
 
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
 
#define lb lower_bound
#define up upper_bound
 
#define rep(i,a,b) for(int i = (a); i <= b; i++)
#define loop(i,a,b,add) for(int i = (a); i - (add) != (b); i += (add))
 
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 7ll;
const int mN = 1e5 + 10;
const int dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0};
int numTest = 1, n, k;
ll sumBefore, sumAfter;
string s[mN];
ll a[mN];
vector <pair <pii, int>> sto;
 
template <typename T> bool maximize(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T> bool minimize(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
 
ll convert_string_to_int(string o) {
    ll ans = 0;
    rep(i, 0, sz(o) - 1) ans = ans * 10 + o[i] - '0';
    return ans;
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (numTest--) {
        cin >> n >> k;
        rep(i, 1, n) {
            cin >> s[i];
            a[i] = convert_string_to_int(s[i]);
            sumBefore += a[i];
            reverse(all(s[i]));
            rep(j, 0, sz(s[i]) - 1)
                if (s[i][j] != '9') sto.push_back({{j, '9' - s[i][j]}, i});
        }
        sort(all(sto), greater<pair<pii, int>>());
        rep(i, 0, min(k - 1, sz(sto) - 1)) {
            int u, p;
            p = sto[i].se;
            u = sto[i].fi.fi;
            s[p][u] = '9';
        }
        rep(i, 1, n) {
            reverse(all(s[i]));
            a[i] = convert_string_to_int(s[i]);
            sumAfter += a[i];
        }
        cout << sumAfter - sumBefore;
    }
}