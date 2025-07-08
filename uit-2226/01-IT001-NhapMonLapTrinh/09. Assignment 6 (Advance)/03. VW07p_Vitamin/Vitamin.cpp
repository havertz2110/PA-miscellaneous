#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int n, x;
    cin >> n >> x;
    vector<int> s(n+1);
    vector<int> a(n+1);
    vector<int> dp(x+1),dp_n(x+1);
    for (int i = 1; i<=n; i++){
        cin >> a[i];
        s[i] = s[i-1]+a[i];
    }
    for (int i = 1; i<=x; i++){
        for (int j = 1; j<=n; j++){
            if (i - s[j] == 0 || i-s[j] > 0 && dp[i-s[j]]>0){
                if (dp[i]){
                    dp[i] = min(dp[i], dp[i-s[j]] + j + 1);
                }
                else{
                    dp[i] = dp[i-s[j]] + j + 1;
                }
                if (j == n){
                    if (dp_n[i]) dp_n[i] = min(dp_n[i], dp[i-s[j]] + j + 1);
                    else dp_n[i] = max(dp_n[i], dp[i-s[j]] + j + 1);
                }
            }
 
        }
        if (i - a[n] > 0 && dp_n[i- a[n]]){
            if (dp_n[i])
                dp_n[i] = min(dp_n[i-a[n]] + 1,dp_n[i]);
            else dp_n[i] = dp_n[i-a[n]] + 1;
        }
        if (dp_n[i]) dp[i] = min(dp[i], dp_n[i]);
        
    }
    
    if (dp[x] == 0){
        cout  << - 1;
    }
    else cout << dp[x] - 1;
 
    return 0;
}