
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[256];
int main(){
string s;
int k;
cin >> k >> s;
int res = 1e5;
cnt['A' ]= cnt['V'] = cnt['C'] = 0 ;
for ( int l=1, r=0; l<s.size(); --cnt [s[l++]])
{
while ( r+1 < s.size() && (cnt['A'] < k || cnt['V'] < k || cnt['C'] <k))
++cnt[s[++r]];
if (cnt['A']<k || cnt['V'] < k || cnt['C'] <k)
break;
int t=0;
t+= cnt['A']-k;
t+=cnt['V']-k;
t+=cnt['C']-k;
res = min(res,t);
    }
cout <<res;
return 0 ;
}