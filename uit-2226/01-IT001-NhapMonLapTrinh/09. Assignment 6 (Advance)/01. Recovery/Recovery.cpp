#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    long long n, c, k;
    cin >> n >> c >> k;
    queue<long long> q;
    vector<long long> a(n+1);
    for (long long i=1; i<=n;i++){
        cin >> a[i];
    }
    long long ans = INT64_MAX;
    sort(a.begin()+1, a.end());
 
    for (int i = 1; i<=n; i++){
        if (a[i] <= c && a[i] - a[i-1] > k) ans = 0;
    }
 
    long long s = 0;
    long long cnt = 0;
    for (long long i = 1; i<=n; i++){
        if (a[i] <= k){
            s += a[i];
            q.push(a[i]);
            cnt = i;
        }
        else break;
    }
    ans = min(ans,s);
 
    for (long long i = cnt+1; i<=n; i++){
        if (a[i] > c){
            break;
        }
        while (!q.empty() && a[i] - q.front() > k){
            s-= q.front();
            q.pop();
        }
        ans = min(ans,s);
        s+= a[i];
        q.push(a[i]);
        if (i < n && a[i] == a[i+1]) continue;
        while (a[i] - q.front() + 1 > k){
            s-= q.front();
            q.pop();
        }
        ans = min(ans,s);
    }
    queue<long long> q2;
    long long sum = 0;
    for (int i = 1; i<=n; i++){
        if (a[i] > c) break;
        q2.push(a[i]);
        sum += a[i];
    }
 
    while (q2.size() && c - q2.front() + 1 > k){
        sum -= q2.front();
        q2.pop();
    }
    ans = min(ans,sum);
 
    cout << ans;
 
    return 0;
}
