#include <bits/stdc++.h>
#define int long long
using namespace std;

int t;
long long k;

bool check(long long val) {
   long long j;
   for (long long i = sqrt(val); i; i--) {
        int l = 1, r = val, mid, tmp;
    while (l <= r) {
        mid = (l + r) >> 1;
        tmp = mid * i + (mid + 1) * (i + 1);
        if (tmp == 2 * val) {
            if (mid > i) swap(mid, i);
            cout << mid << " " << i << "\n";
            return true;
        }
        else if (tmp > 2 * val) r = mid - 1;
        else l = mid + 1;
     }
  }
  return false;
}
int32_t main(){
cin >> t;
while ( t-- ) {
cin >> k;
if (!check(k)) cout << -1 << " " << -1 << "\n";
   }
}