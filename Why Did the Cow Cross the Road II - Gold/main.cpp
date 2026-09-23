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

    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);

    int n; cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<vector<int>> dp (n + 1, vector<int> (n + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i - 1 >= 0) {
                dp[i][j] = max (dp[i - 1][j], dp[i][j]);
            }
            if (j - 1 >= 0) {
                dp[i][j] = max (dp[i][j - 1], dp[i][j]);
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] = max (dp[i - 1][j - 1] + (abs(a[i - 1] - b[j - 1]) <= 4), dp[i][j]);
            }
        }
    }

    //print2d(dp);

    cout << dp[n][n] << endl;

    return 0;
}
