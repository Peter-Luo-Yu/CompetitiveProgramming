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

struct Edge {
    int a, b, w, f;
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<Edge> edges (m);
    vector<int> flow (m);
    for (int i = 0; i < m; i++) {
        int a, b, w, f; cin >> a >> b >> w >> f; a--, b--;
        edges[i] = {a, b, w, f};
        flow[i] = f;
    }

    ld ans = -1;
    for (int f : flow) {
        // f is the minimum flow rate, any edge with less flow rate than f is ignored

        vector<vector<pair<int, int>>> adj (n);
        vector<int> dist (n, 1e9);

        for (Edge edge : edges) {
            if (edge.f >= f) {
                adj[edge.a].push_back({edge.b, edge.w});
                adj[edge.b].push_back({edge.a, edge.w});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            int cur = pq.top().second;
            int curd = pq.top().first;
            pq.pop();

            if (curd != dist[cur]) continue;

            for (auto next : adj[cur]) {
                if (curd + next.second < dist[next.first]) {
                    dist[next.first] = curd + next.second;
                    pq.push({dist[next.first], next.first});
                }
            }
        }

        //print(dist);
        
        if (dist[n - 1] != 1e9) {
            ans = max(ans, (ld) f / dist[n - 1]);
        }

        //space;

    }

    int finalans = ans * 1e6;


    cout << finalans << endl;


    return 0;
}
