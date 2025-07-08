#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sophantu;
    cin >> sophantu;
    int a[sophantu];
    int soluong=0;
    for (int i=0; i< sophantu; i++){
        cin >> a[i];
    }
    int max = a[0];
    for ( int j =0; j < sophantu; j++){
         if ( a[j] > max){
            max = a[j];
         }
    }
    for ( int c =0; c< sophantu; c++){
        if (a[c]==max)
            soluong ++;
    }
   cout << max << endl;
   cout << soluong;
}