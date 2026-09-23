#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    vector<int> data (t);

    for (int i = 0; i < t; i++) {cin >> data[i];}

    for (int i = 0; i < data.size(); i++){
        if (data[i] <= 1399) {
            cout << "Division 4" << "\n";
        }
        if (data[i] >= 1400 && data[i] <= 1599) {
            cout << "Division 3" << "\n";
        }
        if (data[i] >= 1600 && data[i] <= 1899) {
            cout << "Division 2" << "\n";
        }
        if (data[i] >= 1900) {
            cout << "Division 1" << "\n";
        }
    }
    
    return 0;
}