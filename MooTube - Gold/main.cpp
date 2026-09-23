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

void setup() {
    for (int i = 0; i < n; i++) {
        parent[i] = i; sz[i] = 1;
    }
}

int find (int x) {
    while (x != parent[x]) x = parent[x];
    return x;
}

bool same (int a, int b) {
    return find(a) == find(b);
}

void unite (int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    parent[b] = a;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int q; cin >> n >> q;

    parent = sz = vector<int> (n);
    setup();

    vector<pair<int, pair<int, int>>> arr, query;

    for (int i = 0; i < n - 1; i++) {
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        arr.push_back({w, {a, b}});
    }

    for (int i = 0; i < q; i++) {
        int k, v; cin >> k >> v; v--;
        query.push_back({i, {v, k}});
    }

    sort (arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    sort (query.begin(), query.end(), [](pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
        return a.second.second > b.second.second;
    });

    /*
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i].first << " " << arr[i].second.first << " " << arr[i].second.second << endl; 
    } space;
    for (int i = 0; i < query.size(); i++) {
        cout << query[i].first << " " << query[i].second.first << " " << query[i].second.second << endl; 
    } space;
    */

    vector<int> ans (q);
    int arridx = 0; 

    for (int i = 0; i < query.size(); i++) {
        int idx = query[i].first, k = query[i].second.second, v = query[i].second.first;
        
        while (arridx < arr.size() && arr[arridx].first >= k) {
            unite(arr[arridx].second.first, arr[arridx].second.second);
            arridx++;
        }

        ans[idx] = sz[find(v)] - 1;
    }

    for (auto a : ans) {
        cout << a << endl;
    }



    return 0;
}
