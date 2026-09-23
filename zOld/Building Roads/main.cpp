#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';


void dfs (int s, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& tracker, int mark) {
    if (vis[s]) return;
    vis[s] = true;
    tracker[s] = mark;

    for (int i = 0; i < adj[s].size(); i++) {
        dfs(adj[s][i], adj, vis, tracker, mark);
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj (n);
    vector<bool> vis (n);
    vector<int> tracker (n, -1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int mark = 1;
    for (int i = 0; i < n; i++) {
        dfs (i, adj, vis, tracker, mark);
        mark++;
    }

    //print(tracker);

    map<int, int> mp;   // first occurence for each mark
    for (int i = 0; i < tracker.size(); i++) {
        if (mp[tracker[i]] == 0){
            mp[tracker[i]] = i + 1;
        }
    }

    vector<int> ans;
    for (auto i : mp) {
        ans.push_back(i.first);
    }
    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << " " << ans[i+1] << endl;
    }

    /*
    for (int i = 0; i < adj.size(); i++) {
        cout << "i: " << i << " | ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    */
    

    return 0;
}