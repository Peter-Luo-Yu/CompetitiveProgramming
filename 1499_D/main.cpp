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

    int N = 2 * 1e7 + 5;
    vector<int> factors (N);

    for (int i = 2; i < N; i++) {
        if (factors[i] == 0) {
            for (int j = i; j < N; j += i) {
                factors[j]++;
            }
        }
    }

    //print(factors);

    int t; cin >> t;
    while (t--) {
        ll c, d, x; cin >> c >> d >> x;

        ll ans = 0;

        for (ll div = 1; div * div <= x; div++) {
            if (x % div == 0) {
                if (((x / div) + d) % c == 0) {
                    ll k = ((x / div) + d)/c;
                    ans += (1LL << factors[k]);
                }

                if (div != x / div) {
                    ll other = x / div;

                    if (((x / other) + d) % c == 0) {
                        ll k = ((x / other) + d) / c;
                        ans += (1LL << factors[k]);
                    }
                }
            }
        }

        cout << ans << endl;
    }



    return 0;
}
