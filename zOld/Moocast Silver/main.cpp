#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(arr) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

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
    
    vector<vector<int>> data;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        int x, y, p; cin >> x >> y >> p;
        temp = {x , y, p};
        data.push_back(temp);
    }
    
    vector<vector<int>> adj (n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int dist = (data[i][0] - data[j][0]) * (data[i][0] - data[j][0])
                          +(data[i][1] - data[j][1]) * (data[i][1] - data[j][1]);

                if (dist <= data[i][2] * data[i][2]) {
                    adj[i].push_back(j);
                }
            }
        }
    }

    //printG(adj);

    vector<bool> vis (n);
    int Max = -1;
    for (int i = 0; i < n; i++) {
        dfs(i, adj, vis);

        //print(vis);

        int count = 0;
        for (int j = 0; j < vis.size(); j++) {
            if (vis[j]) count++;
        }

        Max = max (Max, count);

        vis = vector<bool> (n);
    }   

    cout << Max << endl;

    return 0;
}