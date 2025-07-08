#include <bits/stdc++.h>
using namespace std;
int main ()
{
  float a[100][100];
  int row,col;
  cin>> row >> col; // nhap so dong / cot
  float trace=0;
  for (int j=1; j<=col;j++){ // nhap ma tran 
      for (int i=1;i<=row;i++){
         cin>> a[i][j];
         if (i==j) // tinh toan ma tran 
            trace+=a[i][j];
      }
  }
  cout << trace;
return 0;
}