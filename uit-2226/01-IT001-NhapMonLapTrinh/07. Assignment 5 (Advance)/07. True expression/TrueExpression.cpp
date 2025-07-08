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
const int mN = 2e4 + 10;
const int mV = 110;
const int tt = 1e4 + 10;
const int dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0};
int numTest = 1, n, s;
bool mark[mN][mV];
pii pa[mN][mV];
queue <pii> q;
deque <char> ans;
 
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
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (numTest--) {
        int u, now, v;
        cin >> n >> s;
        s += tt;
        mark[tt][0] = 1;
        q.push({tt, 0});
        while (q.size()) {
            now = q.front().first;
            u = q.front().second;
            q.pop();
            if (u < n) {
                v = u + 1;
                loop(i, -1, 1, 2) if (!mark[now + v * i][v]){
                    mark[now + v * i][v] = 1;
                    pa[now + v * i][v] = {now, i};
                    q.push({now + v * i, v});
                }
            }
        }
        if (!mark[s][n]) cout << "NO_SOLUTION";
        else {
            now = s;
            while (n != 0) {
                v = pa[now][n].second;
                now = pa[now][n].first;
                if (v > 0) ans.push_front('+');
                else ans.push_front('-');
                n--;
            }
            for (char c : ans) cout << c;
        }
    }
}