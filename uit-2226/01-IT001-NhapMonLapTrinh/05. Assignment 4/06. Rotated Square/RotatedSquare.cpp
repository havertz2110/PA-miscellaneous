#include <bits/stdc++.h>
using namespace std;

const int mN = 101;
int n, N, cnt;
char s[mN][mN], bigS[mN][mN], newS[mN][mN];

void rotate_matrix() {
    int col = n + 1;
    for (int i = 1; i <= n; i++) {
        col--;
        for (int j = 1; j <= n; j++)
            newS[j][col] = s[i][j];
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        s[i][j] = newS[i][j];
}

bool check(int u, int v) {
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        if (s[i][j] != bigS[i + u - 1][j + v - 1]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> N >> n) {
        if (N + n == 0) break;
        for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) cin >> bigS[i][j];
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> s[i][j];
        for (int turn = 0; turn < 4; turn++) {
            cnt = 0;
            for (int i = 1; i <= N - n + 1; i++)
            for (int j = 1; j <= N - n + 1; j++)
                if (check(i, j)) cnt++;
            cout << cnt << " ";
            rotate_matrix();
        }
        cout << "\n";
    }
}