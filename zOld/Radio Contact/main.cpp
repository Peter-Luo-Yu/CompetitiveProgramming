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

    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<pair<int, int>> f(n + 1), b(m + 1);

    cin >> f[0].first >> f[0].second >> b[0].first >> b[0].second;

    string s1; cin >> s1;
    for (int i = 1; i <= n; i++) {
        if (s1[i - 1] == 'N') {
            f[i].first = f[i - 1].first;
            f[i].second = f[i - 1].second + 1;
        }
        if (s1[i - 1] == 'E') {
            f[i].first = f[i - 1].first + 1;
            f[i].second = f[i - 1].second;
        }
        if (s1[i - 1] == 'S') {
            f[i].first = f[i - 1].first;
            f[i].second = f[i - 1].second - 1;
        }
        if (s1[i - 1] == 'W') {
            f[i].first = f[i - 1].first - 1;
            f[i].second = f[i - 1].second;
        }
    }
    string s2; cin >> s2;
    for (int i = 1; i <= m; i++) {
        if (s2[i - 1] == 'N') {
            b[i].first = b[i - 1].first;
            b[i].second = b[i - 1].second + 1;
        }
        if (s2[i - 1] == 'E') {
            b[i].first = b[i - 1].first + 1;
            b[i].second = b[i - 1].second;
        }
        if (s2[i - 1] == 'S') {
            b[i].first = b[i - 1].first;
            b[i].second = b[i - 1].second - 1;
        }
        if (s2[i - 1] == 'W') {
            b[i].first = b[i - 1].first - 1;
            b[i].second = b[i - 1].second;
        }
    }

    //printP(f); printP(b);

    vector<vector<ll>> dp (n + 1, vector<ll> (m + 1, 1e18));

    // let dp[i][j] be min cost after farmer has walked i steps and bessie walked j steps

    dp[0][0] = 0;
    //cout << "initial cost; " << dp[0][0] << endl;
    
    
    // only farmer walks
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min (dp[i - 1][0] + dist(f[i], b[0]), dp[i][0]);
    }
    // only bessie walks
    for (int j = 1; j <= n; j++) {
        dp[0][j] = min (dp[0][j - 1] + dist(f[0], b[j]), dp[0][j]);
    }
    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            // say only farmer moves
            dp[i][j] = min (dp[i - 1][j] + dist(f[i], b[j]), dp[i][j]);

            // only bessie moves
            dp[i][j] = min (dp[i][j - 1] + dist(f[i], b[j]), dp[i][j]);
        
            // both move
            dp[i][j] = min (dp[i - 1][j - 1] + dist(f[i], b[j]), dp[i][j]);
            
        }
    }

    //print2d(dp);

    cout << dp[n][m] << endl;

    return 0;
}
