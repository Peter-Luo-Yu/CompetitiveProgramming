#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int n;
vector<vector<char>> arr;
vector<vector<bool>> vis;
vector<vector<int>> SCC;
int idx = 1;


void dfs (int r, int c, char color) {
    if (r < 0 || c < 0 || r >= n || c >= n || vis[r][c] || arr[r][c] != color) {
        return;
    }

    vis[r][c] = true;
    if (arr[r][c] == '#') {
        SCC[r][c] = idx;
    }


    dfs (r + 1, c, color);
    dfs (r - 1, c, color);
    dfs (r, c + 1, color);
    dfs (r, c - 1, color);
    
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    cin >> n;
    arr = vector<vector<char>> (n, vector<char> (n));
    vis = vector<vector<bool>> (n, vector<bool> (n));
    SCC = vector<vector<int>> (n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    //print2d(arr);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                dfs (i, j, arr[i][j]);
                idx++;
            }
        }
    }

    //print2d(SCC);

    vector<pair<int, int>> areas (n * n);

    for (int i = 0; i < n; i++) {
        areas[i].second = i; 
        for (int j = 0; j < n; j++) {
            areas[SCC[i][j]].first++;
        }
    }
    sort (areas.begin(), areas.end());
    
    //printP(areas);

    int maxArea = 0, maxId = 0;
    for (int i = areas.size() - 1; i >= 0; i--) {
        if (areas[i].second != 0) {
            maxArea = areas[i].first;
            maxId = areas[i].second;
            break;
        }
    }

    int maxPeri = 0, shared = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (SCC[i][j] == maxId) {
                if (i - 1 >= 0 && SCC[i - 1][j] == maxId) {
                    shared++;
                }
                if (i + 1 < n && SCC[i + 1][j] == maxId) {
                    shared++;
                }
                if (j - 1 >= 0 && SCC[i][j - 1] == maxId) {
                    shared++;
                }
                if (j + 1 < n && SCC[i][j + 1] == maxId) {
                    shared++;
                }
            }
        }
    }
    
    maxPeri = 4 * maxArea - shared;

    cout << maxArea << " " << maxPeri << endl;

    
    return 0;
}
