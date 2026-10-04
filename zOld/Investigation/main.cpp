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

ll MOD = 1e9 + 7;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj (n);

    // we need to track the min dist, number of paths, min length and max length (of route).
    vector<ll> dist(n, 1e18), paths(n), Minlen(n, 1e18), Maxlen(n, -1);

    for (int i = 0; i < m; i++) {
        ll a, b, w; cin >> a >> b >> w; a--, b--;
        adj[a].push_back({b, w});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    paths[0] = 1;
    Minlen[0] = 0;
    Maxlen[0] = 0;

    while (!pq.empty()) {
        ll cur = pq.top().second;
        ll curd = pq.top().first;
        pq.pop();

        if (curd > dist[cur]) continue;

        for (auto &[next, nextd] : adj[cur]) {
            if (curd + nextd == dist[next]) {
                paths[next] = (paths[next] + paths[cur]) % MOD;
                Minlen[next] = min(Minlen[cur] + 1, Minlen[next]);
                Maxlen[next] = max(Maxlen[cur] + 1, Maxlen[next]);
            }
            else if (curd + nextd < dist[next]) {
                dist[next] = curd + nextd;
                paths[next] = paths[cur];
                Minlen[next] = Minlen[cur] + 1;
                Maxlen[next] = Maxlen[cur] + 1;
                pq.push({dist[next], next});
            }
        }
    }

    cout << dist[n - 1] << " " << paths[n - 1] << " " << Minlen[n - 1] << " " << Maxlen[n - 1] << endl;



    return 0;
}
