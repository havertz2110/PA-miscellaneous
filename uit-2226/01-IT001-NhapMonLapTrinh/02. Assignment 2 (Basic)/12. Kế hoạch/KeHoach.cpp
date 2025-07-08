/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int temperature;
    cout<<"What is the outdoor temperature? ";
    cin>>temperature;
    cout<<endl;

//###INSERT CODE HERE -

    return 0;
}
// quăng code dưới đây dô chỗ insert code nhe
if ( temperature >= 33) {
    cout << "What is your plan today?" << endl;
    cout << "Good day for swimming" << endl;
   }
   else if ( temperature >= 24 && temperature <33) {
    cout << "What is your plan today?" << endl;
    cout << "Good day for golfing" << endl;
   }
   else if ( temperature >=10 && temperature <24 ) {
    cout << "What is your plan today?" << endl;
    cout << "Good day to play tennis" << endl;
   }
   else if ( temperature < 10) {
    cout << "What is your plan today?" << endl;
    cout << "Go to bed" << endl;
   }
