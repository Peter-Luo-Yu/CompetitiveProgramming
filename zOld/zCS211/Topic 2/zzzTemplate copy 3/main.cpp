#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll h, c; cin >> h >> c;            // h is the goal
    vector<pair<ll, ll>> workers;
    ll minA = 1e9, maxA = -1;
    for (int i = 0; i < c; i++) {
        ll a, b; cin >> a >> b;
        workers.push_back({a, b});
        minA = min (minA, a);
        maxA = max (maxA, a);
    }
    
    ll l = minA, r = 2e15;
    ll ans = 9e18;
    while (l <= r) {
        ll mid = (l + r) / 2;
        
        ll cur = 0;

        for (int i = 0; i < c; i++) {
            if (mid >= workers[i].first) {
                cur += (mid - workers[i].first) / workers[i].second;
            }
            if (cur >= h) {
                break;
            }
        }

        //cout << "mid: " << mid << " cur: " << cur << endl;
    
        if (cur >= h) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    cout << max(maxA, ans) << endl;

    return 0;
}