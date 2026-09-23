#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        string a, b, s; cin >> a >> b >> s;

        vector<vector<int>> dp (a.size() + 1, vector<int> (b.size() + 1, 1e9));

        dp[0][0] = 0;
        for (int i = 0; i < a.size(); i++) {
            dp[i + 1][0] = dp[i][0] + (a[i] != s[i]); 
        }
        for (int j = 0; j < b.size(); j++) {
            dp[0][j + 1] = dp[0][j] + (b[j] != s[j]); 
        }

        //print2d(dp);

        for (int i = 1; i <= a.size(); i++) {
            for (int j = 1; j <= b.size(); j++) {

                // the offset, dp[i][j] is based on length, but the ith element is in pos i - 1;
                dp[i][j] = min (dp[i - 1][j] + (a[i - 1] != s[i + j - 1]),
                                dp[i][j - 1] + (b[j - 1] != s[i + j - 1]));
            }
        }

        //print2d(dp); 
        cout << dp[a.size()][b.size()] << endl; 
    }
    
    return 0;
}
