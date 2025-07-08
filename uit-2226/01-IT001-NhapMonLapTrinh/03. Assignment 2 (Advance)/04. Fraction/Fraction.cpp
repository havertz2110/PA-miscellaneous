#include <bits/stdc++.h>
using namespace std;
int main ()
{

  long long a, b,c,d;
  int dem = 0;
  cin >> a>> b >> c >> d;
  while ((a!=c)||(b!=d))
    {
      a++;
      b++;
      long long a2=a;
      a /= __gcd (a, b);
      b /= __gcd (a2, b);
     if (((c-d!=1) && (a-b==1))||((d-c!=1) && (b-a==1))){
         dem=0;
         break;
     }
      dem++;
    }
  cout << dem;
  return 0;
}
