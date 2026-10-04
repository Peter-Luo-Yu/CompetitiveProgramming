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

    int find (int x) {
        while (x != parent[x]) x = parent[x];
        return x;
    }

    bool same (int a, int b) {
        return find(a) == find(b);
    }

    void unite (int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap (a, b);
        sz[a] += sz[b];
        parent[b] = a;
    }
};

struct Edge {
    int w, a, b;
};


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);

    int A, B, n, m; cin >> A >> B >> n >> m;
    vector<int> vert (n + 1), hori (m + 1);
    for (int i = 0; i < n; i++) cin >> vert[i];
    for (int i = 0; i < m; i++) cin >> hori[i];

    vert[n] = A;
    hori[m] = B;

    sort (vert.begin(), vert.end());
    sort (hori.begin(), hori.end());

    //print(vert); print(hori);

    vector<Edge> edges;

    // holding x const, doing all vertical connections
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = (n + 1) * j + i, next = (n + 1) * (j + 1) + i;
            int weight = (i == 0 ? vert[i] : vert[i] - vert[i - 1]);
            
            //cout << cur << " " << next << " " << weight << endl;
            Edge edge;
            edge.w = weight;
            edge.a = cur;
            edge.b = next;

            edges.push_back(edge);
        }
    }

    for (int j = 0; j <= m; j++) {
        for (int i = 0; i < n; i++) {
            int cur = (n + 1) * j + i, next = (n + 1) * j + (i + 1);
            int weight = (j == 0 ? hori[j] : hori[j] - hori[j - 1]);
            
            //cout << cur << " " << next << " " << weight << endl;
            Edge edge;
            edge.w = weight;
            edge.a = cur;
            edge.b = next;

            edges.push_back(edge);
        }
    }

    sort (edges.begin(), edges.end(), [](Edge &a, Edge &b) {return a.w < b.w;});

    //for (auto x : edges) cout << x.w << " " << x.a << " " << x.b << endl;
    
    DSU dsu;
    ll nodes = (n + 1) * (m + 1);
    dsu.setup(nodes);
    
    ll ans = 0;
    
    for (int i = 0; i < edges.size(); i++) {
        if (!dsu.same(edges[i].a, edges[i].b)) {
            dsu.unite(edges[i].a, edges[i].b);
            ans += edges[i].w;
        }
    }
    
    cout << ans << endl;

    return 0;
}
