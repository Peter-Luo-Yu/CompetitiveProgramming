#include<iostream>
#include<cmath>
using namespace std;

int main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x,y;
    cin >> x >> y;
    int temp = x;

    int i = 0;
    int sign = 1;

    int prev = x;

    int length = 0;
    if (x < y){
        while (x < y){
            prev = x;
            x = temp + sign*pow(2,i);
            length += abs(x - prev);
            
           // cout << x << " " << i << " "<< prev << endl;
            i++;
            sign = -sign;
        }
        length -= (x-y);
    }
    else{
        while (x > y){
            prev = x;
            x = temp + sign*pow(2,i);
            length += abs(x - prev);
            
          //  cout << x << " " << i << " "<< prev << endl;
            i++;
            sign = -sign;
        }
        length -= (y-x);
    }
    cout << length;



    return 0;
}