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

    int t; cin >> t;
    while (t--) {
        string s1, s2; cin >> s1 >> s2;
        vector<int> pref1(s1.size() + 1), pref2(s2.size() + 1);

        for (int i = 0; i < s1.size(); i++) {
            pref1[i + 1] = (pref1[i] + s1[i] - '0') % 10; 
        }
        for (int i = 0; i < s2.size(); i++) {
            pref2[i + 1] = (pref2[i] + s2[i] - '0') % 10; 
        }

        //print(pref1); print(pref2);

        if (pref1[pref1.size() - 1] != pref2[pref2.size() - 1]) {
            cout << -1 << endl;
            continue;
        }

        // LCS, dp[i][j] = len, i = first i elements of pref1, j = first j elements of pref2
        vector<vector<int>> dp (s1.size() + 1, vector<int> (s2.size() + 1));
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (pref1[i] == pref2[j]) {
                    dp[i][j] = max (dp[i][j], dp[i - 1][j - 1] + 1);
                }
                else {
                    dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }

        cout << dp[s1.size()][s2.size()] << endl;
    }


    return 0;
}
