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
        ll a, b, c; cin >> a >> b >> c;

        ll MOD = 1e9 + 7;
        ll MOD2 = MOD - 1;

        // first compute b ^ c
        ll pow = 1;
        ll temp = b;
        while (c > 0) {
            if (c % 2 == 1) {
                pow *= temp;
                pow %= MOD2;
            }
            temp *= temp;
            temp %= MOD2;

            c /= 2;
        }


        ll ans = 1;
        temp = a;
        while (pow > 0) {
            if (pow % 2 == 1) {
                ans *= temp;
                ans %= MOD;
            }
            temp *= temp;
            temp %= MOD;

            pow /= 2;
        }

        cout << ans << endl;
    }


    return 0;
}
