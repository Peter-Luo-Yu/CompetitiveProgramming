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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<int>> arr (n, vector<int> (m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
    x0--; y0--; x1--; y1--;

    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {1, 0, -1, 1, -1, 1, 0, -1};


    vector<vector<vector<int>>> vis (n, vector<vector<int>> (m, vector<int> (3, -1)));

    // 0 - prev is smaller, 1 - prev is bigger
    
    //cout << vis[x1][y1][0] << " " << vis[x1][y1][1] << endl;

    vis[x0][y0][2] = 0;


    queue<vector<int>> q;

    q.push({x0, y0, 2});

    while (!q.empty()) {
        vector<int> temp = q.front();
        q.pop();

        int x = temp[0], y = temp[1];

        for (int i = 0; i < 8; i++) {
            int nextX = x + dx[i], nextY = y + dy[i];

            if (nextX < 0 || nextY < 0 || nextX > n - 1 || nextY > m - 1) {
                continue;
            }

            int change = -1; 

            if (temp[2] == 2) {
                if (arr[nextX][nextY] > arr[x][y]) {
                    change = 0;
                } 
                else if (arr[nextX][nextY] < arr[x][y]) {
                    change = 1;
                } else {
                    continue;
                }
            }
            else if (temp[2] == 0) {    // prev is smaller -> cur is bigger -> next must be smaller
                if (arr[nextX][nextY] < arr[x][y]) {
                    change = 1;
                } else {
                    continue;
                }
            }
            else if (temp[2] == 1) {
                if (arr[nextX][nextY] > arr[x][y]) {
                    change = 0;
                } else {
                    continue;
                }
            }

            //cout << "nX: " << nextX << " nY: " << nextY << " change: " << change << endl;

            if (vis[nextX][nextY][change] > -1 || change == -1) {
                continue;
            }
                

            vis[nextX][nextY][change] = vis[x][y][temp[2]] + 1;

            q.push({nextX, nextY, change});
        }


        //cout << vis[x1][y1][0] << " " << vis[x1][y1][1] << endl;

    }


    if (x0 == x1 && y0 == y1) {
        cout << 0 << endl;
    }
    else if (vis[x1][y1][0] == -1 && vis[x1][y1][1] == -1) {
        cout << -1 << endl;
    }
    else {
        int ans = 1e9;

        if (vis[x1][y1][0] > -1) {
            ans = min (ans, vis[x1][y1][0]);
        } 
        if (vis[x1][y1][1] > -1) {
            ans = min (ans, vis[x1][y1][1]);
        }

        cout << ans << endl;
    }
    
    return 0;
}
