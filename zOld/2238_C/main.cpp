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

int n; 
vector<vector<int>> adj;
vector<bool> vis;
vector<int> dist, dp;

// depth, number of nodes
map<int, int> depth;
vector<int> pref;


void dfs (int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        if (!vis[u]) {
            dfs(u);
            dp[s] += dp[u];
        }
    }

    // has 2 or more children = new guild, only accounts for depth of 1
    dp[s] += pref[pref.size() - 1] - pref[dist[s] + 1];
}   



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        cin >> n;
        adj = vector<vector<int>>(n);
        vis = vector<bool> (n);
        dp = vector<int> (n, 1);
        dist = vector<int>(n, 1e9);

        depth = map<int, int> ();

        for (int i = 0; i < n - 1; i++) {
            int parent; cin >> parent; parent--;
            int child = i + 1;

            //cout << child << " " << parent << endl;

            adj[child].push_back(parent);
            adj[parent].push_back(child);
        }

        //printG(adj);

       
        // BFS for finding distance;
        queue<int> q;
        q.push({0});
        dist[0] = 0;
        vis[0] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            //cout << "cur: " << cur << endl;
            
            for (auto next : adj[cur]) {
                if (!vis[next]) {
                    vis[next] = true;
                    dist[next] = dist[cur] + 1;
                    q.push({next});
                }
            }
        }

        cout << "dist: "; print(dist);

        int Maxdepth = 0;
        for (int i = 0; i < dist.size(); i++) {
            depth[dist[i]] += 1;
            Maxdepth = max(Maxdepth, dist[i]);
        }
        //printP(depth);

        pref = vector<int> (Maxdepth + 2);
        int idx = 0;
        for (auto d : depth) {
            pref[idx + 1] = pref[idx] + (d.second >= 2);
            idx++; 
        }

        cout << "pref: "; print(pref);

        vis = vector<bool> (n);
        dfs(0);
        print(dp);



        space;
    }


    return 0;
}
