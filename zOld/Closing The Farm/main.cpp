#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(arr) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
void dfs(int s, vector<vector<int>>& adj, vector<bool>& vis) {
    if (vis[s]) return;

    vis[s] = true;

    for (auto x : adj[s]) {
        dfs (x, adj, vis);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj (n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> barns;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        barns.push_back(--val);
    }

    //print(barns);

    vector<bool> vis (n);
    for (int i = 0; i < n; i++) {
        int check = barns[0];
        dfs(check, adj, vis);

        /*
        cout << "matrix: " << endl;
        
        for (int i = 0; i < adj.size(); i++) {
            cout << "i: " << i << " | ";
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
        */

        for (int j = 0; j < adj.size(); j++) {
            if (j == check) {
                adj[j] = {};
                continue;
            }
            for (int k = 0; k < adj[j].size(); k++) {
                if (adj[j][k] == check) {
                    adj[j].erase(adj[j].begin() + k);
                    break;
                }
            }
        }

        bool failed = false;
        for (int i = 0; i < barns.size(); i++) {
            if (!vis[barns[i]]) {
                failed = true;
            }
        }

        if (failed) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

        barns.erase(barns.begin());

        //print(vis);
        vis = vector<bool> (n, false);
        //cout << endl;
        
    }
    

    return 0;
}