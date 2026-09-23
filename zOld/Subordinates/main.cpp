#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

vector<int> subtreeSize;

void dfs (vector<vector<int>> &adj, int s, int p) {
    subtreeSize[s] = 1;

    for (int i = 0; i < adj[s].size(); i++) {
        if (adj[s][i] != p) {
            dfs (adj, adj[s][i], s);
        }
        subtreeSize[s] += subtreeSize[adj[s][i]];
    }
    

}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n; cin >> n;

    subtreeSize = vector<int> (n);
    vector<vector<int>> adj (n);

    for (int i = 1; i < n; i++) {
        int boss; cin >> boss; boss--;

        adj[boss].push_back(i);
    }

    //printG(adj);

    dfs(adj, 0, -1);

    for (int i = 0; i < subtreeSize.size(); i++) {
        cout << subtreeSize[i] - 1 << " ";
    }

    return 0;
}
