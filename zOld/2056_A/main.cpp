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

    while (t--) {
        int n, m; cin >> n >> m;

        if (n == 1) {
            cout << 4 * m << endl; 
            cin >> n >> m; continue;
        }

        vector<pair<int, int>> data (n); 

        for (int i = 0; i < n; i++) {cin >> data[i].first >> data[i].second;}

        int ans = 4 * m - data[0].first - data[0].second;

        for (int i = 0; i < n; i++) {
            ans += data[i].first + data[i].second;
        }
        for (int i = 1; i < n; i++) {
            ans += data[i].first + data[i].second;
        }

        cout << ans << endl;

    }
    
    return 0;
}
