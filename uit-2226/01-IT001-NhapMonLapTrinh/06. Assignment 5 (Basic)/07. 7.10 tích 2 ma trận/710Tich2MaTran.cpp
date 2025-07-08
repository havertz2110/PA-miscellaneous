#include <iostream>
using namespace std;
int main(){
	float a[100][100], b[100][100],c[100][100];
	int x,y,i,j,m,n;

// ma tran a
	cin>> x >> y;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			cin >> a[i][j];
		}
	}

// ma tran b
	cin>>m>>n;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
            cin>>b[i][j];
		}
	}


c[i][j] = 0;

//nhan ma tran
		for(i = 0; i < x; i++){
			for(j = 0; j < n; j++){
				for(int k = 0; k < m; k++){
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}

		for(i = 0; i < x; i++){
			for(j = 0; j < n; j++){
				cout << c[i][j] << "  ";
			}
			cout << endl;
		}

	return 0;
}