#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void print (vector<int> data){
    for (int x : data){
        cout << x << " ";
    }cout << endl; 
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;

        int Max = -1;
        vector<int> odd, even;

        for (int i = 0; i < n; i++){
            int val; cin >> val;

            Max = max(Max, val);
            if (val % 2 == 0){
                even.push_back(val);
            } else {
                odd.push_back(val);
            }
        }
        
        sort (odd.begin(), odd.end());
        sort (even.begin(), even.end());

        int ans = Max;

        if (Max % 2 == 0){
            for (int i = 0; i < even.size(); i++){
                if (even[i] == Max){
                    even.erase(even.begin() + i);
                    break;
                }
            }
        } else {
            for (int i = 0; i < odd.size(); i++){
                if (odd[i] == Max){
                    odd.erase(odd.begin() + i);
                    break;
                }
            }
        }


        cout << "Max: " << Max << endl;
        cout << "Odd: "; print (odd);
        cout << "Even: "; print (even);


        if (Max % 2 == 0){  // can add one odd to an even
            ans += odd[odd.size() - 1];
            for (int i = 0; i < even.size(); i++){
                ans += even[i];
            }
        } else {            // already odds can't get any evens
            for (int i = 0; i < even.size(); i++){
                ans += even[i];
            }
        }

        cout << ans << endl;
    }
    
    
    return 0;
}