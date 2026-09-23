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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<vector<bool>> adj (n, vector<bool> (n));    

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                adj[i][j] = true;
            }
        }
        adj[i][i] = true;
    }

    //print2d(adj);

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][k] && adj[k][j]) {
                    adj[i][j] = true;
                }
            }
        }
    }

    //print2d(adj);

    ld ans = 0;

    for (int i = 0; i < n; i++) {
        ld reachcnt = 0;

        for (int j = 0; j < n; j++) {
            if (adj[j][i]) {
                reachcnt++;
            }
        }

        ans += (ld) 1 / reachcnt;
    }

    cout << fixed << setprecision(16) << ans << endl;

    return 0;
}
