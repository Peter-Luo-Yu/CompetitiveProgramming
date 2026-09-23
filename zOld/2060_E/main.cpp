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

int fidx = 0, gidx = 0;

void dfs1 (vector<vector<int>> &adj, vector<bool> &vis, int s, vector<int> &CCF) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto x : adj[s]) {
        dfs1 (adj, vis, x, CCF);
    }

    CCF[s] = fidx;
}

void dfs2 (vector<vector<int>> &adj, vector<bool> &vis, int s, vector<int> &CCG) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto x : adj[s]) {
        dfs2 (adj, vis, x, CCG);
    }

    CCG[s] = gidx;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n, m1, m2; 
        cin >> n >> m1 >> m2;

        vector<vector<int>> adjG(n);
        vector<pair<int, int>> temp;

        // can only make changes to F to match G

        for (int i = 0; i < m1; i++) {
            int a, b; cin >> a >> b; a--, b--;
            temp.push_back({a, b});
        }

        for (int i = 0; i < m2; i++) {
            int a, b; cin >> a >> b; a--, b--;

            adjG[a].push_back(b);
            adjG[b].push_back(a);
        }

        fidx = 0; gidx = 0;
        vector<int> CCF(n), CCG(n);
        vector<bool> vis(n);

        for (int i = 0; i < adjG.size(); i++) {
            dfs2 (adjG, vis, i, CCG);
            gidx++;
        }

        //printG(adjG); print(CCG); space;


        // remove every edge (F) that connects different component in G

        vector<vector<int>> cleanF (n);
        int ans = 0;
        for (int i = 0; i < m1; i++) {
            int a = temp[i].first;
            int b = temp[i].second;

            //cout << "a: " << a << " b: " << b << endl;

            if (CCG[a] != CCG[b]) {
                ans++;
            } else {
                cleanF[a].push_back(b);
                cleanF[b].push_back(a);
            }
        }


        // how to link: we first gaurantee no path in F if there isn't one in G
        // NOW: Think of each component in $G$ as a bucket. 
        // Inside a single bucket, $F$ might be split into several pieces. 
        // If bucket #1 has 3 pieces of $F$, you need 2 edges to connect them. If bucket #2 has 1 piece of $F$, you need 0 edges.

        vis = vector<bool> (n);
        for (int i = 0; i < cleanF.size(); i++) {
            dfs1(cleanF, vis, i, CCF);
            fidx++;
        }

        //printG(cleanF); print(CCF);

        set<int> numF, numG;

        for (int i = 0; i < CCF.size(); i++) {
            numF.insert(CCF[i]);
        }
        for (int i = 0; i < CCG.size(); i++) {
            numG.insert(CCG[i]);
        }

        ans += (numF.size() - numG.size());

        cout << ans << endl;

        //space; space;
    }
    
    return 0;
}
