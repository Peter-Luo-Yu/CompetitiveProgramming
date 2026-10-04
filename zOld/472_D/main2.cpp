#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

struct Edge {
    int w, u, v;

    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

struct AdjEdge {
    int to, w;
};

struct DSU {
    int n;
    vector<int> parent, sz;

    void setup(int x) {
        n = x;
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    vector<Edge> edges;
    edges.reserve(1LL * n * (n - 1) / 2);

    bool failed = false;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            if (i == j && arr[i][j] != 0)
                failed = true;

            if (arr[i][j] != arr[j][i])
                failed = true;

            if (i != j && arr[i][j] > 0)
                edges.push_back({arr[i][j], i, j});
        }
    }

    if (failed) {
        cout << "NO\n";
        return 0;
    }

    sort(edges.begin(), edges.end());

    DSU dsu;
    dsu.setup(n);

    vector<vector<AdjEdge>> adj(n);

    for (const Edge &e : edges) {
        if (!dsu.same(e.u, e.v)) {
            dsu.unite(e.u, e.v);
            adj[e.u].push_back({e.v, e.w});
            adj[e.v].push_back({e.u, e.w});
        }
    }

    bool works = true;

    for (int s = 0; s < n && works; s++) {

        vector<ll> dist(n, -1);
        queue<int> q;

        dist[s] = 0;
        q.push(s);

        int visited = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            visited++;

            for (const AdjEdge &e : adj[v]) {
                if (dist[e.to] != -1) continue;

                dist[e.to] = dist[v] + e.w;
                q.push(e.to);
            }
        }

        if (visited != n) {
            works = false;
            break;
        }

        for (int i = 0; i < n; i++) {
            if (dist[i] != arr[s][i]) {
                works = false;
                break;
            }
        }
    }

    cout << (works ? "YES" : "NO") << endl;

    return 0;
}