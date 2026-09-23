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
    for (int i = 0; i < n + 2; i++) {
        parent[i] = i; sz[i] = 1;
    }
}

int find (int x) {
    while (x != parent[x]) x = parent[x];
    return x;
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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int a, b; cin >> n >> a >> b;
    vector<int> arr (n);
    parent = sz = vector<int> (n + 2);
    
    map<int, int> at; // stores val - index

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        at[arr[i]] = i;
    }

    setup();

    //print(parent);

    int dummyA = n;
    int dummyB = n + 1;

    for (int i = 0; i < n; i++) {
        if (at.count(a - arr[i]) > 0) {
            unite(i, at[a - arr[i]]);
        } else {
            unite(i, dummyB);
        }

        if (at.count(b - arr[i]) > 0) {
            unite(i, at[b - arr[i]]);
        } else {
            unite(i, dummyA);
        }
    }

    //print(parent);

    if (find(dummyA) == find(dummyB)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(dummyA)) {
                cout << 0 << " ";
            } else {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }


    return 0;
}
