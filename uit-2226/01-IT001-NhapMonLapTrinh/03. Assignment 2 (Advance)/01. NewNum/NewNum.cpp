#include <bits/stdc++.h>
using namespace std;
int main ()
{
  string n;
  cin >> n;
  int s = 0;
  const int val0 = int ('0');
  for (int i = 0; i < n.length (); i++)
    {
      s = s + int (n[i]) - val0;

    }
int i=0;
int c=0;
  while (c==0)
    {
      int a = int (n[i]) - val0;
      int b = a;
      int t = s;
     while ((t%3!=0) && (a<9))
     {
	  a += 1;
	  t += 1;
	 }
      while (a < 7)
	  a +=3;
	  
      if ((t%3==0) && (i==n.length()-1))
      {
              if (a==b)
              {
                  n[i]= char (val0+a-3);
                  break;
              }
              else 
              {
                 n[i]= char (val0+a);
                 break;
              }
      }
              if ((a==9) && (t%3!=0)&& (i==n.length()-1))
        {
          while  (t%3!=0)
          {
              
              a-=1;
              t-=1;
          }
          n[i]= char (val0+a);
          break;
        }

      
      
      if ((b == a) || (t%3!=0))
	{
	  i++;
	}
      else if ((b != a) && (t%3==0))
	{
	  n[i] = char (val0+a);
	  c=1;
	}
    }
  cout << n;
  return 0;
}
