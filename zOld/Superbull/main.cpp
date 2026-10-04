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

    bool same (int a, int b) {
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

    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);

    int n; cin >> n;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> edges;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int w = arr[i] ^ arr[j];
            edges.push_back({w, i, j});
        }
    }

    sort (edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    //print2d(edges);

    DSU dsu;
    dsu.setup(n);

    ll ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        int w = edges[i][0], a = edges[i][1], b = edges[i][2];
        if (!dsu.same(a, b)) {
            dsu.unite(a, b);
            ans += w;
        }
    }

    cout << ans << endl;

    return 0;
}
