#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

void dfs (int s, vector<vector<int>>& adj, vector<bool>& vis) {
    if (vis[s]) return;
    vis[s] = true;  
    //cout << "vis: " << s << endl;
    for (auto x : adj[s]) {
        //cout << "going to: " << x << endl;
        dfs (x, adj, vis);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj (n);
    vector<vector<int>> radj (n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--,b--;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    //printG(adj); cout << endl;
    //printG(radj);

    vector<bool> vis (n);

    dfs (0, adj, vis);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "NO" << endl;
            cout << 0 << " " << i << endl;
            return 0;
        }
    }

    vis = vector<bool> (n);
    dfs (0, radj, vis);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "NO" << endl;
            cout << i << " " << 0 << endl;
            return 0;
        } 
    }

    cout << "YES" << endl;

    return 0;
}