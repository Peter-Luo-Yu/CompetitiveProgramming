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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, m, k; cin >> n >> m >> k;
    
    vector<pair<ll, ll>> arr (n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second; // weight, number of cows
    }

    sort (arr.begin(), arr.end());
    reverse (arr.begin(), arr.end());

    //printP(arr);

    ll avail = m;
    ll ans = 0;

    queue<pair<ll, ll>> q; // weight of tower (weight of smallest cow on top) - cnt

    for (int i = 0; i < n; i++) {
        ll curWeight = arr[i].first;
        ll numCows = arr[i].second;

        // free spots from queue
        while (!q.empty() && q.front().first >= curWeight + k) {
            avail += q.front().second;
            q.pop();
        }

        ll placed= min (numCows, avail);
        if (placed > 0) {
            ans += placed;
            q.push({curWeight, placed});
            avail -= placed;
        }
    }

    cout << ans << endl;


    return 0;
}
