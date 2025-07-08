#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5;

int jury[N] = {0, 5, 5, 5, 1}, out[N], cnt;
bool ok = 0;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll h){
    return l + rd() * 1LL * rd() % (h - l + 1);
}

void random_secret(){
    for(int i = 1; i <= 4; ++i){
        jury[i] = ((1 * rd()) % 6) + 1;
    }
}

void guess(){
    for(int i = 1; i <= 4; ++i){
        cin >> out[i];
    }
}

pair<int, int> check(){
    int b = 0, w = 0;

    for(int i = 1; i <= 4; ++i){
        if(out[i] == jury[i]){
            ++b;
            out[i] *= -1;
            jury[i] *= -1;
        }
    }


    for(int i = 1; i <= 4; ++i){
        if(jury[i] < 0) {jury[i] *= -1;continue;}
        for(int j = 1; j <= 4; ++j){
            if(out[j] == jury[i]){
                ++w;
                out[j] *= -1;
                jury[i] *= -1;
                break;
            }
        }
    }
    for(int i = 1; i <=4; ++i){
        if(out[i] < 0) out[i] *= -1;
        if(jury[i] < 0) jury[i] *= -1;
    }
    return make_pair(b, w);
}

signed main(){


    while(!ok){
        guess();
        ++cnt;
        auto res = check();
        if(res == make_pair(4, 0)) ok = 1;
        cout << res.first << "B " << res.second << "W \n";
    }
    cout << "You won in " << cnt << " guesses\n";
}

