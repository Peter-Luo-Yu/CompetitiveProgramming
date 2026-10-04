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

struct DSU {
    int n;
    vector<int> parent, sz;

    void setup(int x) {
        n = x;
        parent = sz = vector<int> (n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; sz[i] = 1;
        }
    }

    int find(int x) {
        while (x != parent[x]) x = parent[x];
        return x;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        parent[b] = a;
    }

    
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w; a--, b--;
        edges[i] = {w, a, b};
    }

    sort (edges.begin(), edges.end());

    DSU dsu;
    dsu.setup(n);

    ll ans = 0;

    for (int i = 0; i < edges.size(); i++) {
        if (!dsu.same(edges[i][1], edges[i][2])) {
            dsu.unite(edges[i][1], edges[i][2]);
            ans += edges[i][0];
        }
    }

    int ccsize = 0;

    for (int i = 0; i < dsu.sz.size(); i++) {
        ccsize = max (ccsize, dsu.sz[i]);
    }

    if (ccsize == n) {
        cout << ans << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}
