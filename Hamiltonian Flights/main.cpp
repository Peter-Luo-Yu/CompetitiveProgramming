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

    int n, m; cin >> n >> m;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[b].push_back(a);
    }

    ll MOD = 1e9 + 7;
    // dp[i][j] = i is subset, ending at city j = number of routes
    vector<vector<int>> dp ((1 << 20), vector<int> (20));

    dp[1][0] = 1;

    for (int s = 2; s < (1 << n); s++) {
        // only consider subsets containing first city
        // why: because you have to start at city 1
        if ((s & (1 << 0)) == 0) continue;

        // only consider last city if it's the full subset
        // why: the problem asks that you visit each city exactly once 
        // => you have to visit everybody before you can finish at city n
        if ((s & (1 << (n - 1))) && (s != ((1 << n) - 1))) continue;

        for (int end = 0; end < n; end++) {
            // if the current subset doesn't contain the destination, skip
            if ((s & (1 << end)) == 0) continue;

            // this represents s / {end}
            int subtract = s - (1 << end);

            for (int start : adj[end]) {
                // remember s has to already contain the starting city
                // because otherwise you are adding to the wrong subset
                if (s & (1 << start)) {
                    dp[s][end] = (dp[s][end] + dp[subtract][start]) % MOD;
                }

            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
 

    return 0;
}
