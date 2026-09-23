#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> amount(n);
    for (int i = 0; i < n; ++i) {
        cin >> amount[i];
    }

   
    vector<vector<pair<int, int>>> adj(n);
    vector<int> in_degree(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> v >> u >> w; 
        adj[u].push_back({v, w});
        in_degree[v]++; 
    }


    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            
            amount[v] += amount[u] * (long long)weight;

            
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    
    for (int i = 0; i < n; ++i) {
        cout << amount[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}