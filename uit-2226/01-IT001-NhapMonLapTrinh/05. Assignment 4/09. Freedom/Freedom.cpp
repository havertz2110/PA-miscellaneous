#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9;
int lf, rt, cnt;
vector <int> sto, stoNum;

bool check (int val) {
for (int i = 0; stoNum[i] <= val; i++)
if (val % stoNum[i] == 0) return false;
return true;
}

int gcd(int a, int b) {
if (b == 0) return a;
return gcd(b, a%b ) ;
}

int main() {
cin >> lf >> rt;
for (int i = 2; i * i <= MAX; i++)
stoNum. push_back(i * i);
stoNum. push_back(MAX + 1);
for (int i = lf; i <= rt; i++)
if (check(i)) sto. push_back(i);
for (int i = 0; i < sto.size(); i++)
for (int j = i + 1; j < sto.size(); j++)
if (gcd(sto[i], sto[j]) == 1) ++cnt;
cout << cnt;
}