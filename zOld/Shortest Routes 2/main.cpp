#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, m, q; cin >> n >> m >> q;

    vector<vector<ll>> adj (n, vector<ll> (n, 1e18));
    for (int i = 0; i < n; i++) {adj[i][i] = 0;}

    vector<vector<ll>> distance(n, vector<ll> (n));

    for (int i = 0; i < m; i++) {
        ll a, b, w; cin >> a >> b >> w; a--, b--;

        adj[a][b] = min(adj[a][b], w);
        adj[b][a] = min(adj[a][b], w);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) distance[i][j] = 0;
            else if (adj[i][j] > 0) distance[i][j] = adj[i][j];
            else distance[i][j] = 1e18;
        }
    }

    //print2d(distance);

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        a--, b--;

        (distance[a][b] == 1e18) ? (cout << -1 << endl) : (cout << distance[a][b] << endl);
    }
    

    
    
    return 0;
}
