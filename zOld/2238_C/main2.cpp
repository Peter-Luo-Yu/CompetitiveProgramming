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
vector<int> dist, furthest, ans;
vector<bool> vis;

void calcfurthest (int s) {
    if (vis[s]) return;
    vis[s] = true;

    /*
    if (adj[s].size() == 1 && s != 0) { 
        furthest[s] = 0;
        return;
    } */

    for (auto u : adj[s]) {
        if (!vis[u]) {
            calcfurthest(u);
            furthest[s] = max (1 + furthest[u], furthest[s]); 
        }
    }
}


void dfs (int s) {
    if (vis[s]) return;
    vis[s] = true;

    // a temp arr to store furthest dist for each child
    vector<int> temp;
    for (auto u : adj[s]) {
        if (!vis[u]) {
            dfs(u);
            ans[s] += ans[u];
            temp.push_back(furthest[u]);
        }
    }

    sort (temp.begin(), temp.end());

    ans[s] += 1;
    if (temp.size() >= 2) {
        ans[s] += (temp[temp.size() - 2] + 1);
    }
    //temp.clear();
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // you add the second furthest leaf of the child
    int t; cin >> t;
    while (t--) {
        cin >> n;
        adj = vector<vector<int>> (n);
        ans = furthest = vector<int> (n);
        dist = vector<int> (n, 1e9);
        vis = vector<bool> (n);

        for (int i = 0; i < n - 1; i++) {
            int parent; cin >> parent; parent--;
            int child = i + 1;
            adj[parent].push_back(child);
            adj[child].push_back(parent);
        }
        
        //printG(adj);

        // simple BFS from 0 to find all distances
        queue<int> q;
        q.push(0);
        vis[0] = true;
        dist[0] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto next : adj[cur]) {
                if (!vis[next]) {
                    vis[next] = true;
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
        //cout << "dist: "; print(dist);

        // compute the distance from current node to the furthest node that it is connected to.
        vis = vector<bool> (n);
        calcfurthest(0);
        //cout << "farr: "; print(furthest);

        // Now compute the ans;
        vis = vector<bool> (n);
        dfs(0);
        //cout << "ans:  "; print(ans);

        cout << ans[0] << endl;

        //space;
    }


    return 0;
}
