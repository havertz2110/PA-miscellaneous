#include<iostream>
#define MAX 20
using namespace std;
 
int n;
int Bool[MAX] = { 0 };
int A[MAX];
 
void xuat() {
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
 
void Try(int k) {
    for (int i = 1; i <= n; i++) {
     
        if (!Bool[i]) {
            A[k] = i; 
            Bool[i] = 1;
            if (k == n)
                xuat();
            else
                Try(k + 1);
            Bool[i] = 0;
        }
    }
}
 
int main() {
    cin >> n;
    Try(1);
}
