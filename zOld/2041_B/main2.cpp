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
        ll b, w; cin >> b >> w;

        // k(k+1)/2 <= b + w
        ll tot = b + w;
        tot *= 2;

        //cout << tot << endl;
        ll root = sqrt(tot);
        ll above = root + 1;
        ll below = root - 1;

        if (root * above <= tot) {
            cout << root << endl;
        } else {
            cout << root - 1 << endl;
        }
    }
    

    return 0;
}