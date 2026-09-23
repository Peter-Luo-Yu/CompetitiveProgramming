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
        ll n, d; cin >> n >> d;

        vector<ll> arr (n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ll ans = 0, neighbors = arr[0];

        for (int i = n - 1; i >= n - d; i--) {
            neighbors += arr[i];
        }
        for (int i = 1; i <= d; i++) {
            neighbors += arr[i];
        }
        //cout << neighbors << endl;

        for (int i = 0; i < n; i++) {
            ll cur = arr[i];
            ll neighborSum = neighbors - cur;

            ll contrib = 2 * d * cur - neighborSum;
            if (contrib > 0) {
                ans += contrib;
            }

            int lidx = i - d;
            if (lidx < 0) lidx += n;

            neighbors -= arr[lidx];
            neighbors += arr[(i + d + 1) % n];
        }

        cout << ans << endl;


        //space;
    }


    return 0;
}
