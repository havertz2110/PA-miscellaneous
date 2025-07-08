#include <bits/stdc++.h>
using namespace std;
 
long long a,k,b,m,n;
 
long long Calc(long long d){
    if (log10(d - d%k) - log10(k) + log10(k-1) + log10(a) > 18 || log10(a) + log10(d%k) > 18 
    || log10(d - d%m) - log10(m) + log10(m-1) + log10(b) > 18 || log10(b) + log10(d%m) > 18)
    return INT64_MAX;
    return (d - d%k)/k*(k-1)*a + a*(d%k) + (d - d%m)/m*(m-1)*b + b*(d%m);
}
 
long long Find(long long l, long long r){
    long long ret=0;
    while (l <= r){
        long long mid = (l+r)/2;
        if (Calc(mid) >= n){
            ret = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> a >> k >> b >> m >> n;
    cout << Find(1,2*n);
    return 0;
}