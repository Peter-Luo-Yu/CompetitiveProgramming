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

int n, m;
vector<vector<int>> adj1, adj2;
vector<bool> vis1, vis2;
vector<int> topo1, topo2;

void dfs1 (int s) {
    if (vis1[s]) return;
    vis1[s] = true;
    for (auto u : adj1[s]) {
        dfs1(u);
    }
    topo1.push_back(s);
}

void dfs2 (int s) {
    if (vis2[s]) return;
    vis2[s] = true;
    for (auto u : adj2[s]) {
        dfs2(u);
    }
    topo2.push_back(s);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    adj1 = vector<vector<int>> (n);
    adj2 = vector<vector<int>> (m);

    vis1 = vector<bool> (n);
    vis2 = vector<bool> (m);

    int nedges1, nedges2; cin >> nedges1 >> nedges2;
    for (int i = 0; i < nedges1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj1[a].push_back(b);
    }
    for (int i = 0; i < nedges2; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj2[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        dfs1(i);
    }
    for (int i = 0; i < m; i++) {
        dfs2(i);
    }
    reverse(topo1.begin(), topo1.end());
    reverse(topo2.begin(), topo2.end());

    //print(topo1); print(topo2);

    map<int, vector<int>> dp1, dp2;
    map<int, set<int>> tracker1, tracker2;
    dp1[0].push_back({0});
    dp2[0].push_back({0});

    for (int cur : topo1) {
        for (int next : adj1[cur]) {
            for (int i = 0; i < dp1[cur].size(); i++) {
                if (tracker1[next].count(dp1[cur][i] + 1) == 0) {
                    dp1[next].push_back(dp1[cur][i] + 1);
                    tracker1[next].insert(dp1[cur][i] + 1);
                }
            }
        }
    }

    for (int cur : topo2) {
        for (int next : adj2[cur]) {
            for (int i = 0; i < dp2[cur].size(); i++) {
                if (tracker2[next].count(dp2[cur][i] + 1) == 0) {
                    dp2[next].push_back(dp2[cur][i] + 1);
                    tracker2[next].insert(dp2[cur][i] + 1);
                }
            }
        }
    }

    //for (auto x : dp1) {cout << x.first << " | "; print(x.second)};
    //for (auto x : dp2) {cout << x.first << " | "; print(x.second)};
    
    vector<int> one = dp1[n - 1];
    vector<int> two = dp2[m - 1];

    int q; cin >> q;
    while (q--) {
        int s; cin >> s;

        map<int, int> exist;
        for (int i = 0; i < two.size(); i++) {
            exist[two[i]]++;
        }

        bool possible = false;
        for (int i = 0; i < one.size(); i++) {
            if (one[i] <= s) {
                int goal = s - one[i];
                if (exist[goal]) {
                    possible = true;
                }
            }
        }

        cout << (possible ? "YES" : "NO") << endl;

    }

    return 0;
}
