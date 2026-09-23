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

string str;
int CCidx = 0;
vector<int> CC;
vector<vector<int>> adj;
vector<bool> vis;

void dfs (int s, char breed) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto x : adj[s]) {
        if (str[x] == breed) {
            dfs (x, breed);
        }
    }

    CC[s] = CCidx;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int n, q; cin >> n >> q;

    cin >> str;

    adj = vector<vector<int>> (n);
    vis = vector<bool> (n);
    CC = vector<int> (n);
    
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        dfs (i, str[i]);
        CCidx++;
    }
    
    //print(CC);

    for (int i = 0; i < q; i++) {
        int a, b; char c;
        cin >> a >> b >> c;  a--, b--;

        if (CC[a] == CC[b]) {
            if (str[a] == c) {
                cout << "1";
            }
            else {
                cout << "0";
            }
        }
        else {
            cout << "1";
        }
    }

    return 0;
}
