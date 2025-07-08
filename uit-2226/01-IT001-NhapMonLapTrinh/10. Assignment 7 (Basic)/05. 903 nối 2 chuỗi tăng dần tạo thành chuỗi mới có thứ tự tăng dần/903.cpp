#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
 
    int m;
    cin >> m;
    int b[100];
    for (int i = 0; i<m; i++){
        cin >> b[i];
    }
 
    int i = 0;
    int j = 0;
 
    while (i<n && j<m){
        if (a[i] <= b[j]){
            cout << a[i] << " ";
            i++;
        }
        else {
            cout << b[j] << " ";
            j++;
        }
    }
 
    for (;i<n; i++){
        cout << a[i] << " ";
    }
    for (;j<m; j++){
        cout << b[j] << " ";
    }
 
    return 0;
}