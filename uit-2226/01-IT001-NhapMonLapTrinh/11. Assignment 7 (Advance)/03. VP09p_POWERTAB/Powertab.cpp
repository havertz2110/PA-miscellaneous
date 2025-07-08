#include <bits/stdc++.h>
using namespace std;
 
struct matrix{
    long long a=1, b=0, c=0, d=1;
};
 
long long n, m, x;
 
matrix I = {1,0,0,1};
 
matrix multiplyMatrix(matrix mt1, matrix mt2, long long p){
    matrix ret;
    ret.a = ((mt1.a*mt2.a)%p + (mt1.b*mt2.c)%p)%p;
    ret.b = ((mt1.a*mt2.b)%p + (mt1.b*mt2.d)%p)%p;
    ret.c = ((mt1.c*mt2.a)%p + (mt1.d*mt2.c)%p)%p;
    ret.d = ((mt1.c*mt2.b)%p + (mt1.d*mt2.d)%p)%p;
    return ret;
}
 
matrix powMatrix(matrix mt, long long k, long long p){
    if (k == 1) return mt;
    if (k == 0) return I;
    matrix tmp = powMatrix(mt,k/2,p);
    tmp = multiplyMatrix(tmp,tmp,p);
    if (k%2 == 0) return tmp;
    else return multiplyMatrix(tmp,mt,p);
}
 
long long Pow(long long x, long long k, long long p){
    if (k == 1) return x;
    if (k == 0) return 1;
    
    long long tmp = Pow(x,k/2,p);
    if (k%2 == 0){
        return tmp*tmp%p;
    }
    else return (tmp*tmp)%p*x%p;
}
 
long long Solve(long long x1, long long x2, long long y1, long long y2,long long p){
    long long t0 = Pow(x, y1 + (x1-1)*m, p);
    
    matrix mt1 = {1,x,0,x};
    mt1 = powMatrix(mt1,y2 - y1, p);
    long long t1 = (mt1.a + mt1.b)%p;
 
    long long tmp = Pow(x,m,p);
    matrix mt2 = {1,tmp,0,tmp};
    mt2 = powMatrix(mt2, x2 - x1, p);
    long long t2 = (mt2.a + mt2.b)%p;
 
    return t0*t1%p*t2%p;
}
 
int main()
{
    
    cin >> n >> m >> x;
    long long q;
    cin >> q;
    for (int i = 1; i<=q; i++){
        long long x1, x2, y1, y2, p;
        cin >> x1 >> x2 >> y1 >> y2 >> p;
        cout << Solve(x1,x2,y1,y2,p) << "\n";
    }
    return 0;
}