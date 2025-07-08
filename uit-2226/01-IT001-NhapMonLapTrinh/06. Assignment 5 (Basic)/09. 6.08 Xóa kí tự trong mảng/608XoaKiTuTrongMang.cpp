#include <iostream>

using namespace std;

int main(){
   int row;
   cin >> row;
   int a[row];
   for (int i =0; i<row; i++){
          cin >>  a[i];
        }
   int x;
   cin >> x;

    for (int i = 0; i < row; i++){
            if ( a[i] != x )
			cout << a[i] << " ";
	}
return 0;
}