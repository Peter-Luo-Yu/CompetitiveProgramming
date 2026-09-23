#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

struct point {
    ll lidx;
    ll ridx;
};

// sort by left index
struct cmpLeft {
    bool operator()(const point &a, const point &b) const {
        return a.lidx < b.lidx;
    }
};

// min-heap by ridx
struct cmpRight {
    bool operator()(const ll &a, const ll &b) const {
        return a > b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    ll n, p, q, s;
    cin >> n >> p >> q >> s;

    vector<ll> a(p), b(q);

    for (ll i = 0; i < p; i++) cin >> a[i];
    for (ll i = 0; i < q; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (min(p, q) < n) {
        cout << -1 << endl;
        return 0;
    }

    ll l = 0, r = s;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;

        vector<point> data;

        // build intervals
        for (ll i = 0; i < p; i++) {
            ll low = a[i] - mid;
            ll hi = min(a[i] + mid, s - a[i]);

            ll lowidx = lower_bound(b.begin(), b.end(), low) - b.begin();
            ll hiidx = upper_bound(b.begin(), b.end(), hi) - b.begin() - 1;

            if (lowidx <= hiidx) {
                data.push_back({lowidx, hiidx});
            }
        }

        sort(data.begin(), data.end(), cmpLeft());

        priority_queue<ll, vector<ll>, cmpRight> pq;

        ll ptr = 0;
        ll paired = 0;

        // sweep through b
        for (ll j = 0; j < q; j++) {

            while (ptr < data.size() && data[ptr].lidx <= j) {
                pq.push(data[ptr].ridx);
                ptr++;
            }

            while (!pq.empty() && pq.top() < j) {
                pq.pop();
            }

            if (!pq.empty()) {
                pq.pop();
                paired++;
            }
        }

        if (paired >= n) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (l > s) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
