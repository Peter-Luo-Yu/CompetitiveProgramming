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
        int n, q; cin >> n >> q;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<int> pref0 (n + 1), pref1(n + 1);
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                pref0[i + 1] = pref0[i] + 1;
                pref1[i + 1] = pref1[i];
            } 
            else { // arr[i] == 1
                pref0[i + 1] = pref0[i];
                pref1[i + 1] = pref1[i] + 1;
            }   
        }

        //print(pref0); print(pref1);


        // dp[i] is the longest alt seq. ending at i
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                dp[i] = 1; 
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }

        //print(dp);

        for (int i = 0; i < q; i++) {
            int l, r; cin >> l >> r; l--, r--;

            int num0 = pref0[r + 1] - pref0[l];
            int num1 = pref1[r + 1] - pref1[l];

            //cout << num0 << " " << num1 << endl;

            int len = r - l + 1; // interval len
            
            int alt_len = dp[r]; // alternating len
            
            //cout << "len: " << len << " alternating: " << alt_len << endl;

            if (num0 % 3 != 0 || num1 % 3 != 0) {
                cout << -1 << endl;
            }
            else if (alt_len >= len) {
                cout << (num0 + num1) / 3 + 1 << endl;
            } else {
                cout << (num0 + num1) / 3 << endl;
            }


        }


        //space;
    }

    
    return 0;
}
