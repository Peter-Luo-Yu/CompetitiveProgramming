#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t-- ){
        int n, k; cin >> n >> k;

        // you get k free single changes, each time you can delete all mins
        vector<int> arr (n);
        
        map<int, int> mp;
        vector<pair<int, int>> freq;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            
            mp[arr[i]]++;
        }

        //printP(mp);
        
        for (auto x : mp) {
            freq.push_back({x.second, x.first});
        }

        sort (freq.begin(), freq.end());

        //printP(freq);

        int idx = 0;
        while (k > 0) {
            int sub = min(freq[idx].first, k);

            freq[idx].first -= sub; k -= sub;
            freq[freq.size() - 1].first += sub;

            if (freq[idx].first == 0) {
                idx++;
            }
        }

        //space;
        //printP(freq);
       
        int ans = 0;

        for (int i = 0; i < freq.size(); i++) {
            if (freq[i].first != 0) {
                ans++;
            }
        }

        cout << ans << endl; 
    }
    
    return 0;
}
