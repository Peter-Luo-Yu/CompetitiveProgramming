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

int sum1 = 0, sum2 = 0, num1 = 0, num2 = 0;
vector<int> arr, group;

void dfs (int s, int color, vector<vector<int>>&adj, vector<bool> &vis) {
    if (vis[s]) return;
    vis[s] = true;

    if (color == 1) {
        sum1 += arr[s];
        group[s] = 1; num1++;
    } else {
        sum2 += arr[s];
        group[s] = 2; num2++;
    }

    for (auto u : adj[s]) {
        dfs (u, -1 * color, adj, vis);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);

    int n; cin >> n;
    arr  = vector<int> (n);
    group = vector<int> (n);
    vector<vector<int>> adj (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis (n);

    dfs (0, 1, adj, vis);

    
    sum1 %= 12;
    sum2 %= 12;

    //print(group);
    //cout << sum1 << " " << sum2 << endl;

    if (sum1 == sum2) {
        cout << n << endl;
    }
    else if ((sum1 + 1) % 12 == sum2) {
        cout << num2 << endl;
    } 
    else if ((sum2 + 1) % 12 == sum1) {
        cout << num1 << endl;
    } 
    else {
        cout << 0 << endl;
    }

    
    return 0;
}
