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

void dfs (int s, vector<int>& component) {
    if (vis[s]) return;

    vis[s] = true;
    component.push_back(s);
    for (auto x : adj[s]) {
        dfs (x, component);
    }
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

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b; a--, b--;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        //printG(adj); cout << endl;
        
        vector<int> g1, gN; // the components containing 1 and N
        dfs (0, g1);

        if (vis[n-1]) {
            cout << 0 << endl;
            continue;
        }

        dfs (n-1, gN);
        sort (g1.begin(), g1.end());
        sort (gN.begin(), gN.end());

        //cout << "g1: "; print(g1); cout << "gN: "; print(gN);

        // Case 1 (one path): compute min1, shortest dist between g1 and gN
        
        int dist1 = 1e9;
        for (int i = 0; i < g1.size(); i++) {
            int idx = lower_bound(gN.begin(), gN.end(), g1[i]) - gN.begin(); // returns position of first element (in gN) GREATER THAN OR EQUAL TO g1[i];
            //cout << "idx: " << idx << endl;

            if (idx == 0) { //g1[i] less than or equal to gN[0]
                dist1 = min (dist1, abs(gN[idx] - g1[i]));
            } else if (idx == gN.size()) {  //g1[i] is strictly greater than gN[0]
                dist1 = min (dist1, abs(g1[i] - gN[idx - 1]));
            } else {
                dist1 = min (dist1, min (abs(gN[idx] - g1[i]), abs(g1[i] - gN[idx - 1])));
            }
        }
        ll min1 = (ll) dist1 * (ll) dist1;
        
        
        // Case 2 (two paths): you find the distance from an intermediate component to g1 and to gN.
        vector<vector<int>> groups;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> group;
                dfs (i, group);
                sort(group.begin(), group.end());
                groups.push_back(group);
            }
        }

        //cout << "groups: " << endl; print2d(groups);
        ll min2 = 2e18;
        for (int j = 0; j < groups.size(); j++) {
            int dist2 = 1e9, dist3 = 1e9;

            for (int i = 0; i < groups[j].size(); i++) {    // i'm holding groups[j] constant, and comparing it to g1
                int idx = lower_bound(g1.begin(), g1.end(), groups[j][i]) - g1.begin();

                if (idx == 0) { 
                    dist2 = min (dist2, abs(groups[j][i] - g1[idx]));
                } else if (idx == g1.size()) {  
                    dist2 = min (dist2, abs(g1[idx - 1] - groups[j][i]));
                } else {
                    dist2 = min (dist2, min (abs(groups[j][i] - g1[idx]), abs(g1[idx-1] - groups[j][i])));
                }
            }
            for (int i = 0; i < groups[j].size(); i++) {
                int idx = lower_bound(gN.begin(), gN.end(), groups[j][i]) - gN.begin(); 

                if (idx == 0) { 
                    dist3 = min (dist3, abs(gN[idx] - groups[j][i]));
                } else if (idx == gN.size()) {  
                    dist3 = min (dist3, abs(groups[j][i] - gN[idx - 1]));
                } else {
                    dist3 = min (dist3, min (abs(gN[idx] - groups[j][i]), abs(groups[j][i] - gN[idx - 1])));
                }
            }
            min2 = min(min2, (ll) dist2 * (ll) dist2 + (ll) dist3 * (ll) dist3);
        }

        //cout << "d1: " << dist1 << " d2: " << dist2 << " d3: " << dist3 << endl;

        
        ll ans =  min (min1, min2);
        cout << ans << endl;
        
        
    }

    return 0;
}