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

    // since n = 6000 you can check every subsegment
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        int N = 6000 + 5;
        vector<vector<bool>> dp(N, vector<bool> (N));

        for (int i = 0; i < n; i++) {
            vector<bool> vis (n + 1);
            int Min = arr[i], Max = arr[i];

            for (int j = i; j < n; j++) {
                if (vis[arr[j]]) break;
                vis[arr[j]] = 1;

                Min = min(arr[j], Min);
                Max = max(arr[j], Max);

                //cout << Max << " " << Min << " " << j - i << endl;

                if (Max - Min == j - i) {
                    dp[Min][Max] = 1;
                }
            }
        }

        //print2d(dp);

        int res = 0;
        // check if each answer is possible
        for (int ans = 1; ans <= n / 2; ans++) {
            for (int j = 1; j + 2 * ans - 1 <= n; j++) {
                if (dp[j][j + ans - 1] && dp[j + ans][j + 2 * ans - 1]) {
                    res = max (res, ans);
                }
            }
        }

        cout << res << endl;

        //space;

    }



    return 0;
}
