#include <bits/stdc++.h>
using namespace std;

int main(){
int k;
string s, s1;
bool flag = 0;
getline(cin, s) ;
getline(cin, s1) ;
cin >> k;
if(k < 0 || k > s. size()) {
cout << "Vi tri " << k <<" khong thoa dieu kien.";
return 0;
}
   for (int i = 0; i < s. size(); i++) {
       if (i == k) {
        cout << s1;
        flag = true;
       }
        cout << s[i];
   }
if (flag==0) cout << s1;

}