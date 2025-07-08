#include <iostream>

using namespace std;

int main()
{
    string a, b, str;
    cin >> a >> b;
    while (a.size() + str.size() < b.size()) str += "0";
    str = str +a;
    if (a.size() !=b.size())
    {
        cout << b.size();
        return 0;
    }
    for ( int i = 0; i < b.size(); i++ )
        if (str[i] !=b[i])
    {
        cout << b.size() - i;
        return 0;
    }
cout << 0;
}
