#include <vector>
#include <iostream>
#include <string>

using namespace std;

int m, n, p, k;
string s;
int del[50][50][250] = {};
bool bl[50][50] = {};

pair<int, int> trans(int i, int j, char c) {
    switch (c) {
        case 'U':
            if (i == 1 || bl[i - 1][j]) {
                return {i, j};
            }
            return {i - 1, j};
        case 'D':
            if (i == m || bl[i + 1][j]) {
                return {i, j};
            }
            return {i + 1, j};
        case 'L':
            if (j == 1 || bl[i][j - 1]) {
                return {i, j};
            }
            return {i, j - 1};
        case 'R':
            if (j == n || bl[i][j + 1]) {
                return {i, j};
            }
            return {i, j + 1};
        default:
            return {0, 0};
    }
}

int main() {
    cin >> m >> n >> p >> k;
    cin >> s;
    for (int i = 1; i <= p; i++) {
        int x, y;
        cin >> x >> y;
        bl[x][y] = true;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int st = 0; st <= k; st++) {
                del[i][j][st] = 2000;
            }
        }
    }
    del[1][1][0] = 0;
    
    for (int st = 0; st < k; st++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                
                pair<int, int> t = trans(i, j, s[st]);
                if (t == pair(i, j)) {
                    if (del[i][j][st] < del[i][j][st + 1]) {
                        del[i][j][st + 1] = del[i][j][st];
                    }
                }
                else {
                    if (del[i][j][st] < del[t.first][t.second][st + 1]) {
                        del[t.first][t.second][st + 1] = del[i][j][st];
                    }
                    if (del[i][j][st] + 1 < del[i][j][st + 1]) {
                        del[i][j][st + 1] = del[i][j][st] + 1;
                    }
                }
            }
        }
    }
    
    if (del[m][n][k] == 2000) {
        cout << -1;
    }
    else {
        cout << del[m][n][k] << '\n';
    }
}
