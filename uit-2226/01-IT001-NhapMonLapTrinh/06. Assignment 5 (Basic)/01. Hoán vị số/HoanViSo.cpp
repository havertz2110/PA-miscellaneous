#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    stack<string> st;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    do{
        st.push(s);
    }while(next_permutation(s.begin(),s.end()));
    while(!st.empty()){
        cout<<st.top()<<'\n';
        st.pop();
    }
}
