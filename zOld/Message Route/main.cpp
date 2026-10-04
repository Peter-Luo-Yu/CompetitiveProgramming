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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj (n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //printG(adj);

    vector<int> distance(n, 1e9), parent(n);
    vector<bool> vis (n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if (vis[node]) continue;
        vis[node] = true;

        for (auto u : adj[node]) {
            // dist cur + weight < dist target
            if (distance[node] + 1 < distance[u]) {
                parent[u] = node;

                distance[u] = distance[node] + 1;
                pq.push({distance[u], u});
            }
        }   
    }

    //print(distance);

    if (distance[n - 1] == 1e9) {
        cout << "IMPOSSIBLE" << endl;
    } 
    else {
        cout << distance[n - 1] + 1 << endl;

        vector<int> ans;
        int cur = n - 1;
        while (cur != 0) {
            ans.push_back(cur + 1);
            cur = parent[cur];
        }
        ans.push_back(cur + 1);

        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }

        cout << endl;
    }



    return 0;
}
