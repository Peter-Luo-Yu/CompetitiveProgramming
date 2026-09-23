#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--){
        int k, n; cin >> k >> n;

        map <int, int> mp;                  // the map auto sorts -> nice :)
        vector<int> order;
        for (int i = 0; i < k; i++){
            int val; cin >> val;
            mp[val]++;
        }

        // the key to the problem is looping through (complete search) every possible
        // type of card and include it to maximize the number of cards.
        // This is done by having both the map to track the number of cards of each type
        // and a normal array to track the pile types. 

        for (auto i : mp){
            order.push_back(i.first);
            //cout << i.first << " " << i.second << endl;
        }

        //print(order);

        int Max = 0; 
        // looping through the map, i is the first card

        
        for (int i = 0; i < order.size(); i++){
            //cout << i -> first << " " << i -> second << endl;
            int j = i + 1; 
            int used = 0;
            int count = 0;

            count += mp[order[i]]; used++;
            
            //cout << "i: " << i << " type: " << order[i] << " amount: " << mp[order[i]] << " used: " << used << " count: " <<  count << endl;

            while (j < order.size() && order[j] - order[j-1] == 1 && used < n){

                count += mp[order[j]];
                used++;
                //cout << "j: " << j << " type: "<< order[j] << " amount: " << mp[order[j]]<< " used: " << used << " count: " <<  count << endl;

                j++;


            }

            Max = max (Max, count);

        }

        cout <<  Max << endl;
    }

    return 0;
}