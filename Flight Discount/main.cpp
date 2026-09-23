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

    int n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n), rev(n);

    vector<ll> dist1(n, 1e18), distN(n, 1e18);

    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w; a--, b--;
        adj[a].push_back({b, w});
        rev[b].push_back({a, w});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
    dist1[0] = 0;

    while (!pq.empty()) {
        ll cur = pq.top().second;
        ll curdist = pq.top().first;
        pq.pop();

        if (curdist != dist1[cur]) continue;

        for (auto next : adj[cur]) {
            if (curdist + next.second < dist1[next.first]) {
                dist1[next.first] = curdist + next.second;
                pq.push({dist1[next.first], next.first});
            }
        }
    }
    
    //print(dist); 

    pq = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> ();
    pq.push({0, n - 1});
    distN[n - 1] = 0;

    while (!pq.empty()) {
        ll cur = pq.top().second;
        ll curdist = pq.top().first;
        pq.pop();

        if (curdist != distN[cur]) continue;

        for (auto next : rev[cur]) {
            if (curdist + next.second < distN[next.first]) {
                distN[next.first] = curdist + next.second;
                pq.push({distN[next.first], next.first});
            }
        }
    }

    ll ans = 1e18;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int a = i, b = adj[i][j].first, w = adj[i][j].second;
            
            if (dist1[a] != 1e18 && distN[b] != 1e18) {
                ans = min(ans, dist1[a] + distN[b] + w/2);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
