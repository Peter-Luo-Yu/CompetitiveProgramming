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

int maxDist = -1;
int furthest = -1;
vector<int> a, b;

void dfs1 (int s, int dist, vector<vector<int>> &adj, vector<bool> &vis) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        dfs1 (u, dist + 1, adj, vis);
    }

    if (dist > maxDist) {
        maxDist = dist;
        furthest = s;
    }
}

int max2 = -1, furthest2 = -1;

void dfs2 (int s, int dist, vector<vector<int>> &adj, vector<bool> &vis) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        dfs2 (u, dist + 1, adj, vis);
    }

    a[s] = max (dist, a[s]);

    if (dist > max2) {
        max2 = dist;
        furthest2 = s;
    }
}

void dfs3 (int s, int dist, vector<vector<int>> &adj, vector<bool> &vis) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        dfs3 (u, dist + 1, adj, vis);
    }

    b[s] = max (dist, b[s]);
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> adj (n);
    vector<bool> vis (n);
    a = vector<int> (n);
    b = vector<int> (n);

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // find point a, on the edge.
    dfs1 (0, 0, adj, vis);

    //cout << furthest << " " << maxDist << endl;
    vis = vector<bool> (n);

    // find all dist from a, also find point b.
    dfs2 (furthest, 0, adj, vis);

    vis = vector<bool> (n);

    // find all dist from b.
    dfs3 (furthest2, 0, adj, vis);

    //print(a); print(b);

    for (int i = 0; i < n; i++) {
        cout << max (a[i], b[i]) << " ";
    }

    
    return 0;
}
