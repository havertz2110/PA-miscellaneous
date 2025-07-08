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
const int mN = 5;
const int dr[] = {0, -1, 0, 1, -1, -1, 1, 1}, dc[] = {1, 0, -1, 0, -1, 1, -1, 1};
int numTest = 1;
int a[5][5], x[5][5];
 
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
 
bool inMatrix(int u, int v) {
    return (1 <= u && u <= 4 && 1 <= v && v <= 4);
}
 
void check() {
    int cnt;
    rep(i, 1, 4)
    rep(j, 1, 4) {
        cnt = 0;
        rep(k, 0, 7)
            if (inMatrix(i + dr[k], j + dc[k]) && x[i + dr[k]][j + dc[k]] == 1)
                cnt++;
        if (cnt != a[i][j]) return;
    }
    rep(i, 1, 4) {
        rep(j, 1, 4) cout << x[i][j] << " ";
        cout << "\n";
    }
    exit(0);
}
 
void Try(int u, int v) {
    if (u == 5 && v == 1) {
        check();
        return;
    }
    rep(i, 0, 1) {
        x[u][v] = i;
        if (v == 4) Try(u + 1, 1);
        else Try(u, v + 1);
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (numTest--) {
        rep(i, 1, 4)
        rep(j, 1, 4) cin >> a[i][j];
        Try(1, 1);
    }
}