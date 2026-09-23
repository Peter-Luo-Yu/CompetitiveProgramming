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


int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
    }


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            //cout << "a: " << a[i] << " | ";

            if (i == 0) {
                ll gcd1 = gcd (a[i], a[i + 1]);
                
                //cout << gcd1 << endl;

                if (gcd1 < a[i]) ans++;
            }
            else if (i == n - 1) {
                ll gcd1 = gcd (a[i], a[i - 1]);
                
                //cout << gcd1 << endl;

                if (gcd1 < a[i]) ans++;

            } else {

                // there's two constraints, the new a[i] must have the same gcd's as the previous ones
                ll gcd1 = gcd (a[i], a[i - 1]);
                ll gcd2 = gcd (a[i], a[i + 1]);

                // gcd (a, b) * lcm (a, b) = a * b
                
                ll lcm = gcd1 * gcd2 / gcd(gcd1, gcd2);

                if (lcm < a[i]) ans++;
            }
        }

        cout << ans << endl;
    }
    
    
    return 0;
}
