#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9+7;
 
long long Pow(long long x, long long n){
    if (n == 1) return x;
    long long tmp = Pow(x,n/2);
    if (n%2 == 0){
        return (tmp*tmp)%MOD;
    }
    else return (((tmp*tmp)%MOD)*x)%MOD;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    long long n, l;
    cin >> n >> l;
 
    cout << ((l*l)%MOD * ((Pow(4,n+1) - 1)%MOD * (Pow(3,MOD-2))%MOD)%MOD)%MOD;
 
    return 0;
}