#include <bits/stdc++.h>
using namespace std;
 
vector<long long> a,tree,dp,s;
 
void build(int id, int l, int r){
    if (l == r) {
        tree[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id] = min(tree[id*2],tree[id*2+1]);
}
 
long long query(int id, int l, int r, int L, int R){
    if (r<L || l>R) return INT32_MAX;
 
    if (L <= l && r <= R) return tree[id];
 
    int mid = (l+r)/2;
    return min(query(id*2,l,mid,L,R), query(id*2+1,mid+1,r,L,R));
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int n;
    cin >> n;
 
    a.resize(n+1);
    tree.resize(4*n+4);
    dp.resize(n+1);
    s.resize(n+1);
 
    for (int i = 1; i<=n; i++){
        cin >> a[i];
        s[i] = s[i-1]+a[i];
    }
 
    build(1,1,n);
 
    for (int i = 1; i<=n; i++){
        if (i < 10) {
            dp[i] = dp[i-1]+a[i];
            continue;
        }
        long long Min = query(1,1,n,i-9,i);
        // cout << Min << "\n";
        dp[i] = min(dp[i-1] + a[i], dp[i-10] + s[i] - s[i-10] - Min);
    }
 
    cout << dp[n];
    return 0;
}