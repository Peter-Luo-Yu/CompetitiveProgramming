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

int n;
vector<vector<pair<int, int>>> parent;
vector<vector<int>> sz, arr;

void setup() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            parent[i][j] = {i, j};
            sz[i][j] = 1;
        }
    }
}

pair<int, int> find (int i, int j) {
    while (parent[i][j].first != i || parent[i][j].second != j) {
        pair<int, int> temp = parent[i][j];
        i = temp.first; j = temp.second;
    }
    return {i, j}; 
}

void unite (int ai, int aj, int bi, int bj) {
    pair<int, int> a = find(ai, aj);
    pair<int, int> b = find(bi, bj);

    if (a == b) return;

    if (sz[a.first][a.second] < sz[b.first][b.second]) {
        swap(a, b);
    }

    sz[a.first][a.second] += sz[b.first][b.second];
    parent[b.first][b.second] = a;
}

bool bsta(int mid) {
    setup();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int nx = i, ny = j;

            vector<int> dx = {1, -1, 0, 0};
            vector<int> dy = {0, 0, 1, -1};

            for (int k = 0; k < 4; k++) {
                nx += dx[k]; ny += dy[k];

                if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || 
                    abs(arr[i][j] - arr[nx][ny]) > mid) continue;
                
                unite(i, j, nx, ny);
            }
        }
    }

    int threshold = (n * n) / 2 + ((n * n) % 2 != 0);

    int best = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            best = max (best, sz[i][j]);
        }
    }

    return best >= threshold;

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);

    cin >> n;

    parent = vector<vector<pair<int, int>>> (n, vector<pair<int, int>> (n));
    arr = sz = vector<vector<int>> (n, vector<int> (n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int l = 0, r = 1e9;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (bsta(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;


    return 0;
}
