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

int maxDist = -1, furthest = -1;

void dfs (int s, int dist, vector<vector<int>> &adj, vector<bool> &vis) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        dfs (u, dist + 1, adj, vis);
    }

    if (dist > maxDist) {
        maxDist = dist;
        furthest = s;
    }
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> adj (n);
    vector<bool> vis (n);

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs (0, 0, adj, vis);

    //cout << maxDist << " " << furthest << endl;

    vis = vector<bool> (n);
    maxDist = 0;

    dfs (furthest, 0, adj, vis);

    cout << maxDist << endl;
    
    return 0;
}
