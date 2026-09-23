#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

vector<vector<int>> adj;
vector<bool> vis;
vector<int> components;

void dfs (int s, int c) {
    if (vis[s]) return;
    vis[s] = true;
    components[s] = c;
    for (auto x : adj[s]) {dfs (x,c);}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    
    while (t--) {
        int n, m; cin >> n >> m;

        adj = vector<vector<int>> (n);
        vis = vector<bool> (n);
        components = vector<int> (n);

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b; a--, b--;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        //printG(adj); cout << endl;
        
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs (i, cur++); 
            }
        }

        //cout << "components: "; print(components);

        vector<int> start (cur, 1e9), end (cur, -1e9);

        // y'all call this coordinate compression?
        for (int i = 0; i < n; i++) {
            start[components[i]] = min (start[components[i]], i);
            end[components[i]] = max (end[components[i]], i);
        }

        //cout << "start: "; print(start); cout << "end: "; print(end);

        ll ans = 2e18;

        // edge cases where start.size() and end.size() = 1 or 2
        if (start.size() == 1) { 
            // only 1 component
            cout << 0 << endl; //cout << endl; 
            continue;
        }
        if (start.size() == 2) {
            // 2 components - think on a number line you get 1 cut - max dist is one
            cout << 1 << endl; //cout << endl;
            continue;
        }
        
        // there are 2 possible cases since "he can build up to 2 paths"
        // 1) first path: 1 -> start of longest component in the middle | second path: end of longest component -> N
        // 2) ONLY 1 path: end of path containing 1 -> start of path containing N

        // the problem is the first node is gauranteed to be in the first component, but not the last in the last.
        int endIdx = components[components.size() - 1];
        //cout << "endIdx: " << endIdx << endl;

        // Case 1
        for (int i = 1; i < start.size() - 1; i++) {
            ll cost = (end[0] - start[i]) * (end[0] - start[i]) + (start[endIdx] - end[i]) * (start[endIdx] - end[i]);
            ans = min (ans, cost);
        }

        // Case 2
        ll cost = (end[0] - start[endIdx]) * (end[0] - start[endIdx]);
        ans = min (ans, cost);

        cout << ans << endl;
        //cout << endl;
    }

    return 0;
}