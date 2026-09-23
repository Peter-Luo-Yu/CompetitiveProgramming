#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    ll n, m; cin >> n >> m;

    vector<pair<ll, ll>> arr (m);

    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        arr[i] = {a,b};
    }
    sort (arr.begin(), arr.end());

    ll l = 1, r = 2e18;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l+r)/2;

        ll prev_cow = -1;
        ll placed = 0;
        for (int i = 0; i < arr.size(); i++) {
            ll a = arr[i].first, b = arr[i].second;

            if (prev_cow == -1) {
                prev_cow = a;
                placed++;
            }

            ll start = prev_cow + mid;
            ll gap;
            if (start > a) {
                gap = b - start;
            }
            else {
                gap = b - a;
            }

            ll amount = 0;
            if (gap >= 0) {
                amount = (gap/mid) + 1;
            }


            placed += amount;

            if (amount > 0) {
                if (start > a) {
                    prev_cow = start + (amount-1) * mid;
                } else {
                    prev_cow = a + (amount-1) * mid;
                }   
                
            }

            //cout << "mid: " << mid << " " << a << " " << b << " start: " << start << " gap: " << gap << " amount: " << amount << " placed: " << placed << " prev: " << prev_cow << endl;
        }

        if (placed >= n) {
            ans = max(mid, ans);
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    

    return 0;
}