#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        ll x, y, a;            //little B starts diggin first
        cin >> x >> y >> a;

        double remaining = a % (x+y);

        if (remaining + 0.5 <= x){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}