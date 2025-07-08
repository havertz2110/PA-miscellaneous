#include <bits/stdc++.h>
using namespace std;

void Nhap(int a[], int n){
    for(int i = 0; i < n ; i++){
        cin >>a[i]; 
    }
}


void Xuat(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] <<" ";
    }
}


void ThemPhanTu(int a[], int index, int PhanTu, int &n){
    for(int i = n; i > index; i--){ 
        a[i] = a[i-1];
    }
    a[index] = PhanTu; 
    n++; 
}
int main(){

    int n;
    scanf("%d",&n);
    int a[n]; 
    Nhap(a,n);

    int PhanTu;
    scanf("%d",&PhanTu);
    
    int index; 
    scanf("%d",&index);

    ThemPhanTu(a,index, PhanTu, n); 
    Xuat(a,n);   
}