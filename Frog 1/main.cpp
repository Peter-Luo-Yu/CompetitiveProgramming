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

    int n; cin >> n;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // dp[i] = min cost to get to i
    vector<int> dp (n, 1e9);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        if (i - 2 >= 0) {
            dp[i] = min (dp[i], dp[i - 2] + abs(arr[i] - arr[i - 2]));
        }
        dp[i] = min (dp[i], dp[i - 1] + abs(arr[i] - arr[i - 1]));
    }

    //print(dp);

    cout << dp[n - 1] << endl;


    return 0;
}
