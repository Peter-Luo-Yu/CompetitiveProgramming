#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        vector<int> tracker (n);
        int Min = 1e9;
        for (int i = n - 1; i >= 0; i--) {
            Min = min (Min, arr[i]);
            tracker[i] = Min;
        }
        
        cout << "minimums: "; print(tracker);

        vector<int> temp;
        vector<int> fixed;
        bool stopped = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] == tracker[i]) {
                fixed.push_back(arr[i]);
            } else {
                stopped = true;
                temp.push_back(arr[i] + 1);
            }
        }

        sort (temp.begin(), temp.end());
        
        for (auto x : temp) {
            fixed.push_back(x);
        }
        print(fixed);
    }


    
    return 0;
}
