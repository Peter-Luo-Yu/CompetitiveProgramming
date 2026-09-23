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
    while (t--){
        int l, r, k; cin >> l >> r >> k;
        int largest = r/k;

        //cout << "largest multiple: " << largest << endl;
        int ans = largest - l + 1;

        if (ans < 0){
            cout << 0 << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}