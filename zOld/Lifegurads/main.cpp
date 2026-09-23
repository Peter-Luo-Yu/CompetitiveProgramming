#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "---------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    ll n; cin >> n;
    vector<pair<ll, ll>> pts;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        pts.push_back({a, 0});
        pts.push_back({b, 1});
    }

    sort (pts.begin(), pts.end());

    //printP(pts);

    vector<ll> arr(2 * n), diff(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        arr[i] = pts[i].first;
        if (pts[i].second == 0) {
            diff[i] = 1;
        } else {
            diff[i] = -1;
        }
    }

    //cout << "  "; print(arr);
    //cout << "  "; print(diff);

    vector<ll> prefix (2 * n + 1, 0);
    for (int i = 0; i < 2 * n; i++) {
        prefix[i + 1] = prefix[i] + diff[i];
    }

    //print(prefix);


    ll total = 0;
    for (int i = 1; i < prefix.size(); i++) {
        if (prefix[i] > 0) {
            total += arr[i] - arr[i - 1];
        }
    }


    ll min_lost = 1e12;
    for (int i = 1; i < prefix.size(); i++) {
        if (prefix[i] == 1) {   
            min_lost = min (min_lost, arr[i] - arr[i - 1]);
        }
    }

    if (min_lost == 1e12) min_lost = 0;

    cout << total - min_lost << endl;


    
    return 0;
}
