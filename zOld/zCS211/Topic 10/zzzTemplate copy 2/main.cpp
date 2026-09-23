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

void dfs (vector<vector<int>> &arr, vector<vector<bool>> &vis, int color, int r, int c) {
    if (r < 0 || c < 0 || r > arr.size() - 1 || c > arr.size() - 1 || arr[r][c] != color || vis[r][c]) {
        return;
    }

    vis[r][c] = true;

    dfs (arr, vis, color, r - 1, c);
    dfs (arr, vis, color, r, c - 1);
    dfs (arr, vis, color, r + 1, c);
    dfs (arr, vis, color, r, c + 1);
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<vector<int>> arr (n, vector<int> (n));

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                arr[i][j] = s[j] - '0' - 1;
            }
        }

        vector<int> ans (6);

        //print2d(arr); space;

        vector<vector<bool>> pvis (n, vector<bool> (n));
        int moves = 0;
        // important, first flood fill the origin (top left) -- not just pvis[0][0] = true;
        dfs(arr, pvis, arr[0][0], 0, 0);

        while (true) {
            bool allvis = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!pvis[i][j]) {
                        allvis = false;
                    }
                }
            }

            if (allvis) break;


            int Max = -1;
            int color = 0; 
            vector<vector<bool>> temp (n, vector<bool> (n));

            for (int k = 0; k < 6; k++) { // k for kolor
                
                vector<vector<bool>> vis (n, vector<bool> (n));

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (pvis[i][j] == true) {
                            if (i + 1 < n && !pvis[i + 1][j]) {
                                dfs(arr, vis, k, i + 1, j);
                            }
                            if (j + 1 < n && !pvis[i][j + 1]) {
                                dfs(arr, vis, k, i, j + 1);
                            }
                            if (i - 1 >= 0 && !pvis[i - 1][j]) {
                                dfs(arr, vis, k, i - 1, j);
                            }
                            if (j - 1 >= 0 && !pvis[i][j - 1]) {
                                dfs(arr, vis, k, i, j - 1);
                            }
                           
                        }
                    }
                }

                
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (vis[i][j]) {
                            cnt++;
                        }
                    }
                }

                if (cnt > Max) {
                    Max = cnt;
                    color = k;
                    temp = vis;
                }

                //cout << "k: " << k << " ------" << endl;
                //print2d(vis); space;

            }

            // First expand pvis with temp
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (temp[i][j]) pvis[i][j] = true;

            // Then expand pvis further with same-color neighbors
            //dfs(arr, pvis, color, 0, 0);

            // NOW recolor everything in pvis
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (pvis[i][j]) arr[i][j] = color;

            ans[color]++;
            moves++;
            //cout << "Max: " << Max << " best color: " << color << endl;
            //print2d(arr); space;
            
            

        }

        cout << moves << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
        
            
    }
    
    return 0;
}