#include <bits/stdc++.h>
using namespace std;
int main ()
{

  int a, b,c,d, u;
  int solan = 0;
  cin >> a>> b >> c >> d;
  while ((a!=c)||(b!=d))
    {
    a++;
    b++;
    u = __gcd(a,b );
    a/= u;
    b/=u;
     if (((c-d!=1) && (a-b==1))||((d-c!=1) && (b-a==1)))
        {
         solan=0;
         break;
     }
      solan++;
    }
  cout << solan;
  return 0;
}