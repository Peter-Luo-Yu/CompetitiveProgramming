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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<char>> arr (n, vector<char> (m));

    queue<pair<int, int>> q;
    vector<vector<bool>> vis (n, vector<bool> (m));
    vector<vector<int>> dist (n, vector<int> (m, 1e9));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (m, {-1, -1}));

    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            arr[i][j] = c;

            if (arr[i][j] == 'A') {
                sx = i; sy = j;
            }
            if (arr[i][j] == 'B') {
                ex = i; ey = j;
            }
        }
    }

    //print2d(arr);

    dist[sx][sy] = 0;

    q.push({sx, sy});
    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        //cout << "cur: " << curx << " " << cury << endl;

        if (vis[curx][cury]) continue;
        vis[curx][cury] = true;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i], ny = cury + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != '#') {
                //cout << "next: " << nx << " " << ny << endl;

                if (dist[curx][cury] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[curx][cury] + 1;
                    parent[nx][ny] = {curx, cury};
                    q.push({nx, ny});
                    
                }

            }
        }
    }


    if (dist[ex][ey] == 1e9) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << dist[ex][ey] << endl;

        vector<pair<int, int>> path;
        pair<int, int> cur = {ex, ey};
        while (cur.first != -1 || cur.second != -1) {
            path.push_back(cur);
            cur = parent[cur.first][cur.second];
        }

        reverse(path.begin(), path.end());

        vector<char> ans;
        for (int i = 1; i < path.size(); i++) {
            if (path[i].first == path[i - 1].first) { // equal i = equal row
                if (path[i].second > path[i - 1].second) { 
                    ans.push_back('R');
                } else {
                    ans.push_back('L');
                }
            }
            else if (path[i].second == path[i - 1].second) { // equal j = equal row
                if (path[i].first > path[i - 1].first) { 
                    ans.push_back('D');
                } else {
                    ans.push_back('U');
                }
            }
        }
        
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << endl;
    }

    /*
    print2d(dist);
    
    for (int i = 0; i < parent.size(); i++) {
        for (int j = 0; j < parent[i].size(); j++) {
            cout << "(" << parent[i][j].first << " " << parent[i][j].second << ") ";
        }
        cout << endl;
    }
    */


    return 0;
}
