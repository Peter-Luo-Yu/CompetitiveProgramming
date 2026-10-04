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

ll MOD = 1e9 + 7;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<ll>> dp (n, vector<ll> (m + 1));

    // dp[i][j] = number of ways using first i elements, such that the final value is j
    if (arr[0] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {

            if (arr[i] != 0 && arr[i] != j) continue;

            dp[i][j] = dp[i - 1][j];

            if (j - 1 >= 1) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            if (j + 1 <= m) {
                dp[i][j] += dp[i - 1][j + 1];
            }

            dp[i][j] %= MOD;

        }
    }

    //print2d(dp);

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n - 1][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
