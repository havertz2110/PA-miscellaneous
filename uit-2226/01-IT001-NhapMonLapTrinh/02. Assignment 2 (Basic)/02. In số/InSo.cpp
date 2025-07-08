#include <iostream>

using namespace std;

int main(){
	double a,b,c,tam;
	cin >> a >> b >> c;
	if(a>b)
	{
		tam=a;
		a=b;
		b=tam;
	}
	if(a>c)
	{
		tam=a;
		a=c;
		c=tam;
	}
	if(b>c)
	{
		tam=b;
		b=c;
		c=tam;
	}
	cout<<a <<" "<<b <<" "<<c;
}
