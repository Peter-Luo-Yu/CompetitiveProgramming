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

    int n, x; cin >> n >> x;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // dp[i] is min number of coins to achieve sum of i;
    int N = 1e6 + 5;
    vector<int> dp (N, 1e9);
    
    for (int i = 0; i < n; i++) {
        dp[arr[i]] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < n; j++) {
            if (i - arr[j] >= 0) {
                dp[i] = min (dp[i], dp[i - arr[j]] + 1);
            }
        }
    }

    //print(dp);

    if (dp[x] == 1e9) {
        cout << -1 << endl;
    }
    else {
        cout << dp[x] << endl;
    }
    
    return 0;
}
