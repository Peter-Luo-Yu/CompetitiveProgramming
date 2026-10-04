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

void dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &sz, int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        if (!vis[u]) { // important: because u could be the parent s in the adj list
            dfs(adj, vis, sz, u);
            sz[s] += sz[u];
        }
    }
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr (n);

        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<vector<int>> adj (n);

        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b; a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> vis (n);
        vector<int> sz (n, 1);

        dfs (adj, vis, sz, 0);

        //print(sz);

        ll ans = 0;

        for (int i = 0; i < n; i++) { // node i is getting taken out
            if ((ll) sqrt(arr[i]) * (ll) (sqrt(arr[i])) == arr[i]) {

                vector<int> sizes;

                for (auto c : adj[i]) {
                    if (sz[c] < sz[i]) { // size of child is gauranteed to be smaller than size of parent
                        sizes.push_back(sz[c]);
                    }
                }

                if (n - sz[i] > 0) {
                    sizes.push_back(n - sz[i]);
                }

                //print(sizes);

                ll sum = 0;
                ll pair = 0;
                ll triple = 0;

                for (int j = 0; j < sizes.size(); j++) {
                    triple += pair * sizes[j];
                    pair += sum * sizes[j];
                    sum += sizes[j];
                }

                ans += (pair + triple);
            }
        }

        cout << ans << endl;

        //space;
    }


    return 0;
}
