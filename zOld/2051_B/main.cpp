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

    int t; cin >> t;
    while (t--) {
        ll n, a, b, c; cin >> n >> a >> b >> c;

        ll cur = n % (a+b+c); 
        ll ans = 3LL * (n / (a + b + c));
        ll idx = 0;

        //cout << cur << " " << ans << endl;
        while (cur > 0) {
            if (idx % 3 == 0) {
                cur -= a;
                idx++; ans++;
            } else if (idx % 3 == 1) {
                cur -= b;
                idx++; ans++;
            } else {
                cur -= c;
                idx++; ans++;
            }
        }

        cout << ans << endl;

    }
    
    return 0;
}
