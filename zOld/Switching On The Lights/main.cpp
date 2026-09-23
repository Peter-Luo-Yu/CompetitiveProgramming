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

int n;
vector<vector<bool>> vis;

void dfs (vector<vector<bool>> &reach, int r, int c) {
    if (r < 1 || c < 1 || r > n || c > n || reach[r][c]) return;

    reach[r][c] = true;

    if (r + 1 <= n && vis[r + 1][c]) {
        dfs (reach, r + 1, c);
    }
    if (c + 1 <= n && vis[r][c + 1]) {
        dfs (reach, r, c + 1);
    }
    if (r - 1 >= 1 && vis[r - 1][c]) {
        dfs (reach, r - 1, c);
    }
    if (c - 1 >= 1 && vis[r][c - 1]) {
        dfs (reach, r, c - 1);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    int m; cin >> n >> m;

    vis = vector<vector<bool>> (n + 1, vector<bool> (n + 1));
    map<pair<int, int>, vector<pair<int, int>>> mp;

    for (int i = 0; i < m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        mp[{a, b}].push_back({c, d});
    }

    /*
    for (auto x : mp) {
        cout << x.first.first << " " << x.first.second << " --\n";
        printP(x.second);
        space;
    }*/

    vis[1][1] = true;

    vector<vector<bool>> reach (n + 1, vector<bool> (n + 1));

    int ans = 1;

    while (true) {
        reach = vector<vector<bool>> (n + 1, vector<bool> (n + 1));

        dfs (reach, 1, 1);

        //cout << "before: " << endl; print2d(reach); space;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (reach[i][j]) {
                    for (auto k : mp[{i, j}]) {
                        //cout << k.first << " " << k.second << endl;
                        
                        vis[k.first][k.second] = true;
                    }
                }
            }
        }

        reach = vector<vector<bool>> (n + 1, vector<bool> (n + 1));

        int cnt = 0;
        dfs (reach, 1, 1);

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (vis[i][j]) {
                    cnt++;
                }
            }
        }

        //cout << "vis: " << endl; print2d(vis); space;
        //cout << "after: " << endl; print2d(reach); space; space;

        if (cnt == ans) break;
        ans = cnt;
    
    }

    cout << ans << endl;
    
    return 0;
}
