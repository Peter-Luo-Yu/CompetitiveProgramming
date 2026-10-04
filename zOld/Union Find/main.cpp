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

vector<int> parent, sz;

int find(int x) {
    while (x != parent[x]) {
        x = parent[x];
    }
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    sz[a] += sz[b];
    parent[b] = a;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q; cin >> n >> q;

    parent = sz = vector<int> (n);
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    while (q--) {
        int t, a, b; cin >> t >> a >> b;

        if (t == 0) {
            unite(a, b);
        } else {
            if (same(a, b)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }


    return 0;
}

