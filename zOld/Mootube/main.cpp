#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int K = -1;

void dfs (vector<vector<pair<int, int>>> &adj, vector<bool> &vis, int s, int p) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto x : adj[s]) {
        if (x.first != p && x.second >= K) {
            dfs (adj, vis, x.first, s);
        } 
    }
}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int n, q; cin >> n >> q;

    vector<vector<pair<int, int>>> adj (n);

    for (int i = 0; i < n - 1; i++) {
        int a, b, w; cin >> a >> b >> w; a--; b--;

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    /*
    for (auto x : adj) {
        printP(x);
    } */

    for (int i = 0; i < q; i++) {
        int k, v; cin >> k >> v; v--;
        K = k;

        vector<bool> vis (n);
        dfs (adj, vis, v, -1);

        int ans = 0;

        //print(vis);

        for (int i = 0; i < vis.size(); i++) {
            if (vis[i]) ans++;
        }

        cout << ans - 1 << endl;
    }

    
    return 0;
}
