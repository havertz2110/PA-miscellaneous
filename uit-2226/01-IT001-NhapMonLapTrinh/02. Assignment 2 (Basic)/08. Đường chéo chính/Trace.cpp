#include <bits/stdc++.h>
using namespace std;
int main ()
{
  float arr[100][100];
  int row,col;
  cin>> row >> col;
  float trace=0;
  for (int j=1; j<=col;j++)
    {
      for (int i=1;i<=row;i++)
      {
         cin>> arr[i][j];
         if (i==j)
            trace+=arr[i][j];
      }
  }
  cout << trace;
return 0;
}
