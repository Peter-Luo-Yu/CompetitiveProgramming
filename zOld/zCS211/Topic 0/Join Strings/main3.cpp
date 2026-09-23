#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

vector<vector<int>> adj;
vector<bool> vis;
vector<int> order;

void dfs (int s) {
    if (vis[s]) return;
    //cout << "visiting: " << s << endl;
    vis[s] = true;
    order.push_back(s);

    for (int i = 0; i < adj[s].size(); i++) {
        dfs(adj[s][i]);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<string> arr (n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {
        cout << arr[0] << endl;
        return 0;
    }

    adj = vector<vector<int>> (n);

    vector<bool> temp (n, false);

    for (int i = 0; i < n - 1; i++) {
        ll a, b; cin >> a >> b;
        a--; b--; 
        
        temp[b] = true;

        adj[a].push_back(b);
    }

    int final = -1;
    for (int i = 0; i < temp.size(); i++) {
        if (!temp[i]) {
            final = i;
        }
    }

    //printG(adj);
    /*
    for (auto x : mp) {
        cout << x.first << " | "; print(x.second);
    }
    */

    //cout << "final: " << final << " final size: " << adj[final].size() << endl;

    vis = vector<bool> (n, false);
    order.push_back(final);
    vis[final] = true;
    for (int i = 0; i < adj[final].size(); i++) {
        dfs (adj[final][i]);
    }

    //cout << "order: "; print(order);
    
    for (int i = 0; i < order.size(); i++) {
        cout << arr[order[i]];
    }

    cout << endl;
    
    

    


    return 0;
}