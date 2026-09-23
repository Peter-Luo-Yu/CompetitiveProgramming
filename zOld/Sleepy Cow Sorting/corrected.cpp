#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void print(vector<int> order){
    for (int i = 0; i < order.size(); i++){
        cout << order[i] << " "; 
    }
    cout << "\n";
}


bool lined_up(vector<int> order){
    for (int i = 0; i < order.size() - 1; i++){
        if (order[i] > order[i+1]){
            return false;
        }
    }
    return true;
}

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n; cin >> n;
    vector<int> order (n); for (int i = 0; i < n; i++) {cin >> order[i];}

    int index; // tracks where the sorted part begins

    for (int i = order.size() - 1; i > 0; i--){
        if (order[i] < order[i-1]){
            index = i;
            break;
        }
    }

    int count = 0;

    while (!lined_up(order)){
        int cow = order[0];

        int target_location = -1;

        for (int i = index; i < order.size(); i++){
            if (cow < order[i]){
                target_location = i-1;
                break;
            }
        }
        if (target_location == -1) {target_location = order.size() - 1;}

        for (int i = 0; i < target_location; i++){      // shift everybody forward
            order[i] = order[i+1];
        }
        order[target_location] = cow;
        index--;                                        // the sorted part increases!
        count++;
        //print(order);
    }
    cout << count << endl;
}