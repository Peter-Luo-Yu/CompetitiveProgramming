#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<pair<ld, ld>> arr (n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first >> arr[i].second;
            arr[i].second /= 100;
        }

        vector<vector<ld>> dp (151, vector<ld> (n + 1));

        //printP(arr); space

        dp[0][0] = 1;
        for (int j = 1; j <= n; j++) {
            for (int i = 0; i <= 150; i++) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);

                if (i >= arr[j].first) {
                    dp[i][j] = max (dp[i][j], dp[i - arr[j].first][j - 1] * arr[j].second);
                }
                
            }
        }

        //print2d(dp);

        ld ans = 0;

        for (int j = 1; j <= n; j++) {
            for (int i = 76; i <= 150; i++) {
                ans = max (ans, dp[i][j]);
            }
        }
        
        cout << fixed << setprecision(6) << ans * 100 << endl;
    }
    
    return 0;
}
