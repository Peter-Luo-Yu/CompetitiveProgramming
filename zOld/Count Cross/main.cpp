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

void dfs (int r, int c, vector<vector<bool>> &vis, vector<vector<int>> roads) {
    if (r >= n || c >= n || r < 0 || c < 0 || vis[r][c]) return;

    vis[r][c] = true;
    //cout << "r: " << r << " c: " << c << endl;

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
        int nR = r + dx[i], nC = c + dy[i];

        bool blocked = false;
        for (int j = 0; j < roads.size(); j++) {

            if (roads[j][0] == r && roads[j][1] == c &&
                roads[j][2] == nR && roads[j][3] == nC) {
                blocked = true;
            }
        }

        if (!blocked) {
            dfs(nR, nC, vis, roads);
        }
    }

}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);

    // n by n grid, m cows, k roads
    int m, k; cin >> n >> m >> k;

    vector<vector<int>> roads;
    for (int i = 0; i < n; i++) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        r1--,c1--,r2--,c2--;

        roads.push_back({r1, c1, r2, c2});
        roads.push_back({r2, c2, r1, c1});
    }

    //print2d(roads);space;

    vector<vector<int>> cows;
    for (int i = 0; i < m; i++) {
        int r, c; cin >> r >> c; r--, c--;

        cows.push_back({r, c});
    }

    int ans = 0;

    for (int i = 0; i < cows.size() - 1; i++) {
        for (int j = i + 1; j < cows.size(); j++) {
            
            //cout << cows[i][0] << " " << cows[i][1] << " | " << cows[j][0] << " " << cows[j][1] << endl;

            vector<vector<bool>> vis (n, vector<bool> (n));

            dfs (cows[i][0], cows[i][1], vis, roads);

            //print2d(vis); space;

            if (!vis[cows[j][0]][cows[j][1]]) {
                ans++;
            }

        }
    }

    cout << ans << endl;

    
    return 0;
}
