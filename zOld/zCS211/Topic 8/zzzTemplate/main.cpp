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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> price (n);
    vector<int> prefix (n);
    for (int i = 0; i < n; i++) {cin >> price[i];}
    for (int i = 1; i < n; i++) {int val; cin >> val; prefix[i] = prefix[i - 1] + val;}
    prefix.push_back(1e9);

    int d, m; cin >> d >> m;

    vector<int> arr (2 * m);
    for (int i = 0; i < 2*m; i++) {cin >> arr[i];}
    arr.push_back(d);

    // cost pref array
    vector<int> costs (1e6 + 5);
    int temp = 0;
    for (int i = 1; i <= 1e6; i++) {
        if (i <= prefix[temp + 1]) {
            costs[i] = costs[i - 1] + price[temp];
        } else {
            temp++;
            costs[i] = costs[i - 1] + price[temp];
        }
    }

    print(price); print(prefix); print(arr); print(costs); space

    // dp[i] = cost to get to time -> arr[i - 1]
    vector<int> dp (arr.size() + 1, 1e9);
    dp[0] = 0;
    
    for (int i = 1; i <= arr.size(); i+=2) {
        
        int curT = arr[i - 1];

        // j is point where you reset
        for (int j = 1; j < i; j+= 2) {
            cout << "i: " << i << " j: " << j << endl;

            int prevT = 0;
            if (j != 1) {
                prevT = arr[j];
            }


            int cost = costs[curT] - costs[prevT];

            cout << "curT: " << curT << " prevT: " << prevT << " cost[cur]: " << costs[curT] << " cost[prev]: " << costs[prevT]  << " dp[j] " << dp[j] << " dp[i]: " << dp[i] << endl;
            
            dp[i] = min(dp[j - 1] + cost, dp[i]);
            
            cout << "final: " << dp[i] << endl;
            space
        }
    }

    print(dp);

    return 0;
}
