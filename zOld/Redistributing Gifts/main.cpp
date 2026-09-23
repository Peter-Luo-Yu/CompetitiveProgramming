#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define printM(mp) for (auto x : mp) {cout << x.first << " " << x.second << "\n";}

int n; int idx = 0;
stack<int> stk;
vector<vector<int>> adj;
vector<vector<int>> adj2;
vector<bool> vis;
vector<int> SCC;

void dfs (int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto x : adj[s]) {
        dfs (x);
    }
    stk.push(s);
}

void dfs2 (int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto x : adj2[s]) {
        dfs2 (x);
    }
    SCC[s] = idx;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    adj = vector<vector<int>> (n);
    adj2 = vector<vector<int>> (n);
    vis = vector<bool> (n);
    SCC = vector<int> (n);

    vector<vector<int>> arr (n, vector<int> (n));
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) { 
            cin >> arr[i][j];
            arr[i][j]--;
        }
    }

    for (int i = 0; i < n; i++) {   // row = destination
        for (int j = 0; j < n; j++) { // col = source;
            if (arr[i][j] == i) {
                adj[arr[i][j]].push_back(i);
                break;
            }
            else {
                adj[arr[i][j]].push_back(i);
            }
        }
    }

    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            adj2[adj[i][j]].push_back(i);
        }
    }


    for (int i = 0; i < n; i++) {
        dfs (i);
    }
    vis = vector<bool> (n);
    
    while (!stk.empty()) {
        int val = stk.top();
        stk.pop();

        if (!vis[val]) {
            dfs2 (val);
            idx++;
        }
    }
    
    //print2d(arr);
    //cout << "SCC: "; print(SCC);
    //cout << "--------" << endl;

    vis = vector<bool> (n); // tracks vis components
    vector<bool> taken (n); // tracks which cow got what

    vector<int> ans (n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (SCC[i] == SCC[arr[i][j]]) {
                ans[i] = arr[i][j] + 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
