#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        ll x, y; cin >> x >> y;
        ll MOD = 676767677;


        if (x != y) {
            ll n = abs(x - y);
            ll ans = 0;

            for (int i = 1; i <= n; i++) {
                if (n % i == 0) {
                    ans++;
                    //ans %= MOD;
                }
            }

            cout << ans << endl;

            for (int i = 0; i < x; i++) {
                cout << 1 << " ";
            }
            for (int i = 0; i < y; i++) {
                cout << -1 << " ";
            }
            cout << endl;

        } else {

            cout << 1 << endl;

            for (int i = 0; i < x; i++) {
                cout << 1 << " ";
            }
            for (int i = 0; i < y; i++) {
                cout << -1 << " ";
            }
            cout << endl;
        }
    }
    
    
    return 0;
}
