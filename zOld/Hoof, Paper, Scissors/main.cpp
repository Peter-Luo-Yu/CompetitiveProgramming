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

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<char> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<vector<int>>> dp (n, vector<vector<int>> (3, vector<int> (k + 1)));
    
    if (arr[0] == 'H') {
        dp[0][0][0] = 1;
    } else if (arr[0] == 'P') {
        dp[0][1][0] = 1;
    } else {
        dp[0][2][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int cost = 0; cost <= k; cost++) {
            if (arr[i] == 'H') {
                // don't switch to beating H
                dp[i][0][cost] = max (dp[i][0][cost], dp[i - 1][0][cost] + 1);
                dp[i][1][cost] = max (dp[i][1][cost], dp[i - 1][1][cost]);
                dp[i][2][cost] = max (dp[i][2][cost], dp[i - 1][2][cost]);

                // we do switch to beating H
                if (cost - 1 >= 0) {
                    dp[i][0][cost] = max (dp[i][0][cost], dp[i - 1][1][cost - 1] + 1);
                    dp[i][0][cost] = max (dp[i][0][cost], dp[i - 1][2][cost - 1] + 1);
                }

            } else if (arr[i] == 'P') {
                // don't switch to beating P
                dp[i][0][cost] = max (dp[i][0][cost], dp[i - 1][0][cost]);
                dp[i][1][cost] = max (dp[i][1][cost], dp[i - 1][1][cost] + 1);
                dp[i][2][cost] = max (dp[i][2][cost], dp[i - 1][2][cost]);

                // we do switch to beating P
                if (cost - 1 >= 0) {
                    dp[i][1][cost] = max (dp[i][1][cost], dp[i - 1][0][cost - 1] + 1);
                    dp[i][1][cost] = max (dp[i][1][cost], dp[i - 1][2][cost - 1] + 1);
                }

            } else {
                // don't switch to beating S
                dp[i][0][cost] = max (dp[i][0][cost], dp[i - 1][0][cost]);
                dp[i][1][cost] = max (dp[i][1][cost], dp[i - 1][1][cost]);
                dp[i][2][cost] = max (dp[i][2][cost], dp[i - 1][2][cost] + 1);

                // we do switch to beating S
                if (cost - 1 >= 0) {
                    dp[i][2][cost] = max (dp[i][2][cost], dp[i - 1][0][cost - 1] + 1);
                    dp[i][2][cost] = max (dp[i][2][cost], dp[i - 1][1][cost - 1] + 1);
                }
            }
        }
    }


    int ans = 0;
    for (int c = 0; c <= k; c++) {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < 3; j++) {
                //cout << dp[i][j][c] << " ";
                ans = max (ans, dp[i][j][c]);
            }
            //cout << endl;
        }
        //space;
    }

    cout << ans << endl;

    return 0;
}
