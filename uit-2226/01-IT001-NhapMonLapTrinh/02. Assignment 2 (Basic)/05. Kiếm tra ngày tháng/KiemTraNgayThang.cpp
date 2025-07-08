#include <bits/stdc++.h>

using namespace std;
int main()
{
    int ngay,thang,nam;
	cin>>ngay>>thang>>nam;
	if (nam==0){
		cout<<"Nam khong hop le.";
		return 0;
	}
	if (thang>12){
		cout<<"Thang khong hop le.";
		return 0;
	}
	if((thang==1 || thang==3 || thang==5 || thang==7 || thang==8 || thang==10 || thang==12) && (ngay >=1 && ngay <=31)){
		cout<<ngay<<"/"<<thang<<"/"<<nam<<" la ngay hop le."; return 0;
	}
	else if ((nam%4==0 ) &&(thang==2) && (ngay>=1 && ngay <=29)){
			cout<<ngay<<"/"<<thang<<"/"<<nam<<" la ngay hop le.";return 0;
		}
		else if((nam%4!=0) && (thang==2) && (ngay >=1 && ngay <=28)){
				cout<<ngay<<"/"<<thang<<"/"<<nam<<" la ngay hop le.";return 0;
			}
			else
				cout<<ngay<<"/"<<thang<<"/"<<nam<<" la ngay khong hop le.";return 0;
		}
