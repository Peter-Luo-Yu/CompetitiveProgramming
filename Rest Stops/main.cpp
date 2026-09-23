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

    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    ll l, n, rf, rb; 
    cin >> l >> n >> rf >> rb;
    ll diff = rf - rb;

    // input is given in sorted order, pos - tastiness
    vector<pair<ll, ll>> arr (n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    //printP(arr);

    ll Max = 0;
    vector<bool> good (n);

    for (int i = n - 1; i >= 0; i--){
        if (arr[i].second > Max) {
            good[i] = true;
            Max = arr[i].second;
        }
    }

    //print(good);

    ll ans = 0, prev = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ll dist = arr[i].first - prev;
            ll f_time = dist * rf;
            ll b_time = dist * rb;
            ll dt = f_time - b_time;

            ans += dt * arr[i].second;
            prev = arr[i].first;
        } 
    }

    cout << ans << endl;


    return 0;
}
