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

    string s1, s2; cin >> s1 >> s2;

    vector<vector<int>> dp (s1.size() + 1, vector<int> (s2.size() + 1, 1e9));

    // correct: dp[i][j] = cost to convert first i letters into first j letters

    dp[0][0] = 0;
    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i - 1 >= 0) {
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
            }
            if (j - 1 >= 0) {
                dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
            }

            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] = min(dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]), dp[i][j]);
            }
        }
    }

    //print2d(dp);
    
    cout << dp[s1.size()][s2.size()] << endl;


    return 0;
}
