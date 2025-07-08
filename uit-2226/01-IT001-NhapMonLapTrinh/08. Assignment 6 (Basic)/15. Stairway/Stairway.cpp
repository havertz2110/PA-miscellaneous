#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    if(n==1){
        cout<<"1";
        return 0;
    }
    long long dem=1;
   long long b=1;
    long long a=log10(n)+1;
    for(int i=2;i<a;i++){
        dem=dem+i*9*b;
        b*=10;
    }
    long long s = n/10-b;
    if(n%10!=0){
        dem+=a;
    }
    cout<<(s+1)*(a)+dem;
}