#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {if (arr[i][j] == 1e9) {cout << "- "; } else {cout << arr[i][j] << " ";}} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "---------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<char>> grid (n, vector<char> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    //print2d(grid);

    vector<vector<int>> Adist (n, vector<int> (m, 1e9));
    vector<vector<bool>> vis (n, vector<bool> (m));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                q.push({i, j});
                Adist[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || grid[nx][ny] == '#') {
                continue;
            }

            if (Adist[cx][cy] + 1 < Adist[nx][ny]) {
                Adist[nx][ny] = Adist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }


    vector<vector<int>> Mdist (n, vector<int> (m, 1e9));
    vis = vector<vector<bool>> (n, vector<bool> (m));
    q = queue<pair<int, int>> ();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                Mdist[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || grid[nx][ny] == '#') {
                continue;
            }

            if (Mdist[cx][cy] + 1 < Mdist[nx][ny]) {
                Mdist[nx][ny] = Mdist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }


    vector<vector<int>> Pdist (n, vector<int> (m, 1e9)); // path dist
    vector<vector<pair<int, int>>> parent (n, vector<pair<int, int>> (m, {-1, -1}));

    vis = vector<vector<bool>> (n, vector<bool> (m));
    q = queue<pair<int, int>> ();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                q.push({i, j});
                Pdist[i][j] = 0;
                vis[i][j] = true;
                parent[i][j] = {i, j};
            }
        }
    }

    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 ||
                grid[nx][ny] == '#' || Mdist[nx][ny] <= Adist[nx][ny]) {
                continue;
            }

            if (Pdist[cx][cy] + 1 < Pdist[nx][ny]) {
                Pdist[nx][ny] = Pdist[cx][cy] + 1;
                parent[nx][ny] = {cx, cy};
                q.push({nx, ny});
            }
        }
    }

    /*
    print2d(Adist);
    space;
    print2d(Mdist);
    space;
    print2d(Pdist);
    space;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "(" << parent[i][j].first << ", " << parent[i][j].second << ") ";
        }
        cout << endl;
    }
    space;
    */

    bool found = false;
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Pdist[i][j] != 1e9 && (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                sx = i; 
                sy = j; 
                found = true;
            }
        }
    }


    if (found) {
        vector<pair<int, int>> ans;

        while (grid[sx][sy] != 'A') {
            ans.push_back({sx, sy});

            pair<int, int> next = parent[sx][sy];
            sx = next.first;
            sy = next.second;
        }

        ans.push_back({sx, sy});

        reverse(ans.begin(), ans.end());
        
        //printP(ans);

        vector<char> finalans;

        for (int i = 1; i < ans.size(); i++) {
            if (ans[i].first == ans[i - 1].first) {
                if (ans[i].second < ans[i - 1].second) {
                    finalans.push_back('L');
                } else {
                    finalans.push_back('R');
                }
            }
            else if (ans[i].second == ans[i - 1].second) {
                if (ans[i].first < ans[i - 1].first) {
                    finalans.push_back('U');
                } else {
                    finalans.push_back('D');
                }
            }
        }

        cout << "YES" << endl;
        cout << finalans.size() << endl;
        for (int i = 0; i < finalans.size(); i++) {
            cout << finalans[i];
        }
        cout << endl;


    } else {
        cout << "NO" << endl;
    }


    return 0;
}
