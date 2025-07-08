
#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e9+9;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+2,vector<int> (m+2));
    vector<vector<pair<int,int>>> F(n+2, vector<pair<int,int>> (m+2,{2*MAX,2*MAX}));
    vector<vector<pair<char,char>>> Trace(n+2, vector<pair<char,char>> (m+2));
 
    F[n][m+1] = {0,0};
    F[n+1][m] = {0,0};
 
    pair<int,int> pos0;
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            cin >> a[i][j];
            if (a[i][j] == 0) {
                pos0 = {i,j};
            }
        }
    }
 
    bool check_0 = false;
 
    for (int i = n; i>=1; i--){
        for (int j = m; j>=1; j--){
            int pow2 = 0, pow5=0;
            if (a[i][j] == 0){
                check_0 = true;
                F[i][j].first = MAX;
                F[i][j].second = MAX;
                if (i==n)Trace[i][j] = {'L','L'};
                else Trace[i][j] = {'D','D'};
                continue;
            }
            while (a[i][j]%2 == 0 && a[i][j] != 0){
                a[i][j] /= 2;
                pow2++;
            }
            while (a[i][j]%5 == 0 && a[i][j] != 0){
                a[i][j] /= 5;
                pow5++;
            }
            
            //min 2
            if (F[i+1][j].first > F[i][j+1].first){
                Trace[i][j].first = 'L';
                F[i][j].first = F[i][j+1].first + pow2;
            }
            else {
                Trace[i][j].first = 'D';
                F[i][j].first = F[i+1][j].first + pow2;
            }
 
            //min 5
            if (F[i+1][j].second > F[i][j+1].second){
                Trace[i][j].second = 'L';
                F[i][j].second = F[i][j+1].second + pow5;
            }
            else {
                Trace[i][j].second = 'D';
                F[i][j].second = F[i+1][j].second + pow5;
            }
        }
    }
 
 
    vector<char> duong_di_2(n+m-1),duong_di_5(n+m-1), duong_di_0(n+m-1);
    bool check = true;
    // tim duong di it 2 nhat
    int i = 1, j = 1, cnt = 1;
    while (i!=n || j!=m){
        duong_di_2[cnt] = Trace[i][j].first;
        cnt++;
        if (Trace[i][j].first == 'D'){
            i++;
        }
        else j++;
    } 
 
    //tim duong di it 5 nhat
    i = 1, j = 1, cnt = 1;
    while (i!=n || j!=m){
        duong_di_5[cnt] = Trace[i][j].second;
        cnt++;
        if (Trace[i][j].second == 'D'){
            i++;
        }
        else j++;
    } 
    //duong di it 0 nhat
    i = 1, j = 1, cnt = 1;
    bool duong_di_0_2 = true;
    bool duong_di_0_5 = true;
 
    while (i!=n || j!=m){
        if (a[i][j] == 0){
            pos0.first = 0;
            pos0.second = 0;
        }
        if (i < pos0.first){
            duong_di_0[cnt] = 'D';
            i++; cnt++;
        }
        else if (i == pos0.first && j < pos0.second){
            duong_di_0[cnt] = 'L';
            j++; cnt++;
        }
        else if (i >= pos0.first && i < n){
            duong_di_0[cnt] = 'D';
            i++; cnt++;
        }
        else {
            duong_di_0[cnt] = 'L';
            j++; cnt++;
        }
    }
 
    //duong di tu dien nho nhat
    
    for (int i = 1; i<=n+m-2; i++){
        if (duong_di_2[i] > duong_di_5[i]){
            check = false;
            break;
        }
        if (duong_di_2[i] < duong_di_5[i]){
            check = true;
            break;
        }
    }
 
    //duong di 0 nho nhat?
    for (int i = 1; i<=n+m-2; i++){
        if (duong_di_0[i] > duong_di_5[i]){
            duong_di_0_5 = false;
            break;
        }
        if (duong_di_0[i] < duong_di_5[i]){
            duong_di_0_5 = true;
            break;
        }
    }
    for (int i = 1; i<=n+m-2; i++){
        if (duong_di_0[i] > duong_di_2[i]){
            duong_di_0_2 = false;
            break;
        }
        if (duong_di_0[i] < duong_di_2[i]){
            duong_di_0_2 = true;
            break;
        }
    }
 
    if (check_0 && min(F[1][1].first, F[1][1].second) >= 1){
        int tmp = 0;
        if (F[1][1].first > 1 || (F[1][1].first == 1 && duong_di_0_2 == true)){
            tmp++;
        }
        if (F[1][1].second > 1 || (F[1][1].second == 1 && duong_di_0_5 == true)){
            tmp++;
        }
        if (tmp == 2){
            cout << 1 << "\n";
            for (int i = 1; i<=n+m-2; i++){
                cout << duong_di_0[i];
            }
            return 0;
        }
    }
    if (F[1][1].first < F[1][1].second){
        cout << F[1][1].first << "\n";
        for (int i = 1; i<=n+m-2; i++){
            cout << duong_di_2[i];
        }
    }
    else if (F[1][1].first > F[1][1].second){
        cout << F[1][1].second << "\n";
        for (int i = 1; i<=n+m-2; i++){
            cout << duong_di_5[i];
        }
    }
    else {
        cout << F[1][1].first << "\n";
        if (check == true){
            for (int i = 1; i<=n+m-2; i++){
                cout << duong_di_2[i];
            }
        }
        else 
            for (int i = 1; i<=n+m-2; i++){
                cout << duong_di_5[i];
            }
    }
 
 
    return 0;
}