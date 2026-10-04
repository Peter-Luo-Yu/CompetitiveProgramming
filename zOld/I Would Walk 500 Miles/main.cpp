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
    int w, a, b;
};

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

    bool same (int a, int b) {
        return find(a) == find(b);
    }

    void unite (int a, int b) {
        a = find(a); 
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        parent[b] = a;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);

    int n, k; cin >> n >> k;

    vector<Edge> edges (n * (n - 1) / 2);

    int idx = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            int w = (2019201913LL * i + 2019201949LL * j) % 2019201997LL;
            edges[idx] = {w, i - 1, j - 1};
            idx++;
        }
    }

    sort (edges.begin(), edges.end(), [](Edge &a, Edge &b) {return b.w > a.w;});

    /*
    for (auto e : edges) {
        cout << e.a << " " << e.b << " " << e.w << endl;
    }
    */

    DSU dsu; 
    dsu.setup(n);

    vector<int> lens; 
    for (int i = 0; i < edges.size(); i++) {
        if (!dsu.same(edges[i].a, edges[i].b)) {
            dsu.unite(edges[i].a, edges[i].b);
            lens.push_back(edges[i].w);
        }
    }

    //print(lens);

    // smallest k are grouped
    cout << lens[n - k] << endl;

    return 0;
}
