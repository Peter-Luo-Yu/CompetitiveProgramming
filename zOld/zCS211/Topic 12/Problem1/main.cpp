#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printWG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (auto x : adj[i]) {cout << "(" << x.first << " " << x.second << ") ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, m, t; cin >> n >> m >> t;

    vector<vector<pair<int, int>>> adj (n);
    for (int i = 0; i < m; i++) {
        ll a, b, w; cin >> a >> b >> w;

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    //printWG(adj);

    ll s, e; cin >> s >> e; // start end

    vector<bool> speedray (n); // no AI detection
    vector<ll> spiderDist (n, 1e18);
    priority_queue<pair<ll, ll>> pq; // dist - node;
    vector<bool> vis (n);

    ll k; cin >> k;
    for (int i = 0; i < k; i++) {
        ll node; cin >> node;
        speedray[node] = true;  // mark the spider intersection

        spiderDist[node] = 0;
        pq.push({0, node});
    }

    while (!pq.empty()) { // mini Dijkstra to know how close EACH node is to a spider
        ll cur = pq.top().second;
        pq.pop();

        if (vis[cur] == true) continue;
        vis[cur] = true;

        for (auto u : adj[cur]) {
            ll next = u.first, w = u.second;

            if (spiderDist[cur] + w < spiderDist[next]) {
                spiderDist[next] = spiderDist[cur] + w;
                pq.push({-spiderDist[next], next});
            }
        }
    }

    //print(spiderDist);

    ll l = 0, r = 1e9; 
    ll ans = 0;

    while (l <= r) {
        ll mid = (l + r) / 2; // D: min dist to a spider

        //cout << "MID: " << mid << endl;

        bool failed = false;

        pq = priority_queue<pair<ll, ll>> (); // dist - node;
        vis = vector<bool> (n, false);
        vector<ll> distance (n, 1e18);

        if (spiderDist[s] < mid) {
            failed = true;

        } else {
        
            distance[s] = 0;
            pq.push({0, s});

            while (!pq.empty()) {
                ll cur = pq.top().second; 
                pq.pop();

                if (vis[cur]) continue;
                vis[cur] = true;

                for (auto u : adj[cur]) {
                    ll next = u.first, w = u.second;

                    if (spiderDist[next] < mid) continue;

                    if (distance[cur] + w < distance[next]) {
                        distance[next] = distance[cur] + w;
                        pq.push({-distance[next], next});
                    }
                }
            }
        }

        //print(distance);

        //cout << "end: " << distance[e] << endl;

        if (distance[e] > t) {
            failed = true;
        }

        if (!failed) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }

    }

    cout << ans << endl;
    




    return 0;
}
