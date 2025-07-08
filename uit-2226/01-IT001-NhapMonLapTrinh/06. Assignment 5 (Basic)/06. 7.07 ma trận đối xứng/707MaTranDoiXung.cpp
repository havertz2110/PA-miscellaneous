#include <iostream>

using namespace std;

void nhap(float a[][100], int row, int col){
    for(int i =0;i< row;i++){
        for(int j=0;j< col;j++){
        cin >> a[i][j];
         }
}
}

int ktdoixung(float a[][100], int row, int col){
    for(int i=0;i<row;i++){
        for(int j=i+1;j<col;j++){
            if(a[i][j] != a[j][i]) return false;
        }
    }
     return true;
}

int main(){
float a[100][100];
int row, col;
cin >> row>>col;
nhap(a,row,col);
 if(ktdoixung(a,row,col)==1)
    cout<<"Yes";
    else
    cout<<"No";
}