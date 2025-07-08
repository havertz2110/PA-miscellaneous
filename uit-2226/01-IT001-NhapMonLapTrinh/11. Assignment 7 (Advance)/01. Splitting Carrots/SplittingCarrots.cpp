#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 2e5+5;
 
int main()
{
    int n;
    cin >> n;
    int a[100];
    vector<vector<int>> F(2,vector<int>(MAX));
    F[0][0] = true;
 
    int sum = 0;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }
 
    for (int i = 1; i<=n; i++){
        for (int j = 0; j < MAX; j++){
            if (j-a[i] >= 0)
                F[i%2][j] = max({F[i%2][j], F[1-(i%2)][j], F[1-(i%2)][j-a[i]]});
            else F[i%2][j] = max(F[i%2][j],F[1-(i%2)][j]);
        }
    }
   
    if (sum%2 == 1 || (!F[0][sum/2] && !F[1][sum/2])){
        cout << 0;
        return 0;
    }
 
    int tmp = a[1];
    for (int i = 1; i<=n; i++){
        tmp = __gcd(tmp,a[i]);
    }
 
    int ans = 0;
 
    for (int i = 1; i<=n; i++){
        a[i]/=tmp;
        if (a[i]%2 == 1) {
            ans = i;
            break;
        }
    }
    cout << 1 << "\n";
    cout << ans;
 
    return 0;
}
