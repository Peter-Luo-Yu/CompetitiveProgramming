#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    sort (arr.begin(), arr.end());
    //print(arr);

    ll ans = 0;
    while (m--) {
        int val; cin >> val;

        int pos = lower_bound(arr.begin(), arr.end(), val) - arr.begin();

        if (pos > arr.size() - 1) {
            ll need = val / arr[arr.size() - 1] + (val % arr[arr.size() - 1] != 0);
            ll total = need * arr[arr.size() - 1] * 1LL;
            //cout << "tot: " << total << endl;
            ans += total - val;
        } else {
            ans += arr[pos] - val;
        }
    }
    cout << ans << endl;

    return 0;
}
