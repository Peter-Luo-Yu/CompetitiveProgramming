#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n; cin >> n; 
    vector<int> cows(n); for (int i = 0; i < n; i++) {cin >> cows[i];} // cows are really hays
    sort (cows.begin(), cows.end());

    for (int i = 0; i < n; i++){
        cout << cows[i] << " ";
    }
    cout << "\n";
    
    for (int i = 0; i < n; i++) {
        vector<int> left;
        vector<int> right;
        
        for (int j = 0; j < n; j++){            // remember that i is omitted
            if (j < i){
                left.push_back(cows[j]);
            }
            if (j > i){
                right.push_back(cows[j]);
            }
        }

        vector<int> rtracker (right.size());
        vector<int> ltracker (left.size());

        tracker[i] = 1;
        


        if (abs(right[0] - cows[i]) <= 1){                  // check if r[0] is hit, if hit -> r = 2
            rtracker[0] = 2;
            for (int j = 0; j < right.size() - 1; j++){
                if (abs(right[j] - right[j+1]) <= rtracker[j]){
                    rtracker[j+1] = rtracker[j] + 1;
                }

            }
        }




        if (abs(left[0] - cows[i]) <= 1){
            for (int j = 0; j < left.size(); j++){
            
            }
        }




    }
        /*
        cout << "left: ";
        for (int j = 0; j < left.size(); j++){
            cout << left[j] << " ";
        }
        cout << "\n";
        cout << "right: ";
        for (int j = 0; j < right.size(); j++){
            cout << right[j] << " ";
        }
        cout << "\n"; */
    
    
    
    return 0;
}