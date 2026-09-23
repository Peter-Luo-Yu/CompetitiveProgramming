#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

void dfs (int s, vector<vector<int>>& adj, vector<bool>& vis) {
    if (vis[s]) return;

    vis[s] = true;

    for (auto x : adj[s]) {
        dfs (x, adj, vis);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n; cin >> n;
    vector<int> a (n), b (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int l = 0, r = 1e9;
    int ans = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        //cout << "r: " << mid << endl;

        vector<vector<int>> adj (n);

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ll dist = (a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]);
                //cout << "dist: " << dist << endl;
                if (mid >= dist) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis (n);

        dfs (0, adj, vis);

        //printG(adj);
        //print(vis);

        bool failed = false;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) failed = true;
        }

        if (failed) {
            l = mid + 1;
        } else {
            ans = min (ans, mid);
            r = mid - 1;
        }
        
        
    }

    cout << ans << endl;
    

    

    return 0;
}