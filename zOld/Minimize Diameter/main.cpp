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

int max1 = -1, furthest1 = -1;
int max2 = -1, furthest2 = -1;

void dfs1 (int s, int dist, vector<vector<int>> &adj, vector<bool> &vis) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        dfs1 (u, dist + 1, adj, vis);
    }

    if (dist > max1) {
        max1 = dist;
        furthest1 = s;
    }
}

void dfs2 (int s, int dist, vector<vector<int>> &adj, vector<bool> &vis) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        dfs2 (u, dist + 1, adj, vis);
    }

    if (dist > max2) {
        max2 = dist;
        furthest2 = s;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> adj1 (n);
    vector<bool> vis1 (n); 
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj1[a].push_back(b); adj1[b].push_back(a);
    }

    int m; cin >> m;
    vector<vector<int>> adj2 (m);
    vector<bool> vis2 (m); 
    for (int i = 0; i < m - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj2[a].push_back(b); adj2[b].push_back(a);
    }

    //printG(adj1); printG(adj2);

    dfs1(0, 0, adj1, vis1);
    vis1 = vector<bool> (n);
    dfs1(furthest1, 0, adj1, vis1);

    dfs2(0, 0, adj2, vis2);
    vis2 = vector<bool> (m);
    dfs2(furthest2, 0, adj2, vis2);

    int ans = ((max1/2) + (max1 % 2 != 0)) + ((max2/2) + (max2 % 2 != 0)) + 1;

    cout << max(ans, max(max1, max2)) << endl;
    
    return 0;
}
