#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll s)
{
    ll tong=0;
    while(s!=0)
    {
        s/=2;
        tong+=s;
    }
    return tong;
}


int main() 
{
   ll lf,rt;
   cin >> lf >> rt;
   cout << solve(rt) - solve(lf-1);
   return 0;
}
