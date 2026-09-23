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

int n, m; 
vector<vector<char>> grid;
vector<vector<bool>> vis;

void dfs (int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '#'|| vis[r][c]) return;
    vis[r][c] = true;

    //cout << "vis: " << r << " " << c << endl;

    dfs (r + 1, c);
    dfs (r - 1, c);
    dfs (r, c + 1);
    dfs (r, c - 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;

    grid = vector<vector<char>> (n, vector<char> (m));
    vis = vector<vector<bool>> (n, vector<bool> (m));

    int r1, c1; cin >> r1 >> c1; r1--, c1--;
    int r2, c2; cin >> r2 >> c2; r2--, c2--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    dfs(r1, c1);
    
    if (vis[r2][c2]) {
        cout << "NOT SAFE" << endl;
    } else {
        cout << "SAFE" << endl;
    }


    return 0;
}
