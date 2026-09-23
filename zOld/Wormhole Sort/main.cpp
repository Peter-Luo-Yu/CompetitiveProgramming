#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}


vector<int> order ;
vector<vector<pair<int, int>>> adj ;
vector<int> components ; 
vector<bool> vis ;

void dfs (int s, int cur, int min_width) {
    if (vis[s]) return;
    vis[s] = true;
    
    components[s] = cur;

    for (int i = 0; i < adj[s].size(); i++) { 
        if (adj[s][i].second >= min_width) {
            dfs (adj[s][i].first, cur, min_width);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int n, m; cin >> n >> m;

    order = vector<int> (n);
    for (int i = 0; i < n; i++) {cin >> order[i];}
    bool edgecase = true;
    for (int i = 0; i < n; i++) {
        if (order[i] != i + 1) {
            edgecase = false;
        }
    }
    if (edgecase) {
        cout << -1 << endl;
        return 0;
    }


    adj = vector<vector<pair<int, int>>> (n);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    ll l = 1, r = 1e9;
    int ans = 1e9;
    while (l <= r) {
        int mid = (l+r)/2;  

        //cout << "min width: " << mid << endl;

        int cur_component = 0;
        components = vector<int> (n, -1); 
        vis = vector<bool> (n);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs (i, cur_component, mid);
                cur_component++;
            }
        }

        //print(components)

        bool sortable = true;
        for (int i = 0; i < n; i++) {
            if (components[i] != components[order[i] - 1]) {
                sortable = false;
            }
        }

        if (sortable) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }    
    cout << ans << endl;
    return 0;
}