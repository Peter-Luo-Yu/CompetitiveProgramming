#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

struct point {
    ll val;
    ll lidx;
    ll ridx;
    ll len;
};

// the goal is to pair biggest a with biggest b
bool cmp (point a, point b) {
    if (a.ridx == b.ridx) {
        return a.len > b.len;
    }
    return a.ridx < b.ridx;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, p, q, s;
    cin >> n >> p >> q >> s;

    vector<ll> a, b;
    
    for (int i = 0; i < p; i++) {ll val; cin >> val; a.push_back(val);}
    for (int i = 0; i < q; i++) {ll val; cin >> val; b.push_back(val);}
    
    vector<ll> temp;
    if (p > q) {
        temp = b;
        //b = vector<int> ();
        b = a;
        //a = vector<int> ();
        a = temp;
    }

    sort (a.begin(), a.end());
    sort (b.begin(), b.end());

    //print(a); print(b);

    ll ans = -1;
    ll l = 0, r = 1e15;
    while (l <= r) {
        ll mid = l + (r - l)/2;
        
        //cout << "MID: " << mid << endl;

        // precomputing the range of possibilities of A
        vector<point> data;
        for (int i = 0; i < a.size(); i++) {
            ll low = a[i] - mid;
            ll hi = min (a[i] + mid, s - a[i]);
            ll lowidx = lower_bound(b.begin(), b.end(), low) - b.begin();
            ll hiidx = upper_bound(b.begin(), b.end(), hi) - b.begin() - 1;


            if (lowidx <= hiidx) {
                point pt;
                pt.val = a[i]; pt.lidx = lowidx; pt.ridx = hiidx; pt.len = hiidx - lowidx;
                data.push_back(pt);

                //cout << "low: " << low << " hi: " << hi << endl;
                //cout << "lowidx: " << lowidx << " hiidx: " << hiidx << endl;
            }
        }

        sort (data.begin(), data.end(), cmp);

        ll paired = 0;
        ll maxBidx = b.size() - 1;

        for (int i = data.size() - 1; i >= 0; i--) {
            //cout << "data: " << i << " | " << data[i].lidx << " " << data[i].ridx << endl;

            while (maxBidx > data[i].ridx) {
                maxBidx--;
            }

            if (data[i].lidx <= maxBidx && maxBidx <= data[i].ridx) {
                maxBidx--;
                paired++;
            } 
        }

        //cout << "paired: " << paired << " ------------" << endl;

        if (paired >= n) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
