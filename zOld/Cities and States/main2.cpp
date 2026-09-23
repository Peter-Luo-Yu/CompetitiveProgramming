#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {

    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int n; cin >> n;
    map<string, string> data_1; // city -> state
    map<string, string> data_2; // state -> city

    int count = 0;

    for (int i = 0; i < n; i++){
        string city, state;
        cin >> city >> state;           // our current city and state

        data_1[city] = state;       // STORES TWO COPIES    
        data_2[state] = city;
        //cout << city << " " << state << endl;
    }


        // goal is to have the final city = ini state, and 
        // final state = ini city, but not state = state
    for (auto x : data_1){
        string city = x.first.substr(0,2);      // flint -> FL
        string state = x.second.substr(0,2);    // michigan -> MI
 
        cout << city << " " << state << endl; 

        if (data_2.count(city) == 0){     // first check if the state even exists
            cout << "skipped: " << city << endl;
            continue;
        }

        string final_state = city;        // FL is now the state 
        string final_city = data_2[city].substr(0,2); // search for the final city: MI ami

        cout << final_city << " " << final_state << endl;

        if (final_city == state && state != final_state){
            count++;
            cout << "COUNTED" << endl;
            
        } else {
            cout << "NOT COUNTED" << endl;
        }
    }

    cout << count/2 << endl;

    return 0;
}