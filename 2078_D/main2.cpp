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

        vector<pair<char, ll>> l(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i].first >> l[i].second;
            cin >> r[i].first >> r[i].second;
        }

        vector<vector<ll>> dp (n + 1, vector<ll> (2));

        // backwards DP: if the person started right before gate[i], 
        // how many times would they get multiplied

        dp[n][0] = 1;
        dp[n][1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            ll best = max(dp[i + 1][0], dp[i + 1][1]);

            if (l[i].first == 'x') {
                dp[i][0] = dp[i + 1][0] + (l[i].second - 1) * best;
            } else {
                dp[i][0] = dp[i + 1][0];
            }

            if (r[i].first == 'x') {
                dp[i][1] = dp[i + 1][1] + (r[i].second - 1) * best;
            } else {
                dp[i][1] = dp[i + 1][1];
            }
        }

        //print2d(dp);

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            ll best = max (dp[i + 1][0], dp[i + 1][1]);
            ll sm = 0;

            if (l[i].first == '+') {
                sm += l[i].second;
            } 
            if (r[i].first == '+') {
                sm += r[i].second;
            }
            ans += sm * best;
        }

        ans += (dp[0][0] + dp[0][1]);

        cout << ans << endl;

        //space;
    }


    return 0;
}
