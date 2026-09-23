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

    ll n, k; cin >> n >> k; 

    vector<ll> arr (n); 
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    ll l = 0, r = 2e18;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l+r)/ (ll)2;

        ll cur_sum = 0;
        ll count = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                count = 2e18;
                break;
            }

            if (cur_sum + arr[i] > mid) {
                count++;
                cur_sum = arr[i];
            } else {
                cur_sum += arr[i];
            }

            //cout << "mid: " << mid << " arr: " << arr[i] << " cursum: " << cur_sum << " count: " << count << endl;
        }

        

        if (count > k) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }

    }

    cout << ans << endl;

    return 0;
}