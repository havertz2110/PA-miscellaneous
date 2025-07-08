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
const int MAXN = 1e5 + 10;
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
 
void Nhap(PhanSo a[MAXN], int n) {
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i].u >> a[i].v;
        if (a[i].v == 0) cout << "Khong thoa yeu cau bai toan\n";
        else if (a[i].u == 0) cout << "0\n";
        else {
            int tmp = __gcd(a[i].u, a[i].v);
            a[i].u /= tmp;
            a[i].v /= tmp;
            if (a[i].v < 0) {
                a[i].u *= -1;
                a[i].v *= -1;
            }
            cout << a[i].u;
            if (a[i].v != 1) cout << "/" << a[i].v;
            cout << "\n";
        }
    }
}
 
void Xuat(PhanSo a[MAXN], int n) {
 
}
