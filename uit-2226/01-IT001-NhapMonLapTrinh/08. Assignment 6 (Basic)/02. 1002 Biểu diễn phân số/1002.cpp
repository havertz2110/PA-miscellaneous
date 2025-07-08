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
int numTest = 1;
 
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
 
struct PhanSo {
    int u, v;
};
 
void Nhap(PhanSo &a) {
    cin >> a.u >> a.v;
    if (a.v < 0) {
        a.u *= -1;
        a.v *= -1;
    }
}
 
PhanSo Nhap() {
    PhanSo k;
    cin >> k.u >> k.v;
    if (k.v < 0) {
        k.v *= -1;
        k.u *= -1;
    }
    return k;
}
 
int SoSanh(PhanSo a, PhanSo b) {
    if (a.u * b.v < b.u * a.v) return -1;
    if (a.u * b.v == b.u * a.v) return 0;
    return 1;
}