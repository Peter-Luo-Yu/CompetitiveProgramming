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
vector<int> SCC, arr, ans;
vector<bool> vis;
stack<int> stk;
int ccidx = 0;

void dfs1 (int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        dfs1 (u);
    }

    stk.push(s);
}

void dfs2 (int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : radj[s]) {
        dfs2 (u);
    }

    SCC[s] = ccidx;
}

int solvedfs (int s) {
    if (ans[s] != 0) return ans[s];

    return ans[s] = solvedfs(arr[s]) + 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    arr = SCC = vector<int> (n);
    adj = radj = vector<vector<int>> (n);
    vis = vector<bool> (n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; arr[i]--;
        adj[i].push_back(arr[i]);
        radj[arr[i]].push_back(i);
    }

    //printG(adj); printG(radj);

    for (int i = 0; i < n; i++) {
        dfs1(i);
    }
    vis = vector<bool> (n);
    while (!stk.empty()) {
        int val = stk.top();
        stk.pop();
        if (!vis[val]) {
            dfs2(val);
        }
        ccidx++;
    }

    //print(SCC);

    ans = vector<int> (n);
    map<int, int> freq;

    for (int i = 0; i < SCC.size(); i++) {
        freq[SCC[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (freq[SCC[i]] > 1) {
            ans[i] = freq[SCC[i]];
        }
        else {
            if (arr[i] == i) {
                ans[i] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        solvedfs(i);
    }
    
    print(ans);


    return 0;
}
