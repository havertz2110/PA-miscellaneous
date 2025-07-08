#include <bits/stdc++.h>
using namespace std;

int val( long long a,  long long b, long long c,  long long d){
int dem=0;
while (a>c){
    ++a/=2;
    dem++;
}
while (b>d){
    ++b/=2;
    dem++;
}
return dem;
}
int main() {
 
    long long n,m,h,w,dem,res;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    std::cin>> n >> m >> h >>w;
    std::cout<< std::min(val(m,n,h,w),val(n,m,h,w));
return 0;
}
