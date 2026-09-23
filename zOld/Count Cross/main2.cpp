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

void dfs (vector<vector<char>> grid, vector<vector<bool>> &vis, int r, int c) {
    if (r < 2 || c < 2 || r > 2 * n || c > 2 * m || vis[r][c] == true || grid[r][c] == '#') {
        return;
    }
    vis[r][c] = true;

    dfs (grid, vis, r + 1, c);
    dfs (grid, vis, r - 1, c);
    dfs (grid, vis, r, c + 1);
    dfs (grid, vis, r, c - 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);

    // n by n grid, m cows, k roads
    int k; cin >> n >> m >> k;

    vector<vector<int>> roads;
    for (int i = 0; i < n; i++) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        //r1--,c1--,r2--,c2--;

        roads.push_back({r1, c1, r2, c2});
        //roads.push_back({r2, c2, r1, c1});
    }

    vector<vector<int>> cows;
    for (int i = 0; i < m; i++) {
        int r, c; cin >> r >> c; r *= 2, c *= 2;
        cows.push_back({r, c});
    }
    
    // grid starts at (2, 2)
    vector<vector<char>> grid (2*n + 1, vector<char> (2*m + 1, '.'));
    for (int i = 0; i < roads.size(); i++) {
        int x1 = roads[i][0], y1 = roads[i][1], x2 = roads[i][2], y2 = roads[i][3];
        x1 *= 2, y1 *= 2, x2 *= 2, y2 *= 2;

        //cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl; 

        if (x1 == x2) {
            if (y1 > y2) {
                grid[x1][y2+1] = '#';
            } 
            else if (y1 < y2) {
                grid[x1][y1+1] = '#';
            }
        }
        else if (y1 == y2) {
            if (x1 > x2) {
                grid[x2+1][y1] = '#';
            }
            else if (x1 < x2) {
                grid[x1+1][y1] = '#';
            }

        }
    }

    //print2d(grid);

    set<pair<int, int>> st;

    for (int i = 0; i < cows.size(); i++) {
        vector<vector<bool>> vis (2*n + 1, vector<bool> (2*m + 1, false));

        int curX = cows[i][0], curY = cows[i][1];
        dfs (grid, vis, curX, curY);
        
        //print2d(vis);

        for (int j = 0; j < cows.size(); j++) {
            if (j != i) {
                int otherX = cows[j][0], otherY = cows[j][1];

                if (!vis[otherX][otherY]) {
                    //cout << "insert: " << i << " " << j << endl;
                    
                    st.insert({i, j});
                    st.insert({j, i});
                }
            }
        }

        //space;
    }

    cout << st.size() / 2 << endl;

    return 0;
}
