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

int n, m;
vector<vector<int>> arr;
vector<vector<int>> way;
vector<vector<bool>> vis;

void dfs (int r, int c, int diff) {
    if (r < 0 || c < 0 || r > n - 1 || c > m - 1 ||
        vis[r][c]) {
        return;
    }

    vis[r][c] = true;

    if (r - 1 >= 0 && abs(arr[r - 1][c] - arr[r][c]) <= diff) {
        dfs (r - 1, c, diff);
    }
    if (r + 1 < n && abs(arr[r + 1][c] - arr[r][c]) <= diff) {
        dfs (r + 1, c, diff);
    }
    if (c - 1 >= 0 && abs(arr[r][c - 1] - arr[r][c]) <= diff) {
        dfs (r, c - 1, diff);
    }
    if (c + 1 >= 0 && abs(arr[r][c + 1] - arr[r][c]) <= diff) {
        dfs (r, c + 1, diff);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);

    cin >> n >> m;
    arr = vector<vector<int>> (n, vector<int> (m));
    way = vector<vector<int>> (n, vector<int> (m));
    vis = vector<vector<bool>> (n, vector<bool> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> way[i][j];
            if (way[i][j] == 1) {
                total++;
            }
        }
    }

    //print2d(arr); print2d(way); cout << total << endl;

    int l = 0, r = 1e9;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;

        vis = vector<vector<bool>> (n, vector<bool> (m));

        bool done = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (way[i][j] == 1) {
                    dfs (i, j, mid);
                    done = true;
                    break;
                }
            }
            if (done) {
                break;
            }
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (way[i][j] == 1 && vis[i][j]) {
                    cur++;
                }
            }
        }

        //cout << "mid: " << mid << " cur: " << cur << endl;
    
        if (cur == total) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
