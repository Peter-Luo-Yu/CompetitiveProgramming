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
 
int n;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> topo;
 
void dfs(int s) {
    if (vis[s]) return;
    vis[s] = true;
 
    for (auto u : adj[s]) {
        dfs(u);
    }
 
    topo.push_back(s);
}
 
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int m; cin >> n >> m;
    adj = vector<vector<int>> (n);
    vis = vector<bool> (n);
    topo = vector<int> ();
 
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
    }
 
    for (int i = 0; i < n; i++) {
        dfs(i);
    }
    reverse(topo.begin(), topo.end());
 
    // topo sort: if u -> v, then u must come before v
 
    // map to instantly know the idx of vertex in topo sort
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[topo[i]] = i;
    }
 
    bool failed = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            // connection from i to adj[i][j], i has to come strictly before
            if (idx[adj[i][j]] <= idx[i]) {
                failed = true;
            }
        }
    }
 
    if (failed) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
 
    
    for (int val : topo) {
        cout << val + 1 << " ";
    } cout << endl;
 
 
 
    return 0;
}