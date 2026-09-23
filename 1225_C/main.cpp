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

    // we can only add 2^x + p, suppose we do this t times.
    // so: n = t(2^x + p) = t(2^x) + tp
    // rearrange: n - tp = summation t times of (2 ^ different powers)

    // since n and p are already fixed, we can just brute force over t

        
    ll n, p; cin >> n >> p;

    
    ll ans = -1;
    for (int t = 1; t <= 1e6; t++) {
        ll m = n - t * p;

        //cout << "m: " << m << endl;

        ll bits_on = 0;
        ll temp = m;
        while (temp > 0) {
            if (temp % 2 == 1) {
                //cout << 1 << " ";
                bits_on++;
            } else {
                //cout << 0 << " ";
            }
            temp /= 2LL;
        }
        //cout << endl;
        
        //cout << "bits: " << bits_on << endl;

        if (bits_on <= t && t <= m) {
            ans = t;
            break;
        }

        //space;
    }

    if (ans == -1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }


    return 0;
}
