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
        int n; cin >> n;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        ll mod = 998244353;

        vector<vector<ll>> dp (n + 1, vector<ll> (4));
        dp[0][0] = 1;

        // dp[i][j], first i elements, jth state, 
        
        for (int i = 0; i < n; i++) {
            for (int s = 0; s < 4; s++) {
                dp[i + 1][s] = (dp[i + 1][s] + dp[i][s]) % mod;
            }

            if (arr[i] == 1) {
                dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % mod;
            }
            if (arr[i] == 2) {
                dp[i + 1][2] = (dp[i + 1][2] + dp[i][1] + dp[i][2]) % mod;
            }
            if (arr[i] == 3) {
                dp[i + 1][3] = (dp[i + 1][3] + dp[i][2]) % mod;
            }
        }

        cout << dp[n][3] << endl;
    }


    return 0;
}
