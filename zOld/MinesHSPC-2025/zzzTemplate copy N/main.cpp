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


int ccidx = 0;
vector<int> CC;

void dfs (vector<vector<int>> &adj, vector<bool> &vis, int s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto x : adj[s]) {
        dfs (adj, vis, x);
    }

    CC[s] = ccidx;

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<vector<int>> adj (n);
    vector<bool> vis (n);
    CC = vector<int> (n);

    for (int i = 0; i < n; i++) {
        int val; cin >> val; val--;
        adj[i].push_back(val);
    }

    //printG(adj);

    for (int i = 0; i < n; i++) {
        dfs(adj, vis, i);
        ccidx++;
    }

    //print(CC);

    map<int, int> mp;

    for (int i = 0; i < CC.size(); i++) {
        mp[CC[i]]++;
    }


    int ans = 0;
    for (auto x : mp) {
        if (x.second > 1) {
            ans += x.second % 2;
        }
    }

    cout << ans << endl;
    
    return 0;
}
