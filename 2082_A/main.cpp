#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "---------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        int r = 0, c = 0;

        vector<vector<int>> arr (n, vector<int> (m));
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                arr[i][j] = s[j] - '0';
            }
        }

        //print2d(arr);

        // because the result is either 0 or 1, 
        // everytime you make a change you 
        // can affect two col/rows at once

        for (int i = 0; i < n; i++) {
            int val = 0;

            for (int j = 0; j < m; j++) {
                val ^= arr[i][j];
            }

            if (val == 1) {
                r++;
            }
        }

        for (int j = 0; j < m; j++) {
            int val = 0;

            for (int i = 0; i < n; i++) {
                val ^= arr[i][j];
            }

            if (val == 1) {
                c++;
            }
        }

        cout << max (r, c) << endl;
    }


    return 0;
}
