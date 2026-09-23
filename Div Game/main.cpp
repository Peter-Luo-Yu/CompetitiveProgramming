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

    ll n; cin >> n;
    ll N = n;

    ll ans = 0;
    for (ll i = 2; i * i <= N; i++) {
        if (n % i == 0) {
            ll p = 0;
            while (n % i == 0) {
                n /= i;
                p++;
            }

            //cout << "i: " << i << " p: " << p << " n: " << n << endl;

            ll amt = 1;
            while (p > 0) {
                p -= amt; 
                amt++;
                if (p >= 0) {
                    ans++;
                }
            }
        }
    }

    if (n > 1) ans++;

    cout << ans << endl;


    return 0;
}
