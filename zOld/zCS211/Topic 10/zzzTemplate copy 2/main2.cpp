#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        vector<int> cnt(6, 0); // count for colors 0-5

        auto get_size = [&](int newColor) {
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            queue<pair<int,int>> q;

            int curColor = grid[0][0] - '0';

            q.push({0,0});
            vis[0][0] = true;
            int sz = 1;

            while (!q.empty()) {
                auto [x,y] = q.front(); q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (vis[nx][ny]) continue;

                    int col = grid[nx][ny] - '0';

                    // can expand if same as current region OR target color
                    if (col == curColor || col == newColor) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                        sz++;
                    }
                }
            }
            return sz;
        };

        auto flood = [&](int newColor) {
            int curColor = grid[0][0] - '0';

            vector<vector<bool>> vis(n, vector<bool>(n, false));
            queue<pair<int,int>> q;

            q.push({0,0});
            vis[0][0] = true;

            vector<pair<int,int>> cells;
            cells.push_back({0,0});

            while (!q.empty()) {
                auto [x,y] = q.front(); q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (vis[nx][ny]) continue;

                    if (grid[nx][ny] - '0' == curColor) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                        cells.push_back({nx, ny});
                    }
                }
            }

            // repaint region
            for (auto [x,y] : cells) {
                grid[x][y] = char('0' + newColor);
            }
        };

        int moves = 0;

        while (true) {
            int total = get_size(grid[0][0] - '0');
            if (total == n * n) break;

            int bestColor = 0;
            int bestSize = -1;

            for (int c = 0; c < 6; c++) {
                int sz = get_size(c);
                if (sz > bestSize) {
                    bestSize = sz;
                    bestColor = c;
                }
            }

            flood(bestColor);
            cnt[bestColor]++;
            moves++;
        }

        cout << moves << "\n";
        for (int i = 0; i < 6; i++) {
            cout << cnt[i] << (i + 1 < 6 ? ' ' : '\n');
        }
    }

    return 0;
}