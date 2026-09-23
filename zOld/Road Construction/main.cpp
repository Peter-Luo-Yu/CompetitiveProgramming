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
vector<int> parent;
vector<int> siz;

int maxSize = 1;

int find (int x) {
    while (x != parent[x]) x = parent[x];
    return x;
}

bool same (int a, int b) {
    return find(a) == find(b);
}

void unite (int a, int b) {
    a = find(a); b = find(b);
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    parent[b] = a;

    maxSize = max(maxSize, siz[a]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m; cin >> n >> m;

    parent = vector<int> (n + 1);
    siz = vector<int> (n + 1);

    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 1; i <= n; i++) siz[i] = 1;
    
    int components = n;
    //print(parent); print(siz); space;
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;

        if (!same(a, b)) {
            unite(a, b);
            components--;
        }

        //print(parent); print(siz); 
        cout << components << " " << maxSize << endl;
        //space;
    }
    
    
    return 0;
}
