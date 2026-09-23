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

ll MOD = 1e9 + 7;

ll n;
vector<ll> topo;
vector<vector<ll>> adj;
vector<bool> vis;

void dfs (ll s) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto u : adj[s]) dfs(u);
    topo.push_back(s);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll m; cin >> n >> m;
    adj = vector<vector<ll>>(n);
    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
    }
    vis = vector<bool> (n);

    for (int i = 0; i < n; i++) {
        dfs (i);
    }

    reverse(topo.begin(), topo.end());
    //print(topo);

    vector<ll> dp (n);
    dp[0] = 1;

    for (ll i = 0; i < n; i++) {
        ll cur = topo[i];
        for (ll next : adj[cur]) {
            dp[next] = (dp[next] + dp[cur]) % MOD;
        }
    }

    //print(dp);

    cout << dp[n - 1] << endl;

    return 0;
}
