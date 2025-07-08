#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int d, m, y;
   cin >> d >> m >> y;



    if ( d< 1 || d > 31 || m < 1 || m > 12 ){
        cout << "ERROR";
        return 0;
    }


    if ( m ==2 ){
        if ( d > 29){  cout << "ERROR";
        return 0;
        }
        else if(d==29) { // neu ngay la 29
            if((y%4==0&&y%100!=0)||(y%400==0) ) { // neu nam nhuan thi len thang 3
                cout<<1<<"/"<<m+1<<"/"<<y;
                return 0;
            }
            else {
                cout<<"ERROR"; // neu khong phai nam nhuan thi sai
                return 0;
            }
        }
        else if(d == 28) { // neu ngay la 28
            if((y%4==0&&y%100!=0)||(y%400==0) ) {  // neu nam nhuan thi ngay tang len 1
                cout <<d+1<<"/"<<m<<"/"<<y;
                return 0;
            }
            else{
                cout <<1<<"/"<< m+1<< "/"<<y; // neu khong phai nam nhuan thi len thang 3
                return 0;
            }
        } else{
            cout <<d+1<<"/"<<m<<"/"<<y;
                return 0;
        }
    }


    if ( m == 1 || m == 3 || m==5 ||m== 7||m==8|| m== 10){
        if (d ==31){
            cout << 1<<"/"<< m+1<<"/"<< y;

        }
        else{
            cout<< d+1<< "/"<< m<<"/"<<y;

        }
    }


    if ( m == 4 ||m==6||m== 9||m== 11){
        if ( d==30){
            cout << 1<<"/"<< m+1<<"/"<<y;
            return 0;
        }
        else if  ( d ==31){
            cout << "ERROR";
            return 0;
        }
       else{
            cout << d+1<<"/"<<m<<"/"<<y;
            return 0;
       }
    }



     if (m==12){
        if ( d == 31){
            cout << 1<<"/"<<1<<"/"<<y+1;
            return 0;
        }
       else {
            cout << d+1<<"/"<<m<<"/"<<y;
            return 0;
       }
    }
}
