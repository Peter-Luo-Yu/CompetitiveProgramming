#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> process (n, vector<int>(2));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            cin >> process[i][j];
        }
    }

    sort (process.begin(), process.end());

    int cur_time = process[0][0];       

    for (int i = 0; i < n; i++){
        
        if (process[i][0] <= cur_time){              // process has already arrived
            cur_time += process[i][1];
        }
        else{
            cur_time = process[i][0];
            cur_time += process[i][1];
        }
        
    }


    cout << cur_time << "\n";



    /*
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            cout << process[i][j] << " ";
        }
        cout << "\n";
    }*/

    return 0;
}