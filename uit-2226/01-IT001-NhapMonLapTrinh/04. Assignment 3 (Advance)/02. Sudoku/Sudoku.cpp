#include <bits/stdc++.h>
using namespace std;

const int mN = 10;
typedef pair<int, int> ii;
char c[mN][mN];
int a[mN][mN];
bool used[mN][mN], row[mN][mN], col[mN][mN];
vector <ii> stoPos;

int getComp(int u, int v) {
    return (u - 1) / 3 * 3 + (v - 1) / 3;
}

void print() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) cout << a[i][j] << " ";
        cout << "\n";
    }
    exit(0);
}

void Try(int id) {
    if (id == stoPos.size()) print();
    ii pos = stoPos[id];
    for (int i = 1; i <= 9; i++)
        if (!used[getComp(pos.first, pos.second)][i] && !row[pos.first][i] && !col[pos.second][i]) {
            used[getComp(pos.first, pos.second)][i] = 1;
            row[pos.first][i] = 1;
            col[pos.second][i] = 1;
            a[pos.first][pos.second] = i;
            Try(id + 1);
            used[getComp(pos.first, pos.second)][i] = 0;
            row[pos.first][i] = 0;
            col[pos.second][i] = 0;
        }
}

int main() {
    for (int i = 1; i <= 9; i++)
    for (int j = 1; j <= 9; j++) {
        cin >> c[i][j];
        if (c[i][j] == 'X') stoPos.push_back({i, j});
        else {
            used[getComp(i, j)][c[i][j] - '0'] = 1;
            row[i][c[i][j] - '0'] = 1;
            col[j][c[i][j] - '0'] = 1;
        }
        a[i][j] = c[i][j] - '0';
    }
    Try(0);
}
