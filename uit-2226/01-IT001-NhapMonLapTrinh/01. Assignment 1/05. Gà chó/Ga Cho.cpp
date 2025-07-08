#include <iostream>

#include <math.h>
using namespace std;

int main()
{
   int ga, cho;
   int xxx, yy;
  // xxx là tổng số con
  // yy là tổng số chân
   cin >> xxx >> yy;
cho = (yy - 2*xxx)/2;
ga = xxx - cho;
cout << ga <<  " " << cho;
}
