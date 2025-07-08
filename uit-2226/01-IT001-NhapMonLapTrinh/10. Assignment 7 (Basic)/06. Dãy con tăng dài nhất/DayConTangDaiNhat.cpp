#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> F(n+1);
    F[0] = 0;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
    }
 
    for (int i = 1; i<=n; i++){
        for (int j = 0; j<=i; j++){
            if (a[i] > a[j]){
                F[i] = max(F[i],F[j]+1);
            }
        }
      
    }
    int ans = 0;
 
    for (int i = 1; i<=n; i++){
        ans = max(ans,F[i]);
    }
    cout << ans;
    return 0;
}