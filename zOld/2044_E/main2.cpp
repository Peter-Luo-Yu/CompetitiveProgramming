#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // y / x = k ^ n    y = k^n x 
    // log k (y / x) = log k (k ^ n)
    // log k (y) - log k (x) = n    or   logk y = logk k^n + logk x                

    int t; cin >> t;

    while (t--) {
        ll k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;

        // you fix n, and count the x values in the interval 
        ll ans = 0;
        ll kn = 1;
        for (int n = 0; n < 32; n++) {
            
            // condition 1: ceil(l2/k^n) <= x <= floor(r2/k^n)

            ll left = (l2 + kn - 1)/(kn);
            ll right = r2/kn;
            
            left = max (left, l1);
            right = min (right, r1);

            ans += max (right - left + 1, 0LL);

            if (kn > LLONG_MAX / k) {
                break;
            }
            kn *= k;
        }

        cout << ans << endl;
    }


    return 0;
}