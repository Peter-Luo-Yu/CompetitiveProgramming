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
    int cost;
    int idx;
    bool hay;

    bool operator<(const Edge &other) const {
        return cost > other.cost;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;

    vector<int> hay (n);
    vector<vector<pair<int, int>>> adj (n);
    // we need to track b, w, and haybale
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w; a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    
    for (int i = 0; i < k; i++) {
        int idx, val; cin >> idx >> val; idx--;
        hay[idx] = max (hay[idx], val);
    }

    // we need to rip a dijkstra from the ending node
    priority_queue<Edge> pq;
    vector<vector<int>> dist (n, vector<int> (2, 1e9));

    dist[n - 1][0] = 0;
    pq.push({0, n - 1, false});
    if (hay[n - 1] > 0) {
        dist[n - 1][1] = hay[n - 1];
        pq.push({-hay[n - 1], n - 1, true});
    }

    while (!pq.empty()) {
        int curcost = pq.top().cost;
        int curidx = pq.top().idx;
        bool curhay = pq.top().hay;
        pq.pop();

        if (dist[curidx][curhay] > curcost) continue;

        for (auto next : adj[curidx]) {
            int newcost = curcost + next.second;

            if (curhay) {
                if (newcost < dist[next.first][1]) {
                    dist[next.first][1] = newcost;
                    pq.push({newcost, next.first, true});
                }
            }
            else {
                if (newcost < dist[next.first][0]) {
                    dist[next.first][0] = newcost;
                    pq.push({newcost, next.first, false});
                }
                // try to visit the haybale at next, remember you have already visited (or not vis) the cur hayble
                if ((hay[next.first] > 0) && (newcost - hay[next.first] < dist[next.first][1])) {
                    dist[next.first][1] = newcost - hay[next.first];
                    pq.push({newcost - hay[next.first], next.first, true});
                }

            }
        }
    }

    //print2d(dist);

    for (int i = 0; i < n - 1; i++) {
        if (dist[i][1] <= dist[i][0]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
