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
const int mN = 2e5 + 10;
const int dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0};
int numTest = 1, n, cnt;
int a[mN];
map <int, int> mp;
 
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
 
void process(int val) {
    mp[val] = 0;
    while (mp[val] == 0 && val%2 == 0) {
        val >>= 1;
        cnt++;
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    veci sto{};
    while (numTest--) {
        cin >> n;
        rep(i, 1, n){
            cin >> a[i];
            if (a[i]%2 == 0) {
                sto.push_back(a[i]);
                mp[a[i]]++;
            }
        }
        sort(all(sto), greater<int>());
        sto.resize(unique(all(sto)) - sto.begin());
        rep(i, 0, sz(sto) - 1) process(sto[i]);
        cout << cnt;
    }
}