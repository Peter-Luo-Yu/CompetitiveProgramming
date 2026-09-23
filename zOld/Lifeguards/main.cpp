#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main () {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int N; cin >> N;
    vector<vector<int>> lifeguard (N, vector<int> (2));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++){
            cin >> lifeguard[i][j];
        }
    }

    sort (lifeguard.begin(), lifeguard.end());  // lexographic sorting in N log N time!

    int max_time = 0;

    for (int i = 0; i < N; i++) {   // removing the ith lifeguard
    
        vector<vector<int>> data = lifeguard;
        data.erase(data.begin() + i);

        int current_time = data[0][0];
        int total_time = 0;

        for (int j = 0; j < N-2; j++){

            if (data[j+1][0] <= data[j][1]) {  // if starting time overlaps
                total_time += data[j+1][0] - current_time;
                current_time = data[j+1][0];
            }

            if (data[j+1][0] > data[j][1]) {  // if no overlap
                total_time += data[j][1] - data[j][0];
                current_time = data[j+1][0];
            }
        }

        if (data[data.size()-1][0] > current_time){    // no overlap
            total_time += (data[data.size()-1][1] - data[data.size()-1][0]);
        }
        if (data[data.size()-1][0] <= current_time){    // is overlapped
            total_time += (data[data.size()-1][1] - current_time);
        }

        max_time = max(max_time, total_time);

    }


    cout << max_time << "\n";
    
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++){
            cout << lifeguard[i][j] << " ";
        }
        cout << "\n";
    } */

    return 0;
}