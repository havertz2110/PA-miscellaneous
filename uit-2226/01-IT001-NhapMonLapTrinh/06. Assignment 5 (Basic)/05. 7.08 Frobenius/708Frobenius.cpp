#include<bits/stdc++.h>
#include <initializer_list>
#define fastIO                  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define FOR(i, j, k, in)        for (int i = (j); i < (k); i += (in))
#define FORW(i, j, k, in)        for (int i = (j); i <= (k); i += (in))
#define RFOR(i, j, k, in)        for (int i = (j); i >= (k); i -= (in))
#define RFORW(i, j, k, in)        for (int i = (j); i > (k); i -= (in))
#define sz(arr)                 ((int)(arr).size())
#define pb                      push_back
#define pf                      push_front
#define pob                      pop_back
#define pof                      pop_front
#define fi                        first
#define se                        second
#define mp                        make_pair
#define gP(n) (mark[(n)>>6]&(1<<(((n)>>1)&31)))
#define rP(n) (mark[(n)>>6]&=~(1<<(((n)>>1)&31)))
#define all(x)                      x.begin(), x.end()

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<pii,int> piii;
typedef vector<pii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef pair<pii,string> psi;

const int N = 1000;
double a[N][N];
int ok,m,n;

string solve(){
    FORW(i,1,n,1){
        if(a[i][i] != 1) return "No";
    }
    FORW(i,1,n,1){
        FORW(j,1,n,1){
            if(i!=j && a[i][j] != 0 && ok!=0 && ok!=j) return "No";
            if(i!=j && a[i][j] != 0 && ok==0) ok=j;
        }
    }
    return "Yes";
}

signed main(){
    fastIO;
    cin>>n>>m;
    FORW(i,1,n,1){
        FORW(j,1,m,1){
            cin>>a[i][j];
        }
    }
    cout<<solve();
}