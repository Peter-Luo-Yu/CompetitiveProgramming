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

    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // just best score at cow i;
    vector<int> dp (n);

    for (int i = 0; i < n; i++) {
        int cur = arr[i];

        // you only look back k spots
        for (int j = i; j >= max(0, i - k + 1); j--) {
            cur = max (cur, arr[j]);

            if (j > 0) {
                dp[i] = max(dp[i], dp[j - 1] + cur * (i - j + 1));
            } else {
                dp[i] = max(dp[i], cur * (i - j + 1));
            }
        }
    }

    //print(dp);

    cout << dp[n - 1] << endl;

    return 0;
}
