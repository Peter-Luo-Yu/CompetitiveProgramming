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

    int n, c; cin >> n >> c;

    int num_c = 0;
    int best_sub = 0;

    vector<int> dp (5e5 + 5);
    // very special dp, it tracks the frequency of x

    for (int i = 0; i < n; i++) {
        int val; cin >> val;

        if (val == c) {
            num_c++;
        }
        else {
            dp[val] = max (dp[val], num_c) + 1;
        }

        best_sub = max (best_sub, dp[val] - num_c); 
    }

    cout << num_c + best_sub << endl;


    return 0;
}
