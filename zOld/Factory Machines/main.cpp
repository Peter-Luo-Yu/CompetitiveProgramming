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

    ll n, t; cin >> n >> t;

    vector<ll> arr (n); 
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    ll l = 0, r = 2e18;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / (ll) 2;

        ll made = 0;
        for (int i = 0; i < n; i++) {
            made += mid/arr[i];
            if (made >= t) {
                break;
            }
        }

        //cout << "l: " << l << " r: " << r << " time: " << mid << " made: " << made << endl;

        if (made >= t) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }   

    cout << ans << endl;
    

    return 0;
}