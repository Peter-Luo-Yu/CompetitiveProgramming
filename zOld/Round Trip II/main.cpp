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

int n, m;
vector<vector<int>> adj;
vector<int> vis, parent;
int start = -1, cyclend = -1;

void dfs (int s) {
    vis[s] = 1;

    for (auto u : adj[s]) {
        if (start != -1) return;

        if (vis[u] == 0) {
            parent[u] = s;
            dfs(u);
        }
        else if (vis[u] == 1) { //u has been seen before
            start = u; // then start is u
            cyclend = s;
            return;
        }
    }

    vis[s] = 2;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;

    adj = vector<vector<int>> (n);
    vis = parent = vector<int> (n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs(i);
            //if (start == -1) break;
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
       //print(parent);

        vector<int> cycle;
        int cur = cyclend;
        while (cur != start) {
            cycle.push_back(cur);
            cur = parent[cur];
        }
        cycle.push_back(start);

        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() + 1 << endl;

        for (auto c : cycle) {
            cout << c + 1 << " ";
        }
        cout << cycle[0] + 1 << endl;
    }

    return 0;
}
