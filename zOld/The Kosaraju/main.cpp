#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}


stack<int> stake;
vector<int> SCC (5);
int idx = 0;

void dfs (vector<vector<int>>& adj, vector<bool>& vis, int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto x : adj[s]) {
        dfs (adj, vis, x);
    }

    cout << "pushing: " << s << endl;
    stake.push(s);
}

void dfs2 (vector<vector<int>>& adj, vector<bool>& vis, int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto x : adj[s]) {
        dfs2 (adj, vis, x);
    }

    SCC[s] = idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> adj = {
    {1},  // 0 -> 1
    {2},  // 1 -> 2
    {0, 3},  // 2 -> 0, 3
    {4},  // 3 -> 4
    {3}   // 4 -> 3
    };
    vector<bool> vis1 (5);

    printG(adj);

    vector<vector<int>> adj2 (5);

    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {

            adj2[adj[i][j]].push_back(i);
                     
        }
    }

    printG(adj2);

    for (int i = 0; i < 5; i++) {
        dfs (adj, vis1, i);
    }

    vis1 = vector<bool> (5);

    while (!stake.empty()) {
        int val = stake.top();
        stake.pop();
        cout << "val: " << val << endl;
        //if (!vis1[val]) {
            dfs2 (adj2, vis1, val);
            idx++;
        //}
    }

    print(SCC);

    return 0;
}