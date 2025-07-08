#include <bits/stdc++.h>
using namespace std;

vector<long long> cnt(10);
vector<string> a;

long long Pow[13];
void calcPow(){
    long long tmp = 1;
    for (long long i=0;i<13;i++){
        Pow[i] = tmp;
        tmp*=10;
    }
}

void calc(string x){
    if (cnt[x[0] - '0'] < 1e12) cnt[x[0] - '0'] += 1e12; 
    for (long long i=0;i < x.length(); i++){
        cnt[x[i] - '0'] += Pow[x.length() - i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    calcPow();
    long long n;
    cin >> n;
    a.resize(n);
    for (long long i=0;i<n;i++){
        cin >> a[i];
    }

    for (long long i=0;i<n;i++){
        calc(a[i]);
    }

    sort(cnt.begin(),cnt.end());
    long long ans=0;
    for (long long i=0;i<10;i++){
        if (cnt[i] > 1e12) cnt[i] -= 1e12;
        ans += cnt[i]*i;
    }

    cout << ans;
    return 0;
}

# cách khác dưới đây:

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

const int inf=1e9+7;
const long double PI=acos(-1);
const int MOD = 1e9+7;
const int N = 1e5+7;

int a[N],n;
int p[10]={0,1,2,3,4,5,6,7,8,9};
ll po[10];
bool idk[10];
ll ans;
int m10[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000};

signed main(){
    fastIO;
    /*freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);*/
    cin >> n;
    FORW(i,1,n,1){
        cin >> a[i];
        int t = a[i];
        int mul = 1;
        while(t){
            if(t/10 == 0) idk[t] = 1;
            po[t % 10] += mul;
            mul *= 10;
            t /= 10;
        }
    }
    do{
        ll tmp = 0;
        bool kt=0;
        FOR(i,0,10,1){
            if(p[i]==0 && idk[i]) {kt=1; break;}
            tmp += po[i] * p[i];
        }
        if(kt) continue;
        ans = max(tmp,ans);
    }while(next_permutation(p,p + 10));
    cout << ans;
}