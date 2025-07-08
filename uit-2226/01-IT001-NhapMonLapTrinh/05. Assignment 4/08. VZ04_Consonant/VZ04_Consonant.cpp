#include <bits/stdc++.h>
#define bit(i, k) ((i>>k)&1)
using namespace std;

const int ch[] = {'b', 'c', 'd', 'f',	'g', 'h', 'j', 'k',
                'l', 'm', 'n', 'p',	'q', 'r', 's', 't',
                 'v', 'x', 'z'};
string s;
int preres, res, final_mask;
int previous[19][19], follow[19][19], tt[300];

bool check(int i) {
    if (i < 0 || i >= s.size() ||
        s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'
            || s[i] == 'u' || s[i] == 'w' || s[i] == 'y') return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int dem = 0;
    for (int i = 0; i < 19; i++) tt[ch[i]] = dem++;
    cin >> s;
    for (int i = 0; i < s.size(); i++) if (check(i)) {
        if (check(i - 1)) previous[tt[s[i]]][tt[s[i - 1]]]++;
        if (check(i + 1)) follow[tt[s[i]]][tt[s[i + 1]]]++;
    }
    int full = (1<<19) - 1;
    for (int mask = 0; mask <= full; mask++) {
        preres = 0;
        for (int i = 0; i < 19; i++)
            for (int j = 0; j < i; j++)
                if (bit(mask, i) ^ bit(mask, j) == 1)
                    preres += previous[i][j] + follow[i][j];
        if (res < preres) {
            res = preres;
            final_mask = mask;
        }
    }
    for (int i = 0; i < s.size(); i++)
        if (bit(final_mask, tt[s[i]]) == 1) cout << char (s[i] - 32);
        else cout << s[i];
}