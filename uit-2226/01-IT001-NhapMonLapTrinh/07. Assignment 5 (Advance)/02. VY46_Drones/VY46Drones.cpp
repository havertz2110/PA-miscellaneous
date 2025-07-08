#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define fi first
#define se second
int main(){
    int n, x, y;
    cin >>n;
    vector<ii>drones(n);
    for(int i=0; i<n;i++){
        cin >>x>>y;
        drones[i].fi=max(abs(x),abs(y));
        drones[i].se=i+1;
    }
    sort(drones.begin(), drones.end());
    for(int i=0; i<n;i++)
        if(drones[i].fi<=i){
            cout <<-1;
            return 0;
        }
        for (auto d:drones)
        cout << d.se <<" ";
        return 0;
}
