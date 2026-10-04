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

int CCidx = 0;

void dfs (int s, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &CC) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        dfs(u, adj, vis, CC);
    }

    CC[s] = CCidx;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n >> x >> y;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--;
        }

        vector<vector<int>> adj (n);

        for (int i = 0; i < n - x; i++) {
            adj[arr[i]].push_back(arr[i + x]);
            adj[arr[i + x]].push_back(arr[i]);
        }
        for (int i = 0; i < n - y; i++) {
            adj[arr[i]].push_back(arr[i + y]);
            adj[arr[i + y]].push_back(arr[i]);
        }

        //printG(adj);
        vector<bool> vis(n);
        vector<int> CC(n);
        CCidx = 0;
        for (int i = 0; i < n; i++) {
            dfs(i, adj, vis, CC);
            CCidx++;
        }

        //print(CC);

        bool sorted = true;
        for (int i = 1; i <= n; i++) {
            //cout << i << " " << arr[i - 1] + 1 << endl;
            if (arr[i - 1] + 1 != i) {
                sorted = false;
            }
        }
        if (sorted) {
            cout << "YES" << endl;
            continue;
        }

        bool failed = false;
        for (int i = 0; i < n; i++) { // check if each node is in it's own CC
            if (CC[i] != CC[arr[i]]) {
                failed = true;
            }
        }

        if (failed) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

        //space;
    }


    return 0;
}
