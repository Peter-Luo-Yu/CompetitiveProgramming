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

void dfs (int r, int c, char color) {
    if (r < 0 || c < 0 || r > n - 1 || c > m - 1 ||
        vis[r][c] == true || arr[r][c] == '#') {
            return;
    }
    vis[r][c] = true;

    dfs (r + 1, c, color);
    dfs (r - 1, c, color);
    dfs (r , c + 1, color);
    dfs (r , c - 1, color);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        cin >> n >> m;

        arr = vector<vector<char>> (n, vector<char> (m));
        vis = vector<vector<bool>> (n, vector<bool> (m));

        int numG = 0, numB = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 'G') {
                    numG++;
                } 
                if (arr[i][j] == 'B') {
                    numB++;
                }
            }
        }
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 'B') {
                    if (i - 1 >= 0 && arr[i - 1][j] == '.') {
                        arr[i - 1][j] = '#';
                    }
                    if (i + 1 < n && arr[i + 1][j] == '.') {
                        arr[i + 1][j] = '#';
                    }
                    if (j - 1 >= 0 && arr[i][j - 1] == '.') {
                        arr[i][j - 1] = '#';
                    }
                    if (j + 1 < m && arr[i][j + 1] == '.') {
                        arr[i][j + 1] = '#';
                    }
                }
            }
        }

        //print2d(arr);

        /*
        bool goodleave = true;
        bool badleave = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis = vector<vector<bool>> (n, vector<bool> (m));

                if (arr[i][j] == 'G') {
                    dfs(i, j, 'G');
                    if (!vis[n - 1][m - 1]) {
                        goodleave = false;
                    }
                }
                else if (arr[i][j] == 'B') {
                    dfs(i, j, 'B');
                    if (vis[n - 1][m - 1]) {
                        badleave = true;
                    }
                }

            }
        } 

        if (goodleave && !badleave) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        } 
        */

        // To speed things up, you can just do a single DFS from the end
        // and check how many good and bad people are connnected.

        int goodcnt = 0, badcnt = 0;

        dfs (n - 1, m - 1, '.');
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j]) {
                    if (arr[i][j] == 'G') {
                        goodcnt++;
                    } 
                    if (arr[i][j] == 'B') {
                        badcnt++;
                    }
                }
            }
        }

        if (goodcnt == numG && badcnt == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
       
        
        //cout << "---" << endl;

    }
    
    return 0;
}
