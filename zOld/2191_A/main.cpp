#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        vector<pair<int, int>> c1;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                c1.push_back({arr[i], 0});
            }   
            else {
                c1.push_back({arr[i], 1});
            }   
        }

        sort (c1.begin(), c1.end());

        bool failed = false;

        for (int i = 0; i < n - 1; i++) {
            if (c1[i].second == c1[i+1].second) {
                failed = true;
            }
        }

        if (failed) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    

    return 0;
}