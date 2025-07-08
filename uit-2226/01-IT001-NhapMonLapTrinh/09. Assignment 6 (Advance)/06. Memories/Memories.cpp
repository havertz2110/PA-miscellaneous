#code này không được full điểm nhé
#include <bits/stdc++.h>
using namespace std;
 
vector<long long> s;
vector<long long> a;
long long n,k;
 
bool Solve(long long t)
{
    long long Start=0,tmp=1;
    for (long long i=1;i<=n;i++){
        if (a[i] > t) return 0;
        if (s[i] - s[Start] > t){
            Start = i-1;
            tmp++;
        }
    }
    if (tmp>k) return false;
    return true;
}
 
int main()
{
    cin >> n >> k;
    a.resize(n+1);
    for (long long i=1;i<=n;i++){
        cin >> a[i];
    }
    s.resize(n+1);
 
    s[0]=0;
    for (long long i=1;i<=n;i++){
        s[i] = s[i-1] + a[i];
    }
 
    long long L=s[n]/k,R=s[n];
    long long kq;
    while (L<=R){
        long long mid=(L+R)/2;
        if (Solve(mid)){
            kq=mid;
            R=mid-1;
        }
        else {
            L=mid+1;
        }
    }
    cout << kq;
}