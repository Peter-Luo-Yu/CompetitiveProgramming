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

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        vector<vector<int>> arr (n, vector<int> (m));
        map<int, vector<pair<int, int>>> pos;   // color - positions
        //map<int, int> mp; // color - # of sets needed

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int color; cin >> color;
                arr[i][j] = color;
                pos[color].push_back({i, j});
            }
        }

        int ans = 0;
        int Max = 1;

        for (auto p : pos) {
            vector<pair<int, int>> coords = p.second;
            
            //cout << p.first << endl; printP(coords);

            bool touch = false;

            for (int i = 0; i < coords.size(); i++) {
                int x = coords[i].first, y = coords[i].second;

                if (x - 1 >= 0 && arr[x - 1][y] == p.first) {
                    touch = true;
                }
                if (x + 1 < n && arr[x + 1][y] == p.first) {
                    touch = true;
                }
                if (y - 1 >= 0 && arr[x][y - 1] == p.first) {
                    touch = true;
                }
                if (y + 1 < m && arr[x][y + 1] == p.first) {
                    touch = true;
                }
            }

            if (touch) {
                ans += 2; Max = 2;
            } else {
                ans += 1;
            }
            
        }

        cout << ans - Max << endl;
        

        //space;
    }


    return 0;
}
