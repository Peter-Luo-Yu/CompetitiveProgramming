#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}


int n, m;
vector<vector<char>> arr;
vector<vector<bool>> vis;
vector<vector<int>> CC;
int idx = 0;

// color is the wall or not
void dfs (int r, int c, int color) {    
    if (r < 0 || c < 0 || r >= n || c >= m || 
        arr[r][c] != color || vis[r][c]) {
        return;
    }
    vis[r][c] = true;
    CC[r][c] = idx;
    dfs (r + 1, c, color);
    dfs (r - 1, c, color);
    dfs (r, c + 1, color);
    dfs (r, c - 1, color);
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    arr = vector<vector<char>> (n, vector<char> (m));
    vis = vector<vector<bool>> (n, vector<bool> (m));
    CC = vector<vector<int>> (n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    //print2d(arr);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                dfs (i, j, arr[i][j]);
                idx++;
                if (arr[i][j] == '.') {
                    ans++;
                }
            }
        }
    }

    //print2d(CC);

    cout << ans << endl;
    
    return 0;
}
