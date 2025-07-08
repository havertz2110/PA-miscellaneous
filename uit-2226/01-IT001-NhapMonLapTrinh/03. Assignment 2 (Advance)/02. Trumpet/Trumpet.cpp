#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	vector<int> vec;
	int dem=0;
	int dem1=0;
	for(int i=0;i<a;i++){
		cin>>i;
		vec.push_back(i);
	}
	for(int j=0;j<a;j++){
		if(vec[j]==0)
			dem++;
		else if(vec[j]==1)
			dem=0;
		if(dem==b){
			dem1++;
			dem=0;
		}
	}
	cout<<dem1;
	return 0;
}
