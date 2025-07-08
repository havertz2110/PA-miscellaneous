#include <bits/stdc++.h>
using namespace std;
int snt(int N){
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}
int main() {
 int n;
 cin>>n;
 int tong=0;
 for (int i=2;i<=n;i++){
     if ((snt(i)==1)&&(snt(i+2)==1) &&(i+2<n)) {
     tong+=1;
     cout << i <<", "<< i+2 << endl;
     }
 }
 cout<< "Tong: " << tong <<" cap so sinh doi < " << n;
 return 0;
}
