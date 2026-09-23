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

vector<int> SCC;
int sccidx = 0;

stack<int> stk;

void dfs (vector<vector<int>> &adj, vector<bool> &vis, int s) {
    if (vis[s]) return;

    vis[s] = true;

    // s is current pos, x is next pos. "down the line"
    for (auto x : adj[s]) {
        dfs (adj, vis, x);
    }
    stk.push(s);
}

void dfs2 (vector<vector<int>> &adj, vector<bool> &vis, int s) {
    if (vis[s]) return;

    vis[s] = true;

    // s is current pos, x is next pos. "down the line"
    for (auto x : adj[s]) {
        dfs2 (adj, vis, x);
    }
    
    SCC[s] = sccidx;
}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<vector<int>> adj (n);
        vector<vector<int>> rev (n);
        vector<bool> vis (n);
        SCC = vector<int> (n);
        sccidx = 0;

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b; a--, b--;

            adj[a].push_back(b);
            rev[b].push_back(a);
        }

        //cout << "adj: " << endl; printG(adj); space; cout << "rev adj: " << endl; printG(rev); space;

        for (int i = 0; i < n; i++) {
            dfs(adj, vis, i);
        }
        vis = vector<bool> (n);
        while (!stk.empty()) {
            int top = stk.top();
            stk.pop();

            if (!vis[top]) {
                dfs2(rev, vis, top);
                sccidx++;
            }
        }

        //cout << "SCC: "; print(SCC); cout << "sccidx: " << sccidx << endl; space;

        vector<vector<int>> sccadj (sccidx);
        map<int, vector<int>> sccmp;
                
        for (int i = 0; i < SCC.size(); i++) {
            sccmp[SCC[i]].push_back(i);
        }

        for (auto c : sccmp) {

            vis = vector<bool> (n);

            // for each vertex in CC, you need to run a DFS
            for (int i = 0; i < c.second.size(); i++) {
                dfs (adj, vis, c.second[i]);
            }

            //cout << "vis: "; print(vis);

            for (auto d : sccmp) {
                if (d.first != c.first) {
                    for (int i = 0; i < d.second.size(); i++) {
                        if (vis[d.second[i]]) {
                            sccadj[c.first].push_back(d.first);
                        }
                    }
                }
            }
        }

        //printG(sccadj);

        int ans = 0;
        vector<bool> vis2 (sccadj.size());

        for (int i = 0; i < sccadj.size(); i++) {
            if (!vis2[i]) {
                dfs(sccadj, vis2, i);
                ans++;
            }
        }

        //print(vis2);

        cout << ans << endl;
        
    }


    
    return 0;
}
