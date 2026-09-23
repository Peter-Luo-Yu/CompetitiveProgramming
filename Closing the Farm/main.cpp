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

int n;
vector<int> parent, sz;

int find (int x) {
    while (x != parent[x]) {
        x = parent[x];
    }
    return x;
}

bool same (int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a); b = find(b);
    if (sz[a] < sz[b]) swap (a, b);
    sz[a] += sz[b];
    parent[b] = a;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int m; cin >> n >> m;

    vector<vector<int>> adj (n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> order (n);
    parent = sz = vector<int> (n);

    for (int i = 0; i < n; i++) {cin >> order[i]; order[i]--;}
    reverse(order.begin(), order.end());

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    //printG(adj);

    vector<bool> vis (n);
    vis[order[0]] = true;
    
    vector<string> ans = {"YES"};

    // we can only connect to visited places
    int cc = 1;
    for (int i = 1; i < n; i++) {
        cc++;
        vis[order[i]] = true;

        for (auto v : adj[order[i]]) {
            if (vis[v]) {
                if (!same(order[i], v)) {
                    unite(order[i], v);
                    cc--;
                }
            }
        }

        //cout << cc << endl;

        if (cc == 1) {
            ans.push_back("YES");
        } else {
            ans.push_back("NO");
        }
    }

    reverse(ans.begin(), ans.end());

    for (string s : ans) {
        cout << s << endl;
    }
    


    return 0;
}
