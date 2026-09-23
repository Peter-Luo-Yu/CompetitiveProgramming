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

ll dist (pair<int, int> a, pair<int, int> b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<pair<ll, ll>> h(n), g(m);

    for (int i = 0; i < n; i++) {
        cin >> h[i].first >> h[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> g[i].first >> g[i].second;
    }

    // cost after visiting first i holstein and first j guernseys, given we are at a h or g
    vector<vector<vector<ll>>> dp (n + 1, vector<vector<ll>> (m + 1, vector<ll> (2, 1e18)));
    dp[1][0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {

            if (i - 1 >= 0) { // going to visit a holstein, but the final cow visited previously could be either holstein or guernsey

                dp[i][j][0] = min (dp[i - 1][j][0] + dist(h[i - 2], h[i - 1]), dp[i][j][0]);

                if (j - 1 >= 0) { 
                    dp[i][j][0] = min (dp[i - 1][j][1] + dist(g[j - 1], h[i - 1]), dp[i][j][0]);
                }
            }
            if (j - 1 >= 0) { // going to visit a guernsey

                dp[i][j][1] = min (dp[i][j - 1][1] + dist(g[j - 2], g[j - 1]), dp[i][j][1]);

                if (i - 1 >= 0) { 
                    dp[i][j][1] = min (dp[i][j - 1][0] + dist(g[j - 1], h[i - 1]), dp[i][j][1]);
                }
                
            }
        }
    }

    cout << dp[n][m][0] << endl;

    return 0;
}
