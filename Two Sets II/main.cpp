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

    ll MOD = 1e9 + 7;
    ll n; cin >> n;
    
    if (n * (n + 1) % 4 != 0) {
        cout << 0 << endl;
        return 0;
    }

    ll sum = n * (n + 1) / 4;

    int N = 7 * 1e4;
    vector<vector<int>> dp (N, vector<int> (n));
    // num of ways we can make sum i with first j elements

    dp[0][0] = 1;
    
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < N; i++) {

            dp[i][j] += dp[i][j - 1];

            if (i - (j + 1) >= 0) {
               
                dp[i][j] += dp[i - (j + 1)][j - 1];
                
            }

            dp[i][j] %= MOD;
        }
    }
    
    //print2d(dp);

    //cout << "sum: " << sum << endl;

    // asks if you can make sum with all elements
    cout << dp[sum][n - 1] << endl;


    return 0;
}
