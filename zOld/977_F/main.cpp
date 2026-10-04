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
    vector<int> arr (n); for (int i = 0; i < n; i++) cin >> arr[i];

    // according to solution: dp[a] = lis ending at element a
    map<int, int> dp;

    for (int i = 0; i < n; i++) {
        dp[arr[i]] = 1;
        dp[arr[i]] = max(dp[arr[i] - 1] + 1, dp[arr[i]]);
    }

    //printP(dp);

    int freq = -1;
    int val = -1;
    for (auto x : dp) {
        if (x.second > freq) {
            freq = x.second;
            val = x.first;
        }
    }

    //cout << val << " " << freq << endl;

    vector<int> ans;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == val) {
            ans.push_back(i);
            val--;
        }
    }

    //print(ans);
    
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;


    return 0;
}
