#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, k; cin >> n >> k;

    vector<int> arr (n); 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort (arr.begin(), arr.end());

    ll ans = 0;
    ll l = 0;
    ll r = 2999999999;

    while (l <= r) {
        ll mid = (l+r)/2; // the median

        ll cost = 0;
        for (int i = n/2; i < n; i++){
            cost += max (0LL, mid - arr[i]);
        }

        if (cost <= k) {
            l = mid + 1;
            ans = mid;
        } 
        else if (cost > k) {
            r = mid - 1;
        }

        //cout << "mid: " << cost << endl;
    }

    cout << ans << endl;



    return 0;
}