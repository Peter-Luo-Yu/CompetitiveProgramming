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

    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);

    ll B, E, P; cin >> B >> E >> P;
    int n, m; cin >> n >> m;

    vector<vector<ll>> adj(n);
    vector<bool> vis(n);

    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //printG(adj);

    // bessie starts at 1, elsie starts at 2
    vector<ll> Bdist (n, 1e16), Edist (n, 1e16), Pdist(n, 1e16);

    
    queue<int> q;
    q.push(0);
    Bdist[0] = 0;
    vis[0] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : adj[cur]) {
            if (vis[next]) continue;

            if (Bdist[cur] + B < Bdist[next]) {
                Bdist[next] = Bdist[cur] + B;
                q.push(next);
            }
            
        }

    }

   
    vis = vector<bool> (n);
    q = queue<int> ();
    q.push(1);
    Edist[1] = 0;
    vis[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : adj[cur]) {
            if (vis[next]) continue;

            if (Edist[cur] + E < Edist[next]) {
                Edist[next] = Edist[cur] + E;
                q.push(next);
            }
            
        }

    }


    vis = vector<bool> (n);
    q = queue<int> ();
    q.push(n - 1);
    Pdist[n - 1] = 0;
    vis[n - 1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : adj[cur]) {
            if (vis[next]) continue;

            if (Pdist[cur] + P < Pdist[next]) {
                Pdist[next] = Pdist[cur] + P;
                q.push(next);
            }
            
        }

    }

    //print(Bdist); print(Edist); print(Pdist);

    ll ans = 1e18;

    for (int i = 0; i < n; i++) {
        ans = min (ans, Bdist[i] + Edist[i] + Pdist[i]);
    }

    cout << ans << endl;


    return 0;
}
