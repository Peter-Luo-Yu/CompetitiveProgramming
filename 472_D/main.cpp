#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printWG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << "(" << adj[i][j].first << "," << adj[i][j].second << ") ";} cout << endl;}
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




int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<vector<int>> arr (n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> edges;

    bool failed = false;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j && arr[i][j] != 0) {
                failed = true;
                continue;
            }
            if (arr[i][j] != arr[j][i]) {
                failed = true;
                continue;
            }
            
            if (arr[i][j] > 0) {
                edges.push_back({arr[i][j], i, j});
            }
        }
    }

    if (failed) {
        cout << "NO" << endl;
        return 0;
    }

    //print2d(edges);

    sort (edges.begin(), edges.end());

    DSU dsu; dsu.setup(n);
    vector<vector<pair<int, int>>> adj (n);

    for (int i = 0; i < edges.size(); i++) {
        if (!dsu.same(edges[i][1], edges[i][2])) {
            dsu.unite(edges[i][1], edges[i][2]);
            adj[edges[i][1]].push_back({edges[i][2], edges[i][0]});
            adj[edges[i][2]].push_back({edges[i][1], edges[i][0]});
        }
    }

    //printWG(adj);

    bool works = true;

    // Run BFS from every single node to check all-pairs distances
    for (int i = 0; i < n; i++) {
        vector<long long> dist(n, -1);
        queue<int> q;

        dist[i] = 0;
        q.push(i);

        int visited_count = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited_count++;

            for (auto& edge : adj[cur]) {
                int next_node = edge.first;
                int weight = edge.second;

                if (dist[next_node] == -1) { // Not visited
                    dist[next_node] = dist[cur] + weight;
                    q.push(next_node);
                }
            }
        }

        // 1. Check if the tree is fully connected
        if (visited_count != n) {
            works = false;
            break;
        }

        // 2. Validate that the calculated tree distances match the input matrix
        for (int j = 0; j < n; j++) {
            if (dist[j] != arr[i][j]) {
                works = false;
                break;
            }
        }

        if (!works) break;
    }

    cout << (works ? "YES" : "NO") << endl;


    return 0;
}
