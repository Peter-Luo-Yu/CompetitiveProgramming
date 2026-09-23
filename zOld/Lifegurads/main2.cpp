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
    vector<vector<ll>> data;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        data.push_back({a, i, 0});
        data.push_back({b, i, 1});
    }

    sort (data.begin(), data.end());

    //print2d(data);

    // how much time alone
    vector<int> alone (n);

    set<int> active;
    int prev = 0, total = 0;

    for (int i = 0; i < data.size(); i++) {
        int cur = data[i][0];

        //cout << "cur: " << cur << " active: " << active.size() << endl;

        if (active.size() > 0) {
            total += cur - prev;
        }
        if (active.size() == 1) {
            alone[*active.begin()] += cur - prev;
        }

        if (data[i][2] == 0) {
            active.insert(data[i][1]);
        } else {
            active.erase(data[i][1]);
        }

        prev = cur;
    }
    
    cout << total - *min_element(alone.begin(), alone.end()) << endl;

    
    return 0;
}
