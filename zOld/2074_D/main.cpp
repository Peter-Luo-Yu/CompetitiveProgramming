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

        vector<ll> x(n), r(n);

        for (int i = 0; i < n; i++) cin >> x[i];
        for (int i = 0; i < n; i++) cin >> r[i];

        map<ll, ll> h;

        for (int i = 0; i < n; i++) {
            ll center = x[i];
            for (int j = center - r[i]; j <= center + r[i]; j++) {
                ll height = sqrtl(r[i] * r[i] - (j - center) * (j - center));
                h[j] = max (h[j], height);
            }
        }

        //printP(h);

        ll ans = 0;

        for (auto x : h) {
            ans += 2 * x.second + 1;
        }

        cout << ans << endl;


        //space;
    }

    return 0;
}
