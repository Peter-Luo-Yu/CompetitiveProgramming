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

        // dp[i] = cost killing everybody up to and including monster i,
        // currently j is 0 it's friend's turn, 1 if it's my turn
        vector<vector<int>> dp (n, vector<int> (2, 1e9));   

        if (arr[0] == 1) {
            dp[0][0] = 1;
        } else {
            dp[0][0] = 0;
        }

        if (n > 1) {
            if (arr[1] == 1) {
                dp[1][0] = dp[0][0] + 1;
            } else {
                dp[1][0] = dp[0][0];
            }
        }

        for (int i = 1; i < n; i++) {
            // I can either move forward 1 boss or 2 bosses
            
            if (i - 1 >= 0) {
                dp[i][1] = min (dp[i][1], dp[i - 1][0]);
            }
            if (i - 2 >= 0) {
                dp[i][1] = min (dp[i][1], dp[i - 2][0]);
            }

            // the friend can move forward 1 or 2.
            if (i - 1 >= 0) {
                dp[i][0] = min (dp[i][0], dp[i - 1][1] + (arr[i] == 1));
            }
            if (i - 2 >= 0) {
                dp[i][0] = min (dp[i][0], dp[i - 2][1] + (arr[i] == 1) + (arr[i - 1] == 1));
            }

        }

        //print2d(dp);

        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;

        //space;

    }


    return 0;
}
