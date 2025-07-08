#include <bits/stdc++.h>
using namespace std;
int main(){
string s1,s2;
getline(cin,s1);
getline(cin,s2);
int n1=s1.length();
int n2=s2.length();
if ( n1 > 254 || n2 >254||n1 + n2 > 254)
{
    cout <<  "Khong noi duoc. Khong du bo nho.";
}
 else
  cout << s1 << s2;
}
