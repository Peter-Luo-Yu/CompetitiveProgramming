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
        int n, m; cin >> n >> m;

        vector<vector<ll>> arr (n, vector<ll> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        vector<pair<ll, ll>> summary;
        for (int i = 0; i < n; i++) {
            ll sum = 0;
            for (int j = 0; j < m; j++) {
                sum += arr[i][j];
            }
            summary.push_back({sum, i});
        }

        sort (summary.begin(), summary.end());
        reverse(summary.begin(), summary.end());

        vector<int> a;
        for (int i = 0; i < n; i++) {
            int idx = summary[i].second;

            for (int j = 0; j < m; j++) {
                a.push_back(arr[idx][j]);
            }
        }

        //print(a);

        ll ans = 0, multiplier = a.size();
        for (int i = 0; i < a.size(); i++) {
            ans += a[i] * multiplier;
            multiplier--;
        }

        cout << ans << endl;

    }

    
    return 0;
}
