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

// NOT LEGIT :( -- I DON'T GET HOW IT WORKS, AND THE DEGREES OF A GRAPH.

vector<vector<int>> adj;
vector<vector<int>> rev;
vector<bool> vis;
vector<int> order, component;

void dfs (int s) {
    if (vis[s]) return;
    vis[s] = true;

    // s is current pos, x is next pos. "down the line"
    for (auto x : adj[s]) {
        dfs (x);
    }
    
    order.push_back(s);
}   

void dfs2 (int s) {
    if (vis[s]) return;
    vis[s] = true;

    component.push_back(s);

    // s is current pos, x is next pos. "down the line"
    for (auto x : rev[s]) {
        dfs2 (x);
    }
    
}

void dfs3 (vector<vector<int>> &adj, vector<bool> &vis, int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto x : adj[s]) {
        dfs3 (adj, vis, x);
    }
}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        
        order.clear();
        
        vis = vector<bool> (n);
        adj = vector<vector<int>> (n);
        rev = vector<vector<int>> (n);

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b; a--, b--;

            adj[a].push_back(b);
            rev[b].push_back(a);
        }

        //cout << "adj: " << endl; printG(adj); space; cout << "rev adj: " << endl; printG(rev); space;

        for (int i = 0; i < n; i++) {
            dfs(i);
        }

        //cout << "SCC: "; print(SCC); cout << "sccidx: " << sccidx << endl; space;

        vis = vector<bool> (n);
        reverse(order.begin(), order.end());


        vector<vector<int>> sccadj (n);
        vector<int> roots(n);
        vector<int> root_nodes; 

        for (auto v : order) {
            if (!vis[v]) {
                component.clear();

                dfs2(v);

                int root = component[0];
                
                for (auto u : component) {
                    roots[u] = root;
                }

                root_nodes.push_back(root);

                //cout << "components: "; print(component);

            }
        }

        //cout << "roots: "; print(roots);

        for (int v = 0; v < n; v++) {
            for (auto u : adj[v]) {
                int root_v = roots[v];
                int root_u = roots[u];

                //cout << "u: " << root_u << " v: " << root_v << endl;

                if (root_u != root_v) {
                    sccadj[root_v].push_back(root_u);
                }
            }
        }

        //printG(sccadj);

        vector<int> indeg(n,0);

        for (int v = 0; v < n; v++) {
            for (auto u : sccadj[v]) {
                indeg[u]++;
            }
        }

        int ans = 0;

        for (auto r : root_nodes) {
            if (indeg[r] == 0) ans++;
        }

        cout << ans << endl;
        
    }


    
    return 0;
}
