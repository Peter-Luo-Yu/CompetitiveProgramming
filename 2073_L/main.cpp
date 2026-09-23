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

    int r, c, n, p; cin >> r >> c >> n >> p;

    vector<vector<int>> arr (r, vector<int> (c));
    map<int, pair<int, int>> mp;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            
            if (arr[i][j] != 0) {
                mp[arr[i][j]] = {i, j};
            }
        }
    }

    /*
    for (auto x : mp) {
        cout << x.first << " | " << x.second.first << " " << x.second.second << endl;
    } */

    set<int> ans;

    int t = 0;
    for (int i = p; i > 0; i--) {
        int curX = mp[i].first, curY = mp[i].second;

        //cout << curX << " " << curY << endl;

        int neighbor;
        if (curX + 1 < r) {
            if (arr[curX + 1][curY] != 0) {
                neighbor = arr[curX + 1][curY] + t;
                if (neighbor <= n) {
                    ans.insert(neighbor);
                }
            }
        }
        if (curX - 1 >= 0) {
            if (arr[curX - 1][curY] != 0) {
                neighbor = arr[curX - 1][curY] + t;
                if (neighbor <= n) {
                    ans.insert(neighbor);
                }
            }
        }
        if (curY + 1 < c) {
            if (arr[curX][curY + 1] != 0) {
                neighbor = arr[curX][curY + 1] + t;
                if (neighbor <= n) {
                    ans.insert(neighbor);
                }
            }
        }
        if (curY - 1 >= 0) {
            if (arr[curX][curY - 1] != 0) {
                neighbor = arr[curX][curY - 1] + t;
                if (neighbor <= n) {
                    ans.insert(neighbor);
                }
            }
        }
        t++;
    }

    cout << ans.size() << "/" << n - 1 << endl;

    return 0;
}
