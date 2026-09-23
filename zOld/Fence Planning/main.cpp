#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(arr) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

ll maxX = -1e9, minX = 1e9;
ll maxY = -1e9, minY = 1e9;
ll n, m; 
vector<pair<ll,ll>> pos;
vector<vector<ll>> adj;
vector<bool> vis;

void dfs (int s) {
    if (vis[s]) return;

    vis[s] = true;

    maxX = max (maxX, pos[s].first);
    maxY = max (maxY, pos[s].second);
    minX = min (minX, pos[s].first);
    minY = min (minY, pos[s].second);

    for (auto x : adj[s]) {
        dfs (x);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    cin >> n >> m;
    
    pos = vector<pair<ll,ll>> (n);
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        pos[i] = {x, y};
    }

    adj = vector<vector<ll>> (n);
    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //printG(adj);
    vis = vector<bool> (n);

    ll minPeri = 1e10;

    for (int i = 0; i < n; i++) {
        dfs (i);

        minPeri = min (minPeri, abs(2LL * ((maxX - minX) + (maxY - minY))));

        //cout << "x: " << minX << " " << maxX << " y: " << minY << " " << maxY << " p: " << minPeri << endl;

        maxX = -1e9, minX = 1e9;
        maxY = -1e9, minY = 1e9;
    }
    cout << minPeri << endl;

    return 0;
}