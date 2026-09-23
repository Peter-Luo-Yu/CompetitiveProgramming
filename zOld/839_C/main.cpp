#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

ld ans = 0;

// 0: 0 is not visited, 1: prob, 2: path len
void dfs (vector<vector<int>> &adj, vector<vector<ld>> &vis, int s) {
    vis[s][0] = 1;

    int possible_moves = 0;

    for (auto x : adj[s]) {
        if (vis[x][0] == 0) possible_moves++;
    }

    if (possible_moves == 0) {
        ans += vis[s][1] * vis[s][2];
    } else {
        ld prob = vis[s][1] / possible_moves;

        for (auto x : adj[s]) {
            if (vis[x][0] == 0) {

                vis[x][1] = prob;
                vis[x][2] = vis[s][2] + 1;

                dfs (adj, vis, x);
            
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<vector<int>> adj (n);

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //printG(adj);

    vector<vector<ld>> vis (n, vector<ld> (3));
    vis[0][0] = 1; vis[0][1] = 1; vis[0][2] = 0;
    
    dfs (adj, vis, 0);


    cout << fixed << setprecision(6) << ans << endl;
    
    return 0;
}
