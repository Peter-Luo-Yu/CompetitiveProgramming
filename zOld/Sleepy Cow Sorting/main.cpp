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

    //print(order);
    //for (int i = 0; i < n; i++) {cout << order[i] << " ";}
    int count = 0;

    if (n == 1){
        cout << 0 << endl;
        return 0;
    }
    if (n == 2){
        if (lined_up(order)){
            cout << 0 << endl;
            return 0;
        } else {
            cout << 1 << endl;
            return 0;
        }
    }

    while (!lined_up(order)){
        int cow = order[0];

        int index = -1;
        int min_diff = n + 1;

        if (cow == n){
            index = order.size() - 1;
        } else {
            for (int i = 2; i < order.size(); i++){
                if (order[i] < cow){
                    continue;
                }
                if (order[i] - cow < min_diff){
                    bool works = false;
                    for (int j = 0; j < i; j++){
                        if (order[j] + 1 != order[j+1]){
                            works = true;
                        }
                    }

                    if (works){
                        min_diff = order[i] - cow;
                        index = i - 1;
                    }
                    if (cow != index){
                        index = -1;
                    }
                    //cout << min_diff << " " << index << endl;
                }
            }
            if (index == -1){   // if everything doesn't work, default to end
                index = order.size()-1;
            }
        }

        //cout << "chosen index: " << index << endl; 

        for (int i = 0; i < index; i++){  // inserting at the index before the index
            order[i] = order[i+1];
        }
        order[index] = cow;

        count++;

        print(order);

    }

    cout << count << endl;

    return 0;
}