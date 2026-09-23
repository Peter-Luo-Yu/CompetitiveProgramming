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
        int n; cin >> n;

        vector<int> arr (n + 1);

        for (int i = 0; i < n; i++) cin >> arr[i + 1];

        //print(arr);

        vector<int> dp (n + 1); // dp[i] is number of combos assuming i is honest.

        dp[0] = 1;  // there is 1 way to arrange 0 people

        if (arr[1] == 0) dp[1] = 1; // first person is honest
        if (arr[1] != 0) dp[1] = 0;

        int MOD = 998244353;

        for (int i = 2; i <= n; i++) {
            
            // if i - 1 is honest -> a[i - 1] = a[i]
            if (arr[i] == arr[i - 1]) {
                dp[i] = (dp[i] + dp[i - 1]) % MOD;
            }

            // if i - 1 is liar. then i - 2 is honest. 
            if (i >= 2 && arr[i] == arr[i - 2] + 1) {
                dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
        }

        //print(dp);

        ll ans =  (dp[dp.size() - 1] + dp[dp.size() - 2]) % MOD;

        cout << ans << endl;

        //space;
 
    }

    
    return 0;
}
