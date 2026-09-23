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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<char> arr (n);
        vector<pair<int, int>> ranges;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] == 's') {        // to the right
                ranges.push_back({i, n - 1});
            } 
            else if (arr[i] == 'p') {
                ranges.push_back({0, i});
            }
        }

        //printP(ranges);

        bool failed = false;
        for (int i = 0; i < ranges.size(); i++) {
            
            for (int j = 0; j < ranges.size(); j++) {
                int l1 = ranges[i].first, r1 = ranges[i].second;
                int l2 = ranges[j].first, r2 = ranges[j].second;

                if (l2 <= l1 && r1 <= r2) {

                }
                else if (l1 <= l2 && r2 <= r1) {

                } else {
                    failed = true;
                }

            }
        }

        if (failed) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        //cout << "----------" << endl;
    }
    
    return 0;
}
