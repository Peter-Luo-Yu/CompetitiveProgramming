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

int n; 
vector<vector<int>> adj, radj;
vector<bool> vis;

vector<int> SCC;
int ccidx = 0;

stack<int> stk;

void dfs1(int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        dfs1(u);
    }

    stk.push(s);
}

void dfs2(int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : radj[s]) {
        dfs2(u);
    }

    SCC[s] = ccidx;

}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    cin >> n;
    adj = vector<vector<int>> (n);
    radj = vector<vector<int>> (n);
    vis = vector<bool> (n);
    SCC = vector<int> (n);

    for (int i = 0; i < n; i++) {
        int b; cin >> b; b--;

        adj[i].push_back(b);
        radj[b].push_back(i);
    }

    //printG(adj);

    for (int i = 0; i < n; i++) {
        dfs1(i);
    }

    vis = vector<bool> (n);

    while (!stk.empty()) {
        int val = stk.top();
        stk.pop();

        if (!vis[val]) {
            dfs2(val);
            ccidx++;
        }
    }

    //print(SCC);

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[SCC[i]]++;
    }

    //printP(freq);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (freq[SCC[i]] > 1) {
            ans++;
        } 
        else {
            if (adj[i][0] == i) {
                ans++;
            }
        }

    }

    cout << ans << endl;


    return 0;
}
