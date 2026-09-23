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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    // the number of colors needed to color a tree
    // is simply the max(deg (v)) + 1

    int n; cin >> n;
    vector<vector<int>> adj (n);

    
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        //cout << a << b << endl;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
        

    //printG(adj);

    
    int Maxdeg = -1;
    for (int i = 0; i < n; i++) {
        Maxdeg = max (Maxdeg, (int) adj[i].size());
    }

    cout << Maxdeg + 1 << endl;

    

    return 0;
}
