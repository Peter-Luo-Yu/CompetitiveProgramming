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

    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);

    ll n, t; cin >> n >> t;

    vector<vector<ll>> grid (n, vector<ll> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<ll>> dist (n, vector<ll> (n, 1e18));

    // 3 poss: go 3 in all direction, hop like a knight, or go up-down-up = nets 1 up 
    vector<ll> dx = {0, 0, -3, 3, 1, -1, 1, -1, 2, -2, 2, -2, 0, 0, -1, 1};
    vector<ll> dy = {-3, 3, 0, 0, 2, 2, -2, -2, 1, 1, -1, -1, -1, 1, 0, 0};

    // distance, {r, c};
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        ll cur = pq.top().first;
        ll cr = pq.top().second.first, cc = pq.top().second.second;
        pq.pop();

        if (cur > dist[cr][cc]) continue;

        for (int i = 0; i < 16; i++) {
            ll nr = cr + dx[i], nc = cc + dy[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

            if (dist[cr][cc] + 3 * t + grid[nr][nc] < dist[nr][nc]) {
                dist[nr][nc] = dist[cr][cc] + grid[nr][nc] + 3 * t;
                pq.push({dist[nr][nc], {nr, nc}});
            }
        }
    }

    //print2d(dist);

    ll ans = dist[n - 1][n - 1]; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == 1e18) continue;
            
            ll manhattan = (n - 1 - i) + (n - 1 - j);
            if (manhattan < 3) {
                ans = min(ans, dist[i][j] + manhattan * t);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
