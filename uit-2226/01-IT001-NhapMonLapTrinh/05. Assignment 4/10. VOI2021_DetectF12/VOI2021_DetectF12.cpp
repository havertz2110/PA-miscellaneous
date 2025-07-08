#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<long long, long long > ii;

long long dis(ii a, ii b)
{
    return (long long)(a.f - b.f) * (a.f - b.f) + (long long)(a.s - b.s) * (a.s - b.s);
}

int main()
{
    int n, ff, res = 0;
    long long d;
    ii a[1005];
    vector<ii> f1, f2;
    cin >> n >> ff >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i].f >> a[i].s;

    for (int i = 1; i <= n; i++)
    {
        if (i == ff)
            continue;
        if (dis(a[i], a[ff]) < d * d)
            f1.push_back(a[i]);
        else
            f2.push_back(a[i]);
    }

    
    for (int j = 0; j < f2.size(); j++)
        for (int i = 0; i < f1.size(); i++)
            if (dis(f1[i], f2[j]) < d * d)
            {
                res++;
                break; 
            }
    cout << f1.size() << " " << res;
}