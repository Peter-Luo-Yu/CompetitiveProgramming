#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        ll n; cin >> n;
        int ops = 0;
        while (n > 3) {
            n /= 4;
            ops++;
        }

        ll ans = 1;
        for (int i = 0; i < ops; i++) {
            ans *= 2;
        }

        cout << ans << endl;
       
    }
    

    return 0;
}