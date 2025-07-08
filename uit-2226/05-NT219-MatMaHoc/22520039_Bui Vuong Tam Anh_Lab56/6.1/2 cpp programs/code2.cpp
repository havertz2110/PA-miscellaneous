#include <bits/stdc++.h>
using namespace std;
int main(){
    int MAX = 100;
    int matrix[MAX][MAX];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}