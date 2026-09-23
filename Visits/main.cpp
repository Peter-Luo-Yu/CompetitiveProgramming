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
vector<int> a, w, SCC;
vector<bool> vis;
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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    adj = radj = vector<vector<int>> (n);
    a = w = SCC = vector<int> (n);
    vis = vector<bool> (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> w[i]; a[i]--;
        adj[i].push_back(a[i]);
        radj[a[i]].push_back(i);
    }
    
    for (int i = 0; i < n; i++) {
        dfs1(i);
    }
    vis = vector<bool> (n);
    while (!stk.empty()) {
        int val = stk.top(); 
        stk.pop();
        //if (!vis[val]) {
            dfs2(val);   
            
        //}
        ccidx++;
    }

    //print(SCC);
    
    map<int, int> freq;
    map<int, vector<int>> cycles;
    for (int i = 0; i < n; i++) {
        freq[SCC[i]]++;
        cycles[SCC[i]].push_back(i);
    }

    vis = vector<bool> (n);
    ll ans = 0;
    for (int i = 0; i < n; i++) { // in this problem there are no self loops
        if (vis[i]) continue;

        if (freq[SCC[i]] > 1) { // if cycle: you must sack one
            int Min = 1e9;
            ll sum = 0;

            for (int j = 0; j < cycles[SCC[i]].size(); j++) {
                sum += w[cycles[SCC[i]][j]];
                Min = min (Min, w[cycles[SCC[i]][j]]);

                vis[cycles[SCC[i]][j]] = true;
            }

            sum -= Min;
            ans += sum;
        }
        else {  // no cycle, all cows can get the moo off
            ans += w[i];
        }
    }

    cout << ans << endl;

    return 0;
}
