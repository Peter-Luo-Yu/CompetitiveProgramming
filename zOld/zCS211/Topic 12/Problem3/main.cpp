#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (auto &p : adj) {cout << p.first << ": "; for (auto x : p.second) cout << x << " "; cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int n; 
map<string, vector<string>> adj;
map<string, int> color;
vector<string> names;


bool dfs(int idx, int k) {
    if (idx == names.size()) return true;

    string s = names[idx];

    for (int c = 1; c <= k; c++) {
        bool valid_color = true;

        for (auto x : adj[s]) {
            if (color[x] == c) {
                valid_color = false;
                break;
            }
        }

        if (valid_color) {
            color[s] = c;

            if (dfs(idx + 1, k)) return true;

            color[s] = 0; // backtrack
        }
    }

    return false;
}   

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    while (true) {
        int m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        adj.clear();
        color.clear();
        names.clear();

        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (auto x : adj) {
            names.push_back(x.first);
        }

        
        while (names.size() < n) {
            string fake = "person" + to_string(names.size());
            names.push_back(fake);
            adj[fake] = {};
        }

        int ans = n;

        for (int k = 1; k <= n; k++) {
            // reset colors
            for (auto &name : names) color[name] = 0;

            if (dfs(0, k)) {
                ans = k;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}