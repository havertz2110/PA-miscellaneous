#include<bits/stdc++.h>
using namespace std;
string sum(string s1,string s2){
   reverse(s1.begin(),s1.end());
   reverse(s2.begin(),s2.end());
   string res; int c=0; int i=0;
   for(; i<min(s1.length(),s2.length()); i++)
   {
       int n=(s1[i]-'0'+s2[i]-'0')+c;
       res+=to_string(n%10);
       c=n/10;
   }
   for(; i<s1.length(); i++)
   {
       int n=(s1[i]-'0')+c;
       res+=to_string(n%10);
       c=n/10;
   }
   for(; i<s2.length(); i++)
   {
       int n=(s2[i]-'0')+c;
       res+=to_string(n%10);
       c=n/10;
   }
   while(c!=0){
       res+=to_string(c%10);
       c=c/10;
   }
   reverse(res.begin(),res.end());
   return res;
}
bool check(string s1,string s2,string s)
{
   if(s=="") return true;
   string n=sum(s1,s2);
   if(n==s.substr(0,n.length()) && check(s2,n,s.substr(n.length()))){
       return true;
   }
   else{
       return false;
   }
}
bool isAdditiveNumber(string num) {
   string s1,s2;
   for(int i=1; i<num.length(); i++){
       for(int j=i+1; j<num.length(); j++){
           s1=num.substr(0,i);
           s2=num.substr(i,j-i);
           if(s2[0]=='0' && s2.length()>1) continue;
           string s=num.substr(j);
           if(check(s1,s2,s)) return true;
       }
   }
   return false;
}
int main()
{
   string num;
   cin>>num;
  bool ans=isAdditiveNumber(num);
  ans=ans?true:false;
  cout<< boolalpha <<ans;
}