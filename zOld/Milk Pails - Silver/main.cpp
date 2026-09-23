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

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, k, m;
    cin >> x >> y >> k >> m;

    vector<vector<vector<int>>> dp (x + 1, vector<vector<int>> (y + 1, vector<int> (k + 1, 1e9)));
    vector<vector<vector<bool>>> vis (x + 1, vector<vector<bool>> (y + 1, vector<bool> (k + 1)));

    queue<vector<int>> q;
    q.push({0,0,0}); 
    dp[0][0][0] = 0;
    vis[0][0][0] = true;

    while (!q.empty()) {
        vector<int> prev = q.front();
        q.pop();

        int pX = prev[0];
        int pY = prev[1];
        int pK = prev[2];

        //cout << "visiting: " << pX << " " << pY << " " << pK << endl;

        if (pK == k) {
            continue;
        }
        
        // 1. fill X
        int nX = pX, nY = pY, nK = pK;
        nX = x; 
        nK++;
        if (!vis[nX][nY][nK]) {
            vis[nX][nY][nK] = true;
            dp[nX][nY][nK] = nX + nY;
            q.push({nX, nY, nK});
        }

        // 2. fill Y
        nX = pX, nY = pY, nK = pK;
        nY = y;
        nK++;
        if (!vis[nX][nY][nK]) {
            vis[nX][nY][nK] = true;
            dp[nX][nY][nK] = nX + nY;
            q.push({nX, nY, nK});
        }

        // 3. empty X
        nX = pX, nY = pY, nK = pK;
        nX = 0;
        nK++;
        if (!vis[nX][nY][nK]) {
            vis[nX][nY][nK] = true;
            dp[nX][nY][nK] = nX + nY;
            q.push({nX, nY, nK});
        }

        // 4. empty Y
        nX = pX, nY = pY, nK = pK;
        nY = 0;
        nK++;
        if (!vis[nX][nY][nK]) {
            vis[nX][nY][nK] = true;
            dp[nX][nY][nK] = nX + nY;
            q.push({nX, nY, nK});
        }

        // 5. dump X into Y
        nX = pX, nY = pY, nK = pK;
        int amt = min (nX, y - nY);
        nX -= amt;
        nY += amt;
        nK++;
        if (!vis[nX][nY][nK]) {
            vis[nX][nY][nK] = true;
            dp[nX][nY][nK] = nX + nY;
            q.push({nX, nY, nK});
        }

        // 6. dump Y into X
        nX = pX, nY = pY, nK = pK;
        amt = min (nY, x - nX);
        nY -= amt;
        nX += amt;
        nK++;
        if (!vis[nX][nY][nK]) {
            vis[nX][nY][nK] = true;
            dp[nX][nY][nK] = nX + nY;
            q.push({nX, nY, nK});
        }
    }

    int ans = 1e9;

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            for (int k = 0; k < dp[i][j].size(); k++) {
                if (dp[i][j][k] != 1e9) {
                    //cout << dp[i][j][k] << " ";
                    ans = min (ans, abs(m - dp[i][j][k]));
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
