#include <bits/stdc++.h>
using namespace std;
 
const int mN = 110;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
typedef pair<int, int> ii;
int numRow, numCol, numHeir, numBattle;
int newMatrix[mN][mN], matrix[mN][mN];
vector <ii> sto[mN];
 
bool inMatrix(int u, int v) {
    return 1 <= u && u <= numRow && 1 <= v && v <= numCol;
}
 
int mod(int a, int b) {
    return a + b >= numHeir ? a + b - numHeir : a + b;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p, q;
    while (cin >> numHeir >> numRow >> numCol >> numBattle) {
        if (numHeir + numRow + numCol + numBattle == 0) break;
        for (int i = 1; i <= numRow; i++)
        for (int j = 1; j <= numCol; j++) {
            cin >> matrix[i][j];
            sto[matrix[i][j]].push_back({i, j});
        }
        while (numBattle--) {
            for (int i = 1; i <= numRow; i++)
            for (int j = 1; j <= numCol; j++)
                newMatrix[i][j] = matrix[i][j];
            for (int child = 0; child < numHeir; child++) {
                for (auto [u, v] : sto[child]) {
                    for (int i = 0; i < 4; i++) {
                        p = u + dr[i];
                        q = v + dc[i];
                        if (inMatrix(u, v) && matrix[p][q] == mod(matrix[u][v], 1))
                            newMatrix[p][q] = matrix[u][v];
                    }
                }
                sto[child].clear();
            }
            for (int i = 1; i <= numRow; i++)
            for (int j = 1; j <= numCol; j++) {
                matrix[i][j] = newMatrix[i][j];
                sto[matrix[i][j]].push_back({i, j});
            }
        }
        for (int i = 1; i <= numRow; i++) {
            for (int j = 1; j <= numCol; j++) cout << matrix[i][j] << " ";
            cout << "\n";
        }
        for (int i = 0; i < numHeir; i++) sto[i].clear();
    }
}
