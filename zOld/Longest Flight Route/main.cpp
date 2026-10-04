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

void dfs (vector<vector<int>> &adj, vector<bool> &vis, vector<int> &topo, int s) {
    if (vis[s]) {
        return;
    }
    vis[s] = true;

    for (auto u : adj[s]) {
        dfs(adj, vis, topo, u);
    }
    topo.push_back(s);
}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n), rev(n);
    vector<bool> vis(n);
    vector<int> topo;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        dfs(adj,vis,topo,i);
    }

    reverse(topo.begin(), topo.end());
    //print(topo);

    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[topo[i]] = i;
    }

    bool failed = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) { // want u to appear before v
            if (idx[i] >= idx[adj[i][j]]) {
                failed = true;
            }
        }
    }

    if (failed) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> dist(n, -1e9), parent(n, -1);
    dist[0] = 0;
    // you need to check which edges are going into node i
    for (int i = 1; i < topo.size(); i++) {
        int cur = topo[i];
        for (int prev : rev[cur]) {
            if (dist[prev] + 1 > dist[cur]) {
                dist[cur] = dist[prev] + 1;
                parent[cur] = prev;
            }
        }
    }

    //print(dist); print(parent);

    if (dist[n - 1] < 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }


    vector<int> route;
    int cur = n - 1;
    while (cur != 0) {
        route.push_back(cur);
        cur = parent[cur];
    }
    route.push_back(0);
    reverse(route.begin(), route.end());

    //print(route);

    cout << route.size() << endl;
    for (auto r : route) {
        cout << r + 1 << " ";
    }cout << endl;






    return 0;
}
