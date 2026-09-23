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
        int n; cin >> n;

        vector<ll> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<ll> pref (n + 1), suff (n + 1);
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                pref[i + 1] = pref[i] + arr[i];
            } else {
                pref[i + 1] = pref[i];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] < 0) {
                suff[i] = suff[i + 1] - arr[i];
            } else {
                suff[i] = suff[i + 1];
            }
        }

        //print(pref); print(suff);

        ll ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = max (ans, pref[i] + suff[i]);
        }

        cout << ans << endl;
    }
    
    return 0;
}
