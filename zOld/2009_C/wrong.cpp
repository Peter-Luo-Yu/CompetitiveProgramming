#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--){
        ll x, y, k; cin >> x >> y >> k;
        //cout << x << " " << y << " " << k << endl;
        ll moves = (max(x, y) + k - 1)/k;

        if (x > y){
            ll ans = 2 * moves - 1;
            cout << ans << endl;
        } 
        else if (y >= x){
            ll ans = 2 * moves;
            cout << ans << endl;
        }

    }

    return 0;
}