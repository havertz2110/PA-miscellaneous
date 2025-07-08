#include <bits/stdc++.h>
using namespace std;
int main(){
    int m, n;
    cin >> m >> n;
    float a[m][n];
    for (int i=0; i< m; i++){
        for (int j=0; j< n;j++){
            cin >> a[i][j];
        }
    }
    for (int i=0;i<n;i++ ){
        float max=a[0][i];
        for(int j=1;j<m;j++){
            if(a[j][i]>max){
                max=a[j][i];
            }
        }
  cout << "Gia tri lon nhat tren cot " << i << " la: " << max << endl;
    }
}