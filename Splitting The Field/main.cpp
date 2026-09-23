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

    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    ll n; cin >> n;
    ll min_x = 1e12, min_y = 1e12, max_x = -1, max_y = -1;

    vector<pair<ll, ll>> arr (n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        min_x = min (min_x, arr[i].first);
        min_y = min (min_y, arr[i].second);
        max_x = max (max_x, arr[i].first);
        max_y = max (max_y, arr[i].second);
    }

    ll total_area = (max_x - min_x) * (max_y - min_y);
    //cout << total_area << endl;


    ll min_area = 1e18;

    // splitting vertically, by x coordinate
    vector<pair<ll, ll>> pts_x = arr;
    sort (pts_x.begin(), pts_x.end());
    //printP(pts_x);

    vector<ll> premin (n, 1e9), premax (n, -1), sufmin (n, 1e9), sufmax (n, -1);
    premin[0] = pts_x[0].second; premax[0] = pts_x[0].second;
    sufmin[n - 1] = pts_x[n - 1].second; sufmax[n - 1] = pts_x[n - 1].second;

    for (int i = 1; i < n; i++) {
        premin[i] = min(premin[i - 1], pts_x[i].second);
        premax[i] = max(premax[i - 1], pts_x[i].second);
    }
    for (int i = n - 2; i >= 0; i--) {
        sufmin[i] = min(sufmin[i + 1], pts_x[i].second);
        sufmax[i] = max(sufmax[i + 1], pts_x[i].second);
    }

    //print(premin); print(premax); print(sufmin); print(sufmax);

    for (int i = 0; i < n - 1; i++) {
        if (pts_x[i].first != pts_x[i + 1].first) {
            ll area1 = (pts_x[i].first - pts_x[0].first) * (premax[i] - premin[i]);
            ll area2 = (pts_x[n - 1].first - pts_x[i + 1].first) * (sufmax[i + 1] - sufmin[i + 1]);
            
            min_area = min (min_area, area1 + area2);
            //cout << min_area << endl;
        }
    }

    //space;

    // splitting horizontally, by y coordinate
    vector<pair<ll, ll>> pts_y = arr;
    for (int i = 0; i < n; i++) {   
        swap (pts_y[i].first, pts_y[i].second);
    }
    sort (pts_y.begin(), pts_y.end());
    for (int i = 0; i < n; i++) {
        swap (pts_y[i].first, pts_y[i].second);
    }

    //printP(pts_y);

    premin = vector<ll> (n, 1e9); premax = vector<ll> (n, -1); sufmin = vector<ll> (n, 1e9); sufmax = vector<ll> (n, -1);
    premin[0] = pts_y[0].first; premax[0] = pts_y[0].first;
    sufmin[n - 1] = pts_y[n - 1].first; sufmax[n - 1] = pts_y[n - 1].first;

    for (int i = 1; i < n; i++) {
        premin[i] = min(premin[i - 1], pts_y[i].first);
        premax[i] = max(premax[i - 1], pts_y[i].first);
    }
    for (int i = n - 2; i >= 0; i--) {
        sufmin[i] = min(sufmin[i + 1], pts_y[i].first);
        sufmax[i] = max(sufmax[i + 1], pts_y[i].first);
    }

    //print(premin); print(premax); print(sufmin); print(sufmax);

    for (int i = 0; i < n - 1; i++) {
        if (pts_y[i].second != pts_y[i + 1].second) {
            ll area1 = (pts_y[i].second - pts_y[0].second) * (premax[i] - premin[i]);
            ll area2 = (pts_y[n - 1].second - pts_y[i + 1].second) * (sufmax[i + 1] - sufmin[i + 1]);
            
            min_area = min (min_area, area1 + area2);
            //cout << min_area << endl;
        }
    }
    
    cout << total_area - min_area << endl;

    return 0;
}
