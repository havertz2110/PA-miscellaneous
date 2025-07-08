#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    int tmp = 0;
    long long res = 0ll,check = 0ll;
    cin >> s;
    sort(s.begin(), s.end());
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
            tmp = i;
        else
            check = 1ll;
        res = res + tmp;
    }

    cout << res + check;
}