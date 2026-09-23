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

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) cin >> l[i];
        for (int i = 0; i < n; i++) cin >> r[i];

        vector<pair<int, int>> s(n);
        for (int i = 0; i < n; i++) {
            s[i] = {l[i] + r[i], i};
        }
        sort (s.begin(), s.end());
        
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {l[s[i].second], r[s[i].second]};
        }

        printP(arr);

        ll ans = 0;

        for (int i = n - 1; i > n - k; i--) {
            ans += arr[i].first;
            ans += arr[i].second;

            cout << "add: " << arr[i].first << " " << arr[i].second << " sum: " << ans << endl;
        }

        

        for (int i = n - k; i >= 0; i--) {
            ans += max (arr[i].first, arr[i].second);

            cout << "add: " <<max (arr[i].first, arr[i].second) << " sum: " << ans << endl;
        }

        cout << ans + 1 << endl;
        
        space;

    }


    return 0;
}
