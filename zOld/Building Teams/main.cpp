#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}

bool failed = false;

void dfs (int s, vector<vector<int>>& adj, vector<int>& team, int parent) { 
    
    // if visited, check if the colors are differnet, if differnet then we good.
    if (team[s] != 0) {
        if (team[s] == team[parent]) {
            failed = true;
        }
        //cout << "on: " << s << " parent: " << parent << " teamS: " << team[s] << " team parent: " << team[parent] << " returned! " << endl;
        return;
    }

    if (parent == -1) {
        team[s] = 1;
    } else if (team[parent] == 1) {
        team[s] = 2;
    } else if (team[parent] == 2) { 
        team[s] = 1;
    } else {
        failed = true;
    }

    //cout << "on: " << s << " parent: " << parent << " teamS: " << team[s] << " team parent: " << team[parent] << endl;

    for (auto x : adj[s]) {
        dfs(x, adj, team, s);
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj (n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //print2d(adj);

    vector<int> team (n);
    for (int i = 0; i < n; i++) {
        dfs (i, adj, team, -1);
    }

    
    if (failed) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        print(team);
    }

    return 0;
}