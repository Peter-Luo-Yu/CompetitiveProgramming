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
        int n, k; cin >> n >> k;

        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) cin >> l[i];
        for (int i = 0; i < n; i++) cin >> r[i];

        ll ans = 0;

        vector<int> leftover;

        for (int i = 0; i < n; i++) {
            if (l[i] > r[i]) {
                ans += l[i];
                leftover.push_back(r[i]);
            } else {
                ans += r[i];
                leftover.push_back(l[i]);
            }
        }

        sort (leftover.begin(), leftover.end());

        for (int i = n - 1; i > n - k; i--) {
            ans += leftover[i];
        }
        
        ans += 1;

        cout << ans << endl;
    }


    return 0;
}
