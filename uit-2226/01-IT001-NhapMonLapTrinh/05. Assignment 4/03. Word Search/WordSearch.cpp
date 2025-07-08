#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<char>> vt;
int tf[10][10] ; 
vt getMatrix(string s, int &n, int &m)
{
    vt g;
    g.clear();
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '[')
        {
            vector<char> h;
            h.clear();
            g.push_back(h);
            n++;
            continue;
        }

        if (('A' <= s[i] && s[i] <= 'Z') ||('a' <= s[i] && s[i] <='z') )
            g[n - 1].push_back(s[i]);
    }
    m = g[0].size();
    return g;
}

void dfs(int u, int v, vt g, int pos, string s , int n , int m ) 
{
    if (pos == s.size())
    {
        cout << "true";
        exit(0);
    }

    if (u < 0 || v < 0 || u == n || v == m || !tf[u][v] ) 
        return;
    
    tf[u][v] = 0 ; 
    int du[4] = {0,0,-1,1} ; 
    int dv[4] = {-1,1,0,0} ; 
    if (g[u][v] == s[pos])
    {
        for (int i = 0; i < 4; i++)
            dfs(u+du[i], v+dv[i],  g, pos + 1, s , n , m ) ; 
    }
    tf[u][v] = 1 ;
}

void solve(vt g, string s, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dfs(i, j, g, 0, s, n , m );
}

int main()
{
    for ( int i=0 ; i<10 ; i++ ) 
        for ( int j =0 ; j<10 ; j++ )  
            tf[i][j] = 1; 
 
    string s, t;
    int n = 0, m = 0;
    getline(cin, s); 
    cin >> t;

    vt g = getMatrix(s, n, m); 
    solve(g, t, n, m);
    cout << "false";
}