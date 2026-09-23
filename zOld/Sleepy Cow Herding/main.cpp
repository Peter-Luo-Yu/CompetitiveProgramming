#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int a,b,c; cin >> a >> b >> c;

    int diff1 = b - a, diff2 = c - b;

    int min = 0, max = 0; 

    if (diff1 == 1 && diff2 > 0){
        //cout << "case1" << endl;
        max = diff2 - 1;
        min = diff2 - 1;
    }
    else if (diff1 > 0 && diff2 == 1){
        //cout << "case2" << endl;
        max = diff1 - 1;
        min = diff1 - 1;
    }
    else if (diff1 > diff2 && diff1 != 0 && diff2 != 0) {
        //cout << "case3" << endl;
        max = diff1-1;
        min = diff2-1;
    }
    else if (diff2 > diff1 && diff1 != 0 && diff2 != 0){
        //cout << "case4" << endl;
        max = diff2-1;
        min = diff1-1;
    } else if (diff1 == 0 && diff2 == 0) {
        //cout << "case5" << endl;
        max = diff1-1;
        min = diff1-1;
    }

    if (min > 1){
        min = 2;
    }

    //cout << diff1 << " " << diff2 << endl;

    cout << min << endl;
    cout << max << endl;
    
    return 0;
}