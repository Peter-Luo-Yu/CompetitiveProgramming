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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> arr = a;
        sort(arr.begin(), arr.end());
        int m = arr[arr.size()/2];

        //print(arr);

        // first set of dp tables
        vector<int> psmall(n+1), pbig(n+1);
        for (int i = 0; i < n; i++) {
            if (a[i] < m) {
                psmall[i+1] = psmall[i] + 1; 
                pbig[i+1] = pbig[i];
            }
            else if (a[i] > m) {
                psmall[i+1] = psmall[i];
                pbig[i+1] = pbig[i] + 1; 
            } else {
                psmall[i+1] = psmall[i];
                pbig[i+1] = pbig[i]; 
            }
        }

        //print(psmall); print(pbig);

        vector<int> dp(n + 1, -n);  // most amount of subarrays ending at j??
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j+=2) {
                int half = (j - i) / 2;
                int small = psmall[j] - psmall[i];
                int big = pbig[j] - pbig[i];

                if (small <= half && big <= half) {
                    dp[j] = max (dp[j], dp[i] + 1);
                }
            }
        }

        //print(dp);

        cout << dp[n] << endl;


        //space;
    }

    return 0;
}