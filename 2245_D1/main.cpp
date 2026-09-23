
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

struct Data {
    int o, i, j; 
};

void dfs (int s, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &topo) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto u : adj[s]) dfs (u, adj, vis, topo);
    topo.push_back(s);
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        vector<int> sign (n);

        // if |a1| > |a2| edge from a1 to a2
        vector<vector<int>> adj (n);

        vector<Data> data;
        for (int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c; b--, c--;
            if (b == c) {
                if (a == 1) {
                    sign[b] = 1; // 1 for pos
                } else {
                    sign[b] = 0; // 0 for neg;
                }
            }
            else {
                Data d;
                if (a == 2) {
                    a = 0;
                }
                d.o = a;
                d.i = b;
                d.j = c;
                data.push_back(d);
            }
        }

        //cout << "sign: "; print(sign);

        // check if you failed off rip
        bool failed = false;
        for (int i = 0; i < data.size(); i++) {
            //cout << data[i].i << " " << data[i].j << " " << data[i].o << endl;

            int u = data[i].i, v = data[i].j;

            if (sign[u] == sign[v]) {
                if (sign[u] == 1 && data[i].o == 0) {
                    failed = true;
                } 
                else if (sign[u] == 0 && data[i].o == 1) {
                    failed = true;
                }
            }
            else {
                if (sign[u] == 1 && sign[v] == 0) {
                    if (data[i].o == 0) {
                        //cout << "c1" << endl;
                        adj[v].push_back(u);
                    } else {
                        //cout << "c2" << endl;
                        adj[u].push_back(v);
                    }
                }
                else if (sign[v] == 1 && sign[u] == 0) {
                    if (data[i].o == 1) {
                        //cout << "c3" << endl;
                        adj[v].push_back(u);
                    } else {
                        //cout << "c4" << endl;
                        adj[u].push_back(v);
                    }
                }
            }
        }

        //printG(adj);

        if (failed) {
            cout << "NO" << endl;
            //space;
            continue;
        }
    
        

        vector<bool> vis (n);
        vector<int> topo;

        for (int i = 0; i < n; i++) {
            dfs (i, adj, vis, topo);
        }
        reverse(topo.begin(), topo.end());

        //print(topo);
        
    
        vector<int> idx (n);
        for (int i = 0; i < n; i++) {
            idx[topo[i]] = i;
        }
        
        bool cycle = false;

        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                if (idx[i] >= idx[adj[i][j]]) {
                    cycle = true;
                }
            }
        }

        if (cycle) {
            cout << "NO" << endl;
            //space;
            continue;
        }


        int x = 1e5;
        vector<int> ans (n);
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            if (sign[topo[i]] == 0) {
                ans[topo[i]] = -x;
            } else {
                ans[topo[i]] = x;
            }
            x--;
        }

        print(ans);


        //space;
        
    }


    
    return 0;
}