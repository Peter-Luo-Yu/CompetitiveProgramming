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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);

    int n; cin >> n;

    vector<pair<int, int>> arr(n + 2);
    cin >> arr[0].first >> arr[0].second >> arr[n + 1].first >> arr[n + 1].second;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // kind of coordinate compression
    map<int, vector<int>> vtoh, htov;

    for (int i = 0; i < n + 2; i++) {
        // x cor to y
        vtoh[arr[i].first].push_back(i);

        // y cor to x
        htov[arr[i].second].push_back(i);
    }

    /*
    for (auto x : vtoh) {
        cout << x.first << " | "; print(x.second);
    }
    space;
    for (auto x : htov) {
        cout << x.first << " | "; print(x.second);
    }
    */

    vector<int> dist (n + 2, 1e9);
    dist[0] = 0;
    
    
    // 0 = vert, 1 = horizontal
    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({0, 1});

    while (!q.empty()) {
        int idx = q.front().first, dir = q.front().second;
        q.pop();

        if (dir == 0) {
            int x = arr[idx].first;
            for (int y : vtoh[x]) {
                if (dist[y] == 1e9) {
                    dist[y] = dist[idx] + 1;
                    q.push({y, 1});
                }
            }
        } else {
            int y = arr[idx].second;
            for (int x : htov[y]) {
                if (dist[x] == 1e9) {
                    dist[x] = dist[idx] + 1;
                    q.push({x, 0});
                }
            }
        }
    } 

    //print(dist);

    if (dist[dist.size() - 1] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dist[dist.size() - 1] - 1 << endl;
    }

    return 0;
}
