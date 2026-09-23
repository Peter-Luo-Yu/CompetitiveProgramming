#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        ld n; cin >> n; ll sum = 0;
        vector<int> arr (n); for (int i = 0; i < n; i++) {cin >> arr[i]; sum += arr[i];}
        sort (arr.begin(), arr.end());

        ld avg = (ld) sum/n;

        if (n == 1 || n == 2){
            cout << -1 << endl;
            continue;
        }
        if (avg > 2 * arr[n/2]){
            cout << 0 << endl;
        } else {
            ll ans = 2 * arr[n/2] * n - sum;
            cout << (ll) ans + 1 << endl;
        }
        
        
    }

    return 0;
}