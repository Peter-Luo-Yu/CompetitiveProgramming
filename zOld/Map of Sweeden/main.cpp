#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int r, c, u;
vector<vector<char>> arr;
vector<vector<bool>> vis;
set<pair<int, int>> counter;

void dfs (int i, int j) {
    if (i < 0 || j < 0 || i > r - 1 || j > c - 1 ||
        (arr[i][j] == '.') || vis[i][j]) {
        return;
    }

    vis[i][j] = true;

    counter.insert({i, j});

    dfs (i + 1, j);
    dfs (i - 1, j);
    dfs (i, j + 1);
    dfs (i, j - 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> r >> c >> u;
    arr = vector<vector<char>> (r, vector<char> (c));
    vis = vector<vector<bool>> (r, vector<bool> (c));

    int S_r, S_c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                S_r = i; S_c = j;
            }
        }
    }

    /*
    print2d(arr);
    cout << S_r << " " << S_c << endl;

    for (auto x : counter) {
        cout << x.first << " " << x.second << endl;
    }
    */

    dfs (S_r, S_c);
    cout << counter.size() << endl;

    for (int i = 0; i < u; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        arr[a][b] = '#';

        if ((a - 1 >= 0 && vis[a - 1][b]) || (a + 1 <= r - 1 && vis[a + 1][b]) ||
            (b - 1 >= 0 && vis[a][b - 1]) || (b + 1 <= c - 1 && vis[a][b + 1])) {
            
            dfs (a, b);
        }
        cout << counter.size() << endl;
    }
    
    return 0;
}
