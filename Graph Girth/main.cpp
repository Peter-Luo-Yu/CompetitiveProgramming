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

    int ans = 1e9;

    for (int i = 0; i < n; i++) {
        vector<int> dist (n, 1e9), parent(n, -1);
        vector<bool> vis (n);
        queue<int> q;

        dist[i] = 0;
        q.push(i);
        vis[i] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto next : adj[cur]) {
                if (!vis[next]) {
                    dist[next] = dist[cur] + 1;
                    parent[next] = cur;
                    q.push(next);
                    vis[next] = true;
                } else if (parent[cur] != next) {
                    ans = min (ans, dist[cur] + dist[next] + 1);
                }
            }
        }
    }
    
    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }


    return 0;
}
