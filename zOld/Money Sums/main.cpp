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

    int N = 1e5 + 5;
    vector<vector<int>> dp (N, vector<int> (n));

    // let dp[i][j] = 1 if sum of i using first j is possible
    
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    dp[arr[0]][0] = 1;

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < N; i++) {

            dp[i][j] = dp[i][j - 1];

            if (i - arr[j] >= 0) {
                if (dp[i - arr[j]][j - 1] == 1) {
                    dp[i][j] = 1;
                }
            }
        }
    }

    //print2d(dp);
    
    set<int> st;

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            if (dp[i][j] == 1) {
                st.insert(i);
            }
        }
    }

    cout << st.size() - 1 << endl;
    for (auto ele : st) {
        if (ele == 0) {
            continue;
        }
        cout << ele << " ";
    }

    return 0;
}
