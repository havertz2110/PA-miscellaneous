#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
		string s; getline(cin,s);
		for (int i=0;i<s.length();i++) {
			if (s[i]>='A'&&s[i]<='Z') {
				s[i]+=32;
			}
		}
		for (int i=0;i<s.length();i++) {
			if (s[i]>='a'&&s[i]<='z') {
				s[i]-=32;
				break;
			}
		}
		for (int i=0;i<s.length();i++) {
			if (s[i]==' '&& s[i+1]>='a'&&s[i+1]<='z') 
			    s[i+1]-=32;
		}
		for (int i=0;i<s.length();i++) {
		    if (s[i]==' ')
		   {
		    while (s[i+1]==' ')
		    {
		      s.erase(i+1,1);  
		    }
		   }
		}
		if (s.length()==' ')  s.pop_back();
		if (s[0]==' ') s.erase(0,1);
		cout << s << endl;
}
