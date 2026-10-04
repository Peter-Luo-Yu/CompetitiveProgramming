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

    int n, m; cin >> n >> m; 
    vector<vector<pair<ll, ll>>> adj (n);

    for (int i = 0; i < m; i++) {
        ll a, b, w; cin >> a >> b >> w; a--, b--;
        adj[a].push_back({b, w});
    }

    vector<bool> vis (n);
    vector<ll> dist (n, 1e18);

    // distance - idx
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[0] = 0;
    vis[0] = true;
    pq.push({0, 0});

    while (!pq.empty()) {
        ll d = pq.top().first;
        ll cur = pq.top().second;
        pq.pop();

        // to not TLE
        if (d != dist[cur]) continue;

        for (auto next : adj[cur]) {
            if (vis[next.first]) continue;

            if (dist[cur] + next.second < dist[next.first]) {
                dist[next.first] = dist[cur] + next.second;
                pq.push({dist[next.first], next.first});
            }
        }
    }

    print(dist);


    return 0;
}
