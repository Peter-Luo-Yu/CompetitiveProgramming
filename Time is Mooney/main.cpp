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

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    int n, m, c; cin >> n >> m >> c;

    vector<ll> money (n);
    for (int i = 0; i < n; i++) cin >> money[i];
    
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
    }

    //printG(adj);

    // dp[i][j], pos is at i, j days later = moonies
    vector<vector<ll>> dp (n, vector<ll> (1005, -1));
    dp[0][0] = 0;

    for (int days = 1; days < 1005; days++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {

                int cur = i;
                int next = adj[i][j];

                if (dp[cur][days - 1] != -1) {
                    dp[next][days] = max (dp[cur][days - 1] + money[next],dp[next][days]);
                }

            }
        }
    }

    //print2d(dp);

    ll ans = 0;
    for (int days = 1; days < 1005; days++) {
        ll penalty = c * days * days;

        for (int i = 0; i < n; i++) {
            if (dp[i][days] != -1 && i == 0) {
                ans = max (ans, dp[i][days] - penalty);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
